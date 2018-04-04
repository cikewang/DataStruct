# 稀疏矩阵

	矩阵：具有 m行  X n列的数表，共包含 mXn个元素。
	稀疏矩阵：是矩阵的一种特殊情况，其非零元素个数远远小于零元素的个数。
	稀疏矩阵的三元组线性表表示 ： (i, j, Aij), i 行号， j 列号， Aij 元素值
	
	如图：
![稀疏矩阵](https://github.com/cikewang/DataStruct/blob/master/Z_Images/05_sparsematrix.jpg)
	

### 稀疏矩阵的抽象数据类型
~~~
ADT SparseMatrix is 
	Data :
	
	Operation:
		// 初始化稀疏矩阵 M，使它成为不含任何元素的空矩阵
		void initMatrix(SMatrix &M);
		// 求出稀疏矩阵M的转置矩阵并返回
		SMatrix transpose(SMatrix &M);
		// 求出 M1 和 M2 稀疏矩阵之和并返回
		SMatrix add(SMatrix &M1, SMatrix &M2);
		// 求出 M1 和 M2 稀疏矩阵之乘积并返回
		SMatrix multiplay(SMatrix &M1, SMatrix &M2);
		// 按照一定格式向稀疏矩阵M输入所对应的三元组线性表
		void inputMatrix(SMatrix &M, int m, int n);
		// 按照一定格式输出稀疏矩阵M
		void outputMatrix(SMatrix &m);
end SparseMatrix
~~~



### 稀疏矩阵的存储结构
1. 顺序存储


2. 链接存储
	* 带行指针向量的链接存储
	
	
	* 十字连接存储
	
	
	
	





	