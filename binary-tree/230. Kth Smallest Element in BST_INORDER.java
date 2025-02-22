class Solution {
    public int kthSmallest(TreeNode root, int k) {
        ArrayDeque<TreeNode> q = new ArrayDeque<>();
        ArrayList<Integer> tree= new ArrayList<>();

        q.addLast(root);
        while(!q.isEmpty()) {
            TreeNode now = q.poll();

            tree.add(now.val);
            
            if(now.left != null)
                q.addLast(now.left);
            if(now.right != null)
                q.addLast(now.right);
        }

        Collections.sort(tree);

        return tree.get(k - 1);
    }
}
