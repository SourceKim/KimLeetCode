/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
 *
 * algorithms
 * Medium (39.74%)
 * Likes:    1233
 * Dislikes: 116
 * Total Accepted:    276.9K
 * Total Submissions: 696.1K
 * Testcase Example:  '{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}'
 *
 * You are given a perfect binary tree where all leaves are on the same level,
 * and every parent has two children. The binary tree has the following
 * definition:
 * 
 * 
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 * 
 * 
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 * 
 * Initially, all next pointers are set to NULL.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * 
 * 
 * Input:
 * {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}
 * 
 * Output:
 * {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":{"$id":"6","left":null,"next":null,"right":null,"val":7},"right":null,"val":6},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"7","left":{"$ref":"5"},"next":null,"right":{"$ref":"6"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"7"},"val":1}
 * 
 * Explanation: Given the above perfect binary tree (Figure A), your function
 * should populate each next pointer to point to its next right node, just like
 * in Figure B.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You may only use constant extra space.
 * Recursive approach is fine, implicit stack space does not count as extra
 * space for this problem.
 * 
 * 
 */
#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        
        // 使用 queue 进行逐层遍历即可

        stack<Node*> st;

        stack<Node*> childSt;

        if (root) {
            st.push(root);
        }

        while (!st.empty())
        {
            // cout << " == " << endl;
            int size = st.size(); // 先把 size 记录下来，不然后面的 push & pop 会影响
            for (int i=0; i<size; i++) {

                Node *top = st.top();
                st.pop();

                // cout << top->val << endl;
                if (i != size-1) { // 不是该层最后一个 
                    top->next = st.top();
                }
            
                if (top->left) {
                    // cout << top->left->val << top->right->val << endl;
                    childSt.push(top->left);
                    childSt.push(top->right);
                }
            }
            int childSize = childSt.size();
            for (int i=0; i<childSize; i++) {
                Node *top = childSt.top();
                // cout << top->val << endl;
                childSt.pop();
                st.push(top);
            }
        }

        return root;
        
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    Node n4 = Node(4, NULL, NULL, NULL);
    Node n5 = Node(5, NULL, NULL, NULL);
    Node n6 = Node(6, NULL, NULL, NULL);
    Node n7 = Node(7, NULL, NULL, NULL);
    Node n2 = Node(2, &n4, &n5, NULL);
    Node n3 = Node(3, &n6, &n7, NULL);
    Node n1 = Node(1, &n2, &n3, NULL);


    Solution *sol = new Solution();
    Node *n = sol->connect(&n1);

    cout << n->left->next->val << endl;
    cout << n->left->left->next->val << endl;
    cout << n->left->right->next->val << endl;
    

    return 0;
}
