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
~~~
struct Triple {
	int row, col;
	ElemType val;
}

struct SMatrix {
	int m, n, t;
	Triple sm[maxTerms+1];
}
~~~
	三元组线性表顺序存储， row, col 分别用来存储行号和列好，val用来存储元素值
	m、n 和 t 用来存储稀疏矩阵的行数、列数和非零元素的个数，sm数组域用来存每个三元组元素。 
	

2. 链接存储
	* 带行指针向量的链接存储
	~~~
	struct TripleNode {
		int row, col;		// 存储行号和列好
		ElemType val;		// 存储元素值
		TripleNode *next;	// 指向同一行的下一个结点
	}
	
	struct LMatrix {
		int m, n, t;			// 矩阵 m 行，n 列， 非零元素总共  t 个
		TripleNode *vector[maxRows + 1];	// 用来保存稀疏矩阵所对应的 m个行单链表的表头指针
	}
	~~~
	
![带行指针向量的链接存结构](https://github.com/cikewang/DataStruct/blob/master/Z_Images/05_01.jpg)	
	
	
	* 十字连接存储
		十字链接存储是既带有 ***行指针向量*** 又带 ***列指针向量*** 的链接存储，每一个三元组结点既处于同一行的单链表中，又处于同一列的单链表中。
	~~~
	struct CrossNode {
		int row, col;		
		ElemType val;
		CrossNode *down, *right;
	}
	
	struct CLMatrix {
		int m, n, t;
		CrossNode *rv[maxRows+1];
		CorssNode *cv[maxRows+1];
	}
	~~~
		row 、col 和 val 域分别用来存储非零元素的行号、列号、和元素值，down域用力啊存指向同一列下一个结点指针，right域用来存储指向同一行下一个结点指针，若下一个结点不存在，指针域为空值
![带行指针向量的链接存结构](https://github.com/cikewang/DataStruct/blob/master/Z_Images/05_02.jpg)	
	
	
	





	