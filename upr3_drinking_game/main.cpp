#include <iostream>
#include <sstream>

using namespace std;

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

int main()
{
    int *arr = new int[1048576];

    char cmd;
    int n;
    int counter = 0;
    stringstream ss;

    while(cmd != 'Q')
    {
        cin >> cmd;

        switch(cmd)
        {
            case 'A':
                cin >> n;

                if(n < 1 || n > 100000000)
                    return 0;

                arr[counter] = n;
                quickSort(arr, 0, counter);
                counter++;
                break;
            case 'L':
                if(counter == 0)
                    ss << "Not available" << endl;
                else
                    ss << arr[counter-1] << endl;
                break;
            case 'R':
                if(counter == 0)
                    ss << "Not available" << endl;
                else
                {
                    ss << arr[counter-1] << endl;
                    counter--;
                }
                break;
            default:
                cout << ss.str();
                return 0;
        }
    }

    return 0;
}
