import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class PizzaDelivery {
    static int[] a, b;
    static int pizza;
    static int m, n;

    static int[][] sumOfA, sumOfB;

    static int[] seqA, seqB;

    static final int MAX_PIZZA_SEQ = 1_000_001;

    // A와 B를 선택하는 경우 두 가지 밖에 없다.
    // 따라서,

    // 누적합 해결 아이디어
    // 각 피자 조각을 크기 몇 조각 몇 개 이렇게 누적합을 만들어 놓는다.
    // 그 다음 DP를 돌려 조합의 개수를 찾는다.

    static void prefixSum() {
        sumOfA = new int[m][m];
        sumOfB = new int[n][n];
        seqA = new int[MAX_PIZZA_SEQ];
        seqB = new int[MAX_PIZZA_SEQ];

        for(int i=0; i<m; i++) {
            sumOfA[i][i] = a[i];
            seqA[sumOfA[i][i]]++;
            for(int j=i + 1; j<m; j++) {
                sumOfA[i][j] = sumOfA[i][j - 1] + a[j];
                seqA[sumOfA[i][j]]++;
            }
        }

        for(int i=m-1; i>1; i--) {
            for(int j=0; j<i-1; j++) {
                sumOfA[i][j] = sumOfA[0][j] + sumOfA[i][m-1];
                seqA[sumOfA[i][j]]++;
            }
        }

        for(int i=0; i<n; i++) {
            sumOfB[i][i] = b[i];
            seqB[sumOfB[i][i]]++;
            for (int j = i + 1; j < n; j++) {
                sumOfB[i][j] = sumOfB[i][j - 1] + b[j];
                seqB[sumOfB[i][j]]++;
            }
        }

        for(int i=n-1; i>1; i--) {
            for(int j=0; j<i-1; j++) {
                sumOfB[i][j] = sumOfB[0][j] + sumOfB[i][n-1];
                seqB[sumOfB[i][j]]++;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        pizza = Integer.parseInt(br.readLine());

        String[] mn = br.readLine().split(" ");

        m = Integer.parseInt(mn[0]);
        n = Integer.parseInt(mn[1]);

        a = new int[m];
        b = new int[n];
        for(int i=0; i<m; i++) {
            a[i] = Integer.parseInt(br.readLine());
        }
        for(int i=0; i<n; i++) {
            b[i] = Integer.parseInt(br.readLine());
        }

        prefixSum();

        int ans = 0;
        for(int i=0; i<=pizza; i++) {
            if(i == 0 || i == pizza) {
                ans += (seqA[i] + seqB[pizza-i]);
            } else {
                if(seqA[i] != 0 && seqB[pizza-i] != 0) {
                    ans += (seqA[i] * seqB[pizza-i]);
                }
            }

//            System.out.println("pizza : (" + i + ", " + (pizza - i) + ") : " + ans);
        }

        System.out.println(ans);
    }
}
