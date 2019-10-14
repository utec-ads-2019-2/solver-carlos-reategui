#ifndef SOLVER_5_SOLVER_H
#define SOLVER_5_SOLVER_H

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <cmath>
#include "node.h"

using namespace std;

class Solver{
private:
    stack<char> operatorsStack;
    stack<Node*> tree;
    map<char, int> enteredVariables;
    vector<Node*> postOrderExpression;
    string expression;
    string answer;
private:
    void checkOperatorsStack(unsigned long index);
    static bool isOperator(char c);
    static bool isParenthesis(char c);
    static unsigned short hierarchy(char c);
    void toPostOrder();
    float operate(char);
    void solveExpression();
    void fillRestOfPostOrder();
    void getAnswerFromExpression(const string&);
public:
    explicit Solver(const string&);
    [[nodiscard]] const string &getAnswer() const;
};

#endif //SOLVER_5_SOLVER_H
