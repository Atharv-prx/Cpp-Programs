//Idea of memoization - 
//“If I’ve already solved a subproblem, don’t solve it again—just store it and reuse it.”

#include <iostream>

int fib(int n, int dp[]) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (dp[n] != -1) return dp[n];

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main() {
    int n = 10;
    int dp[100];  // assume max n ≤ 100

    // initialize with -1
    for (int i = 0; i <= n; i++) {
        dp[i] = -1;
    }

    std::cout << fib(n, dp);

    return 0;
}
// Time complexity O(n) due to memoization