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
    int count=0;
    int ans=0;
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr){
            return 0;
        }
        inorderRecursive(root,k);
        return ans;
    }
    void inorderRecursive(TreeNode* root,int k){ 
        if(root==nullptr) return;
        inorderRecursive(root->left,k);
        count++;
        if(count==k){
            ans=root->val;
            return;
        }
        inorderRecursive(root->right,k);
    }
};
