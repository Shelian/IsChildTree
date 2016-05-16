#ifndef __ISCHILDTREE_H__
#define __ISCHILDTREE_H__
#include <iostream>
using namespace std;

struct BinaryTreeNode
{
	int _data;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};

bool IsTree1HasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	//如果子树已经为空了那么说明已经找到了全部节点，那么确定为子树
	if (pRoot2 == NULL)
		return true;

	//如果父树已经为空，还没找到说明，不是子树
	if (pRoot1 == NULL)
		return true;

	if (pRoot1->_data != pRoot2->_data)
		return false;

	//如果相等则递归判断左边的是否相等，右边的是否相等
	return IsTree1HasTree2(pRoot1->_left, pRoot2->_left) &&
		   IsTree1HasTree2(pRoot1->_right, pRoot2->_right);
}

bool IsChildTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool result = false;
	if (pRoot1 != NULL && pRoot2 != NULL)
	{
		//如果相等，那么递归遍历比较是否全部节点相等
		if (pRoot1->_data == pRoot2->_data)
			result = IsTree1HasTree2(pRoot1, pRoot2);

		//递归遍历左子树
		if (!result)
			result = IsChildTree(pRoot1->_left, pRoot2);

		//递归遍历右子树
		if (!result)
			result = IsChildTree(pRoot1->_right, pRoot2);
	}
	return result;
}


#endif //__ISCHILDTREE_H__