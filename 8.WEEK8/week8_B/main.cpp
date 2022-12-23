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

    const int N = 5e5 + 5;
    string value[N];
    map <string,int> index;
    set <int> st;

    void solve(){
        int m,pos = 0;
        cin>>m;
        while(m--){
            string op,x,y;
            cin>>op>>x;
            if(op == "put"){
                cin>>y;
                if(st.find(index[x]) == st.end()) {
                    value[++pos] = y;
                    index[x] = pos;
                    st . insert(pos);
                } else {
                    value[index[x]] = y;
                }
            } else if(op == "get"){
                if(st.find(index[x]) != st.end()){
                    cout<<value[index[x]]<<'\n';
                } else {
                    cout<<"<none>\n";
                }
            } else if(op == "prev"){
                set <int> :: iterator it = st.find(index[x]);
                if(it == st.end()){
                    cout<<"<none>\n";
                } else if(it == st.begin()){
                    cout<<"<none>\n";
                } else {
                    --it;
                    cout<<value[*it]<<'\n';
                }
            } else if(op == "next"){
                set <int> :: iterator  it = st.find(index[x]);
                if(it == st.end()){
                    cout<<"<none>\n";
                } else if(index[x] == *st.rbegin()){
                    cout<<"<none>\n";
                } else {
                    ++it;
                    cout<<value[*it]<<'\n';
                }
            } else if(op == "delete"){
                if(st.find(index[x]) != st.end()){
                    st.erase(st.find(index[x]));
                }
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
