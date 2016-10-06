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

int bawah,samping,x,y,z;
char flag[111][111];
bool oke;

int main()
{
	scanf("%d %d",&bawah,&samping);
	for(x=0;x<bawah;x++) scanf("%s",flag[x]);
	oke=true;
	for(x=0;x<bawah;x++) if(!oke) break; else
		for(y=1;y<samping;y++) if(flag[x][y]!=flag[x][0]) oke=false;
		
	if(oke) for(x=1;x+1<bawah;x++) 
		if((flag[x][0]==flag[x-1][0])||(flag[x][0]==flag[x+1][0])) oke=false;
	
	printf("%s\n",oke?"YES":"NO");
	return 0;
}

