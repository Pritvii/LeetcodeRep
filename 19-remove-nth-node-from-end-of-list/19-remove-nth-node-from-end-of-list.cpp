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
        int i = 0 ; 
        ListNode* temp = head;
        while(temp)
        {
            i++;
            temp = temp->next;
        }
        if(i == 0)
            return NULL;
        if(i == 1)
            return NULL;
        if(n > i)
            return head;
        int num_from_start = i - n ;
        
        temp = head;
        ListNode* temp2 = NULL;
        while(num_from_start--){
            temp2 = temp;
            temp = temp->next;
        }
        if(temp2 == NULL)
            return head->next;
        temp2->next = temp->next;
        temp->next = NULL;
        
        cout<<temp->val;
        
        return head;
        
        
    }
};