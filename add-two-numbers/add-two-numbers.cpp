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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        int d;
        while(l1 && l2){
            d = (l1->val+l2->val+c)%10;
            c = (l1->val+l2->val+c)/10;
            cout<<c<<endl;
            ListNode *newNode = new ListNode(d);
            tail->next = newNode;
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            d = (l1->val+c)%10;
            c = (l1->val+c)/10;
            ListNode *newNode = new ListNode(d);
            tail->next = newNode;
            tail = tail->next;
            l1=l1->next;
        }
        while(l2){
            d = (l2->val+c)%10;
            c = (l2->val+c)/10;
            ListNode *newNode = new ListNode(d);
            tail->next = newNode;
            tail = tail->next;
            l2=l2->next;
        }
        if(c>0){
            ListNode *newNode = new ListNode(c);
            tail->next = newNode;
            tail = tail->next;
        }
        return head->next;
    }
};