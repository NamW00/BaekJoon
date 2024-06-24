#include <iostream>
#include <string>
#include <algorithm> // reverse
using namespace std;

int main()
{
    string x, y;
    cin >> x >> y;
    string bigger;
    // reverse(문자열 이름.begin(), 문자열 이름.end());
    // reverse 함수는 문자열을 반전시켜서 저장하는 함수로 algorithm 헤더파일을
    // 선언하여 사용한다.
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    for (int i = 0; i < 3; i++)
    {
        if (x[i] > y[i])
        {
            bigger = x; break;
        }
        else if(x[i] < y[i])
        {
            bigger = y; break;
        }
        
    }
    cout << bigger;
    return 0;
}