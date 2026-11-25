/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Base Case : 
        //If our old LL has nullptr at first only.
        if(head == nullptr){
            return nullptr;
        }
        //Lets create a unordered_map to store the address of oldNode and CopyNode

        unordered_map<Node*, Node*> m;

        //Lets break this down this into smaller parts. 

        //1) We will have create a copy of the LL that we have with the 
        //normal next pointers. 

        //2) We will copy the random pointers after creatin the copy LL. 

        //Since we need a new head of the new LL. 
        Node* newHead = new Node(head -> val); // this will create 7 as a  new head of the new LL. 
        //We need two pointers now which will traverse over these two LL. 

        //oldLL = 3 -> 7 -> -> 4 -> 5 -> null
        //newLL = 3 (right now)

        Node* oldTemp = head -> next; // this is pointing to 7 rn
        Node* newTemp = newHead; // this is pointing to 3 rn
        //We need to store the copy node of head and newHead in the map 
        m[head] = newHead;

        //Now, we have to run a loop to traverse over old LL using oldTemp and copy its nodes one by one to newLL. 
        //Step 1) We need to create a new LL with the normal nodes that old LL has and the its next pointers connections as well. 
        //Also, we would need to store the address of the old Node and new Nodes in the hashmaps.

        while(oldTemp != nullptr){// we will move this loop until the oldTemp will reach at null
            //We need a new Node after newHead now which is a copy of oldTemp
            Node* copyNode = new Node(oldTemp -> val); // first iteration would be : node after 3 should be 7.          
            //Lets store the memeory address of each nodes in the map
            m[oldTemp] = copyNode;
            //Now, we need to establish the connection 3 -> 7

            newTemp -> next = copyNode;  
            //Since newTemp is at 3. We are pointing its next pointer at new Node which is 7. 
            //Now, we are going to move the pointers. 
            oldTemp = oldTemp -> next;
            newTemp = newTemp -> next;
        }

        //Now initlize the oldTemp and newTemp as heads.
        oldTemp = head;
        newTemp = newHead;
        // Since we have to travese again over the nodes. 

        while(oldTemp != nullptr){
            newTemp->random = m[oldTemp->random];
            oldTemp = oldTemp -> next;
            newTemp = newTemp -> next;
        }

        return newHead;
    }
};
