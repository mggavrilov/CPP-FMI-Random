#include <iostream>

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
    int n;
    cin >> n;
    if(n < 1 || n > 100000)
        return 0;

    int *arr = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(n < 1 || n > 2147483647)
            return 0;
    }

    quickSort(arr, 0, n-1);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
