#include <iostream>
#include "MyThreadPool.h"
#include "MyThread.h"
#include"TestTask.h"

#include "SmallThreadPool.h"

//�����̳߳�
//int main(int argc,char**argv)
//{
//	CTestTask*p=NULL;
//
//	//��ʼ��ʮ���߳�
//	CMyThreadPool threadpool(10);
//
//	//����һ�ٸ�����
//	for(int i=0;i<100;i++)
//	{
//		//��������
// 		p=new CTestTask(i);
//		threadpool.addTask(p,PRIORITY::NORMAL);
//	}
//	p=new CTestTask(102200);
//	
//	
//	threadpool.addTask(p,PRIORITY::HIGH);
//	
//	//threadpool.destroyThreadPool();
//	//���߳�ִ������������
//	{
//		Sleep(1000*1000);
//	}
//	
//	return 0;
//}

//int main(void)
//{
//	ThreadPool myPool(10);
//
//	//����50�����񣬸�10���߳�ִ��
//	for (int i = 0; i < 50; i++)
//	{
//		myPool.enqueue(i);
//	}
//
//	Sleep(1000 * 10);
//}


//int main(void)
//{
//	printf("���߳̿�ʼִ�С�����\n");
//	system("pause");
//	return 0;
//}