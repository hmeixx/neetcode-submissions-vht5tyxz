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
    int preIdx = 0;
    unordered_map<int,int> indexMap;//建hashmap
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Preorder：「告訴我誰是 root」
        // Inorder：「告訴我 root 左右有哪些東西」
        
        for(int i=0;i<inorder.size();i++){   
            indexMap[inorder[i]]=i; //key:值->value:位置
        }
        
        return build(preorder,0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder,int l, int r){
        if(l>r)return nullptr;
        TreeNode* node = new TreeNode(preorder[preIdx]);//建新樹[1]
        int sep=indexMap[preorder[preIdx]];
        preIdx++;
        node->left=build(preorder,l,sep-1);
        node->right=build(preorder,sep+1,r);
        return node;
    }
};
