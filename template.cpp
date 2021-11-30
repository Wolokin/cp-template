#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define all(c) (c).begin(), (c).end()
#define loop(i, a, b) for(int i = a; (i) < (b); (i)++)
#define loopback(i, a, b) for(int i = a; (i) >= (b); (i)--)

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef unsigned int uint;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi > vvi;
typedef vector<pii> vpi;
const int INF = 1<<30, MOD = 1000000007, MAX = 200005;

int popcount(uint i) { return __builtin_popcount(i); }
template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T> inline void yesno(bool f, const T& y = "YES", const T& n = "NO") { cout << (f ? y : n) << "\n"; }

class Solve {
    int n;
public:
    Solve() {
        cin >> n;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) Solve();
    return 0;
}
