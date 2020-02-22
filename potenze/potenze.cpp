#include <fstream>
#include <cmath>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int N;
  fin >> N;

  int minres = 1;
  int sqrtn = floor(sqrt(N));
  for (int m = 2; m <= sqrtn; m++)  {
    int dmax = round(log(N) / log(m));
    for (int d = dmax - 1; d <= dmax; d++) {
      int res = (int)pow (m, d);
      if (res > N) continue;
      if ((N - res) < (N - minres)) {
        minres = res;
      }
    }
  }
  fout << minres;
  return 0;
}
