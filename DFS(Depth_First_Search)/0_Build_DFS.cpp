/*
    깊이 우선 탐색(DFS)
    깊이 우선 탐색은 탐색을 함에 있어서 보다 깊은 것을 우선적으로 하여
    탐색하는 알고리즘이다.

    너비 우선 탐색에서는 큐가 사용되었다면, 깊이 우선 탐색에서는 스택이 사용됩니다.

    더불어 사실 스택을 사용하지 않아도 구현이 가능하다는 특징이 있습니다.

    컴퓨터는 구조적으로 항상 스택의 원리를 사용하기 때문입니다.

    DFS Algorithm
    1. 스택의 최상단 노드를 확인합니다.
    2. 최상단 노드에게 방문하지 않은 인접 노드가 있으면 그 노드를 스택에 넣고 방문처리합니다. 
    3. 방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 뺍니다.

    위 알고리즘을 계속해서 반복 수행하면 된다.
*/
#include <iostream>
#include <vector>

using namespace std;

int number = 7;
int c[7];
vector<int> a[8];

void dfs(int x)
{
    if (c[x]) return;
    c[x] = true;
    cout << x << ' ';
    for (int i = 0; i < a[x].size(); i++)
    {
        int y = a[x][i];
        dfs(y);
    } 
}

int main(void)
{
    a[1].push_back(2);
    a[2].push_back(1);

    a[1].push_back(3);
    a[3].push_back(1);

    a[2].push_back(3);
    a[3].push_back(2);

    a[2].push_back(4);
    a[4].push_back(2);

    a[2].push_back(5);
    a[5].push_back(2);

    a[4].push_back(5);
    a[5].push_back(4);    

    a[3].push_back(6);
    a[6].push_back(3);

    a[3].push_back(7);
    a[7].push_back(3);

    a[6].push_back(7);
    a[7].push_back(6);

    dfs(1);

    return 0;
}