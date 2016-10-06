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

PII digit;
int N,x,y,z,temp;
vector<int> empat,tujuh;
string ans;

int main()
{
	scanf("%d",&N);
	for(x=0;4*x<=N;x++) empat.pb(4*x);
	for(x=0;7*x<=N;x++) tujuh.pb(7*x);
	ans.clear();
	digit=mp(INF,INF);
	
	for(x=0;x<empat.size();x++)
	{
		y=upper_bound(tujuh.begin(),tujuh.end(),N-empat[x])-tujuh.begin();y--;
		if(empat[x]+tujuh[y]==N)
			if((x+y<digit.fi+digit.se)||((x+y==digit.fi+digit.se)&&(x>digit.fi)))
				digit=mp(x,y);
	}

	if(digit!=mp(INF,INF))
	{
		for(z=0;z<digit.fi;z++) ans.append("4");
		for(z=0;z<digit.se;z++) ans.append("7");
	}
	
	if(!ans.size()) printf("-1\n"); else printf("%s\n",ans.c_str());
	return 0;
}

