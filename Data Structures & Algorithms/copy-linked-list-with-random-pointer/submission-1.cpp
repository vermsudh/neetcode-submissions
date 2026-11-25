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
        //We are going to divide the solutions in parts. 

        //We have been given that head of the LL of length n. We have a single LL that contains two pointers. One is 
        //next pointer and the other one is random pointer. 

        //Next pointer points to the next node in the LL. Just like a normal pointer of a single LL. 
        //Example : head -> 3 -> 7 -> 4 -> 5 -> null
        //However, we have random pointers which points randomly to any nodes. 
        //Example: head -> 5->7->4->3->null 

        //We need to create a deep copy of this LL where the memory address of pointers should be different but should point to the right nodes for 
        //random and next pointers. 

        //We can solve this question using hashmaps to store the addresses of the new and old LL of each node. 
        //     old(key).     new(value).   Storing memeory addresses which will help us to make connections between the random nodes later
        // m = [   3      ,     3      ]  
        //     [   7      ,     7      ]  
        //     [   4      ,     4      ]  
        //     [   5      ,     5      ]

        //Step1)  a) Make a simple copy of the orginalLL and CopiedLL. 
                // originalLL = head -> 3 -> 7 -> 4 -> 5 -> null
                // copiedLL   = head -> 3 -> 7 -> 4 -> 5 -> null
                //b) Store the memeory address of each nodes in the map while we traverse over the original LL.
        
        //val is the value of the nodes | A next pointer to the new node corresponding to the next pointer of the original node | A random pointer to the new node corresponding to the random pointer of the original node

        //Lets create a new Node first of the copied LL. 

        //One base case that we have to keep in mind is when our head is nullptr. 
        if(head == nullptr){
            return nullptr;// IN this case, we will return null. 
        }

        Node* newHead = new Node(head -> val); // This will create a new Node 3 (head->val) is the original LL head value that we are assigning to copied LL head
        
        //We have an unordered_map to store the memory address.
        unordered_map<Node*, Node*> m;


        //Now, we would need to two pointers to travese over the LL.
        Node* oldTemp = head -> next; // This is pointing to Node 7 of the original LL
        Node* newTemp = newHead; // This is pointing to new Head which is 3. 

        //At first, we need to store the memory address of the head and the new Head. 
        m[head] = newHead;

        while(oldTemp != nullptr){
            //We need to copy each nodes of original LL to copied LL. 

            //First we would need to create a node for the copied LL.
            Node* copyNode = new Node(oldTemp -> val);// This will create Node 7 on the first iteration. 
            //Second, we are going to form a connection. 
            //Now we have to point the next poting of newHead to copyNode :Therefore, 7 -> 3
            newTemp -> next = copyNode;

            //We need to store the rest of the nodes after the head in the maps. 
            m[oldTemp] = copyNode;
            
            //Now, we need to move the pointers oldTemp and newTemp. 
            oldTemp = oldTemp -> next;
            newTemp = newTemp -> next;

            //2) iteration
            // copyNode = 4
            // newConnection = 7 -> 3 -> 4

            // 3) iteration
            // copyNode = 5
            // New Connection =7 -> 3 -> 4 -> 5

            // 4) iteration 
            // copyNode = null
            // New Connection = 7 -> 3 -> 4 -> 5 -> null;
        }

        //Now we need to bring the oldTemp and newTemp again to their original heads to iterate again over them to form random pointers connections. 

        oldTemp = head;
        newTemp = newHead;
        //Step2) Now, we need to form a random connections between the nodes from orginal LL to copied LL. 
        
        //We are going to run a loop again till oldTemp != null.
        while(oldTemp != nullptr){
            //We need to point the random pointers. 
            //We know the memory address of each nodes that are being stored in the hashmaps. 
            // m = [   3      ,     3      ]  
            //     [   7      ,     7      ]  
            //     [   4      ,     4      ]  
            //     [   5      ,     5      ]

            //Now, we look at the example: Node 4 random pointer is pointing Node 3 which means. 
            //We have to map newTemp random pointers to the right node. 
            newTemp -> random = m[oldTemp -> random];
            
            //Now we have to increment the oldTemp and newTemp
            oldTemp = oldTemp -> next;
            newTemp = newTemp -> next;
        }

        //Return the head of the copied linked list.
        return newHead;
    }
};
