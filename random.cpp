#include<random>

int random_int() {
  std::random_device rd_int;
  std::mt19937 engine_int(rd_int());
  std::uniform_int_distribution<int> dist_int(0,99999);
  return dist_int(engine_int);
}

double random_double() {
  std::random_device rd_double;
  std::mt19937 engine_double(rd_double());
  std::uniform_real_distribution<double> dist_double(0.0,1.0);
  return dist_double(engine_double);
}
