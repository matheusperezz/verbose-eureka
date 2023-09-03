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
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
  int n = nums.size();
  sort(nums.begin(), nums.end());
  set<vector<int>> set;
  vector<vector<int>> output;
  for (int i = 0; i < n - 3; i++)
  {
    for (int j = i + 1; j < n - 2; j++)
    {
      long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
      int low = j + 1, high = n - 1;
      while (low < high)
      {
        if (nums[low] + nums[high] < newTarget)
        {
          low++;
        }
        else if (nums[low] + nums[high] > newTarget)
        {
          high--;
        }
        else
        {
          set.insert({nums[i], nums[j], nums[low], nums[high]});
          low++;
          high--;
        }
      }
    }
  }
  for (auto it : set)
  {
    output.push_back(it);
  }
  return output;
}