/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (29.89%)
 * Likes:    1307
 * Dislikes: 448
 * Total Accepted:    272.7K
 * Total Submissions: 911.9K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */

#include <vector>
using namespace std;
// @lc code=start
/* 
    关键：
        在遍历的时候，把 不是素数 的先记录下来
        这个 不是素数 的定义就是 i * j 的结果，因为能相乘得到的都不是素数
 */
class Solution {
public:
    int countPrimes(int n) {
        
        vector<bool> isPrime (n + 1, true); // 默认都是素数

        int res = 0;

        for (int i = 2; i < n; i++) {
            
            if (!isPrime[i]) continue; // 剪枝，不是素数直接返回，避免重复运算

            res++;

            for (int j = 2; j * i < n; j++) isPrime[j * i] = false;
        }

        return res;
    }
};
// @lc code=end

