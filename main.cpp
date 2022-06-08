#include <iostream>

using namespace std;

int aMatrix[20][20];
int vertex[20];
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
  bool loop = true;
  while(loop == true){
    int input;
    cout << "type 1 to add a vertex, type 2 to add a edge, type 3 to delete a vertex, type 4 to remove an edge, type 5 to find shortest path, and type 6 to quit" << endl;
    cin >> input;
    
    if(input == 1){
      int name;
      cout << "name your vertex a number from 1 - 20" << endl;
      cin >> name;
      if(vertex[name] == 1){
       cout << "this name is taken, try again and choose another name between 1-20" << endl;
      }
      else{
        vertex[name] = 1;
        }
    }else if(input == 6){
        loop = false;
    }else if(input == 2){
        int fv;
        int sv;
        cout << "enter the name of your starting vertex " << endl;
        cin >> fv;
        cout << "enter the name of your second vertex" << endl;
        cin >> sv;
        
        if(vertex[fv] == 0){
            cout << "please add ur starting vertex to the vertex list by typing 1 in the main menu before you crete an edge"  << endl;
        }
        
        if(vertex[sv] == 0){
            cout << "please add ur ending vertex to the vertex list by typing 1 in the main menu before you crete an edge" << endl;
        }
        else if(vertex[fv] == 1 && vertex[sv] == 1){
            int w;
            cout << "what is the weight of the edge" << endl;
            cin >> w;
            aMatrix[sv-1][fv-1] = w;
        }
    }else if()
    
  }
  print();
}
