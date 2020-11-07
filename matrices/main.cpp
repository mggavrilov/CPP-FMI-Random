#include <iostream>

using namespace std;

int main()
{
    int m=0, n=0, k=0;

    cin >> m >> n >> k;
    if(m < 1 || m > 20 || n < 1 || n > 20 || k < 1 || k > 20)
        return 0;

    int **m1 = new int*[m];
    for(int i = 0; i < m; i++)
    {
        m1[i] = new int[n];
    }
    int **m2 = new int*[n];
    for(int i = 0; i < n; i++)
    {
        m2[i] = new int[k];
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> m1[i][j];

            if(m1[i][j] < -100000 || m1[i][j] > 100000)
                return 0;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cin >> m2[i][j];

            if(m2[i][j] < -100000 || m2[i][j] > 100000)
                return 0;
        }
    }

    int **m3 = new int*[m];
    for(int i = 0; i < m; i++)
    {
        m3[i] = new int[k];
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < k; j++)
        {
            m3[i][j] = 0;

            for(int x = 0; x < n; x++)
            {
                m3[i][j] += m1[i][x] * m2[x][j];
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cout << m3[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}
