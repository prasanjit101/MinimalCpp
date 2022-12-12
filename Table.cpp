// implement table to store records

class Table
{
public:
    Table(int = 10);                       // default constructor
    Table(const Table &);                  // copy constructor
    ~Table();                              // destructor
    const Table &operator=(const Table &); // assignment operator

    void insertRecord(int, const Record &);   // insert record
    bool deleteRecord(int);                   // delete record
    bool retrieveRecord(int, Record &) const; // retrieve record

    int getNumberOfRecords() const; // get number of records
    void printTable() const;        // print table

private:
    int size;            // size of table
    int numberOfRecords; // number of records in table
    Record *ptr;         // pointer to table
};                       // end class Table

Table::Table(int tableSize)
{
    size = tableSize;
    numberOfRecords = 0;
    ptr = new Record[size];
}

Table::Table(const Table &tableToCopy)
{
    size = tableToCopy.size;
    numberOfRecords = tableToCopy.numberOfRecords;
    ptr = new Record[size];
    for (int i = 0; i < numberOfRecords; i++)
        ptr[i] = tableToCopy.ptr[i];
}

Table::~Table()
{
    delete[] ptr;
}

const Table &Table::operator=(const Table &right)
{
    if (&right != this)
    {
        if (size != right.size)
        {
            delete[] ptr;
            size = right.size;
            ptr = new Record[size];
        } // end inner if

        numberOfRecords = right.numberOfRecords;

        for (int i = 0; i < numberOfRecords; i++)
            ptr[i] = right.ptr[i];
    } // end outer if

    return *this;
}

void Table::insertRecord(int key, const Record &value)
{
    int newRecord = numberOfRecords;
    ptr[newRecord].setKey(key);
    ptr[newRecord].setValue(value.getValue());
    numberOfRecords++;
}

bool Table::deleteRecord(int key)
{
    int i;
    for (i = 0; i < numberOfRecords; i++)
        if (ptr[i].getKey() == key)
            break;

    if (i == numberOfRecords)
        return false;

    for (int j = i; j < numberOfRecords - 1; j++)
        ptr[j] = ptr[j + 1];

    numberOfRecords--;
    return true;
}

bool Table::retrieveRecord(int key, Record &value) const
{
    for (int i = 0; i < numberOfRecords; i++)
        if (ptr[i].getKey() == key)
        {
            value = ptr[i].getValue();
            return true;
        } // end if

    return false;
}

int Table::getNumberOfRecords() const
{
    return numberOfRecords;
}

void Table::printTable() const
{
    for (int i = 0; i < numberOfRecords; i++)
    {
        cout << ptr[i].getKey() << ' ' << ptr[i].getValue() << endl;
    } // end for
}