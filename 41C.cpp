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

char msk[200];
string ans;
int x,y,z,len;
bool at;

int main()
{
	scanf("%s",msk);len=strlen(msk);
	at=false;
	for(x=0;x<len;x++)
	{
		if((x)&&(x+3<len)&&(msk[x]=='d')&&(msk[x+1]=='o')&&(msk[x+2]=='t'))
		{
			ans.pb('.');
			x+=2;
		} else
		
		if((x)&&(!at)&&(x+2<len)&&(msk[x]=='a')&&(msk[x+1]=='t'))
		{
			ans.pb('@');
			at=true;
			x++;
		} else ans.pb(msk[x]);
	}
	printf("%s\n",ans.c_str());
	return 0;
}

