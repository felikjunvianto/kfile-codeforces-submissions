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

const int SIZE = 100005;

int N, i;
LL arr[SIZE],sorted[SIZE], H;


int main()
{
	scanf("%d %I64d",&N,&H);
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
		sorted[i] = arr[i];
	} sort(sorted,sorted+N);
	
	//if all in one set
	LL maxOne = sorted[N-1] + sorted[N-2];
	LL minOne = sorted[0] + sorted[1];
	
	//if divide into {a1} and {a2,a3,a4,...,aN}
	LL maxTwo = max(maxOne, sorted[0] + sorted[N-1] + H);
	LL minTwo = minOne + H;
	if(N >= 3) minTwo = min(minTwo, sorted[1] + sorted[2]);
	
	if(maxOne - minOne <= maxTwo - minTwo) 
	{
		printf("%I64d\n",maxOne - minOne);
		for(i=0;i<N;i++) printf("1%c",i==N-1?'\n':' ');
	}
	else
	{
		printf("%I64d\n",maxTwo - minTwo);
		
		bool placed = false;
		for(i=0;i<N;i++)
		{
			if(arr[i] == sorted[0] && !placed)
			{
				printf("2");
				placed = true;
			} else printf("1");
			if(i==N-1) printf("\n"); else printf(" ");
		}
	}
	return 0;
}

