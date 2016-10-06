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

char msk[2000];
int cnt[1111],len,x,y,maks,mien,temp;
bool awal;

int main()
{
	scanf("%s",msk);len=strlen(msk);
	temp=maks=0,mien=2000;
	memset(cnt,0,sizeof(cnt));
	for(x=0;x<=len;x++) if((x==len)||(msk[x]==','))
	{
		cnt[temp]++;
		maks=max(maks,temp);
		mien=min(mien,temp);
		temp=0;
	} else temp=temp*10+(msk[x]-'0');
	
	x=mien-1;
	awal=true;
	do
	{
		x++;y=x;
		while((y<=maks)&&(cnt[y])) y++;
		
		if(!awal) printf(",");
		awal=false;
		printf("%d",x);
		if((y-1)!=x) printf("-%d",y-1);
		while((y<=maks)&&(!cnt[y])) y++;
		x=y-1;
	}while(x<maks);
	printf("\n");
	return 0;
}

