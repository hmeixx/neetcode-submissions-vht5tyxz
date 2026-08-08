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
/*如果 root 是空的
    回傳空

建立 Queue
建立最終答案

root 放進 Queue

只要 Queue 不為空：

    記住目前 Queue 的 size
    ↓
    這就是這一層有幾個節點

    建立一個空的 level

    重複 levelSize 次：

        取出 Queue 最前面的 node

        把 node->val 放進 level

        如果有 left
            放進 Queue

        如果有 right
            放進 Queue

    level 放進最終答案

回傳最終答案*/
#include <queue>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;

        if (root == nullptr) {
            return {};
        }

        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }

            result.push_back(level);
        }

        return result;
    }
};