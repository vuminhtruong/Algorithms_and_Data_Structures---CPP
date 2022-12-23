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

    int n;

    class Node{
    public:
        Node *left,*right;
        int key,height,balance;
    public:
        Node(){};
        Node(Node *ll,Node *rr,int key,int height,int balance){
            this -> left = ll;
            this -> right = rr;
            this -> key = key;
            this -> height = height;
            this -> balance = balance;
        }
        void computeHeight(){
            height = 1 + max(left ? left -> height : 0,right ? right -> height : 0);
        }
        void computeBalance(){
            balance = (right ? right -> height : 0) - (left ? left -> height : 0);
        }
    };
    Node *tree = nullptr;

    Node* rotateLeft(Node *cur){
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

    Node* rotateRight(Node *cur){
        Node *nw_root = cur -> left;
        Node *rr = nw_root -> right;
        nw_root -> right = cur;
        cur -> left = rr;
        cur -> computeHeight();
        cur -> computeBalance();
        nw_root -> computeHeight();
        nw_root -> computeBalance();
        return nw_root;
    }

    Node* rotateNode(Node *cur){
        if(cur -> balance < -1 && cur -> left -> balance <= 0){
            return rotateRight(cur);
        }
        if(cur -> balance < -1 && cur -> left -> balance > 0){
            cur -> left = rotateLeft(cur -> left);
            return rotateRight(cur);
        }
        if(cur -> balance > 1 && cur -> right -> balance >= 0){
            return rotateLeft(cur);
        }
        if(cur -> balance > 1 && cur -> right -> balance < 0){
            cur -> right = rotateRight(cur -> right);
            return rotateLeft(cur);
        }
        return cur;
    }

    Node* insertKey(Node *cur,int key){
        if(!cur){
            return new Node(nullptr,nullptr,key,1,0);
        }
        if(key < cur -> key){
            cur -> left = insertKey(cur -> left,key);
        } else if(key > cur -> key){
            cur -> right = insertKey(cur -> right,key);
        } else {
            return cur;
        }
        cur -> computeHeight();
        cur -> computeBalance();
        cur = rotateNode(cur);
        return cur;
    }

    Node* findRightChild(Node *cur){
        Node *ret = cur;
        while(ret -> right){
            ret = ret -> right;
        }
        return ret;
    }

    Node* deleteKey(Node *cur,int key){
        if(!cur){
            return nullptr;
        }
        if(key < cur -> key){
            cur -> left = deleteKey(cur -> left,key);
        } else if(key > cur -> key){
            cur -> right = deleteKey(cur -> right,key);
        } else {
            if(cur -> left && cur -> right){
                Node *t = findRightChild(cur -> left);
                cur -> key = t -> key;
                cur -> left = deleteKey(cur -> left,t -> key);
            } else if(cur -> left){
                cur = cur -> left;
            } else if(cur -> right){
                cur = cur -> right;
            } else {
                cur = nullptr;
            }
        }
        if(!cur){
            return nullptr;
        }
        cur -> computeHeight();
        cur -> computeBalance();
        cur = rotateNode(cur);
        return cur;
    }

    int findKey(Node *cur,int key){
        if(!cur){
            return 0;
        }
        int le = 0,ri = 0;
        if(key < cur -> key){
            le = findKey(cur -> left,key);
        } else if(key > cur -> key){
            ri = findKey(cur -> right,key);
        } else {
            return 1;
        }
        return (le | ri);
    }

    void solve(){
        cin>>n;
        while(n--){
            char c;
            int key;
            cin>>c>>key;
            if(c == 'A'){
                tree = insertKey(tree,key);
                cout<<tree -> balance<<'\n';
            } else if(c == 'D'){
                tree = deleteKey(tree,key);
                if(tree) {
                    cout << tree -> balance << '\n';
                } else {
                    cout<<0<<'\n';
                }
            } else {
                cout<<(findKey(tree,key) ? "Y" : "N")<<'\n';
            }
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
