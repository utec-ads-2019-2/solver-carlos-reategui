#include "solver.h"
const size_t numberOfTests = 5;

string tests[numberOfTests] = {
        "7/4*((3+1)*3)+3",
        "2+(3)",
        "7/4*((1+2)^4*2)+3",
        "1-2*5/2+1-2^4+1",
        "((7*3)/4+6*(3^2)/2)"
};

int main() {
    string expression;
    cout << "TESTS: " << endl;
    for (const auto & i : tests) {
        Solver solver(i);
        cout << solver.getAnswer() << endl;
    }
    putchar('\n');
    cout << "Enter mathematical expressions. Type 0 to quit" << endl;
    while(cin >> expression and expression != "0") {
        Solver solver(expression);
        cout << solver.getAnswer() << endl;
    }
    return EXIT_SUCCESS;
}