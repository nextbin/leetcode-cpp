//
// Created by Bytedance on 2021/5/29.
//

#include "vector"
#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
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
    int res = 0;
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
            if (val == target) {
              //              printf("match: x1: %d, y1: %d, x2: %d, y2: %d\n",
              //              x1, y1, x2, y2);
              res++;
            }
          }
        }
      }
    }
    return res;
  }
};

int test1074() {
  vector<vector<vector<int>>> cases = {{
                                           {0, 1, 0},
                                           {1, 1, 1},
                                           {0, 1, 0},
                                       },
                                       {
                                           {1, -1},
                                           {-1, 1},
                                       },
                                       {
                                           {111},
                                       }};
  vector<int> wants = {4, 5, 0};
  Solution s = Solution();
  for (int i = 0; i < cases.size(); ++i) {
    auto ca = cases[i];
    int res = s.numSubmatrixSumTarget(ca, 0);
    if (res != wants[i]) {
      printf("case fail: %d, got: %d, want: %d\n", i, res, wants[i]);
      throw bad_exception();
    }
    cout << res << endl;
  }
  return 0;
}
