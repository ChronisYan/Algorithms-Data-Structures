class Node
{
public:
    int value;
    Node *prev;
    Node *next;

    Node(int value) : value(value), prev(nullptr), next(nullptr){};
};

class DoublyLinkedList
{
public:
    DoublyLinkedList() : head_(nullptr), tail_(nullptr){};

    void setHead(Node *node)
    {
        if (node == head_)
            return;

        remove(node);
        node->next = head_;
        if (head_)
            head_->prev = node;
        head_ = node;
    }

    void setTail(Node *node)
    {
        if (node == tail_)
            return;

        remove(node);
        node->prev = tail_;
        if (tail_)
            tail_->next = node;
        tail_ = node;
    }

    void insertBefore(Node *node, Node *nodeToInsert)
    {
        if (node == head_)
        {
            setHead(nodeToInsert);
            return;
        }

        remove(nodeToInsert);
        if (node->prev)
        {
            node->prev->next = nodeToInsert;
            nodeToInsert->prev = node->prev;
        }
        nodeToInsert->next = node;
        node->prev = nodeToInsert;
    }

    void insertAfter(Node *node, Node *nodeToInsert)
    {
        if (node == tail_)
        {
            setTail(nodeToInsert);
            return;
        }

        remove(nodeToInsert);
        if (node->next)
        {
            node->next->prev = nodeToInsert;
            nodeToInsert->next = node->next;
        }
        nodeToInsert->prev = node;
        node->next = nodeToInsert;
    }

    void insertAtPosition(int position, Node *nodeToInsert)
    {
        int i = 1;
        Node *node = head_;
        while (i < position)
        {
            node = node->next;
            i++;
            if (!node)
                return;
        }
        insertBefore(node, nodeToInsert);
    }

    void removeNodesWithValue(int value)
    {
        Node *cur = head_;
        while (cur)
        {
            if (cur->value == value)
            {
                Node *new_cur = cur->next;
                remove(cur);
                cur = new_cur;
                continue;
            }
            cur = cur->next;
        }
    }

    void remove(Node *node)
    {
        if (node == head_)
            head_ = node->next;

        if (node == tail_)
            tail_ = node->prev;

        if (node->prev)
            node->prev->next = node->next;

        if (node->next)
            node->next->prev = node->prev;

        node->next = nullptr;
        node->prev = nullptr;
    }

    bool containsNodeWithValue(int value)
    {
        Node *cur = head_;
        while (cur)
        {
            if (cur->value == value)
            {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

private:
    Node *head_;
    Node *tail_;
};
