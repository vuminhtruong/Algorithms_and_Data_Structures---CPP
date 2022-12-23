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
        int m;
        cin>>m;
        for(int i = 1;i <= m;++i){
            int val;
            cin>>val;
            int l = 1,r = n;
            int pos_l = -1,pos_r = -1;
            for(int mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
                if(a[mid] < val){
                    l = mid + 1;
                } else {
                    r = mid - 1;
                    if(a[mid] == val){
                        pos_l = mid;
                    }
                }
            }
            l = 1,r = n;
            for(int mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
                if(a[mid] > val){
                    r = mid - 1;
                } else {
                    l = mid + 1;
                    if(a[mid] == val){
                        pos_r = mid;
                    }
                }
            }
            cout<<pos_l<<' '<<pos_r<<'\n';
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
