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

int K,ans,temp,x,y;
int cm[15];

int main()
{
	scanf("%d",&K);
	for(x=0;x<12;x++) scanf("%d",&cm[x]);
	sort(cm,cm+12);
	
	ans = temp = 0;
	x = 11;
	while(temp<K && x>=0) 
	{
		temp += cm[x--];
		ans++;
	}
	
	printf("%d\n",temp<K?-1:ans);
	return 0;
}

