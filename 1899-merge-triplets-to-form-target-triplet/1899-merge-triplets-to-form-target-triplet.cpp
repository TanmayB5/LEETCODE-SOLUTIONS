class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> merged(3, 0);
        
        for (auto& triplet : triplets) {
            // Skip invalid triplets (those with any value > target)
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) {
                continue;
            }

            // Merge triplet into merged vector
            for (int i = 0; i < 3; i++) {
                merged[i] = max(merged[i], triplet[i]);
            }
        }

        return merged == target;
    }
};
