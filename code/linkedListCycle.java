/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        // using set store put ListNode
        Set<ListNode> listSet = new HashSet<ListNode>();
        int setSize = 0;
        
        if(head == null) return false;
        // since set cannot have duplicates, if the size stays the same after adding,
        // it means the node contains a cycle.
        while(head != null) {
            listSet.add(head);
            setSize++;
            if(listSet.size() != setSize) return true;
            head = head.next;
        }
        
        return false;
    }
}