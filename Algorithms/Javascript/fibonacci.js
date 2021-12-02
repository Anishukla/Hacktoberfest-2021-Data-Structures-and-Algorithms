/**
 * Fibonacci
 * calculating value of n(th) place in Fibonacci sequence
 * f(n) = f(n-2) + f(n-1)
 * f(0) = 0
 * f(1) = 1
 * @param {*} n
 * @returns
 */
function fibonacci(n) {
  if (n == 0 || n == 1) {
    return n;
  } else {
    return fibonacci(n - 2) + fibonacci(n - 1);
  }
}
