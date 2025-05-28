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
        if(!head) return nullptr;

        unordered_map<Node*, Node*> mpp;

        // set the top level node (head)
        Node* curr = head;

        while(curr != nullptr) {
            mpp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        //set the random and next pointer
        curr = head;
        while(curr != nullptr) {
            mpp[curr]->next = mpp[curr->next];
            mpp[curr]->random = mpp[curr->random];
            curr = curr->next;
        }

        return mpp[head];
    }
};