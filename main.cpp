#include <iostream>
#include <cstring>

using namespace std;

// Definisikan struct untuk menyimpan informasi mahasiswa
struct Mahasiswa {
    int id;
    char nama[50];
    float ipk;
    Mahasiswa* next; // Pointer ke node berikutnya dalam linked list
};

// Fungsi untuk menambahkan data mahasiswa
void tambahMahasiswa(Mahasiswa*& kepala) {
    Mahasiswa* mahasiswaBaru = new Mahasiswa; // Buat node baru

    // Meminta pengguna untuk memasukkan informasi mahasiswa
    cout << "Masukkan ID mahasiswa: ";
    cin >> mahasiswaBaru->id;
    cout << "Masukkan nama mahasiswa: ";
    cin.ignore(); // Untuk menghindari masalah dengan getline setelah cin
    cin.getline(mahasiswaBaru->nama, 50);
    cout << "Masukkan IPK mahasiswa: ";
    cin >> mahasiswaBaru->ipk;

    mahasiswaBaru->next = nullptr;

    if (kepala == nullptr) {
        // Jika linked list masih kosong, atur node baru sebagai kepala
        kepala = mahasiswaBaru;
    } else {
        // Jika tidak, cari node terakhir dan tambahkan node baru ke ujung
        Mahasiswa* temp = kepala;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = mahasiswaBaru;
    }
}

// Fungsi untuk mencetak semua data mahasiswa
void cetakMahasiswa(Mahasiswa* kepala) {
    if (kepala == nullptr) {
        cout << "Tidak ada mahasiswa dalam catatan." << endl;
    } else {
        cout << "Catatan Mahasiswa:" << endl;
        while (kepala != nullptr) {
            cout << "ID: " << kepala->id << ", Nama: " << kepala->nama << ", IPK: " << kepala->ipk << endl;
            kepala = kepala->next;
        }
    }
}

int main() {
    Mahasiswa* kepala = nullptr; // Pointer ke node pertama dalam linked list
    char tambahData;

    do {
        tambahMahasiswa(kepala); // Memanggil fungsi untuk menambahkan data mahasiswa
        cout << "Apakah Anda ingin menambahkan data mahasiswa lainnya? (y/n): ";
        cin >> tambahData;
    } while (tambahData == 'y' || tambahData == 'Y');

    // Mencetak semua data mahasiswa setelah pengguna selesai mengisi data
    cetakMahasiswa(kepala);

    return 0;
}
