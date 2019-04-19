 //There are 5 processes and 3 resource types, resource A with 10 instances, B with 5 instances and C with 7 instances.
 // Find whether the system is in safe state or not?
#include<math.h>
#include<string.h>
#include <stdio.h> 
#include<conio.h>
int main() 
{ 
	// P0, P1, P2, P3, P4 are the Process names here 

	int n, m, i, j, k; 
	n = 5; // Number of processes 
	m = 3; // Number of resources 
	int allocation[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix 
	                	{ 2, 0, 0 }, // P1 
						{ 3, 0, 2 }, // P2 
						{ 2, 1, 1 }, // P3 
						{ 0, 0, 2 } }; // P4 

	int maximum[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix 
					{ 3, 2, 2 }, // P1 
					{ 9, 0, 2 }, // P2 
					{ 2, 2, 2 }, // P3 
					{ 4, 3, 3 } }; // P4 

	int available[3] = { 3, 3, 2 }; // Available Resources 

	int x[n], safe[n];
	for (k=0;k<n;k++)
	{ 
		x[k] = 0; 
	} 
	int needmat[n][m]; 
	for (i=0;i<n;i++) 
	{ 
		for (j=0;j<m;j++) 
			needmat[i][j] = maximum[i][j] - allocation[i][j]; 
	} 
	int y = 0; 
	for (k=0;k<5;k++) 
	{ 
		for (i=0;i<n;i++) 
		{ 
			if (x[i]==0) 
			{ 

				int found = 0; 
				for (j=0;j<m;j++) 
				{ 
					if (needmat[i][j] > available[j]) 
						found= 1; 
					break; 
				} 

				if (found == 0) 
				{ 
					safe[count++] = i; 
					for (y=0;y<m;y++) 
						available[y]= available[y]+allocation[i][y]; 
					x[i] = 1; 
				} 
			} 
		} 
	} 

	printf("Following is the SAFE Sequence\n"); 
	for (i=0;i<n-1;i++) 
		printf(" P%d ->", safe[i]); 
	printf(" P%d", safe[n-1]); 

	return (0); 

} 

