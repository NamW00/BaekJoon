#include <iostream>
using namespace std;

int main()
{
    int t;
    string word;

    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        cin >> word;
        cout << word[0] << word[word.length() - 1]<< endl;
    }
    
    return 0;
}