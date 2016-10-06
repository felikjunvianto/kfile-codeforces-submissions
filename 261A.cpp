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

int N, M, i;
int temp, disc;
int price[100010], total;

int main()
{
	scanf("%d\n",&N);
	
	disc = INF;
	while(N--)
	{
		scanf("%d",&temp);
		disc = min(temp,disc);
	}
	
	scanf("%d",&M);
	for(i=0;i<M;i++) scanf("%d",&price[i]);
	sort(price,price+M);
	
	total = 0;
	int cnt = 0;
	for(i = M - 1; i >= 0; i--)
	{
		total += price[i];
		cnt++;
		if(cnt == disc) 
		{
			i -= 2;
			cnt = 0;
		}
	}
	
	printf("%d\n",total);
	return 0;
}

