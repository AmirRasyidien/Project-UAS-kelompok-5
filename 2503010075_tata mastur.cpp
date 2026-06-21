#include <iostream>
using namespace std;

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

    if (nomorAntrean < 10)
        cout << "00";
    else if (nomorAntrean < 100)
        cout << "0";

    cout << nomorAntrean << " berhasil diambil." << endl;
}

void panggilNomor() {
    if (front == -1 || front > rear) {
        cout << "\nTidak ada antrean yang dipanggil." << endl;
        return;
    }

    int dipanggil = antrean[front];

    cout << "\nMemanggil nomor antrean : A";

    if (dipanggil < 10)
        cout << "00";
    else if (dipanggil < 100)
        cout << "0";

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

        if (antrean[front] < 10)
            cout << "00";
        else if (antrean[front] < 100)
            cout << "0";

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

        if (antrean[i] < 10)
            cout << "00";
        else if (antrean[i] < 100)
            cout << "0";

        cout << antrean[i] << endl;
    }

    cout << "Jumlah antrean : "
         << (rear - front + 1) << endl;
}

void menuQueue() {
    int pilih;

    do {
        cout << "\n=================================";
        cout << "\n       MODUL ANTREAN (QUEUE)";
        cout << "\n=================================";
        cout << "\n1. Ambil Nomor Antrean";
        cout << "\n2. Panggil Nomor Antrean";
        cout << "\n3. Lihat Antrean Berikutnya";
        cout << "\n4. Tampilkan Semua Antrean";
        cout << "\n5. Kembali ke Menu Utama";
        cout << "\nPilih Menu : ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                ambilNomor();
                break;

            case 2:
                panggilNomor();
                break;

            case 3:
                lihatAntreanBerikutnya();
                break;

            case 4:
                tampilAntrean();
                break;

            case 5:
                cout << "\nKembali ke Menu Utama..." << endl;
                break;

            default:
                cout << "\nPilihan tidak tersedia!" << endl;
        }

    } while (pilih != 5);
}

int main() {
    int menu;

    do {
        cout << "\n=================================";
        cout << "\n          MENU UTAMA";
        cout << "\n=================================";
        cout << "\n1. Modul Antrean (Queue)";
        cout << "\n2. Tentang Program";
        cout << "\n3. Keluar";
        cout << "\nPilih Menu : ";
        cin >> menu;

        switch (menu) {
            case 1:
                menuQueue();
                break;

            case 2:
                cout << "\nPROGRAM UAS STRUKTUR DATA";
                cout << "\nImplementasi Queue";
                cout << "\nFitur Pengambilan dan Pemanggilan Nomor Antrean";
                cout << "\nMenggunakan Dev-C++";
                cout << endl;
                break;

            case 3:
                cout << "\nTerima kasih." << endl;
                break;

            default:
                cout << "\nMenu tidak tersedia!" << endl;
        }

    } while (menu != 3);

    return 0;
}
