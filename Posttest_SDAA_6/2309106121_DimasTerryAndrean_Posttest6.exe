#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menu item dengan kategori dan deskripsi
struct MenuItem {
    char nama[50];
    int harga;
    int stok;
    char kategori[30];     // Kategori menu (contoh: "Makanan", "Minuman")
    char deskripsi[100];   // Deskripsi singkat menu
    struct MenuItem *next;
};

// Fungsi untuk membuat menu item baru dengan kategori dan deskripsi
struct MenuItem* createMenuItem(const char *nama, int harga, int stok, const char *kategori, const char *deskripsi) {
    struct MenuItem *newItem = (struct MenuItem*)malloc(sizeof(struct MenuItem));
    strcpy(newItem->nama, nama);
    newItem->harga = harga;
    newItem->stok = stok;
    strcpy(newItem->kategori, kategori);
    strcpy(newItem->deskripsi, deskripsi);
    newItem->next = NULL;
    return newItem;
}

// Fungsi untuk menambahkan menu item ke dalam list
void tambahMenuItem(struct MenuItem **head, const char *nama, int harga, int stok, const char *kategori, const char *deskripsi) {
    struct MenuItem *newItem = createMenuItem(nama, harga, stok, kategori, deskripsi);
    if (*head == NULL) {
        *head = newItem;
    } else {
        struct MenuItem *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newItem;
    }
}

// Fungsi untuk menampilkan semua item menu beserta kategori dan deskripsi
void tampilkanMenu(struct MenuItem *head) {
    struct MenuItem *temp = head;
    printf("Daftar Menu di Warmindo :\n");
    printf("------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-8s | %-15s |\n", "Nama", "Harga", "Stok", "Kategori");
    printf("------------------------------------------------------\n");
    while (temp != NULL) {
        printf("| %-20s | %-10d | %-8d | %-15s |\n", temp->nama, temp->harga, temp->stok, temp->kategori);
        printf("  Deskripsi: %s\n", temp->deskripsi);
        printf("------------------------------------------------------\n");
        temp = temp->next;
    }
}

// Fungsi untuk menghapus semua elemen menu dari list
void hapusSemuaMenu(struct MenuItem **head) {
    struct MenuItem *temp = *head;
    struct MenuItem *next;
    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

// Program utama
int main() {
    struct MenuItem *head = NULL;

    // Tambahkan beberapa item menu dengan kategori dan deskripsi
    tambahMenuItem(&head, "Indomie Goreng", 12000, 10, "Makanan", "Indomie goreng dengan topping telur");
    tambahMenuItem(&head, "Nasi Goreng", 15000, 5, "Makanan", "Nasi goreng spesial dengan ayam suwir");
    tambahMenuItem(&head, "Es Teh", 5000, 20, "Minuman", "Es teh manis segar");
    tambahMenuItem(&head, "Jus Alpukat", 15000, 8, "Minuman", "Jus alpukat dengan susu coklat");

    // Tampilkan menu yang sudah ditambahkan
    tampilkanMenu(head);

    // Hapus semua menu saat program berakhir
    hapusSemuaMenu(&head);

    return 0;
}
