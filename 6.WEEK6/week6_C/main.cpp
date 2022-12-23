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

    const int N = 2e5 + 5;
    int n,height = 0;
    vector <int> adj[N];
    int l[N],r[N],k[N];

    void dfs(int u,int par,int deep = 0){
        maximize(height,deep);
        for(int i = 0;i < len(adj[u]);++i){
            int v = adj[u][i];
            if(v != par){
                dfs(v,u,deep + 1);
            }
        }
    }

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>k[i]>>l[i]>>r[i];
        }
        if(!n){
            cout<<0;
            exit(0);
        }
        for(int i = 1;i <= n;++i){
            if(l[i]){
                adj[i].emplace_back(l[i]);
            }
            if(r[i]){
                adj[i].emplace_back(r[i]);
            }
        }
        dfs(1,1);
        cout<<height + 1;
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
