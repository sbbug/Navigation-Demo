/*
ѧУ���㶨�壬�������������д
  */


#include<string>

using namespace std;

//ѧУ�����������

#define viewSpotCount 30

//����һ��������

#define INF 100000;

/*

  ÿ�����㶨��

 ���ýṹ�嶨��

  */



struct viewSpot{
       
	   //������  

       int viewSpotNum;

	   //��������

	   string viewSpotName;

	   //������

	   string viewSpotIntroduction;

};

//�洢������Ϣ��һά����



viewSpot viewSpots[viewSpotCount+1];


//�Ͼ���ҵ��ѧ��ͼ���ڽӾ���

int locations[viewSpotCount+1][viewSpotCount+1];
  

