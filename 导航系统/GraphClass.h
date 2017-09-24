/*

  南京工业大学校园导航系统，图的头文件定义

  此项目为方便学校学生老师外来者参观时使用

  语言实现：C++

*/


#include <iomanip>

using namespace std;

//顶点的邻接矩阵定义

template <typename T>

struct MGraph{
  
    //存放邻接矩阵的数组定义
    
    //里面存储的是权值，也就是距离值

	T edges[viewSpotCount+1][viewSpotCount+1];
    
    //存放顶点个数

	int n; 
   
	//存放边得数目

    int e; 

};

//定义边节点结构体类型

template <typename T>

struct ArcViewSpot{
  
	T adjvex  ; 

	ArcViewSpot<T> *next;
   
	T weight;
}; 

//定义链表的表头节点

template <typename T>

struct viewSpotStart{
  
	T start;
    
    ArcViewSpot<T> *first; 
};

//图的邻接表类型

template <typename T>

struct graph{
   
	viewSpotStart<T> spots[viewSpotCount+1];  //定义邻接链表的表头数组

	int n;  //节点个数

	int e;  //边的个数

};

//图的链表节点定义
/*

  校园地图类模板的定义

  
  里面包括相关属性与相关方法
*/


template <typename T>

class GraphClass{


  //相关私有属性定义

	private:
        
     graph<T>  *G ;
		

    //相关公有方法定义

	public:
        
		//公有邻接矩阵

		MGraph<T> M;
       
		//构造方法

		GraphClass();

		//析构方法‘

		~GraphClass();

		//创建图的邻接矩阵

		void CreateMGraph( int a[][viewSpotCount+1] , int n , int e );

       //输出图的邻接矩阵

		void DisMGraph();

       //创建图的邻接链表

		void CreateGraph(int a[][viewSpotCount+1], int n , int e);
		
       //输出图的邻接链表

		void DisGraph();

		//获取图的邻接链表的句柄

		graph<T> * getHandle();


};


//类的方法实现

template <typename T>

GraphClass<T>::GraphClass(){

   G = NULL;

}

//析构方法实现

template <typename T>

GraphClass<T>::~GraphClass(){


}

//图的邻接矩阵的初始化

template <typename T>

void GraphClass<T>::CreateMGraph( int a[][viewSpotCount+1] , int n , int e ){

    int i,j;

    M.n = n ; 

	M.e = e;

	for(i = 1 ; i <= n ; i++){
	  
		for(j = 1 ; j <= n ; j++){
		
		  M.edges[i][j] = a[i][j];
		
		}
	
	}

}

//输出图的邻接矩阵

template <typename T>

void GraphClass<T>::DisMGraph(){
   
	int i ,j;
    
    cout<<"\t\t\t\t\t\t\t\t  地图的邻接矩阵: \n\n\n";

	for(i = 1 ; i <= M.n ; i++){
	    
		cout<<"\t";
		for(j = 1 ; j <= M.n ; j++){
		   
			if(M.edges[i][j] == 100000)
				cout<<setw(5)<<"∞" <<setw(5);
		    else
				cout<<setw(5)<<M.edges[i][j]<<setw(5);
		}
	   
		cout<<endl;
	}
    
}

//创建图的邻接链表

template <typename T>

void GraphClass<T>::CreateGraph(int a[][viewSpotCount+1], int n , int e){
   	
	int i , j ; 

	ArcViewSpot<T> * p ;

	G = new graph<T> ;

	G -> n = n;

	G -> e = e;

    for(i = 1 ; i <= G -> n ; i++)  G -> spots[i].first = NULL;
    
    for(i = 1 ; i <= G -> n ; i++)
	
		for(j = 1 ; j <= G -> n; j++){
			
			if(a[i][j] != 0 && a[i][j] != 100000){
			   
                p = new ArcViewSpot<T> ;

				p -> adjvex = j;
                
				p -> weight = a[i][j];

				p -> next = G -> spots[i].first;   //采用头插法插入数据

				G -> spots[i].first = p;
			   }
		}

}


//输出图的邻接链表

template <typename T>

void GraphClass<T>:: DisGraph(){
   
	  cout<<"\n\n图的邻接链表\n\n";

      ArcViewSpot<T> * p = NULL;
      
	  int i ;

	  for( i = 1 ; i <= G -> n ; i++){
	  
	     p = G -> spots[i].first;
	     
         cout<<'('<< i <<')' <<": "<< viewSpots[i].viewSpotName << ":  "; 

		 while(p){
		 
		   cout<< " ---> " << '('<< p -> adjvex << ')' <<": "<<viewSpots[ p -> adjvex].viewSpotName ;
		 
		   p = p -> next;
		 }

		 cout<<endl;
	  }




}