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
	//��������Ѿ�Ϊ������ô˵���Ѿ��ҵ���ȫ���ڵ㣬��ôȷ��Ϊ����
	if (pRoot2 == NULL)
		return true;

	//��������Ѿ�Ϊ�գ���û�ҵ�˵������������
	if (pRoot1 == NULL)
		return true;

	if (pRoot1->_data != pRoot2->_data)
		return false;

	//��������ݹ��ж���ߵ��Ƿ���ȣ��ұߵ��Ƿ����
	return IsTree1HasTree2(pRoot1->_left, pRoot2->_left) &&
		   IsTree1HasTree2(pRoot1->_right, pRoot2->_right);
}

bool IsChildTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool result = false;
	if (pRoot1 != NULL && pRoot2 != NULL)
	{
		//�����ȣ���ô�ݹ�����Ƚ��Ƿ�ȫ���ڵ����
		if (pRoot1->_data == pRoot2->_data)
			result = IsTree1HasTree2(pRoot1, pRoot2);

		//�ݹ����������
		if (!result)
			result = IsChildTree(pRoot1->_left, pRoot2);

		//�ݹ����������
		if (!result)
			result = IsChildTree(pRoot1->_right, pRoot2);
	}
	return result;
}


#endif //__ISCHILDTREE_H__