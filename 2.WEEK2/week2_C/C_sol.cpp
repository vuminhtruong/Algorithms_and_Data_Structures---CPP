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
            
            int n;
            vector < int > a;
            
            void solve(){
                cin>>n;
                a.resize(n + 2,0);
                int idx = 1,index = 1;
                int l = 1,r = n;
                for(int i = n;i >= 1;--i){
                    index = (l + r) >> 1;
                    while(a[index]){
                        index = a[index];
                    }
                    if(i == 2){
                        idx = index;
                    }
                    a[index] = i;
                    --r;
                }
                swap(a[index],a[idx]);
                for(int i = 1;i <= n;++i){
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

