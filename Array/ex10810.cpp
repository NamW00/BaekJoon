#include <iostream>
using namespace std;

int main()
{
    int num, count = 0;
    int arr[101] = {0,};
    int startNum, endNum, ballNum = 0;

    cin >> num >> count;

    for (int i = 0; i < count; i++)
    {
        cin >> startNum >> endNum >> ballNum;
        for (int j = startNum; j <= endNum; j++) 
            arr[j] = ballNum;
    }
    
    for (int i = 1; i <= num; i++)
    {
        cout << arr[i] << ' ';
    }
    
    return 0;
}
