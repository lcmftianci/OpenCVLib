//#include "csrthread.h"
//
////��ʼ���߳�
//bool InitThreadPool(threadPool* pPool, size_t nThreadNum)
//{
//	//��ʼ���̳߳�
//	
//	//����nThreadNum���߳�
//	//for (int i = 0; i < nThreadNum; i++)
//	//{
//	//	//��������ÿ���߳�
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
////��������¼�
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
////�����̳߳�
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