// 2212번: 센서
// https://www.acmicpc.net/problem/2212

// 문제 정리
// 1. 고속도로 위에 N개의 센서를 설치함
// 2. 예산상의 문제로, 고속도로 위에 최대 K개의 집중국을 세울 수 있다고 한다.
// 3. 각 집중국은 센서의 수신 가능 영역을 조절할 수 있다. 
//    집중국의 수신 가능 영역은 고속도로 상에서 연결된 구간으로 나타나게 된다.
// 4. N개의 센서가 적어도 하나의 집중국과는 통신이 가능해야 하며, 
// 5. 집중국의 유지비 문제로 인해 각 집중국의 수신 가능 영역의 길이의 합을 최소화해야 한다.

// 각 집중국의 수신 가능 영역의 거리의 합의 최솟값을 구하는 프로그램을 작성하시오.
// 집중국의 수신 가능 영역의 길이는 0 이상이며 모든 센서의 좌표가 다를 필요는 없다.

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, pos;
int result;
int input[100001];
priority_queue< int, vector<int>, greater<int> > pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> input[i];
    }
    sort(input, input + n);

    pos = input[0];
    for (int i = 1; i < n; i++)
    {
        pq.push(input[i] - pos);
        pos = input[i];
    }

    for (int i = 0; i < n - k; ++i)
    {
        result += pq.top();
        pq.pop();
    }

    cout << result << endl;

    return 0;
}
