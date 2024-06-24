#include <iostream>
using namespace std;

int main()
{
    int startNum[26] = {0, };
    
    string word;
    
    cin >> word;
    
    // word.find(n)
    // 문자열 word에서 문자열 n이 최초로 등장하는 인덱스 번호를 반환해주는 함수이다.
    // 만약 찾는 문자열이 없을 경우 string::npos 를 반환한다.
    // npos의 값은 -1이지만 자료형이 unsigned이므로 int로 캐스팅 후 출력한다.
    for (char i = 'a'; i <= 'z'; i++)
    {
        cout << (int)word.find(i) << ' ';
    }

    return 0;
}