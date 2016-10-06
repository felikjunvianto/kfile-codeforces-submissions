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

vector<int> idx[30];
char msk[1111];
int len;

int main()
{
	scanf("%s", msk); len = strlen(msk);
	for(int i = 0; i < len; i++) idx[msk[i]-'A'].pb(i);
		
	int ans = 0;
	for(int i = 0; i < 26; i++)
		for(int j = 0; j < idx[i].size(); j++)
		{
			int now = idx[i][j], cnt = 1;
			for(int k = j + 1; k < idx[i].size(); k++)
				if((idx[i][k] - now) & 1)
				{
					//cout << "now " << idx[i][j] << " ----> " << idx[i][k] << endl;
					now = idx[i][k];
					cnt++;
				}
			//cout << cnt << " " << i << " " << j << endl;
			ans = max(cnt, ans);
		}
		
	printf("%d\n", ans);
	return 0;
}

