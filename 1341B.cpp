#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int> 
#define pdd pair<double,double>
#define LL long long

#define PI 2*acos(0.0)
#define EPS 1e-9
#define INF 1e9

using namespace std;

const int SIZE = 2e5 + 10;

int T, K, N;
int arr[SIZE];
int pSum[SIZE];

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &N, &K);
		for(int i = 0; i < N; i++) scanf("%d", &arr[i]);

		memset(pSum, 0, sizeof(pSum));
		for(int i = 1; i + 1 < N; i++) {
			pSum[i] = pSum[i-1];
			if(arr[i-1] < arr[i] && arr[i] > arr[i+1]) pSum[i]++;
		}

		int L = 1, t = 1;
		for(int i = 0; i + K <= N; i++) {
			int pCnt = pSum[i + K - 2] - pSum[i];
			if(t < pCnt + 1) {
				t = pCnt + 1;
				L = i + 1;
			}
		}

		printf("%d %d\n", t, L);
	}
	return 0;
}

