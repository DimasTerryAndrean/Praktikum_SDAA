#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MenuItem {
    char nama[50];
    int harga;
    int stok;
    struct MenuItem *next; // Pointer ke item berikutnya
};

// Head dari linked list
struct MenuItem *head = NULL;

// Fungsi untuk membuat item menu baru
struct MenuItem* createMenuItem(char *nama, int harga, int stok) {
    struct MenuItem *newItem = (struct MenuItem*)malloc(sizeof(struct MenuItem));
    strcpy(newItem->nama, nama);
    newItem->harga = harga;
    newItem->stok = stok;
    newItem->next = NULL;
    return newItem;
}

// Fungsi untuk menambahkan item menu ke linked list
void tambahMenu(char *nama, int harga, int stok) {
    struct MenuItem *newItem = createMenuItem(nama, harga, stok);
    if (head == NULL) {
        head = newItem; // Jika list kosong, set head ke item baru
    } else {
        struct MenuItem *temp = head;
        while (temp->next != NULL) { // Traverse ke akhir list
            temp = temp->next;
        }
        temp->next = newItem; // Tambahkan item baru di akhir
    }
    printf("Item '%s' berhasil ditambahkan ke menu!\n", nama);
}

// Fungsi untuk menampilkan item menu
void tampilkanMenu() {
    if (head == NULL) {
        printf("Menu kosong. Tambahkan item terlebih dahulu.\n");
        return;
    }
    printf("\n=== Daftar Menu ===\n");
    struct MenuItem *temp = head;
    int index = 1;
    while (temp != NULL) {
        printf("%d. %s - Harga: %d - Stok: %d\n", index++, temp->nama, temp->harga, temp->stok);
        temp = temp->next;
    }
}

// Fungsi untuk mengubah item menu
void ubahMenu(int index, char *namaBaru, int hargaBaru, int stokBaru) {
    struct MenuItem *temp = head;
    for (int i = 0; temp != NULL && i < index; i++) {
        temp = temp->next; // Traverse ke index
    }
    if (temp == NULL) {
        printf("Item menu tidak ditemukan.\n");
        return;
    }
    strcpy(temp->nama, namaBaru);
    temp->harga = hargaBaru;
    temp->stok = stokBaru;
    printf("Item menu berhasil diubah!\n");
}

// Fungsi untuk menghapus item menu
void hapusMenu(int index) {
    if (head == NULL) {
        printf("Menu kosong. Tidak ada item untuk dihapus.\n");
        return;
    }
    struct MenuItem *temp = head;
    struct MenuItem *prev = NULL;

    if (index == 0) {
        head = temp->next; // Ganti head ke item berikutnya
        free(temp); // Bebaskan memori dari head lama
        printf("Item menu berhasil dihapus!\n");
        return;
    }

    for (int i = 0; temp != NULL && i < index; i++) {
        prev = temp;
        temp = temp->next; // Traverse ke index
    }

    if (temp == NULL) {
        printf("Item menu tidak ditemukan.\n");
        return;
    }

    prev->next = temp->next; // Lepaskan node dari linked list
    free(temp); // Bebaskan memori
    printf("Item menu berhasil dihapus!\n");
}

// Fungsi untuk membuat pesanan
void buatPesanan() {
    int totalHarga = 0;
    int pilihan, kuantitas;

    tampilkanMenu();

    if (head == NULL) return;

    printf("Masukkan nomor item yang ingin dipesan (0 untuk selesai): ");
    while (1) {
        scanf("%d", &pilihan);
        if (pilihan == 0) break;

        struct MenuItem *temp = head;
        for (int i = 1; temp != NULL && i < pilihan; i++) {
            temp = temp->next; // Traverse ke item yang dipilih
        }

        if (temp == NULL) {
            printf("Nomor item tidak valid. Coba lagi.\n");
            continue;
        }

        printf("Masukkan kuantitas: ");
        scanf("%d", &kuantitas);

        if (temp->stok < kuantitas) {
            printf("Stok tidak mencukupi.\n");
            continue;
        }

        totalHarga += temp->harga * kuantitas;
        temp->stok -= kuantitas;

        printf("Item '%s' sebanyak %d berhasil ditambahkan ke pesanan.\n", temp->nama, kuantitas);
    }

    printf("Total harga pesanan: %d\n", totalHarga);
}

// Fungsi utama
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

    // Bebaskan memori yang dialokasikan
    struct MenuItem *current = head;
    struct MenuItem *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
