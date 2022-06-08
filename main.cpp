#include <iostream>

using namespace std;


void print(int aMatrix[][20])
{
    for (int a = 0; a < 20; a++)
    {
    for (int b = 0; b < 20; b++)
      {
       cout << aMatrix[a][b] << " ";
      }
      cout << endl;
    }
}

int main(){
  int aMatrix[20][20];
  print(aMatrix);
}
