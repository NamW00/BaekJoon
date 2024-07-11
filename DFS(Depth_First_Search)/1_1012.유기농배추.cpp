/*
    1012번 - 유기농 배추
    https://www.acmicpc.net/problem/1012

    [ 문제 정리 ]
    입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 
    그 다음 줄부터 각각의 테스트 케이스에 대해 첫째 줄에는 
    배추를 심은 배추밭의 가로길이 M(1 ≤ M ≤ 50)과 세로길이 N(1 ≤ N ≤ 50), 
    그리고 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)이 주어진다. 
    그 다음 K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)가 주어진다. 
    두 배추의 위치가 같은 경우는 없다.

    [ 해결 방법 ]




    [ 자료형 ]
    1. M : 배추밭의 가로길이 (1 <= N <= 50)
    2. N : 배추밭의 세로길이 (1 <= M <= 50)
    3. K : 배추밭의 가로길이 (1 ≤ K ≤ 2500)


    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초

*/
#include <iostream>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<pair<int, int>> v;
stack<pair<int, int>> st;

int t, m, n, k;
int visited[51][51] = { 0, };

// 상하좌우 세팅
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void dfs(int x, int y)
{
   // 0으로 바꾸기(방문처리)
	visited[x][y] = 0;
     
    // 상하좌우 탐색
	for (int i = 0; i < 4; i++)
	{
		int searchX = dx[i] + x;
		int searchY = dy[i] + y;
        
        // 갈 수 있는 좌표라면
		if (searchY >= 0 && searchY < n && searchX >= 0 && searchX < m)
		{
            // 계산한 좌표가 배추 밭이라면
			if (visited[searchY][searchX] == 1)
				dfs(searchY, searchX);
		}
	}
}

int main()
{
   // 테스트 케이스 개수 입력
	cin >> t;

	int x, y;

	while(t--)
	{
		int count = 0;
        // 가로, 세로, 배수를 심은 밭 개수 
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++)
		{
            // 좌표 입력
			cin >> x >> y;
            // 해당 좌표 배추 밭 처리
			v.push_back({x, y});
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{  
                // 해당 좌표가 배추 밭이라면
				if (visited[i][j] == true)
				{
                    // DFS를 통해 연결되어 있는 배추 밭을 0으로 바꿈
					dfs(i, j);
                    // 개수를 셈
					count++;
				}
			}
		}
        // 개수 출력
		cout << count << endl;

        // 배열 초기화
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				visited[i][j] = 0;
			}
		}
        
	}
}