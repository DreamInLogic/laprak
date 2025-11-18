#include <stdio.h>
#include <stdlib.h>

// Struktur Node
typedef struct TNode {
    int data;
    struct TNode *next;
} TNode;

TNode *head;

// Inisialisasi Linked List
void awal() {
    head = NULL;
}

// Mengecek apakah kosong
int IsEmpty() {
    return head == NULL;
}

// Tambah Depan
void TambahDepan() {
    TNode *baru = (TNode *)malloc(sizeof(TNode));
    printf("Masukan Data LinkedList Depan : ");
    scanf("%d", &baru->data);
    baru->next = head;
    head = baru;
    printf("Data %d berhasil ditambahkan di depan.\n", baru->data);
}

// Tambah Belakang
void TambahBelakang() {
    TNode *baru = (TNode *)malloc(sizeof(TNode));
    printf("Masukan Data LinkedList Belakang : ");
    scanf("%d", &baru->data);
    baru->next = NULL;

    if (IsEmpty()) {
        head = baru;
    } else {
        TNode *bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
    printf("Data %d berhasil ditambahkan di belakang.\n", baru->data);
}

// Hapus Depan
void HapusDepan() {
    if (IsEmpty()) {
        printf("Linked List kosong!\n");
    } else {
        TNode *hapus = head;
        int d = hapus->data;
        head = head->next;
        free(hapus);
        printf("Data %d terhapus dari depan.\n", d);
    }
}

// Hapus Belakang
void HapusBelakang() {
    if (IsEmpty()) {
        printf("Linked List kosong!\n");
    } else if (head->next == NULL) {
        int d = head->data;
        free(head);
        head = NULL;
        printf("Data %d terhapus dari belakang.\n", d);
    } else {
        TNode *bantu = head;
        while (bantu->next->next != NULL) {
            bantu = bantu->next;
        }
        int d = bantu->next->data;
        free(bantu->next);
        bantu->next = NULL;
        printf("Data %d terhapus dari belakang.\n", d);
    }
}

// Tampilkan
void Tampilkan() {
    if (IsEmpty()) {
        printf("Linked List kosong!\n");
    } else {
        TNode *bantu = head;
        printf("Isi Linked List: ");
        while (bantu != NULL) {
            printf("%d ", bantu->data);
            bantu = bantu->next;
        }
        printf("\n");
    }
}

int main() {
    char pilih;
    awal();

    while (1) {
        printf("\n============================================================\n");
        printf("====================== Linked List =========================\n");
        printf("======================= 250215030 ==========================\n");
        printf("============================================================\n");
        printf("\nMenu:\n");
        printf("1. Tambah Depan\n");
        printf("2. Tambah Belakang\n");
        printf("3. Hapus Depan\n");
        printf("4. Hapus Belakang\n");
        printf("5. Tampilkan\n");
        printf("6. Keluar\n");
        printf("\nPilih Menu : ");
        scanf(" %c", &pilih);
        getchar(); // membersihkan buffer

        switch (pilih) {
            case '1':
                TambahDepan();
                break;
            case '2':
                TambahBelakang();
                break;
            case '3':
                HapusDepan();
                break;
            case '4':
                HapusBelakang();
                break;
            case '5':
                Tampilkan();
                break;
            case '6':
                printf("Program selesai. Terima kasih!\n");
                exit(0);
            default:
                printf("Pilihan tidak valid!\n");
        }

        printf("\nTekan ENTER untuk kembali ke menu...");
        getchar();
    }

    return 0;
}

