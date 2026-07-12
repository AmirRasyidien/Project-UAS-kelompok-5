# 🏥 Project UAS: Sistem Rumah Sakit Digital

Selamat datang di repositori **Project UAS Praktikum Algoritma dan Struktur Data**. 
Repositori ini berisi *source code*, dokumentasi, dan aset proyek untuk pengembangan **Sistem Rumah Sakit Digital** berbasis C++ (CLI). Aplikasi ini dirancang untuk menyelesaikan permasalahan nyata di fasilitas kesehatan dengan mengimplementasikan berbagai struktur data secara efisien.

---

## 🎯 Deskripsi Proyek

Sistem Rumah Sakit Digital adalah aplikasi yang mengelola alur informasi di rumah sakit, mulai dari pendaftaran pasien, pengelolaan antrean, jadwal dokter, rekam medis, hingga sistem rujukan antar unit pelayanan. 

### ⚙️ Fitur Utama & Implementasi Struktur Data
Sesuai dengan kebutuhan studi kasus, aplikasi ini memanfaatkan struktur data berikut:
1. **Manajemen Data Pasien:** Menggunakan **Linked List** untuk menyimpan data pasien secara dinamis (tambah, edit, hapus, cari).
2. **Sistem Antrean Pelayanan:** Menggunakan **Queue** untuk mengatur antrean pasien di loket pendaftaran, poliklinik, dan farmasi (FIFO).
3. **Riwayat Pemeriksaan (Rekam Medis):** Menggunakan **Stack** untuk melihat riwayat kunjungan terakhir pasien (LIFO).
4. **Pencarian Jadwal Dokter:** Menggunakan **Binary Search Tree (BST)** untuk mempercepat pencarian data dokter berdasarkan spesialisasi atau ID.
5. **Sistem Rujukan & Pemetaan Unit:** Menggunakan **Graph** untuk merepresentasikan jarak atau rute pemindahan pasien antar unit/bangsal rumah sakit.

---

## 📂 Struktur Direktori

* **`📁 Pengumpulan/`** : Berisi file final siap kumpul (*Source Code* C++ utama, File Executable `.exe`, Laporan Proyek `.pdf`, dan Slide Presentasi).
* **`📁 SOAL/`** : Berisi referensi dokumen soal UAS dan panduan proyek.
* **`📄 README.md`** : Dokumentasi utama repositori ini.

---
## 👥 tim Pengembang

Proyek ini dikerjakan secara berkelompok. Berikut adalah susunan tim kami beserta tugas dan tanggung jawab masing-masing:

| Peran | Nama | Tugas & Tanggung Jawab |
| :--- | :--- | :--- |
| **Ketua** | Amir Rasyidien Soekandar | Lead Developer, bertanggung jawab melakukan analisis kebutuhan sistem, merancang struktur program, mengelola repository GitHub, membuat menu utama. |
| **Anggota 1** | Silmi | Mengembangkan Modul Manajemen Pasien menggunakan Linked List, meliputi fitur tambah, tampil, ubah, dan hapus data pasien. Menggabungkan seluruh modul., menyusun laporan. |
| **Anggota 2** | Tata | Mengembangkan Modul Antrean Pelayanan menggunakan Queue, meliputi pengambilan nomor antrean, pemanggilan antrean, melihat antrean berikutnya, dan menampilkan seluruh antrean. |
| **Anggota 3** | Dyraj | Mengembangkan Modul Jadwal Dokter menggunakan Binary Search Tree (BST), meliputi tambah, tampil, cari berdasarkan ID dan spesialisasi, serta hapus data dokter. Membuat ppt presentasi. |
| **Anggota 4** | Soshander | Mengembangkan Modul Rujukan Rumah Sakit menggunakan Graph dan Algoritma Dijkstra untuk menentukan jalur tercepat antar unit rumah sakit, serta membantu proses pengujian aplikasi. |

## 🛠️ Langkah-langkah Menjalankan Program

Pastikan Anda memiliki *compiler* C++ (seperti MinGW/GCC) yang terinstal di perangkat Anda.

1. **Clone Repositori** Buka terminal/CMD dan jalankan:
```bash
   git clone [https://github.com/](https://github.com/)[Username-Kamu]/[Nama-Repository].git
