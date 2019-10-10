/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (27.67%)
 * Likes:    3701
 * Dislikes: 152
 * Total Accepted:    362.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * The cache is initialized with a positive capacity.
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * 
 * LRUCache cache = new LRUCache( 2 /* capacity * );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 * 
 * 
 */
#include <list>
#include <stdio.h>
#include <unordered_map>
using namespace std;
// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {

        if (hashMap.find(key) != hashMap.end()) { // 能找到的话

            // 用 put 带到 list 头
            int value = hashMap[key]->second;
            put(key, value);
            return value;
        }

        return -1;
        
    }
    
    void put(int key, int value) {
        
        if (hashMap.find(key) != hashMap.end()) {

            // 在 hash map 中找到的话，就移除掉
            cache.erase(hashMap[key]);

        } else {

            // 不存在 hash map 中，就需要对比一下 size
            if (cache.size() >= size) {
                // 超过 size 则移除掉 最后一个 （cache & hashMap）
                hashMap.erase(cache.back().first);
                cache.pop_back();
            }

        }

        // 加入到 hashMap & cache 中
        cache.push_front( {key, value} );
        hashMap[key] = cache.begin();
    }

private:

    int size;
    list<pair<int, int>> cache; // 双向链表
    unordered_map<int, list<pair<int, int>>::iterator> hashMap; // 哈希 map

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

