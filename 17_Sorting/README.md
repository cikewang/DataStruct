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



## 归并排序

> 归并（merge）就是将两个或多个有序表合并成一个有序表的过程。若将两个有序表合并成一个有序表则称为二路归并。

~~~

~~~



 





