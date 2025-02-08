#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class EmptyStackError final : public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Empty stack, can't pop a element";
    }
};

class CustomStack {
    vector<int> stack;

public:
    [[nodiscard]] bool isEmpty() const {
        return stack.empty();
    }

    [[nodiscard]] int getTop() const {
        return stack.back();
    }

    int pop() {
        if (isEmpty()) {
            throw EmptyStackError();
        }

        const int lastItem = stack.back();
        stack.pop_back();
        return lastItem;
    }

    void push(int v) {
        stack.push_back(v);
    }

    void display() {
        for (const int &s: stack) {
            cout << s << " ";
        }
        cout << endl;
    }
};

int main() {
    CustomStack stack;
    // stack.pop();
    stack.push(3);
    stack.push(2);
    stack.push(1);
    stack.push(98);
    stack.pop();
    stack.display();
    return 0;
}
