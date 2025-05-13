package number;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();

        int idx = 0;
        int num = 0;
        while(idx < s.length()) {
            num++;
            String number = num + "";
            for(int i=0; i<number.length(); i++) {
                if(idx < s.length() && number.charAt(i) == s.charAt(idx)) {
                    idx++;
                }
            }
        }

        System.out.println(num);
    }
}
