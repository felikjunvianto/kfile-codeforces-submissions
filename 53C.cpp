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

int N,x,maju,mundur;

int main()
{
	scanf("%d",&N);
	maju=1,mundur=N;
	for(x=1;x<=N;x++) if(x&1) printf("%d%c",maju++,x==N?'\n':' ');
		else printf("%d%c",mundur--,x==N?'\n':' ');
	return 0;
}

