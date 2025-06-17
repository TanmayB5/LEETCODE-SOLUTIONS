class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char,int> freq;
        int i=0,j=0,maxfreq =0;
        int ans = 0;

        for(int j=0;j<answerKey.size();j++){
            freq[answerKey[j]]++;
            maxfreq = max(maxfreq,freq[answerKey[j]]);

            while((j-i+1)-maxfreq>k){
                freq[answerKey[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};