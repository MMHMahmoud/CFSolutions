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

bool ispalin(ll in){
	stringstream ss;
	ss << in;
	string str = ss.str();
	REP(i, SZ(str) / 2){
		if (str[i] != str[SZ(str) - i - 1])return 0;
	}
	return 1;
}

const int MAXSTEPS = 1500000;

int tau[MAXSTEPS], rub[MAXSTEPS];
bool marked[MAXSTEPS];
bool isprime[MAXSTEPS];

void dosieve(int maxnum){
	fill(marked, marked + MAXSTEPS, 0);
	fill(isprime, isprime + MAXSTEPS, 0);
	REPs(i,2, sqrt(maxnum)+1){
		if (!marked[i]) isprime[i] = 1;
		int cur = i+i;
		while (cur < maxnum){
			marked[cur] = 1;
			cur += i;
		}
	}
	REPs(i, sqrt(maxnum) + 1, maxnum){
		if (!marked[i]) isprime[i] = 1;
	}
}

void __main() {
	int maxmax = -1;
	int p, q;
	cin >> p >> q;
	int cur = 1;
	int curtau=0, currub=0;
	dosieve(MAXSTEPS);
	//while (true){
	REPs(i,1, MAXSTEPS){
		if (ispalin(cur)) currub++;
		if (isprime[cur]) curtau++;
		rub[cur] = currub;
		tau[cur] = curtau;
		//if (42 * currub < curtau) break;
		if (p*currub >= q*curtau) maxmax = i;
		cur++;
	}
	if (maxmax == -1) cout << "Palindromic tree is better than splay tree";
	else cout << maxmax;
}

int main(){
#ifndef UNLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "1 1\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
	printf("40\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "1 42\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #2 ...\n\tExpected: ");
	printf("1\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "6 4\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #3 ...\n\tExpected: ");
	printf("172\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
#else
	__main();
#endif

	return 0;
}
