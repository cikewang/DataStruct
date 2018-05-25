# 排序

## 插入排序
>插入排序主要包括 *直接插入排序* 和 *希尔排序* 两种

##### 直接插入排序

时间复杂度 O(n²)

~~~
void insertSort(ElemType A[], int n) {
	ElemType x;
	int i, j;
	for (i=1; i<n; i++) {
		x = A[i];
		for (j=i-1; j>=0; j--) {
			if (x.stn < A[j].stn) {
				A[j+1] = A[j];
			} else {
				break;
			}
		}
		A[j+1] = x;
	}
}
~~~

##### 希尔排序
>希尔(Shell)排序又称缩小增量排序，它是对直接插入排序的一种改进方法。

时间复杂度在O(nlbn) 和 O(n²)之间

~~~
void ShellSort(ElemType A[], int n) {
	ElemType x;
	int i, j, d;
	for (d=n/2; d>=1; d/=2) {
		for (i=d; i<n; i++) {
			x = A[i];
			for (j=i-d; j>=0; j-=d) {
				if (x.data < A[j].data) {
					A[j+d] = A[j];
				} else {
					break;
				}
			}
			A[j+d] = x;
		}
	}
}
~~~


## 选择排序

> 选择排序主要包括*直接选择排序*和 *堆排序* 两种

##### 直接选择排序

> 直接选择排序是从待排序的区间中选择出具有最小排序码的元素，把该元素与该区间的第一个元素交换位置。

时间复杂度 O(n²)

~~~
void SelectSort(ElemType A[], int n) {
	ElemType x;
	int i, j, k;
	for (i=1; i<=n-1; i++) {
		k = i-1;
		for (j=i; j<=n-1; j++) {
			if (A[j].data < A[k].data) {
				k = j;
			}
		}
		
		if (k != i-1) {
			x = A[i-1];
			A[i-1] = A[k];
			A[k] = x;
		}
	}
}
~~~


##### 堆排序

> 堆排序是利用堆的特性进行排序的过程。堆主要分为 大根堆 和小根堆

~~~
// 对 A[n]数组中的 A[i]元素进行筛运算，形成以 A[i]为根的堆
void Sift(ElemType A[], int n, int i) {
	// 把待筛结点的值暂存于 x 中
	ElemType x = A[i];
	int j;
	// A[j]是A[i]的左孩子
	j = 2*i+1;
	// 当 A[i]的左孩子不为空时执行循环
	while (j<=n-1) {
		// 若右孩子的排序码较大，则把 j 修改为右孩子的下标
		if (j<n-1 && A[j].data < A[j+1].data) {
			j++;
		}
		// 将 A[j] 调到双亲位置上，修改 i 和 j 的值，以便继续向下筛
		if (x.data < A[j].data) {
			A[i] = A[j];
			i = j;
			j = 2*i+1;
		} else {
			break;
		}
	}
	// 被筛结点的值放入最终位置
	A[i] = x;
}
// 利用堆排序的方法对数组 A中的 n个元素进行排序
void HeapSort(ElemType A[], int n) {
	ElemType x;
	int i;
	for (i=n/2-1; i>=0; i--) {
		Sift(A, n, i);
	}
	
	for (i=1; i<=n-1; i++) {
		x = A[0];
		A[0] = A[n-i];
		A[n-i] = x;
		
		Sift(A, n-i, 0);
	}

}
~~~


## 交换排序

> 交换排序包括 *气泡排序* 和 *快速排序* 两种

##### 气泡排序

> 气泡排序（bubble sorting） 又称冒泡排序

时间复杂度  O(n²)

~~~
void BubbloSort(ElemType A[], int n) {
	ElemType x;
	int i, j, flag;
	
	for (i=1; i<=n-1; i++) {
		flag = 0;
		for (j=n-1; j>=i; j--) {
			if (A[j].data < A[j-1].data) {
				x = A[j-1];
				A[j-1] = A[j];
				A[j] = x;
				flag = 1;
			}
		}
		if (flag == 0) {
			return; 
		}
	}
}
~~~

##### 快速排序

> 快速排序（quick sorting) 又称划分排序。

~~~
// 采用快速排序方法对数组 A中 A[s]~A[t]区间进行排序
// 开始进行非递归调用时 s 和 t的初值分别为 0 和 n-1
// 对当前排序区间进行一次划分
void QuickSort(ElemType A[], int s, int t) {
	int i = s+1, j = t;
	// 把基准元素的值暂存 x 中
	ElemType x = A[s];
	while (i<=j) {
		// 从前向后顺序比较
		while (A[i].data <= x.data && i<=j) {
			i++;
		}
		// 从后向前顺序比较
		while (A[j].data > x.data && j>=i) {
			j--;
		}
		// 当条件成立时交换 A[i]和A[j]的值
		if (i<j) {
			ElemType temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
			j--;
		}
	}
	// 交换 A[s] 和 A[j] 的值，得到前后两个子区间 A[s]~A[j-1]和 A[j+1]~A[t]
	if (s!=j) {
		A[s] = A[j];
		A[j] = x;
	}
	// 在当前左区间内超过一个元素的情况下递归处理左区间
	if (s<j-1) {
		QuickSort(A, s, j-1);
	}
	// 在当前右区间内超过一个元素的情况下递归处理右区间
	if (j+1<t) {
		QuickSort(A, j+1, t);
	}
}
~~~



## 归并排序

> 归并（merge）就是将两个或多个有序表合并成一个有序表的过程。若将两个有序表合并成一个有序表则称为二路归并。

~~~

~~~



 





