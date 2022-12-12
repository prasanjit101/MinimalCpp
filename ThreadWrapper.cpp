#include <iostream>
#include <thread>

class ThreadWrapper
{
    // initialize n number of threads with function
    std::thread *threads;
    int threadCount;
    int count = 0;
    void (*function)(int);

public:
    ThreadWrapper(int threadCount)
    {
        this->threadCount = threadCount;
        this->function = NULL;
        threads = new std::thread[threadCount];
    }

    ThreadWrapper(int threadCount, void (*function)(int))
    {
        this->threadCount = threadCount;
        this->function = function;
        threads = new std::thread[threadCount];
    }

    void start()
    {
        this->count = this->threadCount;
        for (int i = 0; i < threadCount; i++)
        {
            threads[i] = std::thread(function, i);
        }
    }

    void start(void (*function)(int))
    {
        threads[i] = std::thread(function, i);
        this->count = i;
        int i = this->count + 1;
    }

    void join()
    {
        for (int i = 0; i < threadCount; i++)
        {
            threads[i].join();
        }
    }

    void stop()
    {
        for (int i = 0; i < threadCount; i++)
        {
            threads[i].detach();
        }
    }

    void destroy()
    {
        delete[] threads;
    }

    int getThreadCount()
    {
        return threadCount;
    }

    int getThreadId(int index)
    {
        return threads[index].get_id();
    }

    int getThreadStatus(int index)
    {
        return threads[index].joinable();
    }

    int getThreadPriority(int index)
    {
        return threads[index].get_priority();
    }

    void setThreadPriority(int index, int priority)
    {
        threads[index].set_priority(priority);
    }
};

// driver code
void hello(int i)
{
    std::cout << "Hello " << i << std::endl;
}

int main()
{
    ThreadWrapper tw(1);
    tw.start(hello);
    tw.join();
    tw.destroy();

    return 0;
}