#include <algorithm>
#include <iostream>
#include <limits>
#include <math.h>
#include <string>
#include "output.h"
#include "random.h"
using std::cout;
using std::endl;
using std::sort;
using std::string;

/*
  Swap array elements
*/
void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

/*
  Because we are dealing with integers here,
  just count the number of times each integer appears,
  then set the value of that many elements to that integer.
*/
void program_a(int min, int max, int size, string filename) {
  /*
    Generate random numbers here
  */
  cout << "Generating random numbers..." << endl;
  int * int_arr = new int[size];
  for (int i = 0; i < size; i++) {
    int_arr[i] = random_int(min, max);
  }
  cout << "Done!" << endl;

  /*
    Count the number of times each integer appears in the random number array
  */
  cout << "Sorting..." << endl;
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
  cout << "Done!" << endl;

  /*
    Write the output to a file
  */
  cout << "Writing output..." << endl;
  output_int(int_arr, size, filename);
  cout << "Done!" << endl;

  /*
    Clean up
  */
  cout << "Cleaning up..." << endl;
  delete[] count_arr;
  delete[] int_arr;
  cout << "Done!" << endl;
}

void sort_min_max(double double_arr[], int start, int end) {
  double tmp = 0.0;
  while (start < end) {
    for (int i = start; i < end; i++) {
      if (double_arr[i] < double_arr[start]) {
        tmp = double_arr[i];
        double_arr[i] = double_arr[start];
        double_arr[start] = tmp;
      } else if (double_arr[i] > double_arr[end - 1]) {
        tmp = double_arr[i];
        double_arr[i] = double_arr[end - 1];
        double_arr[end - 1] = tmp;
      }
    }
    start++;
    end--;
  }
}

void program_c_min_max(double min, double max, int size, string filename) {
  /*
    Generate random floating points here
  */
  cout << "Generating random floating points..." << endl;
  double * double_arr = new double[size];
  for (int i = 0; i < size; i++) {
    double_arr[i] = random_double(min, max);
  }
  cout << "Done!" << endl;
  cout << "Sorting..." << endl;
  sort_min_max(double_arr, 0, size);
  cout << "Done!" << endl;

  /*
    Write the output to a file
  */
  cout << "Writing output..." << endl;
  output_double(double_arr, size, filename);
  cout << "Done!" << endl;

  cout << "Cleaning up..." << endl;
  delete[] double_arr;
}

/*
  Quicksort implementation
  Reference:
    https://medium.com/human-in-a-machine-world/quicksort-the-best-sorting-algorithm-6ab461b5a9d0
*/
void quicksort(double arr[], int l, int r)
{
    // Base case: No need to sort arrays of length <= 1
    if (l >= r)
    {
        return;
    }

    // Choose pivot to be the last element in the subarray
    double pivot = arr[r];

    // Index indicating the "split" between elements smaller than pivot and
    // elements greater than pivot
    int cnt = l;

    // Traverse through array from l to r
    for (int i = l; i <= r; i++)
    {
        // If an element less than or equal to the pivot is found...
        if (arr[i] <= pivot)
        {
            // Then swap arr[cnt] and arr[i] so that the smaller element arr[i]
            // is to the left of all elements greater than pivot
            swap(&arr[cnt], &arr[i]);

            // Make sure to increment cnt so we can keep track of what to swap
            // arr[i] with
            cnt++;
        }
    }

    // NOTE: cnt is currently at one plus the pivot's index
    // (Hence, the cnt-2 when recursively sorting the left side of pivot)
    quicksort(arr, l, cnt-2); // Recursively sort the left side of pivot
    quicksort(arr, cnt, r);   // Recursively sort the right side of pivot
}

void program_c_quick(double min, double max, int size, string filename) {
  /*
    Generate random floating points here
  */
  cout << "Generating random floating points..." << endl;
  double * double_arr = new double[size];
  for (int i = 0; i < size; i++) {
    double_arr[i] = random_double(min, max);
  }
  cout << "Done!" << endl;

  cout << "Sorting..." << endl;
  quicksort(double_arr, 0, size - 1);
  cout << "Done!" << endl;

  /*
    Write the output to a file
  */
  cout << "Writing output..." << endl;
  output_double(double_arr, size, filename);
  cout << "Done!" << endl;

  cout << "Cleaning up..." << endl;
  delete[] double_arr;

}

/*
  std::sort
*/
void default_sort(int min, int max, int size, string filename) {
  /*
    Generate random numbers here
  */
  cout << "Generating random numbers..." << endl;
  int * int_arr = new int[size];
  for (int i = 0; i < size; i++) {
    int_arr[i] = random_int(min,max);
  }
  cout << "Done!" << endl;

  cout << "Sorting..." << endl;
  sort(int_arr, int_arr + size);
  cout << "Done!" << endl;

  /*
    Write the output to a file
  */
  cout << "Writing output..." << endl;
  output_int(int_arr, size, filename);
  cout << "Done!" << endl;

  /*
    Clean up
  */
  cout << "Cleaning up..." << endl;
  delete[] int_arr;
  cout << "Done!" << endl;
}
