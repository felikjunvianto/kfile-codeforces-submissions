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

int x,y,z;
char c;
bool oke,tekan[15];

int main()
{
	memset(tekan,false,sizeof(tekan));
	z=0;
	for(y=1;y<=3;y++)
		for(x=1;x<=3;x++)
		{
			z++;
			scanf("%c",&c);
			if(c=='X') tekan[z]=true;
			if(x==3) getchar();
		}
		
	oke=true;
	for(x=1;x<10;x++) if((tekan[x])&&(!tekan[10-x])) oke=false;
	printf("%s\n",oke?"YES":"NO");
	return 0;
}

