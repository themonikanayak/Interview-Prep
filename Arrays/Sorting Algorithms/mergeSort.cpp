#include <iostream>
using namespace std;

//Function to merge two sorted arrays
void merge(int *Arr, int start, int mid, int end)
{
    // Create a temp array
    int temp[end - start + 1];

    // Crawlers for both intervals and for temp
    int i = start, j = mid + 1, k = 0;

    // Traverse both arrays and in each iteration add smaller of both elements in temp
    while (i <= mid && j <= end)
    {
        if (Arr[i] <= Arr[j])
        {
            temp[k] = Arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = Arr[j];
            k++;
            j++;
        }
    }

    // Add elements left in the first interval
    while (i <= mid)
    {
        temp[k] = Arr[i];
        k++;
        i++;
    }

    // Add elements left in the second interval
    while (j <= end)
    {
        temp[k] = Arr[j];
        k++;
        j++;
    }

    // Copy elements from temp array to original array
    for (i = start; i <= end; i += 1)
    {
        Arr[i] = temp[i - start];
    }
}

void mergeSort(int arr[], int start, int end)
{

    //Base Case
    if (start >= end)
    {
        return;
    }

    //Recursive Steps
    //Step 1. Find the middle point of the array
    int mid = start + (end - start) / 2;

    //Step 2. Recursively call merge sort on the first half
    mergeSort(arr, start, mid);

    //Step 3. Recursively call merge sort on the other half
    mergeSort(arr, mid + 1, end);

    //Step 4. Merge the two subarrays
    merge(arr, start, mid, end);

    return;
}

int main()
{
    int n;
    cin >> n;
    int arr[1000];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}