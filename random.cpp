#include<random>

int random_int(int min, int max) {
  std::random_device rd_int;
  std::mt19937 engine_int(rd_int());
  std::uniform_int_distribution<int> dist_int(min,max);
  return dist_int(engine_int);
}

double random_double(double min, double max) {
  std::random_device rd_double;
  std::mt19937 engine_double(rd_double());
  std::uniform_real_distribution<double> dist_double(min, max);
  return dist_double(engine_double);
}
