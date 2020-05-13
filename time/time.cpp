#include <fstream>
#include <vector>
#include <tuple>
#include <iostream>
using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  int h0, m0, h1, m1;
  fin >> h0 >> m0 >> h1 >> m1;

  // the clock has a tuple(hour, minute) for every minute of the day
  vector<tuple<int,int>> clock;
  tuple<int, int> startTime = make_tuple(h0, m0);
  tuple<int, int> endTime = make_tuple(h1, m1);
  int idxStart, idxEnd;
  int h = 0, m = 0;
  for (int i = 0; i < 1440; i++) {
    tuple<int, int> t = make_tuple(h, m);
    if (t == startTime) {
      idxStart = i;
    }
    if (t == endTime) {
      idxEnd = i;
    }
    clock.push_back(t);
    if (m == 59) {
      if (h == 23) {
        h = 0;
      } 
      else {
        h += 1;
      }
      m = 0;
    }
    else {
      m += 1;
    }
  }

  // number of minutes spent sleeping
  int totTime;
  if (idxEnd < idxStart) {
    totTime = 1440 - idxStart + idxEnd;
  }
  else {
    totTime = idxEnd - idxStart;
  }

  int hTot = totTime / 60;
  int mTot = totTime % 60;
  fout << hTot << " " << mTot;
  return 0;
}