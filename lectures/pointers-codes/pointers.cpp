#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>

//////////////////////////////////////////////////////////////////////

void two_variables_question() {
  int x = 1;
  int y = 2;
  *(&y + 1) = 3;
  std::cout << &x << "\n";
}

//////////////////////////////////////////////////////////////////////

void unallocated_memory_access() {
  // p_x stores the address of a double
  // not yet specified
  double *p_x;

  // trying to assign 1.0 in an unspecified
  // memory location
  *p_x = 1.0;
}

//////////////////////////////////////////////////////////////////////

void dynamic_allocation() {
  int *x = new int;
  *x = 10;
  delete x;
}

//////////////////////////////////////////////////////////////////////

void dynamic_allocation_array() {
  double *x = new double[10];
  double *y = new double[10];

  for (int i = 0; i < 10; i++) {
    x[i] = double(i);
    y[i] = 2.0 * x[i];
  }

  delete[] x;
  delete[] y;
}

//////////////////////////////////////////////////////////////////////

void matrix_allocation() {
  int rows = 5, cols = 3;
  double **A = new double *[rows];

  for (int i = 0; i < rows; i++) {
    A[i] = new double[cols];
  }

  // you can access the values of the array with
  A[2][4] = 5;

  // At the end: deallocate the memory
  for (int i = 0; i < rows; i++) {
    delete[] A[i];
  }
  delete[] A;
}

//////////////////////////////////////////////////////////////////////

void row_major_allocation() {
  int rows = 5, cols = 3;
  // creates a contiguous memory space
  double *p_a = new double[rows * cols];

  double **A = new double *[rows];
  for (int i = 0; i < rows; i++) {
    A[i] = &p_a[i * rows];
    A[i] = p_a + i * rows;
  }

  // you can access the values of the array with
  A[2][4] = 5;
  // or with
  p_a[2 * rows + 4] = 5;

  // At the end: de-allocate the memory
  delete[] A;
  delete[] p_a;
}

//////////////////////////////////////////////////////////////////////

void safe_alloc() {
  int *p_x = new int;
  assert(p_x != NULL);
}

//////////////////////////////////////////////////////////////////////

int main(int argc, char **argv) {
  two_variables_question();
  unallocated_memory_access();
  dynamic_allocation();
  dynamic_allocation_array();
  matrix_allocation();
  row_major_allocation();
  safe_alloc();
}