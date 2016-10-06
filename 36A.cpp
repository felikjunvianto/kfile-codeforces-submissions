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

int N,x,beda;
vector<int> sig;
char msk[111];
bool oke;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d",&N);
	scanf("%s",msk);
	for(x=0;x<N;x++) if(msk[x]=='1') sig.pb(x);
	
	beda=sig[1]-sig[0];
	oke=true;
	for(x=2;x<sig.size();x++) if(sig[x]-sig[x-1]!=beda) oke=false;
	printf("%s\n",oke?"YES":"NO");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

