//DANH SACH DOI TUONG SINH VIEN 1
#include<iostream>
#include<string>
#include<ostream>
#include<fstream>
#include<iomanip>
#include<cmath>
using namespace std;
int maSV = 1;
string taoMa(int &maSV) {
	string temp = "B20DCCN000";
	string ma;
	int i = maSV;
	int soChuSo = 0;
	while (i > 0) {
		soChuSo++;
		i /= 10;
	}
	if (maSV < pow(10, soChuSo)) ma = temp.replace(temp.length() - soChuSo, soChuSo, to_string(maSV));
	maSV++;
	return ma;
}
void chuanHoaNgay(string& ngay) {
	if (ngay.substr(0, ngay.find('/')).length() < 2) ngay = "0" + ngay;
	if (ngay.substr(0, ngay.find_last_of('/')).length() < 5) ngay.insert(ngay.find_last_of('/') - 1, "0");
	return;
}
class SinhVien {
private:
	string ma;
	string hoTen;
	string lop;
	string ngaySinh;
	float diemGPA;
public:
	SinhVien();
	friend istream& operator>>(istream&, SinhVien&);
	friend ostream& operator<<(ostream&, SinhVien);

};
SinhVien::SinhVien() {
	ma = "";
	hoTen = "";
	lop = "";
	ngaySinh = "";
	diemGPA = 0;
}
istream& operator>>(istream&is, SinhVien& sv) {
	cin.ignore();
	sv.ma = taoMa(maSV);
	getline(is, sv.hoTen);
	getline(is, sv.lop);
	getline(is, sv.ngaySinh);
	chuanHoaNgay(sv.ngaySinh);
	cin >> sv.diemGPA;
	return is;
}
ostream& operator<<(ostream& os, SinhVien sv) {
	os << sv.ma << " " << sv.hoTen << " " << sv.lop << " " << sv.ngaySinh << " ";
	os <<setprecision(2)<<fixed<< sv.diemGPA << endl;
	return os;
}
int main() {
	SinhVien ds[50];
	int N, i;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> ds[i];
	}
	for (i = 0; i < N; i++) {
		cout << ds[i];
	}
	return 0;
}
