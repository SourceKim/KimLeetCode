/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (42.21%)
 * Likes:    1082
 * Dislikes: 39
 * Total Accepted:    258.5K
 * Total Submissions: 610.8K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */

#include "helper/helper.hpp"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        vector<vector<int>> res;

        vector<int> tmpPath;

        dfs(root, res, tmpPath, sum);

        return res;
    }

private:
    void dfs(
    TreeNode *node, // 节点
    vector<vector<int>> &validPath, // 可用的 path
    vector<int> &lastPath, // 这条路径，上一次的保存值
    int sum) {

        if (!node) return;

        // 先保存一下当前这颗节点
        lastPath.push_back(node->val);

        // 得到结果，有两个条件：
        // 1. sum 正好相等
        // 2. 是 leaf 节点
        if (sum == node->val && !node->left && !node->right)  {
            validPath.push_back(lastPath);
        }

        // dfs
        dfs(node->left, validPath, lastPath, sum - node->val);
        dfs(node->right, validPath, lastPath, sum - node->val);

        // 这颗节点玩完之后，要 pop 回去
        lastPath.pop_back();
    }
};
// @lc code=end

