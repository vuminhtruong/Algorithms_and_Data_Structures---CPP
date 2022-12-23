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
    int n,chk = 1;
    int k[N],l[N],r[N];

    class Node{
    public:
        Node *left,*right;
        int value;
        int max_value,min_value;
    public:
        Node(){}
        Node(int value){
            this -> left = this -> right = nullptr;
            this -> max_value = this -> min_value = this -> value = value;
        }
        Node(Node *ll,Node *rr,int value){
            this -> left = ll;
            this -> right = rr;
            this -> max_value = this -> min_value = this -> value = value;
        }
    };
    vector <Node*> tree;

    void dfs(Node *cur){
        if(!cur){
            return ;
        }
        if(cur -> left){
            dfs(cur -> left);
        }
        if(cur -> right){
            dfs(cur -> right);
        }
        if(cur -> left){
            chk &= (cur -> value > cur -> left -> max_value);
            maximize(cur -> max_value,cur -> left -> max_value);
            minimize(cur -> min_value,cur -> left -> min_value);
        }
        if(cur -> right){
            chk &= (cur -> value < cur -> right -> min_value);
            maximize(cur -> max_value,cur -> right -> max_value);
            minimize(cur -> min_value,cur -> right -> min_value);
        }
    }

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>k[i]>>l[i]>>r[i];
        }
        tree.resize(n + 2);
        for(int i = n;i >= 1;--i){
            if(l[i] && r[i]){
                tree[i] = new Node(tree[l[i]],tree[r[i]],k[i]);
            } else {
                if(l[i]){
                    tree[i] = new Node(tree[l[i]],nullptr,k[i]);
                } else if(r[i]){
                    tree[i] = new Node(nullptr,tree[r[i]],k[i]);
                } else {
                    tree[i] = new Node(k[i]);
                }
            }
        }
        dfs(tree[1]);
        cout<<(chk == 1 ? "YES" : "NO");
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
