#include <iostream>

#include <fstream>

#include <iomanip>

#include <bits/stdc++.h>

#include <cstring>

#include <cstdlib>

#define gopro 50000
#define xiaomi 60000
#define dslrc 85000
#define dslr 110000
#define ce 100000
#define ced 80000
#define nikon 85000
#define nikond 125000
using namespace std;

int pilih;
string pilih1;
void buat(), tampilkan(), search(), sort(), manipulate(), tabel();

struct data {
	string nama, nomor, alamat, kamera1;
	int kamera2, hari, bayar, total;
};

data penyewa[100];

int i = 0, j = 0;

void baca(string namafile) {
	string line, temp;
	ifstream file(namafile);
	i = 0;
	if (file.is_open()) {
		while (getline(file, line)) {
			stringstream ss(line);
			getline(ss, penyewa[i].nama, ',');
			getline(ss, penyewa[i].alamat, ',');
			getline(ss, penyewa[i].nomor, ',');
			getline(ss, temp, ',');
			penyewa[i].kamera2 = atoi(temp.c_str());
			getline(ss, penyewa[i].kamera1, ',');
			getline(ss, temp, ',');
			penyewa[i].hari = atoi(temp.c_str());
			getline(ss, temp, ',');
			penyewa[i].bayar = atoi(temp.c_str());
			getline(ss, temp, ',');
			penyewa[i].total = atoi(temp.c_str());
			i++;
		}
		file.close();
	} else cout << "File gagal dibuka";
}

void merge(string namafile) {
	int y = 0;
	ofstream mfile(namafile, ios::app);
	if (mfile.is_open()) {
		while (y < i) {
			mfile << penyewa[y].nama << ',' << penyewa[y].alamat << ',' << penyewa[y].nomor << ',' << penyewa[y].kamera2 << ',' << penyewa[y].kamera1 << ',' << penyewa[y].hari << ',' << penyewa[y].bayar << ',' << penyewa[y].total << endl;
			y++;
		}
		mfile.close();
	}
}


void bubble() {
	if(pilih1 == "1"){
	data temp;
	int k;
	for (j = 0; j < i - 1; j++) {
		for (k = 0; k < i - 1 - j; k++) {
			if (penyewa[j].nama > penyewa[j + 1].nama) {
				temp = penyewa[j];
				penyewa[j] = penyewa[j + 1];
				penyewa[j + 1] = temp;
			}
		}
	}
	}
	else if(pilih1 == "2"){
	data temp;
	int k;
	for (j = 0; j < i - 1; j++) {
		for (k = 0; k < i - 1 - j; k++) {
			if (penyewa[j].hari > penyewa[j + 1].hari) {
				temp = penyewa[j];
				penyewa[j] = penyewa[j + 1];
				penyewa[j + 1] = temp;
			}
		}
	}
	}
}

void selection(data penyewa[]) {
	data temp;
	int current, j = 0;
	if(pilih1 == "1"){
	for (current = 0; current < i; current++) {
		for (j = current + 1; j < i; j++) {
			if (penyewa[current].nama > penyewa[j].nama) {
				temp = penyewa[current];
				penyewa[current] = penyewa[j];
				penyewa[j] = temp;
			}
		}
	}
	}
	else if (pilih1 == "2"){
	for (current = 0; current < i; current++) {
		for (j = current + 1; j < i; j++) {
			if (penyewa[current].hari > penyewa[j].hari) {
				temp = penyewa[current];
				penyewa[current] = penyewa[j];
				penyewa[j] = temp;
			}
		}
	}
	}
}


void insertion(data penyewa[]) {
	int k, j;
	data key;
	if(pilih1 == "1"){
	for (k = 1; k < i; k++) {
		key = penyewa[k];
		j = k - 1;

		while (j >= 0 && penyewa[j].nama > key.nama) {
			penyewa[j + 1] = penyewa[j];
			j = j - 1;
		}
		penyewa[j + 1] = key;
	}
	}

	else if (pilih1 == "2"){
		for (k = 1; k < i; k++) {
		key = penyewa[k];
		j = k - 1;

		while (j >= 0 && penyewa[j].hari > key.hari) {
			penyewa[j + 1] = penyewa[j];
			j = j - 1;
		}
		penyewa[j + 1] = key;
	}
	}
}


void shell(data penyewa[]) {
	if(pilih1 == "1"){
	for (int gap = i / 2; gap > 0; gap /= 2) {
		for (int k = gap; k < i; k++) {
			data temp = penyewa[k];
			int j;
			for (j = k; j >= gap && penyewa[j - gap].nama > temp.nama; j -= gap) {
				penyewa[j] = penyewa[j - gap];
			}
			penyewa[j] = temp;
		}
	}
	}

	else if(pilih1 == "2"){
	for (int gap = i / 2; gap > 0; gap /= 2) {
		for (int k = gap; k < i; k++) {
			data temp = penyewa[k];
			int j;
			for (j = k; j >= gap && penyewa[j - gap].hari > temp.hari; j -= gap) {
				penyewa[j] = penyewa[j - gap];
			}
			penyewa[j] = temp;
		}
	}
	}
}

void listkamera() {
	cout << "-------------------------------List Kamera----------------------------" << endl;
	cout << "[1] Gopro                              || biaya sewa Rp.50000/hari  ||" << endl;
	cout << "[2] Xiaomi Yi Cam                      || biaya sewa Rp.60000/hari  ||" << endl;
	cout << "[3] DSLR CANON 1000D + Lensa 18-55mm   || biaya sewa Rp.85000/hari  ||" << endl;
	cout << "[4] DSLR CANON 500D + Lensa 18-55mm    || biaya sewa Rp.110000/hari ||" << endl;
	cout << "[5] CANON EOS 1100D + LENSA18-55mm     || biaya sewa Rp.100000/hari ||" << endl;
	cout << "[6] CANON EOS 450D + LENSA18-55mm      || biaya sewa Rp.80000/hari  ||" << endl;
	cout << "[7] DSLR NIKON D3000+ Lensa 18-55mm    || biaya sewa Rp.85000/hari  ||" << endl;
	cout << "[8] DSLR NIKON D80 + Lensa 18-55mm     || biaya sewa Rp.125000/hari ||" << endl;
}

void header() {
	cout << "==============================================" << endl;
	cout << "|\tSelamat Datang di Rental Kamera\t     |" << endl;
	cout << "==============================================" << endl;
	cout << endl;
}
int main() {
	system("cls");
	header();
	cout << "Menu Utama :" << endl << endl;
	cout << "1. Input data" << endl;
	cout << "2. Tampil data" << endl;
	cout << "3. Searching data" << endl;
	cout << "4. Sorting data" << endl;
	cout << "5. Manipulasi data" << endl;
	cout << "6. Exit" << endl << endl;
	cout << "Masukkan pilihan : ";
	cin >> pilih;
	switch (pilih) {
		case 1:
			buat();
			break;
		case 2:
			tampilkan();
			break;
		case 3:
			search();
			break;
		case 4:
			sort();
			break;

		case 5:
			manipulate();
			break;
		case 6:
			break;
		default: {
			cout << "Pilihan yang anda masukkan salah";
			main();
		}
	}
}

void buat() {
	bool kurang=true;
	system("cls");
	header();
	cout << "---------Identitas Perental Kamera-----------" << endl << endl;
	cout << "Masukan Nama Anda                 : ";
	cin.ignore();
	getline(cin, penyewa[i].nama);
	getline(cin, penyewa[i].nama);
	cout << "Masukan Alamat Anda               : ";
	getline(cin, penyewa[i].alamat);
	cout << "Masukan Nomor HP Anda             : ";
	getline(cin, penyewa[i].nomor);
	cout << "---------------------------------------------" << endl;
	listkamera();
	cout << "Masukkan pilihan\t: ";
	cin >> penyewa[i].kamera2;
	cout << "Lama menyewa\t\t: ";
	cin >> penyewa[i].hari;
	switch (penyewa[i].kamera2) {
		case 1:
			penyewa[i].total = penyewa[i].hari * gopro;
			penyewa[i].kamera1 = "Gopro";
			break;

		case 2:
			penyewa[i].total = penyewa[i].hari * xiaomi;
			penyewa[i].kamera1 = "Xiaomi Yi Cam";
			break;

		case 3:
			penyewa[i].total = penyewa[i].hari * dslrc;
			penyewa[i].kamera1 = "DSLR CANON 1000D + Lensa 18-55mm";
			break;

		case 4:
			penyewa[i].total = penyewa[i].hari * dslr;
			penyewa[i].kamera1 = "DDSLR CANON 500D + Lensa 18-55mm";
			break;

		case 5:
			penyewa[i].total = penyewa[i].hari * ce;
			penyewa[i].kamera1 = "CANON EOS 1100D + LENSA18-55mm";
			break;

		case 6:
			penyewa[i].total = penyewa[i].hari * ced;
			penyewa[i].kamera1 = "CANON EOS 450D + LENSA18-55mm";
			break;

		case 7:
			penyewa[i].total = penyewa[i].hari * nikon;
			penyewa[i].kamera1 = "DSLR NIKON D3000+ Lensa 18-55mm";
			break;

		case 8:
			penyewa[i].total = penyewa[i].hari * nikond;
			penyewa[i].kamera1 = "DSLR NIKON D80 + Lensa 18-55mm";
			break;
	}
	while(kurang == true){
	cout << "Total yang harus dibayar: Rp." << penyewa[i].total << endl;
	cout << "Uang yang anda bayarkan : Rp."; cin >> penyewa[i].bayar;

		if(penyewa[i].bayar>=penyewa[i].total){
			cout << "Kembalian Anda\t:  Rp." << penyewa[i].bayar-penyewa[i].total;
			kurang = false;
		}
		else
		if(penyewa[i].bayar<penyewa[i].total){
			cout<<"Uang Anda kurang"<<endl;
			kurang = true;
		}

	}
	system("pause");
	system("cls");
	cout << "-------------------------------------------------" << endl;
	cout << "\t\tPesanan Anda" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "Nama\t\t: " << penyewa[i].nama << endl;
	cout << "Alamat\t\t: " << penyewa[i].alamat << endl;
	cout << "Nomor Telp\t: " << penyewa[i].nomor << endl;
	cout << "--------------Detail pesanan---------------------" << endl;
	cout << "Kamera\t\t: " << penyewa[i].kamera2 << endl;
	cout << "Merk\t\t: " << penyewa[i].kamera1 << endl;
	cout << "Lama menyewa\t: " << penyewa[i].hari << " hari" << endl;
	cout << "Total yang harus dibayarkan\t: Rp." << penyewa[i].total << endl;
	cout << "Uang yang anda bayarkan\t\t: Rp." << penyewa[i].bayar << endl;
	cout << "Kembalian Anda\t\t\t: Rp." << penyewa[i].bayar - penyewa[i].total << endl;
	cout << "Pesanan telah dibuat di file rentalkamera.txt" <<endl;
	ofstream file("rentalkamera.txt", ios::app);
	if (file.is_open()) {
		file << penyewa[i].nama << ',' << penyewa[i].alamat << ',' << penyewa[i].nomor << ',' << penyewa[i].kamera2 << ',' << penyewa[i].kamera1 << ',' << penyewa[i].hari << ',' << penyewa[i].bayar << ',' << penyewa[i].total << endl;
		file.close();
	} else cout << "File gagal dibuka" << endl;
	system("pause");
	system("cls");
	main();
}

void tampilkan() {
    string namafile;

	system("cls");
	header();
	cout<<"Masukkan nama File yang ingin ditampilkan : ";
	cin>>namafile;
	baca(namafile+".txt");

	tabel();

	system("pause");
	system("cls");
	main();
}

void search() {
	system("cls");
	string cari;
	int k;
	j = 0;
	bool found = false;
	header();
	cout << "Pilih metode search yang diinginkan : " << endl;
	cout << "1. Sequential search" << endl;
	cout << "2. Binary search" << endl;
	cout << "Masukkan pilihan : ";
	cin >> pilih;
	cout << "Masukkan nama dari data yang ingin dicari : ";
	cin.ignore();
	getline(cin, cari);
	switch (pilih) {
		case 1: {
			baca("rentalkamera.txt");
			while (j < i) {
				if (penyewa[j].nama == cari) {
					cout << "Data ditemukan & berikut detail data dari " << cari << endl;
					cout << "Nama\t\t: " << penyewa[j].nama << endl;
					cout << "Alamat\t\t: " << penyewa[j].alamat << endl;
					cout << "Nomor Telp\t: " << penyewa[j].nomor << endl;
					cout << "--------------Detail pesanan---------------------" << endl;
					cout << "Kamera\t\t: " << penyewa[j].kamera2 << endl;
					cout << "Merk\t\t: " << penyewa[j].kamera1 << endl;
					cout << "Lama menyewa\t: " << penyewa[j].hari << " hari" << endl;
					cout << "Total yang harus dibayarkan\t: Rp." << penyewa[j].total << endl;
					cout << "Uang yang anda bayarkan\t\t: Rp." << penyewa[j].bayar << endl;
					cout << "Kembalian Anda\t\t\t: Rp." << penyewa[j].bayar - penyewa[j].total << endl;
					found = true;
					j++;
				} else {
					j++;
				}
			}
			if (!found) {
				cout << "Data tidak ditemukan" << endl;
			}
		}
		break;
	case 2: {
		baca("rentalkamera.txt");
		bubble();
		j = 0;
		while (j <= i && !found) {
			k = (j + i) / 2;
			if (cari == penyewa[k].nama) {
				cout << "Data ditemukan & berikut detail data dari " << cari << endl;
				cout << "Nama\t\t: " << penyewa[k].nama << endl;
				cout << "Alamat\t\t: " << penyewa[k].alamat << endl;
				cout << "Nomor Telp\t: " << penyewa[k].nomor << endl;
				cout << "--------------Detail pesanan---------------------" << endl;
				cout << "Kamera\t\t: " << penyewa[k].kamera2 << endl;
				cout << "Merk\t\t: " << penyewa[k].kamera1 << endl;
				cout << "Lama menyewa\t: " << penyewa[k].hari << " hari" << endl;
				cout << "Total yang harus dibayarkan\t: Rp." << penyewa[k].total << endl;
				cout << "Uang yang anda bayarkan\t\t: Rp." << penyewa[k].bayar << endl;
				cout << "Kembalian Anda\t\t\t: Rp." << penyewa[k].bayar - penyewa[k].total << endl;
				found = true;
			} else if (cari < penyewa[k].nama)
				i = k - 1;
			else
				j = k + 1;
		}
		if (!found) {
			cout << "Data tidak ditemukan";
		}
	}
	break;
	default: {
		cout << "Pilihan tidak ada di menu" << endl;
		search();
	}
	}
	system("pause");
	system("cls");
	main();
}

void sort() {
	system("cls");
	header();
	baca("rentalkamera.txt");
	cout << "Mengurutkan data berdasarkan kamera yang dipilih" << endl;
	cout << "1. Selection sort" << endl;
	cout << "2. Insertion sort" << endl;
	cout << "3. Shell sort" << endl;
	cout << "4. Bubble sort" << endl;
	cout << "Masukkan pilihan : ";
	cin >> pilih;
	switch (pilih) {
		case 1: {
			system("cls");
			header();
			cout << "Mengurutkan berdasarkan : \n\n";
			cout << "1. Nama\n";
			cout << "2. Lama Sewa\n";
			cout << "Masukan Pilihan : ";
			cin >> pilih1;

			if (pilih1 == "1") {
				selection(penyewa);
				ofstream sfile("selectionnama.txt");
				if (sfile.is_open()) {
					j = 0;
					while (j < i) {
						sfile << penyewa[j].nama << ',' << penyewa[j].alamat << ',' << penyewa[j].nomor << ',' << penyewa[j].kamera2 << ',' << penyewa[j].kamera1 << ',' <<
							penyewa[j].hari << ',' << penyewa[j].bayar << ',' << penyewa[j].total << endl;
						j++;
					}
					sfile.close();
				} else cout << "File gagal dibuka" << endl;
				baca("selectionnama.txt");
				cout << endl;
				tabel();
				cout << "\nData berhasil disorting dan disimpan dengan nama selectionnama.txt" << endl;
			} else if (pilih1 == "2") {
				selection(penyewa);
				ofstream sfile("selectionhari.txt");
				if (sfile.is_open()) {
					j = 0;
					while (j < i) {
						sfile << penyewa[j].nama << ',' << penyewa[j].alamat << ',' << penyewa[j].nomor << ',' << penyewa[j].kamera2 << ',' << penyewa[j].kamera1 << ',' <<
							penyewa[j].hari << ',' << penyewa[j].bayar << ',' << penyewa[j].total << endl;
						j++;
					}
					sfile.close();
				} else cout << "File gagal dibuka" << endl;
				baca("selectionhari.txt");
				cout << endl;
				tabel();
				cout << "\nData berhasil disorting dan disimpan dengan lama sewa selectionhari.txt" << endl;

			}
		}
		break;
	case 2: {
			system("cls");
			header();
			cout << "Mengurutkan berdasarkan : \n\n";
			cout << "1. Nama\n";
			cout << "2. Lama Sewa\n";
			cout << "Masukan Pilihan : ";
			cin >> pilih1;

			if (pilih1 == "1") {
				insertion(penyewa);
				ofstream sfile("insertionnama.txt");
				if (sfile.is_open()) {
					j = 0;
					while (j < i) {
						sfile << penyewa[j].nama << ',' << penyewa[j].alamat << ',' << penyewa[j].nomor << ',' << penyewa[j].kamera2 << ',' << penyewa[j].kamera1 << ',' <<
							penyewa[j].hari << ',' << penyewa[j].bayar << ',' << penyewa[j].total << endl;
						j++;
					}
					sfile.close();
				} else cout << "File gagal dibuka" << endl;
				baca("insertionnama.txt");
				cout << endl;
				tabel();
				cout << "\nData berhasil disorting dan disimpan dengan nama insertionnama.txt" << endl;
			} else if (pilih1 == "2") {
				insertion(penyewa);
				ofstream sfile("insertionhari.txt");
				if (sfile.is_open()) {
					j = 0;
					while (j < i) {
						sfile << penyewa[j].nama << ',' << penyewa[j].alamat << ',' << penyewa[j].nomor << ',' << penyewa[j].kamera2 << ',' << penyewa[j].kamera1 << ',' <<
							penyewa[j].hari << ',' << penyewa[j].bayar << ',' << penyewa[j].total << endl;
						j++;
					}
					sfile.close();
				} else cout << "File gagal dibuka" << endl;
				baca("insertionhari.txt");
				cout << endl;
				tabel();
				cout << "\nData berhasil disorting dan disimpan dengan lama sewa insertionhari.txt" << endl;

			}
	}
	break;
	case 3: {
			system("cls");
			header();
			cout << "Mengurutkan berdasarkan : \n\n";
			cout << "1. Nama\n";
			cout << "2. Lama Sewa\n";
			cout << "Masukan Pilihan : ";
			cin >> pilih1;

			if (pilih1 == "1") {
				shell(penyewa);
				ofstream sfile("shellnama.txt");
				if (sfile.is_open()) {
					j = 0;
					while (j < i) {
						sfile << penyewa[j].nama << ',' << penyewa[j].alamat << ',' << penyewa[j].nomor << ',' << penyewa[j].kamera2 << ',' << penyewa[j].kamera1 << ',' <<
							penyewa[j].hari << ',' << penyewa[j].bayar << ',' << penyewa[j].total << endl;
						j++;
					}
					sfile.close();
				} else cout << "File gagal dibuka" << endl;
				baca("shellnama.txt");
				cout << endl;
				tabel();
				cout << "\nData berhasil disorting dan disimpan dengan nama shellnama.txt" << endl;
			} else if (pilih1 == "2") {
				shell(penyewa);
				ofstream sfile("shellhari.txt");
				if (sfile.is_open()) {
					j = 0;
					while (j < i) {
						sfile << penyewa[j].nama << ',' << penyewa[j].alamat << ',' << penyewa[j].nomor << ',' << penyewa[j].kamera2 << ',' << penyewa[j].kamera1 << ',' <<
							penyewa[j].hari << ',' << penyewa[j].bayar << ',' << penyewa[j].total << endl;
						j++;
					}
					sfile.close();
				} else cout << "File gagal dibuka" << endl;
				baca("shellhari.txt");
				cout << endl;
				tabel();
				cout << "\nData berhasil disorting dan disimpan dengan lama sewa shellhari.txt" << endl;

			}
	}
	break;
	case 4: {
			system("cls");
			header();
			cout << "Mengurutkan berdasarkan : \n\n";
			cout << "1. Nama\n";
			cout << "2. Lama Sewa\n";
			cout << "Masukan Pilihan : ";
			cin >> pilih1;

			if (pilih1 == "1") {
				bubble();
				ofstream sfile("bubblenama.txt");
				if (sfile.is_open()) {
					j = 0;
					while (j < i) {
						sfile << penyewa[j].nama << ',' << penyewa[j].alamat << ',' << penyewa[j].nomor << ',' << penyewa[j].kamera2 << ',' << penyewa[j].kamera1 << ',' <<
							penyewa[j].hari << ',' << penyewa[j].bayar << ',' << penyewa[j].total << endl;
						j++;
					}
					sfile.close();
				} else cout << "File gagal dibuka" << endl;
				baca("bubblenama.txt");
				cout << endl;
				tabel();
				cout << "\nData berhasil disorting dan disimpan dengan nama bubblenama.txt" << endl;
			} else if (pilih1 == "2") {
				bubble();
				ofstream sfile("bubblehhari.txt");
				if (sfile.is_open()) {
					j = 0;
					while (j < i) {
						sfile << penyewa[j].nama << ',' << penyewa[j].alamat << ',' << penyewa[j].nomor << ',' << penyewa[j].kamera2 << ',' << penyewa[j].kamera1 << ',' <<
							penyewa[j].hari << ',' << penyewa[j].bayar << ',' << penyewa[j].total << endl;
						j++;
					}
					sfile.close();
				} else cout << "File gagal dibuka" << endl;
				baca("bubblehari.txt");
				cout << endl;
				tabel();
				cout << "\nData berhasil disorting dan disimpan dengan lama sewa bubblehari.txt" << endl;

			}
	}
	break;
	default: {
		cout << "Pilihan yang anda masukkan salah";
		sort();
	}
	}
	system("pause");
	system("cls");
	main();
}

void manipulate() {
	bool kurang=true;
	int split;
	j = 0;
	string cari;

	bool found = false;
	string namafile[4];
	system("cls");
	header();
	cout << "1. Split data" << endl;
	cout << "2. Merge data" << endl;
	cout << "3. Update data" << endl;
	cout << "Masukkan pilihan : ";
	cin >> pilih;
	switch (pilih) {
		case 1: {
			cout << "Masukkan nama file untuk hasil splitting" << endl;
			cout << "Nama file ke-1 = ";
			cin >> namafile[0];
			cout << "Nama file ke-2 = ";
			cin >> namafile[1];
			baca("rentalkamera.txt");
			split = i / 2;
			cout<<"\nData yang akan disimpan pada file "<<namafile[0]<<endl;
			cout << setw(121) << setfill('=') << "=" << endl;
			cout << "| ";
			cout << setw((2 - 2) / 2 + 2) << right << setfill(' ') << "No";
			cout << setw(0) << right << setfill(' ') << "";
			cout << " | ";
			cout << setw((16 - 4) / 2 + 4) << right << setfill(' ') << "Nama";
			cout << setw(6) << right << setfill(' ') << "";
			cout << " | ";
			cout << setw((20 - 6) / 2 + 6) << right << setfill(' ') << "Alamat";
			cout << setw(7) << right << setfill(' ') << "";
			cout << " | ";
			cout << setw((13 - 7) / 2 + 7) << right << setfill(' ') << "No Telp";
			cout << setw(3) << right << setfill(' ') << "";
			cout << " | ";
			cout << setw((33 - 7) / 2 + 7) << right << setfill(' ') << "Kamera";
			cout << setw(13) << right << setfill(' ') << "";
			cout << " | ";
			cout << setw((8 - 4) / 2 + 4) << right << setfill(' ') << "Lama";
			cout << setw(2) << right << setfill(' ') << "";
			cout << " | ";
			cout << setw((7 - 5) / 2 + 5) << right << setfill(' ') << "Total";
			cout << setw(1) << right << setfill(' ') << "";
			cout << " | ";
			cout << endl;
			cout << setw(121) << setfill('=') << "=" << endl;
			while(j<split) {
			cout << "| ";
			cout << setw(2) << left << setfill(' ') << j + 1;
			cout << " | ";
			cout << setw(16) << left << setfill(' ') << penyewa[j].nama;
			cout << " | ";
			cout << setw(20) << left << setfill(' ') << penyewa[j].alamat;
			cout << " | ";
			cout << setw(13) << left << setfill(' ') << penyewa[j].nomor;
			cout << " | ";
			cout << setw(33) << left << setfill(' ') << penyewa[j].kamera1;
			cout << " | ";
			cout << setw(8) << left << setfill(' ') << penyewa[j].hari;
			cout << " | ";
			cout << setw(7) << left << setfill(' ') << penyewa[j].total;
			cout << " |\n";
			j++;
			}
			cout << setw(121) << setfill('=') << "=" << endl;

			cout<<"\nData yang akan disimpan pada file "<<namafile[1]<<endl;
			cout << setw(121) << setfill('=') << "=" << endl;
			cout << "| ";
			cout << setw((2 - 2) / 2 + 2) << right << setfill(' ') << "No";
			cout << setw(0) << right << setfill(' ') << "";
			cout << " | ";
			cout << setw((16 - 4) / 2 + 4) << right << setfill(' ') << "Nama";
			cout << setw(6) << right << setfill(' ') << "";
			cout << " | ";
			cout << setw((20 - 6) / 2 + 6) << right << setfill(' ') << "Alamat";
			cout << setw(7) << right << setfill(' ') << "";
			cout << " | ";
			cout << setw((13 - 7) / 2 + 7) << right << setfill(' ') << "No Telp";
			cout << setw(3) << right << setfill(' ') << "";
			cout << " | ";
			cout << setw((33 - 7) / 2 + 7) << right << setfill(' ') << "Kamera";
			cout << setw(13) << right << setfill(' ') << "";
			cout << " | ";
			cout << setw((8 - 4) / 2 + 4) << right << setfill(' ') << "Lama";
			cout << setw(2) << right << setfill(' ') << "";
			cout << " | ";
			cout << setw((7 - 5) / 2 + 5) << right << setfill(' ') << "Total";
			cout << setw(1) << right << setfill(' ') << "";
			cout << " | ";
			cout << endl;
			cout << setw(121) << setfill('=') << "=" << endl;
			while(j<i) {
			cout << "| ";
			cout << setw(2) << left << setfill(' ') << j + 1;
			cout << " | ";
			cout << setw(16) << left << setfill(' ') << penyewa[j].nama;
			cout << " | ";
			cout << setw(20) << left << setfill(' ') << penyewa[j].alamat;
			cout << " | ";
			cout << setw(13) << left << setfill(' ') << penyewa[j].nomor;
			cout << " | ";
			cout << setw(33) << left << setfill(' ') << penyewa[j].kamera1;
			cout << " | ";
			cout << setw(8) << left << setfill(' ') << penyewa[j].hari;
			cout << " | ";
			cout << setw(7) << left << setfill(' ') << penyewa[j].total;
			cout << " |\n";
			j++;
			}
			cout << setw(121) << setfill('=') << "=" << endl;

			j=0;
			ofstream splfile(namafile[0], ios::app);
			if (splfile.is_open()) {
				while (j < split) {
					splfile << penyewa[j].nama << ',' << penyewa[j].alamat << ',' << penyewa[j].nomor << ',' << penyewa[j].kamera2 << ',' << penyewa[j].kamera1 << ',' << penyewa[j].hari << ',' << penyewa[j].bayar << ',' << penyewa[j].total << endl;
					j++;
				}
				splfile.close();
			} else cout << "File gagal dibuka" << endl;

			ofstream spl2file(namafile[1], ios::app);
			if (spl2file.is_open()) {
				while (j < i) {
					spl2file << penyewa[j].nama << ',' << penyewa[j].alamat << ',' << penyewa[j].nomor << ',' << penyewa[j].kamera2 << ',' << penyewa[j].kamera1 << ',' << penyewa[j].hari << ',' << penyewa[j].bayar << ',' << penyewa[j].total << endl;
					j++;
				}
				spl2file.close();
			} else cout << "File gagal dibuka" << endl;
			cout << "File berhasil displit" << endl;
		}
		break;

	case 2: {
		cout << "Masukkan file yang ingin di merge" << endl;
		cout << "Masukkan nama file ke-1\t= ";
		cin >> namafile[0];
		baca(namafile[0]);
		tabel();
		cout << "Masukkan nama file ke-2\t= ";
		cin >> namafile[1];
		baca(namafile[1]);
		tabel();
		cout << "Masukkan nama hasil merging\t= ";
		cin >> namafile[2];

		baca(namafile[0]);
		merge(namafile[2]);
		baca(namafile[1]);
		merge(namafile[2]);
		cout << "File berhasil dimerge dan berikut hasil merging data" << endl;
		baca(namafile[2]);
		tabel();
	}
	break;
	case 3: {
		baca("rentalkamera.txt");
		tabel();
		cout << "Masukkan nama dari data yang ingin diupdate : ";
		getline(cin >> ws, cari);
		j = 0;
		while (j < i) {
			if (penyewa[j].nama == cari) {
				cout << "Data ditemukan & berikut detail data dari " << cari << endl;
				cout << "Nama\t\t: " << penyewa[j].nama << endl;
				cout << "Alamat\t\t: " << penyewa[j].alamat << endl;
				cout << "Nomor Telp\t: " << penyewa[j].nomor << endl;
				cout << "--------------Detail pesanan---------------------" << endl;
				cout << "Kamera\t\t: " << penyewa[j].kamera2 << endl;
				cout << "Merk\t\t: " << penyewa[j].kamera1 << endl;
				cout << "Lama menyewa\t: " << penyewa[j].hari << " hari" << endl;
				cout << "Total yang harus dibayarkan\t: Rp." << penyewa[j].total << endl;
				cout << "Uang yang anda bayarkan\t\t: Rp." << penyewa[j].bayar << endl;
				cout << "Kembalian Anda\t\t\t: Rp." << penyewa[j].bayar - penyewa[j].total << endl;
				system("pause");
				system("cls");
				header();
				cout << "-------Edit Identitas Perental Kamera---------" << endl;
				cout << "Masukan Nama Anda                 : ";
				cin.ignore();
				getline(cin, penyewa[j].nama);
				cout << "Masukan Alamat Anda               : ";
				getline(cin, penyewa[j].alamat);
				cout << "Masukan Nomor HP Anda             : ";
				getline(cin, penyewa[j].nomor);
				cout << "---------------------------------------------" << endl;
				listkamera();
				cout << "Masukkan pilihan\t: ";
				cin >> penyewa[j].kamera2;
				cout << "Lama menyewa\t\t: ";
				cin >> penyewa[j].hari;
				switch (penyewa[j].kamera2) {
					case 1:
						penyewa[j].total = penyewa[j].hari * gopro;
						penyewa[j].kamera1 = "Gopro";
						break;

					case 2:
						penyewa[j].total = penyewa[j].hari * xiaomi;
						penyewa[j].kamera1 = "Xiaomi Yi Cam";
						break;

					case 3:
						penyewa[j].total = penyewa[j].hari * dslrc;
						penyewa[j].kamera1 = "DSLR CANON 1000D + Lensa 18-55mm";
						break;

					case 4:
						penyewa[j].total = penyewa[j].hari * dslr;
						penyewa[j].kamera1 = "DDSLR CANON 500D + Lensa 18-55mm";
						break;

					case 5:
						penyewa[j].total = penyewa[j].hari * ce;
						penyewa[j].kamera1 = "CANON EOS 1100D + LENSA18-55mm";
						break;

					case 6:
						penyewa[j].total = penyewa[j].hari * ced;
						penyewa[j].kamera1 = "CANON EOS 450D + LENSA18-55mm";
						break;

					case 7:
						penyewa[j].total = penyewa[j].hari * nikon;
						penyewa[j].kamera1 = "DSLR NIKON D3000+ Lensa 18-55mm";
						break;

					case 8:
						penyewa[j].total = penyewa[j].hari * nikond;
						penyewa[j].kamera1 = "DSLR NIKON D80 + Lensa 18-55mm";
						break;
				}
				cout << "Total yang harus dibayar: Rp." << penyewa[j].total << endl;
				cout << "Uang yang Anda bayarkan : Rp.";
				cin >> penyewa[j].bayar;
				if(penyewa[j].bayar<penyewa[j].total){
					cout<<"Uang Anda kurang"<<endl;
					}
				while(kurang == true){
				if(penyewa[j].bayar<penyewa[j].total){
					cout << "Uang yang Anda bayarkan : Rp.";
					cin >> penyewa[j].bayar;
					kurang = true;
					}
				if(penyewa[j].bayar<penyewa[j].total){
					cout<<"Uang Anda kurang"<<endl;
					}
				else kurang = false;
				}

				cout << "Kembalian Anda\t\t: Rp." << penyewa[j].bayar - penyewa[j].total << endl;
				found = true;
				j++;
			} else {
				j++;
			}
		}
		if (found) {
			j = 0;
			cout << "Nama file baru yang sudah diupdate = ";
			cin >> namafile[3];
			cout << "File berhasil diupdate" << endl;
			ofstream ufile(namafile[3]);
			if (ufile.is_open()) {
				while (j < i) {
					ufile << penyewa[j].nama << ',' << penyewa[j].alamat << ',' << penyewa[j].nomor << ',' << penyewa[j].kamera2 << ',' << penyewa[j].kamera1 << ',' << penyewa[j].hari << ',' << penyewa[j].bayar << ',' << penyewa[j].total << endl;
					j++;
				}
				ufile.close();
			} else cout << "File tidak ada" << endl;
		} else cout << "Data tidak ditemukan";
		baca(namafile[3]);
		tabel();
	}
	break;
	default:
		cout << "Pilihan tidak ada dalam menu" << endl;
	}
	system("pause");
	system("cls");
	main();
}

void tabel() {
	cout << setw(122) << setfill('=') << "=" << endl;
	cout << "| ";
	cout << setw((2 - 2) / 2 + 2) << right << setfill(' ') << "No";
	cout << setw(0) << right << setfill(' ') << "";
	cout << " | ";
	cout << setw((16 - 4) / 2 + 4) << right << setfill(' ') << "Nama";
	cout << setw(6) << right << setfill(' ') << "";
	cout << " | ";
	cout << setw((20 - 6) / 2 + 6) << right << setfill(' ') << "Alamat";
	cout << setw(7) << right << setfill(' ') << "";
	cout << " | ";
	cout << setw((14 - 7) / 2 + 7) << right << setfill(' ') << "No Telp";
	cout << setw(4) << right << setfill(' ') << "";
	cout << " | ";
	cout << setw((33 - 7) / 2 + 7) << right << setfill(' ') << "Kamera";
	cout << setw(13) << right << setfill(' ') << "";
	cout << " | ";
	cout << setw((8 - 4) / 2 + 4) << right << setfill(' ') << "Lama";
	cout << setw(2) << right << setfill(' ') << "";
	cout << " | ";
	cout << setw((7 - 5) / 2 + 5) << right << setfill(' ') << "Total";
	cout << setw(1) << right << setfill(' ') << "";
	cout << " | ";
	cout << endl;
	cout << setw(122) << setfill('=') << "=" << endl;
	for (int j = 0; j < i; j++) {
		cout << "| ";
		cout << setw(2) << left << setfill(' ') << j + 1;
		cout << " | ";
		cout << setw(16) << left << setfill(' ') << penyewa[j].nama;
		cout << " | ";
		cout << setw(20) << left << setfill(' ') << penyewa[j].alamat;
		cout << " | ";
		cout << setw(14) << left << setfill(' ') << penyewa[j].nomor;
		cout << " | ";
		cout << setw(33) << left << setfill(' ') << penyewa[j].kamera1;
		cout << " | ";
		cout << setw(8) << left << setfill(' ') << penyewa[j].hari;
		cout << " | ";
		cout << setw(7) << left << setfill(' ') << penyewa[j].total;
		cout << " |\n";
	}
	cout << setw(121) << setfill('=') << "=" << endl;
}
