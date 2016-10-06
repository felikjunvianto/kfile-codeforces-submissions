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

char rel[100100],a[2][200];
int N,len[2],x,y,z,tot;
bool bisa[2],oke;

int main()
{
	scanf("%s",rel);N=strlen(rel);
	scanf("%s",a[0]);len[0]=strlen(a[0]);
	scanf("%s",a[1]);len[1]=strlen(a[1]);
	
	memset(bisa,false,sizeof(bisa));
	for(int i=0;i<2;i++)
	{
		z=0;
		for(x=0;x<N;x++) if((rel[x]==a[z][0])&&(x+len[z]-1<N))
		{
			oke=true;
			for(y=0;y<len[z];y++) if(rel[x+y]!=a[z][y])
			{
				oke=false;
				break;
			}
		
			if(oke)
			{
				x+=(len[z]-1);
				z++;
				if(z==2) break;
			}
		}
		
		if(z==2) bisa[i]=true;
		if(!i) reverse(rel,rel+N);
	}
	
	if((bisa[0])&&(bisa[1])) printf("both\n"); else
	if(bisa[0]) printf("forward\n"); else
	if(bisa[1]) printf("backward\n"); else
	printf("fantasy\n");
	return 0;
}

