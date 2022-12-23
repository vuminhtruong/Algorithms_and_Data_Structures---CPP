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
        Node *left,*right;
        int key,height,balance,index;
        Node(Node *ll,Node *rr,int key,int height,int balance){
            this -> left = ll;
            this -> right = rr;
            this -> key = key;
            this -> height = height;
            this -> balance = balance;
        }
    public:
        void computeHeight();
        void computeBalance();
        Node* insertKey(Node*,int);
    };

    void Node::computeHeight() {
        height =  1 + max(left ? left -> height : 0,right ? right -> height : 0);
    }

    void Node::computeBalance() {
        balance =  (left ? left -> height : 0) - (right ? right -> height : 0);
    }

    Node *rotateLeft(Node *cur){
        Node *nw_root = cur -> right;
        Node *ll = nw_root -> left;
        nw_root -> left = cur;
        cur -> right = ll;
        cur -> computeHeight();
        cur -> computeBalance();
        nw_root -> computeHeight();
        nw_root -> computeBalance();
        return nw_root;
    }

    Node *rotateRight(Node *cur){
        Node *nw_root = cur -> left;
        Node *rr = nw_root -> right;
        nw_root -> right = cur;
        cur -> left = rr;
        cur -> computeHeight();
        cur -> computeBalance();
        nw_root -> computeHeight();
        nw_root -> computeBalance();
        return  nw_root;
    }

    void balanceTree(Node *cur){
        if(!cur) {
            return ;
        }
        balanceTree(cur -> left);
        balanceTree(cur -> right);
        cur -> computeHeight();
        cur -> computeBalance();
    }

    Node* Node::insertKey(Node *cur, int key) {
        if(!cur){
            return new Node(nullptr,nullptr,key,1,0);
        }
        if(key < cur -> key){
            cur -> left =  insertKey(cur -> left,key);
        } else if(key > cur -> key){
            cur -> right = insertKey(cur -> right,key);
        }
        cur -> computeHeight();
        cur -> computeBalance();
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

    int pos;
    void dfs(Node *cur){
        if(!cur){
            return ;
        }
        dfs(cur -> left);
        dfs(cur -> right);
        k[pos] = cur -> key;
        l[pos] = r[pos] = 0;
        if(cur -> left){
            l[pos] = cur -> left -> index;
        }
        if(cur -> right){
            r[pos] = cur -> right -> index;
        }
        cur -> index = pos--;
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
        balanceTree(tree[1]);
        int x; cin>>x;
        tree[1] = tree[1] -> insertKey(tree[1],x);
        pos = n + 1;
        dfs(tree[1]);
        cout<<n + 1<<'\n';
        for(int i = 1;i <= n + 1;++i){
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
