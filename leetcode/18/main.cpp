#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

/**
 *
 *  4 Sum
 * 
 *  Input example
 * 
 *  Input: nums = [1,0,-1,0,-2,2], target = 0
 *  Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 *
 *  Input: nums = [2,2,2,2,2], target = 8
 *  Output: [[2,2,2,2]]
 *
 * 
**/
vector<vector<int>> fourSum(vector<int>& nums, int target) {
  vector<vector<int>> result;
  int n = nums.size();

  if (n < 4) {
    return result;
  }

  sort(nums.begin(), nums.end());

  for (int i = 0; i < n - 3; ++i) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue; // Skip duplicates
    }

    for (int j = i + 1; j < n - 2; ++j) {
      if (j > i + 1 && nums[j] == nums[j - 1]) {
        continue; // Skip duplicates
      }

      int left = j + 1;
      int right = n - 1;

      while (left < right) {
        int sum = nums[i] + nums[j] + nums[left] + nums[right];

        if (sum == target) {
          result.push_back({nums[i], nums[j], nums[left], nums[right]});
          while (left < right && nums[left] == nums[left + 1]) left++; // Skip duplicates
          while (left < right && nums[right] == nums[right - 1]) right--; // Skip duplicates
          left++;
          right--;
        } else if (sum < target) {
          left++;
        } else {
          right--;
        }
      }
    }
  }

  return result;
}

int main(){
  
  vector<int> somenums = {-2,-1,-1,1,1,2,2};
  int target = 0;
  
  vector<vector<int>> s = fourSum(somenums, target);
  
  for (const auto& vec : s){
    for (int n : vec){
      cout << n << " ";
    }
    cout << endl;
  }
  
  return 0;
}