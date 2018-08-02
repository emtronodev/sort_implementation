#include<fstream>
using std::string;
using std::ofstream;
using std::endl;

int output_int(int arr[], int size, string filename) {
  ofstream arr_out(filename);
  for (int i = 0; i < size; ++i) {
    arr_out << arr[i] << endl;
  }
  return 0;
}

int output_double(double arr[], int size, string filename) {
  ofstream arr_out(filename);
  for (int i = 0; i < size; ++i) {
    arr_out << arr[i] << endl;
  }
  return 0;
}
