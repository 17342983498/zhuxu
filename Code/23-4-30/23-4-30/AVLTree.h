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
			}
			else
			{
				return false;
			}
		}
		return true;
	}

private:
	Node* _root = nullptr;
};