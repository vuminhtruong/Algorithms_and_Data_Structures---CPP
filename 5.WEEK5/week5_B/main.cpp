#include <iostream>
#include <set>
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

    void solve(){
        int n;
        cin>>n;
        vector <int> value(n + 3,0);
        set <pair <int,int> > heap;
        for(int i = 1;i <= n;++i){
            char c;
            int x,y;
            cin>>c;
            if(c == 'A'){
                cin>>value[i + 1];
                heap.insert(make_pair(value[i + 1],i + 1));
            } else if(c == 'D'){
                cin>>x>>y;
                heap.erase(heap.find(make_pair(value[x + 1],x + 1)));
                value[x + 1] = y;
                heap.insert(make_pair(value[x + 1],x + 1));
            } else {
                if(!heap.empty()){
                    cout<<heap.begin() -> first<<'\n';
                    heap.erase(heap.begin());
                } else {
                    cout<<"*\n";
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
