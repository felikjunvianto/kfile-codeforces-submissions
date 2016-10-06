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

char msk[300];
int x,y,z,len;
string ans;

int main()
{
	gets(msk);len=strlen(msk);
	x=-1;
	do
	{
		x++;
		if(msk[x]==' ') continue;
		
		if(msk[x]==',') 
		{
			ans+=','; 
			if(x+1!=len) ans+=' ';
		}
		
		else if(msk[x]=='.')
		{
			if((!ans.empty())&&(ans[ans.size()-1]!=' ')) ans+=' ';
			ans.append("...");
			x+=2;
		} 
		
		else
		{
			y=x;
			while((y<len)&&(msk[y]>='0')&&(msk[y]<='9')) y++;
			if((ans[ans.size()-1]>='0')&&(ans[ans.size()-1]<='9')) ans+=' ';
			while(x!=y) ans+=msk[x++];
			x--;
		}
	}while(x+1<len);
	printf("%s\n",ans.c_str());
	return 0;
}

