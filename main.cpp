#include <iostream>

using namespace std;

  int aMatrix[20][20];

void print()
{
    for (int a = 0; a < 20; a++){
        for (int b = 0; b < 20; b++){
       cout << aMatrix[a][b] << " ";
      }
      cout << endl;
    }
}

int main(){
  print();
}
