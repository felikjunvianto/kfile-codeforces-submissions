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

int x,y;

int main()
{
	scanf("%d %d",&x,&y);
	if((!x)||(!y)) printf("black\n"); else
	{
		double R=sqrt(x*x+y*y);
		int Rf=(int) floor(R);
		if(x*y>0)
		{
			if((Rf&1)&&(R-(double)Rf>eps)) printf("white\n");
				else printf("black\n");
		} 
		
		else
		{
			if((Rf%2==0)&&(R-(double)Rf>eps)) printf("white\n");
				else printf("black\n");
		}
	}
	return 0;
}

