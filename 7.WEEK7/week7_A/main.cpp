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
    int n;
    int k[N],l[N],r[N];

    class Node{
    public:
        int height,index,diff;
        Node *left,*right;
        Node(Node *ll,Node *rr,int h,int diff,int idx){
            this -> left = ll;
            this -> right = rr;
            this -> height = h;
            this -> diff = diff;
            this -> index = idx;
        }
    };

    void dfs(Node *cur){
        if(!cur){
            return ;
        }
        dfs(cur -> left);
        dfs(cur -> right);
        cur -> height = 1 + max(cur -> right ? cur -> right -> height : 0,cur -> left ? cur -> left -> height : 0);
        cur -> diff = (cur -> right ? cur -> right -> height : 0) - (cur -> left ? cur -> left -> height : 0);
    }

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>k[i]>>l[i]>>r[i];
        }
        vector <Node*> tree(n + 2,nullptr);
        for(int i = n;i >= 1;--i){
            tree[i] = new Node(l[i] ? tree[l[i]] : nullptr,r[i] ? tree[r[i]] : nullptr,0,0,i);
        }
        dfs(tree[1]);
        for(int i = 1;i <= n;++i){
            cout<<tree[i] -> diff<<'\n';
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
