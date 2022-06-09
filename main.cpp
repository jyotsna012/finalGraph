//jyotsna tera
// june 9th
//grapth creator
// Can do the following: add vertex, add edge, remove vertex, remove edge, print, and find smallest distance path


#include <iostream>

using namespace std;

//creates an adjaceny matrix for the graph
int aMatrix[20][20];
//array to store added verticies
int vertex[20];

//print function to print the adjaceny matrix and the vertexes
void print()
{
    //cycles through 2d array and prints each element
    for (int a = 0; a < 20; a++){
        for (int b = 0; b < 20; b++){
       cout << aMatrix[a][b] << " ";
      }
      cout << endl;
    }
    
    cout << endl;
    cout << endl;
    cout << endl;
    
    for (int k = 0; k < 20; k++){
        cout << vertex[k] << endl;
    }
    
}

//function to find the path with the shortest distance
void dijkstra(int start, int end, int end2){
    //goes to vertex array and picks out non 0 elemnts to find how many vertexes there are
    int numVer;
    for(int a = 0; a < 20; a++){
        if(vertex[a] != 0){
        numVer++;
        }
    }
    
    //2d array stores vertex and visit status
    int vers[numVer][2];
    //array to hold the distances
    int distance[numVer];
    //array to hold previpus vertex
    int prev[numVer];
    
    
    for(int vv = 0; vv < 20; vv++){
        prev[vv] = 0;
    }
    
    //moves all non 0 items from vertex array to new vers array so no zeros and only filled spots
    int i = 0;
    for(int v = 0; v < 20; v++){
        if(vertex[v] != 0){
        vers[i][0] = vertex[v];
            i++;
        }
    }
    
    //sets all distances equal to infinty at start excppt the start vertex's
    for(int c = 0; c < numVer; c++){
        vers[c][1] = 0;
        if(vers[c][0] == start){
            distance[c] = 0;
        }else{
            distance[c] = 2147483647;
        }
    }
    
    for(int n = 0; n < numVer; n++){
    }
    
    //actual algotithim
    for(int f = 0; f < numVer; f++){
                
        //choose unvisited vertix with least distance
        
        
        int h = 0;
        while(vers[h][1] != 0){
           h++;
        }
        int temp = distance[h];
        int key = h;
        //finds the smallest distance in the distance array which has an unvisted vector
        for(int p = 0; p < numVer; p++){
            if(vers[p][1] == 0){
                if(temp > distance[p]){
                    temp = distance[p];
                    key = p;
                }
            }
        }
        
        //onces visited, the status changes from 0 to one
        vers[key][1] = 1;
        
        int smallDistVert = vers[key][0];
        
        //check which vertexes this has a connection to
        int index = NULL;
        int connCount = 0;
        //cycles trhough amatrix to see connections
          for(int gg = 0; gg < 20; gg++){
            if(aMatrix[smallDistVert - 1][gg] != 0){
                connCount++;    
            }  
        }
        
        cout << "connectioms: " << connCount << endl;
        
        //adds all connections to an array called connections that also holds edge weight
        int connections[connCount][2];
        int iint = 0;
        for(int g = 0; g < 20; g++){
            if(aMatrix[smallDistVert - 1][g] != 0){
                for(int w = 0; w < numVer; w++){
                    if(vers[w][0] == g+1){
                        if(vers[w][1] != 1){
                        connections[iint][0] = vers[w][0];
                        connections[iint][1] = aMatrix[smallDistVert - 1][g];
                        iint++;
                        }
                    }
                }
            }
        
        }
        
        //finds the distance between connections and of the distance is smaller than what is in
        //the distance array alreayd then the new value is updates
        for(int s = 0; s < connCount; s++){
            for(int w = 0; w < numVer; w++){
                if(vers[w][0] == connections[s][0]){
                    if(distance[w] == 2147483647){
                        distance[w] = connections[s][1];
                         prev[w] = smallDistVert;
                    }else{
                        cout << "in here" << endl;
                        for(int wk = 0; wk < numVer; wk++){
                            if(vers[wk][0] == smallDistVert){
                                int tempDis = distance[wk] + connections[s][1];
                                if(tempDis < distance[w]){
                                   distance[w] = tempDis;
                                    for(int wkk = 0; wkk < numVer; wkk++){
                                        if(vers[wkk][0] == connections[s][0]){
                                           prev[wkk] = smallDistVert;
                                        }
                                    }
                                }
                            }
                        }
                     
                    }
                }
            }
        }
        
        
            for(int l = 0; l < numVer; l++){
    }
    }
    
   
    
    //print the path
    int path[numVer];
        for(int vvv = 0; vvv < numVer; vvv++){
        path[vvv] = 0;
    }
    int pathInt = 0;
    path[pathInt] = end;
    pathInt++;
    int indexInt;
    
    while(end != 0){
    for(int z = 0; z < numVer; z++){
        if(vers[z][0] == end){
            indexInt = z;
        }
    }
    path[pathInt] = prev[indexInt];
    pathInt++;
    end = prev[indexInt];
    }
    
    cout << "the path with the shortest distance is outlined" << endl;
    for(int k = pathInt-1; k >= 0; k--){
        if(path[k] != 0){
        cout << path[k] << endl;
        }
    }
    
    for(int finalInt = 0; finalInt < numVer; finalInt++){
        if(vers[finalInt][0] == end2){
                cout << "the shortest disatnce is: " << distance[finalInt] << endl;
        }
    }
    
    
   
    
}

int main(){
  bool loop = true;
  while(loop == true){
    int input;
    cout << "type 0 to print, type 1 to add a vertex, type 2 to add a edge, type 3 to delete a vertex, type 4 to remove an edge, type 5 to find shortest path, and type 6 to quit" << endl;
    cin >> input;
    
      //adding vertex
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
        //exiting program
    }else if(input == 6){
        loop = false;
        //adding edge
    }else if(input == 2){
        int fv;
        int sv;
        cout << "enter the name of your starting vertex " << endl;
        cin >> fv;
        cout << "enter the name of your second vertex" << endl;
        cin >> sv;
        
        if(vertex[fv-1] == 0){
            cout << "please add ur starting vertex to the vertex list by typing 1 in the main menu before you crete an edge"  << endl;
        }
        
        if(vertex[sv-1] == 0){
            cout << "please add ur ending vertex to the vertex list by typing 1 in the main menu before you crete an edge" << endl;
        }
        else if(vertex[fv-1] != 0 && vertex[sv-1] != 0){
            int w;
            cout << "what is the weight of the edge" << endl;
            cin >> w;
            aMatrix[fv-1][sv-1] = w;
        }
        //deleting vertex
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
           //deleting edge 
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
    
        
    //prints matrix
    }else if(input == 0){
        print();
        //finding shortest distance path
    }else if(input == 5){
         int fv;
        int sv;
        cout << "enter the start vertex" << endl;
        cin >> fv;
        cout << "enter the end vertex" << endl;
        cin >> sv;
            dijkstra(fv, sv,sv);
    }
  }
}
