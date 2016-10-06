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

int N,len,x,y,z,ans,temp;
char msk[10010];
bool bisa;

int main()
{
	scanf("%d",&N);getchar();
	gets(msk);len=strlen(msk);
	
	bisa=true,x=-1;
	ans=0;
	do
	{
		x++;
		z=x;
		temp=0;
		
		while(temp<N)
		{
			y=z;
			while((y<len)&&(msk[y]!='.')&&(msk[y]!='?')&&(msk[y]!='!')) y++;
			if(temp+y-z+1>N) break;
	
			temp+=(y-z+1);
			z=y+1;
		}
		
		if(!temp)
		{
			bisa=false;
			break;
		}
		
		ans++;
		x=z;
		while((x<len)&&(msk[x]==' ')) x++;x--;
	}while(x+1<len);
	
	if(bisa) printf("%d\n",ans); else printf("Impossible\n");
	return 0;
}

