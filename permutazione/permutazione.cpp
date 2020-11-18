#include <fstream>
#include <cmath>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int k;
  fin >> k;

  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  if (k == 1) {
    fout << alphabet;
    return 0;
  }

  int i = 0;
  int j = 25;
  string res = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int letter = 0;
  bool leftEnd = false;

  for (int idx = 0; idx < floor(k / 2); idx++) {
    res[letter++] = alphabet[i++];
    res[letter++] = alphabet[j--];
  }
  if (k % 2 == 1) {
    res[letter++] = alphabet[i++];
    leftEnd = true;
  }
  if (leftEnd) {
    for (int idx = i; idx < j + 1; idx++) {
      res[letter++] = alphabet[idx];
    }
  }
  else {
    for (int idx = j; idx > i - 1; idx--) {
      res[letter++] = alphabet[idx];
    }
  }
  fout << res;
  return 0;
}