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

using namespace std;

int N,x,y,z,ans,win;
vector<string> tim;
char msk[20];

int main()
{
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",msk);
		tim.pb(msk);
	}
	sort(tim.begin(),tim.end());
	
	ans=win=0;
	x=-1;
	do
	{
		x++;y=x;
		while((y<tim.size())&&(tim[x]==tim[y])) y++;y--;
		if(ans<y-x+1)
		{
			ans=y-x+1;
			win=x;
		}
		x=y;
	}while(x+1<(int)tim.size());
	printf("%s\n",tim[win].c_str());
	return 0;
}

