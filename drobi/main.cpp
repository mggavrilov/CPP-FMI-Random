#include <iostream>
#include <vector>

using namespace std;

class fraction
{
    public:
    int numerator;
    int denominator;

    void print()
    {
        if(numerator == 0)
            cout << "0 ";
        else
            cout << numerator << "/" << denominator << " ";
    }
};

int gcdF(int numerator, int denominator)
{
    if(denominator == 0)
        return numerator;
    else
        return gcdF(denominator, numerator % denominator);
}

int main()
{
    vector<fraction> fractions;
    int n;

    cin >> n;

    if(n < 1 || n > 100)
        return 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            int gcd = gcdF(j, i);

            fraction f;

            f.numerator = j/gcd;
            f.denominator = i/gcd;

            bool exists = false;

            for(unsigned int k = 0; k < fractions.size(); k++)
            {
                if(fractions[k].numerator == f.numerator && fractions[k].denominator == f.denominator)
                {
                    exists = true;
                }
            }

            if(!exists)
                fractions.push_back(f);
        }
    }
    //sort
    int tempN, tempD;

    for(unsigned int i = 0; i < fractions.size() - 1; i++)
    {
        for(unsigned int j = i+1; j < fractions.size(); j++)
        {
            double f1 = fractions[j].numerator/(double)fractions[j].denominator;
            double f2 = fractions[i].numerator/(double)fractions[i].denominator;
            if(f1 < f2)
            {
                tempN = fractions[j].numerator;
                tempD = fractions[j].denominator;
                fractions[j].numerator = fractions[i].numerator;
                fractions[j].denominator = fractions[i].denominator;
                fractions[i].numerator = tempN;
                fractions[i].denominator = tempD;
            }
        }
    }

    for(unsigned int i = 0; i < fractions.size(); i++)
    {
        //cout << fractions[i].numerator << "/" << fractions[i].denominator << " ";
        fractions[i].print();
    }

    return 0;
}
