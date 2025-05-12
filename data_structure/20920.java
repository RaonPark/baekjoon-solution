package word;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] nm = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int n = nm[0], m = nm[1];

        Map<String, Integer> wordMap = new LinkedHashMap<>();
        Set<String> wordSet = new HashSet<>();
        for(int i=0; i<n; i++) {
            String word = br.readLine();
            if(word.length() >= m) {
                if(wordMap.containsKey(word)) {
                    wordMap.compute(word, (k, v) -> v + 1);
                } else {
                    wordMap.put(word, 1);
                }
                wordSet.add(word);
            }
        }

        class WordMatch {
            public String word;
            public int appears;
            public WordMatch(String word, int appears) {
                this.word = word;
                this.appears = appears;
            }
        }

        PriorityQueue<WordMatch> q = new PriorityQueue<>((x, y) -> {
            if(x.appears > y.appears)
                return -1;
            else if(x.appears == y.appears) {
                if(x.word.length() > y.word.length()) {
                    return -1;
                } else if(x.word.length() == y.word.length()) {
                    return x.word.compareTo(y.word);
                } else return 1;
            }
            else return 1;
        });

        for(String word: wordSet) {
            q.add(new WordMatch(word, wordMap.get(word)));
        }

        BufferedOutputStream bos = new BufferedOutputStream(System.out);
        while(!q.isEmpty()) {
            WordMatch word = q.poll();
            bos.write(word.word.getBytes());
            bos.write('\n');
        }
        bos.flush();
        bos.close();
    }
}
