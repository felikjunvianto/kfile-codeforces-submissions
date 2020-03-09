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

int T, N, K;
char inp[2000];
vector<int> number[40];
bool used[100];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d\n", &N, &K);
		for(int i = 0; i < N; i++) {
			number[i].clear();
			scanf("%s", inp);
			for(int j = 0, len = strlen(inp); j < len; j++) number[i].pb(inp[j] - '0');
		}

		memset(used, false, sizeof(used));
		bool bisa = true;
		for(int i = 0; i < N && bisa; i++) {
			int loop = 0;

			while(number[i].size() != 1 || number[i][0] != 0) {
				int num = 0;
				vector<int> res;
				for(int j = 0; j < number[i].size(); j++) {
					num = num * 10 + number[i][j];
					res.pb((int) num / K);
					num %= K;
				}

				if(num > 1) {
					bisa = false;
					break;
				} else if(num == 1) {
					if(used[loop]) {
						bisa = false;
						break;
					}
					used[loop] = true;
				}
				loop++;

				int startIdx = 0;
				while(startIdx < res.size() && res[startIdx] == 0) startIdx++;

				number[i].clear();
				for(int j = startIdx; j < res.size(); j++) number[i].pb(res[j]);
				if(startIdx == res.size()) number[i].pb(0);
			}
		}

		printf("%s\n", bisa ? "YES" : "NO");
	}
	return 0;
}

