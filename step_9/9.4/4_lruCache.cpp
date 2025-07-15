#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key, int value) {
        this->key = key;
        this->val = value;
        this->next = NULL;
        this->prev = NULL;
    }
};
class LRUCache {
    // key-node
    unordered_map<int, Node*> mp;
    Node* start = new Node(-1, -1);
    Node* end = new Node(-1, -1);
    int size;

public:
    LRUCache(int capacity) {
        size = capacity;
        // linking start and end
        start->next = end;
        end->prev = start;
    }
    void addnode(Node* newnode) {
        Node* temp = start->next;
        newnode->next = temp;
        newnode->prev = start;
        start->next = newnode;
        temp->prev = newnode;
    }
    void deletenode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* target = mp[key];
            int res = target->val;
            mp.erase(key);
            // removing that node from list
            deletenode(target);
            // putting that node after the dummy head
            addnode(target);
            // update map and return the value
            mp[key] = start->next;
            return res;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // if key already exists
            Node* target = mp[key];
            target->val = value;
            mp.erase(key);
            // removing that node from list
            deletenode(target);
            // putting that node after the dummy head
            addnode(target);
            // update the map
            mp[key] = start->next;
        } else {
            // if key doesn't exist
            if (mp.size() == size) {
                // if limit is reached delete the node before dummy end
                Node* dlt = end->prev;
                deletenode(dlt);
                mp.erase(dlt->key);
                delete (dlt);
            }
            // create a new node, put it after dummy head and update it in map
            Node* newnode = new Node(key, value);
            mp[key] = newnode;
            addnode(newnode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */