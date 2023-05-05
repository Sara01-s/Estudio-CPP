#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
using namespace std;

typedef long long           ll;
typedef pair<int, int>      ii;
typedef vector<int>         vi;
typedef vector<ii>          vii;
#define INF                 1_000_000_000

// Common memset uses
// memset(memo, -1, sizeof memo);           // initialize DP memoization table with -1
// memset(arr, 0, sizeof arr);              // to clear array of integers

// Common simplifications   
// ans = a ? b : c;                         // if (a) ans = b; else ans = c;
// ans += a;                                // ans + = ans + a;
// index = (index + 1)) % n;                // index++; if (index >= n) index = 0;
// index = (index + (n - 1)) % n;           // index--; if (index <  0) index = n - 1;
// int ans = (int) ((double) d + 0.5);      // round to nearest integer
// ans = min(ans, new_computation);         // min/max shortcut
// alternative: ans <?= new_computation


