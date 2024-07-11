/*
    1863번 - 스카이라인 쉬운거
    https://www.acmicpc.net/problem/1863

    [ 문제 정리 ]
    도시에서 태양이 질 때에 보이는 건물들의 윤곽을 스카이라인이라고 한다. 
    스카이라인만을 보고서 도시에 세워진 건물이 몇 채인지 알아 낼 수 있을까? 
    건물은 모두 직사각형 모양으로 밋밋하게 생겼다고 가정한다.

    정확히 건물이 몇 개 있는지 알아내는 것은 대부분의 경우에 불가능하고, 
    건물이 최소한 몇 채 인지 알아내는 것은 가능해 보인다. 
    이를 알아내는 프로그램을 작성해 보자.

    [ 해결 방법 ]

    스카이라인의 고도가 바뀌는 지점의 y좌표에만 관심을 가지면 된다.
    y좌표가 이전보다 작아질 때마다 건물 개수를 세어주면 된다.

    1. 건물의 y좌표들을 순서대로 push해줄 stack을 만들어준다.
    2. 스택이 비어있지 않고 top이 현재 y보다 크다면 건물개수를 증가시키고 pop을 한다.
    3. top과 y가 같다면 pop만 해준다.
    4. 스택에 현재 y값을 push한다.
    5. 위의 과정 반복이 끝난 후, 스택에 남아있을 건물도 세기위해 마지막에 y=0을 넣어주며 2번 과정을 한번 더 한다.
       건물 개수를 출력한다.

    [ 자료형 ]
    첫째 줄에 n이 주어진다. (1 ≤ n ≤ 50,000) 
    다음 n개의 줄에는 왼쪽부터 스카이라인을 보아 갈 때 스카이라인의 고도가 바뀌는 지점의 좌표 x와 y가 주어진다. 
    (1 ≤ x ≤ 1,000,000. 0 ≤ y ≤ 500,000) 
    첫 번째 지점의 x좌표는 항상 1이다.

    1. n : 스카이라인의 고도가 바뀌는 지점의 좌표 개수 (1 <= n <= 50,000)
    2. height : 스카인라인의 고도가 바뀌는 지점의 좌표 x


    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초

*/
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v;
    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(y);
    }

    stack<int> s;
    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        // 스택의 top에 위치한 높이가 현재 높이와 같거나 작아질 때까지 pop하고 count한다.
        // 이 때 값이 0일 경우(건물이 아님) count하지 않는다.
        // pop한 뒤 top에 위치한 높이가 현재 높이와 같을 경우 같은 건물이므로 push하지 않는다.
        while (!s.empty() && v[i] < s.top())
        {
            if (s.top() != 0)
            {
                count++;
            }
            s.pop();  
        }
        if (!s.empty() && v[i] == s.top())
        {
            continue;
        }
        s.push(v[i]);
    }
    // 0일 경우를 제외하고 stack에 남아있는 건물 수를 count에 더한다. 
    while (!s.empty())
    {
        if (s.top() != 0)
        {
            count++;
        }
        s.pop();  
    }
    cout << count << endl;
    return 0;
}