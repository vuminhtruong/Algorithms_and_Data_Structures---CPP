#include <algorithm>
#include <complex>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>

using namespace std;
/*
namespace DEBUG {
    void __print(int x) {cerr << x;}
    void __print(long x) {cerr << x;}
    void __print(long long x) {cerr << x;}
    void __print(unsigned x) {cerr << x;}
    void __print(unsigned long x) {cerr << x;}
    void __print(unsigned long long x) {cerr << x;}
    void __print(float x) {cerr << x;}
    void __print(double x) {cerr << x;}
    void __print(long double x) {cerr << x;}
    void __print(char x) {cerr << '\'' << x << '\'';}
    void __print(const char *x) {cerr << '\"' << x << '\"';}
    void __print(const string &x) {cerr << '\"' << x << '\"';}
    void __print(bool x) {cerr << (x ? "true" : "false");}

    template<typename T, typename V>
    void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
    template<typename T>
    void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
    void _print() {cerr << "]\n";}
    template <typename T, typename... V>
    void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rand __rand
    mt19937 generator(chrono::system_clock::now().time_since_epoch().count());
    template <class T = int>
    T rand(T range = numeric_limits <T> :: max()){
        return (T) (generator() % range);
    }
}
using namespace DEBUG;
*/

template <class T,class U>
void maximize(T &lhs,U rhs){
    if(lhs < rhs)lhs = rhs;
}
template <class T,class U>
void minimize(T &lhs,U rhs){
    if(lhs > rhs)lhs = rhs;
}
template <class T>
T tabs(T x){
    return (x < (T)0 ? -x : x);
}

#define len(c) (int)((c).size())
#define llong int64_t
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define file_name "test"    /// FILE NAME HERE!!!

/* ================================= END OF TEMPLATE ================================= */

namespace Task{

    class Solver{
        public:

            int n,k;
            vector < int > a;
            bool ok = true;
            bool f = false;
            
            void Qsort(int l,int r){
                int mid = r;
                int x = a[mid];
                int i = l;
                int j = r;
                do{
                    while(a[i] < x){
                        i += k;
                    }
                    while(x < a[j]){
                        j -= k;
                    }
                    if(i <= j){
                        swap(a[i],a[j]);
                        i += k;
                        j -= k;
                    }
                } while(i <= j);
                if(l < j){
                    Qsort(l,j);
                } else if(f && (a[l - 1] > a[l] || (l + k - 1 <= n && a[l + k - 1] < a[l]))){
                    ok = false;
                }
                if(i < r){
                    Qsort(i,r);
                } else if(f && (a[r - 1] > a[r] || (r + k - 1 <= n && a[r + k - 1] < a[r]))){
                    ok = false;
                }
                return;
            }
            
            void solve(){
                cin>>n>>k;
                a.resize(n + 2,0);
                for(int i = 1;i <= n;++i){
                    cin>>a[i];
                }
                for(int i = 1;i <= k;++i){
                    int t = (n - i) / k;
                    if(i + k * t > n){
                        --t;
                    }
                    Qsort(i,i + k * t);
                    if(!ok){
                        break;
                    }
                    f = true;
                }
                cout<<(ok ? "YES\n" : "NO\n");
            }

            ~Solver(){} 
    };

    void solve(){
        int ntest = 1;
#ifndef  ONLINE_JUDGE
        ntest = 1; // single test to multitest.
#endif
        //cin>>ntest;  // multitest
        while(ntest--){
            Solver().solve();
        }
    }
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);	
    #endif // ONLINE_JUDGE
    Task::solve();
}

