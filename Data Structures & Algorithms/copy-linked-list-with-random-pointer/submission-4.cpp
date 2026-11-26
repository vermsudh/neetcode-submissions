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
        //One edge case would when our LL can be null, in that case, we can just return.
        if(head == nullptr){
            return nullptr;
        }

        //We have been given a LL of length n. 
        //THis is a singly Linked List. 
        //Each node have two pointers. 
        //1) next -> pointer which is pointing to next node in the LL. 
        // A next pointer to the new node corresponding to the next pointer of the original node
        // Example : head : 3 -> 7 -> 4 -> 5 -> null

        // 2) random -> pointer which is pointing at random pointer. 
        //Example: 4-> 3 -> 7-> 5->3-> null

        // A random pointer to the new node corresponding to the random pointer of the original node

        //We have to create a copied LL which should have similar pointers with different memeory address. 
        //Note: None of the pointers in the new list should point to nodes in the original list. We have to 
        //make sure that we have distintive memeory address stored in the new LL. 
        // Constraints:

        // 0 <= n <= 100
        // -100 <= Node.val <= 100
        // Node values are not guaranteed to be unique.
        // random is null or is pointing to some node in the linked list.
        
        //We are going to divide this problem into two steps. 

        //Step 1) We are just going to create a copy of the single LL with normal next pointers by taking two temp pointers. 

        //Since we have would need to create random connections in the next loop. 
        // we would have to use hashmaps to store the memory addresses of each nodes of original LL and copied LL which will assist us to form random connections in the next loop.

        

        //Now, lets create a copied list. 
        //We know that our current head node is at 3 right now. 

        //We would have to create a newHead for our copied LL. 
        //We can create a new Object using Node class. 

        Node* newHead = new Node(head -> val); // This stores the value. head is a pointer and head -> val stores the value in this pointer which is Node 3.

        //Now, we would need to run a loop over the original LL. 
        //We are going to use temp pointer as we are going to move the pinter till the last point and we do not want our orginal head pointer to do that.
        //If we use our original pointer to travese over the LL. Then we can potentially loose our LL as head will move to the last node after the loop and it can change the LL. 

        //Lets create a hashmap.
        unordered_map<Node*, Node*> m; // We are going to store the pointers memeory address in the map. \

        //We have to store the memory address of the first node that we have created. 
        m[head] = newHead; // This will store the memory addresses of the head and newHead. 

        Node* oldTemp = head -> next;// Since we have already copied the head. Now we need to travese over the nodes after the first node of the original LL. 
        Node* newTemp = newHead;// This will start from newTemp. 

        while(oldTemp != nullptr){
            //Inside the loop, we have two main task. 
            // 1) To create a new Node. 
            Node* copyNode = new Node(oldTemp -> val);// Now we have to create Node 7

            // 2) Form a next pointer connection and form connection between Node 7 and Node 3 which should be 3 -> 7.
            //We would have to point our newTemp -> next to copyNode. 

            newTemp -> next = copyNode;
            //Since we have to store the memory address of all the nodes.
            m[oldTemp] = copyNode; // This will store the memory address of each nodes as we traverser over the original LL. 

            //Now, we would have to move our pointers. 
            //First we will move our old Temp and then newTemp. 
            oldTemp = oldTemp -> next;
            newTemp = newTemp -> next;

            //1) iteration, we will have this LL at copied version newHead = [3 -> 7]; 
                //oldTemp will be at Node 4 now. 
                //newTemp will be at Node 7. 
            
            //2)iteration, we will have this LL at copied version newHead = [3 -> 7 -> 4]; 
            //oldTemp will be at Node 5 now. 
            //newTemp will be at Node 4. 

            //3)iteration, we will have this LL at copied version newHead = [3 -> 7 -> 4 -> 5]; 
            //oldTemp will be at Node null now. 
            //newTemp will be at Node 5. 

            //Now, we have to stop the loop when oldTemp != nullptr;
        }

        //Now, we have newTemp and oldTemp pointing at null and last node. 
        //Since we need to do one more traversal, we would need to move both at original heads. 

        oldTemp = head;
        newTemp = newHead;
        //Step 2) Then, we are going to create connections with the random pointers.

        while(oldTemp != nullptr){
            //Now we need to form random connections and move the the pointers. 
            //Since we need to know what our random pointer will pointing at? 
            
            //For example: We know that we have to form a random connection between Node 5 and Node 7.
            //Where Node 5 RANDOM pointer is pointing to Node 7. 
            //In this case, we need to check our hashmaps for the memory address. 
            //We have currenlt this in the hashmaps. 
            // m = [   0x100 (Node3)      ,    0x500 Node(3)      ]  
            //     [   0x200 (Node7)      ,    0x600 Node(7)      ]
            //     [   0x300 (Node4)      ,    0x700 Node(4)      ]
            //     [   0x400 (Node5)      ,    0x800 Node(5)      ]
            //Since Node 5 -> random is pointing to Node 7.
                    // 0x400 *       to    0x200  
            //We would need to assign 

            newTemp -> random = m[oldTemp -> random];// then we just have to form the same connection when oldTemp is at Node5, its random pointer will Node 7 which is 0x800 Node(5) -> random. = 0x600 Node(7)

            oldTemp = oldTemp -> next;
            newTemp = newTemp -> next;
        }

        return newHead;

    }
};
