// author : @ilimugur 
// Ilim Ugur
#include <bits/stdc++.h>
using namespace std;

long long logExponentiation(long long val, long long exp, long long mod)
{
    /*
     * The algorithm is based on the following equality.
     * `(val) ^ (a + b) = (val ^ a) * (val ^ b)
     * Considers the contribution of the individual bits of
     * `exp` to the result as different values and multiplies
     * them in a compound result.
     * 
     * Utilizes a modulus value, as the result tends to be too
     * large in most practical cases.
     */

    long long a[63] = {val % mod};
    for (int i = 1; i < 63; ++i)
    {
        a[i] = a[i-1] * a[i-1] % mod; // store val ^ (2 ^ i) in a[i]
    }

    long long result = 1LL;
    for (int i = 0; i < 63; ++i)
    {
        if ((exp >> i) & 1LL)
        {
            /*
             * `i`th bit of the exponent is set.
             * a[i] should contribute to the result.
             */
            result = result * a[i] % mod;
        }
    }

    return result;
}

int main()
{
    /*
     * t -> number of testcases
     * 
     * val -> value to exponentiate [0, 2^63-1]
     * exp -> value of exponent [0, 2^63-1]
     * modulus -> base in which to represent the result [0, 2^31-1]
     */
    int t;
    cin >> t;
    while (t--)
    {
        long long val, exp, modulus;
        cin >> val >> exp >> modulus;
        long long result = logExponentiation(val, exp, modulus);
        cout << result << endl;
    }
}
