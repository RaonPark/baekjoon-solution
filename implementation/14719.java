package rainy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] hw = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int h = hw[0];
        int w = hw[1];

        int[] blocks = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int[][] mat = new int[h][w];

        for(int i=0; i<blocks.length; i++) {
            for(int j=h-1; j>=h - blocks[i]; j--) {
                mat[j][i] = 1;
            }
        }

        int total = 0;

        for(int i=h-1; i>=0; i--) {
            boolean left = false;
            boolean right = false;

            int drops = 0;
            for(int j=0; j<w; j++) {
                if(!left && mat[i][j] == 1) {
                    left = true;
                }
                if(left && mat[i][j] == 0) {
                    drops++;
                } else if(left && mat[i][j] == 1) {
                    right = true;
                }

                if(left && right) {
                    left = true;
                    right = false;
                    total += drops;
                    drops = 0;
                }
            }
        }

        System.out.println(total);
    }
}
