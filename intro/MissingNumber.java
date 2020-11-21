import java.util.*;

public class MissingNumber {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        long n = s.nextLong();
        long sum = 0;

        for (int i = 0; i < n - 1; i++) {
            sum += s.nextInt();
        }

        System.out.println(n * (n + 1) / 2 - sum);
    }
}