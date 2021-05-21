#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int ElemType;

#define NoError 0
#define AllocError -1//内存分配错误
#define NullPointerError -2//空指针错误
#define UninitError -3//容器未初始化错误
#define DataIllegalError -4//数据不合法错误
#define NotExistError -5//数据不存在错误


typedef struct Node{
	ElemType data;
	Node* next;
}Node;
Node* initNode();
int pushBack(Node* node, ElemType newdata);
int insert(Node* node, int position, ElemType newdata);
int erase(Node* node, int position);
int find(Node* node, ElemType elem, ElemType* out);
int outputAll(Node* node);
int destory(Node* node);