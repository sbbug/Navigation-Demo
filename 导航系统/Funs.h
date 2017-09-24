/*

  ������ͼ����ط�������

  ��Щ���������ڵ�ͼ�ⲿ���������ڵ�ͼ��


  */
#include<iostream>

#include<string>

using namespace std;

#include "data.h"

#include "GraphClass.h"

/*----------------------------------------------------------------------------

  ��ر����Ķ���
  ----------------------------------------------------------------------------*/

//�˵�ѡ���������

int choice ; 


//�����Ŷ���

int spotNum;

string  spotName ; 

string  spotInfo;

//��������������

int spotNum1 ; 

int spotNum2 ; 

//·��������������󾰵����

#define maxSpotCount 8

//����һ��ȫ�����飬����Ƿ��Ѿ������ʹ�

int visited[viewSpotCount+1];

//����������ʼ�������������

int startSpot , endSpot;

//��ط���������

template <typename T>

void paths(GraphClass<T> & , int  , int  , int []);

template <typename T>

void allPath(GraphClass<T> & , int  , int );

/*-----------------------------------------------------------------------------
  ��ط����Ķ���

  -----------------------------------------------------------------------------*/

//��ͼ�ĳ�ʼ��

//�������ݵĳ�ʼ��

void init1(){
   
viewSpots[1].viewSpotNum = 1;
viewSpots[1].viewSpotName = "ѧ��Է";
viewSpots[1].viewSpotIntroduction = "";

viewSpots[2].viewSpotNum = 2;
viewSpots[2].viewSpotName = "̴��Է";
viewSpots[2].viewSpotIntroduction = "";

viewSpots[3].viewSpotNum = 3;
viewSpots[3].viewSpotName = "��ɽԷ";
viewSpots[3].viewSpotIntroduction = "";

viewSpots[4].viewSpotNum = 4;
viewSpots[4].viewSpotName = "��ɽʳ��";
viewSpots[4].viewSpotIntroduction = "";

viewSpots[5].viewSpotNum = 5;
viewSpots[5].viewSpotName = "�����";
viewSpots[5].viewSpotIntroduction = "";

viewSpots[6].viewSpotNum = 6;
viewSpots[6].viewSpotName = "����¥";
viewSpots[6].viewSpotIntroduction = "";

viewSpots[7].viewSpotNum = 7;
viewSpots[7].viewSpotName = "ͬ��¥";
viewSpots[7].viewSpotIntroduction = "";

viewSpots[8].viewSpotNum = 8;
viewSpots[8].viewSpotName = "����С�鷿";
viewSpots[8].viewSpotIntroduction = "";

viewSpots[9].viewSpotNum = 9;
viewSpots[9].viewSpotName = "����ʡ��ҵ������������";
viewSpots[9].viewSpotIntroduction = "";

viewSpots[10].viewSpotNum = 10;
viewSpots[10].viewSpotName = "�������������о�����";
viewSpots[10].viewSpotIntroduction = "";

viewSpots[11].viewSpotNum = 11;
viewSpots[11].viewSpotName = "��Է";
viewSpots[11].viewSpotIntroduction = "";

viewSpots[12].viewSpotNum = 12;
viewSpots[12].viewSpotName = "�ݷ�ͼ���";
viewSpots[12].viewSpotIntroduction = "";

viewSpots[13].viewSpotNum = 13;
viewSpots[13].viewSpotName = "�칤¥";
viewSpots[13].viewSpotIntroduction = "";

viewSpots[14].viewSpotNum = 14;
viewSpots[14].viewSpotName = "����";
viewSpots[14].viewSpotIntroduction = "";

viewSpots[15].viewSpotNum = 15;
viewSpots[15].viewSpotName = "�ص�ʵ����";
viewSpots[15].viewSpotIntroduction = "";

viewSpots[16].viewSpotNum = 16;
viewSpots[16].viewSpotName = "��Է";
viewSpots[16].viewSpotIntroduction = "";

viewSpots[17].viewSpotNum = 17;
viewSpots[17].viewSpotName = "��Է";
viewSpots[17].viewSpotIntroduction = "";

viewSpots[18].viewSpotNum = 18;
viewSpots[18].viewSpotName = "��������ҩѧԺ";
viewSpots[18].viewSpotIntroduction = "";

viewSpots[19].viewSpotNum = 19;
viewSpots[19].viewSpotName = "�о�Ժ";
viewSpots[19].viewSpotIntroduction = "";

viewSpots[20].viewSpotNum = 20;
viewSpots[20].viewSpotName = "��ԴѧԺ";
viewSpots[20].viewSpotIntroduction = "";

viewSpots[21].viewSpotNum = 21;
viewSpots[21].viewSpotName = "�ﾶ��";
viewSpots[21].viewSpotIntroduction = "";

viewSpots[22].viewSpotNum = 22;
viewSpots[22].viewSpotName = "�ֽ�����";
viewSpots[22].viewSpotIntroduction = "";

viewSpots[23].viewSpotNum = 23;
viewSpots[23].viewSpotName = "������";
viewSpots[23].viewSpotIntroduction = "";

viewSpots[24].viewSpotNum = 24;
viewSpots[24].viewSpotName = "��Է";
viewSpots[24].viewSpotIntroduction = "";

viewSpots[25].viewSpotNum = 25;
viewSpots[25].viewSpotName = "����¥";
viewSpots[25].viewSpotIntroduction = "";

viewSpots[26].viewSpotNum = 26;
viewSpots[26].viewSpotName = "�Ŀ�ͼ���";
viewSpots[26].viewSpotIntroduction = "";


viewSpots[27].viewSpotNum = 27;
viewSpots[27].viewSpotName = "����㳡";
viewSpots[27].viewSpotIntroduction = "";

viewSpots[28].viewSpotNum = 28;
viewSpots[28].viewSpotName = "�ֽ���ѧ¥";
viewSpots[28].viewSpotIntroduction = "";

viewSpots[29].viewSpotNum = 29;
viewSpots[29].viewSpotName = "ҩ���о���";
viewSpots[29].viewSpotIntroduction = "";

viewSpots[30].viewSpotNum = 30;
viewSpots[30].viewSpotName = "����У��";
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
   
   cout<<"\n���ݳ�ʼ�����\n";

   
 }



//��ʾ�˵���������

void showViewSpot(){

   cout<<"\n\n------------------------------------------------------------------------�Ͼ���ҵ��ѧУ԰����ϵͳ------------------------------------------------------------------------\n\n";

   cout<<"\n\t\t\t\t\t\t\t\t          ��ӭ�����Ͼ���ҵ��ѧ\t\t\t\n\n";

   cout<<"\t\t\t\t\t\t\t\t\t       �˵�ѡ��\t\t\t\t\n\n\n";

   cout<<"\t\t\t\t\t\t\t   1. ѧУ�������                   5. ��ѯ��������·��\n\n"; 

   cout<<"\t\t\t\t\t\t\t   2. ������Ϣ��ѯ                   6. ����ͼ��Ϣ\n\n";

   cout<<"\t\t\t\t\t\t\t   3. ��ѯ����·��                   7. ��ӡ�ڽӾ���\n\n";

   cout<<"\t\t\t\t\t\t\t   4. ��ѯ����֮���Ѱ·��           8. �˳�\n\n\n";

   cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
   

}

//ѧУ�������,����ֻ�Ǽ򵥽���

void showSpotInfo(){
   
     int i = 1;
     
     
      
     cout<<"  ���\t\t��������\t\t\t���\t\t\t\n\n";
	 for(; i <= viewSpotCount ; i++){
	 
	   cout<<"  "<<viewSpots[i].viewSpotNum<<"\t\t"<<viewSpots[i].viewSpotName <<"\t\t\t";
	    
       cout<<endl;

	   
	 }

	 cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";


}

//��ѯͼ��ĳһ�������Ϣ

//����Ĳ����Ǿ������

void searchViewSpotInfo(int i){
    
   
    cout<<"\t\t\t\t\t\t\t�þ���������Ϣ��������: \n";

	cout<<"\n  ���:  \t\t"<<viewSpots[i].viewSpotNum<<endl;

	cout<<"\n  ����:  \t\t"<<viewSpots[i].viewSpotName<<endl;

	cout<<"\n  �������:  \t\t"<<viewSpots[i].viewSpotIntroduction<<"\n\n";

	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
}



//��ѯһ�����㵽�������������·����������


template <typename T>

void Dijkstra(GraphClass<T> &gobj,int v){
	
	T dist[viewSpotCount+1]; //�洢���·�� ������

	int path[viewSpotCount+1]; //�洢�ýڵ��ǰ���ڵ�

	int S[viewSpotCount+1];   //�洢�ýڵ��Ƿ񱻷��ʹ�

	int mindis,i,j,u=1,n;

	n = gobj.M.n;
    

   //��������г�ʼ��

	for(i = 1 ; i <= n ; i++){
	    
		dist[i] = gobj.M.edges[v][i];

		S[i] = 0;

		if(gobj.M.edges[v][i] < 100000)

			path[i] = v;

		else

			path[i] = -1;
	}

	S[v] = 1;  //�ѱ����ʹ��Ľڵ�������

	for( i = 1 ;i < n ; i++){
	
	    mindis = INF;
     
		for(j = 1 ; j <= n ;j++){
		
			if(S[j] == 0 && dist[j] < mindis){   //Ѱ�Ҿ������������Сֵ
			   
				u  = j;

                mindis = dist[j]; 
		
			}
		}

		S[u] = 1;   //�ѱ����ʹ��Ľڵ���з���
  
        //��������и���

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

    //����Ӷ���v���� ���������·��

	int i,j,k;

	int apath[viewSpotCount+1];

	int d;

	for(i = 1 ; i <= n ;i++){
	  
		if(S[i]==1 && i!=v){
		   
			
		
		    d = 0; apath[d] = i;

			k = path[i];

			if(k ==-1)
				cout<<"��·��\n";

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

				cout<<"\n��·�߳��ȣ�"<<dist[i]<<" m\n";
                
				cout<<endl<<endl;
			
			}
		
		}
	
	
	}

}

//�����ͼ��ĳһ���㵽��һ��ָ�����������·�������Ҹ�·���������ĵص����Ϊ<=8;

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

			paths(gobj , start , end , k);   //ע��˴�����ĺ�������path()���������ֲ�����һ��������ᱨ���ִ���error C2064: term does not evaluate to a function
		    
			visited[a] = 0;
		}
    
		
	} 
}

//��ѯ��������֮�����·���������壬�����Ӧ��·���㼴��

template <typename T>

void searchShortestPath(GraphClass<T> &obj, int start,int end){

    T dist[viewSpotCount+1]; //�洢���·�� ������

	int path[viewSpotCount+1]; //�洢�ýڵ��ǰ���ڵ�

	int S[viewSpotCount+1];   //�洢�ýڵ��Ƿ񱻷��ʹ�

	int mindis,i,j,u=1,n;

	n = obj.M.n;
    

   //��������г�ʼ��

	for(i = 1 ; i <= n ; i++){
	    
		dist[i] = obj.M.edges[start][i];

		S[i] = 0;

		if(obj.M.edges[start][i] < 100000)

			path[i] = start;

		else

			path[i] = -1;
	}

	S[start] = 1;  //�ѱ����ʹ��Ľڵ�������

	for( i = 1 ;i < n ; i++){
	
	    mindis = INF;
     
		for(j = 1 ; j <= n ;j++){
		
			if(S[j] == 0 && dist[j] < mindis){   //Ѱ�Ҿ������������Сֵ
			   
				u  = j;

                mindis = dist[j]; 
		
			}
		}

		S[u] = 1;   //�ѱ����ʹ��Ľڵ���з���
  
        //��������и���

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

//������·��

template <typename T>

void DispAPath(T dist[] , int path[] , int S[] , int start , int n, int end){

    //����Ӷ���v���� ���������·��

	int j,k;

	int apath[viewSpotCount+1];

	int d;

	if(S[end]==1 && end != start){
		   
		
		    d = 0; apath[d] = end;

			k = path[end];

			if(k ==-1)
				cout<<"��·��\n";

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
			    cout<<"��  "<<viewSpots[start].viewSpotName<<"  ��  "<<viewSpots[end].viewSpotName<<"  ���·������Ϊ:  "<<dist[end]<<"  m";
		
			}
		
		}
	
}

//�޸�ͼ����Ϣ����Ҫ�ǶԾ�����Ϣ���޸�

void modifyNode(int num , string name , string info){
   
      viewSpots[num].viewSpotName = name ;

	  viewSpots[num].viewSpotIntroduction = info;

	  cout<<"\n\t\t\t\t\t\t\t\t�޸ĺ�ľ�����Ϣ:\n\n";
      
	  cout<<"\n  \t\t���:  \t\t"<<viewSpots[num].viewSpotNum<<endl;

	  cout<<"\n  \t\t����:  \t\t"<<viewSpots[num].viewSpotName<<endl;

	  cout<<"\n  \t\t�������: \t"<<viewSpots[num].viewSpotIntroduction<<"\n\n";
      
	  cout<<"\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";

}

//��ӡͼ���ڽӾ���
/*
void showMatrix(GraphClass<T> &obj){

   obj.DisMGraph();

}
*/
//��ѯ����·��,���Ƕ�ͼ�Ĺ�Ȼ�������ȱ���

void searchViewSpotPath(){
 

   
}


//��ѯ�����Ŀ�Ѱ·��

void searchViewSpotPaths(){


}

//�����û�ѡ�񷽷�����

template <typename T>

void executeChoice(GraphClass<T> &G){
    
     showViewSpot();

    

	 cout<<"\n\n\t\t\t\t\t\t\t\t\t����ѡ��:  ";  cin >> choice ; 

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
             
             cout<<"\t\t\t\t\t\t\t\t  �����뾰����:  ";

			 cin >> spotNum;

             cout<<"\n";

			 searchViewSpotInfo(spotNum);

			 break;

         case 3:
             
			 cout<<"\t\t\t\t\t\t\t      ��������ʼ������:  ";

			 cin >> spotNum;
             
			

			 Dijkstra(G,spotNum);

			 cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
             
             break;

         case 4:
               
			 cout<<"\n\t\t\t\t\t\t\t      �����뿪ʼ������:  "; 

			 cin >> spotNum1;

			 cout<<"\n\t\t\t\t\t\t\t      ���������������:  "; 
 
			 cin >> spotNum2;

			 cout<<"\n\n";

			 cout<<"  �� "<<spotNum1<<": "<<viewSpots[spotNum1].viewSpotName<<" �� "<<spotNum2<<": "<<viewSpots[spotNum2].viewSpotName
				 
				 <<" �����п���·��:\n\n";

             allPath(G,spotNum1,spotNum2);
			 
			 cout<<"\n\n\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
			 
			 break;

         case 5:
             
             cout<<"\t\t\t\t\t\t\t\t  �����������:  " ; cin >> startSpot;

			 cout<<"\n\t\t\t\t\t\t\t\t  �����������:  " ; cin >> endSpot;

			 cout<<"\n\n";
             
			 searchShortestPath(G,startSpot,endSpot);
             
			 cout<<"\n\n\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";


			 break;

         case 6:
              
             cout<<"\t\t\t\t\t\t      ��������Ҫ�޸����ƾ�����:  "; 

			 cin >> spotNum;

			 cout<<"\n\t\t\t\t\t\t          �������޸ĺ�ľ�������:  ";

			 cin >> spotName ; 

			 cout<<"\n\t\t\t\t\t\t        �������޸ĺ󾰵���Ϣ����:  ";

			 cin >> spotInfo ; 

             modifyNode(spotNum , spotName , spotInfo); 

			 break;
        
         case 7:
             
             G.DisMGraph();

			 cout<<"\n\n\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";

             break;

         default:

			 cout<<"��������ȷ��ѡ��\n";
              
			 break;
		 }

         showViewSpot(); 

         cout<<"\n\n\t\t\t\t\t\t\t\t\t����ѡ��:  ";  cin >> choice ; 

	 cout<<endl<<endl<<endl;
	 }

	 cout<<"�����˳�ϵͳ\n";
}

  