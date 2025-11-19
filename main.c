#include <stdio.h>

int main(void) {
  int N = 30;  // change at runtime in the debugger is possible
  int countEven = 0, countOdd = 0;
  int countPrime = 0;
  int sum = 0;
  int minPrime = 0, maxPrime = 0;
  

  for (int i = 1; i <= N; ++i) {  // FIXED BUG #1: use <= to include N
    int isPrime = 1;              // FIXED BUG #2: reset isPrime per-iteration
    if (i % 2 == 0)
      countEven++;
    else
      countOdd++;

    if (i >= 2) {
      // primality test
      for (int d = 2; d * d <= i; ++d) {
        if (i % d == 0) {
          isPrime = 0;
          break;
        }
      }
      if (isPrime) {
        countPrime++;
        if (minPrime == 0) minPrime = i;
        if (i > maxPrime) maxPrime = i;
      }
    }
    sum += i;
  }

  // FIXED BUG #3: ensure floating-point division by casting one operand
  double avg = (double)sum / N;
  printf("1..%d: even=%d odd=%d primes=%d sum=%d avg=%.2f\n", N, countEven,
         countOdd, countPrime, sum, avg);
  printf("minPrime=%d maxPrime=%d\n", minPrime, maxPrime);
  return 0;
}
