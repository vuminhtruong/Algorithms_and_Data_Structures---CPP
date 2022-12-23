#include <iostream>
#include <vector>

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
        vector <int> a(n + 2,0);
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        int ok = 1;
        for(int i = 1;i <= n;++i){
            if((i << 1) <= n){
                ok &= (a[i] <= a[i << 1]);
            }
            if((i << 1 | 1) <= n){
                ok &= (a[i] <= a[i << 1 | 1]);
            }
        }
        cout<<(ok == true ? "YES" : "NO");
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
