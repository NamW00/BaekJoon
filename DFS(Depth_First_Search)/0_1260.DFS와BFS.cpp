/*
    1260번 - DFS와 BFS
    https://www.acmicpc.net/problem/1260

    [ 문제 정리 ]
    그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
    단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 
    더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다

    [ 해결 방법 ]
    첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 
    탐색을 시작할 정점의 번호 V가 주어진다. 
    다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 
    어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.



    [ 자료형 ]
    1. Vertex : 정점의 개수 (1 <= N <= 1,000)
    2. Edge : 간선의 개수 (1 <= M <= 10,000)
    3. startNum : 탐색을 시작할 정점의 번호


    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초
*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> v[1001];
bool visited[1001];

void DFS(int start)
{
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        cout << x << " ";
        for (int i = 0; i < v[x].size(); ++i)
        {
            int y = v[x][i];
            if (!visited[y])
            {
                s.push(y);
                visited[y] = true;
            }
        }
    }
    
    

}

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        // 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for (int i = 0; i < v[x].size(); ++i)
        {
            int y = v[x][i];
            if (!visited[y])
            {
                q.push(y);
                visited[y] = true;
            }    
        }  
    }
}

int main()
{
    int vertex, edge, start, x, y;
    cin >> vertex >> edge >> start;

    // 입력값 각 vector값에 대입(양방향으로)
    for (int i = 0; i < edge; ++i)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);    
    }

    for (int i = 1; i <= vertex; i++)
    {
        v[i].begin(), v[i].end();
    }
    

    // DFS(start);
    memset(visited, false, sizeof(visited));
    BFS(start);

    return 0;
}