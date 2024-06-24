#include <iostream>

using namespace std;

int main()
{   
    int total = 0;
    cin >> total;
    int start = total / 5;
    int remain = (total - start*5) % 2;
    while (remain != 0)
    {
        if (start == 0)
        {
            cout << -1;
            return 0;
        }
        start -= 1;
        remain = (total - start*5) % 2;
    }
    
    cout << start + (total - start*5) / 2;
    return 0;
}