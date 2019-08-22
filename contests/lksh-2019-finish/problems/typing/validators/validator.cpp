#include "testlib.h"

using namespace std;

const int SIGMA = 26;
const int MIN_COST = 0;
const int MAX_COST = 1000;
const int MIN_S_LEN = 1;
const int MAX_S_LEN = 100 * 1000;

int main() {
  registerValidation();

  for (int kb_i = 0; kb_i < 2; ++kb_i) {
    for (int cost_i = 0; cost_i < SIGMA; ++cost_i) {
      inf.readInt(MIN_COST, MAX_COST, "cost");
      if (cost_i + 1 < SIGMA) {
        inf.readSpace();
      } else {
        inf.readEoln();
      }
    }
  }
  inf.readToken(format("[a-z]{%d,%d}", MIN_S_LEN, MAX_S_LEN), "s");
  inf.readEoln();
  inf.readEof();
  return 0;
}
