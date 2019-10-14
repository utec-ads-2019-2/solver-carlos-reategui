#include "solver.h"

float Solver::operate(char o){
    float right = stof(tree.top()->data); tree.pop();
    float left = stof(tree.top()->data); tree.pop();
    if (o == '^') return pow(left, right);
    if (o == '*') return left * right;
    if (o == '/') return left / right;
    if (o == '+') return left + right;
    if (o == '-') return left - right;
    return 0;
}

bool Solver::isOperator(char c){
    return c == '+' or c == '-' or c == '*' or c == '/' or c == '^' or c == '(' or c == ')';
}

bool Solver::isParenthesis(char c){
    return c == '(' or c == ')';
}

short unsigned int Solver::hierarchy(char c){
    if (c == '+' or c == '-') return 1;
    if (c == '*' or c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

void Solver::fillRestOfPostOrder() {
    while (!operatorsStack.empty()) {
        if (!isParenthesis(operatorsStack.top()))
            postOrderExpression.push_back(new Node(string(1, operatorsStack.top())));
        operatorsStack.pop();
    }
}

void Solver::toPostOrder() {
    string data;
    for (unsigned long i = 0; i < expression.size(); ++i) {
        if (expression[i] == ' ') continue;
        if (isalpha(expression[i])) {
            postOrderExpression.push_back(new Node(string(1, expression[i])));
            continue;
        }
        if(isdigit(expression[i])){
            data += expression[i];
            if (!isdigit(expression[i+1])){
                postOrderExpression.push_back(new Node(data));
                data = "";
            }
            continue;
        }
        else if (isOperator(expression[i])){
            checkOperatorsStack(i);
        }
    }
    fillRestOfPostOrder();
}

void Solver::checkOperatorsStack(unsigned long index) {
    if (!operatorsStack.empty()) {

        if (expression[index] == '(')
            operatorsStack.push(expression[index]);

        else if (expression[index] == ')'){
            while (operatorsStack.top() != '('){
                if(!isParenthesis(operatorsStack.top())) postOrderExpression.push_back(new Node(string(1, operatorsStack.top())));
                operatorsStack.pop();
            }
            operatorsStack.pop();
        }

        else {
            if (!operatorsStack.empty()){
                while (hierarchy(expression[index]) <= hierarchy(operatorsStack.top())) {
                    postOrderExpression.push_back(new Node(string(1, operatorsStack.top())));
                    operatorsStack.pop();
                    if (operatorsStack.empty()) break;
                }
            }
            operatorsStack.push(expression[index]);
        }
    }

    else
        operatorsStack.push(expression[index]);
}

void Solver::solveExpression() {
    for (auto & node : postOrderExpression) {
        if (isOperator(node->data[0]))
            tree.push(new Node(to_string(operate(node->data[0]))));
        else {
            if (isdigit(node->data[0])) tree.push(node);
            else {
                if (enteredVariables[node->data[0]]) tree.push(new Node(to_string(enteredVariables[node->data[0]])));
                else {
                    cout << "Enter the variable " << node->data[0] << ": ";
                    cin >> enteredVariables[node->data[0]];
                    tree.push(new Node(to_string(enteredVariables[node->data[0]])));
                }
            }
        }
    }
    answer = tree.top()->data;
}

void Solver::getAnswerFromExpression(const string &e) {
    expression = e;
    toPostOrder();
    solveExpression();
}

Solver::Solver(const string &e) {
    getAnswerFromExpression(e);
}

const string &Solver::getAnswer() const {
    return answer;
}

