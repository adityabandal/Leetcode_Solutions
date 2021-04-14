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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lt = new ListNode(0);
        ListNode *gt = new ListNode(0);
        ListNode *tlt = lt, *tgt = gt;
        while(head){
            ListNode *tmp = head;
            head = head->next;
            tmp->next = NULL;
            if(tmp->val<x){
                tlt->next = tmp;
                tlt = tmp;
            }
            else{
                tgt->next = tmp;
                tgt = tmp;
            }
        }
        tlt->next = gt->next;
        return lt->next;
    }
};