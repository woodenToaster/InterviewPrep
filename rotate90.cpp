//Given an image represented by an NxN matrix, where each pixel
//in the image is 4 bytes, write a method to rotate the image by
//90 degrees.  Can you do this in place?

void rotate90(int** m, int n) {
  if(n == 1) {
    return;
  }
  //do rotation
  rotate90(m, n - 1);
}