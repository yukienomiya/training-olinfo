#include <fstream>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int N, M, K;
  fin >> N >> M >> K;

  // creates the vector and inserts the input values
  int V[N + 1];
  for (int i = 0; i < N; i++) {
    fin >> V[i];
  }
  V[N] = K;

  int count = 0;
  int currentGas = M - V[0];  //amount of gas (in km) currently in the tank
  for (int i = 0; i < N; i++) {
    int distance = V[i + 1] - V[i];
    if (distance > currentGas) {  //if the current gas amount isn't enough to make it to the next stop
      count++;
      currentGas = M - distance;
    }
    else {
      currentGas -= distance;
    }
  }
  fout << count;
  return 0;
}
