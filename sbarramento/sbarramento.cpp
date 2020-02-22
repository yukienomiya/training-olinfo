#include <fstream>
#include <iostream>

using namespace std;

// swaps the element i and i + 1 in the array with j and j + 1
void swapa(int &i, int &j) {
  int c = i;
  i = j;
  j = c;
}

void sortas(int arr[][2], int begin, int end) {
  int i = begin;
  while (i < end - 1) {
    if (arr[i][1] < arr[i + 1][1]) i++;
    else if (arr[i][1] == arr[i + 1][1] && arr[i][0] < arr[i + 1][0]) i++;
    else {
      swapa(arr[i][0], arr[i + 1][0]);
      swapa(arr[i][1], arr[i + 1][1]);
      i = begin;
    }
  }
}

int distance(int x1, int y1, int x2, int y2) {
  return (abs(x1 - x2) + abs(y1 - y2));
}

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int N, R;
  fin >> N >> R;

  int pair[N][2];

  for (int idx = 0; idx < N; idx++) {
    fin >> pair[idx][0] >> pair[idx][1];
  }

  sortas(pair, 0, N);


  int dist = 0;
  for (int i = 0; i < N; i++) {
    dist += distance(R, i + 1, pair[i][0], pair[i][1]);
  }


  fout << dist;
  return 0;
}
