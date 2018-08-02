#include <iostream>
#include "random.h"
#include "output.h"
#define SIZE 100
using std::endl;
using std::cout;

#include <algorithm>
using std::sort;

int main()
{
  cout << "Edgar Marko Trono STE Programming Test" << endl;
  /*
    Generate random numbers
  */
  int * int_arr = new int[SIZE];
  for (int i = 0; i < SIZE; i++) {
    int_arr[i] = random_int();
  }

  sort(int_arr, int_arr + SIZE);

  output_int(int_arr, SIZE, "presort_int.txt");

  delete[] int_arr;
}
