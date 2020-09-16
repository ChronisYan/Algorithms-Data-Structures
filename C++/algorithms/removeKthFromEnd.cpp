// A function that takes the head of a linked list and an integer k and removes the kth element
// from the end of the list

class LinkedList
{
public:
    int value;
    LinkedList *next;

    LinkedList(int value) : value(value), next(nullptr){};
    //...
};

void removeKthNodeFromEnd(LinkedList *head, int k)
{

    LinkedList *cur = head;
    int targetIndex = -k;
    while (cur)
    {
        targetIndex++;
        cur = cur->next;
    }
    LinkedList *target = head;
    if (!targetIndex)
    {
        head->value = head->next->value;
    }
    else
    {
        for (int i = 1; i < targetIndex; i++)
        {
            target = target->next;
        }
    }
    if (target->next->next)
        target->next = target->next->next;
    else
        target->next = nullptr;
}