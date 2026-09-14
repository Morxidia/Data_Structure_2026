#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa
{
    std::string nim;
    std::string nama;
    double ipk;
    Mahasiswa *next;
};

bool nimTersedia(Mahasiswa *head, std::string nim);
bool tambahMahasiswa(Mahasiswa *&head,
                     string nama, string nim, double ipk);
Mahasiswa *cariNim(Mahasiswa *head, std::string nim);
bool hapusNim(Mahasiswa *&head, std::string nim);
void tampilkan(Mahasiswa *head);
int jumlahData(Mahasiswa *head);
void clear(Mahasiswa *&head);

void tampilkan(Mahasiswa *head)
{
    // Cek apakah linked list kosong
    if (head == nullptr)
    {
        cout << "Data mahasiswa kosong." << endl;
        return;
    }

    Mahasiswa *currNode = head;
    int nomor = 1;

    cout << "=== Daftar Mahasiswa ===" << endl;
    // Lakukan perulangan selama currNode belum mencapai akhir list (nullptr)
    while (currNode != nullptr)
    {
        cout << nomor << ". NIM  : " << currNode->nim << endl;
        cout << "   Nama : " << currNode->nama << endl;
        cout << "   IPK  : " << currNode->ipk << endl;
        cout << "------------------------" << endl;

        currNode = currNode->next; // Pindah ke node selanjutnya
        nomor++;
    }
}

int main()
{
    Mahasiswa *head = nullptr;
    int pilihan;

    cout << tambahMahasiswa(head, "taff", "12301", 2.3) << endl;
    cout << tambahMahasiswa(head, "taff", "12303", 2.3) << endl;
    cout << tambahMahasiswa(head, "taff", "12302", 2.3) << endl;
    cout << tambahMahasiswa(head, "taff", "12301", 2.3) << endl;
    cout << hapusNim(head, "12302") << endl;
    cout << "test" << endl;
    tampilkan(head);
    // clear(head);
    return 0;
}

Mahasiswa *cariNim(Mahasiswa *head, std::string nim)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    Mahasiswa *currNode = head;
    while (currNode->next != nullptr && currNode->nim != nim)
    {
        currNode = currNode->next;
    }
    if (currNode->next == nullptr && currNode->nim != nim)
    {
        return nullptr;
    }
    else if (currNode->nim == nim)
    {
        return currNode;
    }
    else
    {
        return nullptr;
    }
}

bool nimTersedia(Mahasiswa *head,
                 std::string nim)
{
    if (cariNim(head, nim) == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool tambahMahasiswa(Mahasiswa *&head,
                     string nama, string nim, double ipk)
{
    if (nimTersedia(head, nim) == false)
    {
        return false;
    }

    Mahasiswa *NodeBaru = new Mahasiswa;
    NodeBaru->nama = nama;
    NodeBaru->nim = nim;
    NodeBaru->ipk = ipk;
    NodeBaru->next = nullptr;

    if (head == nullptr)
    {
        head = NodeBaru;
        return true;
    }
    else
    {
        Mahasiswa *temp = head;
        if (temp->nim > nim)
        {
            NodeBaru->next = temp;
            head = NodeBaru;
        }
        while (temp->next != nullptr && temp->nim < nim)
        {
            temp = temp->next;
        }
        if (temp != head && temp->next != nullptr)
        {
            Mahasiswa *belakang = temp->next;
            temp->next = NodeBaru;
            NodeBaru->next = belakang;
        }
        else if (temp->next == nullptr)
        {
            temp->next = NodeBaru;
            NodeBaru->next = nullptr;
        }
        return true;
    }
    return true;
}

bool hapusNim(Mahasiswa *&head, std::string nim)
{
    if (head == nullptr)
    {
        return false;
    }
    Mahasiswa *currNode = head;
    Mahasiswa *sebelum = nullptr;
    while (currNode->nim != nim && currNode->next != nullptr)
    {
        sebelum = currNode;
        currNode = currNode->next;
    }

    if (currNode->next == nullptr && currNode->nim != nim)
    {
        return false;
    }
    else if (currNode->nim == nim)
    {
        if (currNode == head)
        {
            head = currNode->next;
            currNode->next = nullptr;
        }
        else if (currNode != head && currNode->next != nullptr)
        {
            Mahasiswa *sesudah = currNode->next;
            sebelum->next = sesudah;
            currNode->next = nullptr;
        }
        else
        {
            sebelum->next = nullptr;
            currNode->next = nullptr;
        }
        delete currNode;
        return true;
    }
    return false;
}

void clear(Mahasiswa *&head)
{
    Mahasiswa *currNode = head;
    while (currNode != nullptr)
    {
        Mahasiswa *nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
    head = nullptr;
}