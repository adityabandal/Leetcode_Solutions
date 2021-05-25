/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void print(Node *head){
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node *ptr;
        ptr = head;
        while(ptr){
            Node *tmp= new Node(ptr->val);
            tmp->next = ptr->next;
            ptr->next = tmp;
            ptr = tmp->next;
        }
        
        ptr = head;
        // print(ptr);
        while(ptr){
            if(ptr->random){
                ptr->next->random = ptr->random->next;
            }
            ptr = ptr->next->next;
        }
        ptr = head;
        Node *ans = head->next;
        while(ptr){
            Node *cpy = ptr->next;
            Node *nxt = cpy->next; //can be null
            
            ptr->next = nxt;
            cpy->next = NULL;
            if(nxt){
                cpy->next = nxt->next;
            }
            
            ptr = nxt;
            
        }
        return ans;
    }
};