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

string ans[5]={"byte","short","int","long","BigInteger"};
vector<string> bil;
char msk[200];
int x,y,z;

bool cf(string a,string b)
{
	if(a.size()!=b.size()) return(a.size()<b.size());
	return(a<b);
}

int main()
{
	scanf("%s",msk);
	
	bil.pb("127");
	bil.pb("32767");
	bil.pb("2147483647");
	bil.pb("9223372036854775807");
	
	bil.pb(msk);
	sort(bil.begin(),bil.end(),cf);
	
	for(x=0;x<bil.size();x++) if(!strcmp(msk,bil[x].c_str())) break;
	printf("%s\n",ans[x].c_str());
	return 0;
}

