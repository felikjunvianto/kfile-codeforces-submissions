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

int up[100010],low[100010];
char msk[100010];
int x,y,z,len,ans;

int main()
{
	scanf("%s",msk);len=strlen(msk);
	for(x=0;x<len;x++) 
	{
		up[x]=low[x]=0;
		if(msk[x]>='A' && msk[x]<='Z') up[x]++;
		if(msk[x]>='a' && msk[x]<='z') low[x]++;
		
		if(!x) continue;
		up[x]+=up[x-1];
		low[x]+=low[x-1];
	}
	
	ans=INF;
	for(x=0;x<=len;x++)
	{
		int left=(x?low[x-1]:0);
		int right=(x?up[len-1]-up[x-1]:up[len-1]);
		//printf("%d %d %d\n",x,left,right);
		
		ans=min(ans,left+right);
	}
	printf("%d\n",ans);
	return 0;
}

