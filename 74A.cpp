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

int N,win,temp,suc,fail,a,b,c,d,e;
char msk[50];
string ans;

int main()
{
	scanf("%d",&N);win=-INF;
	while(N--)
	{
		scanf("%s %d %d %d %d %d %d %d",msk,&suc,&fail,&a,&b,&c,&d,&e);
		temp=suc*100-fail*50+a+b+c+d+e;
		if(win<temp)
		{
			ans=msk;
			win=temp;
		}
	}
	printf("%s\n",ans.c_str());
	return 0;
}

