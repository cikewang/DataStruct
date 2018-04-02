# 线性顺序表


### 线性表逻辑结构示意图
![线性表逻辑结构示意图](https://github.com/cikewang/DataStruct/blob/master/Z_Images/01_line_table.jpg)

### 线性表抽象数据类型

~~~
ADT LinearList is 
	Data:
		一个具有 ListType 类型线性表 L

	Operation:
		// 初始化 L 为空
		void initList(ListType &L);	

		// 清除 L 中的所有元素
		void clearList(ListType &L);

		// 返回 L 的长度
		int lengthList(ListType &L);

		// 判断 L 是否为空
		bool emptyList(ListType &L);

		// 返回 L 中第 pos 个元素的值	
		ElemType getList(ListType &L, int post);	

		// 遍历输出 L 中的所有元素
		void traverseList(ListType &L);	

		// 从 L 中查找并返回元素
		bool findList(ListType &L, ElemtType &item);	

		// 修改 L 中的元素
		bool updateList(ListType &L, const ElemType &item);	

		// 向 L 插入元素
		bool insertList(ListType &L, ElemType item, int pos);	

		// 从 L 删除元素
		bool deleteList(ListType &L, ElemType &item, int pos);	

		// 对 L 中的所有元素重新按给定条件排序
		void sortList(LisType &L);	
end LinearList
~~~



