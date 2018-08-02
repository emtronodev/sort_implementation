#include <algorithm>
#include <string>
#include "output.h"
#include "random.h"
using std::sort;
using std::string;

/*
  Because we are dealing with integers here,
  just count the number of times each integer appears,
  then set the value of that many elements to that integer.
*/
void program_a(int min, int max, int size, string filename) {
  /*
    Generate random numbers here
  */
  int * int_arr = new int[size];
  for (int i = 0; i < size; i++) {
    int_arr[i] = random_int(min, max);
  }

  /*
    Count the number of times each integer appears in the random number array
  */
  int * count_arr = new int[max - min + 1]();
  for (int i = 0; i < size; i++) {
    count_arr[int_arr[i]]++;
  }

  /*
    For each integer, set the value of that many elements of the output array to that integer
  */
  int current_index = 0;
  for (int i = min; i <= max; i++) {
    for (int j = 0; j < count_arr[i - min]; j++) {
      int_arr[current_index] = i;
      current_index++;
    }
  }

  /*
    Write the output to a file
  */
  output_int(int_arr, size, filename);
  delete[] int_arr;
}

/*
  std::sort for runtime benchmarking
*/
void default_sort(int min, int max, int size, string filename) {
  int * int_arr = new int[size];
  for (int i = 0; i < size; i++) {
    int_arr[i] = random_int(min,max);
  }
  sort(int_arr, int_arr + size);
  output_int(int_arr, size, filename);
  delete[] int_arr;
}
