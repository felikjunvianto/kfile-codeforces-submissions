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

int T;
char inp[555];
bool oke[30];

int main() {
	scanf("%d", &T);
	
	while(T--) {
		scanf("%s", inp);
		memset(oke, false, sizeof(oke));

		for(int i = 0, len = strlen(inp); i < len; i++) {
			if(i < len && i + 1 < len && inp[i] == inp[i + 1]) {
				i++;
			} else {
				char c = inp[i];
				oke[c - 'a'] = true;
			}
		}

		for(int i = 0; i < 26; i++) if(oke[i]) printf("%c", 'a' + i);
		printf("\n");
	}
	return 0;
}
