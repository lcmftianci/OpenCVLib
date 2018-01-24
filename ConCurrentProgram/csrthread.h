#include <windows.h>
#include <process.h>
#include <stdio.h>
#include <iostream>
#include <vector>


//���̺߳���
typedef unsigned int (__stdcall*ThreadProc) (void* pParams);


//�����߳���Ϣ
typedef struct _threadItem{
	HANDLE	hHandle;		//�߳̾��
	bool bBusy;				//�Ƿ�����ִ��
}threadItem;

//����ṹ��
typedef struct _task{
	ThreadProc threadItem;			//�̺߳���
	void* pParams;					//�̲߳���
}task;

//�̳߳ؽṹ��
typedef struct _threadPool{
	std::vector<threadItem> arrItemPool;		//������е��߳�
	int nNum;									//��ǰ�ж��ٿ����߳�
	HANDLE hMutex;								//������
	unsigned int waiting_tasks;					//������������ڵȴ����������  
	unsigned int active_threads;			    //���ڹ������̸߳���
	unsigned int ThreadNum;				     	//�߳��ܸ���
	std::vector<task> arrTask;					//�ȴ����������
}threadPool;


//��ʼ���߳�
bool InitThreadPool(size_t nThreadNum);

//��������¼�
bool AddTaskInThreadPool(ThreadProc *pFunc, void* Params);

//�����̳߳�
bool DestroyPool();

