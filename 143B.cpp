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
int len,x,y,z,awal;
string temp,decim,frac,ans;
bool negatif;

int main()
{
	scanf("%s",msk);temp=msk;
	for(x=0;x<temp.size();x++) if(temp[x]=='.') break;
	if(x==(int)temp.size()) temp+='.';
	
	negatif=false;
	awal=0;
	if(temp[0]=='-') awal=negatif=1;
	for(y=awal;y<x;y++) decim+=temp[y];
	for(y=x+1;y<temp.size();y++) 
	{
		frac+=temp[y];
		if(frac.size()==2) break;
	}
	while(frac.size()<2) frac+='0';
	
	temp.clear();
	int cnt=0;
	for(y=decim.size()-1;y>=0;y--)
	{
		cnt++;
		temp=decim[y]+temp;
		if(cnt==3)
		{
			if(!y) continue;
			temp=','+temp;
			cnt=0;
		}
	}
	
	ans='$'+temp+'.'+frac;
	if(negatif) ans='('+ans+')';
	printf("%s\n",ans.c_str());
	return 0;
}

