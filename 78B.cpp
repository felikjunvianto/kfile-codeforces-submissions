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

char col[]={'R','O','Y','G','B','I','V'};
int N,x,y,urut[110];

int main()
{
	scanf("%d",&N);
	y=0;
	for(x=1;x+3<=N;x++) 
	{
		urut[x]=y;
		y=(y+1)%4;
	}
	urut[N-2]=4;
	urut[N-1]=5;
	urut[N]=6;
	for(x=1;x<=N;x++) printf("%c",col[urut[x]]);
	printf("\n");
	return 0;
}

