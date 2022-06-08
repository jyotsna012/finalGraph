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

void dijkstra(int start){
    int numVer;
    for(int a = 0; a < 20; a++){
        if(vertex[a] != 0){
        numVer++;
        }
    }
    
    cout << "total number of vers: " << numVer << endl;
    int vers[numVer];
    
    for(int v = 0; v < 20; v++){
        if(vertex[v] != 0){
        cout<<vertex[v]<<endl;
        }
    }
}

int main(){
  bool loop = true;
  while(loop == true){
    int input;
    cout << "type 0 to print, type 1 to add a vertex, type 2 to add a edge, type 3 to delete a vertex, type 4 to remove an edge, type 5 to find shortest path, and type 6 to quit" << endl;
    cin >> input;
    
    if(input == 1){
      int name;
      cout << "name your vertex a number from 1 - 20" << endl;
      cin >> name;
      if(vertex[name-1] != 0){
       cout << "this name is taken, try again and choose another name between 1-20" << endl;
      }
      else{
        vertex[name-1] = name;
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
            aMatrix[fv-1][sv-1] = w;
        }
    }else if(input == 3){
        int del;
        cout << "enter name of vertex to delete" << endl;
        cin >> del;
        if(vertex[del] == 0){
            cout << "vertex does not exisist to delete" << endl;
        }else{
            vertex[del] = 0;
            for(int d = 0; d < 20; d++){
                aMatrix[del-1][d] = 0;
            }
            for(int d = 0; d < 20; d++){
                aMatrix[d][del-1] = 0;
            }
        }
            
    }else if(input == 4){
        int fv;
        int sv;
        cout << "enter the first vertex of the connection you want to delete" << endl;
        cin >> fv;
        cout << "enter the second vertex of the connection you want to delete" << endl;
        cin >> sv;
        if(aMatrix[fv-1][sv-1] == 0){
        cout << "none to delete" << endl;
        }
        else{
        aMatrix[fv-1][sv-1] = 0;
        }
    
        
    
    }else if(input == 0){
        print();
    }else if(input == 5){
            dijkstra(1);
    }
  }
}
