import java.math.BigInteger;

// Determinar si un número es primo o no

public class Ejercicio2 {

    public static void main(String[] args) {
        Ejercicio2 ejercicio2 = new Ejercicio2();
        BigInteger a = new BigInteger("479001599");

        long start = System.nanoTime();
        System.out.println(a + " " + ejercicio2.isPrime(a));
        long end = System.nanoTime();
        System.out.println("Time: " + (end - start));
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
