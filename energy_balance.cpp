#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int countBalancedSubstrings(const string& s, int start, int end) {
    int count = 0;
    int n = end - start + 1;
    
    // Check all possible substrings in the range [start, end]
    for (int i = start; i <= end; i++) {
        int magneto = 0, cyborg = 0;
        for (int j = i; j <= end; j++) {
            if (s[j] == 'M') magneto++;
            else if (s[j] == 'C') cyborg++;
            
            // If we have equal numbers of M and C, it's balanced
            if (magneto == cyborg && magneto > 0) {
                count++;
            }
        }
    }
    return count;
}

int solve(const string& s) {
    int n = s.length();
    long long totalSum = 0;
    
    // For each pair (l, r) where 1 <= l <= r <= n
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int balanced = countBalancedSubstrings(s, l, r);
            totalSum = (totalSum + balanced) % MOD;
        }
    }
    
    return totalSum;
}

int main() {
    string s;
    cin >> s;
    
    cout << solve(s) << endl;
    
    return 0;
}