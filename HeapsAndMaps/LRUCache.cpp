/*
Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations:
get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should
invalidate the least recently used item before inserting the new item.
The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of 
unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. 
“Least recently used” item is the one with the oldest access time.

 NOTE: If you are using any global variables, make sure to clear them in the constructor. 
Example :

Input : 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 

https://www.interviewbit.com/problems/lru-cache/
*/

#include "bits/stdc++.h"

list<pair<int, int> > dq;
unordered_map<int, list<pair<int, int> >::iterator> hash;
int cache = 0;

LRUCache::LRUCache(int capacity) {
    cache = capacity;
    dq.clear();
    ::hash.clear();
}

int LRUCache::get(int key) {
    if (::hash.find(key) == ::hash.end())
        return -1;
    else {
        list<pair<int, int> >::iterator it = ::hash[key];
        int val = it->second;
        dq.erase(it);
        dq.push_front(make_pair(key, val));
        ::hash[key] = dq.begin();
        return val;
    }
}

void LRUCache::set(int key, int value) {
    if (::hash.find(key) == ::hash.end()) {
        if (dq.size() == cache) {
            auto last = dq.back();
            dq.pop_back();
            ::hash.erase(last.first);
        }
    } else {
        list<pair<int, int> >::iterator it = ::hash[key];
        dq.erase(it);
    }
    dq.push_front(make_pair(key, value));
    ::hash[key] = dq.begin();
}
