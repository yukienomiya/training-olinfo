#include <fstream>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int N;
  fin >> N;

  int V[N];
  int max = -1;

  for (int i = 0; i < N; i++) {
    fin >> V[i];
  }
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int somma = V[i] + V[j];
      if (somma % 2 == 0 && somma > max) {
        max = somma;
      }
    }
  }
  fout << max;
  return 0;
}
