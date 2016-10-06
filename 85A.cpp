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

int N,x,y,z;
char ans[5][110];

int main()
{
	scanf("%d",&N);
	if(N==1) printf("a\na\nb\nb\n"); else
	if(N==2) printf("aa\nbb\ncc\ndd\n"); else
	{
		if(N&1) 
		{
			ans[1][1]=ans[2][1]=ans[3][N]=ans[4][N]='z';
			z=0;
			for(x=2;x<N;x+=2)
			{
				ans[1][x]=ans[1][x+1]=z+'a';z=(z+1)%4;
				ans[2][x]=ans[2][x+1]=z+'a';z=(z+1)%4;
			}	
		
			z=0;
			for(x=1;x<N;x+=2)
			{
				ans[3][x]=ans[3][x+1]=z+10+'a';z=(z+1)%4;
				ans[4][x]=ans[4][x+1]=z+10+'a';z=(z+1)%4;
			}	
		}
	
		else
		{
			z=0;
			for(x=1;x<=N;x+=2)
			{
				ans[1][x]=ans[1][x+1]=ans[4][x]=ans[4][x+1]='z'-z;
				z^=1;
			}
		
			z=1;
			ans[2][1]=ans[3][1]='a';
			for(x=2;x<N;x+=2)
			{
				ans[2][x]=ans[2][x+1]=z+'a';z=(z+1)%24;
				ans[3][x]=ans[3][x+1]=z+'a';z=(z+1)%24;
			}
			ans[2][N]=ans[3][N]=z+'a';
		}
			
		for(x=1;x<=4;x++)
			for(y=1;y<=N;y++)
			{
				printf("%c",ans[x][y]);
				if(y==N) printf("\n");
			}
	}
	return 0;
}

