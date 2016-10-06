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

const int HEAD = 0;
const int TAIL = 1000005;

typedef struct
{
	int val, prev, next;
} node;

char pos[1000010];
node linked[1000010];
int len;

int main()
{
	scanf("%s",pos); len = strlen(pos);
	linked[HEAD] = (node) {-1,-1, TAIL};
	linked[TAIL] = (node) {-1, HEAD,-1};
	
	int cursor = HEAD;
	for(int i = 0; i < len; i++)
	{
		linked[i+1] = (node) {i + 1, cursor, linked[cursor].next};
		linked[linked[cursor].next].prev = i + 1;
		linked[cursor].next = i + 1;
		if(pos[i] == 'r') cursor = linked[cursor].next;
	}
	
	int pointer = HEAD;
	for(int i = 0; i < len; i++)
	{
		pointer = linked[pointer].next;
		printf("%d\n",linked[pointer].val);
	}
	return 0;
}

