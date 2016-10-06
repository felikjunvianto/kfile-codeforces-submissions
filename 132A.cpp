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

char msk[111];
int x,y,len,prev,now,mod=256;

string ubah(int x)
{
	string ans = "";
	int temp = x;
	while(temp)
	{
		string c;
		c+=(temp%2+'0');
		ans.append(c);
		temp/=2;
	}
	while(ans.size()<8) ans.append("0");
	reverse(ans.begin(),ans.end());
	return(ans);
}

int main()
{
	gets(msk);len=strlen(msk);
	prev=0;
	for(x=0;x<len;x++)
	{
		int now = msk[x];
		string biner = ubah(now);
		reverse(biner.begin(),biner.end());
		now = 0;
		for(y=0;y<8;y++) now=now*2+(biner[y]-'0');
		
		int cetak = (prev-now)%mod;
		while(cetak<0) cetak+=mod;
		printf("%d\n",cetak);
		prev = now;
	}
	return 0;
}

