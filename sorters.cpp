#include <algorithm>
#include <iostream>
#include <limits>
#include <math.h>
#include <random>
#include <string>
#include "output.h"
#include "random.h"
using std::cout;
using std::endl;
using std::sort;
using std::random_device;
using std::string;
using std::numeric_limits;


/*
  Swap array elements
*/
void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

/*
  Because min_max_sort was too slow for 10M elements,
  The following well-known approach is faster:
  1. Choose any value v in the array
  2. iterate through the array
    if an element is less than or equal the chosen v,
    swap it with the leftmost element that is greater than v
  3. After iterating through the array, there will be a split
   marked by the position of v
  4. All elements to the left of v are smaller, elements to the right are larger
  5. Recursively sort the left and right sides of v,
    choosing new v's for the smaller arrays
*/
void quicksort(double arr[], int min, int max)
{
    // If the array length is 1, return
    if (min >= max) {
      return;
    }

    // We will choose any v (last element for convenience)
    double v = arr[max];

    // Tracks the leftmost element that is greater than v
    int track = min;

    for (int i = min; i <= max; i++)
    {
        // When an element which is less or equal to v is found
        if (arr[i] <= v)
        {
            // Swap the element less than v, with the leftmost element greater than v
            swap(&arr[track], &arr[i]);

            // Increment the tracker
            track++;
        }
    }
    quicksort(arr, min, track-2);
    quicksort(arr, track, max);
}

/*
  Because we are dealing with a range of integers
  that is orders of magnitude smaller than the number of elements here,
  just count the number of times each integer appears in the large array,
  then set the value of that many elements to that integer in the output.
*/
void program_a(int size, string filename) {
  /*
    Generate random numbers here
  */
  cout << "Generating random numbers..." << endl;
  int * int_arr = new int[size];
  for (int i = 0; i < size; i++) {
    random_device rd;
    int_arr[i] = random_int(rd());
  }
  cout << "Done!" << endl;

  /*
    Count the number of times each integer appears in the random number array
  */
  cout << "Sorting..." << endl;
  int min = INT_MINIMUM; // defined in random.h as 0
  int max = INT_MAXIMUM; // defined in random.h as 99999
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

/*
  Because of the 5-decimal place limit, the implementation of
  Program B is the same as Program A
  1. Generate 10M floating points
  2. Multiply 10K to each floating point, truncate, then convert to integer type
  3. Use the same counting method in Program A to sort the integers
  4. Format the output so the integers will look like floats (prepend '0.' and leading zeros)
*/
void program_b(int size, string filename) {
  /*
    Generate random floating points here
  */
  cout << "Generating random floating points..." << endl;
  int * int_arr = new int[size];

  for (int i = 0; i < size; i++) {
    random_device rd;
    int_arr[i] = (int) trunc(random_double(rd()) * 100000); // Truncate at 5 decimal places
  }
  cout << "Done!" << endl;

  cout << "Sorting..." << endl;
  int min = 0;
  int max = 99999; // in this case 99999 or 0.99999 * 100000
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
  output_int_format(int_arr, size, filename); // Format the output by appending '0.' and leading zeros
  cout << "Done!" << endl;

  cout << "Cleaning up..." << endl;
  delete[] int_arr;
}


void program_c(int size, string filename) {
  /*
    Generate random floating points here
  */
  cout << "Generating random floating points..." << endl;
  double * double_arr = new double[size];
  for (int i = 0; i < size; i++) {
    random_device rd;
    double_arr[i] = random_double(rd());
  }
  cout << "Done!" << endl;

  cout << "Sorting..." << endl;
  quicksort(double_arr, 0, size - 1);
  cout << "Done!" << endl;

  /*
    Write the output to a file
  */
  cout << "Writing output..." << endl;
  output_double(double_arr, size, numeric_limits<double>::max_digits10, filename); // set precision to max
  cout << "Done!" << endl;

  cout << "Cleaning up..." << endl;
  delete[] double_arr;

}

/*
  std::sort
*/
void default_sort(int size, string filename) {
  /*
    Generate random numbers here
  */
  cout << "Generating random numbers..." << endl;
  int * int_arr = new int[size];
  for (int i = 0; i < size; i++) {
    std::random_device rd;
    int_arr[i] = random_int(rd());
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

/*
  Passes through the array and find the min and max values
  Puts the min value in the first element and the max value in the last element
  Decrement the range to pass (start index + 1, last index - 1)
  Repeat the process
  This approach however is very slow for n = 10M
*/
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

void program_c_min_max(int size, string filename) {
  /*
    Generate random floating points here
  */
  cout << "Generating random floating points..." << endl;
  double * double_arr = new double[size];
  for (int i = 0; i < size; i++) {
    random_device rd;
    double_arr[i] = random_double(rd());
  }
  cout << "Done!" << endl;

  cout << "Sorting..." << endl;
  sort_min_max(double_arr, 0, size);
  cout << "Done!" << endl;

  /*
    Write the output to a file
  */
  cout << "Writing output..." << endl;
  output_double(double_arr, size, numeric_limits<double>::max_digits10, filename);
  cout << "Done!" << endl;

  cout << "Cleaning up..." << endl;
  delete[] double_arr;
}
