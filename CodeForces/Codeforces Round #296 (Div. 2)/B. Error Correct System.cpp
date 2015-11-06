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


struct mys{
	char x;
	char y;
	int pos;
};

//struct classcomp {
//	bool operator() (const mys& a, const mys& b) const{
//		if (a.x != b.x) return a.x < b.x;
//		else if (a.y != b.y) return a.y < b.y;
//		else return a.pos < b.pos;
//	}
//};

void __main() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	map<pair<char, char>, int>  pos;
	map<char, int> posa, posb;
	//set<mys, classcomp > pos;
	int curham = 0;
	REP(i, n){
		if (a[i] != b[i])curham++;
	}
	REP(i, n){
		if (a[i] == b[i])continue;
		//mys temp; 
		//temp.a = a[i], temp.b = b[i]
		pair<int, int> tpair = make_pair(a[i], b[i]);
		if (pos.find(tpair) != pos.end()){
			cout << curham - 2 << endl;
			cout << i + 1 << " " << pos[tpair] + 1 << endl;
			return;
		}
		pos[make_pair(b[i], a[i])] = i;
	}

	REP(i, n){
		if (a[i] == b[i])continue;
		if (posa.find(a[i]) != posa.end()){
			cout << curham - 1 << endl;
			cout << i + 1 << " " << posa[a[i]] + 1 << endl;
			return;
		}
		if (posb.find(b[i]) != posb.end()){
			cout << curham - 1 << endl;
			cout << i + 1 << " " << posb[b[i]] + 1 << endl;
			return;
		}

		posa[b[i]] = i;
		posb[a[i]] = i;
	}

	cout << curham << endl;
	cout << -1<< " " << -1 << endl;
	return;
}

int main(){
#ifndef UNLINE_JUDGE
	FILE* fin = NULL;
	fin = fopen("in.txt", "w+");
	fprintf(fin, "9\npergament\npermanent\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #1 ...\n\tExpected: ");
	printf("1\n4 6\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "6\nwookie\ncookie\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #2 ...\n\tExpected: ");
	printf("1\n-1 -1\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "4\npetr\negor\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #3 ...\n\tExpected: ");
	printf("2\n1 2\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
	fin = fopen("in.txt", "w+");
	fprintf(fin, "6\ndouble\nbundle\n");
	fclose(fin);
	freopen("in.txt", "r", stdin);
	printf("Test Case #4 ...\n\tExpected: ");
	printf("2\n4 1\n");
	printf("\tReceived: ");
	__main();
	printf("\n");
#else
	__main();
#endif

	return 0;
}
