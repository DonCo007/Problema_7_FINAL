#include <stdio.h>

int cicle_check(int number_matrix, int **a) {
	int root = 0, next_node, marked[10] = { 0 }, flag_cicle = 0, iterator_1, iterator_2, matrix[10][10], road[10], count = 0;
	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++)///we copy the matrix a since i am going to destroy it///
		for (iterator_2 = 0; iterator_2 < number_matrix; iterator_2++)
			matrix[iterator_1][iterator_2] = a[iterator_1][iterator_2];

	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
		for (iterator_2 = 0; iterator_2 < number_matrix; iterator_2++) {
			if (a[iterator_2][iterator_2] == 1) { /// check if the main diagonal is 0///
				return 1;
			}
			else if ((a[iterator_1][iterator_2] == 1) && (a[iterator_2][iterator_1] == 1)) {/// check if there are cicles betwenn 2 nodes ///
				return 1;
			}
		}
	}
	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {///in this for we calculate the 1st next_node///
		if (a[root][iterator_1] == 1) { ///we are using a[root], because root = 0,we are searching on line 0 to see if it haves vertices
			next_node = iterator_1;   ///1-st vertix founded becomes next_node
			break;
		}
	}
	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++)
		marked[iterator_1] = 0; ///the freqvency vector "marked" will be 0 everywhere

	road[count] = root; ///the vector road keeps the value of the root, basicly stores the "road" that the root walks///
	marked[root] = 1; ///we mark the root as being vizited///
	while (number_matrix) { ///infinit cicle while
		flag_cicle = 0;
		for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
			if (a[next_node][iterator_1] == 1) {/// if we find a vertix on line next_node form matrix
				count++; ///we increase the count for the road vector so we can store more values
				road[count] = root; ///road takes the new value of the root
				root = next_node; /// the root becomes next_node
				marked[root] = 1; ///it will mark it as vizited
				next_node = iterator_1; ///next node becomes iterator_1 the next line witch we are searching for)
				flag_cicle = 1;
				break;
			}
			if ((marked[next_node] == 1)) {///if next_node is marked it means that we have founded a cycle, so we will exit the while
				return 1;
			}
		}
		///if iterator_1 = number_matrix and flag = 0 it means that the first for has ended and hadnt found the next node
		if ((iterator_1 == (number_matrix)) && (flag_cicle == 0)) {
			marked[root] = 0;
			for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) { ///we determine if there is any other path to reach the end
				if ((matrix[iterator_1][next_node] == 1) && (iterator_1 != root)) {///if there is we erase the one we already checked
					matrix[root][next_node] = 0;
					break;
				}
			}
			///In the next for we check if the current root has more vertices
			///If it does next_node becomes the value of the next vertex
			for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
				marked[root] = 0; ///we unmark the root since we will check it again later on
				if (matrix[root][iterator_1] == 1) {
					next_node = matrix[root][iterator_1];
					flag_cicle = 1;///we raize the flag so we dont check again for the next vertex
				}
			}
			if (flag_cicle != 1) {
				///if we find no vertex in the previous for we will search for the last node that had more vertices
				///and we will start from cont-1 so we dont check again the node we checked before
				for (iterator_1 = count - 1; iterator_1 > 0; iterator_1--) {
					///we unmark the current root since we will check again and we may find this node again so we don't consider it as being a cicle
					marked[root] = 0;
					/// root takes the value stored last int the vector "road" so we can check if that node had more vertices
					root = road[iterator_1];
					///now we check if the current root has more vertices///
					///if it does the vertex already checked will be erased///
					for (iterator_2 = 0; iterator_2 < number_matrix; iterator_2++) {
						if ((matrix[root][iterator_2] == 1) && (iterator_2 != road[iterator_1 + 1])) {
							matrix[root][road[iterator_1 + 1]] = 0;
							next_node = iterator_2;
							count--; ///we decremet the count since we walked back on the road
							flag_cicle = 1;///we raise the flag so we know that we can stop the for later on
							break;
						}
						else
							count--;
					}
					if (flag_cicle == 1)
						break;
				}
			}
			if (flag_cicle == 0) ///if we did not find any cycle we will return 0;
				return 0;
		}
	}
}
