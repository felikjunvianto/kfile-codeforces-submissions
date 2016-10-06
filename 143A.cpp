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

int r1,r2,c1,c2,d1,d2;
int a,b,c,d;
bool ada;

int main()
{
	scanf("%d %d",&r1,&r2);
	scanf("%d %d",&c1,&c2);
	scanf("%d %d",&d1,&d2);
	
	ada=false;
	for(a=1;a<10;a++) for(b=1;b<10;b++) 
		for(c=1;c<10;c++) for(d=1;d<10;d++)
		{
			if(ada) continue;
			if((a!=b)&&(a!=c)&&(a!=d)&&(b!=c)&&(b!=d)&&(c!=d))
			
			if((a+b==r1)&&(a+c==c1)&&(a+d==d1)&&(b+c==d2)&&(b+d==c2)&&(c+d==r2))
			{
				printf("%d %d\n",a,b);
				printf("%d %d\n",c,d);
				ada=true;
			}
		}
	
	if(!ada) printf("-1\n");
	return 0;
}

