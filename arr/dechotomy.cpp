#include <iostream>
using namespace std;
int dechotomy1(int arr[], int length, int n);
int dechotomy2(int arr[], int length, int n);
int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = 10;
    int result1 = dechotomy1(arr, sizeof(arr) / sizeof(arr[0]), n);
    int result2 = dechotomy2(arr, sizeof(arr) / sizeof(arr[0]), n);
    cout << "Index of " << n << " in the array is: " << result1 << endl;
    cout << "Index of " << n << " in the array is: " << result2 << endl;
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << arr[result1] << endl;
    cout << arr[result2] << endl;
    return 0;
}
int dechotomy1(int arr[], int length, int n)
{
    int mid;
    int left = 0;
    int right = length - 1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] > n)
            right = mid - 1;
        else if (arr[mid] < n)
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}

int dechotomy2(int arr[], int length, int n)
{
    int left = 0;
    int right = length;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] < n)
            left = mid + 1;
        else if (arr[mid] > n)
            right = mid;
        else
            return mid;
    }
    return -1;
}
