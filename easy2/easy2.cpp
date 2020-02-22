#include <fstream>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int N;
  fin >> N;

  int parimax = -1;

  for (int i = 0; i < N; i++) {
    int n1;
    int n2;
    fin >> n1;
    fin >> n2;
    int somma = n1 + n2;
    if (somma % 2 == 0 && somma > parimax) {
      parimax = somma;
    }
  }
  fout << parimax << "\n";
  return 0;
}
