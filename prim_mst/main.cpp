#include <iostream>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
    int weight;
    int parent;

    Node(int weight, int parent)
    {
        this->weight = weight;
        this->parent = parent;
    }

    friend bool operator< (const Node &c1, const Node &c2);
};

bool operator<(const Node& a, const Node& b) {
    return a.weight > b.weight;
}

int main()
{
    int n, m;

    cin >> n >> m;

    int **arr = new int*[n];
    bool *marked = new bool[n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        marked[i] = false;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = -1;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int x, y, r;

        cin >> x >> y >> r;

        if(arr[x - 1][y - 1] == -1 || arr[x - 1][y - 1] > r)
        {
            arr[x - 1][y - 1] = r;
            arr[y - 1][x - 1] = r;
        }
    }

    int weight = 0;
    priority_queue<Node> queue;

    int s;
    cin >> s;

    //Node start = Node(0, 0);
    marked[0] = true;
    //queue.push(start);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] != -1 && !marked[j])
            {
                Node temp = Node(arr[i][j], j);
                queue.push(temp);
            }

            if(queue.size())
            {
                Node temp = queue.top();
                queue.pop();

                weight += temp.weight;
                marked[temp.parent] = true;
            }
        }
    }

    cout << weight;

    return 0;
}
