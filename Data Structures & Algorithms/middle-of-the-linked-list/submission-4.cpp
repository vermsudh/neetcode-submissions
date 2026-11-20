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
    ListNode* middleNode(ListNode* head) {
        //We have to return the middle node of the LL in this case. 
        //When the LL has odd numbers of nodes. Lets assume we have 5 nodes.
        // In that case, we have will have our mid at 2 as 5/2 => 2

        //In the case of even nodes like 6, we will have our mid point at 3. 
        //[1,2,3,4,5,6] We have to return the second mif point. which is [4,5,6]


        //There are two approaches in this case. 

        //Approach #1. 
        //We would have calculathe number of nodes first and then we can
        //calculate the mid by didving it by 2. 

        //We would have to run a loop from head to tail to calculate. 

        //We would have need to define a temp pointer which will start from 0 to
        //to end of the LL. 

        ListNode* temp = head; // this stores the header pointer now .
        //Since we need a count, we will store number of counts. 
        int count = 0;
        //Now we need a while loop to iterate over LL. 
        while(temp != nullptr){
            count++;
            //Now need to move the pointer temp. 
            temp = temp -> next; // this will help move the pointer. 
        }

        //Now we have total number of nodes stored inside count. 
        int mid = count / 2;

        //Now, we would need to run our loop from 0 to mid. 

        //First of all, we would need to initlize our temp again to head as currently it is at tail from the previous loop. 

        temp = head;

        //We need to start from i = 0;
        int i = 0;

        while(i < mid){
            i++;
            //We need to increment the temp from i to mid point. 
            temp = temp -> next;
        }
        //now temp will be at mid point. 
        //we can return temp to see the ans. 
        return temp;


        // Aproach #2 
        // We can also solve this question using slow and fast pointer approach. 

        // fast will move by 2 nodes and slow with 1.
        // Since fast will reach the end first. When it it does, we will have out 
        // slow pointing at the mid. 

        // ListNode* fast = head;// both will start from the head.
        // ListNode* slow = head;

        // while(fast != nullptr && fast->next != nullptr){
        //     slow = slow -> next;// move slow by 1 .
        //     fast = fast -> next -> next;//move fast by 2.
        // }

        // return slow;
    }
};