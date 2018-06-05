///\file adjmat.c
///\brief C library implementation for reading a matrix.
#include "adjmat.h"
#include "topsort.h"
#include "check.h"
#include <stdio.h>
#include <stdlib.h>


void adjacency_matrix_in() {
    ///\fn FILE *file_in
	///\brief Opens a file and make it readeble only.
	FILE *file_in;
	file_in = fopen("in.txt", "r");

    ///\param iterator_1
	///\param iterator_2
	///\param number_matrix
	int iterator_1, iterator_2, number_matrix;

    ///\brief Reading the number of lines and collums
	fscanf(file_in, "%d", &number_matrix);

    ///\brief Allocating dynamic a matrix.
	int ** a = (int**)malloc(number_matrix * sizeof(int*));
	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
		a[iterator_1] = (int*)malloc(number_matrix * sizeof(int));
	}


    ///\brief Reading the matrix from file.
	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
		for (iterator_2 = 0; iterator_2 < number_matrix; iterator_2++)
			fscanf(file_in, "%d", &a[iterator_1][iterator_2]);
	}

	///\brief Checking if the matrix is Acyclic
	if(cicle_check(number_matrix, a) == 0)
        topological_sort(number_matrix, a);
    else
        printf("The graph haves cicle.");

	///\brief Freeing the alocated memory
	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
		free(a[iterator_1]);
	}
	free(a);
}
