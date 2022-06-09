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
    
    int vers[numVer][2];
    int distance[numVer];
    int prev[numVer];
    
    int i = 0;
    for(int v = 0; v < 20; v++){
        if(vertex[v] != 0){
        vers[i][0] = vertex[v];
            i++;
        }
    }
    
    for(int c = 0; c < numVer; c++){
        vers[c][1] = 0;
        if(vers[c][0] == start){
            distance[c] = 0;
        }else{
            distance[c] = 2147483647;
        }
    }
    
    distance[0] = 5;
    distance[1] = 2;
    distance[2] = 3;
    distance[3] = 1;
    
    vers[3][1] = 5;
    
    //actual algotithim
    /*for(int f = 0; f < numVer; f++){
        
        cout << "imp stuff" << endl;
            for(int c = 0; c < numVer; c++){
        cout << vers[c][0] << " " << vers[c][1] << endl;
        cout << distance[c] << endl;
    }*/
        //choose unvisited vertix with least distance
        int temp = distance[0];
        int key;
        for(int p = 0; p < numVer; p++){
            cout << "temp: " << temp << endl;
            cout << "the vertex I am checking is: " << vers[p][0];
            cout << "visit staus is: " << vers[p][1] << endl;
            cout << "distance is " << distance[p] << endl;
            if(vers[p][1] == 0){
                cout << "inside if because visit = 0" << endl;
                cout << temp " >? " distance[p] << endl;
                if(temp > distance[p]){
                    cout << "inside again because temp biiger than dist" << endl;
                    temp = distance[p];
                    key = p;
                }
            cout << "the key is " << key << endl;
            }
        }
        
        vers[key][1] = 1;
        cout << "the node with smallest distance was: " << vers[key][0] << endl;
        cout << "the distance of the node is: " << distance[key] << endl;
        
        
    }
    
    /*cout << "final" << endl;
    for(int c = 0; c < numVer; c++){
        //cout << vers[c][0] << " " << vers[c][1] << endl;
        cout << distance[c] << endl;
    }*/
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
            dijkstra(9);
    }
  }
}
