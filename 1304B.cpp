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

int N, len;
bool matched[111];
vector<string> word;
char inp[111];

bool couple(string i, string j) {
	for(int x = 0; x < len; x++) 
		if(i[x] != j[len - x - 1]) return false;
	return true;
}

bool isPalin(string i) {
	for(int x = 0; 2 * x < len; x++)
		if(i[x] != i[len - x - 1]) return false;
	return true;
}

int main() {
	scanf("%d %d", &N, &len);
	for(int i = 0; i < N; i++) {
		scanf("%s", inp);
		word.pb(inp);
	}

	string ans = "";
	int longestSelfIdx = -1;
	for(int i = 0; i < N; i++) if(isPalin(word[i]))
		if(longestSelfIdx == -1 || word[longestSelfIdx].size() < word[i].size())
			longestSelfIdx = i;

	memset(matched, false, sizeof(matched));
	if(longestSelfIdx != -1) {
		matched[longestSelfIdx] = true;
		ans = word[longestSelfIdx];
	}

	for(int i = 0; i < N; i++) if(!matched[i]) {
		for(int j = i + 1; j < N; j++) if(couple(word[i], word[j])) {
			matched[i] = matched[j] = true;
			ans = word[i] + ans + word[j];
			break;
		}
	}

	printf("%d\n%s\n", (int) ans.size(), ans.c_str());
	return 0;
}

