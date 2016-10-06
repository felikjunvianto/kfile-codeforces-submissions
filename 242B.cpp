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

int le, ri, N, x, y, z;
PII segment[100005];

int main()
{
	scanf("%d",&N);
	for(x=1;x<=N;x++)
	{
		scanf("%d %d",&y, &z);
		segment[x] = mp(y,z);
	}
	
	le = 2*INF; ri = 0;
	for(x=1;x<=N;x++)
	{
		le = min(le, segment[x].fi);
		ri = max(ri, segment[x].se);
	}
	
	int ans = -1;
	for(x=1;x<=N;x++)
		if(segment[x].fi <= le && segment[x].se >= ri)
		{
			ans = x;
			break;
		}
		
	printf("%d\n",ans);
	return 0;
}

