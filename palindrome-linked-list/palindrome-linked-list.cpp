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
    ListNode *reverse(ListNode *p){
        ListNode *prev,*curr,*tmp;
        prev = NULL;
        curr = p;
        while(curr){
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *p1, *p2;
        if(!head) return true;
        p1 = head;
        p2 = head->next;
        
        while(p1 && p2){
            p2 = p2->next;
            if(p2){
                p2 = p2->next;
                p1 = p1->next;
            }
        }
        
        p2 = p1->next;
        p1->next = NULL;
        p2 = reverse(p2);
        
        p1 = head;
        while(p1 && p2){
            if(p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return true;
    }
};