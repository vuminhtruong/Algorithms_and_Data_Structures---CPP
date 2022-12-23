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
        cin>>n;
        vector <int> a(n);
        for(int i = 0;i < n;++i){
            cin>>a[i];
        }
        for(int i = 0;i < n;++i){
            int pos = i;
            int val = a[i];
            while(pos >= 1 && a[pos - 1] > val){
                --pos;
            }
            if(pos < i) {
                a.erase(a.begin() + i);
                a . insert(a . begin() + pos, val);
            }
            cout<<pos + 1<<' ';
        }
        cout<<'\n';
        for(int i = 0;i < n;++i){
            cout<<a[i]<<' ';
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
