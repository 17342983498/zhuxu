#pragma once

#include <iostream>
#include <assert.h>
using namespace std;
template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V> *_pLeft;
	AVLTreeNode<K, V> *_pRight;
	AVLTreeNode<K, V> *_pParent;
	pair<K, V> _kv;
	int _bf;

	AVLTreeNode(const pair<K, V>& kv)
		:_pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:

	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = parent->_pRight;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = parent->_pLeft;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_pRight = cur;
		}
		else
		{
			parent->_pLeft = cur;
		}
		cur->_pParent = parent;


		while (parent)
		{
			if (parent->_pLeft == cur)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = cur->_pParent;
			}
			else if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)//需要旋转
			{
				if (parent->_bf == 2 && cur->_bf == 1)//左单旋
				{
					_RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)//右单旋
				{
					_RotateR(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)//先左单旋，后右单旋
				{
					_RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)//先右单旋，后左单旋
				{
					_RotateRL(parent);
				}
				else
				{
					assert(false);
				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}

	int Height()
	{
		return _Height(_root);
	}

private:
	int _Height(Node* root)
	{
		if (root == NULL)
			return 0;

		int leftH = _Height(root->_pLeft);
		int rightH = _Height(root->_pRight);

		return leftH > rightH ? leftH + 1 : rightH + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == NULL)
		{
			return true;
		}

		int leftH = _Height(root->_pLeft);
		int rightH = _Height(root->_pRight);

		if (rightH - leftH != root->_bf)
		{
			cout << root->_kv.first << "节点平衡因子异常" << endl;
			return false;
		}

		return abs(leftH - rightH) < 2
			&& _IsBalance(root->_pLeft)
			&& _IsBalance(root->_pRight);
	}

	void _RotateL(Node* parent)
	{
		Node* subR = parent->_pRight;
		Node* subRL = subR->_pLeft;
		parent->_pRight = subRL;
		if (subRL)
			subRL->_pParent = parent;
		Node* ppnode = parent->_pParent;
		subR->_pLeft = parent;
		parent->_pParent = subR;
		if (ppnode == nullptr)
		{
			_root = subR;
		}
		else
		{
			if (ppnode->_pLeft == parent)
			{
				ppnode->_pLeft = subR;
			}
			else
			{
				ppnode->_pRight = subR;
			}

			subR->_pParent = ppnode;
		}
		parent->_bf = subR->_bf = 0;
	}
	void _RotateR(Node* parent)
	{
		Node* subL = parent->_pLeft;
		Node* subLR = subL->_pRight;

		parent->_pLeft = subLR;
		if (subLR)
			subLR->_pParent = parent;

		Node* ppnode = parent->_pParent;

		subL->_pRight = parent;
		parent->_pParent = subL;

		if (parent == _root)
		{
			_root = subL;
			_root->_pParent = nullptr;
		}
		else
		{
			if (ppnode->_pLeft == parent)
			{
				ppnode->_pLeft = subL;
			}
			else
			{
				ppnode->_pRight = subL;
			}
			subL->_pParent = ppnode;
		}

		subL->_bf = parent->_bf = 0;
	}
	void _RotateRL(Node* parent)
	{
		Node* subR = parent->_pRight;
		Node* subRL = subR->_pLeft;

		//通过这个来决定改变的节点的平衡因子怎么变
		int bf = subRL->_bf;

		_RotateR(subR);
		_RotateL(parent);

		if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	void _RotateLR(Node* parent)
	{
		Node* subL = parent->_pLeft;
		Node* subLR = subL->_pRight;
		int bf = subLR->_bf;
		_RotateL(subL);
		_RotateR(parent);

		if (bf == 1)
		{
			parent->_bf = 0;
			subLR->_bf = 0;
			subL->_bf = -1;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subLR->_bf = 0;
			subL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subLR->_bf = 0;
			subL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_pLeft);
		cout << root->_kv.first << " ";
		_InOrder(root->_pRight);
	}

	Node* _root = nullptr;
};


void Test_AVLTree1()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t1;
	for (auto e : a)
	{

		t1.insert(make_pair(e, e));
		//cout << e << "插入：" << t1.IsBalance() << endl;
	}

	t1.InOrder();
	cout << t1.IsBalance() << endl;
}