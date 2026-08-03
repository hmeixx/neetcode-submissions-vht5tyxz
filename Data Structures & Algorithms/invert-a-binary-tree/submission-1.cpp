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

    /*思考流程
    如果 root 是空
        return

    交換左右子樹
    遞迴左子樹
    遞迴右子樹
    return root*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        else{
            swap(root->left,root->right);
            invertTree(root->left);
            invertTree(root->right);
            return root;
        }
        
    }
};
