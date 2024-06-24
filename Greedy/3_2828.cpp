#include <iostream>

using namespace std;

int main()
{
    int n, m, a;
    int count = 0;
    int applePos = 0;

    cin >> n >> m >> a;

    int s = 1, l = m;

    for (int i = 0; i < a; i++)
    {
        cin >> applePos;

        if (s <= 1 && l >= n)
        {
            continue;
        }
        
        if (l < applePos)
        {         
            count += (applePos - l);
            l = applePos;
            s = l - m + 1;
        }
        else if(s > applePos)
        {
            count += (s - applePos);
            s = applePos;
            l = s + m - 1;
        }
    }
    
    cout << count << endl;

    return 0;
}