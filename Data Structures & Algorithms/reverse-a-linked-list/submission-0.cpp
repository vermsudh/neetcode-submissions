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
    ListNode* reverseList(ListNode* head) {
        //We are going to solve this question using 3 pointers approach. 
        
        //We are going to take previous, current and next pointers. 
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next; //next is a temporary pointer that gets assigned during each iteration.

        //We are going to travese over the LL using while loop.
        while(current != nullptr){ //we are going to run this loop until current is not equal to null pointer. 
            //Since we have to revese the LL. 
            //We can simply revese the connections between the nodes. 
            
            //1) Operation A: Preserve the next node.
            //Why? Because we're about to change the connection of node 1. We don't want to lose access to node 2.
            next = current -> next;

            //Operation B: Reverse the connection.
            current -> next = prev;
            // Previously:

            // 1 → 2

            // Now:

            // NULL ← 1

            //Operation C: Move the pointers.

            prev = current;
            current = next;
        }

        return prev;
    }
};
