package blog;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] nx = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int n = nx[0], x = nx[1];

        int[] counts = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int lo = 0, hi = 0;
        int sum = 0;
        int result = -1;
        ArrayList<Integer> prefixSum = new ArrayList<>();
        while(hi < n) {
            sum += counts[hi];

            if(hi - lo + 1 == x) {
                prefixSum.add(sum);
                result = Math.max(result, sum);
                sum -= counts[lo];
                lo++;
            }

            hi++;
        }

        if(result == 0) {
            System.out.println("SAD");
            return;
        }

        System.out.println(result);

        int count = 0;
        for(int prefix: prefixSum) {
            if(prefix == result) {
                count++;
            }
        }

        System.out.println(count);
    }
}
