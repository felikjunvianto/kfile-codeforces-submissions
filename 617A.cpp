#include <cstdio>
using namespace std;

int x;

int main() {
	scanf("%d", &x);
	printf("%d\n", (int)(x / 5) + (x % 5 > 0 ? 1 : 0));
	return 0;
}
