#include <stdio.h>
#include <string.h>

// Definisi struct untuk item menu
struct MenuItem {
    char nama[50];
    int harga;
    int stok;
};

// Array untuk menyimpan item menu
struct MenuItem menu[100];
int jumlahMenu = 0; // Variabel untuk menghitung jumlah item dalam menu

// Fungsi untuk menambahkan item menu menggunakan pointer
void tambahMenu(char *nama, int harga, int stok) {
    strcpy(menu[jumlahMenu].nama, nama);
    menu[jumlahMenu].harga = harga;
    menu[jumlahMenu].stok = stok;
    jumlahMenu++;
    printf("Item '%s' berhasil ditambahkan ke menu!\n", nama);
}

// Fungsi untuk menampilkan semua item dalam menu
void tampilkanMenu() {
    if (jumlahMenu == 0) {
        printf("Menu kosong. Tambahkan item terlebih dahulu.\n");
        return;
    }
    printf("\n=== Daftar Menu ===\n");
    for (int i = 0; i < jumlahMenu; i++) {
        printf("%d. %s - Harga: %d - Stok: %d\n", i+1, menu[i].nama, menu[i].harga, menu[i].stok);
    }
}

// Fungsi untuk mengubah item menu berdasarkan indeks menggunakan pointer
void ubahMenu(int index, char *namaBaru, int hargaBaru, int stokBaru) {
    if (index < 0 || index >= jumlahMenu) {
        printf("Item menu tidak ditemukan.\n");
        return;
    }
    strcpy(menu[index].nama, namaBaru);
    menu[index].harga = hargaBaru;
    menu[index].stok = stokBaru;
    printf("Item menu berhasil diubah!\n");
}

// Fungsi untuk menghapus item dari menu menggunakan pointer
void hapusMenu(int index) {
    if (index < 0 || index >= jumlahMenu) {
        printf("Item menu tidak ditemukan.\n");
        return;
    }
    for (int i = index; i < jumlahMenu - 1; i++) {
        menu[i] = menu[i + 1];
    }
    jumlahMenu--;
    printf("Item menu berhasil dihapus!\n");
}

// Fungsi untuk memproses pesanan dan mengurangi stok item
void buatPesanan() {
    int totalHarga = 0;
    int pilihan, kuantitas;

    tampilkanMenu();
    
    if (jumlahMenu == 0) return;

    printf("Masukkan nomor item yang ingin dipesan (0 untuk selesai): ");
    while (1) {
        scanf("%d", &pilihan);
        if (pilihan == 0) break;
        if (pilihan < 1 || pilihan > jumlahMenu) {
            printf("Nomor item tidak valid. Coba lagi.\n");
            continue;
        }

        printf("Masukkan kuantitas: ");
        scanf("%d", &kuantitas);

        if (menu[pilihan - 1].stok < kuantitas) {
            printf("Stok tidak mencukupi.\n");
            continue;
        }

        totalHarga += menu[pilihan - 1].harga * kuantitas;
        menu[pilihan - 1].stok -= kuantitas;

        printf("Item '%s' sebanyak %d berhasil ditambahkan ke pesanan.\n", menu[pilihan - 1].nama, kuantitas);
    }

    printf("Total harga pesanan: %d\n", totalHarga);
}

// Main program
int main() {
    int pilihan;

    do {
        printf("\n=== Sistem Penjualan Warmindo ===\n");
        printf("1. Tampilkan Menu\n");
        printf("2. Tambah Item Menu\n");
        printf("3. Ubah Item Menu\n");
        printf("4. Hapus Item Menu\n");
        printf("5. Buat Pesanan\n");
        printf("6. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tampilkanMenu();
                break;
            case 2: {
                char nama[50];
                int harga, stok;
                printf("Masukkan nama item: ");
                scanf(" %[^\n]", nama);
                printf("Masukkan harga item: ");
                scanf("%d", &harga);
                printf("Masukkan stok item: ");
                scanf("%d", &stok);
                tambahMenu(nama, harga, stok);
                break;
            }
            case 3: {
                int index;
                char namaBaru[50];
                int hargaBaru, stokBaru;
                tampilkanMenu();
                printf("Pilih nomor item yang ingin diubah: ");
                scanf("%d", &index);
                printf("Masukkan nama baru: ");
                scanf(" %[^\n]", namaBaru);
                printf("Masukkan harga baru: ");
                scanf("%d", &hargaBaru);
                printf("Masukkan stok baru: ");
                scanf("%d", &stokBaru);
                ubahMenu(index - 1, namaBaru, hargaBaru, stokBaru);
                break;
            }
            case 4: {
                int index;
                tampilkanMenu();
                printf("Pilih nomor item yang ingin dihapus: ");
                scanf("%d", &index);
                hapusMenu(index - 1);
                break;
            }
            case 5:
                buatPesanan();
                break;
            case 6:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 6);

    return 0;
}
