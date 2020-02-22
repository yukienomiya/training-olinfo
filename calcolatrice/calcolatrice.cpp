#include <fstream>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  string num;
  fin >> num;
  int size = num.size();
  string newNum = num;

  for (int i = 0; i < size; i++) {
    if (num[size - 1] == '0' || num[i] == '3' || num[i] == '4' || num[i] == '7') {
      newNum = num;
      break;
    }
    else if (num[i] == '6') {
      newNum[size - i - 1] = '9';
    }
    else if (num[i] == '9') {
      newNum[size - i - 1] = '6';
    }
    else {
      newNum[size - i - 1] = num[i];
    }
  }
  if (newNum < num) {
    fout << newNum;
  }
  else {
    fout << num;
  }
  return 0;
}
