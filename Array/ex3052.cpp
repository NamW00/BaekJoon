#include <iostream>
using namespace std;

int main()
{
    int arr[42] = {0,};
    int input, remainder = 0;
    
    for (int i = 1; i <= 10; i++)
    {
        cin >> input;
        remainder = input % 42;
        arr[remainder] = 1;
    }
    int count = 0;
    for (int i = 0; i < 42; i++)
    {
        if (arr[i] == 1)
        {
            count++;
        }
    }
    cout << count << endl;
      
    return 0;
}