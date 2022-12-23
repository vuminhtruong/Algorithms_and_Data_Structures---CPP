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

    const int N = 3e5 + 5;
    string s;
    string t;
    int n;
    int cnt[27][N];

    void solve(){
        getline(cin,s);
        stringstream str(s);
        while(str >> s){
            t += s;
        }
        n = len(t);
        t = " " + t;
        for(int i = 1;i <= n;++i){
            for(int j = 0;j < 26;++j){
                cnt[j][i] = cnt[j][i - 1] + (t[i] == (char)(j + 'a'));
            }
        }
        llong ans = 0;
        for(int i = 2;i < n;++i){
            for(int j = 0;j < 26;++j){
                ans += 1LL * cnt[j][i - 1] * 1LL * (cnt[j][n] - cnt[j][i]);
            }
        }
        cout<<ans;
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
