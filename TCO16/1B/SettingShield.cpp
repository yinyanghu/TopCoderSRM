#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int maxN = 100100;
const int maxH = 100100;

int protection[maxN];

int Left[maxH], Right[maxH];
int maxR[maxN];

int N, H, T;

long long delta[maxN];

const long long INF = 1000000000000000000LL;

class SettingShield {
public:
	long long getOptimalCost(int, int, int, vector <int>, vector <int>, vector <int>, vector <int>);
};

long long f(int P) {
	long long ret = (long long)P * (long long)T;
	memset(delta, 0, sizeof(delta));
	int nextR = -1;
	long long cover = 0;
	for (int i = 0; i < N; ++ i) {
		nextR = max(nextR, maxR[i]);
		long long K = protection[i] - P - cover;
		if (K > 0) {
			if (nextR < i) return INF;
			cover += K; ret += K; delta[nextR] += K;
		}
		cover -= delta[i];
	}
	return ret;
}


long long SettingShield::getOptimalCost(int n, int h, int t, vector <int> val0, vector <int> a, vector <int> b, vector <int> m) {
	N = n; H = h; T = t;
	protection[0] = val0[0];
	for (int i = 1; i < N; ++ i)
		protection[i] = ((long long)a[0] * protection[i - 1] + b[0]) % m[0];
	Left[0] = val0[1];
	Right[0] = val0[2];
	for (int i = 1; i < H; ++ i) {
		Left[i] = min(N - 1LL, ((long long)a[1] * Left[i - 1] + b[1]) % m[1]);
		int dist = Right[i - 1] - Left[i - 1];
		Right[i] = min(N - 1LL, Left[i] + ((long long)a[2] * dist + b[2]) % m[2]);
	}

	memset(maxR, -1, sizeof(maxR));
	for (int i = 0; i < H; ++ i)
		maxR[Left[i]] = max(maxR[Left[i]], Right[i]);

	int L = 0;
	int R = 0;
	for (int i = 0; i < N; ++ i)
		R = max(R, protection[i]);
	long long ret = INF;

	while (L + 10 < R) {
		int midL = (L * 2 + R) / 3;
		int midR = (L + R * 2) / 3;
		long long p = f(midL);
		long long q = f(midR); 
		if (p < q) {
			R = midR;
			ret = min(ret, p);
		}
		else {
			L = midL;
			ret = min(ret, q);
		}
	}
	for (int i = L; i <= R; ++ i)
		ret = min(ret, f(i));

	return ret;
}
