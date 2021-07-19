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
    void reverse(ListNode* head){
        ListNode *prev = NULL, *ptr = head;
        
        while(ptr){
            ListNode *tmp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = tmp;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prevTail = NULL, *ptr = head;
        
        while(ptr){
            ListNode *start = ptr,*tmp = ptr, *prev = NULL;
            int i;
            for(i=0;i<k && tmp;i++){
                prev = tmp;
                tmp = tmp->next;
            }
            if(i<k) break;
            ListNode *end = prev;
            ListNode *nxt = tmp;
            
            
            end->next = NULL;
            reverse(start);
            
            if(prevTail)
                prevTail->next = end;
            else
                head = end;
            start->next = nxt;
            
            prevTail = start;
            ptr = nxt;
        }
        return head;
    }
};