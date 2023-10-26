#include <windows.h>
#include <iostream>
using namespace std;

#define MAX 10

int antrian [MAX];
int rear = -1;

//cek apakah antrian penuh....................
bool isFull()
{
    return rear == MAX-1;
}

//cek apakah antrian kosong......................
bool isEmpty ()
{
    return rear == -1;
}

//manambahkan data ke antrian....................
void enqueue (){
    if(isFull())
    {
        cout <<"\nAntrian penuh ! ";
        //getch ();
    }
    else
    {
        int xantrian;
        cout << "\nMasukan antrian :" ;cin >> xantrian;

        rear++;
        antrian[rear] = xantrian;
    }
}

//mengambil data dari antrian................
void dequeue (){
    if (isEmpty ())
    {
        cout << "\nAntrian masih kosong !";
    }
    else
    {
        cout <<"\nMengambil antrian \"" << antrian [0] << "\"";
        cout << endl;

        //menggeser data antrian.............................
        for (int i = 0; i < rear; i++)
            antrian [i] = antrian[i + 1];

        antrian [rear] = 0;
        rear--;
    }
}
//Menampilkan Queue..............................................
void printQueue () {
    if (isEmpty())
    {
        cout << "\nAntrian kosong !";
    }
    else {
        cout <<"\n\nkondisi Antrian : \n\n";
        cout <<"masuk=> !";
        for (int i = MAX-1; i >= 0; i--)
        {
            if (antrian[i] == 0)
                cout << " | ";
            else
            cout <<antrian [i] << " | ";
        }
        cout << " => keluar " ;
        cout << "\n\nEnter kembali ke Menu" ;
    }
    //getch();
}
//program utama................................................
int main()
{
    int pilih;
    do
    {
        //Tampilan menu.......................................
        //system("cls");
        cout<< "\n\n";
        cout<< "------------------------------------------\n";
        cout<< "Menu Pilihan\n";
        cout<< "-----------------------------------------\n";
        cout<< " [1] Enqueue / Tambah Antrian \n";
        cout<< " [2] Dequeue / Hapus antrian \n";
        cout<< " [3] PrintDequeue / cetak antrian \n";
        cout<< " [4] Keluar \n\n";
        cout<< "----------------------------------------\n";
        cout<< "Masuk Pilihan : "; cin >> pilih;
        switch (pilih)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printQueue();
                break;
            default:
                cout <<"Pilihan tidak tersedia ! ";
                break;
        }
    } while(pilih != 4);
    return 0;
}
