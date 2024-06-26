#include <iostream>
#include <iomanip> 
using namespace std;

struct Toko{
    
    string produk;
    int harga;
    int stok;

    Toko *next;
};

Toko *head, *tail, *cur, *newNode, *del, *before;


bool isEmpty(){

    if (head == NULL){
        return true;
    }else{
        return false;
    }
}

void createList(string produk, int harga, int stok){

    head = new Toko();
    head->produk = produk;
    head->harga = harga;
    head->stok = stok;
    head->next = NULL;
    tail = head;
}

void tambahDepanProduk(string produk, int harga, int stok){
    newNode = new Toko();
    newNode->produk = produk;
    newNode->harga = harga;
    newNode->stok = stok;
    newNode->next = head;
    head = newNode;
    
}

void tambahBelakangProduk(string produk, int harga, int stok){

    newNode = new Toko();
    newNode->produk = produk;
    newNode->harga = harga;
    newNode->stok = stok;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void tambahTengahProduk(string produk, int harga, int stok, int posisi){

    newNode = new Toko();
    newNode->produk = produk;
    newNode->harga = harga;
    newNode->stok = stok;

    cur = head;
    int nomor = 1;
    while(nomor < posisi-1){

        cur = cur->next;
        nomor++;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    
}

void hapusDepan(){
    
    cur = head;
    head = head->next;
    delete cur;
}

void hapusBelakang(){
    
    del = tail;
    cur = head;
    while(cur->next != tail){
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

void hapusTengah(int posisi){
    
    cur = head;
    int nomor = 1;
    while(nomor <= posisi){
        if(nomor == posisi-1){
            before = cur;
        }
        if(nomor == posisi){
            del = cur;
        }
        cur = cur->next;
        nomor++;
    }
    before->next = cur;
    delete del;
}

void ubahProduk(string produk, int hargaBaru, int stokBaru) {
    cur->produk = produk;
    cur->harga = hargaBaru;
    cur->stok = stokBaru;
}

void cariProduk(string produk) {
    cur = head;
    bool found = false; 

    while (cur != NULL) {
        if (cur->produk == produk) {
            found = true;  
            break;  
        }
        cur = cur->next;
    }

    if (found) {
        cout << "Produk ditemukan:" << endl;
        cout << "Produk: " << cur->produk << endl;
        cout << "Harga: " << cur->harga << endl;
        cout << "Stok: " << cur->stok << endl;
    } else {
        cout << "Produk tidak ditemukan." << endl;
    }
}

void totalHarga(){
    int total = 0;
    cur = head;
    while(cur != NULL){
        total += cur->harga*cur->stok;
        cur = cur->next;
    }
    cout << "Total Nilai Rp." << total;
    cout << endl;
}

void tampilkanSemua() {
    cur = head;

    cout << "+====+=======================+============+===========+" << endl;
    cout << "| No |   Nama Produk         |    Stok    |   Harga   |" << endl;
    cout << "+====+=======================+============+===========+" << endl;

    int nomor = 1;
    while (cur != NULL) {
        cout << "| " << setw(2) << nomor << " | " << setw(21) << cur->produk << " | " << setw(10) << cur->stok << " | " << setw(9) << cur->harga << " |" << endl;
        cur = cur->next;
        nomor++;
    }
    cout << "+====+=======================+============+===========+" << endl;
    cout << endl;
}


int main(){

createList("Samyang",25500,22);
tambahDepanProduk("MSG",3200,43);
tambahBelakangProduk("Torabika",17900,34);
tambahBelakangProduk("Kopiko",9500,42);
tambahDepanProduk("Indomie",3100,56);

int pilih1,pilih2;
string produk;
string produkBaru;
int hargaBaru;
int stokBaru;
int posisi;

do {
    cout << "\n"<< endl;
    cout << ">>>>>Menu Inventaris Toko<<<<<" << endl;
    cout << "1. Tambah Produk" << endl;
    cout << "2. Hapus Produk" << endl;
    cout << "3. Perbarui Produk" << endl;
    cout << "4. Cari Produk" << endl;
    cout << "5. Tampilkan Semua Produk" << endl;
    cout << "6. Hitung Total Nilai Inventaris" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilih Nomer : ";
    cin >> pilih1;
    cout << endl;

    switch (pilih1){

    case 1:
            cout << "Tambahkan produk baru ke bagian:" << endl;
            cout << "1. Awal list" << endl;
            cout << "2. Tengah list" << endl;
            cout << "3. Akhir list" << endl;
            cout << "Pilih nomer : ";
            cin >> pilih2;
            cout << endl;

            switch (pilih2) {
            case 1:
                cout << "Masukkan nama produk, harga, dan stok baru: ";
                cin >> produkBaru >> hargaBaru >> stokBaru;
                tambahDepanProduk(produkBaru, hargaBaru, stokBaru);
                cout << "Produk " << produkBaru << " berhasil ditambahkan ke dalam list";
                break;
            case 2:
                cout << "Masukkan posisi (nomor urut) untuk tambah tengah: ";
                cin >> posisi;
                cout << "Masukkan nama produk, harga, dan stok baru: ";
                cin >> produkBaru >> hargaBaru >> stokBaru;
                tambahTengahProduk(produkBaru, hargaBaru, stokBaru, posisi);
                cout << "Produk " << produkBaru << " berhasil ditambahkan ke dalam list";
                break;
            case 3:
                cout << "Masukkan nama produk, harga, dan stok baru: ";
                cin >> produkBaru >> hargaBaru >> stokBaru;
                tambahBelakangProduk(produkBaru, hargaBaru, stokBaru);
                cout << "Produk " << produkBaru << " berhasil ditambahkan ke dalam list";
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
            }
            break;

        case 2:
            cout << "Hapus produk di bagian:" << endl;
            cout << "1. Awal list" << endl;
            cout << "2. Tengah list" << endl;
            cout << "3. Akhir list" << endl;
            cout << "Pilih nomer : ";
            cin >> pilih2;
            cout << endl;

            switch (pilih2) {
            case 1:
                hapusDepan();
                cout << "Produk di awal list berhasil dihapus";
                break;
            case 2:
                cout << "Masukkan posisi (nomor urut) untuk hapus tengah: ";
                cin >> posisi;
                hapusTengah(posisi);
                cout << "Produk di posisi ke-"<< posisi << "list berhasil dihapus";
                break;
            case 3:
                hapusBelakang();
                cout << "Produk di akhir list berhasil dihapus";
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
            }
            break;

        case 3:
            cout << "Masukkan nama produk yang ingin diperbarui: ";
            cin >> produk;
            cur = head;
            while (cur != NULL) {
                if (cur->produk == produk) {
                    cout << "Masukkan nama produk baru: ";
                    cin >> produkBaru;
                    cout << "Masukkan harga baru: ";
                    cin >> hargaBaru;
                    cout << "Masukkan stok baru: ";
                    cin >> stokBaru;

                    ubahProduk(produkBaru, hargaBaru, stokBaru);
                    cout << "Produk " << produk << " diperbarui " << "menjadi " << produkBaru << endl;
                    break;
                }
                cur = cur->next;
            }
            if (cur == NULL) {
                cout << "Produk tidak ditemukan." << endl;
            }
            break;

        case 4:
            cout << "Nama Produk yang ingin dicari: ";
            cin >> produk;
            cariProduk(produk);
            break;

        case 5:
            tampilkanSemua();
            break;

        case 6:
            totalHarga();
            break;

    case 0:
        cout << "ANDA TELAH KELUAR (˶ᵔ ᵕ ᵔ˶)";
        cout << "\n" <<endl;
        return 0;
    default:
        cout << "Pilih yang bener (˶˃⤙˂˶)";
        break;
}
}while (pilih1 != 0);
return 0;
}
