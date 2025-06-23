class Solution {
public:
    string getHint(string secret, string guess) {
        int x = 0, y = 0;
        unordered_map<char, int> secretFreq, guessFreq;

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                x++; // bull
            } else {
                secretFreq[secret[i]]++;
                guessFreq[guess[i]]++;
            }
        }

        for (char d = '0'; d <= '9'; d++) {
            y += min(secretFreq[d], guessFreq[d]); // now correctly outside
        }

        return to_string(x) + 'A' + to_string(y) + 'B';
    }
};
