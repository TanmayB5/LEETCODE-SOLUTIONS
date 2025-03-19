class Solution {
public:
      bool isHappy(int n) {
        std::unordered_set<int> seen; // Store numbers to detect cycles
        
        while (n != 1 && seen.find(n) == seen.end()) { 
            seen.insert(n);
            int sum = 0;
            
            // Compute the sum of squares of digits
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            
            n = sum; // Update n for next iteration
        }
        
        return n == 1; // If n becomes 1, it's a happy number
    }
};