#include <iostream>
#include <iomanip>

//2311102034_Rizal Dwi Anggoro_IF-11-A

using namespace std;

struct mahasiswa
{
    string nama;
    string nim;
};

struct node
{
    mahasiswa identitas;
    node *next;
};
node *head, *tail, *bantu, *hapus, *before, *baru;

void init()
{
    head = NULL;
    tail = NULL;
    bantu = NULL;
    hapus = NULL;
    before = NULL;
}

bool isEmpty()

{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

mahasiswa mintaData()

{
    system("cls");
    mahasiswa identitas;
    cout << "\nMasukkan Nama\t: ";
    cin.ignore();
    getline(cin, identitas.nama);
    cout << "Masukkan NIM\t: ";
    cin >> identitas.nim;
    return identitas;
}

void insertDepan(mahasiswa identitas)

{
    node *baru = new node;
    baru->identitas.nama = identitas.nama;
    baru->identitas.nim = identitas.nim;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
    cout << "Data " << identitas.nama << " berhasil diinput!\n";
    system("pause");
}

void insertBelakang(mahasiswa identitas)

{
    node *baru = new node;
    baru->identitas.nama = identitas.nama;
    baru->identitas.nim = identitas.nim;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

int hitungList()

{
    int penghitung = 0;
    node *bantu;
    bantu = head;
    while (bantu != NULL)
    {
        penghitung++;
        bantu = bantu->next;
    }
    return penghitung;
}

void insertTengah(mahasiswa identitastitas, int posisi)

{
    node *baru = new node;
    baru->identitas.nama = identitastitas.nama;
    baru->identitas.nim = identitastitas.nim;
    node *bantu;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "posisi diluar jangakauan";
    }
    else if (posisi == 1)
    {
        cout << "INi bukan posisi tengah\n";
    }
    else
    {
        bantu = head;
        int penghitung = 1;
        while (penghitung != posisi - 1)
        {
            penghitung++;
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void ubahDepan(mahasiswa data)

{
    string namaLama = head->identitas.nama;
    head->identitas.nama = data.nama;
    head->identitas.nim = data.nim;

    cout << "data " << namaLama << " telah diganti dengan data "
         << data.nama << endl;
}

void ubahBelakang(mahasiswa data)

{
    string namaLama = tail->identitas.nama;
    tail->identitas.nama = data.nama;
    tail->identitas.nim = data.nim;
    cout << "data " << namaLama << " telah diganti dengan data "
         << data.nama << endl;
}

void ubahTengah(mahasiswa data)

{
    int posisi;
    cout << "\nMasukkan posisi data yang akan diubah : ";
    cin >> posisi;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "\nPosisi diluar jangkauan\n";
    }
    else if (posisi == 1)
    {
        cout << "\nBukan posisi tengah\n";
    }
    else
    {
        bantu = head;
        int penghitung = 1;
        while (penghitung != posisi)
        {
            penghitung++;
            bantu = bantu->next;
        }
        bantu->identitas.nama = data.nama;
        bantu->identitas.nim = data.nim;
    }
}

void tampil()

{
    system("cls");
    node *bantu = head;
    cout << "Nama "
         << " Nim\n";
    while (bantu != NULL)
    {
        cout << bantu->identitas.nama << " " << bantu->identitas.nim << endl;
        bantu = bantu->next;
    }
}

void hapusDepan()

{
    string dataLama = head->identitas.nama;
    hapus = head;
    if (head != tail)
    {
        head = head->next;
        delete hapus;
    }
    else
    {
        head = tail = NULL;
    }
    cout << "Data " << dataLama << " berhasil dihapus\n";
}

void hapusBelakang()

{
    string dataLama = head->identitas.nama;
    if (head != tail)
    {
        hapus = tail;
        bantu = head;
        while (bantu->next != tail)
        {
            bantu = bantu->next;
        }
        tail = bantu;
        tail->next = NULL;
        delete hapus;
    }
    else
    {
        head = tail = NULL;
    }
    cout << "Data " << dataLama << " berhasil dihapus\n";
}

void hapusTengah()

{
    tampil();
    cout << endl;
    if (isEmpty() == false)
    {
    back:
        int posisi;
        cout << "Masukkan Posisi yang dihapus : ";
        cin >> posisi;
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "\nPosisi di luar jangkauan!\n";
            system("pause");
            system("cls");
            cout << "Masukkan posisi baru\n";
            goto back;
        }
        else if (posisi == 1 || posisi == hitungList())
        {
            cout << "\nBukan Posisi tengah\n";
            system("pause");
            // system("cls");
            cout << "Masukkan posisi baru\n";
            goto back;
        }
        else
        {
            bantu = head;
            int penghitung = 1;

            while (penghitung <= posisi)
            {
                if (penghitung == posisi - 1)
                {
                    before = bantu;
                }
                if (penghitung == posisi)
                {
                    hapus = bantu;
                }
                bantu = bantu->next;
                penghitung++;
            }
            string dataLama = hapus->identitas.nama;
            before->next = bantu;
            delete hapus;

            cout << "\nData " << dataLama << " berhasil dihapus !\n ";
            system("pause");
        }
    }
    else
    {
        cout << "\n!!! List Data Kosong !!!\n";
        system("pause");
    }
}

void hapusList()

{
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        delete hapus;
        bantu = bantu->next;
    }
    init();
    cout << "\nsemua data berhasil dihapus\n";
}

int main()

{
    init();
    mahasiswa identitas;
    int operasi, posisi;

    do
    {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR\n\n";
        cout << "1.Tambah Depan" << endl;
        cout << "2.Tambah Belakang" << endl;
        cout << "3.Tambah Tengah" << endl;
        cout << "4.Ubah Depan" << endl;
        cout << "5.Ubah Belakang" << endl;
        cout << "6.Ubah Tengah" << endl;
        cout << "7.hapus depan" << endl;
        cout << "8.hapus belakang" << endl;
        cout << "9.hapus Tengah" << endl;
        cout << "10.hapus list" << endl;
        cout << "11.Tampilkan" << endl;
        cout << "0.Exit" << endl;
        cout << "\nPilih Operasi : ";
        cin >> operasi;

        switch (operasi)
        {
        case 1:
            cout << "tambah depan\n";
            insertDepan(mintaData());
            cout << endl;
            break;
        case 2:
            cout << "tambah belakang\n";
            insertBelakang(mintaData());
            cout << endl;
            break;
        case 3:
            cout << "tambah tengah\n";
            cout << "nama : ";
            cin >> identitas.nama;
            cout << "NIM : ";
            cin >> identitas.nim;
            cout << "Posisi: ";
            cin >> posisi;

            insertTengah(identitas, posisi);
            cout << endl;
            break;
        case 4:
            cout << "ubah depan\n";
            ubahDepan(mintaData());
            cout << endl;
            break;
        case 5:
            cout << "ubah belakang\n";
            ubahBelakang(mintaData());
            cout << endl;
            break;
        case 6:
            cout << "ubah tengah\n";
            ubahTengah(mintaData());
            cout << endl;
            break;
        case 7:
            cout << "hapus depan\n";
            hapusDepan();
            cout << endl;
            break;
        case 8:
            cout << "hapus belakang\n";
            hapusBelakang();
            cout << endl;
            break;
        case 9:
            cout << "hapus tengah\n";
            hapusTengah();
            cout << endl;
            break;
        case 10:
            cout << "hapus list\n";
            hapusList();
            cout << endl;
            break;
        case 11:
            tampil();
            cout << endl;
            break;
        case 0:
            cout << "\nEXIT PROGRAM\n";
            break;
        default:
            cout << "\nSalah input operasi\n";
            cout << endl;
            break;
        }
    } while (operasi != 0);

    return 0;
}
