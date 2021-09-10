#include <iostream>
using namespace std;

int maximumSubarraySum(int arr[], int n)
{
    int curr_sum = 0;
    int max_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
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
    cout << maximumSubarraySum(arr, n);
    return 0;
}