#include <fstream>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int N;
  fin >> N;

  int K;
  fin >> K;

  int value[N];
  for (int i = 0; i < N; i++) {
    fin >> value[i];
  }

  int maxSum = 0;
  int sum;
  for (int i = 0; i <= N - K; i++) {
    sum = 0;
    for (int j = i; j < i + K; j++) {
      sum += value[j];
    }
    if (sum > maxSum) {
      maxSum = sum;
    fout << maxSum << "\n";
    }
    fout << maxSum;
  }
}
