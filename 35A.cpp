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

int sta[5];
int x,a,b;

int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	sta[1]=sta[2]=sta[3]=0;
	scanf("%d",&x);sta[x]=1;
	for(x=0;x<3;x++)
	{
		scanf("%d %d",&a,&b);
		swap(sta[a],sta[b]);
	}
	for(x=1;x<=3;x++) if(sta[x]) break;
	printf("%d\n",x);
	return 0;
}

