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

    const int N = 2e5 + 5;
    int n;
    int k[N],l[N],r[N];

    class Node{
    public:
        int key,height,balance;
        Node *left,*right;
        Node(Node *left,Node *right,int key,int height,int balance){
            this -> left = left;
            this -> right = right;
            this -> key = key;
            this -> height = height;
            this -> balance = balance;
        }
        int computeHeight() {
            return 1 + max(left ? left -> height : 0, right ? right -> height : 0);
        }
        int computeBalance(){
            return (left ? left -> height : 0) - (right ? right -> height : 0);
        }
    };

    Node* rotateLeft(Node *cur){
        Node *nw_root = cur -> right;
        Node *ll = nw_root -> left;
        nw_root -> left = cur;
        cur -> right = ll;
        cur -> height = cur -> computeHeight();
        cur -> balance = cur -> computeBalance();
        nw_root -> height = nw_root -> computeHeight();
        nw_root -> balance = nw_root -> computeBalance();
        return nw_root;
    }

    Node* rotateRight(Node *cur){
        Node *nw_root = cur -> left;
        Node *rr = nw_root -> right;
        nw_root -> right = cur;
        cur -> left = rr;
        cur -> height = cur -> computeHeight();
        cur -> balance = cur -> computeBalance();
        nw_root -> height = nw_root -> computeHeight();
        nw_root -> balance = nw_root -> computeBalance();
        return nw_root;
    }

    Node* balanceTree(Node *cur){
        if(!cur){
            return nullptr;
        }
        cur -> left = balanceTree(cur -> left);
        cur -> right = balanceTree(cur -> right);
        cur -> height = cur -> computeHeight();
        cur -> balance = cur -> computeBalance();
        if(cur -> balance > 1 && cur -> left -> balance >= 0){
            return rotateRight(cur);
        }
        if(cur -> balance > 1 && cur -> left -> balance < 0){
            cur -> left = rotateLeft(cur -> left);
            return rotateRight(cur);
        }
        if(cur -> balance < -1 && cur -> right -> balance <= 0){
            return rotateLeft(cur);
        }
        if(cur -> balance < -1 && cur -> right -> balance > 0){
            cur -> right = rotateRight(cur -> right);
            return rotateLeft(cur);
        }
        return cur;
    }

    map <int,int> ma;
    int pos = 0;
    void dfs(Node *cur){
        if(!cur){
            return ;
        }
        dfs(cur -> left);
        dfs(cur -> right);
        k[pos] = cur -> key;
        if(cur -> left){
            l[pos] = ma[cur -> left -> key];
        } else {
            l[pos] = 0;
        }
        if(cur -> right){
            r[pos] = ma[cur -> right -> key];
        } else {
            r[pos] = 0;
        }
        ma[cur -> key] = pos--;
    }

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>k[i]>>l[i]>>r[i];
        }
        vector <Node*> tree(n + 2,nullptr);
        for(int i = n;i >= 1;--i){
            tree[i] = new Node(tree[l[i]],tree[r[i]],k[i],0,0);
        }
        tree[1] = balanceTree(tree[1]);
        pos = n;
        dfs(tree[1]);
        cout<<n<<'\n';
        for(int i = 1;i <= n;++i){
            cout<<k[i]<<' '<<l[i]<<' '<<r[i]<<'\n';
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
