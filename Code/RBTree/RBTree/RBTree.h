#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

enum colour
{
	RED,
	BLACK,
};

template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K, V> *_pLeft;
	RBTreeNode<K, V> *_pRight;
	RBTreeNode<K, V> *_pParent;
	pair<K, V> _kv;
	colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};



template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	~RBTree()
	{
		_Destroy(_root);
		_root = nullptr;
	}

	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
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


		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_pParent;
			if (parent == grandfather->_pLeft)
			{
				Node* uncle = grandfather->_pRight;
				//情况一：cur为红，p为红，g为黑，u存在且为红
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					//还得继续往上调整
					cur = grandfather;
					parent = cur->_pParent;
				}
				//情况二、三：cur为红，p为红，g为黑，u不存在/u存在且为黑
				//旋转+变色
				else
				{
					if (cur == parent->_pLeft)
					{
						_RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						_RotateL(parent);
						_RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else
			{
				Node* uncle = grandfather->_pLeft;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					//还得继续往上调整
					cur = grandfather;
					parent = cur->_pParent;
				}
				//情况二、三：cur为红，p为红，g为黑，u不存在/u存在且为黑
				//旋转+变色
				else
				{
					if (cur == parent->_pRight)
					{
						_RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						_RotateR(parent);
						_RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}
		_root->_col = BLACK;
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
	void _Destroy(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Destroy(root->_pLeft);
		_Destroy(root->_pRight);
		delete root;
	}

	bool _Check(Node* root, int blackNum, int benchmark)
	{
		if (root == nullptr)
		{
			if (benchmark != blackNum)
			{
				cout << "某条路径黑色节点的数量不相等" << endl;
				return false;
			}
			return true;
		}

		if (root->_col == BLACK)
		{
			++blackNum;
		}

		if (root->_col == RED
			&& root->_pParent
			&& root->_pParent->_col == RED)
		{
			cout << "存在连续的红色节点" << endl;
			return false;
		}

		return _Check(root->_pLeft, blackNum, benchmark)
			&& _Check(root->_pRight, blackNum, benchmark);
	}


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
		if (_root && _root->_col == RED)
		{
			cout << "根节点颜色是红色" << endl;
			return false;
		}

		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				++benchmark;
			cur = cur->_pLeft;
		}

		// 连续红色节点
		return _Check(_root, 0, benchmark);
	}


	//不行呀

	//bool _IsBalance(Node* root, int flag, int benchmark)
	//{
	//	if (_root && _root->_col == RED)
	//	{
	//		cout << "根节点颜色是红色" << endl;
	//		return false;
	//	}
	//	if (flag == 0)
	//	{
	//		benchmark = 0;
	//		Node* cur = _root;
	//		while (cur)
	//		{
	//			if (cur->_col == BLACK)
	//				++benchmark;
	//			cur = cur->_pLeft;
	//		}
	//		flag = 1;
	//	}
	//	if (root == nullptr)
	//	{
	//		if (benchmark != blackNum)
	//		{
	//			cout << "某条路径黑色节点的数量不相等" << endl;
	//			return false;
	//		}
	//		return true;
	//	}
	//	if (root->_col == BLACK)
	//	{
	//		++blackNum;
	//	}

	//	if (root->_col == RED
	//		&& root->_pParent
	//		&& root->_pParent->_col == RED)
	//	{
	//		cout << "存在连续的红色节点" << endl;
	//		return false;
	//	}
	//	return _IsBalance(root->_pLeft, flag, benchmark)
	//		&& _IsBalance(root->_pRight, flag, benchmark);
	//}

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


void Test_RBTree1()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	RBTree<int, int> t1;
	for (auto e : a)
	{

		t1.insert(make_pair(e, e));
		//cout << e << "插入：" << t1.IsBalance() << endl;
	}

	t1.InOrder();
	cout << t1.IsBalance() << endl;
}