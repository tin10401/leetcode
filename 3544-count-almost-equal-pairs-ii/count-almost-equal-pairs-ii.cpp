class Solution {
public:
    unordered_map<string,int>dp;
    string makeDigit(int num, int digits) {//func for digitmakeup
        string s = to_string(num);
        int n = s.size();
        for(int i=0;i<digits-n;i++)
            s = "0" + s;
        return s;
    }
    unordered_map<string,int>getnums(int num,int digits_makeup){
        string s = makeDigit(num,digits_makeup);
        unordered_map<string,int>mp;
        mp[s]++;
        for(int i = 0; i < s.length(); i++){
            for(int j = i + 1; j < s.length(); j++){
                swap(s[i],s[j]);
                mp[s]++;
                for(int k = 0; k < s.length(); k++){
                    for(int l = k + 1; l < s.length(); l++){
                        if(s[k]!=s[l]){
                            swap(s[k],s[l]);
                            mp[s]++;
                            swap(s[k],s[l]);
                        }
                    }
                }
                swap(s[i],s[j]);
            }
        }
        return mp;
    }
    int countPairs(vector<int>& nums) {
        // O(N*49*49) here
        int n=nums.size();
        int digits_makeup = to_string(*max_element(nums.begin(),nums.end())).size();
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(auto s:getnums(nums[i],digits_makeup)){
                if(dp.count(s.first)){
                    ans+=dp[s.first];
                }
            }
            dp[makeDigit(nums[i],digits_makeup)]++;
        }
        return ans;
    }
};