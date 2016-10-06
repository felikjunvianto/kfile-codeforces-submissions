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
#define eps 1e-7
#define PII pair<int,int> 
#define PDD pair<double,double> 
#define LL long long
#define INF 1000000000

using namespace std;

int N,V,tot,x,y,z;
int a[110],b[110];

bool cek(double T)
{
	double ans=0;
	for(int i=1;i<=N;i++) 
	{
		if((double)a[i]*T>(double)b[i]) return(false);
		ans+=(double)a[i]*T;
	}
	if(ans>(double)V) return(false);
	return(true);
}

double binser()
{
	double pivot,l=0,r=V;
	while(fabs(l-r)>eps)
	{
		pivot=(l+r)/2;
		bool bisanow=cek(pivot),bisanext=cek(pivot+0.000001);
		
		if((bisanow)&&(!bisanext)) return(pivot); else
			if((bisanow)&&(bisanext)) l=pivot; else
				if(!bisanow) r=pivot;
	}
	return(r);
}

int main()
{
	scanf("%d %d",&N,&V);
	tot=0;
	for(x=1;x<=N;x++) 
	{
		scanf("%d",&a[x]);
		tot+=a[x];
	}
	for(x=1;x<=N;x++) scanf("%d",&b[x]);
	
	cout << (double)tot*binser() << endl;;
	return 0;
}

