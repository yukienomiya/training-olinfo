#include <fstream>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n;
  fin >> n;
  
  int x;
  long long count = 0;
  int lastBought = 0;
  for (int i = 0; i < n; i++) {
    fin >> x;
    if (x > lastBought) {
      count += x;
      lastBought = x;
    }
  }
  
  fout << count;
  return 0;
}