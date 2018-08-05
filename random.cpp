#include<random>
#include "random.h"

int random_int(int seed) {
  std::mt19937 engine_int(seed);
  std::uniform_int_distribution<int> dist_int(INT_MINIMUM,INT_MAXIMUM);
  return dist_int(engine_int);
}

double random_double(int seed) {
  std::mt19937 engine_double(seed);
  std::uniform_real_distribution<double> dist_double(DBL_MINIMUM, DBL_MAXIMUM);
  return dist_double(engine_double);
}
