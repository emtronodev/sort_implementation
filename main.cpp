#include <iostream>
#include <string>
#include "sorters.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
/* Define number of values here */
#define ARRAY_SIZE 10000
/* Define min and max limits of integers here */
#define INT_MINIMUM 0
#define INT_MAXIMUM 99999
/* Define min and max limits of doubles here */
#define DBL_MINIMUM 0.0
#define DBL_MAXIMUM 1.0

void a_sort(string filename) {
  program_a(INT_MINIMUM, INT_MAXIMUM, ARRAY_SIZE, filename);
}

void b_sort(string filename) {

}

void c_sort(string filename) {

}

void std_sort(string filename) {
  default_sort(INT_MINIMUM, INT_MAXIMUM, ARRAY_SIZE, filename);
}

int main()
{
  string input;
  cout << "Edgar Marko Trono Programming Test" << endl;
  cout << "Choose a sorting program: " << endl;
  cout << "For Program A, hit \'a\' " << endl;
  cout << "For Program B, hit \'b\' " << endl;
  cout << "For Program C, hit \'c\' " << endl;
  cout << "To use std::sort() from <algorithm>, type \'default\' " << endl;
  cin >> input;

  if (input.compare("a") == 0) {
    string filename = "program_a_output.txt";
    cout << "Running Program A" << endl;
    a_sort(filename);
    cout << "Finished Program A. Output is written in " << filename << endl;

  } else if (input.compare("b") == 0) {
    string filename = "program_b_output.txt";
    cout << "Running Program B" << endl;
    /*
      code here
    */
    cout << "Finished Program B. Output is written in " << filename << endl;

  } else if (input.compare("c") == 0) {
    string filename = "program_c_output.txt";
    cout << "Running Program C" << endl;
    /*
      code here
    */
    cout << "Finished Program C. Output is written in " << filename << endl;

  } else if (input.compare("default") == 0) {
    string filename = "std_sort_output.txt";
    cout << "Running std::sort()" << endl;
    std_sort(filename);
    cout << "Finished std::sort(). Output is written in " << filename << endl;

  } else {
    cout << "Invalid input, please try again." << endl;
  }
}
