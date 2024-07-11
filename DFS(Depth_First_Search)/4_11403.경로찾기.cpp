/*
    1092번 - 배
    https://www.acmicpc.net/problem/1092

    [ 문제 정리 ]
    가중치 없는 방향 그래프 G가 주어졌을 때, 모든 정점 (i, j)에 대해서, 
    i에서 j로 가는 길이가 양수인 경로가 있는지 없는지 구하는 프로그램을 작성하시오.

    [ 해결 방법 ]




    [ 자료형 ]
    1. N : 정점의 개수 (1 <= N <= 100)
    2. map[N][N] : 인접 행렬
    
    입력시에 map[i][j]의 값이
    1) 1이면 : i에서 j로 가는 간선이 존재한다는 뜻
    2) 0이면 : i에서 j로 가는 간선이 존재하지 않는다는 뜻
    3) map[n][n]의 값은 항상 0이다
    

    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초
*/
#pragma region 플로이드-와샬 알고리즘
    #include <iostream>

    using namespace std;
    int g[101][101];
    int main()
    {
        int v;
        cin >> v;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cin >> g[i][j];
            } 
        }
        // k : 거처가는 노드
        for (int k = 0; k < v; k++)
        {
            // i : 시작 노드
            for (int i = 0; i < v; i++)
            {
                // j : 도착 노드
                for (int j = 0; j < v; j++)
                {
                    if (g[i][k] && g[k][j])
                    {
                        g[i][j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        return 0;
    }
#pragma endregion
#pragma region 깊이 우선 탐색
    /*
    #include <iostream>
    #include <vector>

    using namespace std;

    vector<int> vertex[101];
    int map[101][101];
    bool visited[101];

    void DFS(int start, int ft) {
        for (int i : vertex[start]) {
            if (!visited[i]) {
                visited[i] = true;
                map[ft][i] = 1;
                DFS(i, ft);
            }
        }
    }

    int main() {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> map[i][j];
                if (map[i][j]) vertex[i].push_back(j);
            }
        }

        for (int i = 1; i <= n; i++) {
            memset(visited, 0, sizeof(visited)); // visited 배열 초기화
            DFS(i, i);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << map[i][j] << ' ';
            }
            cout << '\n';
        }

        return 0;
    }
    */
#pragma endregion