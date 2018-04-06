# 队列
	队列（queue）是一种运算受限的线性表，其限制是仅允许在表的一端进行插入，另一端进行删除。
	队列称为先进先出表（First In First Out， FIFO）
	
### 队列抽象数据类型
~~~
ADT QUEUE is
	Data：
		一个队列Q,假定用标识符 QueueType 表示队列的存储类型
	Operation：
		// 初始化队列 Q，既置为空
		void initQueue(QueueType &Q);
		// 将新元素插入队列尾
		void enQueue(QueuType &Q, ElemType item);
		// 从队列中删除一个首元素并返回
		ElemType outQueue(QueueType &Q);
		// 返回队列首元素，不改变队列状态
		ElemType peekQueue(QueueType &Q);
		// 判断队列是否为空
		bool emptyQueue(QueueType &Q);
		// 清楚队列Q,使之成为空队列
		void clearQueue(QueueType &Q);
end Queue
~~~


### 顺序队列
	顺序队列中进行任何操作的时间复杂度均为O(1),当然队列满时需要复制原队列除外。
	
![顺序队列](https://github.com/cikewang/DataStruct/blob/master/Z_Images/09_01.jpg)
	
