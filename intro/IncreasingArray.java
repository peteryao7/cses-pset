import java.util.*;

public class IncreasingArray {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int temp = s.nextInt();
        long moves = 0;

        for (int i = 1; i < n; i++) {
            int cur = s.nextInt();
            moves += Math.max(0, temp - cur);
            temp = cur + Math.max(0, temp - cur);
        }

        System.out.println(moves);
    }
}