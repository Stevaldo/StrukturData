#include <iostream>

using namespace std;

// Record Definition
struct TheCell
{
  int dat;
  struct TheCell *berikut;
};

struct TheCell *isiCell(int dat, struct TheCell *cellNext, struct TheCell *kepala)
{
  struct TheCell *cellBaru;
  if (kepala == NULL)
  {
    // Mengisi Linked List dari keadaan kosong
    cellNext = (struct TheCell *)malloc(sizeof(struct TheCell));
    cellNext->dat = dat;
    // Tentukan Link selanjutnya pada simpul/node baru di tentukan sebagai NULL
    cellNext->berikut = NULL;
    return (cellNext);
  }
  else
  {
    if (cellNext == NULL)
    {
      // mengisi node pada kepala
      cellNext = (struct TheCell *)malloc(sizeof(struct TheCell));
      cellNext->dat = dat;

      // Tentukan Link selanjutnya ke kepala
      cellNext->berikut = kepala;
      return (cellNext);
    }
    else
    {
      if (cellNext->berikut != NULL)
      {
        // Buat sebuah node baru
        cellBaru = (struct TheCell *)malloc(sizeof(struct TheCell));

        // Isi Data
        cellBaru->dat = dat;

        // Menyisipkan node pada Linked List
        // linked berikut dari cell baru di arahkan ke node /simpul dari node yang akan di geser
        cellBaru->berikut = cellNext->berikut;

        // linked berikut dari cell yang di depannya di arahkan ke alamat dari cell baru
        cellNext->berikut = cellBaru;
        return (cellBaru);
      }
      else
      {
        // Mengisi pada Linked List yang sudah terbentuk
        cellNext->berikut = (struct TheCell *)malloc(sizeof(struct TheCell));
        cellNext = cellNext->berikut;

        // Isi Data
        cellNext->dat = dat;

        // Tentukan Link selanjutnya pada simpul/node baru di tentukan sebagai NULL
        cellNext->berikut = NULL;
        return (cellNext);
      }
    }
  }
}

// program utama
int main()
{
  int i;
  int nodeke;
  int ambilData;
  struct TheCell *kepala = NULL;
  struct TheCell *ptrCell = NULL;

  for (i = 1; i <= 10; i++)
  {
    if (kepala == NULL)
    {
      // Mengisi Linked List dari keadaan kosong
      kepala = isiCell(i * 10, NULL, NULL);
      ptrCell = kepala;
    }
    else
    {
      // Mengisi pada Linked List yang sudah terbentuk
      ptrCell = isiCell(i * 10, ptrCell, kepala);
    }
  }
  // Menampilkan Isi Linked List dari awal
  if (kepala != NULL) // Memastikan Linked List tidak kosong, yg ditandai dengan kepala != NULL
  {
    cout << "cell: {Alamat} [ Data | Cell berikut]" << endl;
    // Arahkan ptrCell ke alamat yang ditunjuk oleh kepala
    ptrCell = kepala;
    do
    {
      // Tampilkan isi Node / Simpul
      cout << "cell: {" << ptrCell << "} [" << ptrCell->dat << " | " << ptrCell->berikut << "]" << endl;

      // Arahkan ptrCell ke Node/Simpul berikutnya
      ptrCell = ptrCell->berikut;

    } while (ptrCell != NULL); // keluar dari loop ketika ptrCell menunjukkan alamat NULL
    cout << endl
         << endl;
  }

  cout << "data: ";
  cin >> ambilData;
  cout << endl;

  cout << "Sisipkan data setelah node ke: ";
  cin >> nodeke;
  cout << endl;

  if (nodeke > 0)
  {
    ptrCell = kepala;
    for (i = 1; i < nodeke; i++)
    {
      ptrCell = ptrCell->berikut;
    }
    ptrCell = isiCell(ambilData, ptrCell, kepala);
  }
  else
  {
    // ptrCell = NULL;
    kepala = isiCell(ambilData, NULL, kepala);
  }

  // Menampilkan Isi Linked List dari awal
  if (kepala != NULL) // Memastikan Linked List tidak kosong, yg ditandai dengan kepala != NULL
  {
    cout << "cell: {Alamat} [ Data | Cell berikut]" << endl;
    // Arahkan ptrCell ke alamat yang ditunjuk oleh kepala
    ptrCell = kepala;
    do
    {
      // Tampilkan isi Node / Simpul
      cout << "cell: {" << ptrCell << "} [" << ptrCell->dat << " | " << ptrCell->berikut << "]" << endl;

      // Arahkan ptrCell ke Node/Simpul berikutnya
      ptrCell = ptrCell->berikut;

    } while (ptrCell != NULL); // keluar dari loop ketika ptrCell menunjukkan alamat NULL

    cout << endl
         << endl;
  }

  return 0;
}