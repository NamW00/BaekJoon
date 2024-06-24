#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int init, result;
    cin >> init >> result;

    int count = 1;
    while (true)
    {
        if (init == result)
            break;
        else if(init > result)
        {
            count = -1;
            break;
        }
        
        if (result % 2 == 0)
        {
            result /= 2;
        }
        else if(result % 10 == 1)
        {
            result = (result - 1) / 10;
        }
        else
        {
            count = -1;
            break;
        }
        count++;
    }

    cout << count << endl;

    return 0; 
}