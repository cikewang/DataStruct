# 特殊二叉树
	特殊二叉树包括二叉搜索树、堆、哈夫曼树、线索二叉树和平衡二叉树等
	

### 二叉搜索树
二叉搜索树(binary searching tree)又称二叉排序树(binary sorting tree)，非空二叉搜索树具有如下特点：
1. 若左子树非空，则左子树上所有结点都小于跟结点
2. 若右子树非空，则右子树上所有结点都大于等于根节点
3. 左、右子树又各是一个二叉搜索树

二叉树搜索树，其结点按照中序遍历得到结点必然是一个有序序列
![树](https://github.com/cikewang/DataStruct/blob/master/Z_Images/12_tree_01.jpg)
<center> 二叉搜索树（图1）</center >

中序遍历得到：12， 15， 18， 23， 26， 30， 52， 63， 74


#### 删除结点
![删除结点](https://github.com/cikewang/DataStruct/blob/master/Z_Images/12_tree_del_1.jpg)
![删除结点](https://github.com/cikewang/DataStruct/blob/master/Z_Images/12_tree_del_2.jpg)

