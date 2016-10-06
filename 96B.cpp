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

vector<LL> lucky;
queue<pair<LL,int> > q;
int x;
LL now;

int main()
{
	q.push(mp(0LL,0));
	while(!q.empty())
	{
		now=q.front().fi;
		x=q.front().se;
		q.pop();
		if((now)&&(!x)) lucky.pb(now);
		if(now<=INF)
		{
			q.push(mp(now*10LL+4LL,x+1));
			q.push(mp(now*10LL+7LL,x-1));
		}
	}
	
	sort(lucky.begin(),lucky.end());
	scanf("%I64d",&now);
	x=lower_bound(lucky.begin(),lucky.end(),now)-lucky.begin();
	printf("%I64d\n",lucky[x]);
	return 0;
}

