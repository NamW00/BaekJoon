#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0, c = 0;
    cin >> n >> c;
    int x[100001];


    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    sort(x, x + n);
    
    
    
    return 0;
}