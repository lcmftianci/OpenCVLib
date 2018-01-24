///*
//* ���̹߳�����
//*
//*/
//#ifndef CTHREADPOOLMANAGE_H
//#define CTHREADPOOLMANAGE_H
//
//#include <iostream>
//#include <pthread.h>
//#include <unistd.h> 
//#include <list>
//#include <vector>
//#include <time.h>
//#include <asm/errno.h>
//
//#define USLEEP_TIME 100
//#define CHECK_TIME 1
//
//
//using namespace std;
//class CDoit
//{
//public:
//	virtual int start(void *){};
//	virtual int end(){};
//};
//
//
//class CthreadPoolManage
//{
//private:
//	int _minThreads;  //���ٱ��������߳�
//	int _maxThreads;  //�������м����߳�
//	int _waitSec;      //���ж�������̹߳ر�
//	class threadInfo{
//	public:
//		threadInfo(){
//			isbusy = false;
//			doFlag = true;
//		}
//		//
//		pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
//		pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
//		bool isbusy;   //�Ƿ����
//		bool doFlag;
//		//
//		time_t beginTime;     //�̲߳�������ʼʱ��
//		pthread_t cThreadPid; //�߳�id
//		pthread_attr_t cThreadAttr; //�߳�����
//		CDoit * doit;         //������
//		void  * value;        //��Ҫ���ݵ�ֵ
//	};
//	//�̺߳���
//	static void* startThread(void*);
//	//���������
//	pthread_mutex_t _duty_mutex;
//	//�������
//	list<threadInfo*> _dutyList;
//	//�̶߳�����
//	pthread_mutex_t _thread_mutex;
//	//�̶߳���
//	list<threadInfo*> _threadList;
//
//	///��ʼ����������С�����߳�///
//	void initThread();
//	///��������߳�///
//	static void* taskAllocation(void*arg);
//	pthread_t tasktPid;
//	///�߳����١�״̬����߳�///
//	static void* checkThread(void* arg);
//	pthread_t checktPid;
//	bool  checkrun;
//
//	//�߳��쳣�˳�����
//	static void threadCleanUp(void* arg);
//
//	//
//	int addThread(list<threadInfo*> *plist, threadInfo* ptinfo);
//
//public:
//	CthreadPoolManage();
//	/*
//	�����������̣߳�����߳��������ж�����٣����������̵߳�����
//	*/
//	CthreadPoolManage(int min, int max, int waitSec);
//	~CthreadPoolManage();
//
//	int start();
//	//����ע����
//	int putDuty(CDoit *, void *);
//
//	int getNowThreadNum();
//
//};
//
//#endif