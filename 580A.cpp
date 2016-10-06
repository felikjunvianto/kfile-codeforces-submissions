#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double> 
#define LL long long
#define INF 1000000000

using namespace std;

int N, A[100010];

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &A[i]);
	
	int x = 0, ans = 0;
	while(x < N)
	{
		int y = x + 1;
		while(y < N && A[y] >= A[y-1]) y++;
		
		ans = max(ans, y - x);
		x = y;
	}
	
	printf("%d\n", ans);
	return 0;
}

