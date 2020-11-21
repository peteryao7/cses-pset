import java.util.*;

public class Repetitions {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String seq = s.next();

        int max = -1;
        int i = 0;

        for (int j = 0; j < seq.length(); j++) {
            while (i <= j && seq.charAt(i) != seq.charAt(j))
                i++;
            
            max = Math.max(max, j - i + 1);
        }

        System.out.println(max);
    }
}