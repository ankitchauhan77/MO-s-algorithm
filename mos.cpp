//https://codeforces.com/contest/617/problem/E
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define rsrt(v) sort(v.begin(), v.end(), greater<int>())
#define rsrtl(v) sort(v.begin(), v.end(), greater<ll>())
#define fi(i, a, b) for (int i = a; i < b; i++)
#define fll(i, a, b) for (ll i = a; i < b; i++)
#define srt(v) sort(v.begin(), v.end())
#define pb push_back
#define g(v, i, j) get<i>(v[j])
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(),(x).end()
#define ll long long
ll md = 1000000007;
#define theartofwar                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define F first
#define S second
#define sz(v) v.size()
using namespace std;
#define dbg(x) cerr << #x << " = " << x << endl;
template <typename T>
T pw(T a, T b){
    T c = 1, m = a;
    while (b){
        if (b & 1) c = (c * m);
        m = (m * m), b /= 2;
    }
    return c;
}
template <typename T>
T ceel(T a, T b){
    if (a % b == 0)
        return a / b;
    else
        return a / b + 1;
}
template <typename T>
T my_log(T n, T b){
    T i = 1, ans = 0;
    while (1){
        if (i > n){
            ans--;
            break;
        }
        if (i == n) break;
        i *= b, ans++;
    }
    return ans;
}
template <typename T>
T gcd(T a, T b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll pwmd(ll a, ll b){
    ll c = 1, m = a;
    while (b){
        if (b & 1) c = (c * m) % md;
        m = (m * m) % md;
        b /= 2;
    }
    return c;
}
ll modinv(ll n){
    return pwmd(n, md - 2);
}
ll inverse(ll i){
    if (i == 1)
        return 1;
    return (md - ((md / i) * inverse(md % i)) % md + md) % md;
}
bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b){
    return (a.second < b.second);
}
ll BLOCK_SIZE = 500;
vll v, cnt(1000001);
bool cmp(pair<ll, ll> p, pair<ll, ll> q) {
    if (p.first / BLOCK_SIZE != q.first / BLOCK_SIZE)
        return p < q;
    return (p.first / BLOCK_SIZE & 1) ? (p.second < q.second) : (p.second > q.second);
}
ll ans = 0;
void add(ll x){
    ans -= cnt[v[x]] * cnt[v[x]] * v[x];
    cnt[v[x]]++;
    ans += cnt[v[x]] * cnt[v[x]] * v[x];
}
void remove(ll x){
    ans -= cnt[v[x]] * cnt[v[x]] * v[x];
    cnt[v[x]]--;
    ans += cnt[v[x]] * cnt[v[x]] * v[x];
}
int main()
{
    theartofwar;
    ll n, t, a, l, r;
    cin >> n >> t;
    ll e = t;
    vector<pll> vp, temp;
    map<pll, ll> w;
    fll(i, 0, n) cin >> a, v.pb(a);
    while (t--) cin >> l >> r, vp.pb({l - 1, r - 1}), temp.pb({l - 1, r - 1});
    sort(all(vp), cmp);
    l = 0, r = 0;
    ans += v[0], cnt[v[0]]++;
    fll(i, 0, e){
        ll L = vp[i].F, R = vp[i].S;
        while (l < L) remove(l), l++;
        while (l > L) l--, add(l);
        while (r > R) remove(r), r--;
        while (r < R) r++, add(r);
        w[{L, R}] = ans;
    }
    fll(i, 0, e) cout << w[temp[i]] << "\n";
}


