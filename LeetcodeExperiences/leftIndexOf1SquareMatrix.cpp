given binary matrix M*N size, there is only square matrix with all 1's in this matrix, 
return the position of upper left corner of that 1 submatrix, 
if its size greater >= k.

where k = floor( sqrt(N) );
k = 2
matrix is:

0000
0000
0110
0110

ans would be: ( 2 , 1 ),


Clarifying question - 

1. There is only one square sub-matrix with all 1's right ?
2. Is it sqrt(N) or sqrt(area of Submatrix with all 1's) ?