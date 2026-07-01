#include <iostream>
#include <string>
using namespace std;

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
    if (root == NULL) {
        return buatNodeDokter(d);
    }

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

    if (id < root->data.id) {
        return cariDokterByID(root->kiri, id);
    } else {
        return cariDokterByID(root->kanan, id);
    }
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
    if (root == NULL) {
        return NULL;
    }

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

    if (berhasil) {
        cout << "\nData dokter berhasil dihapus.\n";
    } else {
        cout << "\nID dokter tidak ditemukan.\n";
    }
}

void menuDokter() {
    int pilih;

    do {
        cout << "\n=================================";
        cout << "\n       MODUL DOKTER (TREE)";
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
            case 1:
                tambahDokter();
                break;
            case 2:
                tampilkanDokter();
                break;
            case 3:
                cariDokter();
                break;
            case 4:
                cariDokterBySpesialisasi();
                break;
            case 5:
                hapusDokter();
                break;
            case 6:
                cout << "\nKembali ke Menu Utama..." << endl;
                break;
            default:
                cout << "\nPilihan tidak tersedia!" << endl;
        }

    } while (pilih != 6);
}

int main() {
    menuDokter();
    return 0;
}
