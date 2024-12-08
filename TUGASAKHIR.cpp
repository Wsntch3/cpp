#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

const int MAX_Barang = 100;

struct Barang {
    int jumlah;
    string nama;
    char kode [10];
    float harga;
};


Barang Inventaris[MAX_Barang];
int jumlahbarang = 0;

string formatharga(float total){
    char buffer[50];
    sprintf(buffer, "%.2f", total);
    return string(buffer);
}


    void simpanfile(){
    ofstream file("inventaris.txt");
    if(!file){
        cout << "File tidak ada" << endl;
        return;
    }

    for (int i=0; i<jumlahbarang; i++){
        file << "Barang ke- " << i + 1 << endl;
        file << "Nama Barang: " << Inventaris[i].nama << endl;
        file << "Kode Barang: " << Inventaris[i].kode << endl;
        file << "Harga Barang: " << formatharga(Inventaris[i].harga) << endl;
        file << "Jumlah Barang: " << Inventaris[i].jumlah << endl;
    }
    file.close();
    cout << "DATA BERHASIL DISIMPAN" << endl;
}


void tambahbarang(){
    if (jumlahbarang >= MAX_Barang){
        cout << "Kapasitas Inventaris Penuh" << endl;
    } 
    Barang B;
        cout << "masukkan nama barang: ";
        cin.ignore();
        getline(cin, B.nama);

        cout << "masukkan kode barang: ";
        cin >> B.kode;

        cout << "masukkan harga barang: ";
        cin >> B.harga;

        cout << "masukkan jumlah barang: ";
        cin >> B.jumlah;

        Inventaris[jumlahbarang++]= B; 
        cout << "Barang berhasil ditambahkan" << endl;

        simpanfile();
    } 

    void tampilkanbarang(){
        if (jumlahbarang <=0){
            cout << "inventaris kosong" << endl;
            return;
        }
        cout << "\nDAFTAR BARANG DALAM INVENTARIS: \n";
        for (int i=0; i<jumlahbarang; i++){
            cout << "Barang ke- " << i + 1 << endl;
            cout << "Nama Barang: " << Inventaris[i].nama << endl;
            cout << "Kode Barang: " << Inventaris[i].kode << endl;
            cout << "Harga Barang: Rp." << formatharga(Inventaris[i].harga) << endl;
            cout << "Jumlah Barang: " << Inventaris[i].jumlah << endl;
        }
    }

    void updatebarang(){
        if (jumlahbarang == 0){
            cout << "Inventaris kosong" << endl;
            return;
        }
        char kode[10];
        cout << "Masukkan Kode Barang: ";
        cin >> kode;
        for (int i=0; i<jumlahbarang; i++){
            if (strcmp(Inventaris[i].kode,kode ) == 0){
                cout << "Barang Ditemukan,Masukkan Jumlah Baru: ";
                cin >> Inventaris[i].jumlah;
                cout << "Barang Berhasil Diupdate \n";
                return;
            } else {
                 cout << "Barang Dengan Kode: " << kode << " Tidak Ditemukan" << endl;
            }
        } 
    }

    void jumlahhargabarang(){
        if (jumlahbarang == 0){
            cout << "Inventaris Kosong" << endl;
            return;
        }

        float total = 0;
        for (int i=0; i<jumlahbarang; i++){
            total += Inventaris[i].harga * Inventaris[i].jumlah;
        }

        cout << "Total Harga Barang Dalam Inventaris: Rp." << formatharga(total) << "\n" << endl;
    }

    int caribarang(int index, const char* kode){
        if (index >= jumlahbarang){
            return -1;
        }
        if (strcmp(Inventaris[index].kode, kode) == 0){
            return index;
        }
        return caribarang(index + 1, kode);
    }


    void caribarang(){
        if(jumlahbarang == 0){
            cout << "Inventaris Kosong" << endl;
            return;
        }
        char kode[10];
        cout << "Masukkan Kode Barang: ";
        cin >> kode;
        int index = caribarang(0, kode);
        if (index != -1){
            cout << "BARANG DITEMUKAN" << endl;
            cout << "Nama Barang:" << Inventaris[index].nama << endl;
            cout << "Kode Barang: " << Inventaris[index].kode << endl;
            cout << "Harga Barang: " << formatharga(Inventaris[index].harga) << endl;
            cout << "Jumlah Barang: " << Inventaris[index].jumlah << endl;
        } else {
            cout << "Barang Dengan Kode: " << kode << " Tidak Ditemukan" << endl;
        }
    }


int main(){
    int pilihan;
    do {
        cout << "Menu : " << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Update Barang" << endl;
        cout << "3. Tampil Barang" << endl;
        cout << "4. Jumlah Harga Barang" << endl;
        cout << "5. Cari Barang" << endl;
        cout << "6. Selesai" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        switch (pilihan){
            case 1:
                tambahbarang();
                break;
            case 2:
                updatebarang();
                break;
            case 3:
                tampilkanbarang();
                break;
            case 4:
                jumlahhargabarang();
                break;
            case 5 :
                caribarang();
                break;
            case 6:
                cout << "Terima Kasih" << endl;
                break;
            default:
                cout << "Pilihan Tidak Valid" << endl;
        } 
    } while (pilihan !=6);
    return 0;
}




