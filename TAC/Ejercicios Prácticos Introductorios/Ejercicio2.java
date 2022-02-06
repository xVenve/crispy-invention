import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Random;

// Determinar si un número es primo o no

public class Ejercicio2 {

    public static void main(String[] args) {
        Ejercicio2 ejercicio2 = new Ejercicio2();
        // BigInteger a = new BigInteger("479001599");

        long start = System.nanoTime();
        // System.out.println(a + " " + ejercicio2.isPrime(a));
        long end = System.nanoTime();
        System.out.println("Time: " + (end - start));

        new File("outputEj2.txt");

        FileWriter write;
        try {
            // BigInteger max = new BigInteger("9223372036854775807");
            write = new FileWriter("outputEj2.txt");
            Random rand = new Random();
            for (int i = 1; i < 64; i++) {
                BigInteger x = new BigInteger(i, rand);
                while (x.compareTo(BigInteger.valueOf((long) Math.pow(2, i - 1))) == -1) {
                    x = new BigInteger(i, rand);
                }
                double algt = 0;
                for (int j = 0; j < 10; j++) {
                    start = System.nanoTime();
                    ejercicio2.isPrime(x);
                    end = System.nanoTime();
                    algt += (end - start);
                }

                System.out.println(i + "; " + algt / 10 + "; " + x);

                write.write(i + "; " + algt / 10 + "\n");
            }

            write.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        /* try {
            // BigInteger max = new BigInteger("9223372036854775807");
            write = new FileWriter("outputEj2.txt");

            FileReader fr = new FileReader(new File("PRIMES1C.TXT"));
            BufferedReader br = new BufferedReader(fr);
            String line = br.readLine();
            String[] elements = line.split(" ");
            int r = 1000;
            for (int i = 1; i < elements.length / r; i++) {
                BigInteger x = new BigInteger(elements[i * r]);

                double algt = 0;
                for (int j = 0; j < 10; j++) {
                    start = System.nanoTime();
                    ejercicio2.isPrime(x);
                    end = System.nanoTime();
                    algt += (end - start);
                }

                System.out.println(i + "; " + algt / 10 + "; " + x);

                write.write(i + "; " + algt / 10 + "\n");
            }

            write.close();
        } catch (IOException e) {
            e.printStackTrace();
        } */
    }

    public boolean isPrime(BigInteger n) {
        boolean isPrime = true;

        for (BigInteger i = BigInteger.valueOf(2); i.compareTo(n) == -1; i = i.add(BigInteger.valueOf(1))) {
            if (n.mod(i).compareTo(BigInteger.valueOf(0)) == 0) {
                isPrime = false;
                break;
            }
        }
        return isPrime;
    }

}
