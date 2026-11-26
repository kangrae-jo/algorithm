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
    public boolean isCousins(TreeNode root, int x, int y) {
        Deque<TreeNode> q = new ArrayDeque<>();
        q.push(root);

        while (!q.isEmpty()) {
            int size = q.size();

            int xParent = -1;
            int yParent = -1;
            boolean xFlag = false;
            boolean yFlag = false;

            while (size-- > 0) {
                TreeNode cur = q.poll();
                if (cur.left != null) {
                    if (cur.left.val == x) {
                        xParent = cur.val;
                        xFlag = true;
                    } else if (cur.left.val == y) {
                        yParent = cur.val;
                        yFlag = true;
                    } else {
                        q.offer(cur.left);
                    }
                }
                if (cur.right != null) {
                    if (cur.right.val == x) {
                        xParent = cur.val;
                        xFlag = true;
                    } else if (cur.right.val == y) {
                        yParent = cur.val;
                        yFlag = true;
                    } else {
                        q.offer(cur.right);
                    }
                }
            }
            if (xFlag && yFlag && (xParent != yParent)) return true;
        }

        return false;
    }
}
