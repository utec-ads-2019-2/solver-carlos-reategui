#ifndef SOLVER_5_NODE_H
#define SOLVER_5_NODE_H

struct Node{
    std::string data;
    Node *left;
    Node *right;

public:
    explicit Node(std::string data) : data(std::move(data)), left(nullptr), right(nullptr) { }

    friend class Solver;
};

#endif //SOLVER_5_NODE_H
