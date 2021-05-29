//
// Created by Bytedance on 2021/5/29.
//

#include "cstdio"
#include "map"
#include "vector"
#include <iostream>

using namespace std;

class Solution {
public:
  int countGoodRectangles(vector<vector<int>> &rectangles) {
    int maxLength = 0;
    int rectangleCountWithMaxLength = 0;
    for (auto rectangle : rectangles) {
      int mi = min(rectangle[0], rectangle[1]);
      if (mi < maxLength) {
        continue;
      }
      if (mi == maxLength) {
        rectangleCountWithMaxLength++;
      } else {
        maxLength = mi;
        rectangleCountWithMaxLength = 1;
      }
    }
    return rectangleCountWithMaxLength;
  }
};

int test1725() {
  vector<vector<vector<int>>> cases = {
      {
          {5, 8},
          {3, 9},
          {5, 12},
          {16, 5},
      },
      {
          {2, 3},
          {3, 7},
          {4, 3},
          {3, 7},
      },
      {
          {5, 8},
          {3, 9},
          {3, 12},
      },
      {{999999994, 999999995}},
  };
  vector<int> wants = {3, 3, 1, 1};
  Solution s = Solution();
  for (int i = 0; i < cases.size(); ++i) {
    auto ca = cases[i];
    int res = s.countGoodRectangles(ca);
    if (res != wants[i]) {
      printf("case fail: %d, got: %d, want: %d\n", i, res, wants[i]);
      throw bad_exception();
    }
    cout << res << endl;
  }
  return 0;
}

int main() { return test1725(); }
