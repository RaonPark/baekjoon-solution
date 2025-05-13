package hamburger;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] nk = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int n = nk[0], k = nk[1];
        String str = br.readLine();
        boolean[] visited = new boolean[n];
        int total = 0;

        for(int i=0; i<str.length(); i++) {
            if(str.charAt(i) == 'P') {
                boolean isFound = false;
                for(int j=k; j>0; j--) {
                    if(i - j >= 0 && !visited[i - j] && str.charAt(i - j) == 'H') {
                        visited[i - j] = true;
                        total++;
                        isFound = true;
                        break;
                    }
                }
                if(!isFound) {
                    for (int j = 1; j <= k; j++) {
                        if (i + j < n && !visited[i + j] && str.charAt(i + j) == 'H') {
                            visited[i + j] = true;
                            total++;
                            break;
                        }
                    }
                }
            }
        }

        System.out.println(total);
    }
}
