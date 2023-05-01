#include <iostream>
using namespace std;

template<class K,class V>
struct AVTreeNode
{
	AVTreeNode<K, V>* _pLeft;
	AVTreeNode<K, V>* _pRight;
	AVTreeNode<K, V>* _pParent;
	pair<K, V> _kv;
	int _bf;//平衡银子

	AVTreeNode(const pair<K,V> kv)
		:_pLeft(nullptr), _pRight(nullptr), _pParent(nullptr)
		, _kv(kv), _bf(0)
	{}
};

template<class K, class V>
struct AVLtree
{
	typedef AVTreeNode<K, V> Node;
public:
	bool insert(const pair<K, V> kv)
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
			if (cur->_kv.second < kv.second)
			{
				parent = cur;
				cur = cur->_pRight;
			}
			else if (cur->_kv.second > kv.second)
			{
				parent = cur;
				cur = cur->_pLeft;
			}
			else
			{
				return false;
			}
		}
		//找到要插入的位置
		cur = new Node(kv);
		if (cur->_kv.second < parent->_kv.second)
		{
			cur = parent->_pLeft;
		}
		else
		{
			cur = parent->_pRight;
		}
		//孩子也要和父亲相连
		cur->_pParent = parent;

		//更新平衡因子
		while (parent)
		{
			if (cur == parent->_pLeft)
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
				parent = parent->_pParent;
			}
			else if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//旋转
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					_RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					_RotateR(parent);
				}
				else if ()
				{

				}
				else
				{

				}
				break;
			}
			else
			{
				return false;
			}
		}
		return true;
	}

private:
	void _RotateL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)
		{
			pSubRL->_pParent = pParent;
		}

		Node* ppParent = pParent->_pParent;

		pSubR->_pLeft = pParent;
		pParent->_pParent = pSubR;

		if (ppParent == nullptr)
		{
			_root = pSubR;
			pSubR->_pParent = nullptr;
		}
		else
		{
			if (ppParent->_pLeft == pParent)
			{
				ppParent->_pLeft = pSubR;
			}
			else
			{
				ppParent->_pRight = pSubR;
			}
			pSubR->_pParent = ppParent;
		}
		pParent->_bf = pSubR->_bf = 0;
	}
	void _RotateR(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;

		pParent->_pLeft = pSubLR;
		if (pSubLR)
		{
			pSubLR->_pParent = pParent;
		}

		Node* ppParent = pParent->_pParent;

		pSubL->_pRight = pParent;
		pParent->_pParent = pSubL;

		if (ppParent == nullptr)
		{
			_root = pSubL;
			pSubL->_pParent = nullptr;
		}
		else
		{
			if (ppParent->_pLeft == pParent)
			{
				ppParent->_pLeft = pSubL;
			}
			else
			{
				ppParent->_pRight = pSubL;
			}
			pSubL->_pParent = ppParent;
		}
		pParent->_bf = pSubL->_bf = 0;
	}
	//先左单旋，再右单旋
	void _RotateLR(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;

		//通过这个来决定改变的节点的平衡因子怎么变
		int bf = pSubLR->_bf;
		
		_RotateL(pSubL);
		_RotateR(pParent);

		if (bf == 1)
		{
			pParent->_bf = 0;
			pSubL->_bf = -1;
			pSubLR->_bf = 0;
		}
		else if (bf == -1)
		{
			pParent->_bf = 1;
			pSubL->_bf = 0;
			pSubLR->_bf = 0;
		}
		else if (bf == 0)
		{
			pParent->_bf = 0;
			pSubL->_bf = 0;
			pSubLR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	//先右单旋，再左单旋
	void _RotateRL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		//通过这个来决定改变的节点的平衡因子怎么变
		int bf = pSubRL->_bf;

		_RotateR(pSubR);
		_RotateL(pParent);

		if (bf == 1)
		{
			pParent->_bf = -1;
			pSubR->_bf = 0;
			pSubRL->_bf = 0;
		}
		else if (bf == -1)
		{
			pParent->_bf = 0;
			pSubR->_bf = 1;
			pSubRL->_bf = 0;
		}
		else if (bf == 0)
		{
			pParent->_bf = 0;
			pSubR->_bf = 0;
			pSubRL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

private:
	Node* _root = nullptr;
};