/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (50.16%)
 * Likes:    1794
 * Dislikes: 46
 * Total Accepted:    436.7K
 * Total Submissions: 869.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
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
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */
#include <vector>
#include <stdio.h>
#include <iostream>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode *> q;
    
        vector<vector<int>> v;

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

            v.push_back(vec);
            
        }

        return v;
        
    }
};
// @lc code=end
// int main(int argc, char const *argv[])
// {
//     TreeNode r = TreeNode(1);

//     TreeNode l0 = TreeNode(2);
//     TreeNode r0 = TreeNode(3);
//     r.left = &l0;
//     r.right = &r0;

//     TreeNode r0_0= TreeNode(4);
//     TreeNode r0_1 = TreeNode(5);
//     l0.left = &r0_0;
//     r0.right = &r0_1;

//     Solution *sol = new Solution();
//     vector<vector<int> > res = sol->levelOrder(&r);


//     for (int i=0;i<res.size();i++) {
//         vector<int> v = res[i];
//         // cout << v.size() << endl;
//         for (int j=0;j<v.size();j++) {
//             cout << v[j] << endl;
//         }
//         cout << "=====" << endl;
//     }
    
//     return 0;
// }


