#include <iostream>
#include <vector>
#include <map>

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
    int n,m;
    int l[N],r[N],k[N];

    class Node{
    public:
        Node *left,*right;
        int szt;
        int value;
    public:
        Node(){
            this -> left = this -> right = nullptr;
            this -> value = this -> szt = 0;
        }
        Node(int value){
            this -> left = this -> right = nullptr;
            this -> szt = 1;
            this -> value = value;
        }
        Node(Node *ll,Node *rr,int value){
            this -> left = ll;
            this -> right = rr;
            this -> value = value;
            this -> szt = 1;
        }
    };

    vector <Node*> tree;
    bool found;

    void dfs(Node *cur){
        if(cur -> left){
            dfs(cur -> left);
        }
        if(cur -> right){
            dfs(cur -> right);
        }
        if(cur -> left){
            cur -> szt += cur -> left -> szt;
        }
        if(cur -> right){
            cur -> szt += cur -> right -> szt;
        }
    }

    void search(Node *cur,int key){
        if(cur == nullptr){
            found = false;
        } else if(cur -> value > key){
            search(cur -> left,key);
        } else if(cur -> value < key){
            search(cur -> right,key);
        } else {
            found = true;
            return;
        }
    }

    Node* del(Node *cur,int key){
        if(cur -> value == key){
            return new Node();
        } else if(cur -> value > key){
            cur -> left = del(cur -> left,key);
            cur -> szt = (cur -> left ? cur -> left -> szt : 0) + 1 + (cur -> right ? cur -> right -> szt : 0);
            return cur;
        } else if(cur -> value < key){
            cur -> right = del(cur -> right,key);
            cur -> szt = (cur -> left ? cur -> left -> szt : 0) + 1 + (cur -> right ? cur -> right -> szt : 0);
            return cur;
        } else {
            return cur;
        }
    }

    void solve(){
        cin>>n;
        map <int,int> ma;
        for(int i = 1;i <= n;++i){
            cin>>k[i]>>l[i]>>r[i];
            ++ma[k[i]];
        }
        tree.resize(n + 2);
        for(int i = n;i >= 1;--i){
            if(l[i] && r[i]){
                tree[i] = new Node(tree[l[i]],tree[r[i]],k[i]);
            } else {
                if(l[i]){
                    tree[i] = new Node(tree[l[i]], nullptr,k[i]);
                } else if(r[i]){
                    tree[i] = new Node(nullptr,tree[r[i]],k[i]);
                } else {
                    tree[i] = new Node(k[i]);
                }
            }
        }
        dfs(tree[1]);
        cin>>m;
        while(m--){
            int key;
            cin>>key;
            found = true;
            search(tree[1],key);
            if(found == true){
                del(tree[1], key);
            }
            cout<<tree[1] -> szt<<'\n';
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
