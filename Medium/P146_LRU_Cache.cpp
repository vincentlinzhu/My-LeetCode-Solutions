struct Node {
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int x, int y){key = x; val = y; prev = NULL; next = NULL;}
 };

class LRUCache {
private:
    unordered_map<int, Node*> m;
    int capacity = 0;
    Node* LRU;
    Node* MRU;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        LRU = new Node(0, 0);
        MRU = new Node(0, 0);
        LRU->next = MRU;
        MRU->prev = LRU;
    }

    void remove(Node *n) {
        if (n->prev != NULL && n->next != NULL) {
            n->prev->next = n->next;
            n->next->prev = n->prev;
        }
    }

    void insert(Node *n) {
        n->next = MRU;
        n->prev = MRU->prev;
        if (MRU->prev != NULL) {
            MRU->prev->next = n;
            MRU->prev = n;
        }
    }
    
    int get(int key) {
        if (m.count(key)) {
            remove(m[key]);
            insert(m[key]);
            return m[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (m.count(key)) {
            remove(m[key]);
        }
        Node *n = new Node(key, value);
        m[key] = n;
        insert(m[key]);
        if (m.size() > capacity && LRU->next != NULL) {
            m.erase(LRU->next->key);
            remove(LRU->next);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */