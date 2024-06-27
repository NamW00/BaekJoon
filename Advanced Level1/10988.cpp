#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    cin >> input;
    int size = input.size();
    for (int i = 0; i < size / 2; i++)
    {
        if (input[i] != input[size - i - 1])
        {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}