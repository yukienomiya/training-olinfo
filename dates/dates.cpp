#include <fstream>

using namespace std;

int daysInTheMonth(int month) {
  if (month == 2) {
    return 28;
  } 
  else if (month == 4 || month == 6 || month == 9 || month == 11) {
    return 30;
  }
  return 31;
}

string getFullYear(string yearStr) {
  int year = stoi(yearStr);
  int l = yearStr.size();
  if (l == 2) {
    return to_string(1900 + year);
  } 
  if (l == 3) {
    return to_string(1000 + year);
  }
  return to_string(year);
}

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  string date;
  fin >> date;

  int res = 0;
  int digits = date.size();

  for (int iD = 1; iD < 3; iD++) {
    int day = stoi(date.substr(0, iD));
    if (day == 0) {
      continue;
    }
    for (int iM = 1; iM < 3; iM++) {
      int month = stoi(date.substr(iD, iM));
      int dOTM = daysInTheMonth(month);
      if (month == 0 || (digits - iD - iM) > 4)
      {
        continue;
      }
      else if (month > 12 || day > dOTM || (digits - iD - iM) == 0)
      {
        break;
      }
      int year = stoi(getFullYear(date.substr(iD + iM)));
      if (year == 0 || year < 1900 || year > 1999) {
        continue;
      }
      res += 1;
    }
  }

  fout << to_string(res);
  return 0;
}