#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxFreq(unordered_map<char,int> &mp){
        int maxi=0;
        for(auto &[key,val]:mp){
            maxi=max(maxi,val);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        
        int start=0;
        int maxi=0;
        int n=s.size();

        unordered_map<char,int> mp;
        int maxFreq=0;
        for(int end=0;end<n;end++){
            mp[s[end]]++;

            int diff=end-start+1;
            maxFreq=max(mp[s[end]],maxFreq);

            if(diff-maxFreq>k){
                while(diff-maxFreq>k){
                    mp[s[start]]--;
                    maxFreq=findMaxFreq(mp);
                    start++;
                    diff--;
                }
            }
            maxi=max(maxi,end-start+1);
        }

        return maxi;
    }
};