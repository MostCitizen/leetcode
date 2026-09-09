class Node{
public: 
    Node(int key, int value){
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
    int key;
    int value;
    Node* prev;
    Node* next;
};
class LRUCache {
private:
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;
    int capacity;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insert(Node* node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!map.contains(key)) {
            return -1;
        }
        Node* node = map[key];
        remove(node);
        insert(node);
        return node->value;
    }

    void put(int key, int value) {
        if (map.contains(key)) {
            Node* node = map[key];
            node->value = value;
            remove(node);
            insert(node);
            return;
        }
        Node* node = new Node(key, value);
        map[key] = node;
        insert(node);

        if (map.size() > capacity) {
            Node* lru = head->next;
            remove(lru);
            map.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */