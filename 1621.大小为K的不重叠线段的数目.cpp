typedef long long ll;
const int MOD = 1e9 + 7;
const int MX = 1999; // n <= 1000, k <= 1000，n+k-1 最大约为 1999
ll F[MX];     // 阶乘数组 F[i] = i! % MOD
ll INV_F[MX]; // 阶乘逆元数组 INV_F[i] = (i!)^(-1) % MOD
ll qpow(ll x, int n) {//快速幂模板
    ll res = 1;
    for (; n; n /= 2) {
        if (n % 2) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
    }
    return res;
}
 //预处理算出 0! 到 1998! 的阶乘及其逆元
auto init = [] {
    F[0] = 1;
    for (int i = 1; i < MX; i++) {
        F[i] = F[i - 1] * i % MOD;
    }

    INV_F[MX - 1] = qpow(F[MX - 1], MOD - 2);
    for (int i = MX - 1; i; i--) {
        INV_F[i - 1] = INV_F[i] * i % MOD;
    }
    return 0;
}();
long long comb(int n, int m) { 
    return F[n] * INV_F[m] % MOD * INV_F[n - m] % MOD;
}//组合数计算函数
class Solution {
public:
    int numberOfSets(int n, int k) {
        return comb(n + k - 1, k * 2);
    }
};