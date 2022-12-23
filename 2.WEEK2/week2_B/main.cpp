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
    vector <int> compress;
    int a[N];
    int n;

    class FenwickTree{
    public:
        vector <int> tree;
        int numNode;
    public:
        FenwickTree(int sizeTree){
            numNode = sizeTree;
            tree.resize(sizeTree + 10,0);
        }
        void update(int node,int val){
            for(;node > 0;node -= node & (-node)){
                tree[node] += val;
            }
        }
        llong rsq(int node){
            llong ret = 0;
            for(;node <= numNode;node += node & (-node)){
                ret += tree[node];
            }
            return ret;
        }
    };

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
            compress.emplace_back(a[i]);
        }
        sort(all(compress));
        compress.erase(unique(all(compress)),compress.end());
        for(int i = 1;i <= n;++i){
            a[i] = lower_bound(all(compress),a[i]) - compress.begin() + 1;
        }
        llong ans = 0;
        FenwickTree *fenw = new FenwickTree(n);
        for(int i = 1;i <= n;++i){
            ans += fenw -> rsq(a[i] + 1);
            fenw -> update(a[i],1);
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
