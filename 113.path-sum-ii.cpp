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
#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        if (sum < 0) return {{}};

        vector<vector<int>> res;

        int target = sum - root->val;

        for (vector<int> left : pathSum(root->left, target)) {

            int 
        }
    }

private:
    void recursive(
    TreeNode *node, // 节点
    vector<vector<int>> &validPath, // 可用的 path
    vector<int> lastPath, // 这条路径，上一次的保存值
    int sum, 
    int lastSum) {

        if (node != NULL) { // 终止

            lastPath.push_back(node->val); // 加入到 path
            lastSum += sum; // 更新 sum

            // 递归左右
            recursive(node->left, validPath, lastPath, sum, lastSum);
            recursive(node->right, validPath, lastPath, sum, lastSum);

            // 更新可用路径
            if (node->left == NULL && node->right == NULL && lastSum == sum) {

                validPath.push_back(lastPath);
                
            }
        } 
    }
};
// @lc code=end

