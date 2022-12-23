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

            static const int N = 4e7 + 2;
            vector < int > a;
            int n,k_1,k_2;
            
            void Qsort(int l,int r){
                int mid = (l + r) >> 1;
                int x = a[mid];
                int i = l;
                int j = r;
                do{
                    while(a[i] < x){
                        ++i;
                    }
                    while(x < a[j]){
                        --j;
                    }
                    if(i <= j){
                        swap(a[i],a[j]);
                        ++i;
                        --j;
                    }
                } while(i <= j);
               if(l < j && j >= k_1 - 1){
                   Qsort(l,j);
               }
               if(i < r && i <= k_2){
                   Qsort(i,r);
               }
            }
            
            void solve(){
                cin>>n>>k_1>>k_2;
                int A,B,C;
                a.resize(n + 2,0);
                cin>>A>>B>>C>>a[1]>>a[2];
                for(int i = 3;i <= n;++i){
                    a[i] = A * a[i - 2] + B * a[i - 1] + C;
                }
                Qsort(1,n);
                for(int i = k_1;i <= k_2;++i){
                    cout<<a[i]<<' ';
                }
                cout<<'\n';
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

