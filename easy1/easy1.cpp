#include <fstream>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    fin >> N;

    if (N <= 0) {
      return 0;
    }

    int max;
    fin >> max;

    for (int i = 0; i < N - 1; i++) {
      int val;
      fin >> val;
      if (val > max) {
        max = val;
      }
    }
    fout << max << "\n";
    return 0;
}
