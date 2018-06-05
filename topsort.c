///\file toposort.c
///\brief C library function for topological sorting.
#include "topsort.h"
#include <stdio.h>

void topological_sort(int number_matrix, int **a) {
	///\param iterator_1 internal parameter
    ///\param iterator_2 internal parameter
	///\param iterator_3 internal parameter
	/// indeg is a vector where we will adding the internal degree of each node.
	/// flag is a vector where we will mark the visited nodes.
	/// count is used to count steps until we reach the number_matrix variable.
	
	int iterator_1, iterator_2, iterator_3, indeg[10] = { 0 }, flag[10] = { 0 }, count = 0;
	/// algorithm of adding on indeg vector every internal degree of each node. 
	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++)
		for (iterator_2 = 0; iterator_2 < number_matrix; iterator_2++)
          if(a[iterator_1][iterator_2]==1)
			indeg[iterator_2] ++;

	/// topological sort algorithm
	printf("\nThe topological order is: ");
   	while (count < number_matrix) {
		for (iterator_3 = 0; iterator_3 < number_matrix; iterator_3++) {
            if((indeg[iterator_3]==0) && (flag[iterator_3] == 0)) {
                printf("%d ",iterator_3 + 1);
                flag[iterator_3] = 1;
                break;
            }
		}
			for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
                if(a[iterator_3][iterator_1]==1)
                    indeg[iterator_1] --;
			}

		count++;
	}
}
