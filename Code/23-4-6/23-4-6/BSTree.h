
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
				//要插入的元素在树中已有
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