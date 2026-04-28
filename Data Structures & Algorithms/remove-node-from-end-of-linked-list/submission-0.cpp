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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*建一個「假的頭節點」
                            head
                            ↓
        結構會變成：dummy →  1 → 2 → 3 → ...
        如果沒有 dummy，你會沒東西可以指向 head 前面*/
        ListNode* dummy = new ListNode(0, head);
        /*左指標一開始放在 *****dummy不是「建立 left 專屬的鏈」而是讓 left 指向 dummy 這個已經存在的節點
        left
        ↓
        dummy → 1 → 2 → 3*/
        ListNode* left = dummy;
        /*右指標一開始放在 head：
                right
                ↓
        dummy → 1 → 2 → 3*/
        ListNode* right = head;
        while(n>0){
            right = right->next;
            n--;
        }
        // 讓 left 和 right 一起往前走，直到 right 走到最後
        // left 就會剛好停在：「要刪的前一個節點」
        while(right!=nullptr){
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return dummy->next;
    }
};
