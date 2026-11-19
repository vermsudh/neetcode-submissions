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
        //We have been given that we have head = [0,1,2,3]
        //We need to return [3,2,1,0]

        //Our flow of nodes is like this head -> 0 -> 1-> 2-> 3 -> null. 
        //the head is the first node which is 0 and tail is 3 which is pointing to null at last. 
        //What we can do to revese this LL is change the order of connections from -> to <-
        //new connections would be null <- 0 <- 1<- 2<- 3 <- head. 

        // we can take three pointers in order to solve this question. 
        
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next; 

        //our prev pointer will have null pointer at first. 
        // current will point to node 0 
        //next will point to node 1. 

        //Then we will change the connections. 

        //since we would have to keep iteration until we are done changing the connection. 
        //We will use while loop. 

        while(current != nullptr){ // we will write the condition soon once we are done writing the inner logic to assign the pointers and move them correctly. 
            //We need to achieve this : null <- 0 <- 1<- 2<- 3 <- head. 

            //first lets mark the next pointer first so that we do not lose the connections. 
            next = current -> next; // this is Node 1. 
                                                                //prev.    curr.   next
            //Now, we need to establish a new connection which is null   <-  0    -> 1 ->  2  -> 3 -> null.
            current -> next = prev;// which is null.  We need point current node to null pointer which is prev. 

            //Now, we need to move the pointers. 
            //at first, we would need to move prev first and then current as if we move current first, then we might loose the connections and whole LL can get lost. 
            prev = current;
            current = next;

            //1) iteration
            //       prev.    curr.   next
            //null<-  0    -> 1 ->    2  ->   3 -> null.

            //2) iteration
            //              prev.    curr.   next
            //null<-  0    -> 1 ->    2  ->   3 -> null.

            //3) iteration
            //                   prev.    curr.   next
            //<-  0    <- 1  <-    2  ->   3 ->    null.

            //4) iteration
            //                       prev.    curr.   next
            //null<-  0    -> 1   <-    2  <-   3     null.

            //now we have reached prev to head which is node 3. 
            //We need to stop the loop when current reaches null so we need to iteration till the time it is not equal to null
        }
        //since we have to return the head. 
        //Head is at prev. 
        return prev;
    }
};
