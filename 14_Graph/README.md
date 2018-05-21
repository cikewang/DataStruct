# 图
>图（graph）是图型结构的简称，是一种复杂的非线性数据结构。


![图](https://github.com/cikewang/DataStruct/blob/master/Z_Images/14_graph_1.jpg)


### 图的基本术语

	1. 端点和邻接点
		无向图(a)中，若存在一条边，则此边的两个断点，并称互为邻接点（adjacent）
		0的4条边为 (0,1)、(0,2)、(0,3)、(0,4)，0的4个邻接点为1,2,3,4。
		有向图(b)中，<A, C> 两个节点，顶点A(起点|出边邻接点)的一条出边，顶点C(终点|入边邻接点)的一条入边
		
	2. 顶点的度
		无向图(a)中，边数就是度，如0 节点度为4
		有向图(b)中，有出度、入度区分
	
	3. 完全图、稠密图、稀疏图
		完全图：若无向图的每两个顶点之间都存在着一条边，有向图每两个顶点之间都存在着相反的边，称为完全图。
		稠密图：当一个图接近完全图，称为稠密图
		稀疏图：当一个图边较少称为稀疏图
		
	4. 子图
		
	5. 路径和回路
		路径是指从一个顶点到另一个顶点的一条
		路径长度是指该路径上经过的边数
		若一条路径上的前后两端点相同，则称为回路或环
		
	6. 连通和连通分量
		连通图是指顶点a到顶点b有路径，若不连通称为非连通图
		无向图的极大连通图称为连通分量
		
	7. 强连通图和强连接分量
		有向图中，从顶点a到顶点b有路径，则称为a到b是连通的。
		强连通度是指，顶点a到b连通，同时 b到a也连通
		有向图的极大强连通图称为强连通分量
	
	8. 权和网
		权是指边上标记的数字
		网是指边上带有权的图称作带权图
		
### 图的抽象数据类型

~~~
DAT GRAPH is
	Data:
		一个图G，存储类型用标识符 GraphType 表示
	Operations
		// 初始化图的存储空间
		void initGraph(GraphType &G);
		// 跟进图的边际 E 建立图的存储结构
		void greateGraph(GraphType &G, char *E, int n);
		// 按照一定次序从顶点 i 开始遍历图
		void traverseGraph(GraphType &G, int i, int n);
		// 从图中查找给定顶点
		bool findGraph(GraphType &G, vertexType &item, int n);
		// 按照图的一种表示方法输出一个图
		void printGraph(GraphType &G, int n);
		// 清楚图中动态分配的存储空间
		void clearGraph(GraphType &G);
		// 求图中的最小生成树
		void minSpanGraph(GraphType &G, int n);
		// 求图中顶点之间的最短路径
		void minPathGraph(GraphType &G, int n);
		// 求有向图中顶点之间的括扑序列
		void topolGraph(GraphType &G, int n);
		// 求有向图带权图中关键路径
		void keyPathGraph(GraphType &G, int n);
end graph
~~~



### 图的存储结构
图的存储结构又称图的存储表示或图的表示，图的表示方法主要有，邻接矩阵、邻接表和边集数组。

##### 邻接矩阵
	

##### 邻接表


##### 边集数组


### 图的遍历





	