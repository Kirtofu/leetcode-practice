#include <bits/stdc++.h>
using namespace std;
class Solution {
    bool is_palindrome(string_view s) {
        int n=s.size();
        for (int i=0;i<n/2;i++){
            if (s[i]!=s[n-1-i]){
                return false;
            }
        }
        return true;
    }
    //判断是不是回文
    //f[i] 表示：前缀字符串 s[0...i-1]（即前 i 个字符）中，能选择的互不重叠且长度至少为 k 的回文子串的最大数量。
public:
    int maxPalindromes(string S, int k) {
        string_view s(S);
        int n=s.size();
        vector<int> f(n + 1);
        for (int i = k; i <= n; i++) {
            f[i] = f[i - 1]; // 不考虑 s[i-1]
            if (is_palindrome(s.substr(i - k, k))) {
                f[i] = max(f[i], f[i - k] + 1);
            }
            if (i > k && is_palindrome(s.substr(i - k - 1, k + 1))) {   //i>k防止数组越界
                f[i] = max(f[i], f[i - k - 1] + 1); //取k+1是因为防止遗漏（奇数偶数）
            }
        }
        return f[n];
    }
};