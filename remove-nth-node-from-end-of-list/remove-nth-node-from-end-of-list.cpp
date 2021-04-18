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
        ListNode *f=head,*s=NULL,*prev;
        for(int i=0;i<n;i++){
            f = f->next;
        }
        prev=NULL;
        s = head;
        while(f!=NULL){
            f = f->next;
            prev = s;
            s = s->next;
        }
        if(prev==NULL){
            head = head->next;
        }
        else{
            prev->next = s->next;
        }
        return head;
    }
};