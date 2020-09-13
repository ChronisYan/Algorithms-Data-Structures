#include <iostream>
#include <stdexcept>

template <typename T>
class List
{
public:
    List() : head_(nullptr){};
    const T &operator[](unsigned index)
    {
        Node *cur_node = head_;

        while (index > 0)
        {
            if (cur_node == nullptr || cur_node->next == nullptr)
                throw std::out_of_range("index is out of range");

            cur_node = cur_node->next;
            index--;
        }
        return cur_node->data;
    }
    // std::cout displaying function
    friend std::ostream &operator<<(std::ostream &os, List &list)
    {
        Node *cur_node = list.head_;

        while (cur_node != nullptr)
        {
            std::cout << cur_node->data << " -> ";
            cur_node = cur_node->next;
        }
        return os;
    }

    // adds element at the front of the list
    void insert(T data)
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
        T data;
        Node *next;
        Node(T data) : data(data), next(nullptr){};
    };
    // list.insert(4);
    // list.insert(1);
    // list.insert(5);
    Node *head_; // pointer to the first element of the list
};

int main()
{
    List<int> list;

    list.insert(4);
    list.insert(1);
    list.insert(5);

    std::cout << list << std::endl;

    return 0;
}
