# 图的应用

## 图的生成树和最小生成树

>最小生成树：具有权最小的生成树
求图的最小生成树的算法主要有两个：*普里姆（Prim）算法* 和 *克鲁斯卡尔（Kruskal）算法*

### 普里姆算法

>从一个顶点开始，依次找一条最小权的边，知道把所有顶点都连接到即为最小生成树

算法：时间复杂度O(n²)，空间复杂度O(1)

~~~
// 利用普里姆算法从订单 0出发求出邻接矩阵GA表示的图
// 最小生成树，最小生成树的边际存于数组 CT中
void Prim(adjmatrix GA, edgeset CT, int n) {
	int i, j, k, min, t, m, w;
	// 给CT赋初值，对应第0次 LW值
	for (i=0; i<n-1; i++) {
		CT[i].formvex = 0;
		CT[i].endvex = i+1;
		CT[i].weight = GA[0].[i+1];
	}
	
	// 进行 n-1 次循环，每次求出最小生成树中的第 k 条边
	for (k=1; k<n; k++) {
		// 从 CT[k-1] ~ CT[n-2] 中查找最短边CT[m]
		min = maxValue;
		m = k-1;
		for (j=k-1; j<n-1; j++){
			if (CT[j].weight < min) {
				min = CT[j].weight;
				m=j;
			}
		}
	}
	
	// 把最短边对调成第 k-1 下标位置
	edge temp = CT[k-1];
	CT[k-1] = CT[m];
	CT[m] = temp;
		
	// 把新并入最小生成树T中的顶点需要赋给 j
	j = CT[l-1].endvex;
	
	// 修改 LW 中的有关边，使 T中到 T外的每一个顶点各保持一条到目前为止最短的边
	for (i=k; i<n-1; i++) {
		t = CT[i].endvex;
		w = GA[j][t];
		if (w < CT[i].weight) {
			CT[i].weight = w;
			CT[i].fromvex = j;
		}
	}
}
~~~


### 克鲁斯卡尔算法

>克鲁斯卡尔算法：设图使用边集数组表示，且数组中个边是按照权值从小到大的顺序排列，若没有按序排列，则可通过调用排序算法，使之成为有序。
从边集数组中依次选取做为树的边，不产生回路的边保留，产生回路的边舍去，总共取 n-1条边,n 为顶点数

>实现克鲁斯卡尔算法的关键之处是：如何判断欲加入T中的一条边是否与生成树中已保留的边行程回路。

算法：时间复杂度O(n²)，空间复杂度O(n²)

~~~
// 求边集数组 GE 所示图的最小生成树，树中每条边依次存于数组 CT 中
void kruskal(edgeset GE, edgeset CT, int n) {
	int i, j;
	// 定义具有 n*n 个元素的动态分配二维数组 s
	bool **s = new bool*[n];
	for (i=0; i<n; i++) {
		s[i] = new bool[n];
	}
	
	// 初始化 s集合，使每一个顶点分属于对应集合
	for (j=0; j<n; j++) {
		if (i==j) {
			s[i][j] = true;
		} else {
			s[i][j] = false;
		}
	}
	
	// 定义相应变量
	int k = 1; // k 表示待获取的最小生成树的边数，初始值为1
	int d = 0; // d 表示 GE 中待扫描边元素的下标位置，初值为 0
	int m1, m2; // m1 和 m2 分别保存一条边的两个顶点所在集合的序号
	// 进行 n-1 次循环，得到最小生成树中的 n-1条边
	while (k<n) {
		for (i=0; i<n; i++) {
			// 求出边 GE[d] 的两个定点所在集合的序号 m1 和 m2
			if (s[i][GE[d].fromvex] == true) {
				m1 = i;
			}
			if (s[i][GE[d].endvex == true) {
				m2 = i;
			}
		}
		
		if (m1 != m2) {
			// 若两个集合序号不等，则表明 GE[d]是生成树中的一条边应将它加入到数组 CT中
			CT[k-1] = GE[d];
			k++;
			for (j=0; j<n; j++) {
				s[m1][j] = s[m1][j] || s[m2][j];
				s[m2][j] = false;
			}
		}
		d++;  // d 后移一个位置，以便扫描 GE 中的下一条边
	}
	// 释放为 s动态分配的数组空间
	for (i=0; i<n; i++) {
		delete[] s[i];
	}
	delete []s;
}
~~~



## 最短路径


## 括扑排序


## 关键路径


