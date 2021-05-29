//
// Created by Bytedance on 2021/5/29.
//

#include "vector"
#include <iostream>

using namespace std;

class Solution {
public:
  int totalHammingDistance(vector<int> &nums) {
    int cnt[32];
    memset(cnt, 0, sizeof(cnt));
    for (int num : nums) {
      for (int j = 0; j < 32; j++) {
        if (num & (1 << j)) {
          cnt[j]++;
        }
      }
    }
    int res = 0;
    int size = int(nums.size());
    for (int v : cnt) {
      res += (v) * (size - v);
    }
    return res;
  }
};

//int main() {
//  Solution s = Solution();
//  vector<vector<int>> cases;
//  cases.push_back({4, 14, 2});
//  cases.push_back({4, 14, 4});
//  cases.push_back({11114, 14, 4});
//  cases.push_back({12345678, 14, 4});
//  for (vector<int> c : cases) {
//    int res = s.totalHammingDistance(c);
//    cout << res << endl;
//  }
//  return 0;
//}
