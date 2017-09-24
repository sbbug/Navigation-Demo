/*
学校景点定义，和其相关数据书写
  */


#include<string>

using namespace std;

//学校顶点个数定义

#define viewSpotCount 30

//定义一个正无穷

#define INF 100000;

/*

  每个景点定义

 采用结构体定义

  */



struct viewSpot{
       
	   //景点编号  

       int viewSpotNum;

	   //景点名称

	   string viewSpotName;

	   //景点简介

	   string viewSpotIntroduction;

};

//存储景点信息的一维数组



viewSpot viewSpots[viewSpotCount+1];


//南京工业大学地图的邻接矩阵

int locations[viewSpotCount+1][viewSpotCount+1];
  

