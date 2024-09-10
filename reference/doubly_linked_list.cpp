/* 
 * doubly linked list implementation
 *
 * ListInitialize
 * addToHead
 * isListEmpty
 * removeNode
*/
#define DEBUG 1
#if(DEBUG)
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
#endif

struct node
{
    int key;
    int value;
    struct node* next;
    struct node* prev;
};

class LRUCache {
public:
    unordered_map<int,struct node*> hashtable;
    unordered_map<int,struct node*> :: iterator it;

    // DLL - dummy head and tail
    struct node head;
    struct node tail;
    int total_size = 0;
    int size = 0;

    void printlist()
    {
        struct node* tranode = head.next;
        cout << "Print List:  " << endl;
        while(tranode != &tail)
        {
            cout << tranode->key << " ";
            tranode = tranode->next;
        }
        cout << endl;
    }

    struct node* createNewNode(int key, int value) {
        struct node* nnode = new node();

        nnode->key = key;
        nnode->value = value;
        nnode->prev = nnode->next = 0;
        return nnode;
    }

    void ListInitialize()
    {
        head.next = &tail;
        head.prev = 0;

        tail.next = 0;
        tail.prev = &head;
    }

    void addToHead(struct node* tnode)
    {
        // if empty, modify tail's prev
        struct node* NEXT = head.next;
        if(isListEmpty())
        {
            tail.prev = tnode;
        }
        else
        {
            NEXT->prev = tnode;
        }

        tnode->next = NEXT;
        tnode->prev = &head;

        head.next = tnode;

        size++;
    }

    bool isListEmpty() {
        return (head.next == &tail);
    }

    void removeTail()
    {
        if(!isListEmpty())
        {
            removeNode(tail.prev);
        }
    }

    void removeNode(struct node* tnode)
    {
        struct node* PREV = tnode->prev;
        struct node* NEXT = tnode->next;

        // Link prev and next nodes
        if(PREV)
            PREV->next = NEXT;
        
        if(NEXT)
            NEXT->prev = PREV;

        // reset pointers and reduce size
        tnode->prev = tnode->next = 0;
        size--;
    }

    void adjustList(struct node* tnode)
    {
        removeNode(tnode);
        addToHead(tnode);
    }

    LRUCache(int capacity) {
        
        hashtable.clear();
        total_size = capacity;
        size = 0; 
        ListInitialize();
    }
    
    int get(int key) {
        
        printlist();
        
        it = hashtable.find(key);

        if(it == hashtable.end()) {
            return -1; // if not in cache return -1;
        }
        else {
            struct node* tnode = it->second;

            // if in cache
            if(tnode->prev && tnode->next) {
                adjustList(tnode);
                printlist();
                return tnode->value;
            }
            else // if not in cache
            {
                return -1;
            }
        }

        return -1;
    }
    
    void put(int key, int value) {
        
        // cout << "put :" << key << " " << value << endl;
        it = hashtable.find(key);

        // new entry
        if(it == hashtable.end()) {
           // cout << "new" << endl;
            // new
            struct node* tnode = createNewNode(key, value);

            hashtable[key] = tnode;  // add to hash

            addToHead(tnode); // add to linked list
        }
        else {
            // existing
            struct node* tnode = it->second;
            tnode->value = value;
            tnode->key = key;

            // if node is presnt currently in LRU
            if(tnode->prev && tnode->next) {
                removeNode(tnode);
            }

            // add to the cache
            addToHead(tnode);
        }

        if(size > total_size)
        {
            removeTail();
        }

        printlist();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
#if(DEBUG)
int main()
{
    class LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    lRUCache->get(1);    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache->get(2);    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache->get(1);    // return -1 (not found)
    lRUCache->get(3);    // return 3
    lRUCache->get(4);    // return 4
}
#endif