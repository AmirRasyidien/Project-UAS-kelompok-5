#include <iostream>
using namespace std;

// struktur data pasien
struct pasien{
	int id;
	string nama;
	int umur;
	string alamat;
	string keluhan;
};

// node linked list pasien
struct node{
	pasien data;
	node* next;
};

node* head = NULL;

// tambah pasien
void tambahPasien(){
	node* baru = new node;

	cout << "\n=====Tambah Data Pasien=====\n";
	cout << "ID Pasien :" ;
	cin >> baru->data.id;
	cin.ignore();

	cout << "Nama      :";
	getline(cin, baru->data.nama;

	cout << "Umur      :";
	cin >> baru->data.umur;
	cin.ignore();

	cout << "Alamat    :";
	getline(cin, baru->data.alamat);

	cout << "Keluhan   :";
	getline(cin, baru->data.keluhan);

}

int main() {
	tambahPasien();
}
