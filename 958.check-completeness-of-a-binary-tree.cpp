/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
 *
 * https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (52.67%)
 * Likes:    1488
 * Dislikes: 19
 * Total Accepted:    90.1K
 * Total Submissions: 171.1K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given the root of a binary tree, determine if it is a complete binary tree.
 * 
 * In a complete binary tree, every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2^h nodes inclusive at the last level
 * h.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,4,5,6]
 * Output: true
 * Explanation: Every level before the last is full (ie. levels with
 * node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are
 * as far left as possible.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,3,4,5,null,7]
 * Output: false
 * Explanation: The node with value 7 isn't as far left as possible.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 100].
 * 1 <= Node.val <= 1000
 * 
 * 
 */

#include "helper/helper.hpp"

/*
    除却最后一层以外，每一层都是满的，

    最后一层可以不是满的，但是节点得尽量靠左边

    思路：
    核心一句：满足上述要求的节点是 **有一个 NULL 节点后面的节点或者孩子必须全是 NULL**
    使用按层遍历，从左往右，并且贯彻上述的原则即可
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
    bool isCompleteTree(TreeNode* root) {

        queue<TreeNode *> q;

        q.push(root);

        bool foundNull = false; // 找到一个为 NULL 的节点

        while (!q.empty())
        {
            TreeNode *top = q.front();
            q.pop();

            if (!top) { // 找到一个是 null 的节点

                foundNull = true;

            } else { // 找到一个非 null 的节点

                // NULL 后面的节点必须全部是 NULL
                if (foundNull) return false; 

                // 无论是不是 NULL，都加入到队列之中
                q.push(top->left);
                q.push(top->right);
            }
        }
        
        return true;
    }
};
// @lc code=end

