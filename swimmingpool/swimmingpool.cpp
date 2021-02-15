#include <fstream>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int size;
  fin >> size;
  int nums[size];
  for (int i = 0; i < size; i++) {
    int x;
    fin >> nums[i];
  }

  int smallest = nums[0];
  int largest = nums[size - 1];
  int res = largest;

  for (int idx = 0; idx < size; idx++) {
    int x = nums[idx];
    int dist1 = x - smallest;
    int dist2 = largest - x;
    int d = max(dist1, dist2);
    if (d < res) {
      res = d;
    }
  }

  fout << res;
  return 0;
}