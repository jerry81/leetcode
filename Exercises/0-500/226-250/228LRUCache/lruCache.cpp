/*

146. LRU Cache
Medium
18.1K
800
Companies
Design a data structure that follows the constraints of a Least Recently Used
(LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return
-1. void put(int key, int value) Update the value of the key if the key exists.
Otherwise, add the key-value pair to the cache. If the number of keys exceeds
the capacity from this operation, evict the least recently used key. The
functions get and put must each run in O(1) average time complexity.



Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4


Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
Accepted
1.4M
Submissions
3.3M
Acceptance Rate
41.1%

*/

#include <unordered_map>

using namespace std;

/*

new strat -
DLL
map of ptrs

every action is delete and insert
*/

struct Node {
  int val;
  int key;
  Node* next;
  Node* prev;
};
void print(Node* fr) {
  cout << "-------PRINTING------" << endl;
  while (fr != nullptr) {
    cout << "key is " << fr->key << endl;
    fr = fr->next;
  }
  cout << "------DONE--------"<<endl;
}
class LRUCache {
  int _capacity;
  unordered_map<int, Node*> cache;
  int seq;
  int count;
  Node* front = nullptr;
  Node* back = nullptr;

 public:
  LRUCache(int capacity) {
    _capacity = capacity;
    seq = 0;
    count = 0;
  }

  int get(int key) {
   // cout << "-----GET-----" << key << endl;
    if (cache.find(key) == cache.end()) {
      return -1;
    } else {
      Node* toRmv = cache[key];

      cache.erase(key);
     // cout << "stitching " << endl;
      if (toRmv->prev != nullptr) {
     //   cout << "toRmv prev is something " << endl;
        toRmv->prev->next = toRmv->next;
      }

      if (toRmv->next != nullptr) {
      //  cout << "toRmv next is something " << endl;
   //     cout << "it is " << toRmv->next->key << endl;;
        toRmv->next->prev = toRmv->prev;
      }
      if (front != nullptr && front == toRmv) {
        front = front->prev;
        if (front != nullptr) front->next = nullptr;
        // cout << "front replaced and is now " << front->key << endl;
      }
      if (back == toRmv) {
        back = back->next;
        if (back != nullptr) back->prev = nullptr;
      }

      Node* n = new Node();
      n->key = key;
      n->val = toRmv->val;
      if (back != nullptr) {
        back->prev = n;
        n->next = back;
      }

      cache[key] = n;

      back = n;

      if (front == nullptr) front = n;
    //  cout << "get " << key << endl;
     // print(back);
      return back->val;
    }
  }

  void put(int key, int value) {
  //  cout << "-----PUT-----" << key <<","<<value<< endl;
    Node* n = new Node();
    n->val = value;
    n->key = key;
    if (cache.find(key) == cache.end()) {
      // add
      // if capacity not reached.
      if (count < _capacity) {
        count++;
      } else {

        Node* toRmv = front;

     //   cout << "will remove " << toRmv->key << endl;
        cache.erase(toRmv->key);
        if (toRmv->prev != nullptr) {
          toRmv->prev->next = toRmv->next;
          front=front->prev;

        }
        if (toRmv->next != nullptr) {
          toRmv->next->prev = toRmv->prev;
        }

      }
    } else {
      // update
      Node* toRmv = cache[key];
      if (front == cache[key]) {
        front = front->prev;
        if (front != nullptr) front->next = nullptr;
      }
      if (back == cache[key]) {
        back = back->next;
        if (back != nullptr) back->prev = nullptr;
      }
      cache.erase(key);

      if (toRmv->prev != nullptr) {
        toRmv->prev->next = toRmv->next;
      }
      if (toRmv->next != nullptr) {
        toRmv->next->prev = toRmv->prev;
      }
    }

    if (front == nullptr) {
      front = n;
    }

    if (back != nullptr) {
      back->prev = n;
      n->next = back;
    }
    back = n;
    cache[key] = n;
  //  cout << "set key " << key << endl;
  //  cout << "front is " << front->key << endl;
  //  cout << "back is " << back->key << endl;
    // print(back);
  }
};