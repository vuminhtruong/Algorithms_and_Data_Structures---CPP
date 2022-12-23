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

    const int N = 1e6 + 6;
    int n,m,k;
    string a[N];
    vector <int> pos[27];
    int cnt[27],ord[N],out[N];

    void radixSort(int row){
        for(int i = 0;i < 26;++i){
            cnt[i] = 0;
        }
        for(int i = 1;i <= n;++i){
            ++cnt[a[row][ord[i]] - 'a'];
            pos[a[row][ord[i]] - 'a'].emplace_back(ord[i]);
        }
        for(int i = 1;i < 26;++i){
            cnt[i] += cnt[i - 1];
        }
        for(int i = 1;i <= n;++i){
            out[cnt[a[row][i] - 'a']--] = pos[a[row][i] - 'a'].back();
            pos[a[row][i] - 'a'].pop_back();
        }
        for(int i = 1;i <= n;++i){
            ord[i] = out[i];
        }
    }

    void solve(){
        cin>>n>>m>>k;
        for(int i = 1;i <= m;++i){
            cin>>a[i];
            a[i] = " " + a[i];
        }
        for(int i = 1;i <= n;++i){
            ord[i] = i;
        }
        while(m > 0 && k > 0){
            radixSort(m);
            --m;
            --k;
        }
        for(int i = 1;i <= n;++i){
            cout<<ord[i]<<' ';
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
