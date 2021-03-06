// redis抠出来.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
extern "C" {
	#include "dict.h"
	#include "sds.h"
	#include<Windows.h>  
}
using namespace std;

void _serverAssert(const char *estr, const char *file, int line) {

}
int main()
{
	dictType BenchmarkDictType = {
		hashCallback,
		NULL,
		NULL,
		compareCallback,
		freeCallback,
		NULL
	};
	dict* dic = dictCreate(&BenchmarkDictType, NULL);
	//添加一个元素
	cout << dictAdd(dic, sdsnew("111"), sdsnew("111")) << endl;
	cout << dictAdd(dic, sdsnew("222"), sdsnew("222")) << endl;
	cout << dictAdd(dic, sdsnew("333"), sdsnew("333")) << endl;
	cout << dictAdd(dic, sdsnew("444"), sdsnew("444")) << endl;
	size_t a;
	//替换给定key的value值
	dictReplace(dic, sdsnew("222"), sdsnew("888"));

	//删除一个元素
	//dictDelete(dic, sdsnew("444"));

	dictEntry* entry = dictGetRandomKey(dic);
	sds s = (sds)entry->key;
	cout << "键:" << s << endl;
	//sdsfree(s);
	
	sds txt = sdsnew((const char *)dictFetchValue(dic, sdsnew("111")));
	cout << txt << endl;
	txt = sdsnew((const char *)dictFetchValue(dic, sdsnew("222")));
	cout << txt << endl;
	txt = sdsnew((const char *)dictFetchValue(dic, sdsnew("333")));
	cout << txt << endl;
	txt = sdsnew((const char *)dictFetchValue(dic, sdsnew("444")));
	cout << txt << endl;
	sdsfree(txt);

	/*DWORD start_time = GetTickCount();
	int count = 1000000;
	for (int j = 0; j < count; j++) {
		sds key = sdsfromlonglong(rand() % count);
		dictAdd(dic, key,(void*)j);
		sdsfree(key);
	}
	DWORD end_time = GetTickCount();
	cout << "一百万插入耗时:" << (end_time - start_time) << "ms!" << endl;
	system("pause");*/
	//释放字典
	dictRelease(dic);
    return 0;
}

