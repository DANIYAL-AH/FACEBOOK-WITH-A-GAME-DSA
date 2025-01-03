//class Lnode
//{
//public:
//	int data;
//	Lnode* next;
//	Lnode* pre;
//	Lnode(int val = 0)
//	{
//		data = val;
//		next = NULL;
//		pre = NULL;
//
//	}
//};
//class LinkList
//{
//public:
//	Lnode* head;
//	Lnode* tail;
//	LinkList()
//	{
//		head = NULL;
//		tail = NULL;
//
//	}
//	void insertatlast(int val)
//	{
//		Lnode* mynode = new Lnode(val);
//		if (head == NULL)
//		{
//			head = mynode;
//			tail = head;
//			tail->next = head;
//			head->pre = tail;
//
//		}
//		else
//		{
//			//node* temp = head;
//
//			while (tail->next != head)
//			{
//
//				//temp = temp->next;
//				tail = tail->next;
//			}
//			tail->next = mynode;
//			mynode->pre = tail;
//			mynode->next = head;
//			tail = mynode;
//			head->pre = tail;
//		}
//
//	}
//	void insertathead(int val)
//	{
//		Lnode* mynewnode = new Lnode(val);
//		if (head == NULL)
//		{
//			head = mynewnode;
//			tail = head;
//			tail->next = head;
//			head->pre = tail;
//		}
//		else
//		{
//
//			mynewnode->next = head;
//			mynewnode->pre = tail;
//			head->pre = mynewnode;
//			tail->next = mynewnode;
//
//		}
//	}
//	void remove(int val)
//	{
//		Lnode* temp = head;
//		if (head->data == val)
//		{
//			head->next->pre = tail;
//			tail->next = head->next;
//			head = head->next;
//
//
//
//
//		}
//		else if (tail->data == val)
//		{
//			tail = tail->pre;
//			tail->next = head;
//			head->pre = tail;
//		}
//		else
//		{
//			while (temp->next != head)
//			{
//				if (temp->data == val)
//				{
//					temp->pre->next = temp->next;
//					temp->next->pre = temp->pre;
//
//				}
//				temp = temp->next;
//			}
//		}
//	}
//
//	void Display()
//	{
//		Lnode* temp = tail;
//		if (tail == NULL)
//		{
//			cout << "EMPTY LIST...." << endl;
//		}
//		else
//		{
//			do
//			{
//				cout << temp->data << endl;
//				temp = temp->pre;
//			} while (temp != tail);
//		}
//	}
//};
//class Stack
//{
//public:
//	int* arr;
//	int size;
//	int top;
//	Stack(int tsize)
//	{
//		size = tsize;
//		arr = new int(size);
//		top = 0;
//
//		/*for (int i = 0; i < size; i++)
//		{
//			arr[i] = -1;
//		}*/
//
//	}
//	bool IsFull()
//	{
//		if (top == size)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	bool IsEmpty()
//	{
//		if (top == 0)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	void push(int val)
//	{
//		if (!IsFull())
//		{
//			arr[top] = val;
//			top++;
//		}
//		else
//		{
//			cout << "Stack Is Full  !!!!" << endl;
//		}
//	}
//	int pop()
//	{
//		if (!IsEmpty())
//		{
//			top--;
//			return arr[top];
//		}
//		else
//		{
//			return -1;
//		}
//	}
//	int topp()
//	{
//		if (!IsEmpty())
//		{
//			return arr[top];
//		}
//		else
//		{
//			return -1;
//		}
//	}
//};
//class BSTNode
//{
//public:
//	int data;
//	BSTNode* left;
//	BSTNode* right;
//	BSTNode(int tdata = 0)
//	{
//		data = tdata;
//		left = right = NULL;
//	}
//};
//class BST
//{
//public:
//	BSTNode* root;
//	BST()
//	{
//		root = NULL;
//	}
//
//	void Insert(int val)
//	{
//		BSTNode* N = new BSTNode(val);
//		if (root == NULL)
//		{
//			root = N;
//		}
//		else
//		{
//			BSTNode* temp = root;
//			while (true)
//			{
//				if (N->data < temp->data)
//				{
//					if (temp->left == NULL)
//					{
//						temp->left = N;
//						return;
//					}
//					temp = temp->left;
//
//				}
//				else
//				{
//					if (temp->right == NULL)
//					{
//						temp->right = N;
//						return;
//					}
//					temp = temp->right;
//				}
//			}
//		}
//
//	}
//
//	void Search(int key)
//	{
//		int flag = 0;
//		BSTNode* temp = root;
//		while (temp != NULL)
//		{
//			if (temp->data == key)
//			{
//				flag = 1;
//				break;
//			}
//			else if (key < temp->data)
//			{
//				temp = temp->left;
//			}
//			else
//			{
//				temp = temp->right;
//			}
//		}
//		if (flag == 1)
//		{
//			cout << "KEY FOUND SUCESSFULLY .....!!" << endl << temp->data << endl;
//
//		}
//		else
//		{
//			cout << "KEY NOT FOUND .....!!" << endl;
//
//		}
//	}
//
//	void MIN()
//	{
//		BSTNode* temp = root;
//		while (temp->left != NULL)
//		{
//			temp = temp->left;
//		}
//		cout << "Minimum Number In Tree Is : " << temp->data << endl;
//
//
//	}
//	void MAX()
//	{
//		BSTNode* temp = root;
//		while (temp->right != NULL)
//		{
//			temp = temp->right;
//		}
//		cout << "Maximum Number In Tree Is : " << temp->data << endl;
//
//
//	}
//	BSTNode* NMAX()
//	{
//		BSTNode* temp = root;
//		while (temp->right != NULL)
//		{
//			temp = temp->right;
//		}
//		return temp;
//
//
//	}
//	int sum = 0;
//	int SUM(BSTNode* temp)
//	{
//		if (temp == NULL)
//		{
//
//			return sum;
//		}
//
//		sum = sum + temp->data;
//		SUM(temp->left);
//		SUM(temp->right);
//
//		return sum;
//
//
//	}
//	int n = 0;
//	int Count(BSTNode* temp)
//	{
//		if (temp == NULL)
//		{
//
//			return n;
//		}
//		n++;
//		Count(temp->left);
//		Count(temp->right);
//
//		return n;
//	}
//	BSTNode* NParent(BSTNode* key)
//	{
//		BSTNode* pt;
//		int flag = 0;
//		BSTNode* temp = root;
//		pt = temp;
//		if (temp->data == key->data)
//		{
//			//cout << "Your Enter Node Is Root Node Which Has No Parent.....!!!" << endl;
//			temp = NULL;
//
//		}
//		else if (key->data < temp->data)
//		{
//			temp = temp->left;
//		}
//		else
//		{
//			temp = temp->right;
//		}
//
//		while (temp != NULL)
//		{
//			if (temp->data == key->data)
//			{
//				flag = 1;
//				break;
//			}
//			else if (key->data < temp->data)
//			{
//				temp = temp->left;
//				pt = pt->left;
//			}
//			else
//			{
//				temp = temp->right;
//				pt->right;
//			}
//		}
//		if (flag == 1)
//		{
//			//cout << "Parent FOUND SUCESSFULLY .....!!" << endl << "Parent = " << pt->data << endl;
//			return  pt;
//
//		}
//		else
//		{
//			//cout << "Parent NOT FOUND .....!!" << endl;
//			return NULL;
//
//		}
//	}
//	void Parent(int key)
//	{
//		BSTNode* pt;
//		int flag = 0;
//		BSTNode* temp = root;
//		pt = temp;
//		if (temp->data == key)
//		{
//			cout << "Your Enter Node Is Root Node Which Has No Parent.....!!!" << endl;
//			temp = NULL;
//
//		}
//		else if (key < temp->data)
//		{
//			temp = temp->left;
//		}
//		else
//		{
//			temp = temp->right;
//		}
//
//		while (temp != NULL)
//		{
//			if (temp->data == key)
//			{
//				flag = 1;
//				break;
//			}
//			else if (key < temp->data)
//			{
//				temp = temp->left;
//				pt = pt->left;
//			}
//			else
//			{
//				temp = temp->right;
//				pt->right;
//			}
//		}
//		if (flag == 1)
//		{
//			cout << "Parent FOUND SUCESSFULLY .....!!" << endl << "Parent = " << pt->data << endl;
//
//		}
//		else
//		{
//			cout << "Parent NOT FOUND .....!!" << endl;
//
//		}
//	}
//
//	int leaf(BSTNode* temp)
//	{
//		int l;
//		int r;
//
//		if (temp == NULL)
//		{
//			return 0;
//		}
//		if (temp->left == NULL && temp->right == NULL)
//		{
//			return temp->data;
//		}
//
//		l = leaf(temp->left);
//		if (l != 0)
//		{
//			cout << l << endl;
//		}
//		r = leaf(temp->right);
//		if (r != 0)
//		{
//			cout << r << endl;
//		}
//		return 0;
//
//	}
//
//	int intermediate(BSTNode* temp)
//	{
//
//		if (temp->left == NULL && temp->right == NULL)
//		{
//			return 0;
//		}
//		if (temp->left != NULL || temp->right != NULL)
//		{
//			if (temp->data != root->data)
//			{
//				cout << temp->data << endl;
//
//			}
//		}
//		return intermediate(temp->left);
//		return intermediate(temp->right);
//
//
//	}
//
//	void remove(int key)
//	{
//		BSTNode* temp = root;
//		BSTNode* p = root;
//		int n = 1;
//		int flag = 0;
//		while (temp != NULL)
//		{
//
//			if (temp->data == key)
//			{
//				flag = 1;
//				break;
//			}
//
//			else if (key < temp->data)
//			{
//				p = p->left;
//				temp = temp->left;
//			}
//			else
//			{
//				p = p->right;
//				temp = temp->right;
//
//			}
//			if (n == 1)
//			{
//				p = root;
//				n++;
//			}
//		}
//
//		if (flag)
//		{
//			if (temp->left == NULL && temp->right == NULL)
//			{
//
//
//				if (p->right == temp)
//				{
//
//					p->right = NULL;
//				}
//				if (p->left == temp)
//				{
//
//					p->left = NULL;
//				}
//				else
//				{
//
//					p = NULL;
//				}
//			}
//
//			else if (temp->left == NULL || temp->right == NULL)
//			{
//
//				if (temp->right == NULL)
//				{
//					if (p->left == temp)
//					{
//						p->left = temp->left;
//					}
//					else
//					{
//
//						p->right = temp->left;
//					}
//
//
//
//				}
//				else if (temp->left == NULL)
//				{
//					if (p->right == temp)
//					{
//						p->right = temp->right;
//					}
//					else
//					{
//						p->left = temp->right;
//					}
//					temp->left = NULL;
//
//				}
//
//				else
//					p = NULL;
//			}
//
//			else
//			{
//				if (p->right == temp)
//				{
//					p->right = (temp->right);
//					Insert(temp->left->data);
//					temp = NULL;
//					delete temp;
//				}
//				else if (p->left == temp)
//				{
//					p->left = temp->right;
//					Insert(temp->right->data);
//					temp = NULL;
//					delete temp;
//
//				}
//				else
//					p = NULL;
//			}
//
//		}
//	}
//	void mirror(BSTNode* temp)
//	{
//		if (temp == NULL)
//		{
//			return;
//		}
//		else
//		{
//			BSTNode* P;
//
//			mirror(temp->left);
//			mirror(temp->right);
//
//			P = temp->left;
//			temp->left = temp->right;
//			temp->right = P;
//		}
//	}
//	int height(BSTNode* temp)
//	{
//		int lh = 0;
//		int rh = 0;
//		int m = 0;
//		if (temp == NULL)
//		{
//			return m;
//		}
//		else
//		{
//			lh = height(temp->left);
//			rh = height(temp->right);
//
//			m = max(lh, rh);
//
//
//			return m + 1;
//		}
//	}
//	int bal_fact(BSTNode* temp)
//	{
//		int balance = 0;
//		int hr = 0;
//		int hl = 0;
//
//
//		hl = height(temp->left);
//		cout << "hl = " << hl << endl;
//		hr = height(temp->right);
//		cout << "hr = " << hr << endl;
//		balance = hl - hr;
//		return balance;
//	}
//
//
//	void Displaypre(BSTNode* temp)
//	{
//		if (temp == NULL)
//		{
//
//			return;
//		}
//		cout << temp->data << endl;
//		Displaypre(temp->left);
//		Displaypre(temp->right);
//	}
//	void Displayin(BSTNode* temp)
//	{
//		if (temp == NULL)
//		{
//
//			return;
//		}
//
//		Displayin(temp->left);
//		cout << temp->data << endl;
//		Displayin(temp->right);
//	}
//	void Displaypost(BSTNode* temp)
//	{
//		if (temp == NULL)
//		{
//
//			return;
//		}
//
//		Displaypost(temp->left);
//		Displaypost(temp->right);
//		cout << temp->data << endl;
//	}
//
//
//};
//class TrNode {
//public:
//	char ch;
//	bool terminal;
//	TrNode* child[26];
//
//	TrNode(char c)
//	{
//		ch = c;
//		terminal = false;
//		for (int i = 0; i < 26; i++)
//		{
//			child[i] = NULL;
//		}
//	}
//};
//class Tries
//{
//public:
//	TrNode* root;
//
//	Tries()
//	{
//		root = createNode('\0');
//	}
//
//	TrNode* createNode(char c)
//	{
//		TrNode* newNode = new TrNode(c);
//		return newNode;
//	}
//
//	void Insert(string word)
//	{
//		TrNode* temp = root;
//		char ch = '\0';
//		int pos = 0;
//		for (int i = 0; i < word.length(); i++)
//		{
//
//			ch = word[i];
//			pos = ch - 'a';
//			if (temp->child[pos] == NULL)
//			{
//				temp->child[pos] = createNode(ch);
//			}
//			temp = temp->child[pos];
//		}
//		temp->terminal = true;
//	}
//
//	void Display(TrNode* temp, string word)
//	{
//		if (temp == NULL)
//			return;
//
//		if (temp != root)
//			word = word + temp->ch;
//		if (temp->terminal)
//			cout << word << endl;
//		for (int i = 0; i < 26; i++)
//		{
//			Display(temp->child[i], word);
//		}
//	}
//
//	TrNode* search(TrNode* temp, string key, int index)
//	{
//
//		if (temp == NULL)
//		{
//			return NULL;
//		}
//
//		char ch = key[index];
//
//		if (temp->terminal && index == key.size())
//		{
//			return temp;
//		}
//		if (ch == '\0')
//		{
//			return NULL;
//		}
//		int i = ch - 'a';
//
//		return	search(temp->child[i], key, ++index);
//
//	}
//};
//
//
//
//
//
//cout <<
//"===========================================================================================" << endl <<
//"     ________________          __________                  " << endl <<
//"    |   _____________|        |   __     '.                " << endl <<
//"    |  |                      |  |  '.    '                " << endl <<
//"    |  |___________           |  |__.'   .'                " << endl <<
//"    |   ___________|          |        .'___               " << endl <<
//"    |  |                      |   ____      '.             " << endl <<
//"    |  |                      |  |     '.     '.           " << endl <<
//"    |  |                      |  |      .      .           " << endl <<
//"    |  |                      |  |____.'     .'            " << endl <<
//"    |__|                      |___________ .'              " << endl <<
//"===========================================================================================" << endl;