#include <fstream>
#include <vector>
using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  long long int k;
  long long int tot = 0;
  int N;
  fin >> N >> k;
  vector<string> words(N);
  for (int i = 0; i < N; i++) {
    fin >> words[i];
    tot += words[i].length() + 1;
  }

  // if all the words fit in a single line
  if (tot - 1 < k) {
    string res = words[0];
    for (int i = 1; i < N; i++) {
      res += " " + words[i];
    }
    fout << res;
    return 0;
  }

  string res, line = "";
  for (int i = 0; i < N; i++) {
    string space = " ";

    // if space + new word fit in the line
    if (line.length() + 1 + words[i].length() <= k) {
      if (line.length() == 0) {
        space = "";
      }
      res += space + words[i];
      line += space + words[i];
    }

    else {
      if (line.length() > 0) {
        res += "\n" + words[i];
        line = words[i];
      }
      else {
        string word = words[i];
        int idx = 0;
        while (idx < word.length()) {
          for (int j = 0; j < k; j++ ) {
            if (idx == word.length()) {
              break;
            }
            line += word[idx];
            idx++;
          }
          res += line + "\n";
          line = "";
        }
      }
    }
  }
  fout << res;
  return 0;
}
