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
    bool hasCycle(ListNode* head) {
        //brute force approach would be to use uordered_set and loop. 

        //Since set have a unique capability to check if memory address 
        //occurred once or twice? 

        unordered_set<ListNode*> visited;//since we are going to pass a pointer 
        //temp. we need to define this. 

        //We would need to take a temp pointer and assign it to head. 
        ListNode* temp = head;

        //Now we run a loop till the time we have temp to nullptr

        //In the cycle, there will not nullptr as it will be pointing to the previous node. But we will return true if we see any temp repeating twice. 

        while(temp != nullptr){
            if(visited.find(temp) != visited.end()){
                return true;
            }
            visited.insert(temp);

            //now we need to increment the temp. 
            temp = temp -> next;
        }
        return false; //if there is not cycle. 
    }
};
