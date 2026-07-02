#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;

struct Edge {
    string tujuan;
    int waktu_tempuh;
};

class RumahSakitGraph {
private:
    // PERBAIKAN: Menambahkan '>' yang kurang pada deklarasi unordered_map
    unordered_map<string, vector<Edge>> graph;

public:
    void tambahUnit(string unit) {
        if (graph.find(unit) == graph.end()) {
            graph[unit] = vector<Edge>();
        }
    }

    void tambahJalur(string asal, string tujuan, int waktu_tempuh) {
        tambahUnit(asal);
        tambahUnit(tujuan);
        graph[asal].push_back({tujuan, waktu_tempuh});
    }

    void cariRuteTercepat(string awal, string tujuan) {
        unordered_map<string, int> waktu_minimum;
        unordered_map<string, string> rute_sebelumnya;

        for (auto const& [unit, list_edge] : graph) {
            waktu_minimum[unit] = INT_MAX;
            rute_sebelumnya[unit] = "";
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        waktu_minimum[awal] = 0;
        pq.push({0, awal});

        while (!pq.empty()) {
            int waktu_sekarang = pq.top().first;
            string unit_sekarang = pq.top().second;
            pq.pop();

            if (unit_sekarang == tujuan) break;

            if (waktu_sekarang > waktu_minimum[unit_sekarang]) continue;

            for (const auto& edge : graph[unit_sekarang]) {
                int total_waktu = waktu_sekarang + edge.waktu_tempuh;

                if (total_waktu < waktu_minimum[edge.tujuan]) {
                    waktu_minimum[edge.tujuan] = total_waktu;
                    rute_sebelumnya[edge.tujuan] = unit_sekarang;
                    pq.push({total_waktu, edge.tujuan});
                }
            }
        }

        if (waktu_minimum[tujuan] == INT_MAX) {
            cout << "[ERROR] Jalur rujukan tidak tersedia atau unit terisolasi." << endl;
            return;
        }

        vector<string> jalur_rujukan;
        string unit_aktif = tujuan;

        while (unit_aktif != "") {
            jalur_rujukan.push_back(unit_aktif);
            unit_aktif = rute_sebelumnya[unit_aktif];
        }

        reverse(jalur_rujukan.begin(), jalur_rujukan.end());

        cout << " [RUTE DITEMUKAN] " << endl;
        for (size_t i = 0; i < jalur_rujukan.size(); ++i) {
            cout << jalur_rujukan[i];
            if (i < jalur_rujukan.size() - 1) {
                cout << " -> ";
            }
        }
        cout << "\nEstimasi Waktu Tempuh: " << waktu_minimum[tujuan] << " Menit" << endl;
    }
};

int main() {
    RumahSakitGraph rs_digital;

    vector<string> units = {"UGD", "Laboratorium", "Apotek", "Ruang Operasi", "ICU", "Poliklinik"};
    for (const string& u : units) {
        rs_digital.tambahUnit(u);
    }

    rs_digital.tambahJalur("UGD", "Laboratorium", 3);
    rs_digital.tambahJalur("UGD", "Ruang Operasi", 5);
    rs_digital.tambahJalur("Laboratorium", "Apotek", 2);
    rs_digital.tambahJalur("Laboratorium", "Ruang Operasi", 4);
    rs_digital.tambahJalur("Ruang Operasi", "ICU", 2);
    rs_digital.tambahJalur("Apotek", "ICU", 6);
    rs_digital.tambahJalur("Poliklinik", "Apotek", 4);

    string asal_rujukan = "UGD";
    string tujuan_rujukan = "ICU";

    cout << "=== SISTEM RUJUKAN DIGITAL RUMAH SAKIT ===" << endl;
    cout << "Mencari rute rujukan tercepat dari [" << asal_rujukan << "] ke [" << tujuan_rujukan << "]...\n" << endl;

    rs_digital.cariRuteTercepat(asal_rujukan, tujuan_rujukan);

    return 0;
}
