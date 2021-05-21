#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>


typedef int SAVEDTYPE;

#define INIT_SIZE 5//初始化大小
#define ADD_SIZE 5//增长大小

#define NoError 0
#define AllocError -1//内存分配错误
#define NullPointerError -2//空指针错误
#define UninitError -3//容器未初始化错误
#define DataIllegalError -4//数据不合法错误

struct cvector;
int initVector(cvector* newvector);//初始化顺序表
int insert(cvector* vector, int position, SAVEDTYPE inserted);//插入元素
int pushBack(cvector* vector, SAVEDTYPE inserted);//在表尾部创建元素
int pushFront(cvector* vector, SAVEDTYPE inserted);//在表头部创建元素(耗时)
int erase(cvector* vector, int position);//删除元素
int popBack(cvector* vector);//在表尾部删除元素
int popFront(cvector* vector);//在表头部删除元素(耗时)
int clear(cvector* vector);//清除表内数据
int destory(cvector* vector);//销毁顺序表
int isEmpty(cvector* vector);//判空
int getLength(cvector* vector);//获取长度
int printAll(cvector* vector);//输出所有元素
int debug(cvector* vector);


struct cvector {
    SAVEDTYPE* HEAD = NULL;
    int init = 0;//是否初始化
    int length = 0;//长度
    int capacity = 0;//容量
    int empty = 0;//是否为空
};
int initVector(cvector* newvector) {//初始化顺序表
    if (newvector == NULL)
        return NullPointerError;
    newvector->HEAD = (SAVEDTYPE*)malloc(sizeof(SAVEDTYPE)* INIT_SIZE);
    if (newvector->HEAD == NULL)
        return AllocError;

    //初始化数据
    newvector->init = 1;
    newvector->length = 0;
    newvector->capacity = 5;
    return newvector->init;
}
int insert(cvector* vector, int position, SAVEDTYPE inserted) {//插入元素
    //索引从0开始，插入到第position个元素之前，0代表插到表首
    if (vector == NULL || vector->HEAD == NULL)
        return NullPointerError;
    if (vector->init != 1)
        return UninitError;
    if (position < 0 || position > vector->length + 1)
        return DataIllegalError;
    
    SAVEDTYPE* newbase = NULL;
    SAVEDTYPE* p1 = NULL;
    SAVEDTYPE* p2 = NULL;

    if (vector->capacity - vector->length <= 2) {//容量动态增长
        newbase = (SAVEDTYPE*)realloc(vector->HEAD, sizeof(SAVEDTYPE) * (vector->capacity + ADD_SIZE));
        if (newbase == NULL)
            return AllocError;
        vector->capacity += ADD_SIZE;
        vector->HEAD = newbase;
    }

    p1 = &(vector->HEAD[position]);
    if (vector->length == 0) {
        *p1 = inserted;
    }
    if (vector->length >= 1) {
        for (p2 = &(vector->HEAD[vector->length-1]); p2 >= p1; p2--) {
            *(p2 + 1) = *p2;
        }
        *p1 = inserted;
    }
    
    vector->empty = 1;
    vector->length++;
    return NoError;
}
int pushBack(cvector* vector, SAVEDTYPE inserted) {//在表尾部创建元素
    //在表尾创建元素仅耗费常数时间
    if (vector->length == 0) {
        return insert(vector, 0, inserted);
    }
    else return insert(vector, vector->length, inserted);
}
int pushFront(cvector* vector, SAVEDTYPE inserted) {//在表头部创建元素
    //移动元素可能耗时
    if (vector->length == 0) {
        return insert(vector, 0, inserted);
    }
    else return insert(vector, 0, inserted);
}
int erase(cvector* vector, int position) {//删除元素
    if (vector == NULL || vector->HEAD == NULL)
        return NullPointerError;
    if (vector->init != 1)
        return UninitError;
    if (vector->length == 0)
        return DataIllegalError;
    if (position < 0 || position > vector->length-1)
        return DataIllegalError;

    SAVEDTYPE* p1 = NULL;
    SAVEDTYPE* p2 = NULL;

    p1 = &(vector->HEAD[position]);
    if (position == vector->length-1) {
        *p1 = 0;
    }
    else {
        p2 = &(vector->HEAD[vector->length - 1]);//获取表尾元素地址
        for (++p1; p1 <= p2; p1++) {
            *(p1 - 1) = *p1;
        }
    }
    vector->length--;
    return NoError;
}
int popBack(cvector* vector) {//在表尾部删除元素
    return erase(vector, vector->length - 1);
}
int popFront(cvector* vector) {//在表头部删除元素(耗时)
    return erase(vector, 0);
}
int getElem(cvector* vector, int position, SAVEDTYPE* out) {
    if (vector == NULL || vector->HEAD == NULL) 
        return NullPointerError;
    if (vector->init != 1)
        return UninitError;
    if (vector->length == 0)
        return DataIllegalError;
    if (position < 0 || position >= vector->length)
        return DataIllegalError;
    *out = vector->HEAD[position];
    return NoError;
}
int clear(cvector* vector) {//清除表内数据
    if (vector == NULL || vector->HEAD == NULL)
        return NullPointerError;
    if (vector->init != 1)
        return UninitError;
    for (int i = 0; i < vector->length; i++)
        vector->HEAD[i] = 0;
    vector->empty = 0;
    vector->length = 0;
    return NoError;
}
int destory(cvector* vector) {//销毁顺序表
    clear(vector);
    vector->capacity = 0;
    vector->init = 0;
    free(vector->HEAD);
    vector->HEAD = NULL;
    return NoError;
}
int isEmpty(cvector* vector) {//判空
    if (vector == NULL || vector->HEAD == NULL)
        return NullPointerError;
    if (vector->init != 1)
        return UninitError;
    return vector->empty;
}
int getLength(cvector* vector) {//获取长度
    if (vector == NULL || vector->HEAD == NULL)
        return NullPointerError;
    if (vector->init != 1)
        return UninitError;
    return vector->length;
}
int printAll(cvector* vector) {//输出所有元素
    if (vector == NULL || vector->HEAD == NULL)
        return NullPointerError;
    if (vector->init != 1)
        return UninitError;
    
    for (int i = 0; i < vector->length; i++)
        printf("第%d个元素的值：%d\n",i,vector->HEAD[i]);
    return NoError;
}
int debug(cvector* vector) {//debug
    printf("\nlength:%d\n", vector->length);
    printf("capacity:%d\n", vector->capacity);
    return NoError;
}
int main(void) {
    int init = 0;
    cvector test;
    init=initVector(&test);
    printf("init:%d\n\n", init);

    //----------------------------------------------------------------------------
    //计时代码部分，精度微秒级
    double run_time;
    LARGE_INTEGER time_start;	//开始时间
    LARGE_INTEGER time_over;	//结束时间
    double dqFreq;		//计时器频率
    LARGE_INTEGER f;	//计时器频率
    QueryPerformanceFrequency(&f);
    dqFreq = (double)f.QuadPart;
    QueryPerformanceCounter(&time_start); //计时开始
    //----------------------------------------------------------------------------   
    //在此处编写需要计时的代码：

    for (int i = 0; i < 10000; i++)
        pushBack(&test, 1 + i);
    //for (int i = 0; i < 100000; i++)
        //popFront(&test);


    //----------------------------------------------------------------------------
    //计时结束
    QueryPerformanceCounter(&time_over);	
    run_time = 1000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
      //乘以1000把单位化为毫秒
    printf("\ntime:%.4lfms\n",run_time);
    //----------------------------------------------------------------------------


    debug(&test);

}