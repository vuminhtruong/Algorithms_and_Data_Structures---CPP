#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <set>
#include <map>
#include <complex>
#include <list>
#include <queue>
#include <stack>
#include <random>
#include <chrono>
#include <cassert>

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
            
            static const int MAXVALUE = 40000;
            static const int MAX_MASK = 255;
            vector < int > a;
            vector < int > b;
            vector < int > c;
            vector < vector < int > > vec;
            int n,m;

            /*
            void radixSort(int L,int pw){
                vector < int > output(len(vec[L]),0);
                vector < int > cnt(11,0);
                
                for(int i = 0;i < len(vec[L]);++i){
                    ++cnt[(vec[L][i] / pw) % 10];
                }
                
                for(int i = 1;i < 10;++i){
                    cnt[i] += cnt[i - 1];
                }
                
                for(int i = len(vec[L]) - 1;i >= 0;--i){
                    output[cnt[(vec[L][i] / pw) % 10] - 1] = vec[L][i];
                    --cnt[(vec[L][i] / pw) % 10];
                }
                vec[L] = output;
            }
            */
            
            void radixSort(int mask){
                vector < int > cnt(MAX_MASK + 2,0);
                vector < int > output(len(c),0);
                
                for(int i = 0;i < len(c);++i){
                    ++cnt[(c[i] >> mask) & MAX_MASK];
                }
                
                for(int i = 1;i <= MAX_MASK;++i){
                    cnt[i] += cnt[i - 1];
                }
                
                for(int i = len(c) - 1;i >= 0;--i){
                    output[cnt[(c[i] >> mask) & MAX_MASK] - 1] = c[i];
                    --cnt[(c[i] >> mask) & MAX_MASK];
                }
                
                c = output;
            }
            
            void solve(){
                cin>>n>>m;
                a.resize(n + 2,0);
                for(int i = 1;i <= n;++i){
                    cin>>a[i];
                }
                b.resize(m + 2,0);
                for(int i = 1;i <= m;++i){
                    cin>>b[i];
                }
                vec.resize(12,vector < int > ());
                for(int i = 1;i <= n;++i){
                    for(int j = 1;j <= m;++j){
                        /*
                        if(a[i] == 0 || b[j] == 0){
                            vec[1].emplace_back(0);
                        } else {
                            vec[(int)(log10(a[i]) + log10(b[j]) + 1)].emplace_back(a[i] * b[j]);
                        }
                        */
                        c.emplace_back(a[i] * b[j]);
                    }
                }
                llong ans = 0;
                /*
                int curLen = 0;
                int digit = 1;
                vector < bool > computed(12,false);
                for(int pos = 1;pos <= n * m;pos += 10){
                    while(digit < 11 && curLen < pos){
                        curLen += len(vec[digit++]);
                    }
                    if(!computed[digit - 1]){
                        for(int pw = 1,j = digit - 1;j >= 1;pw *= 10,--j){
                            radixSort(digit - 1,pw);
                        }
                        computed[digit - 1] = true;
                    }
                    int sum = curLen - len(vec[digit - 1]);
                    int p = pos - sum;
                    //debug(p,digit - 1,len(vec[digit - 1]));
                    assert(p >= 0 && p - 1 < len(vec[digit - 1]));
                    ans += (llong)vec[digit - 1][p - 1];
                }
                */
                for(int i = 0;i < 4;++i){
                    radixSort(i << 3);
                }
                for(int pos = 0;pos < len(c);pos += 10){
                    ans += c[pos];
                }
                cout<<ans<<'\n';
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
    /*
    ofstream cout("input.txt");
    cout<<6000<<' '<<6000<<'\n';
    for(int i = 1;i <= 6000;++i){
        cout<<1 + rand(40000)<<' ';
    }
    cout<<'\n';
    for(int i = 1;i <= 6000;++i){
        cout<<1 + rand(40000)<<' ';
    }
    //cout<<1 + rand(40000);
    cout<<'\n';
    cout.close();
    */
    Task::solve();
}

