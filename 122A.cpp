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

queue<int> q;
vector<int> lucky;
int x,y;
bool oke;

int main()
{
	q.push(0);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		lucky.pb(now);
		for(x=4;x<=7;x+=3)
		{
			int temp=now*10+x;
			if(temp>1000) continue;
			q.push(temp);
		}
	}
	
	scanf("%d",&x);
	oke=false;
	for(y=1;y<lucky.size();y++) if(x%lucky[y]==0)
	{
		oke=true;
		break;
	}
	
	printf("%s\n",oke?"YES":"NO");
	return 0;
}

