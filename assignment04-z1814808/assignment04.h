#ifndef ASSIGNMENT04_H
#define ASSIGNMENT04_H
#include <queue>

class Stack {
    private:
        std::queue<int> q1, q2;
    public:
        bool empty() const;
        int size() const;
        int top();
        void push(const int& val);
        void pop();
};

#endif
