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

int fri[7][7];
int N,x,y,z;
bool oke;

int main()
{
	scanf("%d",&N);
	memset(fri,0,sizeof(fri));
	while(N--)
	{
		scanf("%d %d",&x,&y);
		fri[x][y]=fri[y][x]=1;
	}
	
	oke=false;
	for(x=1;x<=5;x++)
		for(y=x+1;y<=5;y++)
			for(z=y+1;z<=5;z++)
			{
				N=fri[x][y]+fri[y][z]+fri[x][z];
				if((N==0)||(N==3)) oke=true;
			}
			
	printf("%s\n",oke?"WIN":"FAIL");
	return 0;
}

