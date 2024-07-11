/*
    1092번 - 배
    https://www.acmicpc.net/problem/1092

    [ 문제 정리 ]
    방향 없는 그래프가 주어졌을 때, 
    연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

    

    [ 해결 방법 ]




    [ 자료형 ]
    1. N : 정점의 개수 (1 ≤ N ≤ 1,000)
    2. M : 간선의 개수 (0 ≤ M ≤ N×(N-1)/2)
    3. u, v : 간선의 양 끝점 (1 ≤ u, v ≤ N, u ≠ v)

    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[1001];
vector<int> v[1001];

#pragma region 넓이 우선 탐색
    void BFS(int start)
    {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < v[x].size(); i++)
            {
                if (!visited[v[x][i]])
                {
                    visited[v[x][i]] = true;
                    q.push(v[x][i]);
                }        
            }     
        }
    }
    int main()
    {
        int vertex, edge, start, end, count = 0;
        cin >> vertex >> edge;

        for (int i = 0; i < edge; ++i)
        {
            cin >> start >> end;
            v[start].push_back(end);
            v[end].push_back(start);
            
        }
        
        for (int i = 1; i <= vertex; ++i)
        {
            if (visited[i] == false)
            {
                BFS(i);
                count++;
            }
        }
        
        cout << count << endl;

        return 0;
    }
#pragma endregion
#pragma region 유니온 파인드
    /*
    #include <iostream>
    using namespace std;

    int* master_arr;
    int* master_cnt;

    int find(int x) {
        if (master_arr[x] == x)
            return x;

        int root = find(master_arr[x]);
        master_arr[x] = root;

        return root;
    }

    void union_master(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);

        if (root_a == root_b)
            return;

        master_cnt[root_b] = 0;
        master_cnt[root_a] = 1;
        master_arr[root_b] = root_a;

        return;
    }


    int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        // 변수 입력
        int N, M; // N점의 수, M 간선수;
        cin >> N >> M;

        ///유니온 파인드로 풀 수 있을 듯
        // 기본 설정
        master_arr = new int[N+1];
        master_cnt = new int[N+1];
        for (int i = 0; i <= N; i++) {
            master_arr[i] = i;
            master_cnt[i] = 1;
        }
        master_cnt[0] = 0;

        // node를 받아가며 유니온 파인드 진행
        for (int i = 0; i < M; i++) {
            int node_a, node_b;
            cin >> node_a >> node_b;
            union_master(node_a, node_b);
        }

        
        //결과 출력
        //for (int i = 1; i <= N; i++) {
        //	cout << master_arr[i] << " ";
        //}
        //cout << "\n";
        //for (int i = 1; i <= N; i++)
        //	cout << master_cnt[i] << " ";
        //cout << "\n";

        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            if (master_cnt[i] == 1)
                cnt++;
        }

        cout << cnt;
    }
    */
#pragma endregion