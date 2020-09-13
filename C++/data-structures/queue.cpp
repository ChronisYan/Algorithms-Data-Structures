#include <iostream>
#include <queue>
#include <string>

// C++ STL
// queue<int> Q; //empty queue
// int x = Q.front(); // get front element
// int x = Q.back(); //get back element
// Q.pop(); // pop front element
// Q.push(x); //push x at back
// bool x = Q.empty(); // to check if stack is empty
// int sz = Q.size(); // get size of stack

int main()
{
    std::queue<std::string> Q;

    Q.push("Alpha");
    Q.push("Beta");
    Q.push("Gamma");
    Q.push("Delta");
    Q.push("Epsilon");
    Q.push("Zeta");

    std::cout << Q.front() << std::endl;
    Q.pop();
    std::cout << Q.front() << std::endl;

    std::cout << "The Queue is empty: " << Q.empty() << std::endl;
    std::cout << "Leght of the Queue: " << Q.size() << std::endl;

    return 0;
}