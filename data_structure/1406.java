package editor;

import java.io.*;
import java.util.ArrayDeque;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        int m = Integer.parseInt(br.readLine());
        int n = s.length();

        ArrayDeque<Character> leftCursor = new ArrayDeque<>();
        ArrayDeque<Character> rightCursor = new ArrayDeque<>();

        for(int i=0; i<n; i++) {
            leftCursor.addLast(s.charAt(i));
        }

        while(m > 0) {
            String[] commands = br.readLine().split(" ");

            String a = commands[0];
            String b = "";
            if(a.compareTo("P") == 0)
                b = commands[1];

            if(a.compareTo("L") == 0) {
                if(!leftCursor.isEmpty()) {
                    rightCursor.addFirst(leftCursor.pollLast());
                }
            } else if(a.compareTo("D") == 0) {
                if(!rightCursor.isEmpty()) {
                    leftCursor.addLast(rightCursor.pollFirst());
                }
            } else if(a.compareTo("B") == 0) {
                if(!leftCursor.isEmpty()) {
                    leftCursor.pollLast();
                }

            } else if(a.compareTo("P") == 0) {
                for(int i=0; i<b.length(); i++) {
                    leftCursor.addLast(b.charAt(i));
                }
            }
            m--;
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while(!leftCursor.isEmpty()) {
            bw.write(leftCursor.pollFirst());
        }

        while(!rightCursor.isEmpty()) {
            bw.write(rightCursor.pollFirst());
        }

        bw.flush();
        bw.close();

        char[] result = new char[leftCursor.size() +  rightCursor.size()];
        int idx = 0;
        while(!leftCursor.isEmpty()) {
            result[idx++] = leftCursor.pollFirst();
        }

        while(!rightCursor.isEmpty()) {
            result[idx++] = rightCursor.pollFirst();
        }

        System.out.println(result);
    }
}
