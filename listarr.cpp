#include <bits/stdc++.h>

// create a new data structure which can link array elements
struct node
{
    int *data;
    node *next;

    node(int size)
    {
        data = new int[size];
        next = nullptr;
    }
};

class ArrayList
{
    // initalise the data structure
    node *head;
    node *tail;
    int size;
    int capacity;
    int *next;
    int *prev;
    int first;
    int last;
    int free;

public:
    ArrayList(int size)
    {
        this->size = size;
        this->capacity = size;
        head = new node(size);
        tail = head;
        next = new int[size];
        prev = new int[size];
        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
            prev[i] = i - 1;
        }
        next[size - 1] = -1;
        prev[0] = -1;
        first = 0;
        last = size - 1;
        free = size;
    }

    // add a new element to the array
    void add(int value)
    {
        if (free == 0)
        {
            node *temp = new node(size);
            tail->next = temp;
            tail = temp;
            free = size;
        }
        int index = first;
        first = next[first];
        if (first != -1)
        {
            prev[first] = -1;
        }
        free--;
        tail->data[index] = value;
    }

    // get the element at a particular index
    int get(int index)
    {
        if (index >= capacity)
        {
            return -1;
        }
        int i = 0;
        node *temp = head;
        while (i + size <= index)
        {
            temp = temp->next;
            i += size;
        }
        return temp->data[index - i];
    }

    // set the element at a particular index
    void set(int index, int value)
    {
        if (index >= capacity)
        {
            return;
        }
        int i = 0;
        node *temp = head;
        while (i + size <= index)
        {
            temp = temp->next;
            i += size;
        }
        temp->data[index - i] = value;
    }

    // remove the element at a particular index
    void remove(int index)
    {
        if (index >= capacity)
        {
            return;
        }
        int i = 0;
        node *temp = head;
        while (i + size <= index)
        {
            temp = temp->next;
            i += size;
        }
        temp->data[index - i] = 0;
        next[last] = index;
        prev[index] = last;
        last = index;
        free++;
    }

    // print the array
    void print()
    {
        node *temp = head;
        while (temp != nullptr)
        {
            for (int i = 0; i < size; i++)
            {
                std::cout << temp->data[i] << " ";
            }
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // get size
    int getSize()
    {
        return capacity - free;
    }
};
