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
#define INF 2000000000

using namespace std;

int N;
map<int, int> bunga;

int main()
{
	scanf("%d", &N);
	int tergede = -INF, terkecil = INF;
	
	int now;
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &now);
		tergede = max(tergede, now);
		terkecil = min(terkecil, now);
		
		if(bunga.find(now) == bunga.end()) bunga[now] = 1;
			else bunga[now]++;
	}
	
	int jarak = tergede - terkecil;
	LL ans = 0;
	
	for(map<int,int>::iterator it = bunga.begin(); it != bunga.end(); it++)
	{
		int b = it->fi, cnt = it->se;
		int a = b - jarak;
		
		if(a <= 0 || bunga.find(a) == bunga.end()) continue;
		ans += (a == b) ? (LL) cnt * (LL) (cnt - 1LL) / 2LL : (LL) bunga[a] * (LL) cnt;
	}
	
	printf("%d %I64d\n", jarak, ans);
	return 0;
}

