/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (39.32%)
 * Likes:    1093
 * Dislikes: 52
 * Total Accepted:    82.6K
 * Total Submissions: 204.5K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's
 * permutations is the substring of the second string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "ab" s2 = "eidbaooo"
 * Output: True
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 * 
 * 
 */

#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;

using std::vector;
using std::string;

/* 
    考察滑动窗口，滑动窗口可以保证这些字符是连在一起的
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int size1 = s1.size(), size2 = s2.size();

        if (size1 > size2) return false;

        vector<int> map1(26), map2(26);

        // 1. 统计 s1 中每个元素在 s1 & s2 出现的次数
        for (int i = 0; i < size1; i++) {
            map1[s1[i] - 'a']++;
            map2[s2[i] - 'a']++;
        }

        if (map1 == map2) return true;

        // 2. 滑动
        for (int i = 0; i + size1 < size2; i++) {
            map2[s2[i] - 'a']--;
            map2[s2[i + size1] - 'a']++;
            if (map1 == map2) return true;
        }

        return false;
    }
};
// @lc code=end

