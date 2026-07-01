#include <iostream>
#include <string>
using namespace std;

struct pasien {
    int id;
    string nama;
    int umur;
    string alamat;
    string keluhan;
};
 
struct node {
    pasien data;
    node* next;
};

node* head = NULL;

void tambahPasien() {
    node* baru = new node;
    cout << "\n===== Tambah Data Pasien =====\n";
    cout << "ID      : ";
    cin >> baru->data.id;
    cin.ignore();
    cout << "Nama    : ";
    getline(cin, baru->data.nama);
    cout << "Umur    : ";
    cin >> baru->data.umur;
    cin.ignore();
    cout << "Alamat  : ";
    getline(cin, baru->data.alamat);
    cout << "Keluhan : ";
    getline(cin, baru->data.keluhan);
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "\nData pasien berhasil ditambahkan.\n";
}

void tampilkanPasien(){
    if(head == NULL) {
        cout << "\nData Pasien Kosong.\n";
        return;
    }
    cout << "\n===== Daftar Nama Pasien =====\n";
    node* temp = head;
    while(temp != NULL){
        cout << "ID      : " << temp->data.id << endl;
        cout << "Nama    : " << temp->data.nama << endl;
        cout << "Umur    : " << temp->data.umur << endl;
        cout << "Alamat  : " << temp->data.alamat << endl;
        cout << "Keluhan : " << temp->data.keluhan << endl;
        cout << "-------------------------------\n";
        temp = temp->next;
    }
}

void updatePasien(){
    if(head == NULL){
        cout << "\nData Pasien Kosong.\n";
        return;
    }
    int idCari;
    cout << "\nMasukkan ID yang akan diupdate : ";
    cin >> idCari;
    cin.ignore();
    node* temp = head;
    while(temp != NULL){
        if(temp->data.id == idCari){
            cout << "\nData ditemukan.\n";
            cout << "Nama Baru    : ";
            getline(cin, temp->data.nama);
            cout << "Umur Baru    : ";
            cin >> temp->data.umur;
            cin.ignore();
            cout << "Alamat Baru  : ";
            getline(cin, temp->data.alamat);
            cout << "Keluhan Baru : ";
            getline(cin, temp->data.keluhan);
            cout << "Data Berhasil diperbarui.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "ID pasien tidak ditemukan.\n";
}

void hapusPasien(){
    if(head == NULL){
        cout << "\nData Pasien Kosong.\n";
        return;
    }
    int idCari;
    cout << "\nMasukan ID yang akan dihapus : ";
    cin >> idCari;
    node* temp = head;
    node* prev = NULL;
    while(temp != NULL){
        if(temp->data.id == idCari){
            if(prev == NULL){
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Data Pasien Berhasil dihapus.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "ID Pasien tidak ditemukan.\n";
}

void menuPasien(){
    int pilihan;
    do {
        cout << "\n===============================";
        cout << "\n SISTEM MANAJEMEN DATA PASIEN ";
        cout << "\n===============================\n";
        cout << "1. Tambah Data Pasien\n";
        cout << "2. Tampilkan Data Pasien\n";
        cout << "3. Update Data Pasien\n";
        cout << "4. Hapus Data Pasien\n";
        cout << "0. Kembali ke Menu Utama\n";
        cout << "===============================\n";
        cout << "Pilih Menu   : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1 : tambahPasien(); break;
            case 2: tampilkanPasien(); break;
            case 3 : updatePasien(); break;
            case 4 : hapusPasien(); break;
            case 0 : cout << "Kembali ke Menu Utama...\n"; break;
            default : cout << "Pilihan tidak Valid.\n";
        }
    } while(pilihan != 0);
}

const int MAX = 100;
int antrean[MAX];
int front = -1;
int rear = -1;
int nomorAntrean = 0;

void ambilNomor() {
    if (rear == MAX - 1) {
        cout << "\nAntrean sudah penuh!" << endl;
        return;
    }
    nomorAntrean++;
    if (front == -1) {
        front = 0;
    }
    rear++;
    antrean[rear] = nomorAntrean;

    cout << "\nNomor antrean A";
    if (nomorAntrean < 10) cout << "00";
    else if (nomorAntrean < 100) cout << "0";
    cout << nomorAntrean << " berhasil diambil." << endl;
}

void panggilNomor() {
    if (front == -1 || front > rear) {
        cout << "\nTidak ada antrean yang dipanggil." << endl;
        return;
    }
    int dipanggil = antrean[front];
    cout << "\nMemanggil nomor antrean : A";
    if (dipanggil < 10) cout << "00";
    else if (dipanggil < 100) cout << "0";
    cout << dipanggil << endl;

    front++;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

void lihatAntreanBerikutnya() {
    if (front == -1) {
        cout << "\nAntrean kosong." << endl;
    } else {
        cout << "\nAntrean berikutnya : A";
        if (antrean[front] < 10) cout << "00";
        else if (antrean[front] < 100) cout << "0";
        cout << antrean[front] << endl;
    }
}

void tampilAntrean() {
    if (front == -1) {
        cout << "\nTidak ada antrean." << endl;
        return;
    }
    cout << "\nDaftar Antrean :" << endl;
    for (int i = front; i <= rear; i++) {
        cout << "A";
        if (antrean[i] < 10) cout << "00";
        else if (antrean[i] < 100) cout << "0";
        cout << antrean[i] << endl;
    }
    cout << "Jumlah antrean : " << (rear - front + 1) << endl;
}

void menuQueue() {
    int pilih;
    do {
        cout << "\n=================================";
        cout << "\n       MODUL ANTREAN     ";
        cout << "\n=================================";
        cout << "\n1. Ambil Nomor Antrean";
        cout << "\n2. Panggil Nomor Antrean";
        cout << "\n3. Lihat Antrean Berikutnya";
        cout << "\n4. Tampilkan Semua Antrean";
        cout << "\n5. Kembali ke Menu Utama";
        cout << "\nPilih Menu : ";
        cin >> pilih;

        switch (pilih) {
            case 1: ambilNomor(); break;
            case 2: panggilNomor(); break;
            case 3: lihatAntreanBerikutnya(); break;
            case 4: tampilAntrean(); break;
            case 5: cout << "\nKembali ke Menu Utama..." << endl; break;
            default: cout << "\nPilihan tidak tersedia!" << endl;
        }
    } while (pilih != 5);
}

struct dokter {
    int id;
    string nama;
    string spesialisasi;
    string jadwalPraktik;
};

struct nodeDokter {
    dokter data;
    nodeDokter* kiri;
    nodeDokter* kanan;
};

nodeDokter* rootDokter = NULL;

nodeDokter* buatNodeDokter(dokter d) {
    nodeDokter* baru = new nodeDokter;
    baru->data = d;
    baru->kiri = NULL;
    baru->kanan = NULL;
    return baru;
}

nodeDokter* insertDokter(nodeDokter* root, dokter d) {
    if (root == NULL) return buatNodeDokter(d);

    if (d.id < root->data.id) {
        root->kiri = insertDokter(root->kiri, d);
    } else if (d.id > root->data.id) {
        root->kanan = insertDokter(root->kanan, d);
    } else {
        cout << "\nID Dokter sudah terdaftar! Gunakan ID lain." << endl;
    }
    return root;
}

void tambahDokter() {
    dokter d;
    cout << "\n===== Tambah Data Dokter =====\n";
    cout << "ID Dokter      : ";
    cin >> d.id;
    cin.ignore();
    cout << "Nama           : ";
    getline(cin, d.nama);
    cout << "Spesialisasi   : ";
    getline(cin, d.spesialisasi);
    cout << "Jadwal Praktik : ";
    getline(cin, d.jadwalPraktik);

    rootDokter = insertDokter(rootDokter, d);
    cout << "\nData dokter berhasil ditambahkan.\n";
}

void tampilkanInOrder(nodeDokter* root) {
    if (root == NULL) return;
    tampilkanInOrder(root->kiri);
    cout << "ID             : " << root->data.id << endl;
    cout << "Nama           : " << root->data.nama << endl;
    cout << "Spesialisasi   : " << root->data.spesialisasi << endl;
    cout << "Jadwal Praktik : " << root->data.jadwalPraktik << endl;
    cout << "-------------------------------\n";
    tampilkanInOrder(root->kanan);
}

void tampilkanDokter() {
    if (rootDokter == NULL) {
        cout << "\nData Dokter Kosong.\n";
        return;
    }
    cout << "\n===== Daftar Dokter (Terurut berdasarkan ID) =====\n";
    tampilkanInOrder(rootDokter);
}

nodeDokter* cariDokterByID(nodeDokter* root, int id) {
    if (root == NULL) return NULL;
    if (id == root->data.id) return root;

    if (id < root->data.id) return cariDokterByID(root->kiri, id);
    else return cariDokterByID(root->kanan, id);
}

void cariDokter() {
    if (rootDokter == NULL) {
        cout << "\nData Dokter Kosong.\n";
        return;
    }
    int idCari;
    cout << "\nMasukkan ID Dokter yang dicari : ";
    cin >> idCari;

    nodeDokter* hasil = cariDokterByID(rootDokter, idCari);
    if (hasil == NULL) {
        cout << "\nDokter dengan ID tersebut tidak ditemukan.\n";
    } else {
        cout << "\n===== Data Dokter Ditemukan =====\n";
        cout << "ID             : " << hasil->data.id << endl;
        cout << "Nama           : " << hasil->data.nama << endl;
        cout << "Spesialisasi   : " << hasil->data.spesialisasi << endl;
        cout << "Jadwal Praktik : " << hasil->data.jadwalPraktik << endl;
    }
}

bool cariSpesialisasi(nodeDokter* root, string spesialisasi, bool& ketemu) {
    if (root == NULL) return ketemu;

    if (root->data.spesialisasi == spesialisasi) {
        cout << "ID             : " << root->data.id << endl;
        cout << "Nama           : " << root->data.nama << endl;
        cout << "Spesialisasi   : " << root->data.spesialisasi << endl;
        cout << "Jadwal Praktik : " << root->data.jadwalPraktik << endl;
        cout << "-------------------------------\n";
        ketemu = true;
    }
    cariSpesialisasi(root->kiri, spesialisasi, ketemu);
    cariSpesialisasi(root->kanan, spesialisasi, ketemu);

    return ketemu;
}

void cariDokterBySpesialisasi() {
    if (rootDokter == NULL) {
        cout << "\nData Dokter Kosong.\n";
        return;
    }
    string spesialisasi;
    cout << "\nMasukkan Spesialisasi yang dicari : ";
    cin.ignore();
    getline(cin, spesialisasi);

    cout << "\n===== Hasil Pencarian Spesialisasi \"" << spesialisasi << "\" =====\n";
    bool ketemu = false;
    cariSpesialisasi(rootDokter, spesialisasi, ketemu);

    if (!ketemu) {
        cout << "Tidak ada dokter dengan spesialisasi tersebut.\n";
    }
}

nodeDokter* cariNodeTerkecil(nodeDokter* root) {
    while (root->kiri != NULL) {
        root = root->kiri;
    }
    return root;
}

nodeDokter* hapusNodeDokter(nodeDokter* root, int id, bool& berhasil) {
    if (root == NULL) return NULL;

    if (id < root->data.id) {
        root->kiri = hapusNodeDokter(root->kiri, id, berhasil);
    } else if (id > root->data.id) {
        root->kanan = hapusNodeDokter(root->kanan, id, berhasil);
    } else {
        berhasil = true;
        if (root->kiri == NULL && root->kanan == NULL) {
            delete root;
            return NULL;
        } else if (root->kiri == NULL) {
            nodeDokter* temp = root->kanan;
            delete root;
            return temp;
        } else if (root->kanan == NULL) {
            nodeDokter* temp = root->kiri;
            delete root;
            return temp;
        } else {
            nodeDokter* pengganti = cariNodeTerkecil(root->kanan);
            root->data = pengganti->data;
            root->kanan = hapusNodeDokter(root->kanan, pengganti->data.id, berhasil);
        }
    }
    return root;
}

void hapusDokter() {
    if (rootDokter == NULL) {
        cout << "\nData Dokter Kosong.\n";
        return;
    }
    int idHapus;
    cout << "\nMasukkan ID Dokter yang akan dihapus : ";
    cin >> idHapus;

    bool berhasil = false;
    rootDokter = hapusNodeDokter(rootDokter, idHapus, berhasil);

    if (berhasil) cout << "\nData dokter berhasil dihapus.\n";
    else cout << "\nID dokter tidak ditemukan.\n";
}

void menuDokter() {
    int pilih;
    do {
        cout << "\n=================================";
        cout << "\n       MODUL DOKTER       ";
        cout << "\n=================================";
        cout << "\n1. Tambah Data Dokter";
        cout << "\n2. Tampilkan Semua Dokter";
        cout << "\n3. Cari Dokter berdasarkan ID";
        cout << "\n4. Cari Dokter berdasarkan Spesialisasi";
        cout << "\n5. Hapus Data Dokter";
        cout << "\n6. Kembali ke Menu Utama";
        cout << "\nPilih Menu : ";
        cin >> pilih;

        switch (pilih) {
            case 1: tambahDokter(); break;
            case 2: tampilkanDokter(); break;
            case 3: cariDokter(); break;
            case 4: cariDokterBySpesialisasi(); break;
            case 5: hapusDokter(); break;
            case 6: cout << "\nKembali ke Menu Utama..." << endl; break;
            default: cout << "\nPilihan tidak tersedia!" << endl;
        }
    } while (pilih != 6);
}

int main() {
    int menu;
    do {
        cout << "\n=================================================";
        cout << "\n       🏥 SISTEM RUMAH SAKIT DIGITAL 🏥";
        cout << "\n=================================================";
        cout << "\n1. Modul Manajemen Pasien";
        cout << "\n2. Modul Antrean Pelayanan";
        cout << "\n3. Modul Jadwal Dokter";
        cout << "\n4. Modul Rujukan & Pemetaan Unit - KOSONG";
        cout << "\n0. Keluar Aplikasi";
        cout << "\n=================================================";
        cout << "\nPilih Modul : ";
        cin >> menu;

        switch (menu) {
            case 1:
                menuPasien();
                break;
            case 2:
                menuQueue();
                break;
            case 3:
                menuDokter();
                break;
            case 4:
                cout << "\n[!] Modul ini sedang dikerjakan oleh Soshander.\n";
                break;
            case 0:
                cout << "\nTerima kasih telah menggunakan Sistem Rumah Sakit Digital.\n";
                break;
            default:
                cout << "\nMenu tidak tersedia! Silakan pilih kembali.\n";
        }
    } while (menu != 0);

    return 0;
}
