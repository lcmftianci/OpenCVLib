#include <iostream>
#include "MyThreadPool.h"
#include "MyThread.h"
#include"TestTask.h"

#include "SmallThreadPool.h"

//测试线程池
//int main(int argc,char**argv)
//{
//	CTestTask*p=NULL;
//
//	//初始化十个线程
//	CMyThreadPool threadpool(10);
//
//	//分配一百个任务
//	for(int i=0;i<100;i++)
//	{
//		//分配任务
// 		p=new CTestTask(i);
//		threadpool.addTask(p,PRIORITY::NORMAL);
//	}
//	p=new CTestTask(102200);
//	
//	
//	threadpool.addTask(p,PRIORITY::HIGH);
//	
//	//threadpool.destroyThreadPool();
//	//主线程执行其他工作。
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
//	//创建50个任务，给10个线程执行
//	for (int i = 0; i < 50; i++)
//	{
//		myPool.enqueue(i);
//	}
//
//	Sleep(1000 * 10);
//}


//int main(void)
//{
//	printf("主线程开始执行。。。\n");
//	system("pause");
//	return 0;
//}