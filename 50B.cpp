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

int cnt[40],x,y,len;
LL ans;
char msk[100100];

int main()
{
	scanf("%s",msk);len=strlen(msk);
	for(x=0;x<len;x++)
	{
		if((msk[x]>='a')&&(msk[x]<='z')) y=msk[x]-'a'; else y=msk[x]-'0'+26;
		cnt[y]++;
	}
	
	ans=0LL;
	for(x=0;x<40;x++) ans+=(LL)cnt[x]*cnt[x];
	printf("%I64d\n",ans);
	return 0;
}

