#include <iostream>
#include <stack>
#include <string>

// C++ STL
// stack<int> S; //empty stack

// int x = S.top(); // get top element
// S.pop(); // pop top element
// S.push(x); //push x on top

// bool x = S.empty(); // to check if stack is empty
// int sz = S.size(); // get size of stack

int main()
{
    std::stack<std::string> S;

    S.push("Alpha");
    S.push("Beta");
    S.push("Gamma");

    std::cout << S.top() << std::endl;
    S.pop();
    std::cout << S.top() << std::endl;

    std::cout << "The Stack is empty: " << S.empty() << std::endl;
    std::cout << "Leght of the Stack: " << S.size() << std::endl;

    return 0;
}