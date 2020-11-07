#include "RLEString.h"
#include <stdexcept>

RLEString::RLEString()
{
    arr = new Node[DEFAULT_ARRAY_SIZE];
    arrSize = 0;
    strlength = 0;
    maxSize = DEFAULT_ARRAY_SIZE;
}

RLEString::~RLEString()
{
    delete[] arr;
}

RLEString::RLEString(const RLEString& other)
{
    arrSize = other.arrSize;
    strlength = other.strlength;
    maxSize = other.maxSize;
    arr = new Node[maxSize];
    for(int i = 0; i < arrSize; ++i)
    {
        arr[i] = other.arr[i];
    }
}

RLEString& RLEString::operator=(const RLEString& other)
{
    if (this == &other)
        return *this;

    delete[] arr;

    arrSize = other.arrSize;
    strlength = other.strlength;
    maxSize = other.maxSize;
    arr = new Node[maxSize];
    for(int i = 0; i < arrSize; ++i)
    {
        arr[i] = other.arr[i];
    }

    return *this;
}

RLEString::RLEString(const char* a)
{
    char lastChar = *a;
    int counter = 0;
    ++a;
    ++strlength;

    while(*a != '\0')
    {
        if(*a == lastChar)
        {
            ++counter;
        }
        else
        {
            if(arrSize == maxSize)
            {
                Node *temp = arr;

                delete[] arr;
                arr = new Node[maxSize * 2];

                for(int i = 0; i < arrSize; ++i)
                {
                    arr[i] = temp[i];
                }

                delete[] temp;

                maxSize *= 2;
            }

            arr[arrSize++] = Node(counter, lastChar);
            lastChar = *a;
            counter = 0;
        }

        ++strlength;
        ++a;
    }
}

int RLEString::length() const
{
    return strlength;
}

char& RLEString::operator[](int i) const
{
    if(i >= 0 && i < strlength)
    {
        int cnt = 0;

        for(int i = 0; i < arrSize; ++i)
        {
            if(arr[i].count + cnt <= i)
                return arr[i].letter;
            else
                cnt += arr[i].count;
        }
    }
    else
    {
        throw std::invalid_argument("Index out of bounds.");
    }
}

/*RLEString RLEString::operator+(RLEString const &right) const
{
    RLEString returnObject;

    if(arrSize + right.arrSize > maxSize)
    {
        Node *temp = arr;

        delete[] arr;

        arr = new Node[maxSize * 2 + right.arrSize];
        for(int i = 0; i < arrSize; ++i)
        {
            arr[i] = temp[i];
        }

        delete[] temp;

        maxSize *= 2;
        maxSize += right.arrSize;
    }

    for(int i = arrSize; i < right.arrSize; ++i)
    {
        arr[i] = right.arr[i];
    }

    arrSize += right.arrSize;
    strlength ++ right.strlength;

    return this;
}*/

void RLEString::splice(int start, int length)
{

}

void RLEString::insert(const RLEString& rles, int pos)
{

}

std::ostream& operator<<(std::ostream& os, const RLEString& r)
{
    char returnString[r.strlength];
    int cnt = 0;

    for(int i = 0; i < r.arrSize; ++i)
    {
        for(int j = 0; j < r.arr[i].count; ++j)
        {
            returnString[cnt++] = r.arr[i].letter;
        }
    }

    os << returnString;

    return os;
}
