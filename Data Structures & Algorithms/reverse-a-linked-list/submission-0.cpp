/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev =nullptr;//空指標
        ListNode* curr =head;//原本list的開頭
        //prev = nullptr
        //curr = [1] → [2] → [3]
        while(curr){
            ListNode* temp = curr->next;//把「下一個節點」先存起來（避免等一下斷掉）
            curr->next = prev;//反轉
            prev =curr;//prev往後移
            curr=temp;//curr繼續往下走

        }
        return prev;
    }
};
