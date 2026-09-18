class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int> L(26,-1),R(26,-1);
        // 1. 统计每个字符的首次出现 (L) 和最后一次出现 (R)
        for (int i=0;i<n;i++){
            int c=s[i]-'a';
            if (L[c]==-1) L[c]=i;
            R[c]=i;
        }
        vector<pair<int,int>>intervals;
        // 2. 枚举每个字符作为起点，扩展区间
        for (int i=0;i<26;i++){
            if (L[i]==-1){
                continue;
            }
            int l=L[i];
            int r=R[i];
            bool ok=true;
            for (int j=l;j<=r;j++){
                int c=s[j]-'a';
                // 如果区间内部某个字符在起点 l 的左侧就出现过了
                // 说明从 l 开始切断是不合法的（会漏掉该字符左边的部分）
                if (L[c] < l){
                    ok=false;
                    break;
                }
                r=max(r,R[c]);
            }
            if (ok){
                intervals.push_back({r,l});
            }
        }
        // 3. 按照右边界升序排序（C++ pair 默认先比 first，即右边界 r）
        sort(intervals.begin(),intervals.end());
        // 4. 贪心选取互不重叠的子串
        vector<string> ans;
        int last_r = -1; // 上一个被选中子串的右边界
        for (auto& p : intervals) {
            int r = p.first;
            int l = p.second;
            // 只要当前子串的左边界大于上一个子串的右边界，就说明无重叠
            if (l > last_r) {
                ans.push_back(s.substr(l, r - l + 1));
                last_r = r; // 更新最右边界
            }
        }
        return ans;
    }
};