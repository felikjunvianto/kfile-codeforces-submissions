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

map<string,bool> idx;
string nama;
char msk[200];
int ans,x,y,len;

int main()
{
	ans=0;
	while(gets(msk)) switch(msk[0])
	{
		case('+') : len=strlen(msk);
					nama.clear();
					for(x=1;x<len;x++) nama+=msk[x];
					idx[nama]=true;
					break;
					
		case('-') : len=strlen(msk);
					nama.clear();
					for(x=1;x<len;x++) nama+=msk[x];
					idx.erase(nama);
					break;
					
		default : nama=msk;
				  x=nama.find(':');
				  y=(int)nama.size()-x-1;
				  ans+=y*(int)idx.size();
	}
	printf("%d\n",ans);
	return 0;
}

