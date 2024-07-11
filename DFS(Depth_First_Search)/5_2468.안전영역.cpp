/*
    1092번 - 배
    https://www.acmicpc.net/problem/1092

    [ 문제 정리 ]
    재난방재청에서는 많은 비가 내리는 장마철에 대비해서 다음과 같은 일을 계획하고 있다. 
    먼저 어떤 지역의 높이 정보를 파악한다. 
    그 다음에 그 지역에 많은 비가 내렸을 때 물에 잠기지 않는 안전한 영역이 최대로 몇 개가 만들어 지는 지를 조사하려고 한다. 
    이때, 문제를 간단하게 하기 위하여, 장마철에 내리는 비의 양에 따라 일정한 높이 이하의 모든 지점은 물에 잠긴다고 가정한다.
    어떤 지역의 높이 정보가 주어졌을 때, 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 계산하는 프로그램을 작성하시오.
    [ 해결 방법 ]




    [ 자료형 ]
    1. N : 지역의 행과 열 개수 (2 <= N <= 100)
    2. map[N][N] : 각 영역의 고도 (1 <= map[i][j] <= 100)

    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

int n, cnt;
int input[MAX][MAX];
int map[MAX][MAX];
bool visited[MAX][MAX];
vector<int> v;


// 상하좌우 세팅
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void DFS(int y, int x)
{
   // 0으로 바꾸기(방문처리)
	visited[y][x] = true;
     
    // 상하좌우 탐색
	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;
        
        // 갈 수 있는 좌표라면
		if (ny >= 0 && ny < n && nx >= 0 && nx < n)
		{
            // 계산한 좌표가 안전지대라면 DFS실행
			if (map[ny][nx] && !visited[ny][nx])
            {
                visited[ny][nx] = true;
				DFS(ny, nx);
            }
		}
	}
}

void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map[i][j] = 0;
            visited[i][j] = 0;
        } 
    }
    cnt = 0;
}

int main()
{
    int maxVal = -1;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> input[i][j];
            if (input[i][j] > maxVal)
            {
                maxVal = input[i][j];
            }
            
        }
    }

    for (int h = 1; h <= maxVal; ++h)
    {
        memset(map,0,sizeof(map));
        cnt = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (input[i][j] >= h)
                {
                    map[i][j] = 1;
                }
            }
        }   

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {  
                // 해당 좌표가 안전지대라면
                if (map[i][j] && !visited[i][j])
                {
                    DFS(i, j);
                    // 영역 카운트
                    cnt++;
                }
            }
        }
        v.push_back(cnt);

        reset();
    }
    
    sort(v.begin(), v.end());

    // 안전지대 수 출력
    cout << v[v.size() - 1] << endl;
    return 0;
}