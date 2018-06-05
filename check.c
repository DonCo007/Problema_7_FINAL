///\file check.c
///\brief C library implementation for checking ciclic graphs.
#include "check.h"
#include <stdio.h>

int cicle_check(int number_matrix, int **a) {

	int root = 0, next_node, marked[10], flag_ciclu = 0, iterator_1, iterator_2;
	
	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
		for (iterator_2 = 0; iterator_2 < number_matrix; iterator_2++) {
			if (a[iterator_2][iterator_2] == 1) { /// check if the main diagonal is 0
				return 1;
			}
			else if ((a[iterator_1][iterator_2] == 1) && (a[iterator_2][iterator_1] == 1)) {/// check if there are cicles betwenn 2 nodes 
				return 1;
			}
		}
	}
	
	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {///in this for we calculate the 1st next_node
		if (a[root][iterator_1] == 1) {///we are using a[root], because the root = 0, we are searching on the line 0 to see if it haves vertices
			next_node = iterator_1;   ///the first vertix founded will become the next_node
			break;
		}
	}
	
	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++)
		marked[iterator_1] = 0; ///the frequency vector marked will pe initialized with 0
	
	while (number_matrix) { ///ciclu infinit de while
		flag_ciclu = 0;
		for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
			if (a[next_node][iterator_1] == 1) {///if we find a vertix onthe line next_node from matrix
				marked[root] = 1; ///it will pe marked as visited
				root = next_node; /// rootul becomes next_node
				next_node = iterator_1; ///next_node becomes iterator_1 (the next line we are searching for)
				flag_ciclu = 1;
				break;
			}
			if (marked[next_node] == 1) {///if next_node is marked, that means we have founded a cicle, so the while ends
				return 1;
			}
		}
		if ((iterator_1 == (number_matrix)) && (flag_ciclu == 0)) {///if iterator_1 = number_matrix and flag_cicle=0, means that the fist for
			marked[root] = 1; ///ended, and it did not done anything in this if, so we do not know if there are more vertices to check
			marked[next_node] = 1; /// this will mark root and next_node as beeing visited (those been a dead end)
			for (iterator_1 = root; iterator_1 >= 0; iterator_1--) { /// we are starting form root, this being the last checked value
				if (flag_ciclu == 1) ///and we are going back until we reach 0 to see if there are any vertices unchecked 
					break;
				for (iterator_2 = 0; iterator_2 < number_matrix; iterator_2++) {
					if ((a[iterator_1][iterator_2] == 1) && (marked[iterator_2] == 0)) {/// this condition will determine if the vertix founded is visited
						root = iterator_1;
						next_node = iterator_2;
						flag_ciclu = 1;
						break;
					}
				}
			}
			if (flag_ciclu == 0) ///if we have not founded any unvisited vertix, that means the graph is acyclic
				return 0;
			marked[root] = 0; ///if we will found a vertix of circle root it will move on a visited value
		}
	}
}
