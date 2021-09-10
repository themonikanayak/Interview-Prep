#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {

        mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
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

    //If the given array is sorted, then we apply Binary Sort
    //Time Complexity of Binary Search is O(Log N)
    cout << BinarySearch(arr, n, key);
    return 0;
}