#include <iostream>
using namespace std;

int delete_element(int nums[], int length, int val);
int main()
{
    int nums_1[] = {3, 2, 2, 3};
    int val_1 = 3;
    int nums_2[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int val_2 = 2;
    int length_1, length_2;
    length_1 = sizeof(nums_1) / sizeof(nums_1[0]);
    length_2 = sizeof(nums_2) / sizeof(nums_2[0]);
    cout << "Before deleting element " << val_1 << " in array 1: ";
    for (int i = 0; i < length_1; i++)
    {
        cout << nums_1[i] << " ";
    }
    cout << endl;
    int count_1 = delete_element(nums_1, length_1, val_1);
    cout << "After deleting element " << val_1 << " in array 1: ";
    for (int i = 0; i < length_1 - 1; i++)
    {
        cout << nums_1[i] << " ";
    }
    cout << endl;
    cout << "Before deleting element " << val_2 << " in array 2: ";
    for (int i = 0; i < length_2; i++)
    {
        cout << nums_2[i] << " ";
    }
    cout << endl;
    int count_2 = delete_element(nums_2, length_2, val_2);
    cout << "After deleting element " << val_2 << " in array 2: ";
    for (int i = 0; i < length_2 - 1; i++)
    {
        cout << nums_2[i] << " ";
    }
    cout << endl;
    cout << count_1 << endl;
    cout << count_2 << endl;
    return 0;
}
int delete_element(int nums[], int length, int val)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (nums[i] != val)
        {
            nums[count] = nums[i];
            count += 1;
        }
    }
    return count;
}