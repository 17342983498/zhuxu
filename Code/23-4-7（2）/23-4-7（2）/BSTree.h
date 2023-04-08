
template<class T>
struct BSTNode
{
	BSTNode(const T& key = T())
	:_pleft(nullptr), _pright(nullptr), _key(key)
	{}
	BSTNode<T>* _pleft;
	BSTNode<T>* _pright;
	T _key;
};

template<class T>
class BSTree
{
	typedef BSTNode<T> Node;

public:
	Node* Find(const T& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_pright;
			}
			else if (cur->_key > key)
			{
				cur = cur->_pleft;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	bool Insert(const T& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* newnode = new Node(key);
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_pright;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_pleft;
			}
			else
			{
				//Ҫ�����Ԫ������������
				return false;
			}
		}
		if (parent->_key > key)
		{
			parent->_pleft = newnode;
		}
		else
		{
			parent->_pright = newnode;
		}
		return true;
	}

	bool Erase(const T& key)
	{
		if (_root == nullptr)
		{
			return false;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		//��Ҫɾ���Ľڵ�������
		while (cur)
		{
			if (cur->_key == key)
			{
				break;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_pright;
			}
			else
			{
				parent = cur;
				cur = cur->_pleft;
			}
		}

		//û�ҵ�
		if (cur == nullptr)
		{
			return false;
		}

		//Ҫɾ���Ľڵ�û���Һ��ӻ�����Ҷ�ڵ�
		if (cur->_pright == nullptr)
		{
			if (parent == nullptr)
			{
				_root = cur->_pleft;
			}
			else
			{
				if (cur == parent->_pleft)
				{
					parent->_pleft = cur->_pleft;
				}
				else
				{
					parent->_pright = cur->_pleft;
				}
			}
		}
		else if (cur->_pleft == nullptr)
		{
			if (parent == nullptr)
			{
				_root = cur->_pright;
			}
			else
			{
				if (cur == parent->_pleft)
				{
					parent->_pleft = cur->_pright;
				}
				else
				{
					parent->_pright = cur->_pright;
				}
			}
		}
		//Ҫɾ���Ľڵ����Һ��Ӷ��У�����Ҫ�ҵ�����ڵ�������������
		else
		{
			Node* del = cur->_pright;
			parent = cur;
			while (del->_pleft)
			{
				parent = del;
				del = del->_pleft;
			}
			//del���ǿ����滻�Ľڵ㣬��del��ֵ�滻��Ҫɾ���Ľڵ�λ�ô�
			cur->_key = del->_key;
			//Ȼ���del�ڵ�ɾ������
			if (del==parent->_pleft)
			{
				parent->_pleft = del->_pright;
			}
			else
			{
				parent->_pright = del->_pright;
			}
			cur = del;
		}
		delete cur;
		return true;
	}


	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}

	void _Inorder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Inorder(root->_pleft);
		cout << root->_key << " ";
		_Inorder(root->_pright);
	}
private:
	Node* _root = nullptr;
};