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

    private TreeNode createTree(List<Integer> l, int st, int ed) {
        if (st > ed)
            return null;
        int mid = (st + ed) / 2;
        TreeNode nn = new TreeNode();
        nn.val = l.get(mid);
        nn.left = createTree(l, st, mid - 1);
        nn.right = createTree(l, mid + 1, ed);
        return nn;
    }

    public TreeNode balanceBST(TreeNode root) {
        List<Integer> l = new ArrayList<>();
        fill(l, root);
        TreeNode ans = createTree(l, 0, l.size() - 1);
        return ans;
    }

    public void fill(List<Integer> l, TreeNode root) {
        if (root == null) {
            return;
        }
        
        fill(l, root.left);
        l.add(root.val);
        fill(l, root.right);
    }

    // public int height(TreeNode root){
    //     if(root==null){
    //         return 0;
    //     }
    //     int h1=height(root.left);
    //     int h2=height(root.right);
    //     return 1+Math.max(h1,h2);
    // }
}