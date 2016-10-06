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

map<string,int> idx;
char msk[40];
int N;

int main()
{
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",msk);
		if(idx.find(msk)==idx.end())
		{
			printf("OK\n");
			idx[msk]=0;
		} else printf("%s%d\n",msk,++idx[msk]);
	}
	return 0;
}

