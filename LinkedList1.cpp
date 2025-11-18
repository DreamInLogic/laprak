#include <stdio.h>
#include <stdlib.h>

typedef struct TNode
{
	int data;
	TNode *next;
}TNode;

TNode *head;

void awal()
{
	head=NULL;
}

int IsEmpty()  //fungsi mengembalikan nilai
{
	return head==NULL;
}

void TambahDepan()
{
	TNode *baru = (TNode *)malloc(sizeof(TNode));
	printf ("Masukan Data LinkedList Depan : ");
	scanf ("%d", &baru->data);
	baru->next=NULL;
	
	if (IsEmpty()==1)
	{
		head = baru;
		head->next = NULL;
	}
	else
	{
		baru->next = head;
		head = baru;
	}
	printf ("Data Telah Dimasukan.....\n");
}

void TambahBelakang()
{
	TNode *bantu,*baru = (TNode *)malloc(sizeof(TNode));
	printf ("Masukan Data LinkedList Belakang : ");
	scanf ("%d", &baru->data);
	baru->next=NULL;
	
	if (IsEmpty()==1)
	{
		head = baru;
		head->next = NULL;
	}
	else
	{
		bantu=head;
		while(bantu->next!=NULL)
		{
			bantu=bantu->next;	
		}
		bantu->next=baru;
	}
	printf ("Data Telah Dimasukan.....\n");
}

void HapusDepan()
{
    TNode *hapus;
    int d;
    if (IsEmpty() == 0)
    {
        if (head->next != NULL)
        {
            hapus = head;
            d = hapus->data;
            head = head->next;
            free(hapus);
        }
        else // kalau hanya 1 node saja
        {
            d = head->data;
            free(head);
            head = NULL;
        }
        printf("%d Terhapus\n", d);
    }
    else
    {
        printf("Linked List Kosong\n");
    }
}


void HapusBelakang()
{
	TNode *hapus,*bantu;
	int d;
	if (IsEmpty()==0)
	{
		if (head->next!=NULL)
		{
			bantu=head;
			while(bantu->next->next!=NULL)
			{
				bantu=bantu->next;
			}
		hapus=bantu->next;
		d=hapus->data;
		bantu->next=NULL;
		free(hapus);
		}
		else
		{
			d=head->data;
			free(head);
			head=NULL;
		}
		printf ("%d Terhapus\n", d);
	}
	else
	{
		printf ("LinkedList Kosong\n");
	}
}

void Tampilkan()
{	
	TNode *bantu = head;
    int i = 1;
    if (IsEmpty()==1)   
	{
        printf("Linked List kosong!\n");
    }
	else
	{
        printf("\nIsi Linked List:\n");
        printf("----------------------\n");
        while (bantu != NULL)
		{
            printf("Data ke-%d : %d\n", i, bantu->data);
            bantu = bantu->next;
            i++;
        }
        printf("----------------------\n");
    }
}

void tungguEnter()
{
    char c;
    printf("\nTekan Enter untuk kembali ke menu...");
    while ((c = getchar()) != '\n' && c != EOF); // buang sisa input
    getchar(); // tunggu enter
}



main()
{
	char jwb,pilih;
	
	while (1)
	{
		mulai :	
		printf("\n============================================================ \n");
		printf("====================== LInked List ========================= \n");
		printf("======================= 250215030 ========================== \n");
		printf("============================================================ \n");
		printf("\n");
		printf("Menu \n");
		printf("1. Tambah Depan\n");
		printf("2. Tambah Belakang\n");
		printf("3. Hapus Depan\n");
		printf("4. Hapus Belakang\n");
		printf("5. Tampilkan\n");
		printf("6. Keluar\n");
		printf("\n");
		printf("Pilih Menu : ");
		scanf ("%s",&pilih);
		switch (pilih)
		{
			case'1':
				TambahDepan();
				tungguEnter();
				break;
			case'2':
				TambahBelakang();
				tungguEnter();
				break;
			case'3':
				HapusDepan();
				tungguEnter();
				break;
			case'4':
				HapusBelakang();
				tungguEnter();
				break;
			case'5':
				Tampilkan();
				tungguEnter();
				break;
			case'6':
			    printf("Program selesai. Terima kasih!\n");
			    exit(0);
			default:
                printf("\nPilihan tidak valid!\n");
				tungguEnter();				
		}
	}	

}
