
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int> &arr, int target) {
        if (target < 0) return 0;

        int result = 0;
        int left = 0;
        int size = arr.size();
        int currentSum = 0;
        
        int right = 0;
        while (right < size) {
            currentSum += arr[right];

            while (left < size && currentSum > target) {
                currentSum -= arr[left];
                left++;
            }

            result += (right - left + 1);
            right++;
        }

        return result;
    }

    int numSubarraysWithSum(vector<int>& arr, int target) {
        return countSubarrays(arr, target) - countSubarrays(arr, target - 1);
    }
};
