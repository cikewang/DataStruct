# 链表

### 线性表的链接存储
	单向链接表：在每个结点中除包含有数值域外，只设置一个指针域，用以指向其后继结点。
	双向连接表：在每个结点中除包含有数值域外，设置两个指针域，分别指向其前驱结点和后继结点。
	
### 线性表链接表逻辑结构示意图
![线性表逻辑结构示意图](https://github.com/cikewang/DataStruct/blob/master/Z_Images/02_linked.jpg)


### 单链接表上的插入和删除操作
![单链接表上的插入](https://github.com/cikewang/DataStruct/blob/master/Z_Images/02_linked_add.jpg)
>1. 将a结点指针域的值q赋给b结点的指针域
>2. 将b结点指针域赋值给a结点的指针域

(注意：单链表插入结点，首先要把原表头指针赋给新结点的指针域，然后再把新结点的存储位置赋给表头指针变量)

![单链接表上的删除](https://github.com/cikewang/DataStruct/blob/master/Z_Images/02_linked_delete.jpg)
>1. 将a结点指针域q赋给一个临时指针变量s，以便处理和回收该结点
>2. 将b结点指针域的值q赋给a结点的指针域

(注意：单链表删除结点，首先把表头指针赋给一个临时指针变量，以便处理和回收该结点，然后再把原表头结点指针域的值赋给表头指针变量，使其下一个结点成为新的表头结点)



