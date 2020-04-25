/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (47.76%)
 * Likes:    2066
 * Dislikes: 80
 * Total Accepted:    222.3K
 * Total Submissions: 464.3K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */
#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        
        vector<int> dp (n+1, 0); // 含义 是 「以 key 为树的节点数量，value 为有多少个组合」

        // 设置初始状态：
        dp[0] = 1; // 当 没有节点 的时候，只有一种组合方式
        dp[1] = 1; // 当 只有一个节点 的时候，只有一种组合方式

        // 设子节点可以有 2-n 个
        for (int i=2; i<=n; i++) {

            // 设 j 为左边节点的数量
            for (int j=0; j<i; j++) {

                // 状态转移，dp[i] 等于 左右节点的总和（相乘）
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n];

    }
};
// @lc code=end

