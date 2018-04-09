# 树

### 树的定义
树（tree）是树形结构的简称。它是一种重要的非线性数据结构。

![树](https://github.com/cikewang/DataStruct/blob/master/Z_Images/11_tree_01.jpg)
（图）树的结构

在一颗舒总，每个结点被定义为它的每个子树的根结点的前驱，而它的每个子树的根结点成为它的后继。

### 树的基本术语
* 结点的度和树的度
	每个结点具有的子树数或者说后继结点数被定义为该结点的度（degree）。
	树种所有结点的度的最大值被定义为该树的度。
	如上图：B结点度为3， A、E结点度为2， C结点度为1， 其余结点的度均为0。因所谓结点的最大的度为3，所以该树的度为3
	
* 分支结点和叶子结点
	在一棵树中，度等于0的结点称为叶子结点或终端结点，度大于0的结点称为分子结点或非终端结点。
	如上图：D、H、I、F、G 都是叶子结点；A、B、C、E为分支结点；其中 C为单分支结点，A和E为双分支结点，B为三分支结点。
	
* 孩子结点、双亲结点和兄弟结点
	在一棵树中，每个结点的子树的根，或者说每个结点的后继，被习惯地称作该结点的孩子、儿子后子女，相应地，该结点的被称为孩子结点的双亲、父亲或父母。
	如上图：B结点的孩子结点为D、E、F结点，双亲为A结点，D、E、F互为兄弟，B结点的子孙为D、E、H、I、F结点，I结点的祖先为A、B、E结点

* 结点的层度和树的深度
	树即是一种递归结构，也是一种层次结构，树种每个结点都处在一定的层数上。
	结点的层数（level）从树根开始定义，根结点为第1层，它的孩子结点为第2层，以此类推。
	树中所有结点的最大层数称为树的深度或者高度
	如上图：A结点处于第1层，B、C结点处于第2层， D、E、F、G结点处于第3层，H、I结点处于第4层，第4层为树中所有结点最大层数，所以上图树的深度为4	

* 有序树和无序树
	若树中各结点的子树是按照一定的次序从左向右安培的，则称为有序树，否则称为无序树。
	
* 森林
	森林是m(m>=0)课互不相交的树的集合
	
	
### 树的性质
1. 树中结点数等于所有结点的度数加1
2. 度为k的树中第i层上至多有  <img src="https://latex.codecogs.com/gif.latex?k^{i-1}" title="k^{i-1}" /> 个结点 (<img src="https://latex.codecogs.com/gif.latex?i\geq&space;1" title="i\geq 1" />)
3. 深度为h的k叉树至多有  <img src="https://latex.codecogs.com/gif.latex?\frac{k^h-1}{k-1}" title="\frac{k^h-1}{k-1}" /> 个结点
4. 具有n个结点的k叉树的最小深度为 <img src="https://latex.codecogs.com/gif.latex?$\log_k{(n(k-1)+1)}$" title="$\log_k{(n(k-1)+1)}$" />


### 二叉树
	二叉树（binary tree）是指树的度为2的有序树。

### 二叉树的性质
1. 二叉树的终端结点数等于双分支结点数加1
2. 二叉树上第i层至多有  <img src="https://latex.codecogs.com/gif.latex?2^{i-1}" title="2^{i-1}" /> 个结点(<img src="https://latex.codecogs.com/gif.latex?i\geq&space;1" title="i\geq 1" />)
3. 深度为h的二叉树至多有 <img src="https://latex.codecogs.com/gif.latex?2^h-1" title="2^h-1" /> 个结点
	* 满二叉树 ：当第i层的结点数为 <img src="https://latex.codecogs.com/gif.latex?2^{i-1}" title="2^{i-1}" />个时，则称此层的节点数是满的
	* 完全二叉树 ：二叉树中，除最后一层外，若其余层都是满的，并且最后一层是满的或者缺少连续若干个结点。
4. 对完全二叉树中编号为 i的结点（1<=i<=n, n>=1, n为结点数），有如下性质
	* 若编号为 i，则左孩子结点编号为 2i， 右孩子结点编号为 2i-1
	* 除树根节点外，若一个结点的编号为 i，当i为偶数，则它的双亲结点为 i/2，该节点为左结点，当i为奇数，其双亲结点的编号为 （i-1）/2，该结点的右孩子 
	* 若 i<=[n/2]，既 2i<=n， 则编号为 i 的结点为分支结点，否则为叶子结点
	* 若 n为奇数，则每个分支结点都既有左孩子又有右孩子；若n为偶数，则编号最大的分支结点（编号为 n/2）只有左孩子，没有右孩子，其余分支结点左、右孩子都有。
5. 具有 n个（n>0）结点的完全二叉树的深度为  lb(n+1) 或 lbn+1
	* 注：lb 以2为底的对数，例如：lb(2)=1，lb(1024)=10。
	* 理想二叉树：除了最后一层外，其余层都是满的，最后一层上的结点可以任何分布。

### 二叉树的抽象数据类型
~~~
DATA BinaryTree is
	Data:
		
	Operations
		// 初始化二叉树，既把它置为空
		void initBTree(BTreeType &BT);
		// 跟进广义表表示的二叉树简历对应的存储结构
		void createBTree(BTreeType &BT, char *a);
		// 判断一个二叉树是否为空
		bool emptyBTree(BTreeType &BT);
		// 按照一定次序遍历一颗二叉树
		void traverseBTree(BTreeType &BT);
		// 从二叉树中查找为值为 item 的结点，若存在该结点则有 item 带回它的完整值
		bool findBTree(BTreeType &BT, ElemType &item);
		// 求出一颗二叉树的深度
		int btreeDepth(BTreeType &BT);
		// 按照树的一种表示方式输出一颗二叉树
		void prointBTree(BTreeType &BT);
		// 清楚二叉树中的所有结点，使之变为一颗空数
		void clearBTree(BTreeType &BT); 
end BinaryTree
~~~


### 二叉树的存储结构
1. 顺序存储结构
	若一个结点为i，则 左孩子为 2i，右孩子为 2i+1<br>
![二叉树顺序存储结构](https://github.com/cikewang/DataStruct/blob/master/Z_Images/11_02.jpg)<br>
二叉树顺序存储结构图

2. 链接存储结构
	结点中设置3域：值域、左指针、右指针<br>
![二叉树链接存储结构](https://github.com/cikewang/DataStruct/blob/master/Z_Images/11_03.jpg)<br>
二叉树链接存储结构图	

### 二叉树遍历
1. 前序遍历 （根左右）
		
2. 中序遍历 （左根右）
3. 后续遍历 （左右根）


