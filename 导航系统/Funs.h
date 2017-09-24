/*

  操作地图的相关方法定义

  这些方法独立于地图外部，不依赖于地图类


  */
#include<iostream>

#include<string>

using namespace std;

#include "data.h"

#include "GraphClass.h"

/*----------------------------------------------------------------------------

  相关变量的定义
  ----------------------------------------------------------------------------*/

//菜单选择变量定义

int choice ; 


//景点编号定义

int spotNum;

string  spotName ; 

string  spotInfo;

//定义两个景点编号

int spotNum1 ; 

int spotNum2 ; 

//路径上允许经过的最大景点个数

#define maxSpotCount 8

//定义一个全局数组，标记是否已经被访问过

int visited[viewSpotCount+1];

//定义两个开始景点与结束景点

int startSpot , endSpot;

//相关方法的声明

template <typename T>

void paths(GraphClass<T> & , int  , int  , int []);

template <typename T>

void allPath(GraphClass<T> & , int  , int );

/*-----------------------------------------------------------------------------
  相关方法的定义

  -----------------------------------------------------------------------------*/

//地图的初始化

//景点数据的初始化

void init1(){
   
viewSpots[1].viewSpotNum = 1;
viewSpots[1].viewSpotName = "学府苑";
viewSpots[1].viewSpotIntroduction = "";

viewSpots[2].viewSpotNum = 2;
viewSpots[2].viewSpotName = "檀香苑";
viewSpots[2].viewSpotIntroduction = "";

viewSpots[3].viewSpotNum = 3;
viewSpots[3].viewSpotName = "象山苑";
viewSpots[3].viewSpotIntroduction = "";

viewSpots[4].viewSpotNum = 4;
viewSpots[4].viewSpotName = "象山食堂";
viewSpots[4].viewSpotIntroduction = "";

viewSpots[5].viewSpotNum = 5;
viewSpots[5].viewSpotName = "亚青村";
viewSpots[5].viewSpotIntroduction = "";

viewSpots[6].viewSpotNum = 6;
viewSpots[6].viewSpotName = "仁智楼";
viewSpots[6].viewSpotIntroduction = "";

viewSpots[7].viewSpotNum = 7;
viewSpots[7].viewSpotName = "同和楼";
viewSpots[7].viewSpotIntroduction = "";

viewSpots[8].viewSpotNum = 8;
viewSpots[8].viewSpotName = "工大小书房";
viewSpots[8].viewSpotIntroduction = "";

viewSpots[9].viewSpotNum = 9;
viewSpots[9].viewSpotName = "江苏省工业技术创新中心";
viewSpots[9].viewSpotIntroduction = "";

viewSpots[10].viewSpotNum = 10;
viewSpots[10].viewSpotName = "国家生化技术研究中心";
viewSpots[10].viewSpotIntroduction = "";

viewSpots[11].viewSpotNum = 11;
viewSpots[11].viewSpotName = "北苑";
viewSpots[11].viewSpotIntroduction = "";

viewSpots[12].viewSpotNum = 12;
viewSpots[12].viewSpotName = "逸夫图书馆";
viewSpots[12].viewSpotIntroduction = "";

viewSpots[13].viewSpotNum = 13;
viewSpots[13].viewSpotName = "天工楼";
viewSpots[13].viewSpotIntroduction = "";

viewSpots[14].viewSpotNum = 14;
viewSpots[14].viewSpotName = "垒球场";
viewSpots[14].viewSpotIntroduction = "";

viewSpots[15].viewSpotNum = 15;
viewSpots[15].viewSpotName = "重点实验室";
viewSpots[15].viewSpotIntroduction = "";

viewSpots[16].viewSpotNum = 16;
viewSpots[16].viewSpotName = "东苑";
viewSpots[16].viewSpotIntroduction = "";

viewSpots[17].viewSpotNum = 17;
viewSpots[17].viewSpotName = "西苑";
viewSpots[17].viewSpotIntroduction = "";

viewSpots[18].viewSpotNum = 18;
viewSpots[18].viewSpotName = "生物与制药学院";
viewSpots[18].viewSpotIntroduction = "";

viewSpots[19].viewSpotNum = 19;
viewSpots[19].viewSpotName = "研究院";
viewSpots[19].viewSpotIntroduction = "";

viewSpots[20].viewSpotNum = 20;
viewSpots[20].viewSpotName = "能源学院";
viewSpots[20].viewSpotIntroduction = "";

viewSpots[21].viewSpotNum = 21;
viewSpots[21].viewSpotName = "田径场";
viewSpots[21].viewSpotIntroduction = "";

viewSpots[22].viewSpotNum = 22;
viewSpots[22].viewSpotName = "浦江宿舍";
viewSpots[22].viewSpotIntroduction = "";

viewSpots[23].viewSpotNum = 23;
viewSpots[23].viewSpotName = "体育馆";
viewSpots[23].viewSpotIntroduction = "";

viewSpots[24].viewSpotNum = 24;
viewSpots[24].viewSpotName = "南苑";
viewSpots[24].viewSpotIntroduction = "";

viewSpots[25].viewSpotNum = 25;
viewSpots[25].viewSpotName = "笃行楼";
viewSpots[25].viewSpotIntroduction = "";

viewSpots[26].viewSpotNum = 26;
viewSpots[26].viewSpotName = "文科图书馆";
viewSpots[26].viewSpotIntroduction = "";


viewSpots[27].viewSpotNum = 27;
viewSpots[27].viewSpotName = "沉毅广场";
viewSpots[27].viewSpotIntroduction = "";

viewSpots[28].viewSpotNum = 28;
viewSpots[28].viewSpotName = "浦江教学楼";
viewSpots[28].viewSpotIntroduction = "";

viewSpots[29].viewSpotNum = 29;
viewSpots[29].viewSpotName = "药物研究所";
viewSpots[29].viewSpotIntroduction = "";

viewSpots[30].viewSpotNum = 30;
viewSpots[30].viewSpotName = "工大校门";
viewSpots[30].viewSpotIntroduction = "";

}

void init(){

   

   for(int i = 1; i <= viewSpotCount ; i++){
     
	   for(int j = 1; j <= viewSpotCount ; j++){
	   
		   if(i != j){
		   
			   locations[i][j] = 100000;
		    }
			   
		   else if(i == j){
		        

		       locations[i][j] = 0;
		   } 
			  
	   }
   }

   locations[1][2] = 1000 ;
   locations[1][6] = 500;
   locations[1][8] = 100;
   locations[1][9] = 1500;
   locations[2][3] = 450;

   locations[3][4] = 100;
   locations[4][5] = 150;
   locations[4][11] =1700 ;
   locations[5][11] = 1800;
   locations[6][7] = 50;

   locations[7][12] =300 ;
   locations[8][14] = 800;
   locations[9][10] = 200;
   locations[10][14] =400 ;
   locations[11][16] = 150;

   locations[11][17] = 600;
   locations[11][12] = 200;
   locations[12][13] = 200;
   locations[12][14] = 300;
   locations[14][21] =800 ;

   locations[15][22] = 300;
   locations[16][17] =500 ;
   locations[16][18] = 200;
   locations[17][24] = 1200;
   locations[18][19] = 50;

   locations[19][20] = 60;
   locations[21][22] = 50 ;
   locations[21][23] = 300;
   locations[22][23] = 200;
   locations[24][26] = 600;

   locations[25][27] = 100;
   locations[25][28] = 300;
   locations[27][29] = 200;
   locations[29][30] = 600;
   locations[23][30] = 1200;

   locations[26][30] = 400;
   locations[10][15] = 600;
   locations[18][21] = 400;
   locations[23][28] = 600;
   locations[16][25] = 300;

   for(int a = 1 ; a <= viewSpotCount ; a++){
     
	   for(int b = a ; b <= viewSpotCount ;b++){
	    
            locations[b][a] = locations[a][b];
	   }
   }
   
   init1();
   
   cout<<"\n数据初始化完毕\n";

   
 }



//显示菜单函数定义

void showViewSpot(){

   cout<<"\n\n------------------------------------------------------------------------南京工业大学校园导航系统------------------------------------------------------------------------\n\n";

   cout<<"\n\t\t\t\t\t\t\t\t          欢迎来到南京工业大学\t\t\t\n\n";

   cout<<"\t\t\t\t\t\t\t\t\t       菜单选择\t\t\t\t\n\n\n";

   cout<<"\t\t\t\t\t\t\t   1. 学校景点介绍                   5. 查询景点间最短路径\n\n"; 

   cout<<"\t\t\t\t\t\t\t   2. 景点信息查询                   6. 更改图信息\n\n";

   cout<<"\t\t\t\t\t\t\t   3. 查询游览路线                   7. 打印邻接矩阵\n\n";

   cout<<"\t\t\t\t\t\t\t   4. 查询景点之间可寻路径           8. 退出\n\n\n";

   cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
   

}

//学校景点介绍,这里只是简单介绍

void showSpotInfo(){
   
     int i = 1;
     
     
      
     cout<<"  编号\t\t景点名称\t\t\t简介\t\t\t\n\n";
	 for(; i <= viewSpotCount ; i++){
	 
	   cout<<"  "<<viewSpots[i].viewSpotNum<<"\t\t"<<viewSpots[i].viewSpotName <<"\t\t\t";
	    
       cout<<endl;

	   
	 }

	 cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";


}

//查询图的某一景点的信息

//传入的参数是景点序号

void searchViewSpotInfo(int i){
    
   
    cout<<"\t\t\t\t\t\t\t该景点的相关信息介绍如下: \n";

	cout<<"\n  编号:  \t\t"<<viewSpots[i].viewSpotNum<<endl;

	cout<<"\n  名字:  \t\t"<<viewSpots[i].viewSpotName<<endl;

	cout<<"\n  景点介绍:  \t\t"<<viewSpots[i].viewSpotIntroduction<<"\n\n";

	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
}



//查询一个顶点到其余各顶点的最短路径方法定义


template <typename T>

void Dijkstra(GraphClass<T> &gobj,int v){
	
	T dist[viewSpotCount+1]; //存储最短路径 的数组

	int path[viewSpotCount+1]; //存储该节点的前驱节点

	int S[viewSpotCount+1];   //存储该节点是否被访问过

	int mindis,i,j,u=1,n;

	n = gobj.M.n;
    

   //对数组进行初始化

	for(i = 1 ; i <= n ; i++){
	    
		dist[i] = gobj.M.edges[v][i];

		S[i] = 0;

		if(gobj.M.edges[v][i] < 100000)

			path[i] = v;

		else

			path[i] = -1;
	}

	S[v] = 1;  //把被访问过的节点标记下来

	for( i = 1 ;i < n ; i++){
	
	    mindis = INF;
     
		for(j = 1 ; j <= n ;j++){
		
			if(S[j] == 0 && dist[j] < mindis){   //寻找距离数组里的最小值
			   
				u  = j;

                mindis = dist[j]; 
		
			}
		}

		S[u] = 1;   //把被访问过的节点进行访问
  
        //对数组进行更新

		for(j = 1 ; j <= n ;j++){
		
			if(S[j] == 0){
			  
				if(gobj.M.edges[u][j] < 100000 && dist[u]+gobj.M.edges[u][j] < dist[j]){
			              
					dist[j] = dist[u] + gobj.M.edges[u][j];

					path[j] = u;
				
				}
			}
		
		
		}
	
	}

	DispAllPath(dist,path,S,v,n);

}

template <typename T>

void DispAllPath(T dist[] , int path[] , int S[] , int v ,int n){

    //输出从顶点v出发 的所有最短路径

	int i,j,k;

	int apath[viewSpotCount+1];

	int d;

	for(i = 1 ; i <= n ;i++){
	  
		if(S[i]==1 && i!=v){
		   
			
		
		    d = 0; apath[d] = i;

			k = path[i];

			if(k ==-1)
				cout<<"无路径\n";

			else{
			
				while(k != v){
				 
					d++;

					apath[d] = k;

					k = path[k];
				}

				d++;

				apath[d] = v;

				cout<<apath[d]<<":"<<viewSpots[apath[d]].viewSpotName;

				for(j = d-1 ; j >=0 ; j--)
					cout<<" ---> "<<apath[j]<<":"<<viewSpots[apath[j]].viewSpotName;

				cout<<"\n总路线长度："<<dist[i]<<" m\n";
                
				cout<<endl<<endl;
			
			}
		
		}
	
	
	}

}

//输出地图上某一景点到另一个指定景点的所有路径，并且该路径所经过的地点个数为<=8;

int path[maxSpotCount+1];

template <typename T>

void allPath(GraphClass<T> &gobj , int start ,int end){
     
     
	 for(int j = 1 ; j <= viewSpotCount ; j++ )  visited[j] = 0;

	 visited[start] = 1; 

	 path[1] = start ; 

	 paths(gobj,start,end,1);

}

template <typename T>

void paths(GraphClass<T> &gobj , int start , int end , int n){

    int k = n+1;

	if(path[n] == end && n <= maxSpotCount){
	
		cout<<setw(2)<<path[1]<<": "<<viewSpots[path[1]].viewSpotName;

	   for(int i = 2 ; i <= n ; i++)

		   cout << " ---> " <<setw(2)<< path[i] <<": " <<viewSpots[path[i]].viewSpotName ;
       
	   cout<<endl<<endl;
	   return ;
	
	}

    for(int a = 1 ; a<= viewSpotCount ; a++){
	  
		if(gobj.M.edges[path[n]][a] < 100000 && gobj.M.edges[path[n]][a] != 0 && visited[a] == 0){
		    
			path[k] = a;
		    
			visited[a] = 1 ;

			paths(gobj , start , end , k);   //注意此处定义的函数名字path()与数组名字不可以一样，否则会报这种错误error C2064: term does not evaluate to a function
		    
			visited[a] = 0;
		}
    
		
	} 
}

//查询两个景点之间最短路径方法定义，输出相应的路径点即可

template <typename T>

void searchShortestPath(GraphClass<T> &obj, int start,int end){

    T dist[viewSpotCount+1]; //存储最短路径 的数组

	int path[viewSpotCount+1]; //存储该节点的前驱节点

	int S[viewSpotCount+1];   //存储该节点是否被访问过

	int mindis,i,j,u=1,n;

	n = obj.M.n;
    

   //对数组进行初始化

	for(i = 1 ; i <= n ; i++){
	    
		dist[i] = obj.M.edges[start][i];

		S[i] = 0;

		if(obj.M.edges[start][i] < 100000)

			path[i] = start;

		else

			path[i] = -1;
	}

	S[start] = 1;  //把被访问过的节点标记下来

	for( i = 1 ;i < n ; i++){
	
	    mindis = INF;
     
		for(j = 1 ; j <= n ;j++){
		
			if(S[j] == 0 && dist[j] < mindis){   //寻找距离数组里的最小值
			   
				u  = j;

                mindis = dist[j]; 
		
			}
		}

		S[u] = 1;   //把被访问过的节点进行访问
  
        //对数组进行更新

		for(j = 1 ; j <= n ;j++){
		
			if(S[j] == 0){
			  
				if(obj.M.edges[u][j] < 100000 && dist[u]+obj.M.edges[u][j] < dist[j]){
			              
					dist[j] = dist[u] + obj.M.edges[u][j];

					path[j] = u;
				
				}
			}
		
		
		}
	
	}

	DispAPath(dist,path,S,start,n,end);
}

//输出最短路径

template <typename T>

void DispAPath(T dist[] , int path[] , int S[] , int start , int n, int end){

    //输出从顶点v出发 的所有最短路径

	int j,k;

	int apath[viewSpotCount+1];

	int d;

	if(S[end]==1 && end != start){
		   
		
		    d = 0; apath[d] = end;

			k = path[end];

			if(k ==-1)
				cout<<"无路径\n";

			else{
			
				while(k != start){
				 
					d++;

					apath[d] = k;

					k = path[k];
				}

				d++;

				apath[d] = start;

				cout<<apath[d]<<": "<<viewSpots[apath[d]].viewSpotName;

				for( j = d-1 ; j >=0 ; j--)
					cout<<"--->"<<apath[j]<<": "<<viewSpots[apath[j]].viewSpotName;

				cout<<endl<<endl;
			    cout<<"从  "<<viewSpots[start].viewSpotName<<"  到  "<<viewSpots[end].viewSpotName<<"  最短路径长度为:  "<<dist[end]<<"  m";
		
			}
		
		}
	
}

//修改图的信息，主要是对景点信息的修改

void modifyNode(int num , string name , string info){
   
      viewSpots[num].viewSpotName = name ;

	  viewSpots[num].viewSpotIntroduction = info;

	  cout<<"\n\t\t\t\t\t\t\t\t修改后的景点信息:\n\n";
      
	  cout<<"\n  \t\t编号:  \t\t"<<viewSpots[num].viewSpotNum<<endl;

	  cout<<"\n  \t\t名字:  \t\t"<<viewSpots[num].viewSpotName<<endl;

	  cout<<"\n  \t\t景点介绍: \t"<<viewSpots[num].viewSpotIntroduction<<"\n\n";
      
	  cout<<"\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";

}

//打印图的邻接矩阵
/*
void showMatrix(GraphClass<T> &obj){

   obj.DisMGraph();

}
*/
//查询游览路线,就是对图的广度或深度优先遍历

void searchViewSpotPath(){
 

   
}


//查询景点间的可寻路径

void searchViewSpotPaths(){


}

//处理用户选择方法定义

template <typename T>

void executeChoice(GraphClass<T> &G){
    
     showViewSpot();

    

	 cout<<"\n\n\t\t\t\t\t\t\t\t\t输入选择:  ";  cin >> choice ; 

	 cout<<endl<<endl<<endl;

     while(1){
	    
		 if(choice == 8){
		   break;
		 }

         switch(choice){
		 
		 case 1:
             
			 showSpotInfo();

			 break;

         case 2:
             
             cout<<"\t\t\t\t\t\t\t\t  请输入景点编号:  ";

			 cin >> spotNum;

             cout<<"\n";

			 searchViewSpotInfo(spotNum);

			 break;

         case 3:
             
			 cout<<"\t\t\t\t\t\t\t      请输入起始景点编号:  ";

			 cin >> spotNum;
             
			

			 Dijkstra(G,spotNum);

			 cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
             
             break;

         case 4:
               
			 cout<<"\n\t\t\t\t\t\t\t      请输入开始景点编号:  "; 

			 cin >> spotNum1;

			 cout<<"\n\t\t\t\t\t\t\t      请输入结束景点编号:  "; 
 
			 cin >> spotNum2;

			 cout<<"\n\n";

			 cout<<"  从 "<<spotNum1<<": "<<viewSpots[spotNum1].viewSpotName<<" 到 "<<spotNum2<<": "<<viewSpots[spotNum2].viewSpotName
				 
				 <<" 的所有可行路径:\n\n";

             allPath(G,spotNum1,spotNum2);
			 
			 cout<<"\n\n\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
			 
			 break;

         case 5:
             
             cout<<"\t\t\t\t\t\t\t\t  输入出发点编号:  " ; cin >> startSpot;

			 cout<<"\n\t\t\t\t\t\t\t\t  输入结束点编号:  " ; cin >> endSpot;

			 cout<<"\n\n";
             
			 searchShortestPath(G,startSpot,endSpot);
             
			 cout<<"\n\n\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";


			 break;

         case 6:
              
             cout<<"\t\t\t\t\t\t      请输入需要修改名称景点编号:  "; 

			 cin >> spotNum;

			 cout<<"\n\t\t\t\t\t\t          请输入修改后的景点名称:  ";

			 cin >> spotName ; 

			 cout<<"\n\t\t\t\t\t\t        请输入修改后景点信息介绍:  ";

			 cin >> spotInfo ; 

             modifyNode(spotNum , spotName , spotInfo); 

			 break;
        
         case 7:
             
             G.DisMGraph();

			 cout<<"\n\n\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";

             break;

         default:

			 cout<<"请输入正确的选择\n";
              
			 break;
		 }

         showViewSpot(); 

         cout<<"\n\n\t\t\t\t\t\t\t\t\t输入选择:  ";  cin >> choice ; 

	 cout<<endl<<endl<<endl;
	 }

	 cout<<"您已退出系统\n";
}

  