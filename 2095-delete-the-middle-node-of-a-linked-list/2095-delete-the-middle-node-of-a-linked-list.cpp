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
    ListNode* deleteMiddle(ListNode* head) {
        if( !head || !head -> next ) return NULL ;
        
        // Since we do not access the members within null pointers
        ListNode* slow = new ListNode(0) ;
        ListNode* fast = slow ;
        
        slow -> next = head ;
        fast -> next = head ;
        
        // Find the middle of the linked list : Tortoise Method 
        while( fast->next && fast->next->next ){
            slow = slow -> next ;
            fast = fast -> next -> next ;
        }
        
        // Delete a node in a Linked list 
        slow -> next = slow -> next -> next ;
        
        // return the modified Linked list 
        return head ;
    }
};