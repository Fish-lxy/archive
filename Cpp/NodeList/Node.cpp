#include "Node.h"

Node* initNode() {//初始化
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
		exit(AllocError);
	newnode->next = NULL;
	newnode->data = 0;
	return newnode;
}
int pushBack(Node* node, ElemType newdata) {//在链表尾创建结点
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
		return AllocError;
	newnode->data = newdata;
	newnode->next = NULL;

	if (node == NULL)
		return NullPointerError;
	Node* p = node;
	while (p->next != NULL)
		p = p->next;
	p->next = newnode;

	node->data++;
	return NoError;
}
int insert(Node* node, int position, ElemType newdata) {//在指定位置插入节点，下标从0开始
	if (node == NULL)
		return NullPointerError;
	if (position > node->data)
		return DataIllegalError;

	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
		return AllocError;
	newnode->data = newdata;

	Node* p1 = node;

	if (position == 0&&node->data==0) {
		p1->next = newnode;
		newnode->next = NULL;
	}
	else {
		newnode->next = NULL;
		for (int i = 0; i < position; i++)
			p1 = p1->next;
		newnode->next = p1->next;
		p1->next = newnode;
	}
	
	node->data++;
	return NoError;
}
int erase(Node* node, int position) {//在指定位置删除节点，下标从0开始
	if (node == NULL)
		return NullPointerError;
	if (position > node->data)
		return DataIllegalError;

	Node* p1;
	Node* deleted;
	if (position == 0) {
		p1 = node;
		deleted = p1->next;
		p1->next = deleted->next;
		free(deleted);
	}
	else {
		p1 = node;
		for (int i = 0; i < position; i++)
			p1 = p1->next;
		deleted = p1->next;
		p1->next = deleted->next;
		free(deleted);
	}
	
	node->data--;
	return NoError;
}
int find(Node* node, ElemType elem, ElemType* out) {//查找指定元素的下标
	if (node == NULL)
		return NullPointerError;
	if (node->data == 0)
		return DataIllegalError;

	Node* p = node;
	int i = 0;
	while (p != NULL) {
		if (elem == p->data) {
			*out = --i;
			break;
		}
		p = p->next;
		i++;
		*out = 0;
	}
	return NoError;	
}
int outputAll(Node* node) {//输出全表
	if (node == NULL)
		return NullPointerError;

	int i = 0;
	Node* p = node->next;
	while (p!= NULL) {
		printf("第%d个元素的值：%d\n", i, p->data);
		p = p->next;
		i++;
	}
	return NoError;
}
int destory(Node* node) {//销毁全表
	if (node == NULL)
		return NullPointerError;

	Node* p = node;
	while (p != NULL) {
		p = node->next;
		free(node);
		node = p;
	}
	return NoError;
}