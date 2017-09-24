/*

  主入口文件定义

  */


#include<iostream>

#include <windows.h>

using namespace std;

#include "Funs.h"

//定义一个地图的对象，用于操作地图

GraphClass<int> G ;

void createG(){

   G.CreateMGraph(locations,30,40);

   G.CreateGraph(locations,30,40);

}

int main(){
   
   system("mode con:cols=1300 lines=1300");
   system("color 4B");

   init();
   
   createG();
   
  // G.DisGraph();

  // Dijkstra(G,1);

   executeChoice(G);

   /*
  // showViewSpot();
   
   GraphClass<int> G ;

   G.CreateMGraph(locations,30,40);

   G.DisMGraph();

   G.CreateGraph(locations,30,40);

   G.DisGraph();

   Dijkstra(G,1);
*/
cout<<endl;
return 0;
}
