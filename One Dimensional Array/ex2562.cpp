#include <iostream>
using namespace std;

int main()
{
    int arr[9];
    
    // 배열의 길이 : sizeof(arr) / sizeof(*arr)
    // sizeof(arr) = 40 -> 총 배열의 크기(byte)
    // sizeof(*arr) = 4 -> index 한칸의 크기(byte)
    for (int i = 0; i < sizeof(arr) / sizeof(*arr) ; i++)
    {
        cin >> arr[i];
    }
    int maxValue = -1;
    int maxValueIndex;
    for (int i = 0; i < sizeof(arr) / sizeof(*arr) ; i++)
    {
        if(maxValue < arr[i])
        {
            maxValue = arr[i];
            maxValueIndex = i;
        }
    }
    cout << maxValue << endl;
    cout << maxValueIndex + 1 << endl;
    
    return 0;
}
