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

int N, x;
int t[2010], h[2010], m[2010];

int coba(int startT)
{
	bool eaten[2010];
	memset(eaten, false, sizeof(eaten));
	
	int nowT = startT, ans = 0, abJump = x;
	
	while(true)
	{
		int toEat = -1;
		for(int i = 0; i < N; i++) if(t[i] == nowT && !eaten[i] && abJump >= h[i])
			if(toEat == -1 || m[toEat] < m[i]) toEat = i;
		
		if(toEat == -1) break;
		//printf("%d\n", toEat);
		eaten[toEat] = true;
		abJump += m[toEat];
		nowT = 1 - nowT;
		ans++;
	}
	
	//printf("--->%d\n", ans);
	return ans;
}

int main()
{
	scanf("%d %d", &N, &x);
	for(int i = 0; i < N; i++) {
		scanf("%d %d %d", &t[i], &h[i], &m[i]);
		if(t[i] != 0) t[i] = 1;
	}
	
	printf("%d\n", max(coba(0), coba(1)));
	return 0;
}

