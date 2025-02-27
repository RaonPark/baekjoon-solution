class Solution {
    public boolean kahn(int numCourses, ArrayList<ArrayList<Integer>> adjList, int[] indegree) {
        ArrayDeque<Integer> q = new ArrayDeque<>();
        int topo = 0;

        for(int i=0; i<indegree.length; i++) {
            if(indegree[i] == 0)
                q.addLast(i);
        }

        while(!q.isEmpty()) {
            for(int next: adjList.get(q.peekFirst())) {
                indegree[next]--;
                if(indegree[next] == 0) 
                    q.addLast(next);
            }
            topo++;
            q.poll();
        }

        return topo == numCourses;
    }
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
        int[] indegree = new int[numCourses];
        for(int i=0; i<numCourses; i++) {
            adjList.add(new ArrayList<>());
        }

        for(int i=0; i<prerequisites.length; i++) {
            adjList.get(prerequisites[i][1]).add(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        return kahn(numCourses, adjList, indegree);
    }
}
