/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (38.94%)
 * Likes:    2139
 * Dislikes: 229
 * Total Accepted:    352.4K
 * Total Submissions: 905K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 * 
 * 
 */
#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> minSt;

    int currentMin;

    MinStack() {
        currentMin = INT_MAX;
    }
    
    void push(int x) {
        st.push(x);
        if (x < currentMin) {
            currentMin = x;
        }
        minSt.push(currentMin);
    }
    
    void pop() {

        bool needUpdateCurrentMin = st.top() == minSt.top();

        st.pop();
        minSt.pop();

        if (minSt.empty()) {
            currentMin = INT_MAX;
        } else {
            if (needUpdateCurrentMin) {
                currentMin = minSt.top();
            }
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

int main(int argc, char const *argv[])
{
    MinStack* st = new MinStack();
    st->push(-10);
    st->push(14);
    int m0 = st->getMin();
    cout << m0 << endl;
    int m2 = st->getMin();
    cout << m2 << endl;
    st->push(-20);
    int m3 = st->getMin();
    cout << m3 << endl;
    int m4 = st->getMin();
    cout << m4 << endl;
    int t0 = st->top();
    cout << t0 << endl;
    int m5 = st->getMin();
    cout << m5 << endl;
    st->pop();
    st->push(10);
    st->push(-7);
    int m6= st->getMin();
    cout << m6 << endl;


    return 0;
}

