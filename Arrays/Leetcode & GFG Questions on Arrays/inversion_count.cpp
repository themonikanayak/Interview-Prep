#include <iostream>
using namespace std;

long long int merge(long long arr[], long long start, long long mid, long long end)
{
    long long a[mid - start + 1];
    long long b[end - mid];
    long long int inv = 0;
    for (long long i = start; i <= mid; i++)
    {
        a[i - start] = arr[i];
    }

    for (long long i = mid + 1; i <= end; i++)
    {
        b[i - mid - 1] = arr[i];
    }
    long long i = 0, j = 0, k = start;

    while (i < (mid - start + 1) && j < (end - mid))
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            inv += ((mid - start + 1) - i);
            k++;
            j++;
        }
    }
    while (i < (mid - start + 1))
    {
        arr[k] = a[i];
        i++;
        k++;
    }

    while (j < (end - mid))
    {
        arr[k] = b[j];
        k++;
        j++;
    }
    return inv;
}

long long int inversionCount(long long arr[], long long start, long long end)
{
    long long int inv = 0;
    if (start < end)
    {
        long long mid = start + (end - start) / 2;
        inv += inversionCount(arr, start, mid);
        inv += inversionCount(arr, mid + 1, end);
        inv += merge(arr, start, mid, end);
    }
    return inv;
}

int main()
{
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << inversionCount(arr, 0, n - 1);
    return 0;
}