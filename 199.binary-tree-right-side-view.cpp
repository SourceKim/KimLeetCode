/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (57.52%)
 * Likes:    4592
 * Dislikes: 246
 * Total Accepted:    496.8K
 * Total Submissions: 863.6K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given the root of a binary tree, imagine yourself standing on the right side
 * of it, return the values of the nodes you can see ordered from top to
 * bottom.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,null,5,null,4]
 * Output: [1,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,null,3]
 * Output: [1,3]
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
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 * 
 * 
 */

#include "./helper/helper.hpp"

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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> res;

        if (!root) return res;

        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            // 这一层的最后一个加入结果
            TreeNode *last = q.back();
            res.push_back(last->val);

            // 加入子节点 （这里就是按层级遍历了）
            int size = q.size();
            for (int i=0; i<size; i++) {
                // 从头访问 
                TreeNode *top = q.front();
                q.pop();

                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }

        }
        return res;
        
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->left->right = new TreeNode(5);
    node->right->right = new TreeNode(4);
    Solution *sol = new Solution();
    vector<int> res = sol->rightSideView(node);

    printVector(res);

    return 0;
}


