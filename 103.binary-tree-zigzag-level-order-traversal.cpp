/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (51.44%)
 * Likes:    4044
 * Dislikes: 135
 * Total Accepted:    558.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the zigzag level order traversal of
 * its nodes' values. (i.e., from left to right, then right to left for the
 * next level and alternate between).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[20,9],[15,7]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1]
 * Output: [[1]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 2000].
 * -100 <= Node.val <= 100
 * 
 * 
 */

#include "helper/helper.hpp"

/*
    按层遍历，使用循环 size 的方式

    然后每一层都按需反向一下
*/

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if (!root) return {};
        
        vector<vector<int>> res;

        queue<TreeNode *> q;
        q.push(root);

        bool reverse = false; // 是否反向
        while (!q.empty())
        {
            int len = q.size();
            vector<int> levelRes(len);
            for (int i=0; i<len; i++) {

                TreeNode *top = q.front();
                q.pop();

                int idx = reverse ? len - 1 - i : i;
                levelRes[idx] = top->val;

                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }

            reverse = !reverse;
            res.push_back(levelRes);
        }

        return res;
    }
};
// @lc code=end

