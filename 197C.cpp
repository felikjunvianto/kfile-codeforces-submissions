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

char msk[100010],largest[40],ans[100010];
int cnt[30];
string sorted;
int msklen,largestlen,anslen,x,y,z;

int main()
{
	scanf("%s",msk);msklen=strlen(msk);
	sorted = msk;
	sort(sorted.begin(),sorted.end());
	memset(cnt,0,sizeof(cnt));
	
	largestlen = 0;
	for(x=0;x<sorted.size();x++)
	{
		cnt[sorted[x]-'a']++;
		if(x==0 || sorted[x]!=sorted[x-1]) largest[largestlen++] = sorted[x];
	}
	
	reverse(largest,largest+largestlen);
	z = anslen = 0;
	for(x=0;x<msklen;x++) 
	{
		if(msk[x]==largest[z]) ans[anslen++] = msk[x];
		cnt[msk[x]-'a']--;
		while(z<largestlen && cnt[largest[z]-'a']==0) z++;
	}
	
	ans[anslen] = '\0';
	printf("%s\n",ans);
	return 0;
}

