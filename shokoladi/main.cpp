#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Date {
    public:
    string day, month, year;

    Date() {}

    Date(string date)
    {
        day = date.substr(0, 2);
        month = date.substr(3, 2);
        year = date.substr(6, 4);
    }

    bool operator<(const Date& d)
    {
        if(d.year.compare(year) < 0)
        {
            return false;
        }
        else if(d.year.compare(year) == 0)
        {
            if(d.month.compare(month) < 0)
            {
                return false;
            }
            else if(d.month.compare(month) == 0)
            {
                if(d.day.compare(day) < 0 || d.day.compare(day) == 0)
                {
                    return false;
                }
                else
                    return true;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return true;
        }
    }
};

bool isDigit(char digit)
{
    if((int)digit >= 48 && (int)digit <= 57)
        return true;
    else
        return false;
}

bool isValid(string str)
{
    if(isDigit(str[0]) && isDigit(str[1]) && str[2] == '.' && isDigit(str[3]) && isDigit(str[4]) && str[5] == '.' && isDigit(str[6]) && isDigit(str[7]) && isDigit(str[8]) && isDigit(str[9]))
        return true;
    else
        return false;
}

int main()
{
    int n;

    cin >> n;

    if(n < 1 || n > 100)
        return 0;

    vector<string> dates;
    vector<int> indexes;

    for(int i = 0; i < n; i++)
    {
        indexes.push_back(i);
        string input;
        cin >> input;
        if(input.length() != 10 || !isValid(input))
            return 0;

        dates.push_back(input);

    }

    int j, tempindex;
    Date temp;

    vector<Date> dates2;

    for(int i = 0; i < n; i++)
    {
        Date date = Date(dates[i]);
        dates2.push_back(date);
    }

    for(int i = 0; i < n; i++)
    {
        j = i;

        while(j > 0 && dates2[j] < dates2[j-1])
        {
            temp = dates2[j];
            dates2[j] = dates2[j-1];
            dates2[j-1] = temp;

            tempindex = indexes[j];
            indexes[j] = indexes[j-1];
            indexes[j-1] = tempindex;

            j--;
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << indexes[i] + 1 << endl;
    }

    return 0;
}
