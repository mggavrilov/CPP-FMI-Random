#ifndef RLESTRING_H
#define RLESTRING_H

#define DEFAULT_ARRAY_SIZE 10

#include <iostream>

class RLEString
{
    public:
        RLEString();
        virtual ~RLEString();
        RLEString(const RLEString& other);
        RLEString& operator=(const RLEString& other);
        RLEString(const char*);
        int length() const;
        char& operator[](int i) const;
        RLEString operator+(RLEString const &right) const;
        void splice(int start, int length);
        void insert(const RLEString& rles, int pos);
        friend std::ostream& operator<<(std::ostream& os, const RLEString&);

    protected:

    private:
        struct Node
        {
            int count;
            char letter;

            Node()
            {
                count = -1;
                letter = 0;
            }

            Node(int count, char letter)
            {
                this->count = count;
                this->letter = letter;
            }
        };

        Node *arr;
        int arrSize;
        int maxSize;
        int strlength;
};

#endif // RLESTRING_H
