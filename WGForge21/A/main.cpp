#include <iostream>
#include <vector>
int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<double> t1(n);
  for (int kI = 0; kI < n; ++kI) {
    std::cin >> t1[kI];
  }

  std::vector<double> a(m);
  std::vector<double> s(m);
  std::vector<double> T(m);

  for (int kI = 0; kI < m; ++kI) {
    std::cin >> a[kI] >> s[kI] >> T[kI];
  }

  std::vector<double> numbers;
  double minNumS;
  for (int kI = 0; kI < m; ++kI) {
    int flagG = 1;
    for (int kJ = 0; kJ < m; ++kJ) {
      int flag = 0;
      for (int number : numbers) {
        if(kJ == number){
          flag = 1;
          break;
        }
      }
      if(flag != 1){
        if(flagG == 1){
          minNumS = kJ;
          flagG = 0;
        } else if(s[kJ] <= s[minNumS]){
          minNumS = kJ;
        }
      }
    }
    numbers.push_back(minNumS);

    if((a[minNumS] < n-1) && (a[minNumS] != -1)){
      double tempSumTime = 0;
      for (int kJ = 0; kJ < n-1; ++kJ) {
        tempSumTime += t1[kJ];
        if(s[minNumS] <= tempSumTime){
          if((a[minNumS] + kJ) < (n - 1)){
            t1[a[minNumS] + kJ] += T[minNumS];
            break;
          }
        }
      }
    }
  }

  double sumTime = 0;
  for (int kI = 0; kI < n - 1; ++kI) {
    sumTime += t1[kI];
  }
  std::cout << sumTime << std::endl;
  return 0;
}
