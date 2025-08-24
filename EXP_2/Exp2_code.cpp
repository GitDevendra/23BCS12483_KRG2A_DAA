class Solution {
public:
    double myPowUtil(double x, long long n) {
        // Base cases
        if (n == 0) return 1;  // x^0 = 1
        if (n == 1) return x;  // x^1 = x

        // If n is even, use the property: x^n = (x^(n/2)) * (x^(n/2))
        double half = myPowUtil(x, n / 2);
        return (n % 2 == 0) ? half * half : x * half * half;
    }

    double myPow(double x, int n) {
        long long absN = abs(static_cast<long long>(n)); 

        double result = myPowUtil(x, absN);

        return (n < 0) ? 1 / result : result;  // Handle negative powers
    }
};