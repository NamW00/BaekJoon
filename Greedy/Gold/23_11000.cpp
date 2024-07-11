#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int ans;
vector< pair<int,int> > v;
priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }
    sort(v.begin(), v.end());

    pq.push(v[0].second);
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first >= pq.top())
        {
            pq.pop();
            pq.push(v[i].second);
        }
        if (v[i].first < pq.top())
        {
            pq.push(v[i].second);
        }     
    }
    cout << pq.size() << endl;
    return 0;
}