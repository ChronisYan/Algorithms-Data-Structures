class Queue: 
    """
    Simple Queue implementation
    """
    def __init__(self):
        """
        Initialize empty queue
        """
        self._items = []

    def __len__(self):
        """
        Return number of items in queue
        """
        return len(self._items)

    def __iter__(self):
        """ 
        Crete iterator
        """
        for item in self._items:
            yield item 

    def __str__(self):
        """
        Return string version of queue
        """
        return str(self._items)

    def enqueue(self, item):
    """ 
    Add item to queue
    """
         self._items.append(item)
    
    def dequeue(self):
        """
        Remove and return the head of the queue
        """
        return self._items.pop(0)

    def peek(self):
        """
        Return the head of the queue
        """
        return self._items[0]

   def clear(self):
       """
       Remove all items for queue
       """
       self._items = []
