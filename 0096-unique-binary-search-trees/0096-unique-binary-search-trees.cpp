class Solution {
public:

    unsigned long long getCatalanDP(int n) {
    // Base cases: C(0) = 1, C(1) = 1
    std::vector<unsigned long long> catalan(n + 1, 0);
    catalan[0] = 1;
    if (n > 0) catalan[1] = 1;

    // Fill the DP table using the recurrence relation
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - 1 - j];
        }
    }

    return catalan[n];
}
    int numTrees(int n) {
        return getCatalanDP(n);
    }
};