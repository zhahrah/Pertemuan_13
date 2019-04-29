#include <iostream>
#include <string>

using namespace std;

struct Siswa{   //membuat tipe data struct yang berfungsi menyimpan beberapa tipe data yang berbeda.
   int no_peserta;
   int NIS;
   char kelas;
   
   Siswa*next;   //Nama_struct*next.
};

void printList(Siswa*n)   //Membuat fungsi printList
{
 while(n!=NULL)   //syarat n tidak sama dengan NULL
 {
  
   cout<<"No Peserta : "<<n->no_peserta<<" "<<endl;;
   cout<<"NIS        :"<<n->NIS<<" "<<endl;
   cout<<"Kelas      :"<<n->kelas<<" "<<endl;
   cout<<" "<<endl;

     //n-.data adalah sebuah variabel yang akan dipanggil
  n=n->next;
 }
}

int main()
{
 Siswa*head = NULL;
 Siswa*second = NULL;
 Siswa*third = NULL;

 head = new Siswa();
 second = new Siswa();
 third = new Siswa();

 head->no_peserta = 01;
 head->NIS = 111;
 head->kelas = 'a';
 head->next = second;

 second->no_peserta = 02;
 second->NIS = 222;
 second->kelas = 'b';
 second->next = third;

 third->no_peserta = 03;
 third->NIS = 333;
 third->kelas = 'c';
 third->next = NULL;
 printList(head);

 cin.get();
 return 0;
}
