#include <iostream>
#include <string>

using namespace std;

class DynamicArray
{
    char *data;
    int maxSize;
    int arrSize;
    // 0: +, -
    // 1: *, /
    int lastPrecedence;

    public:
        DynamicArray(int n)
        {
            data = new char[n];
            arrSize = 0;
            maxSize = n;
            lastPrecedence = 0;
        }
        char getElement(int n)
        {
            return data[n];
        }
        int getSize()
        {
            return arrSize;
        }
        int getMaxSize()
        {
            return maxSize;
        }
        void resizeArray(int n)
        {
            char *temp = data;
            data = new char[n];
            for (int i = 0; i < arrSize; i++)
            {
                data[i] = temp[i];
            }
            maxSize = n;
        }
        void push(char n)
        {
            if (arrSize == maxSize)
            {
                resizeArray(maxSize * 2);
            }
            switch (n)
            {
                case '+':
                lastPrecedence = 0;
                break;
                case '-':
                lastPrecedence = 0;
                break;
                case '*':
                lastPrecedence = 1;
                break;
                case '/':
                lastPrecedence = 1;
                break;
            }
            data[arrSize] = n;
            arrSize++;
        }
        char pop()
        {
            return data[--arrSize];
        }
        int getLastPrecedence()
        {
            return lastPrecedence;
        }
    };

int main()
{
    /*DynamicArray arr = DynamicArray(5);
    cout << "Array size: " << arr.getSize() << endl;
    arr.push(1);
    arr.push(2);
    arr.push(3);
    cout << "Array size after push: " << arr.getSize() << endl;
    cout << "Element at index 0: " << arr.getElement(0) << endl;
    arr.pop();
    cout << "Array size after pop: " << arr.getSize() << endl;
    cout << "Array max size before resize: " << arr.getMaxSize() << endl;
    cout << "Array elements:" << endl;
    for (int i = 0; i < arr.getSize(); i++)
    {
    cout << arr.getElement(i) << " ";
    }
    arr.resizeArray(6);
    cout << "Array max size after resize: " << arr.getMaxSize() << endl;
    arr.push(5);
    arr.push(6);
    arr.push(7);
    arr.push(8);
    arr.push(9);
    cout << "Array max size after exceeding max array size: " << arr.getMaxSize() << endl;
    cout << "Array elements:" << endl;
    for (int i = 0; i < arr.getSize(); i++)
    {
    cout << arr.getElement(i) << " ";
    }*/
    //Operator stack
    DynamicArray stack = DynamicArray(20);
    string infix;
    cout << "Infix expression: ";
    cin >> infix;
    string output;
    for (int i = 0; i < infix.length(); i++)
    {
        switch (infix[i])
        {
            case '+':
            if (stack.getLastPrecedence() > 0)
            output += stack.pop();
            else
            stack.push('+');
            break;
            case '-':
            if (stack.getLastPrecedence() > 0)
            output += stack.pop();
            else
            stack.push('-');
            break;
            case '/':
            stack.push('/');
            break;
            case '*':
            stack.push('*');
            break;
            default:
            output += infix[i];
            break;
        }
        if (i == infix.length() - 1)
        {
            for (int j = 0; j <= stack.getSize(); j++)
            {
                output += stack.pop();
            }
        }
    }
    cout << "Postfix expression: " << output;
    return 0;
}
