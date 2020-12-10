#pragma once
#include <iostream>
using namespace std;

template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
	:_pLeft(nullptr)
	, _pRight(nullptr)
	, data(data)
	{}
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	T data; 
};

template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()
		:root(nullptr)
	{}

	~BSTree()
	{
		_Destroy(root);
	}

	Node* Find(const T& data)
	{
		Node* cur = root;
		while (cur)
		{
			if (cur->_data == data)
			{
				return cur;
			}
			else if (data > cur->_data)
			{
				cur = cur->_pRight;
			}
			else
				cur = cur->_pLeft;
		}
		return nullptr;
	}

	bool Insert(const T& data)
	{
		if (root == nullptr)
		{
			root = new Node(data);
			return true;
		}
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data < cur->data)
			{
				cur = cur->_pLeft;
			}
			else if (data>cur->data)
			{
				cur = cur->_pRight;
			}
			else
				return false;
		}
		cur = new Node(data);
		if (data < parent->data)
			parent->_pLeft = cur;
		else
			parent->_pRight = cur;
		return true;
	}

	void InOrder()
	{
		_InOrder(root);
	}

	void _Destroy(Node*& root)//��Ҫ�õ�ָ�����û��Ŷ���ָ��
	{
		if (root)
		{
			_Destroy(root->_pLeft);
			_Destroy(root->_pRight);
			delete root;
			root = nullptr;
		}
	}

	bool Erase(const T& data)
	{
		if (nullptr == root)
		{
			return false;
		}

		// BSTree�ǿ�
		// 1. �Ҵ�ɾ���ڵ���BSTree�е�λ�ã���������˫��
		Node* parent = nullptr;
		Node* cur = root;
		while (cur)
		{
			if (data == cur->data)
				break;
			else if (data < cur->data)
			{
				parent = cur;
				cur = cur->_pLeft;
			}
			else
			{
				parent = cur;
				cur = cur->_pRight;
			}
		}

		// ֵΪdata�Ľڵ㲻����
		if (nullptr == cur)
		{
			return false;
		}

		// 2. ɾ���ڵ�
		// cur���ֻ���Һ��� ���� Ҷ�ӽڵ�
		if (nullptr == cur->_pLeft)
		{
			if (nullptr == parent)//ɾ��ͷ�ڵ㣬ֻ��������
			{
				root = cur->_pRight;
			}
			else
			{
				if (cur == parent->_pLeft)
					parent->_pLeft = cur->_pRight;
				else
					parent->_pRight = cur->_pRight;
			}
		}
		else if (nullptr == cur->_pRight)
		{
			// curֻ������
			if (nullptr == parent)
			{
				root = cur->_pLeft;
			}
			else
			{
				if (cur == parent->_pLeft)
					parent->_pLeft = cur->_pLeft;
				else
					parent->_pRight = cur->_pLeft;
			}
		}
		else
		{
			// cur���Һ��Ӿ�����
			// ������ڵ�--->���裺��������������ڵ�
			Node* del = cur->_pRight;
			parent = cur;
			while (del->_pLeft)
			{
				parent = del;
				del = del->_pLeft;
			}

			// ������ڵ��е�ֵ�򽻸�֮ǰҪɾ����cur
			cur->data = del->data;

			// �൱�ڱ��Ҫɾ��del
			if (del == parent->_pLeft)
				parent->_pLeft = del->_pRight;
			else
				parent->_pRight = del->_pRight;

			cur = del;
		}

		delete cur;
		return true;
	}
private:
	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->_pLeft);
			cout << root->data<<" ";
			_InOrder(root->_pRight);
		}
	}
	Node* root;
};

void BSTreeTest()
{
	int a[] = { 5, 1, 3, 0, 6, 8, 7, 9, 4, 2 };
	BSTree<int> T;
	for (auto e : a)
	{
		T.Insert(e);
	}
	T.InOrder();
	T.Erase(5);
	T.InOrder();
}