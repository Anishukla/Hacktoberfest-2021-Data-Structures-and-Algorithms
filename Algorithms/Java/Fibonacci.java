public class Fibonacci {

  /**
   * Fibonacci
   * calculating value of n(th) place in Fibonacci sequence
   * f(n) =f(n-2) + f(n-1)
   * f(0) = 0
   * f(1) = 1
   * 
   * @param {*} n
   * @returns
   */
  public static int getN(int n) {
    if (n == 0 || n == 1) {
      return n;
    } else {
      return getN(n - 1) + getN(n - 2);
    }
  }

  public static void main(String args[]) {
    for (int i = 0; i <= 10; i++) {
      System.out.println(Fibonacci.getN(i));
    }
  }
}