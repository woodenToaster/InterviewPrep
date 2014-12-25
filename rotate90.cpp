//Given an image represented by an NxN matrix, where each pixel
//in the image is 4 bytes, write a method to rotate the image by
//90 degrees.  Can you do this in place?

void rotate90(int** m, int n) {
  if(n <= 1) {
    return;
  }
  
  int *row0 = new int[n];
  for(int i = 0; i < n; i++) {
    row0[i] = m[0][i]; 
  }

  int *colN = new int[n];
  for(int i = 0; i < n; i++) {
    colN[i] = m[i][n-1];
  }

  int *rowN = new int[n];
  for(int i = 0; i < n; i++) {
    rowN[i] = m[n-1][i];
  }

  int *col0 = new int[n];
  for(int i = 0; i < n; i++) {
    col0[i] = m[i][0];
  }

  for(int i = 0; i < n; i++) {
    m[i][n-1] = row0[i];
  }

  for(int i = 0; i < n; i++) {
    m[n-1][i] = colN[n - i - 1];
  }

  for(int i = 0; i < n; i++) {
    m[i][0] = rowN[i];
  }

  for(int i = 0; i < n; i++) {
    m[0][i] = col0[i];
  }
  
  delete[] row0;
  delete[] col0;
  delete[] rowN;
  delete[] colN;

  rotate90(m, n - 2);
}