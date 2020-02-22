#include <fstream>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int N;
  fin >> N;

  char V[N];
  for (int i = 0; i < N; i++) {
    fin >> V[i];
  }

  string testo;
  for (int i = 0; i < N; i++) {
    if ((i <= N - 3) && V[i] == 'P' && V[i + 1] == 'a' && V[i + 2] == 'H') {
      i+= 2;
      continue;
    }
    if ((i <= N - 4) && V[i] == 'T' && V[i + 1] == 'u' && V[i + 2] == 'N' && V[i + 3] == 'Z') {
      i+= 3;
      continue;
    }
    else {
      if ((i >= 3 && (V[i - 3] == 'P' && V[i - 2] == 'a' && V[i - 1] == 'H')) ||
      (i >= 4 && (V[i - 4] == 'T' && V[i - 3] == 'u' && V[i - 2] == 'N' && V[i - 1] == 'Z'))) {
        testo += " ";
      }
      testo += V[i];
    }
  }
  fout << testo;
  return 0;
}
