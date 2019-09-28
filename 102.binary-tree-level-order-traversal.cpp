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
    vector<vector<int> > levelOrder(TreeNode* root) {
        
        vector<vector<int> > vec;

        stack<TreeNode *> st_l;
        stack<TreeNode *> st_r;

        queue<TreeNode *> q;
        q.push(root);

        bool newLevelFlag = true;

        while (!q.empty())
        {
            TreeNode *first = q.front();
            q.pop();

            if (newLevelFlag) {
                vector<int> v;
                
            }

            
            
            v.push_back(first->val);
        }
        

        TreeNode *leftNode;
        TreeNode *rightNode;

        if (root != NULL) {

            vector<int> v;
            v.push_back(root->val);
            vec.push_back(v);
            
            if (root->left != NULL) {
                st_l.push(root->left);
                leftNode = root->left;
            }

            if (root->right != NULL) {
                st_r.push(root->right);
                rightNode = root->right;
            }
            
        }


        while (!st_l.empty() || !st_r.empty())
        {

            TreeNode *top_l= st_l.top();
            st_l.pop();

            TreeNode *top_r= st_r.top();
            st_r.pop();

            if (top->left != NULL || top->right != NULL) { // 如果左边有

                vector<int> v;

                if (top->left != NULL) {
                    v.push_back(top->left->val);
                }

                if (top->right != NULL) {
                    v.push_back(top->right->val);
                }

                if (top->right != NULL) {
                    st.push(top->right);
                }

                if (top->left != NULL) {
                    st.push(top->left);
                }

                vec.push_back(v);

            }
        }

        return vec;
        
    }
};

int main(int argc, char const *argv[])
{
    TreeNode r = TreeNode(1);

    TreeNode l0 = TreeNode(2);
    TreeNode r0 = TreeNode(3);
    r.left = &l0;
    r.right = &r0;

    TreeNode r0_0= TreeNode(4);
    TreeNode r0_1 = TreeNode(5);
    l0.left = &r0_0;
    r0.right = &r0_1;

    Solution *sol = new Solution();
    vector<vector<int> > res = sol->levelOrder(&r);


    for (int i=0;i<res.size();i++) {
        vector<int> v = res[i];
        // cout << v.size() << endl;
        for (int j=0;j<v.size();j++) {
            cout << v[j] << endl;
        }
        cout << "=====" << endl;
    }
    
    return 0;
}


