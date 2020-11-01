package p2;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.security.Key;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.util.Scanner;

import org.bouncycastle.crypto.AsymmetricBlockCipher;
import org.bouncycastle.crypto.BlockCipher;
import org.bouncycastle.crypto.BufferedBlockCipher;
import org.bouncycastle.crypto.CipherParameters;
import org.bouncycastle.crypto.CryptoException;
import org.bouncycastle.crypto.KeyGenerationParameters;
import org.bouncycastle.crypto.engines.AESEngine;
import org.bouncycastle.crypto.engines.DESEngine;
import org.bouncycastle.crypto.engines.DESedeEngine;
import org.bouncycastle.crypto.engines.RSAEngine;
import org.bouncycastle.crypto.generators.DESKeyGenerator;
import org.bouncycastle.crypto.generators.DESedeKeyGenerator;
import org.bouncycastle.crypto.modes.CBCBlockCipher;
import org.bouncycastle.crypto.paddings.PaddedBufferedBlockCipher;
import org.bouncycastle.crypto.params.AsymmetricKeyParameter;
import org.bouncycastle.crypto.params.DESParameters;
import org.bouncycastle.crypto.params.DESedeParameters;
import org.bouncycastle.crypto.params.KeyParameter;
import org.bouncycastle.crypto.params.ParametersWithIV;
import org.bouncycastle.crypto.util.PrivateKeyFactory;
import org.bouncycastle.crypto.util.PublicKeyFactory;
import org.bouncycastle.jcajce.provider.asymmetric.rsa.KeyPairGeneratorSpi;
import org.bouncycastle.util.Arrays;
import org.bouncycastle.util.encoders.Base64Encoder;
import org.bouncycastle.util.encoders.Hex;

public class RSA {

	public void doGenerateKeys() {
		try {
			System.out
					.print("Introduzca el nombre de los archivos de clave a grabar \n(se almacenarán con las extensiones .priv y .pub):");
			String fileName = new Scanner(System.in).nextLine();
			if (fileName.trim().length() > 0) {
				String keyfilePath = Utils.instance().filesPath + fileName;
				KeyPairGenerator gen = KeyPairGeneratorSpi.getInstance("RSA");
				gen.initialize(1024, generateSecureRamdom());

				Base64Encoder b64 = new Base64Encoder();

				KeyPair pair = gen.generateKeyPair();
				Key pubKey = pair.getPublic();
				Key privKey = pair.getPrivate();

				BufferedOutputStream pubOut = new BufferedOutputStream(
						new FileOutputStream(keyfilePath + ".pub"));
				BufferedOutputStream privOut = new BufferedOutputStream(
						new FileOutputStream(keyfilePath + ".priv"));
				b64.encode(pubKey.getEncoded(), 0, pubKey.getEncoded().length,
						pubOut);
				b64.encode(privKey.getEncoded(), 0, privKey.getEncoded().length,
						privOut);
				privOut.flush();
				privOut.close();
				pubOut.flush();
				pubOut.close();
			}
			System.out.println("Archivos de claves RSA almacenados");
		} catch (Exception e) {
			System.out.println("Ha ocurrido un error generando las claves RSA:"
					+ e);
		}

	}

	public SecureRandom generateSecureRamdom() {
		SecureRandom sr = null;
		try {
			sr = new SecureRandom();
			sr.setSeed("UCTresM.".getBytes());
		} catch (Exception e) {
			System.err
					.println("Ha ocurrido un error generando el número aleatorio");
			return null;
		}
		return sr;

	}

	public void doEncrypt() {
		try {
			byte[] text = Utils.instance().doSelectFile(
					"Seleccione un archivo para cifrar", "txt");
			if (text != null) {
				byte[] key = Utils.instance().doSelectFile(
						"Seleccione una clave pública", "pub");
				if (key != null) {
					Base64Encoder b64 = new Base64Encoder();
					ByteArrayOutputStream keyBytes = new ByteArrayOutputStream();
					BufferedOutputStream bKey = new BufferedOutputStream(
							keyBytes);
					b64.decode(key, 0, key.length, bKey);
					bKey.flush();
					bKey.close();

					byte[] res = encrypt(text, keyBytes.toByteArray());
					System.out.println("Texto cifrado (en hexadecimal):"
							+ new String(Hex.encode(res)));
					Utils.instance().saveFile("encrsa", Hex.encode(res));
				}
			} else {
				// No se desea continuar con la ejecución
			}
		} catch (Exception e) {
			System.out.println("Ha ocurrido un error cifrando el archivo:" + e);
		}

	}

	public void doDecrypt() {
		try {
			byte[] fileContent = Utils.instance().doSelectFile(
					"Seleccione una archivo cifrado", "encrsa");
			if (fileContent == null) {
				return;
			}
			byte[] key = Utils.instance().doSelectFile(
					"Seleccione una clave privada", "priv");
			if (key != null) {
				Base64Encoder b64 = new Base64Encoder();
				ByteArrayOutputStream keyBytes = new ByteArrayOutputStream();
				BufferedOutputStream bKey = new BufferedOutputStream(keyBytes);
				b64.decode(key, 0, key.length, bKey);
				bKey.flush();
				bKey.close();

				byte[] res = decrypt(Hex.decode(fileContent),keyBytes.toByteArray() );
				if (res != null) {
					System.out.println("Texto en claro:\n" + new String(res));
				}
			}
		} catch (Exception e) {
			System.out.println("Ha ocurrido un error descifrando el archivo:"
					+ e);
		}

	}

	private byte[] encrypt(byte[] inputData, byte[] keyBytes) {

		try {

			AsymmetricKeyParameter publicKey = (AsymmetricKeyParameter) PublicKeyFactory
					.createKey(keyBytes);
			
			AsymmetricBlockCipher e = new RSAEngine();
			// http://www.emc.com/collateral/white-papers/h11300-pkcs-1v2-2-rsa-cryptography-standard-wp.pdf
			e = new org.bouncycastle.crypto.encodings.PKCS1Encoding(e);
			e.init(true, publicKey);

			byte[] hexEncodedCipher = e.processBlock(inputData, 0,
					inputData.length);
			return hexEncodedCipher;
		} catch (Exception e) {
			System.out.println("Ha ocurrido un error cifrando el archivo:" + e);
		}

		return null;
	}

	private byte[] decrypt(byte[] encryptedData, byte[] keyBytes) {

		try {

			AsymmetricKeyParameter privateKey = (AsymmetricKeyParameter) PrivateKeyFactory
					.createKey(keyBytes);
			AsymmetricBlockCipher e = new RSAEngine();
			e = new org.bouncycastle.crypto.encodings.PKCS1Encoding(e);
			e.init(false, privateKey);

			byte[] hexEncodedCipher = e.processBlock(encryptedData, 0,
					encryptedData.length);
			return hexEncodedCipher;

		} catch (Exception e) {
			System.out.println("Ha ocurrido un error descifrando el archivo:"
					+ e);
		}

		return null;

	}
}
