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

char msk[20],ans[20];
int x,y,z,len;

int main()
{
	scanf("%s",msk);len=strlen(msk);
	sort(msk,msk+len);
	if((len>1)&&(msk[0]=='0'))
	{
		for(x=1;x<len;x++) if(msk[x]!='0') break;
		swap(msk[0],msk[x]);
	}
	
	scanf("%s",ans);
	printf("%s\n",strcmp(msk,ans)==0?"OK":"WRONG_ANSWER");
	return 0;
}

