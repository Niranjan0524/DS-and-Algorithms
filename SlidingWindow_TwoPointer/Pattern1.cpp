#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& arr, int flips) {
        
        int zeroCnt = 0;
        int maxLen = 0;
        int left = 0;
        int n = arr.size();

        for(int right = 0; right < n; right++) {
            if(arr[right] == 0) {
                zeroCnt++;
            }

            if(zeroCnt > flips) {
                while(zeroCnt != flips) {
                    if(arr[left] == 0) {
                        zeroCnt--;
                    }
                    left++;
                }
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
