#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool IsPerson(int num)
{
    if(num <= 0)
        return false;
    else
        return true;
}

long long pos[100001];

int main()
{
    int n = 0, dist = 0;
    string sit;
    cin >> n >> dist;
    cin >> sit;
    for (int i = 0; i < n; i++)
    {
        if (sit[i] == 'H')
        {
            pos[i] = 1;
        }
        if (sit[i] == 'P')
        {
            pos[i] = 0;
        }  
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (pos[i] == 0) // 사람있는 칸이면?
        {
            for (int j = i - dist; j <= i + dist; j++)
            {
               if (j < 0 || j > n - 1)
               {
                    continue;
               }

               if(pos[j] == 1)
               {
                    pos[j] = 2;
                    count++;
                    break;
               } 
            } 
        }
        else 
        {
            continue;
        }
    }

    
    cout << count << endl;
    return 0;
}