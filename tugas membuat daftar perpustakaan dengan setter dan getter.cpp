#include <iostream>
#include <vector>
using namespace std;

// Kelas Buku
class Buku {
private:
    string judul;
    string penulis;
    bool dipinjam;

public:
    void setJudul(string j) { judul = j; }
    void setPenulis(string p) { penulis = p; }
    void setDipinjam(bool status) { dipinjam = status; }

    string getJudul() { return judul; }
    string getPenulis() { return penulis; }
    bool getDipinjam() { return dipinjam; }

    void tampilkanInfo(int index) {
        cout << index + 1 << ". " << judul << " oleh " << penulis << " - ";
        cout << (dipinjam ? "Dipinjam" : "Tersedia") << endl;
    }
};

// Kelas Pelajar
class Pelajar {
private:
    string nama;

public:
    void setNama(string n) { nama = n; }
    string getNama() { return nama; }

    void pinjamBuku(Buku &buku) {
        if (!buku.getDipinjam()) {
            buku.setDipinjam(true);
            cout << nama << " berhasil meminjam buku '" << buku.getJudul() << "'\n";
        } else {
            cout << "Buku '" << buku.getJudul() << "' sedang dipinjam orang lain.\n";
        }
    }

    void kembalikanBuku(Buku &buku) {
        if (buku.getDipinjam()) {
            buku.setDipinjam(false);
            cout << nama << " mengembalikan buku '" << buku.getJudul() << "'\n";
        } else {
            cout << "Buku '" << buku.getJudul() << "' tidak sedang dipinjam.\n";
        }
    }
};

// Program utama
int main() {
    int jumlahBuku;
    cout << "Masukkan jumlah buku di perpustakaan: ";
    cin >> jumlahBuku;
    cin.ignore();

    vector<Buku> daftarBuku(jumlahBuku);

    // Input data buku
    for (int i = 0; i < jumlahBuku; i++) {
        string judul, penulis;
        cout << "\nMasukkan data untuk buku ke-" << i + 1 << ":\n";
        cout << "Judul   : ";
        getline(cin, judul);
        cout << "Penulis : ";
        getline(cin, penulis);

        daftarBuku[i].setJudul(judul);
        daftarBuku[i].setPenulis(penulis);
        daftarBuku[i].setDipinjam(false);
    }

    // Input pelajar
    Pelajar pelajar;
    string namaPelajar;
    cout << "\nMasukkan nama pelajar: ";
    getline(cin, namaPelajar);
    pelajar.setNama(namaPelajar);

    int pilihan;
    do {
        cout << "\n=== Menu ===\n";
        cout << "1. Tampilkan Daftar Buku\n";
        cout << "2. Pinjam Buku\n";
        cout << "3. Kembalikan Buku\n";
        cout << "4. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "\n--- Daftar Buku ---\n";
            for (int i = 0; i < daftarBuku.size(); i++) {
                daftarBuku[i].tampilkanInfo(i);
            }
        } else if (pilihan == 2) {
            int nomor;
            cout << "\nMasukkan nomor buku yang ingin dipinjam: ";
            cin >> nomor;
            if (nomor >= 1 && nomor <= daftarBuku.size()) {
                pelajar.pinjamBuku(daftarBuku[nomor - 1]);
            } else {
                cout << "Nomor buku tidak valid!\n";
            }
        } else if (pilihan == 3) {
            int nomor;
            cout << "\nMasukkan nomor buku yang ingin dikembalikan: ";
            cin >> nomor;
            if (nomor >= 1 && nomor <= daftarBuku.size()) {
                pelajar.kembalikanBuku(daftarBuku[nomor - 1]);
            } else {
                cout << "Nomor buku tidak valid!\n";
            }
        } else if (pilihan != 4) {
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 4);

    cout << "\nTerima kasih. Program selesai.\n";

    return 0;
}
