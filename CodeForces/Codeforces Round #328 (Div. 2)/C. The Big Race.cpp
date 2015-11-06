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

ll gcd(ll n, ll m)
{
	ll gcd, remainder;

	while (n != 0)
	{
		remainder = m % n;
		m = n;
		n = remainder;
	}

	gcd = m;

	return gcd;
}

ll lcm(ll a, ll b)
{
	ll temp = gcd(a, b);

	return temp ? (a / temp * b) : 0;
}

void __main() {
	ll t, p, q;
	cin >> t >> p >> q;
	ll comm = lcm(p, q);	
	ll notcovered = max(t - ((t / p) + (t / q) - (t/comm)), 0LL);
	ll notreacheable = (min(p,q))*(t / comm);
	
	ll nom, denom;
	nom = notreacheable + (min(p, q)-1);
	denom = t;
	ll cgcd = gcd(nom, denom);
	nom = nom / cgcd, denom = denom / cgcd;
	cout << nom << "/" << denom << endl;

}

int main(){
#ifndef UNLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "3000000000000000000  2999999999999999873  2999999999999999977\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
	printf("3/10\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "7 1 2\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #2 ...\n\tExpected: ");
	printf("3/7\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
#else
	__main();
#endif

	return 0;
}
