import java.util.*;

public class Permutations {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        if (n > 1 && n < 4) {
            System.out.println("NO SOLUTION");
            return;
        }

        if (n == 4) {
            System.out.println("3 1 4 2");
            return;
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 1; i <= n; i += 2) {
            sb.append(i);
            sb.append(' ');
        }

        for (int i = 2; i <= n; i += 2) {
            sb.append(i);
            if (i < n - 1) {
                sb.append(' ');
            }
        }

        System.out.println(sb.toString());
    }
}