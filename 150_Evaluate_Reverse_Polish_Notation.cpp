#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  template <typename T>
  auto pop_value(T& stack) {
    auto v = std::move(stack.top());
    stack.pop();
    return v;
  }

 public:
  int evalRPN(const vector<string>& tokens) {
    if (tokens.size() < 1 || tokens.size() % 2 != 1) {
      throw std::runtime_error("Invalid RPN expression");
    }
    std::stack<int> operands;
    for (const string& token : tokens) {
      if (token == "+") {
        operands.push(pop_value(operands) + pop_value(operands));
      } else if (token == "-") {
        int RHS = pop_value(operands);
        int LHS = pop_value(operands);
        operands.push(LHS - RHS);
      } else if (token == "*") {
        operands.push(pop_value(operands) * pop_value(operands));
      } else if (token == "/") {
        int RHS = pop_value(operands);
        int LHS = pop_value(operands);
        if (RHS == 0) {
          throw std::runtime_error("Division by zero");
        }
        operands.push(LHS / RHS);
      } else {
        operands.push(std::stoi(token));
      }
    }
    return operands.top();
  }
};

int main() {
  Solution sol;

  cout << sol.evalRPN({"1", "2", "+", "3", "*", "4", "-"}) << endl;

  return 0;
}
