#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struktur untuk menu item
struct MenuItem {
    char nama[50];
    int harga;
    int stok;
    struct MenuItem *next;
};

// Struktur untuk riwayat pesanan (Stack)
struct RiwayatPesanan {
    char namaPesanan[100];
    int totalHarga;
    char waktuPesan[26];
    struct RiwayatPesanan *next;
};

// Struktur untuk antrian pesanan (Queue)
struct AntrianPesanan {
    char namaPelanggan[50];
    char detailPesanan[200];
    int nomorAntrian;
    struct AntrianPesanan *next;
};

struct MenuItem *head = NULL;
struct RiwayatPesanan *topRiwayat = NULL;
struct AntrianPesanan *frontAntrian = NULL;
struct AntrianPesanan *rearAntrian = NULL;
int nomorAntrianGlobal = 1;

// Fungsi untuk membuat menu item baru
struct MenuItem* createMenuItem(char *nama, int harga, int stok) {
    struct MenuItem *newItem = (struct MenuItem*)malloc(sizeof(struct MenuItem));
    strcpy(newItem->nama, nama);
    newItem->harga = harga;
    newItem->stok = stok;
    newItem->next = NULL;
    return newItem;
}

// Fungsi untuk mencari menu berdasarkan nama
struct MenuItem* cariMenu(char *nama) {
    struct MenuItem *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->nama, nama) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Fungsi untuk mencari menu berdasarkan nomor
struct MenuItem* cariMenuByNomor(int nomor) {
    struct MenuItem *temp = head;
    int index = 1;
    while (temp != NULL && index < nomor) {
        temp = temp->next;
        index++;
    }
    return temp;
}

// Fungsi untuk menambah menu baru
void tambahMenu(char *nama, int harga, int stok) {
    struct MenuItem *newItem = createMenuItem(nama, harga, stok);
    if (head == NULL) {
        head = newItem;
    } else {
        struct MenuItem *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newItem;
    }
    printf("Menu '%s' berhasil ditambahkan!\n", nama);
}

// Fungsi untuk menambah stok menu yang sudah ada
void tambahStokMenu(char *nama, int tambahStok) {
    struct MenuItem *temp = cariMenu(nama); // Mencari menu berdasarkan nama
    if (temp != NULL) {
        temp->stok += tambahStok;
        printf("Stok menu '%s' berhasil ditambahkan. Stok sekarang: %d\n", temp->nama, temp->stok);
    } else {
        printf("Menu '%s' tidak ditemukan.\n", nama);
    }
}

// Fungsi untuk menampilkan semua menu
void tampilkanMenu() {
    if (head == NULL) {
        printf("Menu kosong. Tambahkan menu terlebih dahulu.\n");
        return;
    }
    printf("\n=== Daftar Menu Warmindo ===\n");
    struct MenuItem *temp = head;
    int index = 1;
    while (temp != NULL) {
        printf("%d. %s - Harga: Rp %d - Stok: %d\n", index++, temp->nama, temp->harga, temp->stok);
        temp = temp->next;
    }
}

// Fungsi untuk Stack (Riwayat Pesanan)
void pushRiwayat(char *namaPesanan, int totalHarga) {
    struct RiwayatPesanan *newRiwayat = (struct RiwayatPesanan*)malloc(sizeof(struct RiwayatPesanan));
    strcpy(newRiwayat->namaPesanan, namaPesanan);
    newRiwayat->totalHarga = totalHarga;
    
    time_t waktuSekarang;
    time(&waktuSekarang);
    strcpy(newRiwayat->waktuPesan, ctime(&waktuSekarang));
    newRiwayat->waktuPesan[strlen(newRiwayat->waktuPesan) - 1] = '\0';  // Hapus newline

    newRiwayat->next = topRiwayat;
    topRiwayat = newRiwayat;
}

void tampilkanRiwayat() {
    if (topRiwayat == NULL) {
        printf("\nBelum ada riwayat pesanan.\n");
        return;
    }
    
    printf("\n=== Riwayat Pesanan ===\n");
    struct RiwayatPesanan *temp = topRiwayat;
    while (temp != NULL) {
        printf("Pesanan: %s\n", temp->namaPesanan);
        printf("Total: Rp %d\n", temp->totalHarga);
        printf("Waktu: %s", temp->waktuPesan);
        printf("-------------------------\n");
        temp = temp->next;
    }
}

// Fungsi untuk Queue (Antrian Pesanan)
void enqueueAntrian(char *namaPelanggan, char *detailPesanan) {
    struct AntrianPesanan *newAntrian = (struct AntrianPesanan*)malloc(sizeof(struct AntrianPesanan));
    strcpy(newAntrian->namaPelanggan, namaPelanggan);
    strcpy(newAntrian->detailPesanan, detailPesanan);
    newAntrian->nomorAntrian = nomorAntrianGlobal++;
    newAntrian->next = NULL;

    if (rearAntrian == NULL) {
        frontAntrian = rearAntrian = newAntrian;
    } else {
        rearAntrian->next = newAntrian;
        rearAntrian = newAntrian;
    }
    printf("Pesanan ditambahkan ke antrian dengan nomor %d\n", newAntrian->nomorAntrian);
}

void dequeueAntrian() {
    if (frontAntrian == NULL) {
        printf("Tidak ada antrian pesanan.\n");
        return;
    }

    struct AntrianPesanan *temp = frontAntrian;
    printf("\nPesanan Selesai:\n");
    printf("Nomor Antrian: %d\n", temp->nomorAntrian);
    printf("Nama Pelanggan: %s\n", temp->namaPelanggan);
    printf("Detail Pesanan: %s\n", temp->detailPesanan);

    frontAntrian = frontAntrian->next;
    if (frontAntrian == NULL) {
        rearAntrian = NULL;
    }
    free(temp);
}

void tampilkanAntrian() {
    if (frontAntrian == NULL) {
        printf("\nTidak ada antrian pesanan.\n");
        return;
    }

    printf("\n=== Antrian Pesanan ===\n");
    struct AntrianPesanan *temp = frontAntrian;
    while (temp != NULL) {
        printf("Nomor Antrian: %d\n", temp->nomorAntrian);
        printf("Nama Pelanggan: %s\n", temp->namaPelanggan);
        printf("Detail Pesanan: %s\n", temp->detailPesanan);
        printf("-------------------------\n");
        temp = temp->next;
    }
}

void buatPesanan() {
    char detailPesanan[200] = "";
    char namaPelanggan[50];
    int totalHarga = 0;
    int pilihan, kuantitas;
    char konfirmasi;

    // Tampilkan menu terlebih dahulu
    tampilkanMenu();
    if (head == NULL) {
        printf("\nTekan Enter untuk kembali ke menu utama...");
        getchar();
        getchar();
        return;
    }

    // Input nama pelanggan dengan opsi kembali
    printf("\nMasukkan nama pelanggan (0 untuk kembali): ");
    getchar(); // Membersihkan buffer
    if (fgets(namaPelanggan, sizeof(namaPelanggan), stdin) != NULL) {
        namaPelanggan[strcspn(namaPelanggan, "\n")] = 0; // Menghilangkan newline
        
        if (strcmp(namaPelanggan, "0") == 0) {
            printf("\nKembali ke menu utama...\n");
            return;
        }
    }

    while (1) {
        printf("\n=== Menu Pemesanan ===\n");
        printf("1. Tambah item ke pesanan\n");
        printf("2. Selesaikan pesanan\n");
        printf("0. Batalkan pesanan dan kembali ke menu utama\n");
        printf("Pilih opsi: ");
        
        if (scanf("%d", &pilihan) != 1) {
            printf("Input tidak valid. Harap masukkan angka.\n");
            while(getchar() != '\n');
            continue;
        }

        if (pilihan == 0) {
            printf("\nPesanan dibatalkan. Kembali ke menu utama...\n");
            return;
        }

        if (pilihan == 2) {
            if (strlen(detailPesanan) > 0) {
                break;
            } else {
                printf("\nBelum ada item yang dipesan. Silakan pilih menu terlebih dahulu.\n");
                continue;
            }
        }

        if (pilihan != 1) {
            printf("Pilihan tidak valid.\n");
            continue;
        }

        // Proses pemesanan item
        tampilkanMenu();
        printf("\nPilih nomor menu (0 untuk batal): ");
        if (scanf("%d", &pilihan) != 1) {
            printf("Input tidak valid. Harap masukkan angka.\n");
            while(getchar() != '\n');
            continue;
        }

        if (pilihan == 0) continue;

        struct MenuItem *temp = cariMenuByNomor(pilihan);
        if (temp == NULL) {
            printf("Nomor menu tidak valid. Coba lagi.\n");
            continue;
        }

        printf("Masukkan jumlah pesanan (0 untuk batal): ");
        if (scanf("%d", &kuantitas) != 1) {
            printf("Input tidak valid. Harap masukkan angka.\n");
            while(getchar() != '\n');
            continue;
        }

        if (kuantitas == 0) continue;

        if (kuantitas < 0) {
            printf("Jumlah pesanan tidak boleh negatif!\n");
            continue;
        }

        if (temp->stok < kuantitas) {
            printf("Stok tidak mencukupi. Stok tersedia: %d\n", temp->stok);
            continue;
        }

        // Konfirmasi pesanan
        printf("\nKonfirmasi pesanan:\n");
        printf("Menu: %s\n", temp->nama);
        printf("Jumlah: %d\n", kuantitas);
        printf("Harga satuan: Rp %d\n", temp->harga);
        printf("Total: Rp %d\n", temp->harga * kuantitas);
        printf("\nKonfirmasi? (y/n): ");
        getchar();
        scanf(" %c", &konfirmasi);

        if (konfirmasi == 'y' || konfirmasi == 'Y') {
            totalHarga += temp->harga * kuantitas;
            temp->stok -= kuantitas;

            char itemPesanan[100];
            snprintf(itemPesanan, sizeof(itemPesanan), "%dx %s, ", kuantitas, temp->nama);
            strncat(detailPesanan, itemPesanan, sizeof(detailPesanan) - strlen(detailPesanan) - 1);

            printf("\nMenu '%s' sebanyak %d berhasil ditambahkan ke pesanan.\n", temp->nama, kuantitas);
        }
    }

    // Finalisasi pesanan
    if (strlen(detailPesanan) > 0) {
        printf("\n=== Ringkasan Pesanan ===\n");
        printf("Nama Pelanggan: %s\n", namaPelanggan);
        printf("Detail Pesanan: %s\n", detailPesanan);
        printf("Total Harga: Rp %d\n", totalHarga);
        printf("\nKonfirmasi pesanan final? (y/n): ");
        getchar();
        scanf(" %c", &konfirmasi);

        if (konfirmasi == 'y' || konfirmasi == 'Y') {
            pushRiwayat(detailPesanan, totalHarga);
            enqueueAntrian(namaPelanggan, detailPesanan);
            printf("\nPesanan berhasil dibuat!\n");
        } else {
            printf("\nPesanan dibatalkan.\n");
        }
    }

    printf("\nTekan Enter untuk kembali ke menu utama...");
    getchar();
    getchar();
}

int main() {
    int pilihan;
    char nama[50];
    int harga, stok;

    do {
        printf("\n=== Sistem Penjualan Warmindo ===\n");
        printf("1. Tambah Menu\n");
        printf("2. Tambah Stok Menu\n");
        printf("3. Tampilkan Menu\n");
        printf("4. Buat Pesanan\n");
        printf("5. Tampilkan Riwayat Pesanan\n");
        printf("6. Tampilkan Antrian Pesanan\n");
        printf("7. Selesaikan Pesanan\n");
        printf("0. Keluar\n");
        printf("Pilih opsi: ");

        if (scanf("%d", &pilihan) != 1) { // Validasi input
            printf("Input tidak valid. Harap masukkan angka.\n");
            while(getchar() != '\n'); // Menghapus karakter sisa di buffer
            continue;
        }

        switch (pilihan) {
            case 1:
                printf("Masukkan Nama Menu: ");
                scanf(" %49[^\n]", nama);  // Perhatikan spasi sebelum %49
                printf("Masukkan Harga Menu: ");
                scanf("%d", &harga);
                printf("Masukkan Stok Menu: ");
                scanf("%d", &stok);
                tambahMenu(nama, harga, stok);
                break;

            case 2:
                printf("Masukkan Nama Menu untuk menambah stok: ");
                scanf(" %49[^\n]", nama);
                printf("Masukkan Jumlah Stok yang ingin ditambahkan: ");
                scanf("%d", &stok);
                tambahStokMenu(nama, stok);
                break;

            case 3:
                tampilkanMenu();
                break;

            case 4:
                buatPesanan();
                break;

            case 5:
                tampilkanRiwayat();
                break;

            case 6:
                tampilkanAntrian();
                break;

            case 7:
                dequeueAntrian();
                break;

            case 0:
                printf("Terima kasih! Sampai jumpa.\n");
                break;

            default:
                printf("Opsi tidak valid. Coba lagi.\n");
                break;
        }
    } while (pilihan != 0);

    return 0;
}