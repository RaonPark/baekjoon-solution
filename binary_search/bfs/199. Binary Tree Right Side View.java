class Solution {
    static class Node {
        public int level;
        public TreeNode node;
        public Node(int level, TreeNode node) {
            this.level = level;
            this.node = node;
        }
    }
    public List<Integer> rightSideView(TreeNode root) {
        if(root == null)
            return new ArrayList<>();
        int[] ans = new int[101];
        ArrayDeque<Node> q = new ArrayDeque<>();

        ans[0] = root.val;
        int level = 0;
        q.push(new Node(0, root));

        while(!q.isEmpty()) {
            Node now = q.poll();

            ans[now.level] = now.node.val;
            level = now.level;

            if(now.node.left != null) {
                q.addLast(new Node(now.level + 1, now.node.left));
            }
            if(now.node.right != null) {
                q.addLast(new Node(now.level + 1, now.node.right));
            }
        }

        List<Integer> answer = new ArrayList<>();

        for(int i=0; i<=level; i++) {
            answer.add(ans[i]);
        }

        return answer;
    }
}
