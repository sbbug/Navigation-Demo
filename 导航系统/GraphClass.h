/*

  �Ͼ���ҵ��ѧУ԰����ϵͳ��ͼ��ͷ�ļ�����

  ����ĿΪ����ѧУѧ����ʦ�����߲ι�ʱʹ��

  ����ʵ�֣�C++

*/


#include <iomanip>

using namespace std;

//������ڽӾ�����

template <typename T>

struct MGraph{
  
    //����ڽӾ�������鶨��
    
    //����洢����Ȩֵ��Ҳ���Ǿ���ֵ

	T edges[viewSpotCount+1][viewSpotCount+1];
    
    //��Ŷ������

	int n; 
   
	//��űߵ���Ŀ

    int e; 

};

//����߽ڵ�ṹ������

template <typename T>

struct ArcViewSpot{
  
	T adjvex  ; 

	ArcViewSpot<T> *next;
   
	T weight;
}; 

//��������ı�ͷ�ڵ�

template <typename T>

struct viewSpotStart{
  
	T start;
    
    ArcViewSpot<T> *first; 
};

//ͼ���ڽӱ�����

template <typename T>

struct graph{
   
	viewSpotStart<T> spots[viewSpotCount+1];  //�����ڽ�����ı�ͷ����

	int n;  //�ڵ����

	int e;  //�ߵĸ���

};

//ͼ������ڵ㶨��
/*

  У԰��ͼ��ģ��Ķ���

  
  ������������������ط���
*/


template <typename T>

class GraphClass{


  //���˽�����Զ���

	private:
        
     graph<T>  *G ;
		

    //��ع��з�������

	public:
        
		//�����ڽӾ���

		MGraph<T> M;
       
		//���췽��

		GraphClass();

		//����������

		~GraphClass();

		//����ͼ���ڽӾ���

		void CreateMGraph( int a[][viewSpotCount+1] , int n , int e );

       //���ͼ���ڽӾ���

		void DisMGraph();

       //����ͼ���ڽ�����

		void CreateGraph(int a[][viewSpotCount+1], int n , int e);
		
       //���ͼ���ڽ�����

		void DisGraph();

		//��ȡͼ���ڽ�����ľ��

		graph<T> * getHandle();


};


//��ķ���ʵ��

template <typename T>

GraphClass<T>::GraphClass(){

   G = NULL;

}

//��������ʵ��

template <typename T>

GraphClass<T>::~GraphClass(){


}

//ͼ���ڽӾ���ĳ�ʼ��

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

//���ͼ���ڽӾ���

template <typename T>

void GraphClass<T>::DisMGraph(){
   
	int i ,j;
    
    cout<<"\t\t\t\t\t\t\t\t  ��ͼ���ڽӾ���: \n\n\n";

	for(i = 1 ; i <= M.n ; i++){
	    
		cout<<"\t";
		for(j = 1 ; j <= M.n ; j++){
		   
			if(M.edges[i][j] == 100000)
				cout<<setw(5)<<"��" <<setw(5);
		    else
				cout<<setw(5)<<M.edges[i][j]<<setw(5);
		}
	   
		cout<<endl;
	}
    
}

//����ͼ���ڽ�����

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

				p -> next = G -> spots[i].first;   //����ͷ�巨��������

				G -> spots[i].first = p;
			   }
		}

}


//���ͼ���ڽ�����

template <typename T>

void GraphClass<T>:: DisGraph(){
   
	  cout<<"\n\nͼ���ڽ�����\n\n";

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