/*

  ������ļ�����

  */


#include<iostream>

#include <windows.h>

using namespace std;

#include "Funs.h"

//����һ����ͼ�Ķ������ڲ�����ͼ

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
