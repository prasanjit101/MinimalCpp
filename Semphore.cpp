// implement semaphore

class Semaphore
{
public:
    Semaphore(int = 1); // default constructor
    ~Semaphore();       // destructor
    void wait();        // wait
    void signal();      // signal

private:
    int count; // semaphore count
};             // end class Semaphore

Semaphore::Semaphore(int initialCount)
{
    count = initialCount;
}

Semaphore::~Semaphore()
{
}

void Semaphore::wait()
{
    while (count <= 0)
        ; // do nothing
    count--;
}

void Semaphore::signal()
{
    count++;
}