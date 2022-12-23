#include <iostream>
#include <string>
#include <stack>

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

    void solve(){
        int n;
        cin>>n;
        while(n--){
            string bracket;
            cin>>bracket;
            stack <int> stk;
            bool ok = true;
            for(int i = 0;i < len(bracket);++i){
                if(bracket[i] == '(' || bracket[i] == '['){
                    stk.push(i);
                } else {
                    if(!stk.empty()){
                        if(bracket[i] == ')'){
                            if(bracket[stk.top()] == '('){
                                stk.pop();
                            } else {
                                ok = false;
                                break;
                            }
                        } else {
                            if(bracket[stk.top()] == '['){
                                stk.pop();
                            } else {
                                ok = false;
                                break;
                            }
                        }
                    } else {
                        ok = false;
                    }
                }
            }
            if(!stk.empty()){
                ok = false;
            }
            cout<<(ok == true ? "YES\n" : "NO\n");
        }
    }
}

int main(void){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    task::solve();
}
