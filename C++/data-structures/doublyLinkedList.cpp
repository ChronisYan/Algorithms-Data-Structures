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
        if (!head_ && !tail_)
        {
            head_ = node;
            tail_ = node;
            return;
        }
        insertBefore(head_, node);
    }

    void setTail(Node *node)
    {
        if (!head_ && !tail_)
        {
            head_ = node;
            tail_ = node;
            return;
        }
        insertAfter(tail_, node);
    }

    void insertBefore(Node *node, Node *nodeToInsert)
    {
        if (nodeToInsert == head_ && nodeToInsert == tail_)
            return;

        remove(nodeToInsert);
        nodeToInsert->prev = node->prev;
        nodeToInsert->next = node;
        if (!node->prev)
            head_ = nodeToInsert;
        else
            node->prev->next = nodeToInsert;
        node->prev = nodeToInsert;
    }

    void insertAfter(Node *node, Node *nodeToInsert)
    {
        if (nodeToInsert == head_ && nodeToInsert == tail_)
            return;

        remove(nodeToInsert);
        nodeToInsert->prev = node;
        nodeToInsert->next = node->next;
        if (!node->next)
            tail_ = nodeToInsert;
        else
            node->next->prev = nodeToInsert;
        node->next = nodeToInsert;
    }

    void insertAtPosition(int position, Node *nodeToInsert)
    {
        int i = 1;
        Node *cur = head_;
        while (i++ < position && cur)
            cur = cur->next;

        if (!cur)
            setTail(nodeToInsert);
        else
            insertBefore(cur, nodeToInsert);
    }

    void removeNodesWithValue(int value)
    {
        Node *cur = head_;
        while (cur)
        {
            if (cur->value == value)
            {
                Node *next = cur->next;
                remove(cur);
                cur = next;
                continue;
            }
            cur = cur->next;
        }
    }

    void remove(Node *node)
    {
        if (node == head_)
            head_ = head_->next;
        if (node == tail_)
            tail_ = tail_->prev;
        _unchain(node);
    }

    bool containsNodeWithValue(int value)
    {
        Node *cur = head_;
        while (cur)
        {
            if (cur->value == value)
                return true;
            cur = cur->next;
        }
        return false;
    }

private:
    Node *head_;
    Node *tail_;
    void _unchain(Node *node)
    {
        if (node->next)
            node->next->prev = node->prev;
        if (node->prev)
            node->prev->next = node->next;
        node->next = nullptr;
        node->prev = nullptr;
    }
};
