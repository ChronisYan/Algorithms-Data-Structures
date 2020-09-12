#include <iostream>
#include <stdexcept>

template <typename T>
class List
{
public:
    const T &operator[](unsigned index)
    {
        Node *cur_node = head_;

        while (index > 0)
        {
            if (cur_node->next == nullptr)
                throw std::out_of_range("Index is out of range");

            cur_node = cur_node->next;
            index--;
        }
        return cur_node->data;
    }
    // adds element at the front of the list
    void insert(const T &data)
    {
        // create new node
        Node *new_node = new Node(data);
        // new node points to head
        new_node->next = head_;
        // new node becomes the new head
        head_ = new_node;
    }

private:
    class Node
    {
    public:
        const T &data;
        Node *next;
        Node(const T &data) : data(data), next(nullptr){};
    };

    Node *head_; // pointer to the first element of the list
};

int main()
{

    std::cout << "Hello" << std::endl;

    return 0;
}