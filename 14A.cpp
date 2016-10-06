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

int bawah,samping,xa,xb,ya,yb,x,y,z;
char grid[100][100];
bool jalan;

int main()
{
	scanf("%d %d",&bawah,&samping);getchar();
	for(y=1;y<=bawah;y++)
		for(x=1;x<=samping;x++)
		{
			scanf("%c",&grid[x][y]);
			if(x==samping) getchar();
		}
		
	for(xa=1;xa<=samping;xa++)
	{
		jalan=true;
		for(y=1;y<=bawah;y++) if(grid[xa][y]=='*') jalan=false;
		if(!jalan) break;
	}
	
	for(xb=samping;xb>0;xb--)
	{
		jalan=true;
		for(y=1;y<=bawah;y++) if(grid[xb][y]=='*') jalan=false;
		if(!jalan) break;
	}
	
	for(ya=1;ya<=bawah;ya++)
	{
		jalan=true;
		for(x=1;x<=samping;x++) if(grid[x][ya]=='*') jalan=false;
		if(!jalan) break;
	}
	
	for(yb=bawah;yb>0;yb--)
	{
		jalan=true;
		for(x=1;x<=samping;x++) if(grid[x][yb]=='*') jalan=false;
		if(!jalan) break;
	}
	
	for(y=ya;y<=yb;y++)
		for(x=xa;x<=xb;x++)
		{
			printf("%c",grid[x][y]);
			if(x==xb) printf("\n");
		}
	return 0;
}

