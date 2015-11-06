#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <fstream>

using namespace std;
//#define rep(i,f,t) for(int i = (f),end_##i = (t); i < end_##i; ++i)
#define REP(i,n) for(int i=0; i<n; i++)
#define REPs(i,x,n) for(int i=x; i<n; i++)
#define SZ(x) x.size()
#define VVII vector< vector< pair<int, int> > > 
#define mem(f, a) memset(f, a, sizeof(f))
#define all(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define epsil 1e-9
#define infinit  1e8
#define ll long long
#define PI pair<int, int>
#define X first
#define Y second

#ifndef _WIN64
	#define UNLINE_JUDGE
#endif



void __main() {
	int n;
	cin >> n;
	ll ans = 1;
	const ll MOD = 1e9 + 7;
	ll numvals = 1;
	REP(i, n){
		ans = (ans*7)%MOD;
		numvals = (numvals * 27) % MOD;
	}
	ans = (numvals - ans) % MOD;
	if (ans < 0) ans+=MOD;
	cout<<ans;
}

int main(){
#ifndef UNLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "10\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
	printf("20");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "2\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #2 ...\n\tExpected: ");
	printf("680");
	printf("\tReceived: ");
	__main();
	printf("\n");
#else
	__main();
#endif

	return 0;
}
