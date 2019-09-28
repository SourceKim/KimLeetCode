/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (48.28%)
 * Likes:    849
 * Dislikes: 162
 * Total Accepted:    250.7K
 * Total Submissions: 518.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
 */

// @lc code=start
// #include <vector>
// #include <stdio.h>
// #include <iostream>
// #include <stack>
// #include <queue>
// using namespace std;

// struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        queue<TreeNode *> q;
        stack<vector<int>> st;

        if (root != NULL) {
            q.push(root);
        }

        while (!q.empty()) {

            int qSize = q.size();
            vector<int> vec;

            for (int i = 0; i < qSize; i++)
            {
                TreeNode *top = q.front();
                q.pop();

                vec.push_back(top->val);

                if (top->left != NULL) {
                    q.push(top->left);
                }
                if (top->right != NULL) {
                    q.push(top->right);
                }
            }
            // 压入栈里面
            st.push(vec);
            
        }
        vector<vector<int>> v;

        while (!st.empty())
        {
            vector<int> top = st.top();
            v.push_back(top);
            st.pop();
        }
        
        return v;
    }
};
// @lc code=end

