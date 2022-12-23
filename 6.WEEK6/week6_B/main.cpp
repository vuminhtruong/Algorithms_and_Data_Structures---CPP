#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

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

    const int N = 1e3 + 3;
    const double lim = 1e-6;
    int n;
    double h[N];
    double A;

    bool chk(){
        for(int i = 1;i <= n;++i){
            if(h[i] != 0.0){
                if(h[i] < 0.0){
                    return false;
                }
            }
        }
        return true;
    }

    void solve(){
        cin>>n>>A;
        vector <double> ans;
        for(int i = 2;i < n;++i){
            h[i] = 0.0;
            int cnt = 0;
            double l = 0.0,r = 2.0;
            double f = -1.0;
            while(cnt <= 100){
                double mid = (l + r) / 2.0;
                h[i - 1] = mid;
                for(int j = i - 2;j >= 1;--j){
                    h[j] = 2.0 * (h[j + 1] + 1.0) - h[j + 2];
                }
                if(h[1] >= A){
                    r = mid;
                    if(Abs(A - h[1]) <= 0.000001){
                        f = mid;
                    }
                } else {
                    l = mid;
                }
                ++cnt;
            }
            if(f > -1.0){
                h[i + 1] = 2.0 - f;
                for(int j = i + 2;j <= n;++j){
                    h[j] = 2.0 * (h[j - 1] + 1.0) - h[j - 2];
                }
                if(chk()) {
                    if (h[n] > 0.0) {
                        ans.emplace_back(h[n]);
                    }
                }
            }
        }
        sort(all(ans));
        cout<<setprecision(15)<<fixed<<(ans.empty() ? 0.0 : ans[0]);
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
