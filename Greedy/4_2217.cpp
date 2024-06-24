#include <iostream>
#include <algorithm>

using namespace std;

int n;
int result;
int weight[100000];

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    sort(weight, weight + n);
    for (int i = 0; i < n; i++)
    {
        result = max(result, (n - i) * weight[i]);
    }
    
    cout << result;

    return 0;
}