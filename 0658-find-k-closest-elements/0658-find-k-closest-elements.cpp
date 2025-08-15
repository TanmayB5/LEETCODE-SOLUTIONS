class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;

        // Case 1: x is smaller than smallest element
        if (x <= arr[0]) {
            for (int i = 0; i < k; i++) {
                ans.push_back(arr[i]);
            }
            return ans;
        }

        // Case 2: x is greater than largest element
        if (x >= arr[n - 1]) {
            for (int i = n - k; i < n; i++) {
                ans.push_back(arr[i]);
            }
            return ans;
        }

        // Find closest index
        int temp = 0;
        for (int i = 0; i < n - 1; i++) { // stop at n-2 to avoid out-of-bounds
            if (arr[i] <= x && arr[i + 1] >= x) {
                // Pick closer of the two
                if (x - arr[i] <= arr[i + 1] - x)
                    temp = i;
                else
                    temp = i + 1;
                break;
            }
        }

        ans.push_back(arr[temp]);
        int l = temp - 1, r = temp + 1;
        int remaining = k - 1;

        // Expand from the middle outwards
        while (remaining > 0) {
            if (l >= 0 && r < n) {
                if (x - arr[l] <= arr[r] - x) {
                    ans.push_back(arr[l--]);
                } else {
                    ans.push_back(arr[r++]);
                }
            } else if (l >= 0) {
                ans.push_back(arr[l--]);
            } else {
                ans.push_back(arr[r++]);
            }
            remaining--;
        }

        // Sort final result
        sort(ans.begin(), ans.end());
        return ans;
    }
};
