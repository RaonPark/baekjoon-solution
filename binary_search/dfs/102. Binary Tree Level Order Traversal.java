/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private List<List<Integer>> answer = new ArrayList<>();

    public void levelOrder(TreeNode node, int level) {
        if(answer.size() == level)
            answer.add(new ArrayList<>());

        answer.get(level).add(node.val);
        
        if(node.left != null) {
            levelOrder(node.left, level + 1);
        }
        if(node.right != null) {
            levelOrder(node.right, level + 1);
        }
    }

    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root == null)
            return answer;
        
        levelOrder(root, 0);

        return answer;
    }
}
