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
    ListNode* reverseList(ListNode* head){//For this approach, we can use three pointers. * head) {
        //In this approach, we would need to change the direction in order to solve this question.

        //We know that our head is 0 -> 1-> 2->3>nullptr. 

        //Since we have to return head -> 3-> 2-> 1-> 0. We would need to check what are the possible answers. 
        //We can't traverse the Linkedin List backwards since this is single Linked List. 

        // The length of the linst will be from 0 to 1000. The mode.val will be from -1000 to 1000. 

        //If the head is nullptr, then we would have to simply return the return empty LL. 

        //Now we know that in LL, we have a ListNode struc given to us in the question. 
        //It has a val and next pointer which is pointing to the next node. 

        //head -> 0 -> 1-> 2->3 -> nullptr  We would have to return this : nullptr <-1<-2<-3<-head. 
        //So we simply have to break the connections and establish a new connection. 

       //For this approach, we can use three pointers. 

        ListNode* prev = nullptr; //This is our first pointer.
        ListNode* current = head;//This will be current pointer which is head.
        ListNode* next; // We will assign this Node inside the loop. 

        while(current != nullptr){
            //This loop will traverse over the LL. 

            //We know that prev is starting from nullptr. // current is at head. We would need to assign next which is the next node after head 
            // in the first iteration.

            next = current -> next; // This will assign next to next node after current. 

            //  nullptr ->     0  ->     1->     2->     3 -> nullptr
            //  prev         current     next
            // Step 1 : Once we are done assigning the Nodes or the 3 pointers. We need to break the connection 
            //So nullptr <-   0   ->     1.    ->     2->     3 -> nullptr
            //    prev      current.    next
            //So we need to assign current to prev.

            current -> next = prev; //current should point to prev. 

            // Now, we have assigned all the pointers. We would have to simply increment the three pointers one by one. 
            //Now, first we move prev, current and then next. 

            prev = current;  // prev will become current 
            current = next; //current will become next. 
                            // next will automatically become the next pointer after current as we have established this in the first line of code. 

        //     1) iteration : //So nullptr <-   0   ->     1.    ->     2->     3 -> nullptr
        //                        //  prev     current     next
        //     2)) Iteration: //So nullptr <-   0   <-     1.    ->     2->     3 -> nullptr
        //                                 //  prev     current       next
        //     3) Iteration: //So nullptr <-   0   <-     1.    ->     2->         3 -> nullptr
        //                                             //  prev     current       next
        //     4) Iteration: //So nullptr <-   0   <-     1.    ->     2->         3 ->    nullptr
        //                                                         //  prev     current       next
        //     5) 4) Iteration: //So nullptr <-   0   <-     1.    ->     2->         3 ->     nullptr
        //                                                                         //  prev     current   next
        // }
        
        }
        //Since we have to return the head.
        //Prev will be pointing to head.
        
        return prev;
    }
};
