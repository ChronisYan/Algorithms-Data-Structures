// given 2 sorted singly linked lists write a function that returns sorted merged ll
// sorting in place, return the head of the ll with the smallest value

class LinkedList
{
public:
    int value;
    LinkedList *next;

    LinkedList(int value) : value(value), next(nullptr) {}
};

LinkedList *mergeLinkedLists(LinkedList *headOne, LinkedList *headTwo)
{
    LinkedList *mergedList = nullptr;
    LinkedList *ptr1 = nullptr;
    LinkedList *ptr1_prev = nullptr;
    LinkedList *ptr2 = nullptr;
    if (headOne->value <= headTwo->value)
    {
        mergedList = headOne;
        ptr1 = headOne->next;
        ptr1_prev = headOne;
        ptr2 = headTwo;
    }
    else
    {
        mergedList = headTwo;
        ptr1 = headTwo->next;
        ptr1_prev = headTwo;
        ptr2 = headOne;
    }

    while (ptr1 && ptr2)
    {
        if (ptr1->value <= ptr2->value)
        {
            ptr1 = ptr1->next;
            ptr1_prev = ptr1_prev->next;
        }
        else
        {
            LinkedList *next2 = ptr2->next;
            ptr1_prev->next = ptr2;
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = next2;
        }
    }

    if (!ptr1)
        ptr1_prev->next = ptr2;

    return mergedList;
}
