#include <fstream>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int N;
  fin >> N;

  // creates the vector and inserts the input values
  int V[N];
  for (int i = 0; i < N; i++) {
    fin >> V[i];
  }

  int count = 1;

  int maximumValue = 0; //valore (effettivo) max tra quelli raggiungibili
  int maximumIndex = 0; //indice di maximumValue

  int i = 0;
  while (i  < N) {
    int maxIndex = i + V[i]; //indice del trampolino più raggiungibilew
    for (int j = i + 1; j <= maxIndex; j++) {
      int effValue = V[j] + j;
      if (effValue > maximumValue) {
        maximumValue = effValue;
        maximumIndex = j;
      }
      else if (effValue == maximumValue) {
        if (j > maximumIndex) {
          maximumIndex = j;
          maximumValue = effValue;
        }
      }
    }
    if (maximumIndex <= N - 1) {
      count++;
      i = maximumIndex - 1;
    }
    else {
      count++;
      i = N;
    }
  }
  fout << count;
  return 0;
}
