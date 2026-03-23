class LRUCache {
public:
    class Node{
        public:
        int val;
        int key;
        Node* next;
        Node* prev;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            next=nullptr;
            prev= nullptr;
        }
    };

    unordered_map<int,Node*> mpp;
    int capacity;
    Node* head= new Node(-1, -1);
    Node* tail = new Node(-1,-1);

    void deleteCurrPos(Node* temp) {
        if (!temp || !temp->prev || !temp->next) return;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->prev = nullptr;
        temp->next = nullptr;
    }

    void addToHeadNxt(Node* temp) {
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        // check if exists
        if(mpp.find(key) == mpp.end()) {
            return -1;
        }

        // if exists delete form current pos & move it next to head
        Node* temp = mpp[key];
        deleteCurrPos(temp);
        addToHeadNxt(temp);

        // return
        return temp->val;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* temp = mpp[key];
            deleteCurrPos(temp);
            addToHeadNxt(temp);
            temp->val = value;
            return;
        }

        if (mpp.size() >= capacity) {
            Node* temp = tail->prev;
            mpp.erase(temp->key);
            deleteCurrPos(temp);
            delete temp;
        }

        Node* newNode = new Node(key, value);
        addToHeadNxt(newNode);
        mpp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */