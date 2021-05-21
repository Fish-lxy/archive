#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char ElemType;

#define INIT_SIZE 5//初始化大小
#define ADD_SIZE 5//增长大小

#define NoError 0
#define AllocError -1//内存分配错误
#define NullPointerError -2//空指针错误
#define UninitError -3//容器未初始化错误
#define DataIllegalError -4//数据不合法错误
#define NotExistError -5//数据不存在错误

typedef struct Stack {
    ElemType* BASE = NULL;//栈底指针
    ElemType* TOP = NULL;//栈顶指针
    int init = 0;//是否初始化
    int length = 0;//长度
    int capacity = 0;//容量
    int empty = 1;//是否为空
}Stack;
int initStack(Stack* newstack);//初始化新栈
int push(Stack* stack, ElemType elem);//入栈
int pop(Stack* stack, ElemType* out);//出栈
int getTop(Stack* stack, ElemType* out);//获取栈顶元素
int clear(Stack* stack);//清除栈内数据
int destory(Stack* stack);//销毁栈
int isEmpty(Stack* stack);//判空
int getLength(Stack* stack);//获取栈长度
int output(Stack* stack);//输出所有元素



