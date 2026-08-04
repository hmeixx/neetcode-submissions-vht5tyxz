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
/*如果沒有節點
    高度是0
否則：
    算左邊高度
    算右邊高度
    
    取比較大的那一邊
    
    加上自己這一層*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth=0;
        int leftDepth=0,rightDepth=0;
        if(root==nullptr){
            return depth;
        }
        else{
            leftDepth=maxDepth(root->left);
            rightDepth=maxDepth(root->right);
            maxDepth(root->right);
            return 1 + max(leftDepth, rightDepth);

        }

    }
};
