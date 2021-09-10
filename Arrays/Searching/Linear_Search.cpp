#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for (int idx = 0; idx < n; idx++)
    {
        if (arr[idx] == key)
        {
            //Key is present at index 'idx'
            return idx;
        }
    }
    //If the Key is not present
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    cout << linearSearch(arr, n, key);
    return 0;
}