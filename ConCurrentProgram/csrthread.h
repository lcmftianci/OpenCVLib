#include <windows.h>
#include <process.h>
#include <stdio.h>
#include <iostream>
#include <vector>


//子线程函数
typedef unsigned int (__stdcall*ThreadProc) (void* pParams);


//单个线程信息
typedef struct _threadItem{
	HANDLE	hHandle;		//线程句柄
	bool bBusy;				//是否这在执行
}threadItem;

//任务结构体
typedef struct _task{
	ThreadProc threadItem;			//线程函数
	void* pParams;					//线程参数
}task;

//线程池结构体
typedef struct _threadPool{
	std::vector<threadItem> arrItemPool;		//存放所有的线程
	int nNum;									//当前有多少空闲线程
	HANDLE hMutex;								//互斥锁
	unsigned int waiting_tasks;					//任务队列中正在等待的任务个数  
	unsigned int active_threads;			    //正在工作的线程个数
	unsigned int ThreadNum;				     	//线程总个数
	std::vector<task> arrTask;					//等待的任务个数
}threadPool;


//初始化线程
bool InitThreadPool(size_t nThreadNum);

//添加任务事件
bool AddTaskInThreadPool(ThreadProc *pFunc, void* Params);

//销毁线程池
bool DestroyPool();

