#include <bits/stdc++.h>
using namespace std;

/**
 * 155. Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 */
class MinStack {
 private:
  stack<int> valStack;
  stack<int> minStack;

 public:
  MinStack() {}

  void push(int val) {
    valStack.push(val);
    if (minStack.empty()) {
      minStack.push(val);
    } else {
      minStack.push(min(val, minStack.top()));
    }
  }

  void pop() {
    // assumes stack is not empty, otherwise undefined
    valStack.pop();
    minStack.pop();
  }

  int top() {
    // assumes stack is not empty, otherwise undefined
    return valStack.top();
  }

  int getMin() {
    // assumes stack is not empty, otherwise undefined
    return minStack.top();
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
