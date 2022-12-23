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

    const int N = 1e5 + 5;
    int n;
    int a[N];

    void MergeSort(int l,int r){
        if(l == r){
            return ;
        }
        int mid = (l + r) >> 1;
        MergeSort(l,mid);
        MergeSort(mid + 1,r);
        vector <int> x,y;
        for(int i = l;i <= mid;++i){
            x.emplace_back(a[i]);
        }
        for(int i = mid + 1;i <= r;++i){
            y.emplace_back(a[i]);
        }
        int cur_x = 0,cur_y = 0,cur = l;
        while(cur_x < len(x) && cur_y < len(y)){
            if(x[cur_x] < y[cur_y]){
                a[cur++] = x[cur_x++];
            } else {
                a[cur++] = y[cur_y++];
            }
        }
        while(cur_x < len(x)){
            a[cur++] = x[cur_x++];
        }
        while(cur_y < len(y)){
            a[cur++] = y[cur_y++];
        }
        cout<<l<<' '<<r<<' '<<a[l]<<' '<<a[r]<<'\n';
    }

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        MergeSort(1,n);
        for(int i = 1;i <= n;++i){
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
