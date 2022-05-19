/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //Floyd’s Cycle Finding Algorithm
        if(head == nullptr) return false;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        // checking if fast->next is also nullptr because if fast->next == nullptr, 
        // then fast->next->next causes segfault
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow) return true;
        }
        
        // if fast or fast->next reaches nullptr, then it means no cycle.
        return false;
    }
};