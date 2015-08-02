/**
    Given a set of distinct integers, nums, return all possible subsets.

    Note:
    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.
    For example,
    If nums = [1,2,3], a solution is:

    [
      [3],
      [1],
      [2],
      [1,2,3],
      [1,3],
      [2,3],
      [1,2],
      []
    ]
*/

#include <bits/stdc++.h>
using namespace std;

///Method 1 (Backtracking)
void genSubsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs) {
    subs.push_back(sub);
    for (int i = start; i < nums.size(); i++) {
        sub.push_back(nums[i]);
        genSubsets(nums, i + 1, sub, subs);
        sub.pop_back();
    }
}
vector<vector<int>> subsetsb(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> subs;
    vector<int> sub;
    genSubsets(nums, 0, sub, subs);
    return subs;
}

///Method 2 (Iterative)
vector<vector<int>> subsetsi(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> subs(1, vector<int>());
    for (int i = 0; i < nums.size(); i++) {
        int n = subs.size();
        for (int j = 0; j < n; j++) {
            subs.push_back(subs[j]);
            subs.back().push_back(nums[i]);
        }
    }
    return subs;
}

///Method 3 (Bit Manipulation)
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int nos = pow(2, nums.size());
    for(int i=0; i<nos; i++){
        vector<int> temp;
        for(int j=0; j<nums.size(); j++){
            bool bit = (i>>j)&1;
            if((i>>j)&1) temp.push_back(nums[j]);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main() {

    vector<int> nums={1,3,2};
    vector<vector<int>> ans={{3},{1},{2},{1,2,3},{1,3},{2,3},{1,2},{}};
    vector<vector<int>> a=subsets(nums);
    sort(a.begin(), a.end());
    sort(ans.begin(), ans.end());
    assert(a==ans);

	return 0;
}
