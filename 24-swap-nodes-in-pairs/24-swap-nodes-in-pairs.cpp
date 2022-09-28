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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        
        ListNode* temp = head;
        ListNode* temp2 = head->next;
        
        while(temp2 != NULL)
        {
            int op  = temp->val ;
            temp->val  = temp2->val;
            temp2->val  =  op;
            if(temp2->next  == NULL)
            {
                return head;
            }
            if(temp2->next)
            {
                if(temp2->next->next == NULL)
                    return head;
            }
            temp = temp2->next;
            temp2 = temp2->next->next;
            
        }
        
        return head;
        
    }
};