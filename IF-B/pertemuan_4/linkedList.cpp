#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa
{
    std::string nim;
    std::string nama;
    double ipk;
    Mahasiswa *prev;
    Mahasiswa *next;
};

Mahasiswa *cariNim(Mahasiswa *head, std::string nim);
bool nimTersedia(Mahasiswa *head, std::string nim);
bool tambahMahasiswa(Mahasiswa *&head, Mahasiswa *&tail, string nama, string nim, double ipk);
bool hapusNim(Mahasiswa *&head, Mahasiswa *&tail, std::string nim);
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
    Mahasiswa *tail = nullptr;
    int pilihan;

    cout << tambahMahasiswa(head, tail, "taff", "12301", 2.3) << endl;
    cout << tambahMahasiswa(head, tail, "taff", "12310", 2.9) << endl;
    cout << tambahMahasiswa(head, tail, "taff", "12305", 2.7) << endl;
    cout << tambahMahasiswa(head, tail, "taff", "12307", 3.3) << endl;
    cout << (hapusNim(head, tail, "12305") ? "berhasil dihapus" : "gagal dihapus") << endl;
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

bool nimTersedia(Mahasiswa *head, std::string nim)
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

bool tambahMahasiswa(Mahasiswa *&head, Mahasiswa *&tail, string nama, string nim, double ipk)
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
    NodeBaru->prev = nullptr;

    // sisip depan ketika list Kosong/ initialisasi
    if (head == nullptr)
    {
        head = NodeBaru;
        tail = NodeBaru;
        return true;
    }
    else
    {
        Mahasiswa *temp = head;

        // sisip depan ketika list beranggota
        if (temp->nim > nim)
        {
            NodeBaru->next = temp;
            head->prev = NodeBaru;
            head = NodeBaru;
        }

        // sisip tengah/akhir lakukan traverse
        while (temp->next != nullptr && temp->next->nim < nim)
        {
            temp = temp->next;
        }

        // alternative condition (temp == tail)
        if (temp->next == nullptr)
        {
            // kondisi ketika sisip belakang
            temp->next = NodeBaru;
            NodeBaru->prev = temp;
            tail == NodeBaru;
        }
        else
        {
            // kondisi ketika sisip tengah
            temp->next->prev = NodeBaru;
            NodeBaru->next = temp->next;
            temp->next = NodeBaru;
            NodeBaru->prev = temp;
        }
        return true;
    }
    return true;
}

bool hapusNim(Mahasiswa *&head, Mahasiswa *&tail, std::string nim)
{
    if (head == nullptr)
    {
        return false;
    }
    Mahasiswa *currNode = head;
    
    while (currNode->nim != nim && currNode->next != nullptr){
        currNode = currNode->next;
    }

    if (currNode->nim != nim){
        return false;
    }
    else
    {
        if(currNode == head && currNode == tail){
            head = nullptr;
            tail = nullptr;
        }
        else if (currNode == head)
        {
            // hapus depan, head maju selangkah, hapus current
            head = currNode->next;
            head->prev = nullptr;
        }
        else if (currNode != head && currNode->next != nullptr)
        {
            // hapus tengah
            currNode->prev->next = currNode->next;
            currNode->next->prev = currNode->prev;
        }
        else
        {
            // hapus akhir
            tail = currNode->prev;
            tail->next = nullptr;
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