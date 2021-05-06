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
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        else if(head->next==NULL){
            return new TreeNode(head->val);
        }
        else{
            ListNode *prev, *p1, *p2;
            p1 = head;
            p2 = head->next;
            prev = NULL;
            
            while(p2){
                p2 = p2->next;
                if(p2){
                    p2 = p2->next;
                    prev = p1;
                    p1 = p1->next;
                }
            }
            p2 = p1->next;
            if(prev!=NULL)
            prev->next = NULL;
            
            TreeNode *ans = new TreeNode(p1->val);
            if(prev!=NULL)
            ans->left = sortedListToBST(head);
            ans->right = sortedListToBST(p2);
            return ans;
        }
    }
};