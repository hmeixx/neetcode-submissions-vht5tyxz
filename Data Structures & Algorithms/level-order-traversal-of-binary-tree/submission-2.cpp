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
        /*result
            ├── [1]
            ├── [2,3]
            └── [4,5,6,7]*/
        queue<TreeNode*> q;
        /*建立一個 Queue。
        Queue 裡面放的是：TreeNode*
        也就是「樹的節點指標」。
        例如：q = [1, 2, 3]
        代表 Queue 裡面目前排著這三個節點。*/
        if (root == nullptr) {
            return {};
        }

        q.push(root);
        /*一開始我們只把 root 放進去。
        假設:
              1
            /   \
           2     3
        此時：q = [1] 注意：不是一開始把整棵樹放進 Queue。而是：先放 1-> 處理 1 -> 再把 2、3 放進去*/

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;//這個 level 專門存：目前這一層的所有節點值。
            // 假設：size = 2那這個迴圈就執行兩次：第一次 → 處理 2 第二次 → 處理 3
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();//q.front() 是：取得 Queue 最前面的節點。
                q.pop();//把這個節點從 Queue 移除 
                // 所以：front()拿到目前要處理的節點pop()把它從 Queue 移除

                level.push_back(node->val);//把 node 的值放進這一層
                // 假設：node = 2 那：node->val 就是：2 所以：level.push_back(2);
                // 例如：原本：level = []加入 2：level = [2] 下一次處理 3：level = [2,3]
                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }

            result.push_back(level);//vector 用 push_back() 就是把東西加到 Vector 的最後面。
        }

        return result;
    }
};