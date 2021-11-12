#include <iostream>
#include <vector>
int main() {
  int n, m, k;
  double a,b;
  std::cin >> n >> m >> k >> a >> b;

  std::vector<int> employees(k);
  for (int kI = 0; kI < k; ++kI) {
    std::cin >> employees[kI];
  }

  std::vector<int> floor1(m);
  std::vector<int> floor2(m);
  for (int kI = 0; kI < m; ++kI) {
    std::cin >> floor1[kI] >> floor2[kI];
  }
  double result = 0;
  for (int kI = 1; kI < n; ++kI) {
    result += kI;
  }
  result = result*a + result*b;
  std::cout << result << std::endl;
  return 0;
}
