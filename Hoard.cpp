#include <bits/stdc++.h>

// create a hoard to manage the memory
class Hoard
{
public:
    Hoard(int size);
    ~Hoard();
    void *allocate(int size);
    void deallocate(void *p);

private:
    int size;
    char *memory;
    int *next;
    int *prev;
    int first;
    int last;
    int free;
};

Hoard::Hoard(int size)
{
    this->size = size;
    memory = new char[size];
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

Hoard::~Hoard()
{
    delete[] memory;
    delete[] next;
    delete[] prev;
}

void *Hoard::allocate(int size)
{
    if (free == 0)
    {
        return nullptr;
    }
    int index = first;
    first = next[first];
    if (first != -1)
    {
        prev[first] = -1;
    }
    free--;
    return memory + index;
}

void Hoard::deallocate(void *p)
{
    int index = (char *)p - memory;
    if (last != -1)
    {
        next[last] = index;
        prev[index] = last;
    }
    last = index;
    if (first == -1)
    {
        first = index;
    }
    free++;
}

/* // Application
int main()
{
    Hoard hoard(10);
    int *p = (int *)hoard.allocate(sizeof(int));
    *p = 10;
    std::cout << *p << std::endl;
    hoard.deallocate(p);
    p = (int *)hoard.allocate(sizeof(int));
    *p = 20;
    std::cout << *p << std::endl;
    return 0;
} */