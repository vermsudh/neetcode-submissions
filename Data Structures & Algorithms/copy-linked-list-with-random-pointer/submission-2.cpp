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
        
        //if head is null, return null
        if(head == nullptr){
            return nullptr;
        }
        
        Node* newHead = new Node(head -> val);// creates new node 3
        //We need hashmaps to storeh the memeory address of the old nodes and new nodes. 
        unordered_map<Node*, Node*>m;

        Node* oldTemp = head -> next;
        Node* newTemp = newHead;

        //Store the heads that we have initlized.
        m[head] = newHead;

        while(oldTemp != nullptr){
            //Create a new node. 
            Node* copyNode = new Node(oldTemp -> val); //creating node 7 in first iteration.

            //Form a connection between the nodes Node 3 -> Node 7
            newTemp -> next = copyNode;

            //Store the old and new nodes. 
            m[oldTemp] = copyNode;

            //Move the pointers. 
            oldTemp = oldTemp -> next;
            newTemp = newTemp -> next;
        }

        //Bring oldTemp and newTemp back to heads.
        oldTemp = head;
        newTemp = newHead;

        while(oldTemp != nullptr){
            //Form the the random connections now. 
            newTemp -> random = m[oldTemp -> random];

            //Move the pointers. 
            oldTemp = oldTemp -> next;
            newTemp = newTemp -> next;
        }

        return newHead; 
    }
};
