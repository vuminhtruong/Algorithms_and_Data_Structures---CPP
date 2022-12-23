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
void maximize(T &x,U y){
    if(x < y)x = y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x = y;
}
template <class T>
T Abs(T x){
    return (x < (T)0 ? -x : x);
}

#define len(c) (int)((c).size())
#define llong long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    void solve(){
        int n;
        string s;
        cin>>s;
        n = len(s);
        vector <int> z(n + 2,0);
        for(int l = 0,r = 0,i = 1;i < n;++i){
            if(i <= r){
                z[i] = min(r - i + 1,z[i - l]);
            }
            while(i + z[i] <= n && s[i + z[i]] == s[z[i]]){
                ++z[i];
            }
            if(i + z[i] - 1 > r){
                l = i;
                r = i + z[i] - 1;
            }
        }
        for(int i = 1;i < n;++i){
            cout<<z[i]<<' ';
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
