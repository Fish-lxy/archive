#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define INIT_SIZE 5//初始化大小
#define ADD_SIZE 5//增长大小

#define NoError 0
#define AllocError -1//内存分配错误
#define NullPointerError -2//空指针错误
#define UnInitError -3//容器未初始化错误
#define DataIllegalError -4//数据不合法错误
#define NotExistError -5//数据不存在错误

struct String {
    char* HEAD = NULL;//数据指针
    short int init = 0;//是否初始化
    int length = 0;//长度
    int capacity = 0;//容量
};

int strInit(String* str);//字符串初始化
int strAssign(String* str, const char* s);//字符串赋值
int strLength(String* str, int* out);//求字符串长度
int strClear(String* str);//清空字符串
int strDestroy(String* str);//销毁字符串
int strConcat(String* str1, String* str2);//链接字符串
int strSubString(String* str, String* out, int position, int len);//求字符串的子串的位置
int strIndex(String* str, String* t, int* out);//字符串模式匹配(朴素算法)
int strGetNext(String* str, int* next);//求字符串next数组
