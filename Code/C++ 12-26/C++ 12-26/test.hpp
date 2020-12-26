#pragma once
#include <iostream>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& x)
	: left(nullptr)
	, right(nullptr)
	, parent(nullptr)
	, data(x)
	, bf(0)
	{}

	AVLTreeNode<T>* left;
	AVLTreeNode<T>* right;
	AVLTreeNode<T>* parent;
	T data;
	int bf;  // ƽ������
};


template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		: _root(nullptr)
	{}

	bool Insert(const T& data)
	{
		if (nullptr == _root)
		{
			_root = new Node(data);
			return true;
		}

		// �ǿ�
		// 1. ���ն����������Ĺ�������½ڵ�
		// ���½ڵ������еĲ���λ�ã�����¼��˫��
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data < cur->data)
				cur = cur->left;
			else if (data > cur->data)
				cur = cur->right;
			else
				return false;
		}

		// ���½ڵ�����λ���Ѿ��ҵ���---�����½ڵ�
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;
		cur->parent = parent;

		while (parent)
		{
			// �½ڵ����֮��AVL����ƽ���Կ��ܻ��⵽�ƻ�
			// ����Ҫ����ƽ������
			if (cur == parent->left)
				parent->bf--;
			else
				parent->bf++;

			if (0 == parent->bf)
				return true;
			else if (1 == parent->bf || -1 == parent->bf)
			{
				cur = parent;
				parent = cur->parent;
			}
			else
			{
				// parent��ƽ�����ӿ���Ϊ��2 || -2
				if (2 == parent->bf)
				{
					// ��������--->������ת������
					if (1 == cur->bf)
						RotateLeft(parent);
					else
						RotateRL(parent);
				}
				else
				{
					// ��������---->������ת���ҵ���
					if (-1 == cur->bf)
						RotateRight(parent);
					else
						RotateLR(parent);
				}

				break;
			}
		}

		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	bool IsBalanceTree()
	{
		return _IsBalanceTree(_root);
	}

private:
	int _Height(Node* root)
	{
		if (nullptr == root)
			return 0;

		int leftHeight = _Height(root->left);
		int rightHeight = _Height(root->right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	bool _IsBalanceTree(Node* root)
	{
		if (nullptr == root)
			return true;

		int leftHegiht = _Height(root->left);
		int rightHeight = _Height(root->right);
		if (abs(root->bf) > 1 || (rightHeight - leftHegiht != root->bf))
		{
			cout << root->data << ":" << root->bf << endl;
			return false;
		}

		return _IsBalanceTree(root->left) &&
			_IsBalanceTree(root->right);
	}

	void RotateLeft(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;

		parent->right = subRL;
		if (subRL)
			subRL->parent = parent;

		subR->left = parent;

		Node* pparent = parent->parent;
		subR->parent = pparent;
		parent->parent = subR;

		if (nullptr == pparent)
			_root = subR;
		else
		{
			if (parent == pparent->left)
				pparent->left = subR;
			else
				pparent->right = subR;
		}

		parent->bf = subR->bf = 0;
	}

	void RotateRight(Node* parent)
	{
		Node* subL = parent->left;
		Node* subLR = subL->right;

		parent->left = subLR;
		if (subLR)
			subLR->parent = parent;

		subL->right = parent;

		Node* pparent = parent->parent;
		parent->parent = subL;
		subL->parent = pparent;

		if (nullptr == pparent)
			_root = subL;
		else
		{
			if (parent == pparent->left)
				pparent->left = subL;
			else
				pparent->right = subL;
		}

		// ����parent��subL��ƽ������
		parent->bf = subL->bf = 0;
	}

	void RotateRL(Node* parent)
	{
		RotateRight(parent->right);
		RotateLeft(parent);
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->left;
		Node* subLR = subL->right;
		int bf = subLR->bf;
		RotateLeft(parent->left);
		RotateRight(parent);

		if (1 == bf)
			subL->bf = -1;
		else if (-1 == bf)
			parent->bf = 1;

	}

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->left);
			cout << root->data << " ";
			_InOrder(root->right);
		}
	}

private:
	Node* _root;
};


void TestAVLTree1()
{
	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };

	AVLTree<int> t;
	for (auto e : array)
		t.Insert(e);

	// ��֤��
	t.InOrder();

	if (t.IsBalanceTree())
	{
		cout << " t1 is AVL Tree!!!" << endl;
	}
	else
	{
		cout << "t1 is not AVL Tree!!!" << endl;
	}
}

#if 0
void TestAVLTree2()
{
	int array[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

	AVLTree<int> t;
	for (auto e : array)
		t.Insert(e);

	// ��֤��
	t.InOrder();

	if (t.IsBalanceTree())
	{
		cout << " t2 is AVL Tree!!!" << endl;
	}
	else
	{
		cout << "t2 is not AVL Tree!!!" << endl;
	}
}
#endif