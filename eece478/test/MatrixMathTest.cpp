#include "MatrixMath.h"

#include <iostream>

using namespace MatrixMath;
using namespace std;

int main()
{
  float in1[] = {3, 6, 7, 2, 5, 9, 12, 3, 45, 5, 23, 33, 6, 7, 12, -4};
  float in2[] = {-34, 55, 13, 45, -7, 5, 34, 33.4, 8, 9, 12, 20, -16, 39, 50, 70};
  float out[16];

  Mat4x4Mult4x4(in1, in2, out);

  cout<<"Multiplication result:"<<endl;

  PrintMat4x4(out);

  cout<<"Inverse of in1 result:"<<endl;
  
  float inv[16];

  InvertMatrix(in1, inv);

  PrintMat4x4(inv);

  cout<<"normalize inv(in1) result:"<<endl;
  
  float norm[16];

  Mat4x4Normalize(inv, norm);

  PrintMat4x4(norm);

  return 0;
}
