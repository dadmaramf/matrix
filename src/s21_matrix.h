#ifndef S21_MATRIX_H_
#define S21_MATRIX_H_
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// error handling
#define OK 0
#define IncorrectMatrix 1
#define CalculationError 2

// matrix comparison
#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// support fun
int s21_check_empt(matrix_t A);
int s21_equal_size(matrix_t A, matrix_t B);
int s21_colum_equal_rows(matrix_t A, matrix_t B);
int s21_get_minor_matrix(int rows, int columns, matrix_t A, matrix_t *minor);
double s21_rec_determinant(matrix_t *A);

#endif