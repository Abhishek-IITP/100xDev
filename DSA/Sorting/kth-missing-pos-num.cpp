class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> ans;
        int j = 0;

        for (int i = 1; ; i++) {
            if (j < arr.size() && i == arr[j]) {
                j++;
            } else {
                ans.push_back(i);

                if (ans.size() == k)
                    return ans[k - 1];
            }
        }
    }
};