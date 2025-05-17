package choose;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;

public class Main {
    public static TreeSet<Integer> dfs(int idx, int start, boolean[] visited, int[] values, TreeSet<Integer> searchTree) {
        if(visited[idx] && idx == start) {
            searchTree.add(idx);
            return searchTree;
        }

        int next = values[idx];

        if(!visited[next]) {
            visited[next] = true;
            searchTree.add(next);
            return dfs(next, start, visited, values, searchTree);
        }

        return null;
    }

    // 다시 말하자면, 사이클이 있는 숫자를 검출해내면 된다.
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int[] values = new int[n + 1];

        values[0] = -1;

        for(int i=1; i<=n; i++) {
            values[i] = Integer.parseInt(br.readLine());
        }

        TreeSet<Integer> resultTree = new TreeSet<>();
        for(int i=1; i<=n; i++) {
            boolean[] visited = new boolean[n + 1];
            for(int j=1; j<=n; j++) {
                visited[j] = false;
            }

            TreeSet<Integer> cycles = dfs(i, i, visited, values, new TreeSet<>());
            if(cycles != null)
                resultTree.addAll(cycles);
        }

        System.out.println(resultTree.size());
        for(int node: resultTree) {
            System.out.println(node);
        }
    }
}
