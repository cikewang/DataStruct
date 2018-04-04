# 集合
	集合又称集合结构，由具有相同属性的数据元素组合而成，数据之间没有任何前驱和后继关系。

	
### 集合抽象数据类型
~~~
ADT SET is 
	Data :
		一个集合 S，假定用标识符 SetT 表示抽象存储类型
	Operation:
		void initSet(SetT &s);		// 初始化集合为空
		void clearSet(SetT &s);	// 清除集合中的所有元素
		int lengthSet(SetT &s);	// 求出集合长度
		bool emptySet(SetT &s);	// 判断集合是否为空
		bool inSet(SetT &s, ElemType item);	// 判断一个元素是否属于集合
		void outputSet(SetT &s);	// 输出集合中所有元素
		bool findSet(SetT &s, ElemType &item); // 从集合中查找一个元素
		bool modifySet(SetT &s, const ElemType &item);	// 修改集合元素
		bool insertSet(SetT &s, ElemType item);	// 向集合插入一个元素
		bool deleteSet(SetT &s, ElemType &item);	// 从集合删除一个元素
		void unionSet(SetT &s1, SetT &s2, SetT &s);	// 求两个集合并集
		void interseSet(SetT &s1, SetT &s2, SetT &s);	// 求两个集合交集
		void differenceSet(SetT &s1, SetT &s2, SetT &s);	// 求两个集合差集
end SET
~~~




