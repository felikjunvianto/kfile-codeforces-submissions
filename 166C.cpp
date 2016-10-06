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

int arr[555];
int N,K,x,ans;
bool found;

int main()
{
	scanf("%d %d",&N,&K);
	for(x=1;x<=N;x++) scanf("%d",&arr[x]);
	ans=0;
	
	found=false;
	for(x=1;x<=N;x++) if(arr[x]==K)
	{
		found=true;
		break;
	}
	
	if(!found) {
		N++;
		ans++;
		arr[N]=K;
	}
	
	sort(arr+1,arr+N+1);
	int left = 1;
	int right = N;
	
	while(arr[(left+right)/2]<K)
	{
		right++;
		ans++;
	}
	
	while(arr[(left+right)/2]>K)
	{
		left--;
		ans++;
	}
	
	printf("%d\n",ans);
	return 0;
}

