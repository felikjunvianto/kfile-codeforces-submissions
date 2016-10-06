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

int jam,menit;
char dummy;

int main()
{
	scanf("%d%c%d",&jam,&dummy,&menit);jam%=12;
	cout << (double) (jam*30.00 + menit/2.00) << " " << menit*6 << endl;
	return 0;
}

