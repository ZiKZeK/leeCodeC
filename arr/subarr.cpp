#include <iostream>
using namespace std;
int subarr(int arr[], int n, int k, int sum);
int main()
{
    int arr[] = {2, 3, 1, 2, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int k = 9;
    int sub = subarr(arr, n, k, sum);
    cout << "The number of subarrays with sum " << k << " is " << sub;
    return 0;
}
int subarr(int arr[], int n, int k, int sum)
{
    int temp = sum;
    if (temp < k)
        return 0;
    else
    {
        int i = 0;
        int j = n - 1;
        while (temp >= k)
        {
            if (arr[i] <= arr[j])
            {
                temp = temp - arr[i];
                i++;
            }
            else
            {
                temp = temp - arr[j];
                j--;
            }
        }
        return j - i + 2;
    }
}
