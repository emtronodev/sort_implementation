#include<fstream>
#include<iomanip>
using std::endl;
using std::ofstream;
using std::string;
using std::setfill;
using std::setw;

int output_int(int arr[], int size, string filename) {
  ofstream arr_out(filename);
  for (int i = 0; i < size; ++i) {
    arr_out << arr[i] << endl;
  }
  return 0;
}

int output_int_format(int arr[], int size, string filename) {
  ofstream arr_out(filename);
  for (int i = 0; i < size; ++i) {
    arr_out << "0." << setfill('0') << setw(5) << arr[i] << endl; // prepend "0." and leading zeros
  }
  return 0;
}

int output_double(double arr[], int size, int prec, string filename) {
  ofstream arr_out(filename);
  arr_out.precision(prec);
  for (int i = 0; i < size; ++i) {
    arr_out << arr[i] << endl;
  }
  return 0;
}
