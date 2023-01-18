#include<iostream>
#include <string>
#include<mutex>
#include<thread>
#ifndef WIN_32_LEAN_AND_MEAN
#define WIN_32_LEAN_AND_MEAN
#endif

#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#define _WINSOCKAPI_
#include <windows.h>

#pragma warning(disable: 4996)
using namespace std;
mutex mtx;
string k;
SOCKET Connection;
bool is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}
bool check_length(const std::string& s) {
	if (size(s) > 64) {
		return false;
	}
	return true;
}
void trytoconnectagain() {
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	 Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server.\n";

	}
	else {
		std::cout << "Connected!\n";
	}
}
void thread2() {
	string k1;
	k1 = k;
	k = "";
	int y;
	y = 0;
	char ch;
	
	for (int i = 0; i < size(k1); i++) {
		if (isdigit(k1[i])) {

			ch = k1[i];
			y += atoi(&ch);

		}
	}

	cout <<"sum=" << y << endl;
	cout << k1 << endl;
	const char* c = k1.c_str();
	int result;
	result=send(Connection, c, size(k1), NULL);
	if (result == -1) {
		cout << "ku\n";
		closesocket(Connection);
		thread t3(trytoconnectagain);
		t3.join();
		send(Connection, c, size(k1), NULL);
	}
}
struct Node
{
	
	string data;
	Node* next;
};
class List
{
private:
	Node* head; //"голова" связанного списка
public:
	List() //конструктор класса без параметров
	{
		head = NULL; //первого элемента пока нет
	}
	//метод, добавляющий новый узел в список
	void addNode(string d);
	//метод, выводящий связанный список на экран
	void printList();
	void sort();
	void replace();
	string tostr();
};
void List::addNode(string d) {
	lock_guard<mutex> lg(mtx);
	Node* nd = new Node; //динамически создаем новый узел
	nd->data = d;        //задаем узлу данные
	nd->next = NULL;     //новый узел в конце, поэтому NULL
	if (head == NULL)     //если создаем первый узел
		head = nd;
	else                 //если узел уже не первый
	{
		Node* current = head;
		//ищем в цикле предшествующий последнему узел
		while (current->next != NULL)
			current = current->next;
		//предшествующий указывает на последний
		current->next = nd;
	}

}
void List::printList()
{
	lock_guard<mutex> lg(mtx);
	Node* current = head;
	while (current != NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}
	
}
void List::sort() {
	lock_guard<mutex> lg(mtx);
	 Node* t, * m, * a, * b;
	if (head == NULL)
		return;

	for (bool go = true; go; ) {
		go = false;
		a = t = head;
		b = head->next;

		while (b != NULL) {
			if (a->data < b->data) {
				if (t == a)
					head = b;
				else
					t->next = b;

				a->next = b->next;
				b->next = a;

				m = a, a = b, b = m;
				go = true;
			}
			t = a;
			a = a->next;
			b = b->next;
		}
	}
	
}
void List::replace() {
	lock_guard<mutex> lg(mtx);
	if (head == NULL)
		return;
	string k = "KB";
	int l;
	string r;
	Node* current = head;
	while (current->next != NULL) {
		
		if (stoi(current->data) % 2 == 0) {

			current->data = k;
		}
		current = current->next;
	}

	if (stoi(current->data) % 2 == 0) {

		current->data = k;
	};

}
string List::tostr() {
	lock_guard<mutex> lg(mtx);
	if (head == NULL)
		return 0;
	string str = "";
	Node* current = head;
	while (current->next != NULL) {

		str = str + current->data;
		current = current->next;
	}
	str = str + current->data;
	return str;

}
void thread1(SOCKET Connection) {
	while (true) {
		string str;
		cout << "enter a string" << endl;
		cin >> str;
		bool q;
		bool t = false;
		while (!t) {
			q = check_length(str);
			if (!q) {
				cin >> str;
				continue;
			}
			t = true;
		}
		t = false;
		while (!t) {
			q = is_number(str);
			if (!q) {
				cin >> str;
				continue;
			}
			t = true;
		}
		int i = size(str);
		int l;
		List mylist;
		for (int i = 0; i < size(str); i++) {

			k = str[i];
			l = stoi(k);
			mylist.addNode(k);
		}
		mylist.sort();
		mylist.replace();
		k = mylist.tostr();

		thread t2(thread2);
		t2.join();
		thread1(Connection);
	}
}


int main() {
	//WSAStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
	
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server.\n";
	}
	else {
		std::cout << "Connected!\n";
	}
	
	
	

	thread t1(thread1,Connection);
	t1.join();
	
}
