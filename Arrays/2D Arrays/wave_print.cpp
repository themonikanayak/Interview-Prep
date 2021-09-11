#include <iostream>
using namespace std;
const int row = 10000;
const int col = 10000;
void wavePrint(int arr[][col], int n, int m)
{
    for (int j = 0; j < m; j++)
    {
        //Top-Down Print
        if (j % 2 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                cout << arr[i][j] << " ";
            }
        }
        //Bottom-Up Direction
        else
        {
            for (int i = n - 1; i >= 0; i--)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[row][col];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    wavePrint(arr, n, m);
    return 0;
}