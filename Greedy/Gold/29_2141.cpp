/*
    2141번 우체국
    https://www.acmicpc.net/problem/2141
    
    [ 문제 정리 ]
    수직선과 같은 일직선상에 N개의 마을이 위치해 있다. 
    i번째 마을은 X[i]에 위치해 있으며, A[i]명의 사람이 살고 있다.

    이 마을들을 위해서 우체국을 하나 세우려고 하는데, 그 위치를 어느 곳으로 할지를 현재 고민 중이다. 
    고민 끝에 나라에서는 각 사람들까지의 거리의 합이 최소가 되는 위치에 우체국을 세우기로 결정하였다. 
    우체국을 세울 위치를 구하는 프로그램을 작성하시오.

    각 마을까지의 거리의 합이 아니라, 각 사람까지의 거리의 합임에 유의한다

    [ 해결 방법 ]
    



    [ 자료형 ]
    N : 마을 개수(1 ≤ N ≤ 100,000)
    X[i] : 마을 위치 (|X[i]| ≤ 1,000,000,000)
    A[i] : 마을 거주 사람 수 (1 ≤ A[i] ≤ 1,000,000,000)

    [ 시간 복잡도 ]
    N = 100,000,000 (1억) => 1초
*/
#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;


int n;
pair<ll, ll> arr[100001];
ll sum;

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
		sum += arr[i].second;
	}

	sort(arr, arr + n);

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		ans += arr[i].second;
        // 홀수일 때, 절반 이상
		if (ans >= (sum + 1) / 2) {
			cout << arr[i].first;
			break;
		}
	}
}