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

int A,B,N,x;

int cek(int T)
{
	int i,ret=1;
	for(i=0;i<N;i++) ret*=T;
	return(ret);
}

int main()
{
	scanf("%d %d %d",&A,&B,&N);
	if((!A)&&(!B)) printf("0\n"); else
		if((!A)||(B%A)) printf("No solution\n"); else
		{
			B/=A;
			x=0;
			while(cek(x)<B) x++;
			while(cek(x)>B) x--;
			if(cek(x)==B) printf("%d\n",x); else printf("No solution\n");
		}
	return 0;
}

