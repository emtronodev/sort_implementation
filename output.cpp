#include<fstream>
#include <limits>
using std::endl;
using std::numeric_limits;
using std::ofstream;
using std::string;

int output_int(int arr[], int size, string filename) {
  ofstream arr_out(filename);
  for (int i = 0; i < size; ++i) {
    arr_out << arr[i] << endl;
  }
  return 0;
}

int output_double(double arr[], int size, string filename) {
  ofstream arr_out(filename);
  arr_out.precision(numeric_limits<double>::max_digits10);
  for (int i = 0; i < size; ++i) {
    arr_out << arr[i] << endl;
  }
  return 0;
}
