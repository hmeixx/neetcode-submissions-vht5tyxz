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
/*開始
 ↓
root 是空的？
 ├─ 是 → true
 └─ 否
      ↓
檢查 root 是否在允許範圍內
 ├─ 不在 → false
 └─ 在
      ↓
   檢查左子樹
   範圍：
   最小值 ～ root->val
      ↓
   檢查右子樹
   範圍：
   root->val ～ 最大值
      ↓
   左右都合法？
   ├─ 否 → false
   └─ 是 → true*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
    bool valid(TreeNode* node,long long min,long long max){
        if(node==nullptr){
            return true;
        }
        if(node->val >= max ||node->val <= min ){
            return false;
        }
        else{
            return valid(node->left, min, node->val)&&valid(node->right, node->val, max);
        }
    }
};
