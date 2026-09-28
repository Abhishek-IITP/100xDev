class Solution {
public:
    vector<int> fn(vector<int>& arr1, vector<int>& arr2) {

        int freq[1001] = {0};

        for (int x : arr1) {
            freq[x]++;
        }

        vector<int> ans;

        for (int x : arr2) {
            while (freq[x] > 0) {
                ans.push_back(x);
                freq[x]--;
            }
        }

        for (int i = 0; i <= 1000; i++) {
            while (freq[i]--) {
                ans.push_back(i);
            }
        }

        return ans;
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        return fn(arr1, arr2);
    }
};