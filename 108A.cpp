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

int x,y,z,H,M,bts=1440;
bool palin[1500];

int main()
{
	memset(palin,false,sizeof(palin));
	for(x=0;x<bts;x++)
	{
		H=x/60;
		M=x%60;
		if((H/10==M%10)&&(H%10==M/10)) palin[x]=true;
	}
	
	scanf("%d:%d",&H,&M);
	z=H*60+M;
	
	while(1)
	{
		z=(z+1)%bts;
		if(palin[z]) break;
	}
	
	printf("%02d:%02d\n",z/60,z%60);
	return 0;
}

