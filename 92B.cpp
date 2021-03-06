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

char msk[1000100];
int bin[1000100],dpn,blkg;
int x,y,z,len,ans;

int main()
{
	scanf("%s",msk);len=strlen(msk);
	memset(bin,0,sizeof(bin));
	for(x=0;x<len;x++) bin[x]=msk[len-x-1]-'0';
	ans=0;
	blkg=0;
	dpn=len-1;
	while(blkg!=dpn) 
	{
		if(!bin[blkg])
		{
			y=blkg;
			while((y<dpn)&&(!bin[y])) y++;
			ans+=(y-blkg);
			blkg=y;
		}
				  
		else
		{
			ans++;
			y=blkg;
			z=1;
			while(z)
			{
				bin[y]+=z;
				z=bin[y]/2;
				bin[y]%=2;
				y++;
			}
			dpn=max(dpn,y-1);
		}
	}
	printf("%d",ans);
	return 0;
}

