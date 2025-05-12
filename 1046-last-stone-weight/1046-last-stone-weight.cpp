class Solution {
public:
    priority_queue<int,vector<int>,less<int>> maxheap;

    int lastStoneWeight(vector<int>& stones) {
         

        // Push all stones into the maxheap
        for (int num : stones) {
            maxheap.push(num);
        }

        // Process until at most one stone remains
        while (maxheap.size() > 1) {
            int first = maxheap.top(); maxheap.pop();   // heaviest
            int second = maxheap.top(); maxheap.pop();  // second heaviest

            if (first != second) {
                maxheap.push(first - second); // push the result of smashing
            }
        }
            maxheap.push(0);
        return maxheap.top();
        }
    
};