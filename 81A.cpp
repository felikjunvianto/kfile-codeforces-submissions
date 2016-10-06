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

string ans;
char msk[200100];
int x,y,z,len;
stack<char> s;

int main()
{
	scanf("%s",msk);len=strlen(msk);
	for(x=0;x<len;x++) if((s.empty())||(s.top()!=msk[x])) s.push(msk[x]); else s.pop();
	while(!s.empty())
	{
		ans+=s.top();
		s.pop();
	}
	
	reverse(ans.begin(),ans.end());
	printf("%s\n",ans.c_str());
	return 0;
}

