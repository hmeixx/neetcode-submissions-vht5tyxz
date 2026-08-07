/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*站在每個 root 思考
        情況一：兩個都比 root 小 表示：兩個一定都在左子樹 所以：直接往左走
        情況二：兩個都比 root 大 表示：兩個都在右子樹 所以：直接往右走。
        情況三：一左一右 表示：在這裡分開了 所以：目前這個 root 就是 LCA。直接回傳。
        第四種情況（Hint 4）其中一個就是自己。*/
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else{//情況三四
            return root;
        }

    }
};
