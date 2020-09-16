// reverse a singly linked list in place (don't create new list)

class LinkedList
{
public:
    int value;
    LinkedList *next;

    LinkedList(int value) : value(value), next(nullptr){};
};

LinkedList *reverseLinkedList(LinkedList *head)
{
    LinkedList *currentNode = head;
    LinkedList *previusNode = nullptr;
    while (currentNode)
    {
        LinkedList *nextNode = currentNode->next;
        currentNode->next = previusNode;
        previusNode = currentNode;
        currentNode = nextNode;
    }
    return previusNode;
}
// my first implementation (unnecessarily complicated)
LinkedList *reverseLinkedList_doubleptr(LinkedList *head)
{
    LinkedList *cur = head;
    LinkedList *new_next_value = nullptr;
    LinkedList **new_next = &new_next_value;

    while (cur)
    {
        LinkedList *temp = cur->next;
        cur->next = *new_next;
        new_next_value = cur;
        if (!temp)
            break;
        cur = temp;
    }
    return cur;
}