# 栈 
	栈（stack）又称堆栈，它是一种运算受限的线性表，其限制是仅允许在表的一端进行插入和删除元素。
	栈  ***后进先出*** (Last In First Out, LIFO)

	
### 栈的抽象数据类型

~~~
ADT STACK is
	Data:
		一个栈S，假定用标识符 StackType 表示栈对象类型
	Operation:
		// 初始化栈S,即把它置为空
		void initStack(StackType &S);
		// 元素进栈
		void push(StackType &S, ElemType item);
		// 元素出栈
		ElemType pop(StackType &S);
		// 返回栈顶元素，但是不改变栈
		ElemType peek(StackType &S);
		// 判断S是否为空
		bool emptyStack(StackType &S);
		// 清空栈
		void clearStack(StackType &S);
end STACK		
~~~

