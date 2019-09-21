/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.86%)
 * Likes:    6386
 * Dislikes: 367
 * Total Accepted:    1.1M
 * Total Submissions: 3.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

// #include <stdio.h>
// #include <iostream>
// #include <map>
// using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int sSize = s.size();
        if (sSize == 0) {
            return 0;
        }

        map<char, int> m;
        int maxLength = 0;

        int lastInMapPosition = 0; // 最后一个已经在数组出现的位置

        for (int i=0; i<sSize; i++) {
            char c = s[i];
            map<char, int>::iterator iter;
            iter = m.find(c);

            if (iter != m.end()) {
                
                // 找到了，就 做对比

                int inMapPosition = iter->second;

                if (inMapPosition - 1 >= lastInMapPosition) {
                    lastInMapPosition = inMapPosition;
                }
                // int length = i - inMapPosition;
                // if (length > maxLength) {
                //     maxLength = length;
                // }
                // lastInMapPosition = i;
                // if (firstInMapPosition == -1) {
                //     firstInMapPosition = inMapPosition + 1;
                // }
            } 
            // 更新位置
            m[c] = i + 1;

            if (i - lastInMapPosition + 1 > maxLength) {
                maxLength = i - lastInMapPosition + 1;
            }
        }

        // cout << maxLength << endl;
        // cout << firstInMapPosition << endl;
        // cout << lastInMapPosition << endl;

        // if (firstInMapPosition > maxLength) {
        //     maxLength = firstInMapPosition;
        // }

        // 看下到最后有没有更长的
        // int length = sSize - lastInMapPosition;
        // if (length > maxLength) {
        //     maxLength = length;
        // }
        // for(iter = m.begin() ; iter != m.end() ; iter++ )
        // {
        //     int length = sSize - iter->second;
        //     if (length > maxLength) {
        //         maxLength = length;
        //     }
        // }
        
        return maxLength;
    }
};

// int main(int argc, char const *argv[])
// {
//     Solution *sol = new Solution();

//     string s = "au";

//     int length = sol->lengthOfLongestSubstring(s);

//     cout << length << endl;
    
//     return 0;
// }


