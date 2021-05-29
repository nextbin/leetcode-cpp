//
// Created by Bytedance on 2021/5/29.
//

#include "vector"
#include <cstdio>
#include <iostream>
#include <utility>

using namespace std;

class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int dp[101][101];
    memset(dp, 0, sizeof dp);
    int i = 0, j = 0;
    int n = int(matrix.size());
    int m = int(matrix[0].size());
    for (const vector<int> &row : matrix) {
      j = 0;
      for (int val : row) {
        dp[i][j] = val;
        if (j > 0) {
          dp[i][j] += dp[i][j - 1];
        }
        if (i > 0) {
          dp[i][j] += dp[i - 1][j];
        }
        if (i > 0 && j > 0) {
          dp[i][j] -= dp[i - 1][j - 1];
        }
        j++;
      }
      i++;
    }
    int res = -(1<<30);
    for (int x1 = 0; x1 < n; ++x1) {
      for (int y1 = 0; y1 < m; ++y1) {
        for (int x2 = x1; x2 < n; ++x2) {
          for (int y2 = y1; y2 < m; ++y2) {
            int val = dp[x2][y2];
            if (x1 > 0) {
              val -= dp[x1 - 1][y2];
            }
            if (y1 > 0) {
              val -= dp[x2][y1 - 1];
            }
            if (x1 > 0 && y1 > 0) {
              val += dp[x1 - 1][y1 - 1];
            }
            if (val <= k && val > res) {
              //              printf("match: x1: %d, y1: %d, x2: %d, y2: %d\n",
              //              x1, y1, x2, y2);
              res = val;
            }
          }
        }
      }
    }
    return res;
  }
};

class TestCase {
public:
  vector<vector<int>> matrix;
  int k;
  int want;
  TestCase(vector<vector<int>> _matrix, int _k, int _want)
      : matrix(std::move(_matrix)), k(_k), want(_want) {}
};

int test() {
  vector<TestCase> cases = {
      TestCase(
          {
              {1, 0, 1},
              {0, -2, 3},
          },
          2, 2),
      TestCase({
          {
              {2, 2, -1},
          },
          3,
          3,
      }),
      TestCase({
          {
              {5, -4, -3, 4},
              {-3, -4, 4, 5},
              {5, 1, 5, -4},
          },
          -2,
          -2,
      }),
  };
  Solution s = Solution();
  for (int i = 0; i < cases.size(); ++i) {
    auto ca = cases[i];
    int res = s.maxSumSubmatrix(ca.matrix, ca.k);
    if (res != ca.want) {
      printf("case fail: %d, got: %d, want: %d\n", i, res, ca.want);
      throw bad_exception();
    }
    cout << res << endl;
  }
  return 0;
}

int main() { return test(); }
