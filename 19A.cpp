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

typedef struct{string name;int poin,scored,missed;} team;

string tim[111];
char mska[50],mskb[50],dummy;
int N,x,ida,idb,a,b;
team ans[111];

bool cfscore(team i,team j)
{
	if(i.poin!=j.poin) return(i.poin>j.poin);
	if(i.scored-i.missed!=j.scored-j.missed) return(i.scored-i.missed>j.scored-j.missed);
	if(i.scored!=j.scored) return(i.scored>j.scored);
	return(i.name<j.name);
}

bool cfname(team i,team j)
{
	return(i.name<j.name);
}

int main()
{
	scanf("%d",&N);
	for(x=0;x<N;x++)
	{
		scanf("%s",mska);
		tim[x]=mska;
	}
	sort(tim,tim+N);
	for(x=0;x<N;x++) ans[x]=(team){tim[x],0,0,0};
	
	for(x=1;2*x<=N*(N-1);x++)
	{
		getchar();
		scanf("%[^-]%c%s %d:%d",mska,&dummy,mskb,&a,&b);
		ida=lower_bound(tim,tim+N,mska)-tim;
		idb=lower_bound(tim,tim+N,mskb)-tim;
		ans[ida].scored+=a,ans[ida].missed+=b;
		ans[idb].scored+=b,ans[idb].missed+=a;
		
		if(a==b) ans[ida].poin++,ans[idb].poin++; else
		if(a>b) ans[ida].poin+=3; else ans[idb].poin+=3;
	}
	
	sort(ans,ans+N,cfscore);
	sort(ans,ans+(N/2),cfname);
	
	for(x=0;2*x<N;x++) printf("%s\n",ans[x].name.c_str());
	return 0;
}

