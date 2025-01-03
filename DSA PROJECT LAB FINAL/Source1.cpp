#include<iostream>
#include<string>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <climits>
#include <map>
#include <thread>
#include <chrono>


#pragma warning(disable : 4996)
using namespace std;

string wqt() {
	time_t now = time(0);               // Get current time
	tm* gmtm = gmtime(&now);            // Convert to GMT/UTC

	// Adjust for GMT+5
	gmtm->tm_hour = (gmtm->tm_hour + 5) % 24; // Add 5 hours for GMT+5
	if (gmtm->tm_hour < 0) gmtm->tm_hour += 24;

	char buffer[80];                    // Buffer to store formatted time
	strftime(buffer, sizeof(buffer), "%I:%M:%S %p %a %b %d %Y", gmtm); // Format time in 12-hour format

	return string(buffer);              // Convert to std::string and return
}
class Fnode
{
public:
	string name;
	string username;

	Fnode* next;
	Fnode* pre;
	Fnode(string tname = NULL, string tusername = NULL)
	{

		name = tname;
		username = tusername;
		next = NULL;
		pre = NULL;

	}
};

class Stac_F
{
public:
	Fnode* head;
	Fnode* tail;
	Stac_F()
	{
		head = NULL;
		tail = NULL;

	}
	void push(string val, string fusrnm)
	{
		Fnode* myFnode = new Fnode(val, fusrnm);
		if (head == NULL)
		{
			head = myFnode;
			tail = head;


		}
		else
		{


			while (tail->next != NULL)
			{


				tail = tail->next;
			}
			tail->next = myFnode;
			myFnode->pre = tail;

			tail = myFnode;
			//ti = wqt();

		}

	}
	Fnode* pop()
	{
		if (tail == NULL)
		{
			return tail;
		}
		else
		{
			Fnode* npop = top();
			Fnode* temp1 = tail;
			tail = temp1->pre;
			temp1->pre->next = NULL;
			temp1->pre = NULL;
			temp1 = temp1->pre;
			return npop;
		}
	}
	Fnode* top()
	{
		Fnode* tempt = tail;
		return tempt;
	}
	Fnode* gtnd(int in)
	{
		in = in - 1;
		Fnode* temp = tail;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{

			for (int i = 1; i <= in; i++)
			{
				temp = temp->pre;
			}
		}
		return temp;
	}
	void del(int ind)
	{
		Fnode* temp = gtnd(ind);
		remove(temp->name);



	}
	void upd(int x)
	{
		Fnode* temp = gtnd(x);
		update(temp->name);
	}
	void remove(string val)
	{
		Fnode* temp = head;
		if (head->name == val)
		{
			if (head->next != NULL)
			{
				head->next->pre = head->pre;
				head = head->next;
			}
			else
			{
				head = NULL;
			}

		}
		else if (tail->name == val)
		{
			tail->pre->next = tail->next;
			tail = tail->pre;
		}
		else
		{
			while (temp->next != NULL)
			{
				if (temp->name == val)
				{
					temp->pre->next = temp->next;
					temp->next->pre = temp->pre;

				}
				temp = temp->next;
			}
		}
	}
	void update(string val)
	{
		Fnode* temp = head;
		string updt;
		if (head->name == val)
		{
			cin.ignore();
			cout << "Update Your Post..!!!" << endl;
			getline(cin, updt);
			head->name = updt;

		}
		else if (tail->name == val)
		{
			cin.ignore();
			cout << "Update Your Post..!!!" << endl;
			getline(cin, updt);
			tail->name = updt;
		}
		else
		{
			while (temp->next != NULL)
			{
				if (temp->name == val)
				{
					cin.ignore();
					cout << "Update Your Post..!!!" << endl;
					getline(cin, updt);
					temp->name = updt;

				}
				temp = temp->next;
			}
		}
	}
	bool search(string val)
	{
		bool flag = false;
		Fnode* temp = head;
		if (head->name == val)
		{
			flag = true;

		}
		else if (tail->name == val)
		{
			flag = true;
		}
		else
		{
			while (temp->next != NULL)
			{
				if (temp->name == val)
				{

					flag = true;

				}
				temp = temp->next;
			}

		}
		if (flag == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Display_U()
	{
		Fnode* temp = tail;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{
			int i = 1;
			while (temp != NULL)
			{
				cout << "-------------------------- " << i << " --------------------------" << endl;
				cout << temp->name << endl;
				temp = temp->pre;
				i++;
			}
		}
	}

	void Display()
	{
		Fnode* temp = tail;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{

			while (temp != NULL)
			{
				cout << temp->name << endl;
				cout << "______" << endl;
				temp = temp->pre;
			}
		}
	}
};


class node
{
public:
	
	string data;
	string name;
	string tim;
	node* next;
	node* pre;
	node(string tdata = NULL, string tname = NULL, string tt=" ")
	{
		data = tdata;
		name = tname;
		tim = tt;
		next = NULL;
		pre = NULL;

	}
};


class post
{
public:
	node* head;
	
	node* tail;
	post()
	{
		head = NULL;
		tail = NULL;

	}
	void push(string val, string nm,string tt)
	{
		node* mynode = new node(val, nm, tt);
		if (head == NULL)
		{
			head = mynode;
			tail = head;

			
		}
		else
		{


			while (tail->next != NULL)
			{


				tail = tail->next;
			}
			tail->next = mynode;
			mynode->pre = tail;

			tail = mynode;
			

		}

	}
	node* pop()
	{
		if (tail == NULL)
		{
			return tail;
		}
		else
		{
			node* npop = top();
			node* temp1 = tail;
			
			remove(tail->data);
			return npop;
		}
	}
	bool IsEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	node* top()
	{
		
		return tail;
	}
	node* gtnd(int in)
	{
		in = in - 1;
		int i = 0;
		node* temp = head;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{

			while(i<in){
				temp = temp->next;
				i++;
			}
		}
 		return temp;
	}
	void del(int ind)
	{
		node* temp = gtnd(ind);
		remove(temp->data);



	}
	void upd(int x)
	{
		node* temp = gtnd(x);
		update(temp->data);
	}
	node* ser(int va)
	{
		node* temp = gtnd(va);
		return search(temp->data);
	}
	node* search(string val)
	{
		bool flag = false;
		node* temp = head;
		node* stemp = head;
		if (head->name == val)
		{
			flag = true;

		}
		else if (tail->name == val)
		{
			stemp = tail;
			flag = true;
		}
		else
		{
			while (temp->next != NULL)
			{
				if (temp->name == val)
				{
					stemp = temp;
					flag = true;

				}
				temp = temp->next;
			}

		}
		if (flag == true)
		{
			return stemp;
		}
		else
		{
			return NULL;
		}
	}
	
	void remove(string val) {
		if (head == nullptr) {
			cout << "List is empty. No nodes to delete.\n";
			return;
		}

		node* temp = head;

		// Case 1: Node to remove is the only node in the list
		if (head == tail && head->data == val) {
			delete head;
			head = nullptr;
			tail = nullptr;
			cout << "The only post  was deleted.\n";
			return;
		}

		// Case 2: Node to remove is the head
		if (head->data == val) {
			head = head->next;
			head->pre = nullptr;
			delete temp;
			cout << "post at the head was deleted.\n";
			return;
		}

		// Case 3: Node to remove is the tail
		if (tail->data == val) {
			temp = tail;
			tail = tail->pre;
			tail->next = nullptr;
			delete temp;
			cout << "post at the tail was deleted.\n";
			return;
		}

		// Case 4: Node to remove is in the middle of the list
		while (temp != nullptr) {
			if (temp->data == val) {
				temp->pre->next = temp->next;
				if (temp->next != nullptr) {
					temp->next->pre = temp->pre;
				}
				delete temp;
				cout << "post in the middle of the list was deleted.\n";
				return;
			}
			temp = temp->next;
		}

		// Case 5: Node with the given value does not exist
		cout << "post with value '" << val << "' not found in the list.\n";
	}
// Update function to update the node with given value
	void update(string val) {
		node* temp = head;
		string newData;

		// Check if list is empty
		if (!head) {
			cout << "List is empty." << endl;
			return;
		}

		// Traverse the list to find the node and update
		while (temp) {
			if (temp->data == val) {
				cout << "Update Your Post: ";
				cin.ignore();  // Clear the input buffer
				getline(cin, newData);
				temp->data = newData;
				return;
			}
			temp = temp->next;
		}

		// If the value is not found in the list
		cout << "Value not found." << endl;
	}

	
	void Display_s()
	{
		node* temp = head;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{

			cout << "\n========== MY Social Media Posts ==========\n";
			

			cout << "\n========================================\n";
			int i = 1;
			while (temp != NULL)
			{
				
				cout << "-------------------------- " << i << " --------------------------" << endl;
				cout << "Posted at: " << temp->tim << endl;
				cout << "\n" << temp->data << "\n";
				cout << "----------------------------------------\n";

				
				temp = temp->next;
				i++;
			}
		}
	}
	void Display_U(string nam)
	{
		node* temp = tail;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{
			int i = 1;
			while (temp != NULL)
			{
				cout << "-------------------------- " << i << " --------------------------" << endl;
				cout << temp->name << " : " << endl;
				cout << "          " << temp->data << endl;
				cout << "                                                        " << temp->tim << endl;
				//dis_single();
				string ct;
				int a;
				cout << "---------------------------------------------------------" << endl;
				cout << "------Comments------" << endl << endl << endl;


				cout << "------------------------- " << endl;
				cout << "1- Add New Comment " << endl;
				cout << "2- Display All Comments " << endl;
				cout << "3- Go Back To See Next Post " << endl;
				cout << "------------------------- " << endl;
				cout << "Enter Your Option " << endl;
				cin >> a;
				while (a < 1 || a>3)
				{
					cout << "Enter Valid Option...!!!!" << endl;
					cin >> a;
				}
				system("CLS");
				switch (a)
				{
				case 1:
				{
					//	system("CLS");
					cin.ignore();
					cout << "Enter Comment : " << endl;
					getline(cin, ct);
					//temp->cmt.add_cmnt(ct, nam);
					break;

				}
				case 2:
				{
					//temp->cmt.display_cmnts();
				}
				case 3:
				{
					goto l1;
				}
				default:
					break;
				}

				/*else if (tail->data == val)
				{
					cout << "---------------------------------------------------------" << endl;
					cout << tail->data << endl;
					cout << "---------------------------------------------------------" << endl;
					cout << "------Comments------" << endl;
					temp->cmt.display_cmnts();

				}
				else
				{
					while (temp->next != NULL)
					{
						if (temp->data == val)
						{
							cout << "---------------------------------------------------------" << endl;
							cout << temp->data << endl;
							cout << "---------------------------------------------------------" << endl;
							cout << "------Comments------" << endl;
							temp->cmt.display_cmnts();


						}
						temp = temp->next;
					}
				}
		*/
			l1:
				temp = temp->pre;
				i++;
			}
		}
	}
	/*void Display()
	{
		node* temp = tail;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{

			while (temp != NULL)
			{
				cout << temp->data << endl;
				cout << "                                                              " << temp->tim << endl;
				cout << "______" << endl;
				temp = temp->pre;
			}
		}
	}*/

	void emptyStack() {
		while (!IsEmpty()) {
			pop(); // Remove the top element
		}
	}
	// Save posts to the file for the logged-in user
	void saveToFile(const string& username) {
		const string fileName = "posts.txt";

		// Step 1: Read existing posts and filter out the current user's posts
		ifstream inFile(fileName);
		string existingData = "";
		string line;

		if (inFile) {
			while (getline(inFile, line)) {
				stringstream ss(line);
				string fileUsername, content, timestamp;
				getline(ss, fileUsername, '|');
				getline(ss, content, '|');
				getline(ss, timestamp, '|');

				// Keep only posts not belonging to the logged-in user
				if (fileUsername != username) {
					existingData += line + "\n";
				}
			}
			inFile.close();
		}

		// Step 2: Write back the filtered data to the file
		ofstream outFile(fileName, ios::trunc);
		if (!outFile) {
			cerr << "Error: Unable to open file for writing." << endl;
			return;
		}

		outFile << existingData; // Write existing posts not belonging to the user

		// Step 3: Append current user's posts from the stack
		node* temp = head;
		while (temp != nullptr) {
			outFile << username << "|" << temp->data << "|" << temp->tim << "\n";
			temp = temp->next;
		}

		outFile.close();
		cout << "Posts saved successfully for " << username << ".\n";
	}
	// Load posts for the logged-in user from the file into the stack
	void loadFromFile(const string& username) {
		const string fileName = "posts.txt";
		ifstream inFile(fileName);
		string line;

		if (!inFile) {
			cerr << "Error: Unable to open file for loading.\n";
			return;
		}

		while (getline(inFile, line)) {
			stringstream ss(line);
			string fileUsername, content, timestamp;
			getline(ss, fileUsername, '|');
			getline(ss, content, '|');
			getline(ss, timestamp, '|');

			// If the username matches, add the post to the stack
			if (fileUsername == username) {
				push(content, fileUsername, timestamp);
			}
		}

		inFile.close();
		cout << "Posts loaded successfully for " << username << ".\n";
	}

	void displayAllPosts() {
		const string fileName = "posts.txt"; // File containing all posts
		ifstream inFile(fileName);
		string line;

		if (!inFile) {
			cerr << "Error: Unable to open file for reading.\n";
			return;
		}

		cout << "\n========== Social Media Posts ==========\n";

		while (getline(inFile, line)) {
			stringstream ss(line);
			string username, postContent, timeStamp;

			// Extract fields from the line
			getline(ss, username, '|');
			getline(ss, postContent, '|');
			getline(ss, timeStamp, '|');

			// Display in a formatted "post-like" way
			cout << "\n----------------------------------------\n";
			cout << "User: " << username << endl;
			cout << "Posted at: " << timeStamp << endl;
			cout << "\n" << postContent << "\n";
			cout << "----------------------------------------\n";
		}

		cout << "\n========================================\n";
		inFile.close();
	}

};


class Lnode
{
public:
	string data;
	Lnode* next;
	Lnode(string tdata = NULL)
	{
		data = tdata;
		next = NULL;

	}
};

class Linked_List
{
public:
	Lnode* head;
	Linked_List()
	{
		head = NULL;

	}
	void insert(string val)
	{
		Lnode* myLnode = new Lnode(val);
		Lnode* temp = head;
		if (head == NULL)
		{
			head = myLnode;


		}
		else
		{


			while (temp->next != NULL)
			{


				temp = temp->next;
			}
			temp->next = myLnode;


		}

	}

	Lnode* gtnd(int in)
	{
		in = in - 1;
		Lnode* temp = head;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{

			for (int i = 1; i <= in; i++)
			{
				temp = temp->next;
			}
		}
		return temp;
	}

	void Display_U()
	{
		Lnode* temp = head;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{
			int i = 1;
			while (temp != NULL)
			{
				cout << "-------------------------- " << i << " --------------------------" << endl;
				cout << temp->data << endl;
				temp = temp->next;
				i++;
			}
		}
	}

	void Display()
	{
		Lnode* temp = head;
		if (head == NULL)
		{
			cout << "EMPTY LIST...." << endl;
		}
		else
		{

			while (temp != NULL)
			{
				cout << temp->data << endl;
				cout << "                                                              " << endl;
				cout << "______" << endl;
				temp = temp->next;
			}
		}
	}
};

class NTNode {
public:
	char ch;
	string usernam;
	bool terminal;
	NTNode* child[53];

	NTNode(char c, string un)
	{
		ch = c;
		usernam = un;
		terminal = false;
		for (int i = 0; i < 53; i++)
		{
			child[i] = NULL;
		}
	}
};

class NTries
{
public:
	NTNode* root;
	Linked_List Lfrnd;
	//Stack_L all_f;
	NTries()
	{
		root = createNode('\0', "");
	}

	NTNode* createNode(char c, string usrn)
	{
		NTNode* newNTNode = new NTNode(c, usrn);
		return newNTNode;
	}
	void Insert(string word, string uname)
	{
		NTNode* temp = root;
		string usnam = "";
		char ch = '\0';
		int pos = 0;
		for (int i = 0; i < word.length(); i++)
		{

			ch = word[i];

			pos = ch;

			if (pos >= 97 && pos <= 122)
			{
				pos = (pos + 0) - 97;
			}
			else if (pos >= 65 && pos <= 90)
			{
				pos = (pos + 26) - 65;
			}
			else if (pos == 32)
			{
				pos = (pos + 52) - 32;
			}


			if (temp->child[pos] == NULL)
			{
				temp->child[pos] = createNode(ch, usnam);

			}
			temp = temp->child[pos];

		}
		temp->usernam = uname;
		temp->terminal = true;
	}
	void Display(NTNode* temp, string word)
	{

		if (temp == NULL)
		{
			return;
		}
		else
		{
			if (temp->ch != '\0')
				word = word + temp->ch;
			if (temp->terminal == true)
			{
				cout << word << endl;
			}
		}



		for (int i = 0; i < 53; i++)
		{

			Display(temp->child[i], word);
		}
	}
	int in = 1;
	void Display_s(NTNode* temp1, string word)
	{

		if (temp1 == NULL)
		{
			return;
		}
		else
		{
			if (temp1->ch != '\0')
				word = word + temp1->ch;
			if (temp1->terminal == true)
			{
				cout << "-------------- (" << in << ") --------------" << endl;
				cout << word << endl;
				Lfrnd.insert(word);
				in++;
			}
		}



		for (int i = 0; i < 53; i++)
		{

			Display_s(temp1->child[i], word);
		}
	}
	NTNode* search(NTNode* temp, string key, int index)
	{
		if (temp == NULL)
		{
			return NULL;
		}

		char ch = key[index];

		if (temp->terminal && index == key.size())
		{
			return temp;
		}
		if (ch == '\0')
		{
			return NULL;
		}

		int i;

		if (ch >= 97 && ch <= 122)
		{
			i = ch - 'a';
		}
		else if (ch >= 65 && ch <= 90)
		{
			i = ch - 'A';
			i = i + 26;
		}
		else if (ch == 32)
		{
			i = ch - ' ';
			i = i + 52;
		}


		return	search(temp->child[i], key, ++index);

	}
	NTNode* search_s(NTNode* temp, string key, int index)
	{
		if (temp == NULL)
		{
			return NULL;
		}

		char ch = key[index];

		if (index == key.size())
		{
			return temp;
		}
		if (ch == '\0')
		{
			return NULL;
		}

		int i;

		if (ch >= 97 && ch <= 122)
		{
			i = ch - 'a';
		}
		else if (ch >= 65 && ch <= 90)
		{
			i = ch - 'A';
			i = i + 26;
		}
		else if (ch == 32)
		{
			i = ch - ' ';
			i = i + 52;
		}


		return	search_s(temp->child[i], key, ++index);

	}
	string gtusrnm(int indx)
	{
		string sname;
		sname = Lfrnd.gtnd(indx)->data;
		string susrn;
		susrn = search(root, sname, 0)->usernam;
		return susrn;
	}
};

class all_users
{
public:
	NTries all_usr;
	all_users()
	{

	}
	void insert_user(string name, string uname)
	{
		all_usr.Insert(name, uname);
	}
	void display_usr(NTNode* temp2, string word)
	{
		all_usr.Display(temp2, word);
	}
	void display_s_usr(NTNode* temp4, string word)
	{
		all_usr.Display_s(temp4, word);
	}
	NTNode* search_usr(string key)
	{
		return all_usr.search(all_usr.root, key, 0);
	}
	NTNode* search_s_usr(string key)
	{
		return all_usr.search_s(all_usr.root, key, 0);
	}
	string gtusrnm_al(int inx)
	{
		return all_usr.gtusrnm(inx);
	}

};

class frnd
{
public:
	NTries frndz;
	Stac_F Req;
	//Stack_L usernm;

	frnd()
	{

	}
	void add_frnd(string name, string uname)
	{
		frndz.Insert(name, uname);
	}
	void display_frnd()
	{
		frndz.Display(frndz.root, "");
	}
	bool search_frnd(string key)
	{
		bool temp6 = frndz.search(frndz.root, key, 0);

		if (temp6 == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	NTNode* search_s_frnd(string key)
	{
		return frndz.search_s(frndz.root, key, 0);
	}
	void frnd_req(string rname, string rusername)
	{
		Req.push(rname, rusername);
	}
	string req_gtusrn(int nu)
	{
		return Req.gtnd(nu)->username;
	}
	bool search_req(string name)
	{
		bool temp5 = Req.search(name);
		if (temp5 == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void rmv_req(string name)
	{
		Req.remove(name);
	}
	void show_req()
	{
		Req.Display_U();
	}
	void frnd_usnm()
	{

	}
};



class Node {
public:
	char ch;
	bool terminal;
	string name;
	string pass;
	string num;
	post a;
	frnd f1;
	//Messages M1;
	Node* child[62];

	Node(char c, string n, string p, string no)
	{
		ch = c;
		name = n;
		pass = p;
		num = no;
		terminal = false;
		for (int i = 0; i < 62; i++)
		{
			child[i] = NULL;
		}
	}
};

class Tries
{
public:
	Node* root;

	Tries()
	{
		root = createNode('\0', "", "", "");
	}

	Node* createNode(char c, string cn, string cp, string cno)
	{
		Node* newNode = new Node(c, cn, cp, cno);
		return newNode;
	}
	void Insert(string word, string in, string ip, string ino, Node* t)
	{

		Node* temp = t;
		char ch = '\0';
		string iname = "";
		string ipass = "";
		string inum = "";
		int pos = 0;
		for (int i = 0; i < word.length(); i++)
		{

			ch = word[i];

			pos = ch;

			if (pos >= 97 && pos <= 122)
			{
				pos = (pos + 0) - 97;
			}
			else if (pos >= 65 && pos <= 90)
			{
				pos = (pos + 26) - 65;
			}
			else if (pos >= 48 && pos <= 57)
			{
				pos = (pos + 52) - 48;
			}


			if (temp->child[pos] == NULL)
			{
				temp->child[pos] = createNode(ch, iname, ipass, inum);

			}

			temp = temp->child[pos];

		}
		temp->name = in;
		temp->pass = ip;
		temp->num = ino;
		temp->terminal = true;

	}


	void Display_t(Node* temp, string word)
	{

		if (temp == NULL)
		{
			return;
		}
		else
		{
			if (temp->ch != '\0')
				word = word + temp->ch;
			if (temp->terminal == true)
			{
				cout << word << endl;
				cout << temp->name << endl;
				cout << temp->num << endl;
			}
		}



		for (int i = 0; i < 62; i++)
		{

			Display_t(temp->child[i], word);
		}
	}
	Node* search(Node* temp, string key, int index)
	{
		if (temp == NULL)
		{
			return NULL;
		}

		char ch = key[index];

		if (temp->terminal && index == key.size())
		{
			return temp;
		}
		if (ch == '\0')
		{
			return NULL;
		}

		int i;

		if (ch >= 97 && ch <= 122)
		{
			i = ch - 'a';
		}
		else if (ch >= 65 && ch <= 90)
		{
			i = ch - 'A';
			i = i + 26;
		}
		else if (ch >= 48 && ch <= 57)
		{
			i = ch - '0';
			i = i + 52;
		}


		return	search(temp->child[i], key, ++index);

	}
	Node* signin(Node* temp, string us, string pass, int index)
	{
		if (temp == NULL)
		{
			return NULL;
		}

		char ch = us[index];

		if (temp->terminal && index == us.size() && temp->pass == pass)
		{
			return temp;
		}
		if (ch == '\0')
		{
			return NULL;
		}

		int i;

		if (ch >= 97 && ch <= 122)
		{
			i = ch - 'a';
		}
		else if (ch >= 65 && ch <= 90)
		{
			i = ch - 'A';
			i = i + 26;
		}
		else if (ch >= 48 && ch <= 57)
		{
			i = ch - '0';
			i = i + 52;
		}


		return	signin(temp->child[i], us, pass, ++index);

	}
};

class Hash
{

public:

	Tries bucket[62];




	int Hash_fun(string nam)
	{
		int index;
		index = nam[0];

		if (index >= 97 && index <= 122)
		{
			index = (index + 0) - 97;
		}
		else if (index >= 65 && index <= 90)
		{
			index = (index + 26) - 65;
		}
		else if (index >= 48 && index <= 57)
		{
			index = (index + 52) - 48;
		}
		return index;

	}
	void Insert(string username, string in1, string ip1, string ino1)
	{
		int ind = Hash_fun(username);
		Node* temp = bucket[ind].root;
		//insertUserToDB(username, in1, ip1, ino1);
		
		bucket[ind].Insert(username, in1, ip1, ino1, temp);
	}

	void addUser(const string& username, const string& name, const string& password, const string& mobileNumber) {
		ofstream outFile("users.txt", ios::app);
		if (outFile)
		{
			//if (findUser(username)) {
				outFile << username << "|" << name << "|" << password << "|" << mobileNumber << endl;
				outFile.close();
				//cout << "User added successfully.\n";
			//}
		}
		else {
			cerr << "Error: Unable to open file for writing.\n";
		}
		

	}
	// Recursive function to load data
	void loadFromFileRecursive(ifstream& fileStream) {
		string line;
		if (!getline(fileStream, line)) {
			// Base case: End of file
			return;
		}

		// Parse the line
		stringstream ss(line);
		string username, name, password, mobile_number;
		getline(ss, username, '|');
		getline(ss, name, '|');
		getline(ss, password, '|');
		getline(ss, mobile_number, '|');

		// Call Insert function
		Insert(username, name, password, mobile_number);

		// Recursive call for the next line
		loadFromFileRecursive(fileStream);
	}

	// Wrapper function to load data
	void loadFromFile() {
		ifstream inFile("users.txt");
		if (inFile) {
			//cout << "Loading users from file...\n";
			loadFromFileRecursive(inFile);
			//cout << "All users loaded successfully.\n";
		}
		else {
			cerr << "Error: Unable to open users.txt for reading.\n";
		}
	}

	Node* search(string uname)
	{
		int in = Hash_fun(uname);
		Node* temp = bucket[in].root;
		return bucket[in].search(temp, uname, 0);
	}
	Node* sign_in(string uname, string pass)
	{
		int in = Hash_fun(uname);
		Node* temp = bucket[in].root;
		return bucket[in].signin(temp, uname, pass, 0);
	}

	void Display()
	{

		
		for (int indx = 0; indx < 62; indx++)
		{

			bucket[indx].Display_t(bucket[indx].root, "");

		}
	}

};

//GRAPH AND SHORTEST PATH FIND SNAKE GAME 
// Node class represents each cell on the grid (as a graph node)
class NodeForG {
public:
	int x, y;           // Coordinates of the NodeForG
	bool hasTreasure;   // Indicates if a treasure exists on this NodeForG
	int treasureValue;  // Value of the treasure (0 if none)
	NodeForG* up;           // Pointer to the NodeForG above
	NodeForG* down;         // Pointer to the NodeForG below
	NodeForG* left;         // Pointer to the NodeForG to the left
	NodeForG* right;        // Pointer to the NodeForG to the right

	NodeForG(int x, int y) : x(x), y(y), hasTreasure(false), treasureValue(0), up(nullptr), down(nullptr), left(nullptr), right(nullptr) {}
};

// Graph class manages the grid of NodeForGs
class Graph {
public:
	vector<vector<NodeForG*>> grid; // 2D vector representing the graph as a grid
	int rows, cols;             // Dimensions of the grid
	map<NodeForG*, bool> treasuresCollected;

	Graph(int rows, int cols) : rows(rows), cols(cols) {
		for (int i = 0; i < rows; i++) {
			vector<NodeForG*> row;
			for (int j = 0; j < cols; j++) {
				row.push_back(new NodeForG(i, j));
			}
			grid.push_back(row);
		}
		connectNodes();
	}

	void connectNodes() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (i > 0) grid[i][j]->up = grid[i - 1][j];
				if (i < rows - 1) grid[i][j]->down = grid[i + 1][j];
				if (j > 0) grid[i][j]->left = grid[i][j - 1];
				if (j < cols - 1) grid[i][j]->right = grid[i][j + 1];
			}
		}
	}

	void placeTreasures(int numTreasures) {
		srand(time(0));
		for (int i = 0; i < numTreasures; i++) {
			int x = rand() % rows;
			int y = rand() % cols;
			grid[x][y]->hasTreasure = true;
			grid[x][y]->treasureValue = (rand() % 100) + 1; // Random value between 1-100
			treasuresCollected[grid[x][y]] = false;
		}
	}

	bool allTreasuresCollected() {
		for (auto& pair : treasuresCollected) {
			if (!pair.second) return false;
		}
		return true;
	}

	void displayGrid() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (grid[i][j]->hasTreasure)
					cout << "T ";
				else
					cout << ". ";
			}
			cout << endl;
		}
	}
};

// Snake class represents the player
class Snake {
public:
	NodeForG* currentPosition; // Current position of the snake
	int score;             // Total score of collected treasures
	int moves;             // Tracks the number of moves made by the player

	Snake(NodeForG* start) : currentPosition(start), score(0), moves(0) {}

	void move(NodeForG* destination) {
		if (!destination) {
			cout << "Invalid move. Try again.\n";
			return;
		}

		currentPosition = destination;
		moves++;

		if (currentPosition->hasTreasure) {
			score += currentPosition->treasureValue;
			currentPosition->hasTreasure = false;
			currentPosition->treasureValue = 0;
			cout << "Treasure collected! Current score: " << score << endl;
		}
	}

	void displayPosition() {
		cout << "Snake is at (" << currentPosition->x << ", " << currentPosition->y << ")\n";
	}
};

int findShortestPath(NodeForG* current, NodeForG* target, set<NodeForG*>& visited) {
	// Base case: If the target is reached, return 0
	if (current == target) return 0;

	// If the current node is null or already visited, return a high value (invalid path)
	if (!current || visited.count(current)) return INT_MAX;

	// Mark the current node as visited
	visited.insert(current);

	// Recursively calculate the shortest path in all directions
	int up = findShortestPath(current->up, target, visited);
	int down = findShortestPath(current->down, target, visited);
	int left = findShortestPath(current->left, target, visited);
	int right = findShortestPath(current->right, target, visited);

	// Backtrack: Remove the current node from the visited set
	visited.erase(current);

	// Return 1 + the minimum of all valid paths
	return 1 + min({ up, down, left, right });
}


// Encapsulated function for the game logic
void playGame() {
	int rows = 5, cols = 5;
	Graph graph(rows, cols); // Create a 5x5 grid
	graph.placeTreasures(5); // Place 5 treasures randomly

	cout << "Initial Grid (T = Treasure, . = Empty):\n";
	graph.displayGrid();

	Snake snake(graph.grid[0][0]); // Snake starts at the top-left corner
	int totalShortestPath = 0;

	for (auto& pair : graph.treasuresCollected) {
		set<NodeForG*> visited;
		totalShortestPath += findShortestPath(snake.currentPosition, pair.first, visited);
	}

	char input;
	while (true) {
		snake.displayPosition();
		cout << "Move (W/A/S/D): ";
		cin >> input;

		switch (toupper(input)) {
		case 'W': snake.move(snake.currentPosition->up); break;
		case 'A': snake.move(snake.currentPosition->left); break;
		case 'S': snake.move(snake.currentPosition->down); break;
		case 'D': snake.move(snake.currentPosition->right); break;
		default: cout << "Invalid input. Use W/A/S/D.\n";
		}

		cout << "Updated Grid:\n";
		graph.displayGrid();

		// Check if the current position was a treasure node
		if (graph.treasuresCollected.count(snake.currentPosition)) {
			graph.treasuresCollected[snake.currentPosition] = true;
		}

		// End game when all treasures are collected
		if (graph.allTreasuresCollected()) {
			cout << "All treasures collected!\n";
			cout << "Total moves: " << snake.moves << endl;
			cout << "Shortest possible path: " << totalShortestPath << endl;

			if (snake.moves < totalShortestPath) {
				cout << "You were faster than the shortest path!\n";
			}
			else if (snake.moves == totalShortestPath) {
				cout << "You matched the shortest path!\n";
			}
			else {
				cout << "Your route was longer than the shortest path.\n";
			}
			break;
		}
	}
}
void displayIntro() {
	string projectName = "SPHIRE";
	string developerName = "DANIYAL AHMAD (Developer)";
	string designerName = "WASEEM MIR (Designer)";

	// Simulating large project name using slashes
	string largeProjectName[] = {
		"   SSSSS   PPPPPP   H   H  III  RRRRR  EEEEE  ",
		"  S        P    P   H   H   I   R   R  E       ",
		"   SSS     PPPPPP   HHHHH   I   RRRRR  EEEE    ",
		"      S    P        H   H   I   R  R   E       ",
		"  SSSSS    P        H   H  III  R   R  EEEEE   "
	};

	// Gradually change color of the project name
	for (int colorCode = 1; colorCode <= 4; ++colorCode) {

		// Print each line of the large project name with color
		for (int i = 0; i < 5; ++i) {
			cout << "\t\t\t\t";
			cout << "\033[38;5;" << (colorCode * 10) % 256 << "m" << largeProjectName[i] << endl;
		}


		// Gradual transition between colors
		this_thread::sleep_for(chrono::milliseconds(1000));
	}

	// Print the creator names with color transition
   // cout << "\033[38;5;240m" << developerName << "           " << designerName << endl;

	// Gradually darken the creator names
	for (int i = 9; i < 10; i++) {
		this_thread::sleep_for(chrono::milliseconds(300));

		// Change text color to darker shades
		int colorCode = 240 + i;
		cout << "\t\t\t\t";
		cout << "\033[38;5;" << colorCode << "m" << designerName << "           " <<  developerName << endl;
	}

	// Clear the screen after some time
	cout << "\n\n\t\t\t\t" << "Loading........";
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "\033[2J\033[H";  // Clear screen and reset cursor position
}


void utility()
{

	string key;
	Hash h1;            //USER
	post p;

	all_users a1;
	//h1.Display();
	h1.loadFromFile();




	int a;
lable:
	displayIntro();
	cout<< "                                         1-SIGN UP\n"
		<< "                                         2-SIGN IN\n"
		<< "                                         3-EXIT\n"
		<< "                                   ******************************************************\n";

	cout << "Enter Your Option " << endl;
	cin >> a;

	while (a < 1 || a>3)
	{
		cout << "Enter Valid Option...!!!!" << endl;
		cin >> a;
	}

	system("CLS");
	switch (a)
	{
	case 1:
	{
		cout << "=======================NEW ACCOUNT==========================\n";

		string name;
		string username;
		string password;
		string mobile_number;
		//h1.Insert("ali123", "ali", "123", "032143");
		cin.ignore();
		cout << "Enter Your Name : " << endl;
		getline(cin, name);
		while (name == "")
		{
			cout << "Name Should Not be Epmty...!!!!" << endl;
			cout << "Enter Again..." << endl;
			getline(cin, name);
		}
		//cin >> name;
		cout << "Enter Your Username : " << endl;
		getline(cin, username);
		while (username == "")
		{
			cout << "Username Should Not be Epmty...!!!!" << endl;
			cout << "Enter Again..." << endl;
			getline(cin, username);
		}
		//cin >> username;
		cout << "Enter Your Password : " << endl;
		getline(cin, password);
		while (password == "")
		{
			cout << "Password Should Not be Epmty...!!!!" << endl;
			cout << "Enter Again..." << endl;
			getline(cin, password);
		}
		cout << "Enter Your Mobile Number : " << endl;
		getline(cin, mobile_number);
		while (mobile_number == "")
		{
			cout << "Mobile No. Should Not be Epmty...!!!!" << endl;
			cout << "Enter Again..." << endl;
			getline(cin, mobile_number);
		}

		Node* temp = h1.search(username);
		while (temp)
		{
			cout << "USERNAME ALREADY EXISTS !!!!!  " << endl;
			cout << "Try Another Username : " << endl;
			getline(cin, username);
			temp = h1.search(username);
		}
		h1.Insert(username, name, password, mobile_number);
		h1.addUser(username, name, password, mobile_number);
		//frnd.Insert(name);
		a1.insert_user(name, username);
		cout << "Successfully Signed Up....!!!!" << endl;
		system("pause");
		system("CLS");
		goto lable;
		break;

	}

	case 2:
	{
		cout << "=================================================\n";

		string susername;
		string spassword;
	login:
		cin.ignore();
		cout << "Enter Your Username : " << endl;

		getline(cin, susername);
		while (susername == "")
		{
			cout << "Username Should Not be Epmty...!!!!" << endl;
			cout << "Enter Again..." << endl;
			getline(cin, susername);
		}
		cout << "Enter Your Password : " << endl;
		getline(cin, spassword);
		while (spassword == "")
		{
			cout << "Password Should Not be Epmty...!!!!" << endl;
			cout << "Enter Again..." << endl;
			getline(cin, spassword);
		}
		Node* temp = h1.sign_in(susername, spassword);
		if (temp)
		{
			cout << "Signed In Successfully...!!!" << endl;
			cout << "=================================================\n";
			p.loadFromFile(susername);     //for user post load


			int c;
		lable1:
			cout << "                             =======================Account==========================\n";
			cout << "\n                                **********************************\n"
				<< "                                         1-Personal Tab\n"
				<< "                                         2-Scrolling Tab\n"
				<< "                                         3-Friends Tab\n"
				<< "                                         4-Feeling Bored Play a Game\n"
				<< "                                         5-Log Out\n"
				<< "                                   ************************************\n";

			cout << "Enter Your Option " << endl;
			cin >> c;
			while (c < 1 || c>5)
			{
				cout << "Enter Valid Option...!!!!" << endl;
				cin >> c;
			}
			system("CLS");
			switch (c)
			{
			case 1:
			{
				cout << "=================================================\n";
				int b;
			lable2:
				cout << "                             ======================= PERSONAL TAB ==========================\n";
				cout << "\n                                  *******************************************\n"
					<< "                                         1-My Post\n"
					//	<< "                                         2-View Comment\n"
					<< "                                         2-Add Post\n"
					<< "                                         3-Delete Post\n"
					<< "                                         4-Update Post\n"
					<< "                                         5-GoTo Back Page\n"
					<< "                                     ********************************************\n";

				cout << "Enter Your Option " << endl;
				cin >> b;
				while (b < 1 || b>6)
				{
					cout << "Enter Valid Option...!!!!" << endl;
					cin >> b;
				}
				system("CLS");
				switch (b)
				{
				case 1:
				{
					p.Display_s();
					system("pause");
					system("CLS");
					goto lable2;
					break;

				}
				case 2:
				{
					cout << "====================== ADD POST ===========================\n";
					string adpost;
					cin.ignore();
					cout << "Post Your Feelings Here : " << endl;
					getline(cin, adpost);
					p.push(adpost, susername, wqt());
					p.saveToFile(susername);
					system("pause");
					system("CLS");
					goto lable2;
					break;

				}
				case 3:
				{
					cout << "====================== DELETE POST ===========================\n";
					int in;
					p.Display_s();
					cout << "==============================================================" << endl;
					cout << "Enter Post Number You Want To Delete" << endl;
					cin >> in;
					p.del(in);
					p.saveToFile(susername);
					system("pause");
					system("CLS");
					goto lable2;
					break;
				}
				case 4:
				{
					cout << "====================== UPDATE POST ===========================\n";
					int iu;
					p.Display_s();
					cout << "==============================================================" << endl;
					cout << "Enter Post Number You Want To Update" << endl;
					cin >> iu;
					p.upd(iu);
					p.saveToFile(susername);
					//temp->a.update_post(iu);
					system("pause");
					system("CLS");
					goto lable2;
					break;
				}

				case 5:
				{
					goto lable1;
				}
				default:
					break;


				}
				system("pause");
				system("CLS");
				break;

			}
			case 2:
			{
				cout << "=================================================\n";

			lable3:
				cout << "                             ======================= Scrolling TAB ==========================\n";

				p.displayAllPosts();
				system("pause");
				system("CLS");



				goto lable1;

				break;
			}
			case 3:
			{
				cout << "=================================================\n";
				int e;
			lable4:
				cout << "                             ======================= FRIENDS TAB ==========================\n";
				cout << "\n                                  ***********************************************\n"
					<< "                                         1-My Friends\n"
					<< "                                         2-Add Friends\n"
					<< "                                         3-Friend Requests\n"
					<< "                                         4-GoTo Back Page\n"
					<< "                                     ***********************************************\n";

				cout << "Enter Your Option " << endl;
				cin >> e;
				while (e < 1 || e>4)
				{
					cout << "Enter Valid Option...!!!!" << endl;
					cin >> e;
				}
				system("CLS");
				switch (e)
				{
				case 1:
				{
					cout << "====================== MY FRIENDS ===========================\n";
					int as;
					cout << "--------------------------------------------\n";
					cout << "1- Show All Friends Name " << endl;
					cout << "2- Search Friends " << endl;
					cout << "--------------------------------------------\n";
					cout << "Enter Your Option " << endl;
					cin >> as;
					while (as < 1 || as>2)
					{
						cout << "Enter Valid Option...!!!!" << endl;
						cin >> as;
					}
					system("CLS");
					if (as == 1)
					{
						temp->f1.display_frnd();



					}
					else
					{
						string kye;
						cin.ignore();

						cout << "Search New Friend Here : " << endl;
						getline(cin, kye);

						cout << "Suggesstion are...." << endl;
						NTNode* temp1 = temp->f1.search_s_frnd(kye);
						kye.erase(kye.size() - 1);
						if (temp1)
						{
							temp->f1.frndz.Display_s(temp1, kye);
						}
						else
						{
							cout << "Not Found";
							system("pause");
							system("CLS");
							goto lable4;
						}
						if (a1.all_usr.root != NULL)
						{


							int nf;
							string usrnm;
							cout << "Enter Index Of Above Mentioned User You Want To See ..." << endl;
							cin >> nf;
							usrnm = temp->f1.req_gtusrn(nf);
							Node* temp2 = h1.search(usrnm);
							if (temp2)
							{
								cout << "==================================================================" << endl;
								cout << temp2->name << endl;
								cout << "==================================================================" << endl;
								cout << "-----------------Posts---------------" << endl;
								//		temp2->a.displayHPost();
							}
						}

					}
					system("pause");
					system("CLS");
					goto lable4;
					break;

				}
				case 2:
				{
					cout << "====================== ADD FRIEND ===========================\n";
					//ls1:
					string ky;
					cin.ignore();

					cout << "Search New Friend Here : " << endl;
					getline(cin, ky);

					cout << "Suggesstion are...." << endl;
					NTNode* temp1 = a1.search_s_usr(ky);
					ky.erase(ky.size() - 1);
					if (temp1)
					{
						a1.display_s_usr(temp1, ky);
					}
					else
					{
						cout << "Not Found";
						system("pause");
						system("CLS");
						goto lable4;
					}
					if (a1.all_usr.root != NULL)
					{


						int nf;
						string usrnm;
						cout << "Enter Index Of Above Mentioned User You Want To See ..." << endl;
						cin >> nf;
						usrnm = a1.gtusrnm_al(nf);
						Node* temp2 = h1.search(usrnm);
						if (temp2)
						{
							cout << "==================================================================" << endl;
							cout << temp2->name << endl;

							cout << "==================================================================" << endl;
							cout << "-----------------Posts---------------" << endl;
							//temp2->a.displayHPost();
						}
						int as;
						cout << "--------------------------------------------\n";
						cout << "1- Send Friend Request " << endl;
						cout << "2- GoTo Previous Page " << endl;
						cout << "--------------------------------------------\n";
						cout << "Enter Your Option " << endl;
						cin >> as;
						while (as < 1 || as>2)
						{
							cout << "Enter Valid Option...!!!!" << endl;
							cin >> as;
						}
						system("CLS");
						if (as == 1)
						{

							if (temp->name == temp2->name)
							{
								cout << "Why are you Making Friend Yourself..." << endl;
								cout << "Go And Search Someone Else..." << endl;
							}
							else
							{
								temp2->f1.frnd_req(temp->name, susername);
								cout << "Friend Request Sent !!!!!! " << endl;
								//cout << "added" << endl;
							}
						}
						else
						{
							//cout << "case2" << endl;
							goto lable4;
						}
					}
					system("pause");
					system("CLS");
					goto lable4;
					break;
				}
				case 3:
				{
					cout << "====================== FRIEND REQUESTS ===========================\n";
					temp->f1.show_req();
					if (temp->f1.Req.head != NULL)
					{
						string fusr;
						int fr;
						cout << "Enter Index Of Above Mentioned Requested User You Want To See ..." << endl;
						cin >> fr;
						fusr = temp->f1.req_gtusrn(fr);
						Node* temp3 = h1.search(fusr);
						if (temp3)
						{
							cout << "==================================================================" << endl;
							cout << temp3->name << endl;
							cout << "==================================================================" << endl;
							cout << "-----------------Posts---------------" << endl;
							//temp3->a.displayHPost();
						}
						cout << "======================================================================================================" << endl;
						int fs;
						cout << "--------------------------------------------\n";
						cout << "1- Accept Friend Request " << endl;
						cout << "2- Reject Friend Request " << endl;
						cout << "3- GoTo Previous Page " << endl;
						cout << "--------------------------------------------\n";
						cout << "Enter Your Option " << endl;
						cin >> fs;
						while (fs < 1 || fs>3)
						{
							cout << "Enter Valid Option...!!!!" << endl;
							cin >> fs;
						}
						system("CLS");
						if (fs == 1)
						{
							temp->f1.add_frnd(temp3->name, fusr);
							temp3->f1.add_frnd(temp->name, susername);
							temp->f1.rmv_req(temp3->name);
							cout << "You Are Now Friends !!!!!" << endl;
							//cout << "added" << endl;
						}
						else if (fs == 2)
						{
							temp->f1.rmv_req(temp3->name);
							cout << "Request Removed.!!!!" << endl;
						}
						else
						{
							//cout << "case2" << endl;
							goto lable4;
						}
					}
					system("pause");
					system("CLS");
					goto lable4;
					break;

				}

				case 4:
				{
					goto lable1;
				}
				default:
					break;


				}
				system("pause");
				system("CLS");
				break;

			}
			case 4:
			{

				system("pause");
				system("CLS");
				playGame(); // Call the encapsulated game logic
				goto lable1;
				break;
			}

			case 5:
			{
				p.emptyStack();
				goto lable;
			}
			default:
				break;


			}
		}
		else
		{
			cout << "Incorrect USERNAME or PASSWORD..!!!!!" << endl;
			int z;
			cout << "*******\n"
				<< "1-Go Back\n"
				<< "2-SIGN IN Again\n"
				<< "******\n";

			cout << "Enter Your Option " << endl;
			cin >> z;
			while (z < 1 || z>2)
			{
				cout << "Enter Valid Option...!!!!" << endl;
				cin >> z;
			}
			system("CLS");
			switch (z)
			{
			case 1:
			{
				system("CLS");
				goto lable;
				break;

			}
			case 2:
			{

				goto login;
			}
			default:
				break;
			}
		}
		system("pause");
		system("CLS");
		break;
	}

	case 3:
	{
		exit(0);
	}
	default:
		break;
	}

	system("pause");
}
int main()
{
	utility();
	return 0;
}