#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string color;
    int count = 1;

    cin >> n;
    cin >> color;
    
    for (int i = 1; i < color.size(); i++)
    {
        if (color[i] != color[0] && color[i] != color[i - 1])
        {
            count++;
        }
        else
        {
            continue;
        }
    }
    cout << count << endl;
    return 0;
}