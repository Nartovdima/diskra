#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <iterator>
#include <bitset>
#include <fstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")*/


#define eb emplace_back
#define pb push_back
#define int long long
#define ld long double
#define f first
#define s second
#define dimas_pidoras false
#define buhlich_botaet false
#define deb(a) cerr << #a << " = " << a << '\n';
#define fast() { \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); \
    cout << fixed << setprecision(10); \
    cerr << fixed << setprecision(10); \
}
const int INF = 1e18 + 7;
const ld EPS = 1e-8;
const int MAXI = 20000;
const int MOD = 16714589;
const int MAXST = 2000000;
const int P = 40;
const ld PI = 3.14159265358979323;
const int MAXN = 2 * 1e5;

set <string> st;
int y = 0;

struct dic{
	string rash;
	string g;
	int pos;
};

dic d[MAXN];

void push(string h){
	for(int i = 1; i < y; i++){
		size_t v = h.find(d[i].g);
		if (v != string::npos){
			d[y].rash = h.substr(*--h.end(), 1);
			d[y].g = h;
			d[y].pos = i;
		}
	}
	y++;
}

signed main()
{
    fast();
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	cout << s << '\n';

	d[0].g = string::npos;
	d[0].pos = 0;
	d[0].rash = string::npos;
	y++;
	int n = s.size(), m = 0;
	int l = 0, r = 0;
	for(int i = 0; r < n; i++){
		m = st.size();
		string h = s.substr(l, r - l + 1);
		//cout << h << '\n';
		st.insert(h);
		if (st.size() > m){
			push(h);
			l = r;
		}
		else
			r++;

	}
	for(int i = 0; i < y; i++){
        cout << '(' << d[i].pos << ', ' << d[i].rash << ')' << ' ';
	}
	/*for(auto it: st)
		cout << it << '\n';*/
   	return 0;
}
