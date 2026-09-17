class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, INT_MAX / 2);
        int ans = INT_MAX / 2;
        unordered_map<int, int> pre;
        pre[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            pre[sum] = i;
            if (i > 0) {
                best[i] = best[i - 1];
            }
            if (pre.count(sum - target)) {
                int left = pre[sum - target];
                int cur_len = i - left; // 当前子数组的长度
                // 如果左边 (left 及其之前) 存在合法的子数组，尝试更新全局最小和
                if (left >= 0 && best[left] < INT_MAX / 2) {
                    ans = min(ans, cur_len + best[left]);
                }
                // 更新 best[i]
                best[i] = min(best[i], cur_len);
            }
        }
        return ans >= INT_MAX / 2 ? -1 : ans;
    }
};