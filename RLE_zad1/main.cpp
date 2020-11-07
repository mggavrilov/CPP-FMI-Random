#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(0));

    int random = rand();
    cout << random << endl;

    cout << "Hello world!" << endl;
    return 0;
}
