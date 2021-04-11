struct Node{
    int val;
    struct Node* next, *prev;
    Node(int x){
        val = x;
        prev = NULL;
        next = NULL;
    }
};
class Solution {
public:
    
    int findTheWinner(int n, int k) {
        Node *head = NULL, *tail;//, *prev=NULL;
        
        for(int i=1;i<=n;i++){
            if(head==NULL){
                head = new Node(i);
                tail = head;
            }
            else{
                Node *ptr = new Node(i);
                ptr->prev = tail;
                tail->next = ptr;
                tail = ptr;
            }
        }
        head->prev = tail;
        tail->next = head;
        
        Node *curr = tail;
        while(curr->next!=curr){
            for(int i=0;i<k;i++){
                curr = curr->next;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
        return curr->val;
    }
};