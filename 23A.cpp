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
int ans,len,x,a,b,temp;

int main()
{
	scanf("%s",msk);len=strlen(msk);
	for(ans=len-1;ans;ans--)
	{
		for(a=0;a+ans-1<len;a++)
		{
			temp=0;
			for(b=0;b+ans-1<len;b++)
			{
				bool sama=true;
				for(x=0;x<ans;x++) if(msk[a+x]!=msk[b+x]) sama=false;
				if(sama) temp++;
			}
			if(temp>1) break;
		}
		if(temp>1) break;
	}
	printf("%d\n",ans);
	return 0;
}

