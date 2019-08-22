#include "testlib.h"
#include <iostream>

using namespace std;

const int SIGMA = 26;
const int MIN_COST = 0;
const int MAX_COST = 1000;
const int MIN_S_LEN = 1;
const int MAX_S_LEN = 100 * 1000;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  for (int kb_i = 0; kb_i < 2; ++kb_i) {
    for (int cost_i = 0; cost_i < SIGMA; ++cost_i) {
      cout << rnd.next(MIN_COST, MAX_COST);
      if (cost_i + 1 < SIGMA) {
        cout << ' ';
      } else {
        cout << endl;
      }
    }
  }
  int s_len = rnd.wnext(MIN_S_LEN, MAX_S_LEN, atoi(argv[1]));
  cout << rnd.next("[a-z]{%d}", s_len) << endl;
  return 0;
}
