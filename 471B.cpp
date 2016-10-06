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

int N;
PII kerja[2020];

bool cf(PII i, PII j)
{
	if(i.se != j.se) return i.se < j.se;
	return i.fi < j.fi;
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		kerja[i].fi = i + 1;
		scanf("%d", &kerja[i].se);
	}
	sort(kerja, kerja + N, cf);
	
	int butuh = 3;
	int x = 0;
	do
	{
		int y = x;
		while(y < N && kerja[y].se == kerja[x].se) y++;
		if(y - x > 1) butuh -= (y - x);
		
		x = y;
	} while(x < N && butuh > 0);
	
	if(butuh > 0) printf("NO\n"); else
	{
		printf("YES\n");
		int num = 0;
		x = 0;
		do
		{
			int y = x;
			while(y < N && kerja[y].se == kerja[x].se) y++;
			if(y - x > 1) 
			{
				if(num != 0) next_permutation(kerja + x, kerja + y);
				
				do
				{
					for(int i = 0; i < N; i++) printf("%d%c", kerja[i].fi, i + 1 == N ? '\n' : ' ');
					num++;
				} while(num < 3 && next_permutation(kerja + x, kerja + y));
			}
			
			x = y;
		} while(num < 3 && x < N);
	}
	return 0;
}

