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

using namespace std;

int next,N,M,x,ans;
bool cek[1010];
char arah[10],da[10],db[10],dc[10];

int main()
{
	scanf("%d %d",&N,&M);
	memset(cek,true,sizeof(cek));
	while(M--)
	{
		scanf("%s %s %s %s %d",da,db,arah,dc,&x);
		if(arah[0]=='r') next=-1; else next=1;
		for(int i=x;i&&(i<=N);i+=next) cek[i]=false;
	}
	
	ans=0;
	for(x=1;x<=N;x++) if(cek[x]) ans++;
	printf("%d\n",ans?ans:-1);
	return 0;
}

