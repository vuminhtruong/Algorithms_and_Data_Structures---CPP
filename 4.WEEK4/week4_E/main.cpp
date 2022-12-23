#include <iostream>
#include <vector>
#include <string>

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
    const char sign[] = {'+','-','*'};
    string s[N];
    bool vis[N];
    int n,id = 0;

    class Node{
    public :
        Node *left,*right;
        llong value;
        int index;
        char s;
    public :
        Node(){}
        Node(llong val){
            this -> left = nullptr;
            this -> right = nullptr;
            this -> value = val;
            this -> index = ++id;
            this -> s = ' ';
        }
        Node(Node* ll,Node* rr,char ss){
            this -> left = ll;
            this -> right = rr;
            this -> value = 0;
            this -> index = ++id;
            this -> s = ss;
        }
    };

    llong add(llong a,llong b){
        return a + b;
    }

    llong sub(llong a,llong b){
        return a - b;
    }

    llong mul(llong a,llong b){
        return a * b;
    }

    bool isSign(const string &str){
        if(len(str) > 1){
            return false;
        }
        bool ok = false;
        for(int i = 0;i < 3;++i){
            if(str[0] == sign[i]){
                ok = true;
            }
        }
        return ok;
    }

    llong parse(const string &str){
        llong ret = 0;
        for(int i = 0;i < len(str);++i){
            ret = ret * 1LL + 1LL * (str[i] - '0');
        }
        return ret;
    }

    void dfs(Node *cur){
        vis[cur -> index] = true;
        if(cur -> left){
            if(!vis[cur -> left -> index]){
                dfs(cur -> left);
            }
        }
        if(cur -> right){
            if(!vis[cur -> right -> index]) {
                dfs(cur -> right);
            }
        }
        if(cur -> s == '+'){
            cur -> value = add(cur -> left -> value,cur -> right -> value);
        } else if(cur -> s == '-'){
            cur -> value = sub(cur -> left -> value,cur -> right -> value);
        } else if(cur -> s == '*'){
            cur -> value = mul(cur -> left -> value,cur -> right -> value);
        }
    }

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>s[i];
        }
        vector <Node*> vec;
        for(int i = 1;i <= n;++i){
            if(!isSign(s[i])){
                vec.emplace_back(new Node(parse(s[i])));
            } else {
                Node *right = vec.back();
                vec.pop_back();
                Node *left = vec.back();
                vec.pop_back();
                vec.emplace_back(new Node(left,right,s[i][0]));
            }
        }
        dfs(vec.back());
        cout<<vec.back() -> value;
    }
}

int main(void){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    task::solve();
}
