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
        //We would need to use three pointers in this approach. 
        
        //We have currently this head = 0 -> 1 -> 2 -> 3-> nullptr
        //We can change the sequence to this nullptr nullptr<-0<-1<-2<-3.

        //For this, we have can have three pointers like. 
        //We would have to take these pointers : prev, current, next. 

        ListNode* prev = nullptr; // this is the node before node 1. We are going to assign this as nullptr as we are about the change the sequence of the LL. 
        ListNode* current = head; // this is the node 1. 
        ListNode* next; // this is the next pointer after current. 

        while(current != nullptr){
        //1) Operation A. We would need to initlize next which is after current first. We just simply change the order without initlized or preserving the next. Then the whole LL might get lost. 
        
        next = current -> next;

        //2) Operation B. Now, we need to change the order. So the current should point to prev node which is nullptr.
        
        //nullptr <- 0 ->1 -> 2 -> 3.

        //We need point current to null which is prev. 

        current -> next = prev;

        //Operation C - Now, we would need to increment all the pointers. 
        //First we will will prev and then current. 

        prev = current;
        current = next;

        //We would need to perform these operatios till we have this. 
        //if the current is equal to nullptr, then we have to stop the loop
                                            // prev  current   next
        //nullptr <-    0 <-    1 <-   2 <-   3    <-  null
        }
        //Since we have to return the head which is at prev.
        return prev;
    }
};
