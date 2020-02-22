#include <fstream>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int N;
  fin >> N;

  int max = -101;
  for (int i = 0; i < N; i++) {
    int n1;
    int n2;
    fin >> n1;
    fin >> n2;
    int sub = n1 - n2;
    if (sub > max) {
      max = sub;
    }
  }
  fout << max;
  return 0;
}
