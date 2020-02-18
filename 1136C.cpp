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
#include <set>

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

int R, C, temp;
vector<int> NN[1010], MM[1010];

int main() {
	scanf("%d %d", &R, &C);

	for(int r = 0; r < R; r++)
		for(int c = 0; c < C; c++) {
			scanf("%d", &temp);
			NN[r + c].pb(temp);
		}

	for(int r = 0; r < R; r++)
		for(int c = 0; c < C; c++) {
			scanf("%d", &temp);
			MM[r + c].pb(temp);
		}

	int BTS = R + C - 2;
	bool bisa = true;
	for(int b = 0; b <= BTS && bisa; b++) {
		if(NN[b].size() > 0) sort(NN[b].begin(), NN[b].end());
		if(MM[b].size() > 0) sort(MM[b].begin(), MM[b].end());

		for(int c = 0; c < NN[b].size() && bisa; c++) bisa = NN[b][c] == MM[b][c];
	}

	printf("%s\n", bisa ? "YES" : "NO");

	return 0;
}

