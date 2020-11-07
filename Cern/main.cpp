#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n < 1 || n > 10000)
        return 0;

    vector<string> numbers;
    ostringstream os;

    for(int i = 0; i < n; i++)
    {
        int number;
        cin >> number;

        if(number > 10000000)
            return 0;

        os << number;

        numbers.push_back(os.str());

        os.clear();
        os.str("");
    }

    int j;
    string temp;

    for(int i = 0; i < n; i++)
    {
        j = i;

        while(j > 0 && (numbers[j].compare(numbers[j-1]) < 0))
        {
            temp = numbers[j];
            numbers[j] = numbers[j-1];
            numbers[j-1] = temp;
            j--;
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << numbers[i] << endl;
    }



    return 0;
}
