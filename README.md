# RedisHash
首先感谢redis提供的开源代码 基于最新版的 - redis-4.0.11
 
基于redis分离出来hashtable

只保留了高效的hashtable

修改了n处让他在win c++ 跑起来编译成功
 
修改地方未加注释
 
大体使用方法:

  ```c++
  
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
  ```
  输出:
    ```
      0
      0
      0
      0
      键:222
      111
      888
      333
      444
      一百万插入耗时:7ms!
      请按任意键继续. . .
    ```
  
  
