# 链表

### 线性表的链接存储
	单向链接表：在每个结点中除包含有数值域外，只设置一个指针域，用以指向其后继结点。
	双向连接表：在每个结点中除包含有数值域外，设置两个指针域，分别指向其前驱结点和后继结点。
	
### 线性表链接表逻辑结构示意图
![线性表逻辑结构示意图](https://github.com/cikewang/DataStruct/blob/master/Z_Images/02_linked.jpg)


### 单链接表上的插入和删除操作
![单链接表上的插入](https://github.com/cikewang/DataStruct/blob/master/Z_Images/02_linked_add.jpg)
>插入结点：
>1. 将a结点指针域的值q赋给b结点的指针域
>2. 将b结点指针赋值给a结点的指针域

(注意：单链表插入结点，首先要把原表头指针赋给新结点的指针域，然后再把新结点的存储位置赋给表头指针变量)

![单链接表上的删除](https://github.com/cikewang/DataStruct/blob/master/Z_Images/02_linked_delete.jpg)
>删除结点：
>1. 将a结点指针域的值q赋给一个临时指针变量s，以便处理和回收该结点
>2. 将b结点指针域的值q赋给a结点的指针域

(注意：单链表删除结点，首先把表头指针赋给一个临时指针变量，以便处理和回收该结点，然后再把原表头结点指针域的值赋给表头指针变量，使其下一个结点成为新的表头结点)


### 双向链表中的结点类型插入和删除操作
~~~
struct DNode {
	ElemType data;
	DNode *left;
	DNode *right;
};
~~~
>插入结点：设p和q分配是具有DNode*类型的指针变量，若在双链表中p结点之后插入一个q结点，则需要修改4个指针域的值
>1. 使p结点的后继结点成为q结点的后继结点
	~~~
	q->right = p->right;
	~~~ 
>2. 若p结点有后继结点，则使q结点成为该结点的前驱结点
	if(p->right) p->right->left = q;
>3. 使p结点成为q结点的前驱结点
	q->left = p;
>4. 使q结点成为p结点的后继结点
	p->right = q;
	
	
>删除结点：若删除双向链表中p指针所指向的结点，假定p结点前后都有存在着结点，则只需要修改两个指针
>1. 修改p结点的前驱结点的右指针，使之指向p结点的后继结点
	p->left->right = p->right;
>2. 修改p结点的后继结点的左指针域，使之指向p结点的前驱结点
	p->right->left = p->left;
>3. 回收 p 结点
	delete p;
	

	
