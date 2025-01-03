//#include<iostream>
//#include<string>
//using namespace std;
////class Node {
////public:
////	char ch;
////	bool terminal;
////	Node* child[62];
////
////	Node(char c)
////	{
////		ch = c;
////		terminal = false;
////		for (int i = 0; i < 62; i++)
////		{
////			child[i] = NULL;
////		}
////	}
////};
////
////class Tries
////{
////public:
////	Node* root;
////
////	Tries()
////	{
////		root = createNode('\0');
////	}
////
////	Node* createNode(char c)
////	{
////		Node* newNode = new Node(c);
////		return newNode;
////	}
////	void Insert(string word, Node* t)
////	{
////
////		Node* temp = t;
////		char ch = '\0';
////		int pos = 0;
////		for (int i = 0; i < word.length(); i++)
////		{
////			ch = word[i];
////			pos = ch;
////			if (pos >= 97 && pos <= 122)
////			{
////				pos = (pos + 0) - 97;
////			}
////			else if (pos >= 65 && pos <= 90)
////			{
////				pos = (pos + 26) - 65;
////			}
////			else if (pos >= 48 && pos <= 57)
////			{
////				pos = (pos + 52) - 48;
////			}
////			if (temp->child[pos] == NULL)
////			{
////				temp->child[pos] = createNode(ch);
////			}
////			temp = temp->child[pos];
////		}
////		temp->terminal = true;
////	}
////	void Display_t(Node* temp, string word)
////	{
////
////		if (temp == NULL)
////		{
////			return;
////		}
////		else
////		{
////			if (temp->ch != '\0')
////				word = word + temp->ch;
////			if (temp->terminal == true)
////			{
////				cout << word << endl;
////			}
////		}
////
////
////
////		for (int i = 0; i < 62; i++)
////		{
////
////			Display_t(temp->child[i], word);
////		}
////	}
////	Node* search(Node* temp, string key, int index)
////	{
////		if (temp == NULL)
////		{
////			return NULL;
////		}
////
////		char ch = key[index];
////
////		if (temp->terminal && index == key.size())
////		{
////			return temp;
////		}
////		if (ch == '\0')
////		{
////			return NULL;
////		}
////
////		int i;
////
////		if (ch >= 97 && ch <= 122)
////		{
////			i = ch - 'a';
////		}
////		else if (ch >= 65 && ch <= 90)
////		{
////			i = ch - 'A';
////			i = i + 26;
////		}
////		else if (ch >= 48 && ch <= 57)
////		{
////			i = ch - '0';
////			i = i + 52;
////		}
////
////
////		return	search(temp->child[i], key, ++index);
////
////	}
////};
////class Hash
////{
////public:
////	//int size ;
////	Tries bucket[62];
////
////	/*Hash(int tsize=0)
////	{
////		size = tsize;
////	}*/
////
////
////	int Hash_fun(string nam)
////	{
////		int index;
////		index = nam[0];
////
////		if (index >= 97 && index <= 122)
////		{
////			index = (index + 0) - 97;
////		}
////		else if (index >= 65 && index <= 90)
////		{
////			index = (index + 26) - 65;
////		}
////		else if (index >= 48 && index <= 57)
////		{
////			index = (index + 52) - 48;
////		}
////		return index;
////
////	}
////	void Insert(string name)
////	{
////		int ind = Hash_fun(name);
////		Node* temp = bucket[ind].root;
////
////		bucket[ind].Insert(name, temp);
////	}
////	Node* search(string sname)
////	{
////		int in = Hash_fun(sname);
////		Node* temp = bucket[in].root;
////		return bucket[in].search(temp, sname, 0);
////	}
////	void Display()
////	{
////
////		//char c;
////		//cout << "Enter 1st Alphabet of series : " << endl;
////		//cin >>c;
////		//int indx = c-97;
////		for (int indx = 0; indx < 62; indx++)
////		{
////
////			bucket[indx].Display_t(bucket[indx].root, "");
////
////		}
////	}
////};
//class HNode {
//public:
//	string name;
//	char username;
//	string password;
//	string mobile_no;
//	bool terminal;
//	HNode* child[62];
//
//	HNode(string tname , char tusername,string tpassword,string tm_no)
//	{
//		name = tname;
//		username = tusername;
//		password = tpassword;
//		mobile_no = tm_no;
//		terminal = false;
//		for (int i = 0; i < 62; i++)
//		{
//			child[i] = NULL;
//		}
//	}
//};
//class HTries
//{
//public:
//	HNode* root;
//	HTries()
//	{
//		root = createHNode("",'\0',"","");
//	}
//	HNode* createHNode(string nname, char nusername, string npassword, string nm_no)
//	{
//		HNode* newHNode = new HNode(nname,nusername,npassword,nm_no);
//		return newHNode;
//	}
//	//int i = 0;
//	void Insert(string iname ,string iusern,string ipass,string im_no, HNode* t)
//	{
//		HNode* temp = t;
//		char ch = '\0';
//		int pos = 0;
//		for (int i = 0; i < iusern.length(); i++)
//		{
//			ch = iusern[i];
//			cout <<"ch = "<< ch << endl;
//			pos = ch;
//			if (pos >= 97 && pos <= 122)
//			{
//				pos = (pos + 0) - 97;
//			}
//			else if (pos >= 65 && pos <= 90)
//			{
//				pos = (pos + 26) - 65;
//			}
//			else if (pos >= 48 && pos <= 57)
//			{
//				pos = (pos + 52) - 48;
//			}
//			cout << "pos = "<<pos << endl;
//			if (temp->child[pos] == NULL)
//			{
//				temp->child[pos] = createHNode("", ch, "", "");
//				//cout << i+1 << endl;
//			}
//			temp = temp->child[pos];
//		}
//		temp->name = iname;
//		temp->password = ipass;
//		temp->mobile_no = im_no;
//		temp->terminal = true;
//	}
//
//
//	void Display_t(HNode* temp, string word)
//	{
//
//		if (temp == NULL)
//		{
//			return;
//		}
//		else
//		{
//			if (temp->username != '\0')
//				word = word + temp->username;
//			if (temp->terminal == true)
//			{
//				cout << word << endl;
//			}
//		}
//
//
//
//		for (int i = 0; i < 26; i++)
//		{
//
//			Display_t(temp->child[i], word);
//		}
//	}
//
//	HNode* search(HNode* temp, string key, int index)
//	{
//
//		if (temp == NULL)
//		{
//			return NULL;
//		}
//
//		char ch = key[index];
//		cout << "key = " << key << endl;
//		cout << "ch = " << ch << endl;
//		cout << "index = " << index << endl;
//		cout << "key size = " << key.size() << endl;
//		cout << "terminal = " << temp->username << endl;
//		
//		if (temp->terminal && index == key.size())
//		{
//			return temp;
//		}
//		if (ch == '\0')
//		{
//			return NULL;
//		}
//
//		int i;
//
//		if (ch >= 97 && ch <= 122)
//		{
//			i = ch - 'a';
//		}
//		else if (ch >= 65 && ch <= 90)
//		{
//			i = ch - 'A';
//			i = i + 26;
//		}
//		else if (ch >= 48 && ch <= 57)
//		{
//			i = ch - '0';
//			i = i + 52;
//		}
//
//
//		return	search(temp->child[i], key, ++index);
//
//	
//	}
//};
//class Hash
//{
//public:
//	//int size ;
//	HTries bucket[62];
//
//	/*Hash(int tsize=0)
//	{
//		size = tsize;
//	}*/
//
//
//	int Hash_fun(string nam)
//	{
//		int index;
//		index = nam[0];
//		if (index <= 97 && index >= 122)
//		{
//			index = index - 97;
//		}
//		else if (index <= 65 && index >= 90)
//		{
//			index = index - (65 + 26);
//		}
//		else if (index <= 48 && index >= 57)
//		{
//			index = index - (48 + 52);
//		}
//		//cout << index;
//		return index;
//
//	}
//	void Insert(string inam, string iusername,string ipas,string imb_no)
//	{
//		int ind = Hash_fun(iusername);
//		HNode* temp = bucket[ind].root;
//		bucket[ind].Insert(iusername, inam, ipas, imb_no,temp);
//	}
//	HNode* search(string sname)
//	{
//		int in = Hash_fun(sname);
//		HNode* temp = bucket[in].root;
//		cout << "root :" << temp->username << endl;
//		return bucket[in].search(temp, sname, 0);
//	}
//	void Display()
//	{
//
//		//char c;
//		//cout << "Enter 1st Alphabet of series : " << endl;
//		//cin >>c;
//		//int indx = c-97;
//		for (int indx = 0; indx < 62; indx++)
//		{
//			//cout << indx;
//			bucket[indx].Display_t(bucket[indx].root, "");
//
//		}
//	}
//};
//
//
//int main()
//{
//	
//
//	Hash h1;
//	
//	string name;
//	string username;
//	string password;
//	string mobile_number;
//
//	cout << "Enter Your Name : " << endl;
//	getline(cin, name);
//	cout << "Enter Your Username : " << endl;
//	getline(cin, username);
//	cout << "Enter Your Password : " << endl;
//	getline(cin, password);
//	cout << "Enter Your Mobile Number : " << endl;
//	getline(cin, mobile_number);
//
//	/*HNode* temp = h1.search(username);
//	while (temp)
//	{
//		cout << "USERNAME ALREADY EXISTS !!!!!  " << endl;
//		cout << "Try Another Username : " << endl;
//		getline(cin, username);
//	}*/
//
//	h1.Insert(name, username, password, mobile_number);
//
//
//	h1.Display();
//
//	return 0;
//}