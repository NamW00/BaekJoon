#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int count = 1;
    getline(cin, str);
    // getlin(cin,변수); 로 공백을 포함한 문자열을 입력받을 수 있다.
    // 공백을 포함한 문자열을 입력받는 방법
    // string 헤더파일에 포함된 getline이라는 함수를 이용하여
    // 공백을 포함시킨 단어를 입력받을 수 있다.

    // 필요조건 : 입력받은 단어가 없을 때 단어의 개수가 0이므로 0을 출력
    if (str.length() == 1 && str[0] == ' ')
    {
        cout << 0;
        return 0;
    }
    
    for (int i = 1; i < str.length() - 1; i++)
    {
        if (str[i] == ' ') count++;
    }
    cout << count;

    return 0;
}