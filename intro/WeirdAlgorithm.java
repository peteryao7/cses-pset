import java.util.*;

public class WeirdAlgorithm {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        long n = s.nextLong();

        while (true) {
            if (n == 1) {
                System.out.println(n);
                break;
            }
            else if (n % 2 == 0) {
                System.out.print(n + " ");
                n /= 2;
            }
            else {
                System.out.print(n + " ");
                n = n * 3 + 1;
            }
        }
    }
}