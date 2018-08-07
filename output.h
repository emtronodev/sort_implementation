#ifndef OUTPUT_H
#define OUTPUT_H

using std::string;

int output_int(int arr[], int size, string filename);
int output_int_format(int arr[], int size, string filename);
int output_double(double arr[], int size, int prec, string filename);

#endif
