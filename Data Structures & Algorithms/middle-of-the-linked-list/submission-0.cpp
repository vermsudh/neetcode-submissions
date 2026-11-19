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
        //I will discussing 2 approach to solve this question.
        //First, we can traverse over the ll twice. 
        //In first traversal, we would need to calculate the length of the LL.
        //Since we have a function ll.size() to check the size of the LL. 
        //But we can't use that as ListNode is a structure not a LL. 

        //Since we have to return output : [3,4,5] when head is [1,2,3,4,5]
        
        //Firstly, we would need to store the head in a different varailble so that head does not move from its original node which is the first node. 

        ListNode* temp = head;// temp is copy of head which will traverse over LL. 
        int n = 0;// We are going to store the count in n.
        while(temp != NULL) // we need to travese till a point when temp reaches the last node which is pointing to NULL.
        {
            //This loop will help us to calculate the length of the LL. 
            n++;
            //incrementing the temp one by one. 
            temp = temp -> next;
        }
        //Now, we have n which has the number of counts of nodes in the LL. 

        //We can caluclate the mid point by using a formula n/2;

        int mid = n/2;//this will give us the mid point of the LL. 

        //Now, we would need to run a while loop again from 0 to mid point. 

        int i = 0;
        //We would need to assign temp again to head it is on TAIL right now. 
        temp = head;
        while(i < mid){
            i++;
            temp = temp -> next;// this will traverse from 0 to mid. 
        }
        return temp;//Now, when we return temp. We will have all the nodes from mid to Tail node. 


        // 2nd Approach would be to use slow fast pointer approach. 
    }
};