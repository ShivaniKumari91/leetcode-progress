
class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();

        vector<pair<int,int>> arr;

        // Store value and original index
        for(int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort in descending order of values
        sort(arr.begin(), arr.end(), greater<pair<int,int>>());

        int i = 0;
        int j = n - 1;

        int maxi = INT_MIN;
        vector<int> ans = {-1, -1};

        while(i < j) {
            int sum = arr[i].first + arr[j].first;

            if(sum == target) {
                int product = arr[i].first * arr[j].first;

                if(arr[i].first > arr[j].first && product > maxi) {
                    maxi = product;
                    ans = {arr[i].second, arr[j].second};
                }

                i++;
                j--;
            }
            else if(sum > target) {
                i++;
            }
            else {
                j--;
            }
        }

        return ans;
    }
};
