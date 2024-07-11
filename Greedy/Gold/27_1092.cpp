/*
    1092번 - 배
    https://www.acmicpc.net/problem/1092

    [ 문제 정리 ]
    지민이는 항구에서 일한다. 그리고 화물을 배에 실어야 한다. 모든 화물은 박스에 안에 넣어져 있다. 
    항구에는 크레인이 N대 있고, 1분에 박스를 하나씩 배에 실을 수 있다. 
    모든 크레인은 동시에 움직인다.

    각 크레인은 무게 제한이 있다. 
    이 무게 제한보다 무거운 박스는 크레인으로 움직일 수 없다.
    모든 박스를 배로 옮기는데 드는 시간의 최솟값을 구하는 프로그램을 작성하시오.

    [ 해결 방법 ]




    [ 자료형 ]
    1. N : 크레인 개수 (1 <= N <= 50)
    2. crane : 각 크레인의 무게 제한 (limit <= 1,000,000)
    3. M : 박스의 수 (M <= 10,000)
    4. boxes : 각 박스의 무게 (weight <= 1,000,000)


    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int N, M;
    std::vector<int> cranes;
    std::vector<int> boxes;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int input = 0;
        cin >> input;
        cranes.push_back(input);
    }

    sort(cranes.begin(), cranes.end(), greater<int>());

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int input = 0;
        cin >> input;
        boxes.push_back(input);
    }
    sort(boxes.begin(), boxes.end(), greater<int>());
    
    if (cranes[0] < boxes[0])
    {
        cout << -1 << endl;
        return 0;
    }

    int result = 0;
    while (!boxes.empty())
    {
        result += 1;
        for (int i = 0; i < cranes.size(); ++i)
        {
            for (int j = 0; j < boxes.size(); ++j)
            {
                if (cranes[i] >= boxes[j])
                {
                    boxes.erase(boxes.begin() + j);
                    break;
                }   
            }  
        } 
    }
    cout << result << endl;
    return 0;
}