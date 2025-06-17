class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> lastSeen;
        int minLen = INT_MAX;

        for (int j = 0; j < cards.size(); j++) {
            if (lastSeen.find(cards[j]) != lastSeen.end()) {
                minLen = min(minLen, j - lastSeen[cards[j]] + 1);
            }
            lastSeen[cards[j]] = j;
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};
