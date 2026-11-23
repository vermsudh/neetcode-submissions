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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        //We are going to solve this question using recursion.

        //We would need to compare the heads of each Linked Lists and check which one is smaller. 
        //We have head1 -> 1 -> 2 -> 4
        //We have head2 -> 1 -> 3 -> 5

        //We need to return 1 -> 1 -> 2 -> 3 -> 4 -> 5

        //Lets compare the head 1 and 2. Since 1 and 1 are equal, we can return either head.
        //Lets suppose, we returned from head1

        //We have head1 -> 2 -> 4.
        //Now, we have head2 -> 1 -> 3 -> 5 

        //Now, we compare again 2 and 1. 1 is smaller. We need to point the head to rest of the LL. 
        //1 -> 1 ->  

        //2 -> 4 
        //3 -> 5

        //Now, we compare 2 and 3. 2 is smaller. 
        //We meed to point 2. 

        //1 -> 1 -> 2 

        //Now we compare 
        //4 
        //3 -> 5

        //1 -> 1 -> 2 -> 3

        //Now we compare 
        //4 -> null
        //5 -> null

        //Now //1 -> 1 -> 2 -> 3 -> 5

        //null (Now, we have h1 pointing to null, then we will have to return the rest of the h2 as it is)
        // 5-> null 

        if(head1 == nullptr || head2 == nullptr){
            return head1 == nullptr  ? head2 : head1;
        }

        // Now, we have to check the heads value of each lists and direct the next node to the right direction by calling the same function. 

        if(head1 -> val <= head2 -> val){
            head1 -> next = mergeTwoLists(head1 -> next, head2);
            return head1;
        }else{
            head2 -> next = mergeTwoLists(head1, head2 -> next);
            return head2;
        }

    }
};
