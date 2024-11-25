
// Design a search data structure to store and display recent searches. If
// a user just clicks the search bar without typing anything, it should
// return the N most recent searches. Given a search string it should save
// the search and also return the N most recent searches

class Node{
public:
    Node* next;
    Node* prev;
    int key;
    int value;

    Node(int key, int value){
        this->key = key;
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};


class LRUCache {
public:

    int capacity;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> cache;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;        
    }

    void remove(int key){
        Node* curr = cache[key];
        Node* prevEle = curr->prev;
        Node* nextEle = curr->next;

        prevEle->next = nextEle;
        nextEle->prev = prevEle;

        cache.erase(key);
    }

    void add(int key, int value){
        Node* nextEle = head->next;
        Node* newNode = new Node(key, value);

        head->next = newNode;
        nextEle->prev = newNode;
        newNode->next = nextEle;
        newNode->prev = head;

        cache[key] = newNode;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }

        Node * node = cache[key];
        remove(key);
        add(key, node->value);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(key);
        }
        add(key, value);

        if(cache.size() > capacity){
            // Find the least recently used
            Node* lru = tail->prev;
            remove(lru->key);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */