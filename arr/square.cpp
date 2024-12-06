#include <iostream>
using namespace std;
int *square(int arr[], int n);
int main()
{
    int arr[] = {-4, -1, 0, 3, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *result = square(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    delete[] result;
    return 0;
}
int *square(int arr[], int n)
{
    int *result = new int[n];
    int i = 0;
    int j = n - 1;
    for (int t = 0; t < n; t++)
    {
        if (arr[i] * arr[i] >= arr[j] * arr[j])
        {
            result[n - t - 1] = arr[i] * arr[i];
            i++;
        }
        else
        {
            result[n - t - 1] = arr[j] * arr[j];
            j--;
        }
    }
    return result;
}

// #include <iostream>
// #include <new>
// using namespace std;

// int *square(int arr[], int n);

// int main()
// {
//     int arr[] = {-4, -1, 0, 3, 10};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int *result = square(arr, n);
//     for (int i = 0; i < n; i++)
//     {
//         cout << result[i] << " ";
//     }
//     delete[] result; // 释放动态内存
//     return 0;
// }

// int *square(int arr[], int n)
// {
//     int *result = new int[n]; // 动态分配数组
//     int i = 0;
//     int j = n - 1;
//     for (int t = n - 1; t >= 0; t--)
//     {
//         if (arr[i] * arr[i] > arr[j] * arr[j])
//         {
//             result[t] = arr[i] * arr[i];
//             i++;
//         }
//         else
//         {
//             result[t] = arr[j] * arr[j];
//             j--;
//         }
//     }
//     return result; // 返回动态数组的指针
// }
