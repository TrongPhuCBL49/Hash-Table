//Bảng băm cài đặt từ điển
#include<iostream>
#include<cstdlib>
#include<string>
#include <windows.h>
#include<cstring>
using namespace std;
const int TABLE_SIZE = 128;
class HashEntry
{
public:
	int key;
	string value;
	HashEntry(int key, string value)
	{
		this->key = key;
		this->value = value;
	}
};
// chuyển chuổi string thành key 
int returnHash(string x)
{
	 int index = 0;
	for (int i = 0; i < x.size(); i++)
	{
		index += (x[i]%TABLE_SIZE-'a');
	}
	return index;
}
class HashMap
{
private:
	HashEntry **table;
public:
	HashMap()
	{
		table = new HashEntry *[TABLE_SIZE];
		for (int i = 0; i< TABLE_SIZE; i++)
		{
			table[i] = NULL;
		}
	}
	//hàm băm
	int HashFunc(int key)
	{
		return key % TABLE_SIZE;
	}
	//thêm phần tử
	void Insert(int key, string value)
	{
		int hash = HashFunc(key);
		while (table[hash] != NULL && table[hash]->key != key)
		{
			hash = HashFunc(hash + 1);
		}
		if (table[hash] != NULL)
			delete table[hash];
		table[hash] = new HashEntry(key, value);
	}
	//tìm kiếm phần tử qua key
	string Search(int key)
	{
		int  hash = HashFunc(key);
		while (table[hash] != NULL && table[hash]->key != key)
		{
			hash = HashFunc(hash + 1);
		}
		if (table[hash] == NULL)
			return "a";
		else
			return  table[hash]->value;
	}
	//Tạo bẳng băm
	~HashMap()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			if (table[i] != NULL)
				delete table[i];
			delete[] table;
		}
	}
};
//Chương trình chính
int main()
{
	
	HashMap hash; string keylog;
	int key; string value;
	hash.Insert(returnHash("school"), "truong hoc (Danh tu)");
	hash.Insert(returnHash("chicken"), "ga (Danh tu)");
	hash.Insert(returnHash("girl"), "con gai (Danh tu)");
	hash.Insert(returnHash("boy"), "con trai (Danh tu)");
	hash.Insert(returnHash("run"), "chay (Dong tu)");
	hash.Insert(returnHash("swim"), "boi (Dong tu)");
	hash.Insert(returnHash("beautiful"), "dep (Tinh tu)");
	hash.Insert(returnHash("table"), "cai ban (Danh tu)");
	hash.Insert(returnHash("one"), "so mot (Danh tu)");
	hash.Insert(returnHash("morning"), "buoi sang (Danh tu)");
	hash.Insert(returnHash("afternoon"), "buoi chieu (Danh tu)");
	hash.Insert(returnHash("house"), "nha (Danh tu)");
	int choice;
	while (1)
	{
		cout << "\n----------------------" << endl;
		cout << "Moi ban lua chon" << endl;
		cout << "\n----------------------" << endl;
		cout << "1.Them phan tu vao Tu dien" << endl;
		cout << "2.Tim kiem tu tren tu dien" << endl;
		cout << "3.Thoat" << endl;
		cout << "Ban chon: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "moi ban nhap tu: ";
			cin >> keylog;
			//cout << "Khoa cua tu ban muon them la: " << returnHash(keylog) << endl;;
			//cout << "Moi ban nhap khoa: ";
			key = returnHash(keylog);
			cout << "Nghia cua tu khoa(Loai tu):  ";
			cin.ignore();
			getline(std::cin, value);
			hash.Insert(key, value);
			break;
		}
		case 2:
			cout << "Moi ban nhap tu can dich nghia: ";
			cin >> keylog;
			key = returnHash(keylog);
			if (hash.Search(key) == "a")
			{
				cout << "Khong co tu trong tu dien! " << key << endl;
				continue;
			}
			else
			{
				cout << "Nghia cua tu " << keylog << " la :";
				cout << hash.Search(key) << endl;
			}
			break;
		
		case 3:
			exit(1);
		default:
			cout << "\nBan chon:\n";
		}
	}
	return 0;
}