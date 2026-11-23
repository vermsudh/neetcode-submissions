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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        //We are going to use recursion to solve this question efficiently. 
        
        //In order to solve this through recursion. Lets divide the LL into part
        // We know that we have been given two heads : h1 and h2.
        //We have to return heads only. 

        //The beauty of recursion will help us to solve this problem. 
        // Firstly, we know that the final merged LL should be also assorted and 
        // in ascending order. 
        // output : [1, 1, 2, 3, 4, 5] 

        // h1 -> 1 -> 2 -> 4
        // h2 -> 1 -> 3 -> 5

        // If you notice if we need to return the smallest head out of two heads. 

        //We also need to check one more thing is if our h1 is poiting to null
        // and h2 is pointing to null, we will return that specific list.

        if(h1 == nullptr || h2 == nullptr){
            return h1 == nullptr  ? h2 : h1;
        }

        if(h1 -> val <= h2 -> val){// In this case, we need to return h1 only at first.
            //Now, we need to point the rest of nodes with and attach the nodes using recursion.
            // h1 -> next (this is going to be next node) = call the function again to perform the same step. 
            h1 -> next = mergeTwoLists(h1 -> next, h2);

            return h1; //We will return h1 if h1 is smaller
        }else{ // h2 val is smaller than h1 val
            h2 -> next = mergeTwoLists(h1, h2 -> next);
            //Now, we need to point the rest of nodes with and attach the nodes using recursion.
            // h2 -> next (this is going to be next node) = call the function again to perform the same step. 
            return h2;
        }
    }
};
