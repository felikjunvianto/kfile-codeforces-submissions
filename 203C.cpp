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

typedef struct
{
	int tot,num;
} data;

bool cf(data i, data j)
{
	if(i.tot!=j.tot) return i.tot<j.tot;
	return i.num<j.num;
}

data cust[100010];
int N,D,a,b,x,y,i;
vector<int> ans;

int main()
{
	scanf("%d %d",&N,&D);
	scanf("%d %d",&a,&b);
	for(i=1;i<=N;i++) 
	{
		scanf("%d %d",&x,&y);
		cust[i-1] = (data) {a*x + y*b, i};
	}
	sort(cust,cust+N, cf);
	
	ans.clear();
	for(i=0;i<N && D>=cust[i].tot;i++)
	{
		D-=cust[i].tot;
		ans.pb(cust[i].num);
	}
	
	printf("%d\n",(int)ans.size());
	for(i=0;i<ans.size();i++) printf("%d%c",ans[i],i+1==(int)ans.size()?'\n':' ');
	return 0;
}

