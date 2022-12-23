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

    const int N = 5e3 + 5;
    string s;
    string ts[N];
    int n;
    int f[N],g[N][N],tr[N],cnt[N],suff[N];
    int digit[N];
    int zf[N][N];

    void solve(){
        cin>>s;
        n = len(s);
        for(int i = 1;i <= N - 5;++i){
            int val = i;
            while(val){
                ++digit[i];
                ts[i] += (char)('0' + (val % 10));
                val /= 10;
            }
            reverse(all(ts[i]));
        }
        for(int i = 0;i < n;++i) {
            vector<int> z(n - i + 2, 0);
            string str = s . substr(i);
            for (int l = 0, r = 0, j = 1; j < len(str); ++j) {
                if (j <= r) {
                    z[j] = min(z[j - l], r - j + 1);
                }
                while (j + z[j] <= len(str) && str[j + z[j]] == str[z[j]]) {
                    ++z[j];
                }
                if (j + z[j] - 1 > r) {
                    l = j;
                    r = j + z[j] - 1;
                }
            }
            for (int j = 0; j < len(str); ++j) {
                zf[i][i + j] = z[j];
            }
        }
        for(int k = n;k >= 1;--k){
            for(int l = 0;l + k < n;++l){
                if(zf[l][l + k] >= k){
                    int r = l + k + zf[l][l + k] - 1;
                    r = l + k * ((r - l + 1) / k) - 1;
                    g[l][r] = k;
                }
            }
        }
        for(int gap = n;gap >= 1;--gap){
            for(int l = 0,r = gap - 1;r < n;++l,++r){
                if(g[l][r] > 0){
                    if(l <= r - g[l][r]){
                        minimize(g[l][r - g[l][r]],g[l][r]);
                        minimize(g[l + g[l][r]][r],g[l][r]);
                    }
                } else {
                    g[l][r] = r - l + 1;
                }
            }
        }
        for(int i = 0;i < n;++i){
            f[i] = i + 1;
            cnt[i] = 1;
            suff[i] = i + 1;
        }
        for(int i = 1;i < n;++i){
            for(int j = i;j >= 0;--j){
                int fcur = (j - 1 >= 0 ? f[j - 1] + g[j][i] + 1 : g[j][i]);
                int c = (i - j + 1) / g[j][i];
                if(c > 1){
                    fcur += digit[c] + 1;
                }
                if(f[i] > fcur){
                    f[i] = fcur;
                    tr[i] = j;
                    suff[i] = g[j][i];
                    cnt[i] = c;
                }
                if(f[i] > (j - 1 >= 0 ? f[j - 1] : 0) + i - j + 2){
                    f[j] = (j - 1 >= 0 ? f[j - 1] : 0) + i - j + 2;
                    tr[i] = j;
                    suff[i] = i - j + 1;
                    cnt[i] = 1;
                }
            }
        }
        vector <string> ans;
        for(int t = n - 1;t >= 0;t = tr[t] - 1){
            int l = tr[t];
            string p = "";
            for(int i = l;i <= l + suff[t] - 1;++i){
                p += s[i];
            }
            if(cnt[t] > 1) {
                p += "*" + ts[cnt[t]];
            }
            ans.emplace_back(p);
        }
        for(int i = len(ans) - 1;i >= 0;--i){
            if(i < len(ans) - 1){
                cout<<'+';
            }
            cout<<ans[i];
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
