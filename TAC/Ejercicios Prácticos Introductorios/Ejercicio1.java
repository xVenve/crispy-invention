import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Random;

// Cálculo del máximo comun divisor de dos números

public class Ejercicio1 {

    public static void main(String[] args) {
        BigInteger a = BigInteger.valueOf(13443);
        BigInteger b = BigInteger.valueOf(34344);
        System.out.println("Number 1: " + a + "\nNumber 2: " + b);

        Ejercicio1 ejercicio1 = new Ejercicio1();

        long start = System.nanoTime();
        BigInteger alg1 = ejercicio1.algoritmo1(a, b);
        long end = System.nanoTime();
        System.out.println(end - start);

        start = System.nanoTime();
        BigInteger alg2 = ejercicio1.algoritmo2(a, b);
        end = System.nanoTime();
        System.out.println(end - start);

        System.out.println("The greatest common divisor of two numbers is : " + alg1);
        System.out.println("The greatest common divisor of two numbers is : " + alg2);

        new File("outputEj1.txt");

        FileWriter write;
        try {
            //BigInteger max = new BigInteger("9223372036854775807");
            write = new FileWriter("outputEj1.txt");
            Random rand = new Random();
            for (int i = 1; i < 64; i++) {
                BigInteger x = new BigInteger(i, rand); // (2^i-1)
                while (x.compareTo(BigInteger.valueOf((long) Math.pow(2, i - 1))) == -1) {
                    x = new BigInteger(i, rand);
                }
                BigInteger y = new BigInteger(i, rand);
                while (y.compareTo(BigInteger.valueOf((long) Math.pow(2, i - 1))) == -1) {
                    y = new BigInteger(i, rand);
                }

                double algt1 = 0;
                for (int j = 0; j < 10; j++) {
                    start = System.nanoTime();
                    ejercicio1.algoritmo1(x, y);
                    end = System.nanoTime();
                    algt1 += (end - start);
                }

                double algt2 = 0;
                for (int j = 0; j < 10; j++) {
                    start = System.nanoTime();
                    ejercicio1.algoritmo2(x, y);
                    end = System.nanoTime();
                    algt2 += (end - start);
                }

                System.out.println(i + "; " + algt1 / 10 + "; " + algt2 / 10 + "; " + ejercicio1.algoritmo2(x, y));

                write.write(i + "; " + algt1 / 10 + "; " + algt2 / 10 + "\n");
            }

            write.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public BigInteger algoritmo1(BigInteger number1, BigInteger number2) {
        BigInteger number3 = number1.min(number2);
        BigInteger mcd = BigInteger.valueOf(1);
        number3.add(BigInteger.valueOf(1));
        for (BigInteger i = BigInteger.valueOf(2); i.compareTo(number3) == -1; i = i.add(BigInteger.valueOf(1))) {
            while (number1.mod(i).equals(BigInteger.valueOf(0)) && number2.mod(i).equals(BigInteger.valueOf(0))) {
                number1 = number1.divide(i);
                number2 = number2.divide(i);
                mcd = i.multiply(mcd);
            }
        }
        return (mcd);
    }

    public BigInteger algoritmo2(BigInteger number1, BigInteger number2) {
        while (!number1.equals(BigInteger.valueOf(0)) && !number2.equals(BigInteger.valueOf(0))) {
            if (number1.compareTo(number2) == -1) {
                number2 = number2.mod(number1);
            } else {
                number1 = number1.mod(number2);
            }
        }
        return number1.max(number2);
    }
}