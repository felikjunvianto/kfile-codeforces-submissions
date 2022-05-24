#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
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
#define pii pair<int,int> 
#define pdd pair<double,double>
#define LL long long

#define PI 2*acos(0.0)
#define EPS 1e-9
#define INF 1e9

using namespace std;

struct state {
	string num;
	int opcnt;

	state(string num) : num(num), opcnt(0) {};
	state(string num, int opcnt) : num(num), opcnt(opcnt) {};
};

int N;
char x[30];
queue<state> Q;
set<string> visited;
bool exist[10];

bool isHope(string &toCheck) {
	memset(exist, false, sizeof(exist));
	for(char &c : toCheck) exist[c - '0'] = true;

	bool oke = false;
	for(int i = 2; i < 10 && !oke; i++) if(exist[i]) oke = true;
	return oke;
}

int main()
{
	scanf("%d %s", &N, x);

	string init = x;
	reverse(init.begin(), init.end());

	if(!isHope(init)) {
		printf("-1\n");
		return 0;
	}

	visited.insert(init);
	Q.push(state(init, 0));

	int ans = -1;
	while(!Q.empty()) {
		state now = Q.front(); Q.pop();
		string &num = now.num;

		if(num.length() == N) {
			ans = now.opcnt;
			break;
		}

		if(!isHope(num)) continue;
		for(int i = 2; i < 10; i++) if(exist[i]) {
			int temp[30];
			int carry = 0;

			for(int j = 0; j < num.length(); j++) {
				temp[j] = (num[j] - '0') * i + carry;
				carry = temp[j] / 10;
				temp[j] %= 10;
			}

			int end = num.length() - 1;
			while(carry > 0) {
				temp[++end] = carry % 10;
				carry /= 10;
			}

			string next = "";
			for(int j = 0; j <= end; j++) next += (char)(temp[j] + '0');

			if(visited.find(next) == visited.end()) {
				visited.insert(next);
				Q.push(state(next, now.opcnt + 1));
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}

