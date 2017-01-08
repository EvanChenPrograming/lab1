#include<fstream>
#include<iostream>
#include<cstdlib>

#define NODES 8 

int main(){
// open file
  std::ifstream inFile("distance_matrix.txt");
  if(!inFile){
    std::cerr<<"Failed open file distance_matrix.txt."<<std::endl;
  }
  int D[NODES][NODES];
  int P[NODES][NODES];
// initializing P, which is used to store the previous node 
// of the least cost.
  for(int i=0;i<NODES;i++){
    for(int j=0;j<NODES;j++){
      P[i][j]=j;
    }
  }
// read file
  for(int i=0;i<NODES;i++){
    for(int j=0;j<NODES;j++){
      inFile>>D[i][j];
      if(D[i][j]==0)D[i][j]=100000;
    }
  }
  inFile.close();
  
// the Floyd's algorithm
  for(int k=0;k<NODES;++k){
    for(int v=0;v<NODES;++v){
      for(int w=0;w<NODES;++w){
        if(D[v][w]>D[v][k]+D[k][w]){
          D[v][w]=D[v][k]+D[k][w];
          P[v][w]=P[v][k];
        }  
      }
    }
  }
  int start, end; 
  int k, w;
  while(1){
    std::cout<<"Input start and end or -1 to exit.\nstart: ";
    std::cin>>start;
    if(start<0)return 0;
    std::cout<<"end: ";
    std::cin>>end;
    if(end<0)return 0;
    std::cout<<"distance: "<<D[start][end]<<std::endl;
    //find the path according to the P matrix
    while(start!=end){
      std::cout<<start<<"->";
      start=P[start][end];
    }
    std::cout<<end<<std::endl;
  }

}



