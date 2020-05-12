#include <fstream>
#include <vector>
using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  long long int M;
  int N, last;
  long long int tot = 0;
  fin >> N >> M;
  vector<int> candies(N);
  for (int i = 0; i < N; i++) {
    fin >> candies[i];
    tot += candies[i];
    if (candies[i] != 0) {
      last = i;
    }
    if (tot >= M) {
      fout << last;
      return 0;
    }
  }
  long long int rem = M % tot;

  if (rem > 0) {
    for (int i = 0; i < N; i++) {
      rem -= candies[i];
      if (rem <= 0){
        fout << i;
        break;
      }
    }
  }
  else {
    fout << last;
  }
  return 0;
}