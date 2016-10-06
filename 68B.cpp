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

int N,K,x,power[10010];

bool cek(double T)
{
	int i;
	double temp,tampung=0;
	for(i=0;i<N;i++) if((double)power[i]>T)
	{
		temp=(double)power[i]-T;
		tampung+=temp*(double)(100-K)/100.00;
	}
	
	for(i=0;i<N;i++) if((double)power[i]<T)
	{
		temp=T-(double)power[i];
		if(tampung<temp) return(false);
		tampung-=temp;
	}
	return(true);
}

double binser()
{
	double pivot,l=0.00,r=1000.00;
	while(fabs(l-r)>eps)
	{
		pivot=(l+r)/2.00;
		bool bisanow=cek(pivot),bisanext=cek(pivot+0.00000001);
		if((bisanow)&&(!bisanext)) return(pivot); else
			if((bisanow)&&(bisanext)) l=pivot; else
				if(!bisanow) r=pivot;
	}
	return(r);
}

int main()
{
	scanf("%d %d",&N,&K);
	for(x=0;x<N;x++) scanf("%d",&power[x]);
	
	printf("%.8lf\n",binser());
	return 0;
}

