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

int V, E;
int val[555];
vector<PII> elist;

int main()
{
	scanf("%d %d", &V, &E);
	for(int i = 1; i <= V; i++) scanf("%d", &val[i]);
	
	for(int i = 0; i < E; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		elist.pb(mp(val[a] + val[b], c));
	}
	
	if(V == 1 || E == 0) printf("0\n"); else
	{
		int num = elist[0].fi, denum = elist[0].se;
		for(int i = 1; i < elist.size(); i++)
			if(num * elist[i].se < elist[i].fi * denum)
			{
				num = elist[i].fi;
				denum = elist[i].se;
			}
			
		printf("%.10lf\n", num / (double) denum);
	}
	return 0;
}

