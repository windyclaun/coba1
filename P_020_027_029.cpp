#include <iostream>
#include <iomanip>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
using namespace std;

struct daftarMengajar{
    string nama;
    int nip;
    string mka;
    int jam;
};

char kembali;
//string replaceSpasi(string str);
//string replaceUnderscore(string str);
void inputData(daftarMengajar data_mengajar[1000]);
void outputData(daftarMengajar data_mengajar[1000]);
void cariData(daftarMengajar data_mengajar[1000]);
void sortingData(daftarMengajar data_mengajar[1000]);
void manipulasiData(daftarMengajar data_mengajar[1000]);
void sequentialSearch(daftarMengajar data_mengajar[1000], string file);
void binarySearch(daftarMengajar data_mengajar[1000], string file);
void bubbleSort(daftarMengajar data_mengajar[1000], string file);
void selectionSort(daftarMengajar data_mengajar[1000], string file);
void insertionSort(daftarMengajar data_mengajar[1000], string file);
void shellSort(daftarMengajar data_mengajar[1000], string file);
void mergeSambung(daftarMengajar data_mengajar[1000], string file);
void updatingData(daftarMengajar data_mengajar[1000], string file);
void splitingData(daftarMengajar data_mengajar[1000], string file);

int main()
{
    daftarMengajar pengajar[100], tempPengajar[100];
    string menuAwal;
    int pilihMenuAwal;

    do
    {
        system("cls");
		cout << " +===============================+ " << endl;
        cout << " |     PROGRAM DATA MENGAJAR     | " << endl;
        cout << " +===============================+ " << endl;
        cout << " | 1. Input Data                 | " << endl;
        cout << " | 2. Output Data                | " << endl;
        cout << " | 3. Searching Data             | " << endl;
        cout << " | 4. Sorting Data               | " << endl;
        cout << " | 5. Manipulasi Data            | " << endl;
        cout << " | 6. Exit                       | " << endl;
        cout << " +===============================+ " << endl;
        cout << "Pilih Menu: ";
        cin >> pilihMenuAwal;
        system("cls");

        if (pilihMenuAwal == 1)
        {
            inputData(pengajar);
            cout << "\nKembali ke Menu Awal? (y/n) ";
            cin >> menuAwal;
            system("cls");
        }
        else if (pilihMenuAwal == 2)
        {
            outputData(tempPengajar);
            cout << "\nKembali ke Menu Awal? (y/n) ";
            cin >> menuAwal;
            system("cls");
        }
        else if (pilihMenuAwal == 3)
        {
            cariData(pengajar);
            menuAwal = "y";
        }
        else if (pilihMenuAwal == 4)
        {
            sortingData(pengajar);
            menuAwal = "y";
        }
        else if (pilihMenuAwal == 5)
        {
            manipulasiData(pengajar);
            menuAwal = "y";
        }
        else if (pilihMenuAwal == 6)
        {
            cout << "Terima kasih telah menggunakan program ini" << endl;
            return 0;
        }
        else
        {
            cout << "Pilihan tidak ada" << endl;
            cout << "\nKembali ke Menu Awal? (y/n) ";
            cin >> menuAwal;
            system("cls");
        }

    } while (menuAwal == "y");
}

/*string replaceSpasi(string str)
{
    for (int i = 0; i < str.length(); i++) // Melakukan iterasi melalui setiap karakter dalam string 'str'
    {
        if (str[i] == ' ')
        {
            str[i] = '_';
        }
    }
    return str;
}
string replaceUnderscore(string str)
{
    for (int i = 0; i < str.length(); i++) // Melakukan iterasi melalui setiap karakter dalam string 'str'
    {
        if (str[i] == '_')
        {
            str[i] = ' ';
        }
    }
    return str;
}*/
void inputData(daftarMengajar data_mengajar[1000])
{
    string namaFile;
    int banyakData = 0;

    cout << "+==================+" << endl;
    cout << "| INPUT DATA DOSEN |" << endl;
    cout << "+==================+" << endl;
    cout << "Masukkan Nama File : ";
    cin >> namaFile;
    cout << "Banyaknya Data\t: ";
    cin >> banyakData;

    for (int i = 0; i < banyakData; i++)
    {
		cout << "----------------------------" << endl;
		cout << "DATA DOSEN KE-" << i+1 << endl;
		cout << "----------------------------" << endl;
        cout << "\t NIP\t\t: ";
        cin >> data_mengajar[i].nip;
        cin.ignore();
        cout << "\t Nama Dosen\t: ";
        getline(cin, data_mengajar[i].nama);
        cout << "\t MKA\t\t: ";
        getline(cin, data_mengajar[i].mka);
        cout << "\t Jam\t\t: ";
        cin >> data_mengajar[i].jam;
        cout << endl;
    }
    for (int i = 0; i < banyakData; i++)
        data_mengajar[i].nama = data_mengajar[i].nama;

    ofstream ofs(namaFile + ".txt", ios::app);
    if (ofs.is_open())
    {
        for (int i = 0; i < banyakData; i++)
        {
            ofs << data_mengajar[i].nip << "\n"
                << data_mengajar[i].nama << "\n"
                << data_mengajar[i].mka << "\n"
                << data_mengajar[i].jam << "\n\n";
        }
        ofs.close();
    }
}
void outputData(daftarMengajar data_mengajar[1000])
{
    int i = 0;
    int jumlahData = 0;
    string namaFile, kosong[1000];
    cout << " +===================+ " << endl;
    cout << " | OUTPUT DATA DOSEN | " << endl;
    cout << " +===================+ " << endl;
    cout << " Masukkan Nama File : ";
    cin >> namaFile;
    ifstream ifs(namaFile + ".txt");
    if (ifs.is_open()){
		while (!ifs.eof())
		{
			ifs >> data_mengajar[i].nip;
			ifs.ignore();
			getline(ifs, data_mengajar[i].nama);
			getline(ifs, data_mengajar[i].mka);
			ifs >> data_mengajar[i].jam;
			getline(ifs, kosong[i]);
			i++;
		}
	}
	else {
		cout << "\n-----------------------" << endl;
		cout << "File Tidak Ditemukan" << endl;
		cout << "-----------------------" << endl;
		//system("pause");
		return;
	}
    ifs.close();

    jumlahData += i - 1;
    cout << "+" <<setfill('-') << setw(80) << "-" << "+" << endl;
    cout << left << "|" << setfill(' ') << setw(16) << " NIP"
         << "|" << setfill(' ') << setw(23);
    cout << " Nama Dosen"
         << "|" << setfill(' ') << setw(19) << " MKA"
         << "|" << setfill(' ') << setw(19);
    cout << " Jam"
         << "|" << endl;
    cout << "+" <<setfill('-') << setw(80) << "-" << "+" << endl;
    for (int i = 0; i < jumlahData; i++){
        cout << "| " << setfill(' ') << setw(15) << data_mengajar[i].nip << "| " << setfill(' ') << setw(22) << data_mengajar[i].nama;
        cout << "| " << setfill(' ') << setw(18) << data_mengajar[i].mka << "| " << setfill(' ') << setw(18) << data_mengajar[i].jam;
        cout << "| " << endl;
    }
    cout << "+" <<setfill('-') << setw(80) << "-" << "+" << endl;
}

void cariData(daftarMengajar data_mengajar[1000]){
    string menuBalik, namaFile, menuSearching2;
    int menuSearching;
    do
    {
        system("cls");
        cout << " +========================+ " << endl;
        cout << " |  MENU CARI DATA DOSEN  | " << endl;
        cout << " +========================+ " << endl;
        cout << " | 1. Sequential          | " << endl;
        cout << " | 2. Binary              | " << endl;
        cout << " | 3. Back to menu        | " << endl;
        cout << " +========================+ " << endl;
        cout << "Pilih Menu: ";
        cin >> menuSearching;
        system("cls");
        if (menuSearching == 1)
        {
            system("cls");
            cout << "Sequential Search\n";
            cout << "Masukkan Nama File : ";
            cin >> namaFile;
            ifstream ifs(namaFile + ".txt");
            if (ifs.is_open())
            {
                ifs.close();
                sequentialSearch(data_mengajar, namaFile);
                menuSearching2 = "y";
            }
            else
            {
                cout << "\n-----------------------" << endl;
                cout << "File Tidak Ditemukan" << endl;
                cout << "-----------------------" << endl;
                cout << "\nKembali ke Menu Searching? (y/n) ";
                cin >> menuSearching2;
            }
        }
        else if (menuSearching == 2)
        {
            system("cls");
            cout << "Binary Search\n";
            cout << "Masukkan Nama File : ";
            cin >> namaFile;
            ifstream ifs(namaFile + ".txt");
            if (ifs.is_open())
            {
                ifs.close();
                binarySearch(data_mengajar, namaFile);
                menuSearching2 = "y";
            }
            else
            {
                cout << "\n-----------------------" << endl;
                cout << "File Tidak Ditemukan" << endl;
                cout << "-----------------------" << endl;
                cout << "\nKembali ke Menu Searching? (y/n) ";
                cin >> menuSearching2;
            }
        }
        else if (menuSearching == 3) break;
        else
        {
            cout << "Pilihan tidak ada" << endl;
        }


    }while(menuSearching2 == "y");
}

void sortingData(daftarMengajar data_mengajar[1000]){
    string menuBalik, namaFile;
    int menuSorting;
    do
            {
                system("cls");
                cout << " +==============================+ " << endl;
                cout << " |  MENU PENGURUTAN DATA DOSEN  | " << endl;
                cout << " +==============================+ " << endl;
                cout << " | 1. Bubble Sort               | " << endl;
                cout << " | 2. Selection Sort            | " << endl;
                cout << " | 3. Insertion Sort            | " << endl;
                cout << " | 4. Shell Sort                | " << endl;
                cout << " | 5. Back to Menu              | " << endl;
                cout << " +==============================+ " << endl;
                cout << "Pilih Menu : ";
                cin >> menuSorting;
                if (menuSorting == 1)
                {
                    do
                    {
                        system("cls");
                        cout << "Masukkan Nama File : ";
                        cin >> namaFile;
                        ifstream ifs(namaFile + ".txt");
                        if (ifs.is_open())
                        {
                            bubbleSort(data_mengajar, namaFile);
                        }
                        else
                        {
                            cout << "\n-----------------------" << endl;
							cout << "File Tidak Ditemukan" << endl;
							cout << "-----------------------" << endl;
							//system("pause");
							//return;
                        }

                        cout << "Ulangi Pengurutan? (y/n) ";
                        cin >> menuBalik;
                    } while (menuBalik == "y");
                }
                else if (menuSorting == 2)
                {
                    do
                    {
                        system("cls");
                        cout << "Masukkan Nama File : ";
                        cin >> namaFile;
                        ifstream ifs(namaFile + ".txt");
                        if (ifs.is_open())
                        {
                            selectionSort(data_mengajar, namaFile);
                        }
                        else
                        {
                            cout << "\n-----------------------" << endl;
							cout << "File Tidak Ditemukan" << endl;
							cout << "-----------------------" << endl;
							//system("pause");
							//return;
                        }

                        cout << "Ulangi Pengurutan? (y/n) ";
                        cin >> menuBalik;
                    } while (menuBalik == "y");
                }
                else if (menuSorting == 3)
                {
                    do
                    {
                        system("cls");
                        cout << "Masukkan Nama File : ";
                        cin >> namaFile;
                        ifstream ifs(namaFile + ".txt");
                        if (ifs.is_open())
                        {
                            insertionSort(data_mengajar, namaFile);
                        }
                        else
                        {
                            cout << "\n-----------------------" << endl;
							cout << "File Tidak Ditemukan" << endl;
							cout << "-----------------------" << endl;
							//system("pause");
							//return;
                        }

                        cout << "Ulangi Pengurutan? (y/n) ";
                        cin >> menuBalik;
                    } while (menuBalik == "y");
                }
                else if (menuSorting == 4)
                {
                    do
                    {
                        system("cls");
                        cout << "Masukkan Nama File : ";
                        cin >> namaFile;
                        ifstream ifs(namaFile + ".txt");
                        if (ifs.is_open())
                        {
                            shellSort(data_mengajar, namaFile);
                        }
                        else
                        {
                            cout << "\n-----------------------" << endl;
							cout << "File Tidak Ditemukan" << endl;
							cout << "-----------------------" << endl;
							//system("pause");
							//return;
                        }

                        cout << "Ulangi Pengurutan? (y/n) ";
                        cin >> menuBalik;
                    } while (menuBalik == "y");
                }
                else if (menuSorting == 5) break;
                else
                {
                    cout << "Pilihan tidak ada" << endl;
                }
                cout << "\nKembali ke Menu Sorting? (y/n) ";
                cin >> menuBalik;
            } while (menuBalik == "y");
}

void manipulasiData(daftarMengajar data_mengajar[1000]){
    string menuBalik, namaFile;
    int menuManipulasi;
    do
            {
                system("cls");
                cout << " +====================+ " << endl;
                cout << " |  MANIPULASI DATA   | " << endl;
                cout << " +====================+ " << endl;
                cout << " | 1. Merging Sambung | " << endl;
                cout << " | 2. Updating        | " << endl;
                cout << " | 3. Splitting       | " << endl;
                cout << " | 4. Back to Menu    | " << endl;
                cout << " +====================+ " << endl;
                cout << "Pilih Menu : ";
                cin >> menuManipulasi;
                system("cls");
                if (menuManipulasi == 1)
                {
                    do
                    {
                        system("cls");
                        mergeSambung(data_mengajar, namaFile);
                        cout << "Ulangi? (y/n) ";
                        cin >> menuBalik;
                    } while (menuBalik == "y");
                }
                else if (menuManipulasi == 2)
                {
                    do
                    {
                        system("cls");
                        updatingData(data_mengajar, namaFile);
                        cout << "Ulangi? (y/n) ";
                        cin >> menuBalik;
                    } while (menuBalik == "y");
                }
                else if (menuManipulasi == 3)
                {
                    do
                    {
                        system("cls");
                        splitingData(data_mengajar, namaFile);
                        cout << "Ulangi? (y/n) ";
                        cin >> menuBalik;
                    } while (menuBalik == "y");
                }
                else if (menuManipulasi == 4) break;

                else
                {
                    cout << "Pilihan tidak ada" << endl;
                }
                cout << "\nKembali ke Menu Manipulasi? (y/n) ";
                cin >> menuBalik;
            } while (menuBalik == "y");
}

void sequentialSearch(daftarMengajar data_mengajar[1000], string file)
{
    string menuBalik;
    do{
        system("cls");
        cout << " +=======================================+ " << endl;
        cout << " | MENU PENCARIAN DATA DENGAN SEQUENTIAL | " << endl;
        cout << " +=======================================+ " << endl;
        cout << " | 1. NIP                                | " << endl;
        cout << " | 2. Nama Dosen                         | " << endl;
        cout << " | 3. MKA                                | " << endl;
        cout << " | 4. Jam                                | " << endl;
        cout << " | 5. Kembali ke menu searching          | " << endl;
        cout << " +=======================================+ " << endl;
        cout << "Pilih : ";
        int pilih, i = 0, banyakData = 0;
        cin >> pilih;
        ifstream ifs(file + ".txt");
        string kosong[1000];
        if (ifs.is_open()){
            while (!ifs.eof())
            {
                ifs >> data_mengajar[i].nip;
                ifs.ignore();
                getline(ifs, data_mengajar[i].nama);
                getline(ifs, data_mengajar[i].mka);
                ifs >> data_mengajar[i].jam;
                ifs.ignore();
                getline(ifs, kosong[i]);
                i++;
            }
        }
        else {
            cout << "\n-----------------------" << endl;
            cout << "File Tidak Ditemukan" << endl;
            cout << "-----------------------" << endl;
            //system("pause");
            return;
        }
        ifs.close();
        banyakData += i - 1;

        if (pilih == 1)
        {
            int nik;
            cout << "Masukkan NIP : ";
            cin >> nik;
            bool found = false;
            for (i = 0; i < banyakData; i++)
            {
                if (data_mengajar[i].nip == nik)
                {
                    found = true;
                    if (found)
                    {
                        cout << "\n-------------------------------------- " << endl;
                        cout << "DATA DOSEN DENGAN NIP : " << data_mengajar[i].nip << endl;
                        cout << "-------------------------------------- " << endl;
                        cout << "NIP\t\t: " << data_mengajar[i].nip << endl;
                        cout << "Nama Dosen\t: " << data_mengajar[i].nama << endl;
                        cout << "MKA\t\t: " << data_mengajar[i].mka << endl;
                        cout << "Jam\t\t: " << data_mengajar[i].jam << endl;
                        cout << "-------------------------------------- " << endl;

                    }
                    else
                    {
                        cout << "Data tidak ditemukan" << endl;
                    }
                    // break;
                }
            }
            if (!found){
                cout << "Data tidak ditemukan" << endl;
            }

        }
        else if (pilih == 2)
        {
            string nama;
            cout << "Masukkan Nama : ";
            cin.ignore();
            getline(cin, nama);
            bool found = false;
            for (i = 0; i < banyakData; i++)
            {
                if (data_mengajar[i].nama == nama)
                {
                    found = true;
                    if (found)
                    {
                        cout << "\n-------------------------------------- " << endl;
                        cout << "DATA DOSEN DENGAN NAMA : " << data_mengajar[i].nama << endl;
                        cout << "-------------------------------------- " << endl;
                        cout << "NIP\t\t: " << data_mengajar[i].nip << endl;
                        cout << "Nama Dosen\t: " << data_mengajar[i].nama << endl;
                        cout << "MKA\t\t: " << data_mengajar[i].mka << endl;
                        cout << "Jam\t\t: " << data_mengajar[i].jam << endl;
                        cout << "-------------------------------------- " << endl;
                    }
                    else
                    {
                        cout << "Data tidak ditemukan" << endl;
                    }
                    // break;
                }
            }
            if (!found){
                cout << "Data tidak ditemukan" << endl;
            }
        }
        else if (pilih == 3)
        {
            string mka;
            cout << "Masukkan MKA : ";
            cin.ignore();
            getline(cin, mka);
            bool found = false;
            for (i = 0; i < banyakData; i++)
            {
                if (data_mengajar[i].mka == mka)
                {
                    found = true;
                    if (found)
                    {
                        cout << "\n-------------------------------------- " << endl;
                        cout << "DATA DOSEN DENGAN MKA : " << data_mengajar[i].mka << endl;
                        cout << "-------------------------------------- " << endl;
                        cout << "NIP\t\t: " << data_mengajar[i].nip << endl;
                        cout << "Nama Dosen\t: " << data_mengajar[i].nama << endl;
                        cout << "MKA\t\t: " << data_mengajar[i].mka << endl;
                        cout << "Jam\t\t: " << data_mengajar[i].jam << endl;
                        cout << "-------------------------------------- " << endl;
                    }
                    else
                    {
                        cout << "Data tidak ditemukan" << endl;
                    }
                    // break;
                }
            }
            if (!found){
                cout << "Data tidak ditemukan" << endl;
            }
        }
        else if (pilih == 4)
        {
            int jam;
            cout << "Masukkan Jam : ";
            cin >> jam;
            cin.ignore();
            bool found = false;
            for (i = 0; i < banyakData; i++)
            {
                if (data_mengajar[i].jam == jam)
                {
                    found = true;
                    if (found)
                    {
                        cout << "\n-------------------------------------- " << endl;
                        cout << "DATA DOSEN DENGAN JAM : " << data_mengajar[i].jam << endl;
                        cout << "-------------------------------------- " << endl;
                        cout << "NIP\t\t: " << data_mengajar[i].nip << endl;
                        cout << "Nama Dosen\t: " << data_mengajar[i].nama << endl;
                        cout << "MKA\t\t: " << data_mengajar[i].mka << endl;
                        cout << "Jam\t\t: " << data_mengajar[i].jam << endl;
                        cout << "-------------------------------------- " << endl;

                    }
                }
            }
            if (!found){
                cout << "Data tidak ditemukan" << endl;
            }
        }
        else if (pilih == 5){
            break;
        }
        else
        {
            cout << "Pilihan tidak ada" << endl;
        }

        cout << "\nKembali ke Menu Sequential  Search? (y/n) ";
        cin >> menuBalik;
    }while(menuBalik == "y" || menuBalik == "Y");
}

void binarySearch(daftarMengajar data_mengajar[1000], string file)
{
    string menuBalik;
    do{
        system("cls");
        cout << " +==============================+ " << endl;
        cout << " | MENU PENCARIAN DENGAN BINARY | " << endl;
        cout << " +==============================+ " << endl;
        cout << " | 1. NIP                       | " << endl;
        cout << " | 2. Nama Dosen                | " << endl;
        cout << " | 3. MKA                       | " << endl;
        cout << " | 4. Jam                       | " << endl;
        cout << " | 5. Kembali ke menu searching | " << endl;
        cout << " +==============================+ " << endl;
        cout << "Pilih : ";
        int pilih, i = 0, banyakData = 0;
        cin >> pilih;
        ifstream ifs(file + ".txt");
        string kosong[1000];
        if (ifs.is_open()){
            while (!ifs.eof())
            {
                ifs >> data_mengajar[i].nip;
                ifs.ignore();
                getline(ifs, data_mengajar[i].nama);
                getline(ifs, data_mengajar[i].mka);
                ifs >> data_mengajar[i].jam;
                getline(ifs, kosong[i]);
                i++;
            }
        }
        else {
            cout << "\n-----------------------" << endl;
            cout << "File Tidak Ditemukan" << endl;
            cout << "-----------------------" << endl;
            //system("pause");
            return;
        }
        ifs.close();
        banyakData = i - 1;

        if (pilih == 1)
    {
    		int n =0;
            int indeksDitemukan[banyakData];
        for (int i = 0; i < banyakData - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < banyakData; j++)
            {
                if (data_mengajar[j].nip < data_mengajar[min].nip)
                {
                    min = j;
                }
            }
            daftarMengajar temp = data_mengajar[i];
            data_mengajar[i] = data_mengajar[min];
            data_mengajar[min] = temp;
        }

        int nip;
        cout << "Masukkan NIP : ";
        cin >> nip;
        int low = 0, high = banyakData - 1, mid;
        //bool found = false;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (data_mengajar[mid].nip == nip)
            {
                				indeksDitemukan[n] = mid;
				n++;
				int i = mid-1, j = mid+1;
				while (i >= low && data_mengajar[i].nip == nip ){
					indeksDitemukan[n] = i;
					n++;
					i--;
				}
				while (j <= high && data_mengajar[j].nip == nip) {
                indeksDitemukan[n] = j;
                n++;
                j++;
				}
                break;
            }
            else if (data_mengajar[mid].nip < nip)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (n>0)
        {

            for (int k = 0; k < n; k++) {
            cout << "--------------------------------------" << endl;
            cout << "DATA DOSEN DENGAN NIP : " << data_mengajar[indeksDitemukan[k]].nip << endl;
            cout << "--------------------------------------" << endl;
            cout << "NIP\t\t: " << data_mengajar[indeksDitemukan[k]].nip << endl;
            cout << "Nama Dosen\t: " << data_mengajar[indeksDitemukan[k]].nama << endl;
            cout << "MKA\t\t: " << data_mengajar[indeksDitemukan[k]].mka << endl;
            cout << "Jam\t\t: " << data_mengajar[indeksDitemukan[k]].jam << endl;
            cout << "--------------------------------------" << endl;
            }
        }
        else
        {
            cout << "Data tidak ditemukan" << endl;
        }
    }

    else if (pilih == 2){
            int n =0;
        int indeksDitemukan[banyakData];
    for (int i = 0; i < banyakData - 1; i++)
    {

        int min = i;
        for (int j = i + 1; j < banyakData; j++)
        {
            if (data_mengajar[j].nama < data_mengajar[min].nama)
            {
                min = j;
            }
        }
        daftarMengajar temp = data_mengajar[i];
        data_mengajar[i] = data_mengajar[min];
        data_mengajar[min] = temp;
    }
    cin.ignore(); // Membersihkan newline sebelum menggunakan getline
    string nama;
    cout << "Masukkan Nama Dosen : ";
    getline(cin, nama);

    int low = 0, high = banyakData - 1, mid;
    //bool found = false;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (data_mengajar[mid].nama == nama)
        {
                indeksDitemukan[n] = mid;
				n++;
				int i = mid-1, j = mid+1;
				while (i >= low && data_mengajar[i].nama == nama){
					indeksDitemukan[n] = i;
					n++;
					i--;
				}
				while (j <= high && data_mengajar[j].nama == nama) {
                indeksDitemukan[n] = j;
                n++;
                j++;
				}
            break;
        }
        else if (data_mengajar[mid].nama < nama)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (n>0)
        {

            for (int k = 0; k < n; k++) {
            cout << "--------------------------------------" << endl;
            cout << "DATA DOSEN DENGAN NAMA : " << data_mengajar[indeksDitemukan[k]].nama << endl;
            cout << "--------------------------------------" << endl;
            cout << "NIP\t\t: " << data_mengajar[indeksDitemukan[k]].nip << endl;
            cout << "Nama Dosen\t: " << data_mengajar[indeksDitemukan[k]].nama << endl;
            cout << "MKA\t\t: " << data_mengajar[indeksDitemukan[k]].mka << endl;
            cout << "Jam\t\t: " << data_mengajar[indeksDitemukan[k]].jam << endl;
            cout << "--------------------------------------" << endl;
            }
        }
    else
    {
        cout << "Data tidak ditemukan" << endl;
    }
}
else if (pilih == 3)
{
        int n =0;
        int indeksDitemukan[banyakData];
    for (int i = 0; i < banyakData - 1; i++)
    {

        int min = i;
        for (int j = i + 1; j < banyakData; j++)
        {
            if (data_mengajar[j].mka < data_mengajar[min].mka)
            {
                min = j;
            }
        }
        daftarMengajar temp = data_mengajar[i];
        data_mengajar[i] = data_mengajar[min];
        data_mengajar[min] = temp;
    }
    cin.ignore(); // Membersihkan newline sebelum menggunakan getline
    string mka;
    cout << "Masukkan MKA : ";
    getline(cin, mka);

    int low = 0, high = banyakData - 1, mid;
    //bool found = false;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (data_mengajar[mid].mka == mka)
        {
                indeksDitemukan[n] = mid;
				n++;
				int i = mid-1, j = mid+1;
				while (i >= low && data_mengajar[i].mka == mka){
					indeksDitemukan[n] = i;
					n++;
					i--;
				}
				while (j <= high && data_mengajar[j].mka == mka) {
                indeksDitemukan[n] = j;
                n++;
                j++;
				}
            break;
        }
        else if (data_mengajar[mid].mka < mka)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (n>0)
        {

            for (int k = 0; k < n; k++) {
            cout << "--------------------------------------" << endl;
            cout << "DATA DOSEN DENGAN MKA : " << data_mengajar[indeksDitemukan[k]].mka << endl;
            cout << "--------------------------------------" << endl;
            cout << "NIP\t\t: " << data_mengajar[indeksDitemukan[k]].nip << endl;
            cout << "Nama Dosen\t: " << data_mengajar[indeksDitemukan[k]].nama << endl;
            cout << "MKA\t\t: " << data_mengajar[indeksDitemukan[k]].mka << endl;
            cout << "Jam\t\t: " << data_mengajar[indeksDitemukan[k]].jam << endl;
            cout << "--------------------------------------" << endl;
            }
        }
    else
    {
        cout << "Data tidak ditemukan" << endl;
    }
    }
    else if (pilih == 4)
    {
        int n =0;
        int indeksDitemukan[banyakData];
    for (int i = 0; i < banyakData - 1; i++)
    {

        int min = i;
        for (int j = i + 1; j < banyakData; j++)
        {
            if (data_mengajar[j].jam < data_mengajar[min].jam)
            {
                min = j;
            }
        }
        daftarMengajar temp = data_mengajar[i];
        data_mengajar[i] = data_mengajar[min];
        data_mengajar[min] = temp;
    }
    cin.ignore(); // Membersihkan newline sebelum menggunakan getline
    int jam;
    cout << "Masukkan JAM : ";
    cin >> jam;

    int low = 0, high = banyakData - 1, mid;
//    bool found = false;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (data_mengajar[mid].jam == jam)
        {
                indeksDitemukan[n] = mid;
				n++;
				int i = mid-1, j = mid+1;
				while (i >= low && data_mengajar[i].jam == jam){
					indeksDitemukan[n] = i;
					n++;
					i--;
				}
				while (j <= high && data_mengajar[j].jam == jam) {
                indeksDitemukan[n] = j;
                n++;
                j++;
				}
            break;
        }
        else if (data_mengajar[mid].jam < jam)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (n>0)
        {

            for (int k = 0; k < n; k++) {
            cout << "--------------------------------------" << endl;
            cout << "DATA DOSEN DENGAN JAM : " << data_mengajar[indeksDitemukan[k]].jam << endl;
            cout << "--------------------------------------" << endl;
            cout << "NIP\t\t: " << data_mengajar[indeksDitemukan[k]].nip << endl;
            cout << "Nama Dosen\t: " << data_mengajar[indeksDitemukan[k]].nama << endl;
            cout << "MKA\t\t: " << data_mengajar[indeksDitemukan[k]].mka << endl;
            cout << "Jam\t\t: " << data_mengajar[indeksDitemukan[k]].jam << endl;
            cout << "--------------------------------------" << endl;
            }
        }
    else
    {
        cout << "Data tidak ditemukan" << endl;
    }
        }
        else if (pilih == 5){
            break;
        }
        else
        {
            cout << "Pilihan tidak ada" << endl;
        }

        cout << "\nKembali ke Menu Binary Search? (y/n) ";
        cin >> menuBalik;
    }while(menuBalik == "y" || menuBalik == "Y");
}

void bubbleSort(daftarMengajar data_mengajar[1000], string file)
{
    string namaFile;
    system("cls");
    cout << " +===============================+ " << endl;
    cout << " | MENU PENGURUTAN DENGAN BUBBLE | " << endl;
    cout << " +===============================+ " << endl;
    cout << " | 1. NIP                        | " << endl;
    cout << " | 2. Nama Dosen                 | " << endl;
    cout << " | 3. MKA                        | " << endl;
    cout << " | 4. Jam                        | " << endl;
    cout << " +===============================+ " << endl;
    cout << "Pilih : ";
    int pilih, i = 0, banyakData = 0;
    cin >> pilih;
    ifstream ifs(file + ".txt");
    string kosong[1000];

	if (ifs.is_open()){
		while (!ifs.eof())
		{
			ifs >> data_mengajar[i].nip;
			ifs.ignore();
			getline(ifs, data_mengajar[i].nama);
			getline(ifs, data_mengajar[i].mka);
			ifs >> data_mengajar[i].jam;
			getline(ifs, kosong[i]);
			i++;
		}
	}
	else {
		cout << "\n-----------------------" << endl;
		cout << "File Tidak Ditemukan" << endl;
		cout << "-----------------------" << endl;
		//system("pause");
		return;
	}
    ifs.close();
    banyakData += i - 1;

    if (pilih == 1)
    {
        for (int i = 0; i < banyakData - 1; i++)
        {
            for (int j = 0; j < banyakData - i - 1; j++)
            {
                if (data_mengajar[j].nip > data_mengajar[j + 1].nip)
                {
                    daftarMengajar temp = data_mengajar[j];
                    data_mengajar[j] = data_mengajar[j + 1];
                    data_mengajar[j + 1] = temp;
                }
            }
        }
    }
    else if (pilih == 2)
    {
        for (int i = 0; i < banyakData - 1; i++)
        {
            for (int j = 0; j < banyakData - i - 1; j++)
            {
                if (data_mengajar[j].nama > data_mengajar[j + 1].nama)
                {
                    daftarMengajar temp = data_mengajar[j];
                    data_mengajar[j] = data_mengajar[j + 1];
                    data_mengajar[j + 1] = temp;
                }
            }
        }
    }
    else if (pilih == 3)
    {
        for (int i = 0; i < banyakData - 1; i++)
        {
            for (int j = 0; j < banyakData - i - 1; j++)
            {
                if (data_mengajar[j].mka > data_mengajar[j + 1].mka)
                {
                    daftarMengajar temp = data_mengajar[j];
                    data_mengajar[j] = data_mengajar[j + 1];
                    data_mengajar[j + 1] = temp;
                }
            }
        }
    }
    else if (pilih == 4)
    {
        for (int i = 0; i < banyakData - 1; i++)
        {
            for (int j = 0; j < banyakData - i - 1; j++)
            {
                if (data_mengajar[j].jam > data_mengajar[j + 1].jam)
                {
                    daftarMengajar temp = data_mengajar[j];
                    data_mengajar[j] = data_mengajar[j + 1];
                    data_mengajar[j + 1] = temp;
                }
            }
        }
    }
    else
    {
        cout << "Pilihan tidak ada" << endl;
    }

    cout << "\nData setelah diurutkan" << endl;
    cout << "+" <<setfill('-') << setw(80) << "-" << "+" << endl;
    cout << left << "|" << setfill(' ') << setw(16) << " NIP"
         << "|" << setfill(' ') << setw(23);
    cout << " Nama Dosen"
         << "|" << setfill(' ') << setw(19) << " MKA"
         << "|" << setfill(' ') << setw(19);
    cout << " Jam"
         << "|" << endl;
    cout << "+" <<setfill('-') << setw(80) << "-" << "+" << endl;

    for (int i = 0; i < banyakData; i++)
    {
        cout << "| " << setfill(' ') << setw(15) << data_mengajar[i].nip << "| " << setfill(' ') << setw(22) << data_mengajar[i].nama;
        cout << "| " << setfill(' ') << setw(18) << data_mengajar[i].mka << "| " << setfill(' ') << setw(18) << data_mengajar[i].jam;
        cout << "| " << endl;
    }
    cout << "+" <<setfill('-') << setw(80) << "-" << "+" << endl;


    cout << "\n\nNama file hasil sorting : ";
    cin >> namaFile;
    ofstream ofs(namaFile + ".txt");
    if (ofs.is_open())
    {
        for (int i = 0; i < banyakData; i++)
        {
            ofs << data_mengajar[i].nip << "\n"
                << data_mengajar[i].nama << "\n"
                << data_mengajar[i].mka << "\n"
                << data_mengajar[i].jam << "\n\n";
        }
        ofs.close();
    }

}
void selectionSort(daftarMengajar data_mengajar[1000], string file)
{
    string namaFile;
    system("cls");
    cout << " +==================================+ " << endl;
    cout << " | MENU PENGURUTAN DENGAN SELECTION | " << endl;
    cout << " +==================================+ " << endl;
    cout << " | 1. NIP                           | " << endl;
    cout << " | 2. Nama Dosen                    | " << endl;
    cout << " | 3. MKA                           | " << endl;
    cout << " | 4. Jam                           | " << endl;
    cout << " +==================================+ " << endl;
    cout << "Pilih : ";
    int pilih, i = 0, banyakData = 0;
    cin >> pilih;
    ifstream ifs(file + ".txt");
    string kosong[1000];

    if (ifs.is_open()){
		while (!ifs.eof())
		{
			ifs >> data_mengajar[i].nip;
			ifs.ignore();
			getline(ifs, data_mengajar[i].nama);
			getline(ifs, data_mengajar[i].mka);
			ifs >> data_mengajar[i].jam;
			getline(ifs, kosong[i]);
			i++;
		}
	}
	else {
		cout << "\n-----------------------" << endl;
		cout << "File Tidak Ditemukan" << endl;
		cout << "-----------------------" << endl;
		//system("pause");
		return;
	}
    ifs.close();
    banyakData += i - 1;

    if (pilih == 1)
    {
        for (int i = 0; i < banyakData - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < banyakData; j++)
            {
                if (data_mengajar[j].nip < data_mengajar[min].nip)
                {
                    min = j;
                }
            }
            daftarMengajar temp = data_mengajar[i];
            data_mengajar[i] = data_mengajar[min];
            data_mengajar[min] = temp;
        }
    }
    else if (pilih == 2)
    {
        for (int i = 0; i < banyakData - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < banyakData; j++)
            {
                if (data_mengajar[j].nama < data_mengajar[min].nama)
                {
                    min = j;
                }
            }
            daftarMengajar temp = data_mengajar[i];
            data_mengajar[i] = data_mengajar[min];
            data_mengajar[min] = temp;
        }
    }
    else if (pilih == 3)
    {
        for (int i = 0; i < banyakData - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < banyakData; j++)
            {
                if (data_mengajar[j].mka < data_mengajar[min].mka)
                {
                    min = j;
                }
            }
            daftarMengajar temp = data_mengajar[i];
            data_mengajar[i] = data_mengajar[min];
            data_mengajar[min] = temp;
        }
    }
    else if (pilih == 4)
    {
        for (int i = 0; i < banyakData - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < banyakData; j++)
            {
                if (data_mengajar[j].jam < data_mengajar[min].jam)
                {
                    min = j;
                }
            }
            daftarMengajar temp = data_mengajar[i];
            data_mengajar[i] = data_mengajar[min];
            data_mengajar[min] = temp;
        }
    }
    else
    {
        cout << "Pilihan tidak ada" << endl;
    }

    cout << "\nData setelah diurutkan" << endl;
    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;
    cout << left << "|" << setfill(' ') << setw(16) << " NIP"
         << "|" << setfill(' ') << setw(23);
    cout << " Nama Dosen"
         << "|" << setfill(' ') << setw(19) << " MKA"
         << "|" << setfill(' ') << setw(19);
    cout << " Jam"
         << "|" << endl;
    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;
    for (int i = 0; i < banyakData; i++)
    {
        cout << "| " << setfill(' ') << setw(15) << data_mengajar[i].nip << "| " << setfill(' ') << setw(22) << data_mengajar[i].nama;
        cout << "| " << setfill(' ') << setw(18) << data_mengajar[i].mka << "| " << setfill(' ') << setw(18) << data_mengajar[i].jam;
        cout << "| " << endl;
    }
    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;

    cout << "\n\nNama file hasil sorting : ";
    cin >> namaFile;
    ofstream ofs(namaFile + ".txt");
    if (ofs.is_open())
    {
        for (int i = 0; i < banyakData; i++)
        {
            ofs << data_mengajar[i].nip << "\n"
                << data_mengajar[i].nama << "\n"
                << data_mengajar[i].mka << "\n"
                << data_mengajar[i].jam << "\n\n";
        }
        ofs.close();
    }

}
void insertionSort(daftarMengajar data_mengajar[1000], string file)
{
    string namaFile;
    system("cls");
    cout << " +==================================+ " << endl;
    cout << " | MENU PENGURUTAN DENGAN INSERTION | " << endl;
    cout << " +==================================+ " << endl;
    cout << " | 1. NIP                           | " << endl;
    cout << " | 2. Nama Dosen                    | " << endl;
    cout << " | 3. MKA                           | " << endl;
    cout << " | 4. Jam                           | " << endl;
    cout << " +==================================+ " << endl;
    cout << "Pilih : ";
    int pilih, i = 0, banyakData = 0;
    cin >> pilih;
    ifstream ifs(file + ".txt");
    string kosong[1000];
    if (ifs.is_open()){
		while (!ifs.eof())
		{
			ifs >> data_mengajar[i].nip;
			ifs.ignore();
			getline(ifs, data_mengajar[i].nama);
			getline(ifs, data_mengajar[i].mka);
			ifs >> data_mengajar[i].jam;
			getline(ifs, kosong[i]);
			i++;
		}
	}
	else {
		cout << "\n-----------------------" << endl;
		cout << "File Tidak Ditemukan" << endl;
		cout << "-----------------------" << endl;
		//system("pause");
		return;
	}
    ifs.close();
    banyakData += i - 1;

    if (pilih == 1)
    {
        for (int i = 1; i < banyakData; i++)
        {
            daftarMengajar temp = data_mengajar[i];
            int j = i - 1;
            while (j >= 0 && data_mengajar[j].nip > temp.nip)
            {
                data_mengajar[j + 1] = data_mengajar[j];
                j--;
            }
            data_mengajar[j + 1] = temp;
        }
    }
    else if (pilih == 2)
    {
        for (int i = 1; i < banyakData; i++)
        {
            daftarMengajar temp = data_mengajar[i];
            int j = i - 1;
            while (j >= 0 && data_mengajar[j].nama > temp.nama)
            {
                data_mengajar[j + 1] = data_mengajar[j];
                j--;
            }
            data_mengajar[j + 1] = temp;
        }
    }
    else if (pilih == 3)
    {
        for (int i = 1; i < banyakData; i++)
        {
            daftarMengajar temp = data_mengajar[i];
            int j = i - 1;
            while (j >= 0 && data_mengajar[j].mka > temp.mka)
            {
                data_mengajar[j + 1] = data_mengajar[j];
                j--;
            }
            data_mengajar[j + 1] = temp;
        }
    }
    else if (pilih == 4)
    {
        for (int i = 1; i < banyakData; i++)
        {
            daftarMengajar temp = data_mengajar[i];
            int j = i - 1;
            while (j >= 0 && data_mengajar[j].jam > temp.jam)
            {
                data_mengajar[j + 1] = data_mengajar[j];
                j--;
            }
            data_mengajar[j + 1] = temp;
        }
    }
    else
    {
        cout << "Pilihan tidak ada" << endl;
    }

    cout << "Data setelah diurutkan" << endl;
    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;
    cout << left << "|" << setfill(' ') << setw(16) << " NIP"
         << "|" << setfill(' ') << setw(23);
    cout << " Nama Dosen"
         << "|" << setfill(' ') << setw(19) << " MKA"
         << "|" << setfill(' ') << setw(19);
    cout << " Jam"
         << "|" << endl;
    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;
    for (int i = 0; i < banyakData; i++)
    {
        cout << "| " << setfill(' ') << setw(15) << data_mengajar[i].nip << "| " << setfill(' ') << setw(22) << data_mengajar[i].nama;
        cout << "| " << setfill(' ') << setw(18) << data_mengajar[i].mka << "| " << setfill(' ') << setw(18) << data_mengajar[i].jam;
        cout << "| " << endl;
    }
    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;

    cout << "\n\nNama file hasil sorting : ";
    cin >> namaFile;
    ofstream ofs(namaFile + ".txt");
    if (ofs.is_open())
    {
        for (int i = 0; i < banyakData; i++)
        {
            ofs << data_mengajar[i].nip << "\n"
                << data_mengajar[i].nama << "\n"
                << data_mengajar[i].mka << "\n"
                << data_mengajar[i].jam << "\n\n";
        }
        ofs.close();
    }

}
void shellSort(daftarMengajar data_mengajar[1000], string file)
{
    string namaFile;
    system("cls");
    cout << " +===============================+ " << endl;
    cout << " | MENU PENGURUTAN DENGAN SHELL  | " << endl;
    cout << " +===============================+ " << endl;
    cout << " | 1. NIP                        | " << endl;
    cout << " | 2. Nama Dosen                 | " << endl;
    cout << " | 3. MKA                        | " << endl;
    cout << " | 4. Jam                        | " << endl;
    cout << " +===============================+ " << endl;
    cout << "Pilih : ";
    int pilih, i = 0, banyakData = 0;
    cin >> pilih;
    ifstream ifs(file + ".txt");
    string kosong[1000];
    if (ifs.is_open()){
		while (!ifs.eof())
		{
			ifs >> data_mengajar[i].nip;
			ifs.ignore();
			getline(ifs, data_mengajar[i].nama);
			getline(ifs, data_mengajar[i].mka);
			ifs >> data_mengajar[i].jam;
			getline(ifs, kosong[i]);
			i++;
		}
	}
	else {
		cout << "\n-----------------------" << endl;
		cout << "File Tidak Ditemukan" << endl;
		cout << "-----------------------" << endl;
		//system("pause");
		return;
	}
    ifs.close();
    banyakData += i - 1;

    if (pilih == 1)
    {
        int gap = banyakData / 2;
        while (gap > 0)
        {
            for (int i = gap; i < banyakData; i++)
            {
                daftarMengajar temp = data_mengajar[i];
                int j = i;
                while (j >= gap && data_mengajar[j - gap].nip > temp.nip)
                {
                    data_mengajar[j] = data_mengajar[j - gap];
                    j -= gap;
                }
                data_mengajar[j] = temp;
            }
            gap /= 2;
        }
    }
    else if (pilih == 2)
    {
        int gap = banyakData / 2;
        while (gap > 0)
        {
            for (int i = gap; i < banyakData; i++)
            {
                daftarMengajar temp = data_mengajar[i];
                int j = i;
                while (j >= gap && data_mengajar[j - gap].nama > temp.nama)
                {
                    data_mengajar[j] = data_mengajar[j - gap];
                    j -= gap;
                }
                data_mengajar[j] = temp;
            }
            gap /= 2;
        }
    }
    else if (pilih == 3)
    {
        int gap = banyakData / 2;
        while (gap > 0)
        {
            for (int i = gap; i < banyakData; i++)
            {
                daftarMengajar temp = data_mengajar[i];
                int j = i;
                while (j >= gap && data_mengajar[j - gap].mka > temp.mka)
                {
                    data_mengajar[j] = data_mengajar[j - gap];
                    j -= gap;
                }
                data_mengajar[j] = temp;
            }
            gap /= 2;
        }
    }
    else if (pilih == 4)
    {
        int gap = banyakData / 2;
        while (gap > 0)
        {
            for (int i = gap; i < banyakData; i++)
            {
                daftarMengajar temp = data_mengajar[i];
                int j = i;
                while (j >= gap && data_mengajar[j - gap].jam > temp.jam)
                {
                    data_mengajar[j] = data_mengajar[j - gap];
                    j -= gap;
                }
                data_mengajar[j] = temp;
            }
            gap /= 2;
        }
    }
    else
    {
        cout << "Pilihan tidak ada" << endl;
    }

    cout << "Data setelah diurutkan" << endl;
    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;
    cout << left << "|" << setfill(' ') << setw(16) << " NIP"
         << "|" << setfill(' ') << setw(23);
    cout << " Nama Dosen"
         << "|" << setfill(' ') << setw(19) << " MKA"
         << "|" << setfill(' ') << setw(19);
    cout << " Jam"
         << "|" << endl;
    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;
    for (int i = 0; i < banyakData; i++)
    {
        cout << "| " << setfill(' ') << setw(15) << data_mengajar[i].nip << "| " << setfill(' ') << setw(22) << data_mengajar[i].nama;
        cout << "| " << setfill(' ') << setw(18) << data_mengajar[i].mka << "| " << setfill(' ') << setw(18) << data_mengajar[i].jam;
        cout << "| " << endl;
    }
    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;

    cout << "\n\nNama file hasil sorting : ";
    cin >> namaFile;
    ofstream ofs(namaFile + ".txt");
    if (ofs.is_open())
    {
        for (int i = 0; i < banyakData; i++)
        {
            ofs << data_mengajar[i].nip << "\n"
                << data_mengajar[i].nama << "\n"
                << data_mengajar[i].mka << "\n"
                << data_mengajar[i].jam << "\n\n";
        }
        ofs.close();
    }

}
void mergeSambung(daftarMengajar data_mengajar[1000], string file)
{
    int i = 0, j = 0, banyakData1 = 0, banyakData2 = 0, banyakDataTotal;
    string file1, file2, kosong[1000];
    system("cls");
    cout << " +=================+ " << endl;
    cout << " | Merging Sambung | " << endl;
    cout << " +=================+ " << endl;
    cout << "Nama File Pertama : ";

    cin >> file1;

    ifstream ifs1(file1 + ".txt");
    if (ifs1.is_open()){
		while (!ifs1.eof())
		{
			ifs1 >> data_mengajar[i].nip;
			ifs1.ignore();
			getline(ifs1, data_mengajar[i].nama);
			getline(ifs1, data_mengajar[i].mka);
			ifs1 >> data_mengajar[i].jam;
			getline(ifs1, kosong[i]);
			i++;
		}
	}
	else {
		cout << "\n-----------------------" << endl;
		cout << "File Tidak Ditemukan" << endl;
		cout << "-----------------------" << endl;
		//system("pause");
		return;
	}
    ifs1.close();
    banyakData1 += i - 1;

    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;
    cout << left << "|" << setfill(' ') << setw(16) << " NIP"
         << "|" << setfill(' ') << setw(23);
    cout << " Nama Dosen"
         << "|" << setfill(' ') << setw(19) << " MKA"
         << "|" << setfill(' ') << setw(19);
    cout << " Jam"
         << "|" << endl;
    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;
    for (int i = 0; i < banyakData1; i++)
    {
        cout << "| " << setfill(' ') << setw(15) << data_mengajar[i].nip << "| " << setfill(' ') << setw(22) << data_mengajar[i].nama;
        cout << "| " << setfill(' ') << setw(18) << data_mengajar[i].mka << "| " << setfill(' ') << setw(18) << data_mengajar[i].jam;
        cout << "| " << endl;
    }
    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;

    cout << "\nNama File Kedua : ";
    cin >> file2;
    j = i - 1;

    ifstream ifs2(file2 + ".txt");
    if (ifs2.is_open()){
		while (!ifs2.eof())
		{
			ifs2 >> data_mengajar[j].nip;
			ifs2.ignore();
			getline(ifs2, data_mengajar[j].nama);
			getline(ifs2, data_mengajar[j].mka);
			ifs2 >> data_mengajar[j].jam;
			getline(ifs2, kosong[j]);
			j++;
            banyakData2++;
		}
	}
	else {
		cout << "\n-----------------------" << endl;
		cout << "File Tidak Ditemukan" << endl;
		cout << "-----------------------" << endl;
		//system("pause");
		return;
	}
    ifs2.close();

    banyakData2--;
    j--;
    banyakDataTotal = banyakData1 + banyakData2;

	cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;
    cout << left << "|" << setfill(' ') << setw(16) << " NIP"
         << "|" << setfill(' ') << setw(23);
    cout << " Nama Dosen"
         << "|" << setfill(' ') << setw(19) << " MKA"
         << "|" << setfill(' ') << setw(19);
    cout << " Jam"
         << "|" << endl;
    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;
		for (int i = banyakData1; i < j; i++)
		{
			cout << "| " << setfill(' ') << setw(15) << data_mengajar[i].nip << "| " << setfill(' ') << setw(22) << data_mengajar[i].nama;
			cout << "| " << setfill(' ') << setw(18) << data_mengajar[i].mka << "| " << setfill(' ') << setw(18) << data_mengajar[i].jam;
			cout << "| " << endl;
		}
    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;

    cout << "\nMasukkan nama file hasil merge : ";
    string file3;
    cin >> file3;
    ofstream ofs(file3 + ".txt");
    if (ofs.is_open())
    {
        for (int i = 0; i < banyakDataTotal; i++)
        {
            ofs << data_mengajar[i].nip << "\n"
                << data_mengajar[i].nama << "\n"
                << data_mengajar[i].mka << "\n"
                << data_mengajar[i].jam << "\n\n";
        }
        ofs.close();
    }
    cout << "Data berhasil disimpan di file " << file3 << endl;
}
void updatingData(daftarMengajar data_mengajar[1000], string file)
{
    string nama, jam, mka;
    system("cls");
    cout << " +==============+ " << endl;
    cout << " | Update Data  | " << endl;
    cout << " +==============+ " << endl;
    int i = 0, k, banyakData = 0;
    cout << "Masukkan Nama File : ";
    cin >> file;
    ifstream ifs(file + ".txt");
    string kosong[1000];
    if (ifs.is_open())
    {
        while (!ifs.eof())
        {
            ifs >> data_mengajar[i].nip;
            ifs.ignore();
            getline(ifs, data_mengajar[i].nama);
            getline(ifs, data_mengajar[i].mka);
            ifs >> data_mengajar[i].jam;
            getline(ifs, kosong[i]);
            i++;
        }
        ifs.close();
        banyakData += i - 1;
    }
    else
    {
  cout << "\n-----------------------" << endl;
  cout << "File Tidak Ditemukan" << endl;
  cout << "-----------------------" << endl;
  //system("pause");
  return;
    }
    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;
    cout << left << "|" << setfill(' ') << setw(16) << " NIP"
         << "|" << setfill(' ') << setw(23);
    cout << " Nama Dosen"
         << "|" << setfill(' ') << setw(19) << " MKA"
         << "|" << setfill(' ') << setw(19);
    cout << " Jam"
         << "|" << endl;
    cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;
		  for (i = 0; i < banyakData; i++)
		  {
		   cout << "| " << setfill(' ') << setw(15) << data_mengajar[i].nip << "| " << setfill(' ') << setw(22) << data_mengajar[i].nama;
		   cout << "| " << setfill(' ') << setw(18) << data_mengajar[i].mka << "| " << setfill(' ') << setw(18) << data_mengajar[i].jam;
		   cout << "| " << endl;
		  }
			cout << "+" << setfill('-') << setw(80) << "-" << "+" << endl;

 //
    cout << "NIP\t: ";
    int nip;
    cin >> nip;
    bool update = false;
    for (k = 0; k < banyakData; k++)
    {
        if (data_mengajar[k].nip == nip)
        {
            update = true;
            break;
        }
    }
    if (update)
    {
        cout << "NIP\t\t: " << (data_mengajar[k].nip) << endl;
        cout << "Nama Dosen\t: " << data_mengajar[k].nama << endl;
        cout << "MKA\t\t: " << data_mengajar[k].mka << endl;
        cout << "Jam\t\t: " << data_mengajar[k].jam << endl;
    }
    else
    {
        cout << "\nNIK tidak ditemukan\n";
        system ("pause");
        updatingData(data_mengajar, file);
    }
		cout << "Masukkan Data Update : " << endl;
		cout << "\n\tNIP\t\t: ";
		cin >> data_mengajar[k].nip;
		cin.ignore();
		cout << "\n\tNama Dosen\t: ";
		getline(cin, data_mengajar[k].nama);
		cout << "\tMKA\t\t: ";
		getline(cin, data_mengajar[k].mka);
		cout << "\tJam\t\t: ";
		cin >> data_mengajar[k].jam;

    // banyakData++;

    cout << "\nMasukkan Nama File Hasil Updating : ";
    string fileUpdate;
    cin >> fileUpdate;
    ofstream ofs(fileUpdate  + ".txt");
    if (ofs.is_open())
    {
        for(int j = 0 ; j < banyakData; j++){
            ofs << data_mengajar[j].nip << "\n"
                << data_mengajar[j].nama << "\n"
                << data_mengajar[j].mka << "\n"
                << data_mengajar[j].jam << "\n\n";
        }
    }
    else
    {
        cout << "File tidak dapat dibuka" << endl;
    }
    ofs.close();
    cout << "\nUpdating Berhasil, lihat file hasil dengan kembali ke menu utama" << endl;
}

void splitingData(daftarMengajar data_mengajar[1000], string file){
    string file1, file2;
    int i = 0, banyakData = 0, j, split;
    cout << "\nMasukkan nama file yang akan displit : ";
    cin >> file;
    ifstream ifs(file + ".txt");
    string kosong[1000];
    if (ifs.is_open()){
		while (!ifs.eof())
		{
			ifs >> data_mengajar[i].nip;
			ifs.ignore();
			getline(ifs, data_mengajar[i].nama);
			getline(ifs, data_mengajar[i].mka);
			ifs >> data_mengajar[i].jam;
			getline(ifs, kosong[i]);
			i++;
		}
	}
	else {
		cout << "\n-----------------------" << endl;
		cout << "File Tidak Ditemukan" << endl;
		cout << "-----------------------" << endl;
		//system("pause");
		return;
	}
    ifs.close();
    banyakData += i - 1;
    //banyak data = 4

    i = 0;
    j = 0;

    cout << "\nMasukkan nama file split pertama       : ";
    cin >> file1;
    cout << "\nMasukkan nama file split kedua         : ";
    cin >> file2;
    do{
    cout << "\nSplit di data ke berapa? (1 - " << banyakData-1 << ") : ";
    cin >> split;

    if(split > banyakData-1){
        cout << "Banyak data kurang dari urutan data yang ingin di split. Input sesuai range.";
        getch();
    }
    }while (split > banyakData-1);

    ofstream ofs1(file1 + ".txt");
    if (ofs1.is_open())
    {
        while(i < split)
        {
            ofs1 << data_mengajar[i].nip << "\n"
                << data_mengajar[i].nama << "\n"
                << data_mengajar[i].mka << "\n"
                << data_mengajar[i].jam << "\n\n";
            i++;
        }
        ofs1.close();
    }
    j = i;
    ofstream ofs2(file2  + ".txt");
    if (ofs2.is_open())
    {
        while(j < banyakData)
        {
            ofs2 << data_mengajar[j].nip << "\n"
                << data_mengajar[j].nama << "\n"
                << data_mengajar[j].mka << "\n"
                << data_mengajar[j].jam << "\n\n";
            j++;
        }
        ofs2.close();
    }
}
