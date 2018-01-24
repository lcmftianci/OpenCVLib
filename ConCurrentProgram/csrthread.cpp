//#include "csrthread.h"
//
////初始化线程
//bool InitThreadPool(threadPool* pPool, size_t nThreadNum)
//{
//	//初始化线程池
//	
//	//创建nThreadNum个线程
//	//for (int i = 0; i < nThreadNum; i++)
//	//{
//	//	//单独创建每个线程
//	//	threadItem ti;
//	//	ti.bBusy = false;
//	//	ti.hHandle = NULL;
//	//	mypool.arrItemPool.push_back(ti);
//	//}
//
//	pPool->active_threads = 0;
//	pPool->hMutex = CreateEvent(NULL, FALSE, FALSE, NULL);
//	pPool->nNum = nThreadNum;
//	pPool->waiting_tasks = 0;
//	return false;
//}
//
////添加任务事件
//HANDLE AddTaskInThreadPool(threadPool* pool, ThreadProc *pFunc, void* Params)
//{
//	WaitForSingleObject(pool->hMutex, INFINITE);
//	for (int i = 0; i < pool->ThreadNum; i++)
//	{
//		if (!pool->arrItemPool[i].bBusy)
//		{
//			/*if ((pool->arrItemPool[i].hHandle = (HANDLE)_beginthreadex(NULL, 0, ()pFunc, Params, 0, NULL)) != INVALID_HANDLE_VALUE)
//			{
//				ReleaseMutex(pool->hMutex);
//				pool->arrItemPool[i].bBusy = TRUE;
//				return pool->arrItemPool[i].hHandle;
//			}*/
//		}
//	}
//	return NULL;
//}
//
////销毁线程池
//bool DestroyPool()
//{
//	return false;
//}
//
//int main(void)
//{
//	threadPool tThreadPool;
//	InitThreadPool(&tThreadPool, 10);
//
//}