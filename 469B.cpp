#include <cstdio>
#include <cstdlib>
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
#include <set>

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

int waktu[2010], P, Q, L, R;
PII jadwal[60];

int main()
{
	scanf("%d %d %d %d", &P, &Q, &L, &R);
	memset(waktu, 0, sizeof(waktu));
	
	int a, b;
	while(P--)
	{
		scanf("%d %d", &a, &b); a++; b++;
		for(int i = a; i <= b; i++) waktu[i]++;
	}
	
	for(int i = 1; i <= 2001; i++) waktu[i] += waktu[i - 1];
	
	for(int i = 0; i < Q; i++)
	{
		scanf("%d %d", &a, &b); a++; b++;
		jadwal[i] = mp(a, b);
	}
	
	int ans = 0;
	for(int t = L; t <= R; t++)
	{
		bool ada = false;
		for(int i = 0; i < Q && !ada; i++)
		{
			int c = jadwal[i].fi + t, d = jadwal[i].se + t;
			if(waktu[d] - waktu[c - 1] > 0) ada = true;
		}
		
		if(ada) ans++;
	}
	
	printf("%d\n", ans);
	return 0;
}

