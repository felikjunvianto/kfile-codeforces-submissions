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

int N,arr[1111],x,a,b;

int main()
{
	scanf("%d",&N);
	for(x=1;x<=N;x++) scanf("%d",&arr[x]);
	
	for(a=1;a<=N;a++) if(arr[a]!=a) break;
	for(b=N;b;b--) if(arr[b]!=b) break;
	for(x=a;2*(x-a)<b-a+1;x++) swap(arr[b-x+a],arr[x]);
	
	bool oke=true;
	for(x=1;x<=N;x++) if(arr[x]!=x) oke=false;
	if((!oke)||(a>b)) a=b=0;
	printf("%d %d\n",a,b);
	return 0;
}

