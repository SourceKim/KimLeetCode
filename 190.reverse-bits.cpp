/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 *
 * https://leetcode.com/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (33.07%)
 * Likes:    644
 * Dislikes: 226
 * Total Accepted:    200.9K
 * Total Submissions: 607.4K
 * Testcase Example:  '00000010100101000001111010011100'
 *
 * Reverse bits of a given 32 bits unsigned integer.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 00000010100101000001111010011100
 * Output: 00111001011110000010100101000000
 * Explanation: The input binary string 00000010100101000001111010011100
 * represents the unsigned integer 43261596, so return 964176192 which its
 * binary representation is 00111001011110000010100101000000.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 11111111111111111111111111111101
 * Output: 10111111111111111111111111111111
 * Explanation: The input binary string 11111111111111111111111111111101
 * represents the unsigned integer 4294967293, so return 3221225471 which its
 * binary representation is 10101111110010110010011101101001.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Note that in some languages such as Java, there is no unsigned integer type.
 * In this case, both input and output will be given as signed integer type and
 * should not affect your implementation, as the internal binary representation
 * of the integer is the same whether it is signed or unsigned.
 * In Java, the compiler represents the signed integers using 2's complement
 * notation. Therefore, in Example 2 above the input represents the signed
 * integer -3 and the output represents the signed integer -1073741825.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * If this function is called many times, how would you optimize it?
 * 
 */
#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        cout << bitset<32>(n) << endl;

        uint32_t res = 0;

        // i 代表，从左边或者从右边数起的第 i 个
        for (int i=0; i<16; i++) {
            
            uint32_t left = 1 << (31 - i); // 1 左移 i 位 
            if ((n & left) > 0) { // 如果 n 的这一位大于 0
                res |= (left >> (31 - i * 2));
            }

            uint32_t right = 1 << i;
            if ((n & right) > 0) { // 如果 n 的这一位大于 0
                res |= (right << (31 - i * 2));
            }

        }

        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution *sol = new Solution();
    uint32_t res = sol->reverseBits(43261596);
    cout << res << endl;
    return 0;
}
