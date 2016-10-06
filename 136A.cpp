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

int N,x,y,arr[111];

int main()
{
	scanf("%d",&N);
	for(x=1;x<=N;x++)
	{
		scanf("%d",&y);
		arr[y]=x;
	}
	for(x=1;x<=N;x++) printf("%d%c",arr[x],x==N?'\n':' ');
	return 0;
}

