#include <iostream>
using namespace std;

int main()
{
    int t, repeat;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> repeat >> s;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < repeat; j++)
            {
                cout << s[i];
            }
        }
        cout << endl;
    }
    return 0;
}