#include <iostream>
#include <vector>

using namespace std;

long long checked[30000000];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, A; long long X, B;
    cin >> N >> X >> A >> B;

    int Ac, Ad; long long Bc, Bd;
    cin >> Ac >> Bc >> Ad >> Bd;

    for (int i = 0; i < N; ++i) {
        int hash = int(X%29999999);
        bool found = false;
        while (checked[hash] != 0) {
            if (checked[hash] == X+1) {
                found = true;
                break;
            }
            else hash = (hash+hash+7)%29999999;
        }
        checked[hash] = X+1;

        if (found) {
            A = (A+Ac)%1000;
            B = (B+Bc)%1000000000000000LL;
        }
        else {
            A = (A+Ad)%1000;
            B = (B+Bd)%1000000000000000LL;
        }
        X = (A*X+B)%1000000000000000LL;
    }

    cout << X << ' ' << A << ' ' << B << '\n';
    return 0;
}
