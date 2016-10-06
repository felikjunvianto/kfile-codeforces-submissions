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

int N,x,y,z;
queue<int> q;
vector<int> num;

int main()
{
	q.push(1);
	while(!q.empty())
	{
		x=q.front();q.pop();
		num.pb(x);
		if((LL)x*10LL<=1000000000LL)
		{
			q.push(x*10);
			q.push(x*10+1);
		}
	}
	
	scanf("%d",&N);
	z=upper_bound(num.begin(),num.end(),N)-num.begin();
	printf("%d\n",z);
	return 0;
}

