#pragma once
#include"ctdl.h"

// ========================== VẬT TƯ ==========================
void them_vat_tu(DSVT &ds_vt);
void xoa_vat_tu(string ma_vt_xoa, DSVT &ds_vt);
void cap_nhat_vat_tu(string ma_vt_cap_nhat, DSVT &ds_vt);
string tao_ma_vt(DSVT ds_vt);
int kt_trung_ma_vt(string a, DSVT ds_vt);
void Ket_Xuat_vat_tu();
void xuat_ds_vt(DSVT ds_vt);
void doc_file_vat_tu(DSVT &ds_vt);

// ================ chuẩn hoá chuỗi ================
void chuan_hoa_chu(string &a);
// ========================== NHÂN VIÊN ==========================
int kt_trung_ma_nv(tree t, int ma_nv);
int tao_ma_nhan_vien(DS_NHAN_VIEN ds_nv);
void Nhap_du_lieu_nhan_vien(DS_NHAN_VIEN &ds_nv);
void them_Nhan_vien(tree &t, node_nhan_vien *p);
void tieu_de_nv();
void tim_node_the_mang(node_nhan_vien *k, tree &t); // k = k->pLeft;
void xoa_Nhan_Vien(tree &t, int ma_nv);
void chuyen_cay_thanh_mang(tree t, NHAN_VIEN *ds[], int &nds);
void in_ds_nv(NHAN_VIEN *ds[], int &nds);
void swap_nhan_vien(NHAN_VIEN *a, NHAN_VIEN *b);
void sap_xep_ds_sinh_vien_theo_thu_tu_alphabet_cua_1_lop(NHAN_VIEN *ds[], int nds);
void cap_nhat_nhan_vien(tree &t, int ma_nv);
void load_file_nhan_vien(DS_NHAN_VIEN &ds_nv);
string ngay_thang_nam_hien_tai();

// ============================= HOÁ ĐƠN ==============================
node_nhan_vien *kiem_tra_ma_nv(tree t, int ma_nv);
void Lap_Hoa_Don(DS_NHAN_VIEN &ds_nv, DSVT &ds_vt);
string tao_ma_hd(DS_HOA_DON ds_hd);
bool kt_trung_ma_hd(DS_HOA_DON ds_hd, string ma_hd);
void them_1_hd(DS_HOA_DON &l, node_hoa_don *p);
node_hoa_don *khoi_tao_node_hoa_don();
void cap_nhat_sl_vat_tu_vua_moi_nhap_vao_tu_hoa_don(DSVT &ds_vt, DS_CHI_TIET_HOA_DON &ds_chi_tiet_hd);
void xoa_ma_vt_trong_chi_tiet_hd(DS_CHI_TIET_HOA_DON &ds_ch_tiet_hd, string ma_vt_xoa, int &check);
void xem_ds_hd_chi_tiet_vua_moi_lap(DS_CHI_TIET_HOA_DON ds_ct_hd);
int kt_ma_vt_co_ton_tai_trong_ds_chi_tiet_hd(DS_CHI_TIET_HOA_DON &ds_ct_hd, string ma_vt);
void cap_nhat_sl_vat_tu_trong_kho_vua_moi_tra_cho_nha_san_xuat(DSVT &ds_vt, DS_CHI_TIET_HOA_DON &ds_chi_tiet_hd);
float tong_tien_khach_hang_phai_tra(DS_CHI_TIET_HOA_DON ds_ct_hd);
void tim_kiem_ma_hd_khach_hang_da_mua(tree t, string ma_hd, int &check_ma_hd, node_hoa_don *&vt_hd_trong_ds_nv);
void xuat_toan_bo_hd(tree t);
void In_1_hoa_don(tree t, string so_hd, int &check_hd);
int kt_ngay_tra_hang(string ngay_tra, string ngay_mua);
int rdn(int y, int m, int d);
void Liet_ke_hoa_don_do_1_nv_lap_trong_khoang_1_tg(DS_NHAN_VIEN ds_nv);
int kc_giua_2_ngay(string ngay_tra, string ngay_mua);
int kt_trung_thang_nam(string ngay_tra, string ngay_mua);
void Doanh_thu_1_thang(tree t, string thang_nam_de_so_sanh, float &tong_doanh_thu_1_thang);
void Thong_ke_doanh_thu_1_nam(DS_NHAN_VIEN ds_nv, string nam);

// =================================================================================================
// câu a: Nhập vật tư : cho phép cập nhật (thêm / xóa / hiệu chỉnh ) thông tin của vật tư; riêng số
// lượng tồn chỉ cho phép nhập khi đó là vật tư mới thêm.


// thêm vật tư
void them_vat_tu(DSVT &ds_vt)
{
	VAT_TU *p = new VAT_TU;
	cin.ignore();
	p->ma_vt = tao_ma_vt(ds_vt);
	cout << "Nhap ten vat tu: ";
	getline(cin, p->ten_vt);
	chuan_hoa_chu(p->ten_vt);
	cout << "Nhap don vi tinh: ";
	getline(cin, p->don_vi_tinh);
	cout << "Nhap so luong ton: ";
	cin >> p->so_luong_ton;
	ds_vt.ds[ds_vt.sl++] = p;
}
// tạo mã vật tư
string tao_ma_vt(DSVT ds_vt)
{
	string a = "VT000";
	do
	{
		for (int i = 2; i < a.length(); i++)
		{
			a[i] = rand() % (57 - 48 + 1) + 48;
		}
	} while(kt_trung_ma_vt(a,ds_vt) != -1);
	
	return a;
}
// kiểm tra trùng mã vật tư
int kt_trung_ma_vt(string a, DSVT ds_vt)
{
	for (int i = 0; i < ds_vt.sl; i++)
	{
		if (_stricmp(a.c_str(), ds_vt.ds[i]->ma_vt.c_str()) == 0)
		{
			return i;
		}
	}
	return -1;
}
// xoá vật tư
void xoa_vat_tu(string ma_vt_xoa,DSVT &ds_vt)
{
	// tìm ra vị trí của vật từ cần xoá
	int vt;
	for (vt = 0; vt < ds_vt.sl; vt++)
	{
		if (_stricmp(ds_vt.ds[vt]->ma_vt.c_str(),ma_vt_xoa.c_str()) == 0)
		{
			for (int i = vt; i < ds_vt.sl - 1; i++)
			{
				ds_vt.ds[i] = ds_vt.ds[i + 1];
			}
			ds_vt.sl--;
			break;
		}
	}
}

// cập nhật vật tư
void cap_nhat_vat_tu(string ma_vt_cap_nhat,DSVT &ds_vt)
{
	// tìm ra vị trí của vật từ cần xoá
	int vt;
	for (vt = 0; vt < ds_vt.sl; vt++)
	{
		if (_stricmp(ds_vt.ds[vt]->ma_vt.c_str(), ma_vt_cap_nhat.c_str()) == 0)
		{
			// cho xem thông tin vật tư cũ
			cout << "\n\tThong tin cu \n";
			cout << "Ma vat tu: " << ds_vt.ds[vt]->ma_vt << endl;
			cout << "Ten vat tu: " << ds_vt.ds[vt]->ten_vt << endl;
			cout << "Don vi tinh: " << ds_vt.ds[vt]->don_vi_tinh << endl;
			cout << "So luong ton: " << ds_vt.ds[vt]->so_luong_ton << endl;
			// cập nhật lại thông tin của vật tư không cho cập nhật số luọng tồn
			cout << "\n\tCap nhat lai thong tin \n";
			cout << "Nhap ten vat tu: ";
			getline(cin, ds_vt.ds[vt]->ten_vt);
			cout << "Nhap don vi tinh: ";
			getline(cin, ds_vt.ds[vt]->don_vi_tinh);
		}
	}
}

void Ket_Xuat_vat_tu()
{
	cout << setw(20) << "Ma VT";
	cout << setw(20) << "Ten vat tu";
	cout << setw(20) << "Don vi tinh";
	cout << setw(20) << "So luong";
	cout << endl;
}
void xuat_ds_vt(DSVT ds_vt)
{
	Ket_Xuat_vat_tu();
	for (int i = 0; i < ds_vt.sl; i++)
	{
		cout << setw(20) << ds_vt.ds[i]->ma_vt;
		chuan_hoa_chu(ds_vt.ds[i]->ten_vt);
		cout << setw(20) << ds_vt.ds[i]->ten_vt;
		cout << setw(20) << ds_vt.ds[i]->don_vi_tinh;
		cout << setw(20) << ds_vt.ds[i]->so_luong_ton;
		cout << endl;
	}
}
// đọc file danh sách vật tự
void doc_file_vat_tu(DSVT &ds_vt)
{
	ifstream Fi;
	Fi.open("ds_vat_tu.txt");
	while (!Fi.eof())
	{
		VAT_TU *p = new VAT_TU;
		getline(Fi, p->ma_vt,',');
		getline(Fi, p->ten_vt, ',');
		getline(Fi, p->don_vi_tinh, ',');
		Fi >> p->so_luong_ton;
		Fi.ignore();
		ds_vt.ds[ds_vt.sl++] = p;
	}
	Fi.close();
}
void menu()
{
	DSVT ds_vt;
	DS_NHAN_VIEN ds_nv;
	// load file
	doc_file_vat_tu(ds_vt);
	load_file_nhan_vien(ds_nv);
	// play
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ============== QUAN LI VAT TU =================\n";
		cout << "\n\t1. Nhap vat tu";
		cout << "\n\t2. Xuat danh sach vat tu";
		cout << "\n\t3. Nhap nhan vien";
		cout << "\n\t4. Xuat danh sach nhan vien";
		cout << "\n\t5. Lap hoa don"; // câu e, câu f
		cout << "\n\t6. In danh sach hoa don theo nhan vien da lap"; // Phân quyền cấp quản lí trở lên mới có chức năng này
		cout << "\n\t7. In mot hoa don"; // câu g
		cout << "\n\t8. Liet ke hoa don do 1 nhan vien lap trong khoang thoi gian"; // câu h
		cout << "\n\t9. Thong ke doanh thu 1 nam"; // câu i
		cout << "\n\t0. Thoat";
		cout << "\n\t  ====================================================";
		int lc;
		cout << "\n\tNhap lua chon: ";
		cin >> lc;
		if (lc == 0)
		{
			break;
		}
		else if (lc == 1)
		{
			system("cls");
			cout << "\n\t1. Them vat tu: ";
			cout << "\n\t2. Xoa vat tu: ";
			cout << "\n\t3. Cap nhat vat tu: ";
			cout << "\n\tNhap lua chon: ";
			int select; // lựa chọn để thêm, xoá hoặc hiệu chỉnh vật tư
			cin >> select;
			if (select == 1) // thêm vật tư
			{
				int sl;
				cout << "\n\tNhap so luong vat tu can them: ";
				cin >> sl;
				for (int i = 0; i < sl; i++)
				{
					cout << "\n\t Nhap vat tu\n";
					them_vat_tu(ds_vt);	
				}
			}
			// xoá vật tư
			if (select == 2)
			{
				cin.ignore();
				cout << "Nhap ma vat tu muon xoa: ";
				string ma_vt_xoa;
				getline(cin, ma_vt_xoa);
				xoa_vat_tu(ma_vt_xoa, ds_vt);
			}
			// cập nhật vật tư
			if (select == 3)
			{
				cin.ignore();
				cout << "Nhap ma vat tu muon cap nhat: ";
				string ma_vt_cap_nhat;
				getline(cin, ma_vt_cap_nhat);
				cap_nhat_vat_tu(ma_vt_cap_nhat, ds_vt);
			}
		}
		else if (lc == 2)
		{
			system("cls");
			xuat_ds_vt(ds_vt);
			system("pause");
		}
		else if (lc == 3)
		{
			system("cls");
			cout << "\n\t1. Them nhan vien: ";
			cout << "\n\t2. Xoa nhan vien: ";
			cout << "\n\t3. Cap nhat nhan vien: ";
			cout << "\n\tNhap lua chon: ";
			int select; // lựa chọn để thêm, xoá hoặc hiệu chỉnh vật tư
			cin >> select;
			if (select == 1) // thêm nhân viên
			{
				int sl;
				cout << "\n\tNhap so luong nhan vien can them: ";
				cin >> sl;
				cin.ignore();
				for (int i = 0; i < sl; i++)
				{
					cout << "\n\t Nhap nhan vien\n";
					Nhap_du_lieu_nhan_vien(ds_nv);
				}
			}
			// xoá nhân viên
			else if (select == 2)
			{
				int ma_nv;
				cout << "Nhap ma nhan vien can xoa: ";
				cin >> ma_nv;
				if (kt_trung_ma_nv(ds_nv.t, ma_nv) == 1)
				{
					xoa_Nhan_Vien(ds_nv.t, ma_nv);
					cout << "\n\tDa xoa nhan vien co ma " << ma_nv;
					ds_nv.sl--;
					system("pause");
				}
				else
				{
					cout << "\n\tKhong ton tai ma nhan vien " << ma_nv;
					system("pause");
				}
			}
			// cập nhật nhân viên
			else if (select == 3)
			{
				int ma_nv;
				cout << "Nhap ma nhan vien can cap nhat: ";
				cin >> ma_nv;
				if (kt_trung_ma_nv(ds_nv.t, ma_nv) == 1)
				{
					cin.ignore();
					cap_nhat_nhan_vien(ds_nv.t, ma_nv);
				}
				else
				{
					cout << "\n\tKhong ton tai ma nhan vien " << ma_nv;
					system("pause");
				}
			}
		}
		else if (lc == 4)
		{
			system("cls");
			tieu_de_nv();
			NHAN_VIEN *ds[100];	
			int nds = 0;
			chuyen_cay_thanh_mang(ds_nv.t, ds, nds);
			in_ds_nv(ds, nds);
			system("pause");
		}
		else if (lc == 5)
		{
			Lap_Hoa_Don(ds_nv,ds_vt);
			system("pause");
		}
		else if (lc == 6)
		{
			cout << "\n\n\t\tBANG LIET KE HOA DON CUA TAT CA NHAN VIEN\n";
			xuat_toan_bo_hd(ds_nv.t);
			system("pause");
		}
		else if (lc == 7)
		{
			cin.ignore();
			string so_h_d;
			cout << "\nNhap ma so hoa don: ";
			getline(cin, so_h_d);
			int check_hd = 0;
			In_1_hoa_don(ds_nv.t, so_h_d, check_hd);
			if (check_hd == 0)
			{
				cout << "\n\tKhong ton tai ma so hoa don " << so_h_d;
			}
			system("pause");
		}
		else if (lc == 8)
		{
			Liet_ke_hoa_don_do_1_nv_lap_trong_khoang_1_tg(ds_nv);
			system("pause");
		}
		else if (lc == 9)
		{
			cin.ignore();
			string nam_tk;
			cout << "\nNhap nam muon thong ke: ";
			getline(cin, nam_tk);
			system("cls");
			Thong_ke_doanh_thu_1_nam(ds_nv, nam_tk);
			system("pause");
		}
	}
}

void chuan_hoa_chu(string &a)
{
	// xứ lí kí tự đầu
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	// xử lí kí tự cuối
	while (a[a.length() - 1] == ' ')
	{
		a.erase(a.begin() + a.length() - 1);
	}
	// xoá kí tự giữa
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(a.begin() + i + 1);
			i--;
		}
	}
	// chuẩn hoá kí tự
	if (a[0] >= 97 && a[0] <= 122)
	{
		a[0] -= 32;
	}
	for (int i = 1; i < a.length(); i++)
	{
		if ((a[i] >= 97 && a[i] <= 122) && a[i - 1] == ' ')
		{
			a[i] -= 32;
		}
		else 
		{
			if (a[i] >= 65 && a[i] <= 90)
			{
				a[i] += 32;
			}
		}
	}
}

// c/ Nhập nhân viên: Cập nhập (thêm / xóa / hiệu chỉnh ) các nhân viên dựa vào mã nhân
// viên, họ, tên không được rỗng.

void Nhap_du_lieu_nhan_vien(DS_NHAN_VIEN &ds_nv)
{
	node_nhan_vien *p = new node_nhan_vien;
	p->pLeft = NULL;
	p->pRight = NULL;
	do
	{
		cout << "Nhap ho: ";   getline(cin, p->data.ho);
	} while (p->data.ho.empty());
	chuan_hoa_chu(p->data.ho);
	do
	{
		cout << "Nhap ten: ";  getline(cin, p->data.ten); 
	} while (p->data.ten.empty());
	chuan_hoa_chu(p->data.ten);
	cout << "Nhap phai: "; getline(cin, p->data.phai);
	//nếu quản lí nhân sự không nhập phái thì mặc định là nam
	if (p->data.phai.empty())
	{
		p->data.phai = "nam";
	}
	p->data.ma_nv = tao_ma_nhan_vien(ds_nv);
	them_Nhan_vien(ds_nv.t, p);
	ds_nv.sl++;
}
// thêm nhân viên
void them_Nhan_vien(tree &t, node_nhan_vien *p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (t->data.ma_nv > p->data.ma_nv)
		{
			them_Nhan_vien(t->pLeft, p);
		}
		else if (t->data.ma_nv < p->data.ma_nv)
		{
			them_Nhan_vien(t->pRight, p);
		}
	}
}
// tạo mã nhân viên
int tao_ma_nhan_vien(DS_NHAN_VIEN ds_nv)
{
	int ma; // 100 - 999
	do
	{
		ma = rand() % (999 - 100 + 1) + 100;
	} while (kt_trung_ma_nv(ds_nv.t,ma) == 1);
	return ma;
}
void load_file_nhan_vien(DS_NHAN_VIEN &ds_nv)
{
	ifstream FileIn;
	FileIn.open("nhanvien.txt");
	while (!FileIn.eof())
	{
		node_nhan_vien *p = new node_nhan_vien;
		p->pLeft = NULL;
		p->pRight = NULL;
		FileIn >> p->data.ma_nv;
		FileIn.ignore();
		getline(FileIn, p->data.ho, ',');
		getline(FileIn, p->data.ten, ',');
		getline(FileIn, p->data.phai);
		them_Nhan_vien(ds_nv.t, p);
		ds_nv.sl++;
	}
	FileIn.close();
}
int kt_trung_ma_nv(tree t, int ma_nv)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		if (t->data.ma_nv == ma_nv)
		{
			return 1;
		}
		else if (t->data.ma_nv > ma_nv)
		{
			kt_trung_ma_nv(t->pLeft, ma_nv);
		}
		else
		{
			kt_trung_ma_nv(t->pRight, ma_nv);
		}
	}
}

// ================ in danh sách nhân viên theo tên tăng dần ========================
void chuyen_cay_thanh_mang(tree t,NHAN_VIEN *ds[],int &nds)
{
	if (t != NULL)
	{
		ds[nds] = new NHAN_VIEN;
		ds[nds]->ma_nv = t->data.ma_nv;
		ds[nds]->ho = t->data.ho;
		ds[nds]->ten = t->data.ten;
		ds[nds]->phai = t->data.phai;
		nds++;
		chuyen_cay_thanh_mang(t->pLeft, ds, nds);
		chuyen_cay_thanh_mang(t->pRight, ds, nds);
	}
	sap_xep_ds_sinh_vien_theo_thu_tu_alphabet_cua_1_lop(ds, nds);
}
void in_ds_nv(NHAN_VIEN *ds[], int &nds)
{
	for (int i = 0; i < nds; i++)
	{
		cout << setw(12) << ds[i]->ma_nv;
		cout << setw(23) << ds[i]->ho << " " << ds[i]->ten;
		cout << setw(27) << ds[i]->phai << endl;
	}
}

void sap_xep_ds_sinh_vien_theo_thu_tu_alphabet_cua_1_lop(NHAN_VIEN *ds[], int nds)
{
	// sắp xếp danh sách theo tên
	for (int i = 0; i < nds - 1; i++)
	{
		for (int j = i + 1; j < nds; j++)
		{
			if (_stricmp(ds[i]->ten.c_str(), ds[j]->ten.c_str()) > 0)
			{
				swap_nhan_vien(ds[i], ds[j]);
			}
			if (_stricmp(ds[i]->ten.c_str(), ds[j]->ten.c_str()) == 0)
			{
				if (_stricmp(ds[i]->ho.c_str(), ds[j]->ho.c_str()) > 0)
				{
					swap_nhan_vien(ds[i], ds[j]);
				}
			}
		}
	}
}
void swap_nhan_vien(NHAN_VIEN *a, NHAN_VIEN *b)
{
	NHAN_VIEN *tam = new NHAN_VIEN;
	tam->ho = a->ho;
	tam->ten = a->ten;
	tam->ma_nv = a->ma_nv;
	tam->phai = a->phai;

	a->ho = b->ho;
	a->ten = b->ten;
	a->ma_nv = b->ma_nv;
	a->phai = b->phai;

	b->ho = tam->ho;
	b->ten = tam->ten;
	b->ma_nv = tam->ma_nv;
	b->phai = tam->phai;
}
void tieu_de_nv()
{
	cout << setw(20) << "Ma nhan vien";
	cout << setw(20) << "Ho va ten";
	cout << setw(30) << "Phai";
	cout << endl;
}
// xoá nhân viên
void xoa_Nhan_Vien(tree &t, int ma_nv)
{
	if (t != NULL)
	{
		if (t->data.ma_nv == ma_nv)
		{
			// node lá
			if (t->pLeft == NULL && t->pRight == NULL)
			{
				delete t;
				t = NULL;
			}
			// node có 1 con
			else if (t->pLeft == NULL && t->pRight != NULL)
			{
				node_nhan_vien *tam = t;
				t = t->pRight;
				delete tam;
			}
			else if (t->pLeft != NULL && t->pRight == NULL)
			{
				node_nhan_vien *tam = t;
				t = t->pLeft;
				delete tam;
			}
			// node có 2 con
			else
			{
				tim_node_the_mang(t->pLeft, t);
			}
		}
		else if (t->data.ma_nv > ma_nv)
		{
			xoa_Nhan_Vien(t->pLeft, ma_nv);
		}
		else if (t->data.ma_nv < ma_nv)
		{
			xoa_Nhan_Vien(t->pRight, ma_nv);
		}
	}
}
// tìm node phải nhất của cây con trái
void tim_node_the_mang(node_nhan_vien *k, tree &t) // k = k->pLeft
{
	if (k->pRight == NULL)
	{
		t->data.ma_nv = k->data.ma_nv;
		t->data.ho = k->data.ho;
		t->data.ten = k->data.ten;
		t->data.phai = k->data.phai;
		node_nhan_vien *tam = k;
		k = k->pLeft;
		delete tam;
	}
	else
	{
		tim_node_the_mang(k->pRight, t);
	}
}

// cập nhật nhân viên
void cap_nhat_nhan_vien(tree &t, int ma_nv)
{
	if (t != NULL)
	{
		if (t->data.ma_nv == ma_nv)
		{
			// cho xem thông tin cũ của nhân viên đó
			cout << "Ma nhan vien: " << t->data.ma_nv << endl;
			cout << "Ho va ten: " << t->data.ho << " " << t->data.ten << endl;
			cout << "Phai: " << t->data.phai << endl;
			// cập nhật lại thông tin nhân viên
			cout << "\n\tCap nhat lai thong tin nhan vien\n";
			do
			{
				cout << "Nhap ho: "; getline(cin, t->data.ho);

			} while (t->data.ho.empty());
			chuan_hoa_chu(t->data.ho);
			do
			{
				cout << "Nhap ten: "; getline(cin, t->data.ten);

			} while (t->data.ten.empty());
			chuan_hoa_chu(t->data.ten);
			cout << "Nhap phai: "; getline(cin, t->data.phai);
			return;
		}
		else if (t->data.ma_nv > ma_nv)
		{
			cap_nhat_nhan_vien(t->pLeft, ma_nv);
		}
		else
		{
			cap_nhat_nhan_vien(t->pRight, ma_nv);
		}
	}
}
/*
e / Lập hóa đơn nhập / Lập hóa đơn xuất : nhập vào số hóa đơn, ngày lập, loại(chỉ nhận ký
	tự N hoặc X).Sau đó, tiếp tục cho phép nhập các vật tư của hóa đơn đó; Căn cứ vào loại
	hóa đơn, chương trình sẽ tự động cập nhật số lượng tồn.
	Lưu ý : -Nếu số lượng xuất không đủ hàng thì báo lỗi và in ra số lượng tồn hiện có trongkho;
	-Chỉ được phép xóa vật tư đang lập của hóa đơn hiện tại.Khi hóa đơn đã ghi thì
	không được xóa các vật tư trong hóa đơn
*/
void Lap_Hoa_Don(DS_NHAN_VIEN &ds_nv,DSVT &ds_vt)
{
	int ma_nv;
	cout << "Nhap ma nhan vien: ";
	cin >> ma_nv;
	node_nhan_vien *tam = kiem_tra_ma_nv(ds_nv.t, ma_nv);
	if (tam == NULL)
	{
		cout << "\n\tKhong co ma nhan vien " << ma_nv;
	}
	else
	{
		node_hoa_don *p = khoi_tao_node_hoa_don();
		while (true)
		{
			system("cls");
			cout << "\n\t1. Hoa don nhap";
			cout << "\n\t2. Hoa don xuat";
			int lc;
			cout << "\n\tNhap lua chon: ";
			cin >> lc;
			if (lc == 1)
			{
				cout << "\n\tLoai hoa don: Nhap\n";
				p->data.loai = 'N';
				break;
			}
			else if (lc == 2)
			{
				cout << "\n\tLoai hoa don: Xuat\n";
				p->data.loai = 'X';
				break;
			}
		}
		p->data.SOHD = tao_ma_hd(tam->data.ds_hd);
		cout << "So Hoa don " << p->data.SOHD << endl;
		cin.ignore();
		string nglap_hd;
		cout << "Nhap ngay lap hoa don: ";
		getline(cin, nglap_hd);
		if (nglap_hd.empty())
		{
			nglap_hd = ngay_thang_nam_hien_tai();
		}
		p->data.ngay_lap_hoa_don = nglap_hd;
		// thêm hoá đơn vào danh sách hoá đơn 
		them_1_hd(tam->data.ds_hd, p);
		cout << "Lap hoa don thanh cong! Nhan phim bat ki de tiep tuc lap chi tiet hoa don" << endl;
		system("pause");
		cout << "  So hoa don: " << p->data.SOHD << "   Ngay lap hoa don: " << p->data.ngay_lap_hoa_don << "   Loai Hoa Don: " << p->data.loai;
		system("pause");
		// ========= lập chi tiết hoá đơn ============
			// NHẬP : là bên xử lí của người trong công ty sẽ nhập hàng về trong kho nếu có hư hại thì sẽ trả hàng bên xử lí nhập
			// XUẤT : là xử lí của nhân viên sale có nhiệm vụ thao tác lập hoá đơn mua và trả hàng thao tác trên khách hàng
					 // 1: đã nhập, 2: đã trả  LOẠI HOÁ ĐƠN : NHẬP
					 // -1: khách mua  -2: khách trả  LOẠI HOÁ ĐƠN: XUẤT

		// hoá đơn nhập
		if (p->data.loai == 'N')
		{
				system("cls");
				cout << "\n\t1. Nhap hang ve kho";
				cout << "\n\t2. Tra hang ve cho nha san xuat\n\t-Luu y: Chi tra hang khi hang bi loi"; // trả hàng khi hàng bị lỗi
				int lc;
				cout << "\n\tNhap lua chon: ";
				cin >> lc;
				// nhập hàng
				if (lc == 1)
				{
					// =================== lần duyệt 1
					// cho xem danh sách các vật tư để biết mã để nhập hàng vào kho
					xuat_ds_vt(ds_vt);
					cout << "\nNhap so luong vat tu can them vao: ";
					int sl;
					cin >> sl;
					if (sl > 20)
					{
						cout << "\n\t Mot hoa don chi co toi da 20 vat tu";
					}
					for (int i = 0; i < sl; i++)
					{
						cin.ignore();
						cout << "\n\t Nhap vat tu \n";
						chi_tiet_hoa_don x;
						cout << "Nhap ma vat tu: ";
						getline(cin, x.ma_vt);
						cout << "Nhap so luong: ";
						cin >> x.sl;
						cout << "Nhap don gia: ";
						cin >> x.don_gia;
						x.VAT = (float)8 / 100;
						cout << "thue VAT: " << x.VAT;
						x.trang_thai = 1;
						cout << "\nTrang Thai: " << x.trang_thai << endl;
						tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.ds[tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.sl++] = x;
					}
					// ================ lần duyệt 2
					while (true)
					{
						cout << "\n\t1. Them so luong vat tu";
						cout << "\n\t2. Xoa vat tu dang o trong danh sach chi tiet hoa don";
						cout << "\n\t0. Thoat";
						int select;
						cout << "\n\tNhap lua chon: ";
						cin >> select;
						// thêm vật tư trong danh sách chi tiết hoá đơn
						if (select == 1)
						{
							int sl;
							cin >> sl;
							if (tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.sl + sl > 20)
							{
								cout << "\n\t Mot hoa don chi co toi da 20 vat tu";
							}
							for (int i = 0; i < sl; i++)
							{
								cin.ignore();
								chi_tiet_hoa_don x;
								cout << "Nhap ma vat tu: ";
								getline(cin, x.ma_vt);
								cout << "Nhap so luong: ";
								cin >> x.sl;
								cout << "Nhap don gia: ";
								cin >> x.don_gia;
								x.VAT = 8 / 100;
								cout << "thue VAT: " << x.VAT;
								x.trang_thai = 1;
								cout << "\nTrang Thai: " << x.trang_thai;
								tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.ds[tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.sl++] = x;
							}
						}
						// chỉ xoá đươc vật tư đang lập trong danh sách chi tiết hoá đơn
						else if (select == 2)
						{
							int check = 0; // dùng để kiểm tra xem mã vật tư có tồn tại
							cin.ignore();
							string ma_vt_xoa;
							cout << "Nhap ma vat tu can xoa: ";
							getline(cin, ma_vt_xoa);
							xoa_ma_vt_trong_chi_tiet_hd(tam->data.ds_hd.pTail->data.ds_chi_tiet_hd, ma_vt_xoa,check);
							if (check == 0)
							{
								cout << "\n\tKhong co ma vat tu " << ma_vt_xoa;
							}
							else if (check == 1)
							{
								cout << "\n\tDa xoa ma vat tu";
							}
						}
						else if (select == 0)
						{
							// cập nhật lại số lượng vật tư vừa mới nhập hàng
							cap_nhat_sl_vat_tu_vua_moi_nhap_vao_tu_hoa_don(ds_vt, tam->data.ds_hd.pTail->data.ds_chi_tiet_hd);
							break;
						}
					}
				}
				// trả hàng về nhà sản xuất do hàng bị lỗi	
				else if (lc == 2)
				{
					
					while (true)
					{
						system("cls");
						cout << "\n\t1. Nhap ma vat tu de tra hang";
						cout << "\n\t2. Thay doi so luong tra";
						cout << "\n\t3. Thoat";
						cout << "\n\tNhap lua chon: ";
						int select_;
						cin >> select_;
						if (select_ == 1)
						{
							cin.ignore();
							// cho xem danh sách vật tư
							xuat_ds_vt(ds_vt);
							chi_tiet_hoa_don x;
							do
							{
								cout << "\nNhap ma vat tu: ";
								getline(cin, x.ma_vt);
							} while (kt_trung_ma_vt(x.ma_vt, ds_vt) == -1);
							cout << "Nhap so luong: ";
							cin >> x.sl;
							cout << "Nhap don gia: ";
							cin >> x.don_gia;
							x.VAT = (float)8 / 100;
							cout << "thue VAT: " << x.VAT;
							x.trang_thai = 2;
							cout << "\nTrang Thai: " << x.trang_thai << endl;
							tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.ds[tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.sl++] = x;
						}
						else if (select_ == 2)
						{
							// cho xem ds chi tiết hoá đơn trong hoá đơn vừa lập
							xem_ds_hd_chi_tiet_vua_moi_lap(tam->data.ds_hd.pTail->data.ds_chi_tiet_hd);
							cout << "\n=================================================\n";
							cin.ignore();
							string ma_vt_update;
							cout << "\nNhap ma vat tu can cap nhat: ";
							getline(cin, ma_vt_update);
							if (kt_ma_vt_co_ton_tai_trong_ds_chi_tiet_hd(tam->data.ds_hd.pTail->data.ds_chi_tiet_hd, ma_vt_update) == -1)
							{
								
								cout << "\n\tKhong co ma vat tu nao nhu tren";
							}
							else
							{
								int vt_vat_tu_trong_chi_tiet_hoa_don = kt_ma_vt_co_ton_tai_trong_ds_chi_tiet_hd(tam->data.ds_hd.pTail->data.ds_chi_tiet_hd, ma_vt_update);
								cout << "Nhap so luong: ";
								cin >> tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.ds[vt_vat_tu_trong_chi_tiet_hoa_don].sl;
								cout << "Nhap don gia: ";
								cin >> tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.ds[vt_vat_tu_trong_chi_tiet_hoa_don].don_gia;
							}
							system("pause");
						}
						else if (select_ == 3)
						{
							cap_nhat_sl_vat_tu_trong_kho_vua_moi_tra_cho_nha_san_xuat(ds_vt, tam->data.ds_hd.pTail->data.ds_chi_tiet_hd);
							break;
						}
					}
				}
		}
		// hoá đơn xuất
		 // -1: khách mua  -2: khách trả  LOẠI HOÁ ĐƠN: XUẤT
		else if (p->data.loai = 'X')
		{
			system("cls");
			cout << "\n\t1. Khach mua";
			cout << "\n\t2. Khach tra hang";
			int select_;
			cout << "\n\tNhap lua chon: ";
			cin >> select_;
			if (select_ == 1)
			{
				while (true)
				{
					system("cls");
					int lc_mua;
					cout << "\n\t1. Mua hang";
					cout << "\n\t2. Thay doi chi vat tu trong danh sach mua hang";
					cout << "\n\t3. Xoa vat tu trong chi tiet hoa don dang lap";
					cout << "\n\t0. Thoat";
					cout << "\n\tNhap lua chon: ";
					cin >> lc_mua;
					if (lc_mua == 1)
					{
						// xem danh sách vật tư trong cửa hàng để khách lựa chọn
						xuat_ds_vt(ds_vt);
						cout << "\nNhap so luong vat tu can mua: ";
						int sl;
						cin >> sl;
						if (sl > 20 || tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.sl + sl > 20)
						{
							cout << "\n\t Mot hoa don chi co toi da 20 vat tu";
						}
						else
						{
							for (int i = 0; i < sl; i++)
							{
								cin.ignore();
								cout << "\n\t Nhap vat tu \n";
								chi_tiet_hoa_don x;
								do
								{
									cout << "\nNhap ma vat tu: ";
									getline(cin, x.ma_vt);
								} while (kt_trung_ma_vt(x.ma_vt, ds_vt) == -1);
								int vt_vat_tu = kt_trung_ma_vt(x.ma_vt, ds_vt);
								do
								{
									cout << "Nhap so luong: ";
									cin >> x.sl;

								} while (x.sl > ds_vt.ds[vt_vat_tu]->so_luong_ton);
								cout << "Nhap don gia: ";
								cin >> x.don_gia;
								x.VAT = (float)8 / 100;
								cout << "thue VAT: " << x.VAT;
								x.trang_thai = -1;
								cout << "\nTrang Thai: " << x.trang_thai << endl;
								tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.ds[tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.sl++] = x;
							}
						}
					}
					else if (lc_mua == 2)
					{
						// cho xem danh sách vật tư đang mua trong chi tiết hoá đơn
						xem_ds_hd_chi_tiet_vua_moi_lap(tam->data.ds_hd.pTail->data.ds_chi_tiet_hd);
						cout << "\n=================================================\n";
						cin.ignore();
						string ma_vt_update;
						cout << "\nNhap ma vat tu can cap nhat: ";
						getline(cin, ma_vt_update);
						if (kt_ma_vt_co_ton_tai_trong_ds_chi_tiet_hd(tam->data.ds_hd.pTail->data.ds_chi_tiet_hd, ma_vt_update) == -1)
						{

							cout << "\n\tKhong co ma vat tu nao nhu tren";
						}
						else
						{
							int vt_vat_tu_trong_ds_vt = kt_trung_ma_vt(ma_vt_update, ds_vt);
							int vt_vat_tu_trong_chi_tiet_hoa_don = kt_ma_vt_co_ton_tai_trong_ds_chi_tiet_hd(tam->data.ds_hd.pTail->data.ds_chi_tiet_hd, ma_vt_update);
							do
							{
								cout << "Nhap so luong: ";
								cin >> tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.ds[vt_vat_tu_trong_chi_tiet_hoa_don].sl;
							} while (tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.ds[vt_vat_tu_trong_chi_tiet_hoa_don].sl > ds_vt.ds[vt_vat_tu_trong_ds_vt]->so_luong_ton);
							cout << "Nhap don gia: ";
							cin >> tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.ds[vt_vat_tu_trong_chi_tiet_hoa_don].don_gia;
						}
						system("pause");
					}
					else if (lc_mua == 3)
					{
						xem_ds_hd_chi_tiet_vua_moi_lap(tam->data.ds_hd.pTail->data.ds_chi_tiet_hd);
						cout << "\n=================================================\n";
						int check = 0; // dùng để kiểm tra xem mã vật tư có tồn tại
						cin.ignore();
						string ma_vt_xoa;
						cout << "Nhap ma vat tu can xoa: ";
						getline(cin, ma_vt_xoa);
						xoa_ma_vt_trong_chi_tiet_hd(tam->data.ds_hd.pTail->data.ds_chi_tiet_hd, ma_vt_xoa, check);
						if (check == 0)
						{
							cout << "\n\tKhong co ma vat tu " << ma_vt_xoa;
						}
						else if (check == 1)
						{
							cout << "\n\tDa xoa ma vat tu";
						}
					}
					else if (lc_mua == 0)
					{
						cout << "\n\tTam tinh: " << tong_tien_khach_hang_phai_tra(tam->data.ds_hd.pTail->data.ds_chi_tiet_hd);
						cap_nhat_sl_vat_tu_trong_kho_vua_moi_tra_cho_nha_san_xuat(ds_vt, tam->data.ds_hd.pTail->data.ds_chi_tiet_hd);
						break;
					}
				}
				
			}
			else if (select_ == 2)
			{
				string ma_hd_vua_moi_lap = p->data.SOHD;
				cin.ignore();
				int check_ma_hd = 0;
				string ma_hd_khach_hang_mua;
				cout << "\n\tNhap so hoa don khach hang da mua: ";
				getline(cin, ma_hd_khach_hang_mua);
				cout << endl;
				if (_stricmp(ma_hd_vua_moi_lap.c_str(), ma_hd_khach_hang_mua.c_str()) == 0)
				{
					cout << "Loi: Hoa don cua khach hang trung voi hoa don vua moi tao";
					// xoá đi hoá đơn vừa được tạo ( xoá cuối dslk đơn)
					if (tam->data.ds_hd.pHead == tam->data.ds_hd.pTail)
					{
						node_hoa_don *p = new node_hoa_don;
						p = tam->data.ds_hd.pHead;
						tam->data.ds_hd.pHead = tam->data.ds_hd.pHead->pNext;
						delete p;
					}
					for (node_hoa_don *k = tam->data.ds_hd.pHead; k != NULL; k = k->pNext)
					{
						// phát hiện node cuối
						if (tam->data.ds_hd.pTail == k->pNext)
						{
							node_hoa_don *p = new node_hoa_don;
							p = tam->data.ds_hd.pTail;
							delete p;
							k->pNext = NULL;
							tam->data.ds_hd.pTail = k;
						}
					}
				}
				else
				{
					//  hoá đơn khách hàng muốn trả
					node_hoa_don *vt_hd_trong_ds_nv = new node_hoa_don;
					tim_kiem_ma_hd_khach_hang_da_mua(ds_nv.t, ma_hd_khach_hang_mua, check_ma_hd, vt_hd_trong_ds_nv);
					system("pause");
					if (check_ma_hd == 0)
					{
						
						cout << "\n\tKhong co so hoa don nao nhu tren";
						system("pause");
						if (tam->data.ds_hd.pHead == tam->data.ds_hd.pTail)
						{
							node_hoa_don *p = new node_hoa_don;
							p = tam->data.ds_hd.pHead;
							tam->data.ds_hd.pHead = tam->data.ds_hd.pHead->pNext;
							delete p;
						}
						// xoá đi hoá đơn vừa được tạo ( xoá cuối dslk đơn)
						for (node_hoa_don *k = tam->data.ds_hd.pHead; k != NULL; k = k->pNext)
						{
							// phát hiện node cuối
							if(tam->data.ds_hd.pTail == k->pNext)
							{
								node_hoa_don *p = new node_hoa_don;
								p = tam->data.ds_hd.pTail;
								delete p;
								k->pNext = NULL;
								tam->data.ds_hd.pTail = k;
							}
						}
					}
					else if (check_ma_hd == 1)
					{
						if (kt_ngay_tra_hang(tam->data.ds_hd.pTail->data.ngay_lap_hoa_don, vt_hd_trong_ds_nv->data.ngay_lap_hoa_don) == -1)
						{
							cout << "\n\tSo ngay tra hang da vuot qua 3 ngay";
							system("pause");
							if (tam->data.ds_hd.pHead == tam->data.ds_hd.pTail)
							{
								node_hoa_don *p = new node_hoa_don;
								p = tam->data.ds_hd.pHead;
								tam->data.ds_hd.pHead = tam->data.ds_hd.pHead->pNext;
								delete p;
							}
							// xoá đi hoá đơn vừa được tạo ( xoá cuối dslk đơn)
							for (node_hoa_don *k = tam->data.ds_hd.pHead; k != NULL; k = k->pNext)
							{
								// phát hiện node cuối
								if (tam->data.ds_hd.pTail == k->pNext)
								{
									node_hoa_don *p = new node_hoa_don;
									p = tam->data.ds_hd.pTail;
									delete p;
									k->pNext = NULL;
									tam->data.ds_hd.pTail = k;
								}
							}
						}
						else
						{
							while (true)
							{
								system("cls");
								cout << "\n\t1. Nhap ma vat tu trong chi tiet hoa don de tra hang";
								cout << "\n\t2. Thay doi so luong";
								cout << "\n\t0. Thoat";
								cout << "\n\tNhap luc chon: ";
								int lc_tra;
								cin >> lc_tra;
								if (lc_tra == 1)
								{
									cin.ignore();
									// cho xem hoá đơn khách hàng đã mua trước đó
									cout << "  So hoa don: " << vt_hd_trong_ds_nv->data.SOHD << "   Ngay lap hoa don: " << vt_hd_trong_ds_nv->data.ngay_lap_hoa_don << "   Loai Hoa Don: " << vt_hd_trong_ds_nv->data.loai;
									cout << endl;
									cout << setw(20) << "Ma vat tu" << setw(20) << "So Luong" << setw(20) << "Don gia" << setw(20) << "Thanh Tien" << endl;
									for (int i = 0; i < vt_hd_trong_ds_nv->data.ds_chi_tiet_hd.sl; i++)
									{
										cout << setw(20) << vt_hd_trong_ds_nv->data.ds_chi_tiet_hd.ds[i].ma_vt << setw(20) << vt_hd_trong_ds_nv->data.ds_chi_tiet_hd.ds[i].sl << setw(20) << vt_hd_trong_ds_nv->data.ds_chi_tiet_hd.ds[i].don_gia << setw(20) << vt_hd_trong_ds_nv->data.ds_chi_tiet_hd.ds[i].don_gia * vt_hd_trong_ds_nv->data.ds_chi_tiet_hd.ds[i].sl;
										cout << endl;
									}
									// khách trả hàng
									chi_tiet_hoa_don x;
									do
									{
										cout << "Nhap ma vat tu: ";
										getline(cin, x.ma_vt);
									} while (kt_ma_vt_co_ton_tai_trong_ds_chi_tiet_hd(vt_hd_trong_ds_nv->data.ds_chi_tiet_hd, x.ma_vt) == -1);
									int vt_vat_tu_trong_chi_tiet_hd = kt_ma_vt_co_ton_tai_trong_ds_chi_tiet_hd(vt_hd_trong_ds_nv->data.ds_chi_tiet_hd, x.ma_vt);
									do
									{
										cout << "Nhap so luong: ";
										cin >> x.sl;

									} while (x.sl > vt_hd_trong_ds_nv->data.ds_chi_tiet_hd.ds[vt_vat_tu_trong_chi_tiet_hd].sl);
									x.don_gia = vt_hd_trong_ds_nv->data.ds_chi_tiet_hd.ds[vt_vat_tu_trong_chi_tiet_hd].don_gia;
									cout << "Don gia: " << x.don_gia;
									x.VAT = (float)8 / 100;
									cout << "\nthue VAT: " << x.VAT;
									x.trang_thai = -2;
									cout << "\nTrang Thai: " << x.trang_thai << endl;
									system("pause");
									tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.ds[tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.sl++] = x;
								}
								else if (lc_tra == 2)
								{
									// cho xem danh sách chi tiết hoá đơn trả khách hàng đang lập
									xem_ds_hd_chi_tiet_vua_moi_lap(tam->data.ds_hd.pTail->data.ds_chi_tiet_hd);
									cout << "\n=================================================\n";
									cin.ignore();
									string ma_vt_update;
									cout << "\nNhap ma vat tu can cap nhat: ";
									getline(cin, ma_vt_update);
									if (kt_ma_vt_co_ton_tai_trong_ds_chi_tiet_hd(tam->data.ds_hd.pTail->data.ds_chi_tiet_hd, ma_vt_update) == -1)
									{

										cout << "\n\tKhong co ma vat tu nao nhu tren";
									}
									else
									{
										int vt_vat_tu_trong_chi_tiet_hd = kt_ma_vt_co_ton_tai_trong_ds_chi_tiet_hd(vt_hd_trong_ds_nv->data.ds_chi_tiet_hd, ma_vt_update);
										int vt_vt = kt_ma_vt_co_ton_tai_trong_ds_chi_tiet_hd(tam->data.ds_hd.pTail->data.ds_chi_tiet_hd, ma_vt_update);
										cout << "\n\t\t\t So luong thay doi phai lon hon 0 va nho hon hoac bang " << vt_hd_trong_ds_nv->data.ds_chi_tiet_hd.ds[vt_vat_tu_trong_chi_tiet_hd].sl;
										do
										{
											cout << "Nhap so luong can thay doi: ";
											cin >> tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.ds[vt_vt].sl;
										} while (tam->data.ds_hd.pTail->data.ds_chi_tiet_hd.ds[vt_vt].sl > vt_hd_trong_ds_nv->data.ds_chi_tiet_hd.ds[vt_vat_tu_trong_chi_tiet_hd].sl);
									}
									system("pause");
								}
								else if (lc_tra == 0)
								{
									cap_nhat_sl_vat_tu_vua_moi_nhap_vao_tu_hoa_don(ds_vt, tam->data.ds_hd.pTail->data.ds_chi_tiet_hd);
									break;
								}
							}
						}
					}
				}
				
			}
		}
	}
}
node_nhan_vien *kiem_tra_ma_nv(tree t, int ma_nv)
{
	if (t != NULL)
	{
		if (t->data.ma_nv == ma_nv)
		{
			return t;
		}
		else if (t->data.ma_nv > ma_nv)
		{
			kiem_tra_ma_nv(t->pLeft, ma_nv);
		}
		else
		{
			kiem_tra_ma_nv(t->pRight, ma_nv);
		}

	}
	else
	{
		return NULL;
	}
}
node_hoa_don *khoi_tao_node_hoa_don()
{
	node_hoa_don *p = new node_hoa_don;
	p->pNext = NULL;
	return p;
}
void them_1_hd(DS_HOA_DON &l, node_hoa_don *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
string tao_ma_hd(DS_HOA_DON ds_hd)
{
	string a = "HD0000";
	do
	{
		for (int i = 2; i < a.length(); i++)
		{
			a[i] = rand() % (57 - 48 + 1) + 48;
		}
	} while (kt_trung_ma_hd(ds_hd, a) == true);
	return a;
}
bool kt_trung_ma_hd(DS_HOA_DON ds_hd, string ma_hd)
{
	for (node_hoa_don *k = ds_hd.pHead; k != NULL; k = k->pNext)
	{
		if (_stricmp(ma_hd.c_str(), k->data.SOHD.c_str()) == 0)
		{
			return true;
		}
	}
	return false;
}
void cap_nhat_sl_vat_tu_vua_moi_nhap_vao_tu_hoa_don(DSVT &ds_vt, DS_CHI_TIET_HOA_DON &ds_chi_tiet_hd)
{
	for (int i = 0; i < ds_chi_tiet_hd.sl; i++)
	{
		for (int j = 0; j < ds_vt.sl; j++)
		{
			if (_stricmp(ds_chi_tiet_hd.ds[i].ma_vt.c_str(), ds_vt.ds[j]->ma_vt.c_str()) == 0)
			{
				ds_vt.ds[j]->so_luong_ton += ds_chi_tiet_hd.ds[i].sl;
			}
		}
	}
}
void xoa_ma_vt_trong_chi_tiet_hd(DS_CHI_TIET_HOA_DON &ds_ch_tiet_hd,string ma_vt_xoa,int &check)
{
	for (int i = 0; i < ds_ch_tiet_hd.sl; i++)
	{
		if (_stricmp(ds_ch_tiet_hd.ds[i].ma_vt.c_str(), ma_vt_xoa.c_str()) == 0)
		{
			check = 1;
			for (int j = i; j < ds_ch_tiet_hd.sl - 1; j++)
			{
				ds_ch_tiet_hd.ds[j] = ds_ch_tiet_hd.ds[j + 1];
			}
			ds_ch_tiet_hd.sl--;
			break;
		}
	}
}
void xem_ds_hd_chi_tiet_vua_moi_lap(DS_CHI_TIET_HOA_DON ds_ct_hd)
{
	for (int i = 0; i < ds_ct_hd.sl; i++)
	{
		cout << "\n\tCHi tiet hoa don thu " << i + 1;
		cout << "\nMa vat tu: " << ds_ct_hd.ds[i].ma_vt;
		cout << "\nSo luong: " << ds_ct_hd.ds[i].sl;
		cout << "\nDon gia: " << ds_ct_hd.ds[i].don_gia;
		cout << "\nVAT: " << ds_ct_hd.ds[i].VAT;
		cout << "\nTrang Thai: " << ds_ct_hd.ds[i].trang_thai;
	}
}

int kt_ma_vt_co_ton_tai_trong_ds_chi_tiet_hd(DS_CHI_TIET_HOA_DON &ds_ct_hd, string ma_vt)
{
	for (int i = 0; i < ds_ct_hd.sl; i++)
	{
		if (_stricmp(ds_ct_hd.ds[i].ma_vt.c_str(), ma_vt.c_str()) == 0)
		{
			return i;
		}
	}
	return -1;
}

void cap_nhat_sl_vat_tu_trong_kho_vua_moi_tra_cho_nha_san_xuat(DSVT &ds_vt, DS_CHI_TIET_HOA_DON &ds_chi_tiet_hd)
{
	for (int i = 0; i < ds_chi_tiet_hd.sl; i++)
	{
		for (int j = 0; j < ds_vt.sl; j++)
		{
			if (_stricmp(ds_chi_tiet_hd.ds[i].ma_vt.c_str(), ds_vt.ds[j]->ma_vt.c_str()) == 0)
			{
				ds_vt.ds[j]->so_luong_ton -= ds_chi_tiet_hd.ds[i].sl;
			}
		}
	}
}
float tong_tien_khach_hang_phai_tra(DS_CHI_TIET_HOA_DON ds_ct_hd)
{
	float tong = 0;
	for (int i = 0; i < ds_ct_hd.sl; i++)
	{
		tong += (ds_ct_hd.ds[i].don_gia * ds_ct_hd.ds[i].sl);
	}
	return tong * 108 / 100;
}

void tim_kiem_ma_hd_khach_hang_da_mua(tree t, string ma_hd,int &check_ma_hd,node_hoa_don *&vt_hd_trong_ds_nv)
{
	if (t != NULL)
	{
		tim_kiem_ma_hd_khach_hang_da_mua(t->pLeft, ma_hd,check_ma_hd, vt_hd_trong_ds_nv);
		for (node_hoa_don *k = t->data.ds_hd.pHead; k != NULL; k = k->pNext)
		{
			// tìm thấy hoá đơn khách hàng muốn trả
			vt_hd_trong_ds_nv = k;
			if (_stricmp(k->data.SOHD.c_str(), ma_hd.c_str()) == 0 && k->data.loai == 'X')
			{
				cout << "  So hoa don: " << k->data.SOHD << "   Ngay lap hoa don: " << k->data.ngay_lap_hoa_don << "   Loai Hoa Don: " << k->data.loai;
				cout << endl;
				cout << setw(20) << "Ma vat tu" << setw(20) << "So Luong" << setw(20) << "Don gia" << setw(20) << "Thanh Tien" << endl;
				for (int i = 0; i < k->data.ds_chi_tiet_hd.sl; i++)
				{
					cout << setw(20) << k->data.ds_chi_tiet_hd.ds[i].ma_vt <<  setw(20) << k->data.ds_chi_tiet_hd.ds[i].sl << setw(20) << k->data.ds_chi_tiet_hd.ds[i].don_gia << setw(20) <<  k->data.ds_chi_tiet_hd.ds[i].don_gia * k->data.ds_chi_tiet_hd.ds[i].sl;
					cout << endl;
				}
				cout << "\t\t\t Tong tien: " << tong_tien_khach_hang_phai_tra(k->data.ds_chi_tiet_hd);
				check_ma_hd = 1;
				return;
			}
		}
		tim_kiem_ma_hd_khach_hang_da_mua(t->pRight, ma_hd,check_ma_hd, vt_hd_trong_ds_nv);
	}
	else
	{
		if (check_ma_hd == 0)
		{
			check_ma_hd = 0;
		}
	}
}
void xuat_toan_bo_hd(tree t)
{
	if (t != NULL)
	{
		xuat_toan_bo_hd(t->pLeft);
		cout << "\n\t\t Ma NV: " << t->data.ma_nv;
		cout << "\n\t\t Ho Ten: " << t->data.ho << " " << t->data.ten;
		cout << "\n\t\t Gioi Tinh: " << t->data.phai << endl;
		if (t->data.ds_hd.pHead != NULL)
		{
			cout << setw(20) << "SO HD" << setw(20) << "Ngay lap" << setw(20) << "Loai HD" << setw(20) << "Tri Gia" << endl;
		}
		for (node_hoa_don *k = t->data.ds_hd.pHead; k != NULL; k = k->pNext)
		{
			cout << setw(20) << k->data.SOHD << setw(20) << k->data.ngay_lap_hoa_don << setw(20) << k->data.loai << setw(20) << tong_tien_khach_hang_phai_tra(k->data.ds_chi_tiet_hd) << endl;
		}
		cout << endl;
		xuat_toan_bo_hd(t->pRight);
	}
}
void In_1_hoa_don(tree t,string so_hd,int &check_hd)
{
	if (t != NULL)
	{
		In_1_hoa_don(t->pLeft, so_hd,check_hd);
		for (node_hoa_don *k = t->data.ds_hd.pHead; k != NULL; k = k->pNext)
		{
			if (_stricmp(k->data.SOHD.c_str(), so_hd.c_str()) == 0)
			{
				check_hd = 1;
				cout << "\n\t\t Ma NV: " << t->data.ma_nv;
				cout << "\n\t\t Ho Ten: " << t->data.ho << " " << t->data.ten;
				cout << "\n\t\t Gioi Tinh: " << t->data.phai << endl;
				// khung
				cout << setw(20) << "SO HD" << setw(20) << "Ngay lap" << setw(20) << "Loai HD" << endl;
				// nội dung
				cout << setw(20) << k->data.SOHD << setw(20) << k->data.ngay_lap_hoa_don << setw(20) << k->data.loai << endl;
				// khung
				cout << setw(10) << "Ma VT" << setw(20) << "Don Gia" << setw(20) << "So luong" << setw(20) << "Trang Thai" << setw(20) << "Thanh Tien" << endl;
				for (int i = 0; i < k->data.ds_chi_tiet_hd.sl; i++)
				{
					cout << setw(10) << k->data.ds_chi_tiet_hd.ds[i].ma_vt << setw(20) << k->data.ds_chi_tiet_hd.ds[i].don_gia << setw(20) << k->data.ds_chi_tiet_hd.ds[i].sl << setw(20) << k->data.ds_chi_tiet_hd.ds[i].trang_thai << setw(20) << k->data.ds_chi_tiet_hd.ds[i].don_gia * k->data.ds_chi_tiet_hd.ds[i].sl << endl;
				}
				cout << "\t\t TONG TIEN: " << tong_tien_khach_hang_phai_tra(k->data.ds_chi_tiet_hd);
			}
		}
		In_1_hoa_don(t->pRight, so_hd,check_hd);
	}
}
string ngay_thang_nam_hien_tai()
{
	string date;
	// current date/time based on current system
	time_t now = time(0);
	tm *ltm = localtime(&now);

	// print various components of tm structure.
	/*cout << "Year: " << 1900 + ltm->tm_year << endl;
	cout << "Month: " << 1 + ltm->tm_mon << endl;
	cout << "Day: " << ltm->tm_mday << endl;*/
	int day = ltm->tm_mday;
	if (day > 10)
	{
		date.insert(date.size(), to_string(day));
	}
	else if (day < 10)
	{
		date.push_back('0');
		date.insert(date.size(), to_string(day));
	}
	date.push_back('/');
	int month = 1 + ltm->tm_mon;
	if (month > 9)
	{
		date.insert(date.size(), to_string(month));
	}
	else if (month < 10)
	{
		date.push_back('0');
		date.insert(date.size(), to_string(month));
	}
	date.push_back('/');
	int year = 1900 + ltm->tm_year;
	date.insert(date.size(), to_string(year));
	return date;
}
int kt_ngay_tra_hang(string ngay_tra,string ngay_mua)
{
	string day_tra;
	string month_tra;
	string year_tra;
	int begin_tra = 0;
	for (int i = 0; i < ngay_tra.length(); i++)
	{
		if (ngay_tra[i] == '/' && begin_tra == 0)
		{
			day_tra = ngay_tra.substr(begin_tra, i - begin_tra);
			begin_tra = i + 1;
		}
		else if (ngay_tra[i] == '/')
		{
			month_tra = ngay_tra.substr(begin_tra, i - begin_tra);
			begin_tra = i + 1;
		}
		// đang ở vị trí cuối chuỗi
		else if (i + 1 == ngay_tra.length() - 1)
		{
			year_tra = ngay_tra.substr(begin_tra);
		}
	}
	
	string day_mua;
	string month_mua;
	string year_mua;
	int begin_mua = 0;
	for (int i = 0; i < ngay_mua.length(); i++)
	{
		if (ngay_mua[i] == '/' && begin_mua == 0)
		{
			day_mua = ngay_mua.substr(begin_mua, i - begin_mua);
			begin_mua = i + 1;
		}
		else if (ngay_mua[i] == '/')
		{
			month_mua = ngay_mua.substr(begin_mua, i - begin_mua);
			begin_mua = i + 1;
		}
		// đang ở vị trí cuối chuỗi
		else if (i + 1 == ngay_mua.length() - 1)
		{
			year_mua = ngay_mua.substr(begin_mua);
		}
	}
	if (strcmp(month_mua.c_str(), month_tra.c_str()) == 0 && strcmp(year_mua.c_str(), year_tra.c_str()) == 0)
	{
		int ngay_tra = atoi(day_tra.c_str());
		int ngay_mua = atoi(day_mua.c_str());
		if (ngay_tra - ngay_mua <= 3 && ngay_tra - ngay_mua >= 0)
		{
			return 1;
		}
	}
	return -1;
}
int rdn(int y, int m, int d)
{
	if (m < 3)
		y--, m += 12;
	return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
void Liet_ke_hoa_don_do_1_nv_lap_trong_khoang_1_tg(DS_NHAN_VIEN ds_nv)
{
	int ma_nv;
	cout << "Nhap ma nhan vien: ";
	cin >> ma_nv;
	node_nhan_vien *tam = kiem_tra_ma_nv(ds_nv.t, ma_nv);
	if (tam == NULL)
	{
		cout << "\n\tKhong co ma nhan vien " << ma_nv;
	}
	else
	{

		if (tam->data.ds_hd.pHead == NULL)
		{
			cout << "\n\tNhan vien nay chua lap hoa don";
			return;
		}
		cin.ignore();
		cout << "\n\tNhap thoi diem\n";
		cout << "Tu ngay: ";
		string begin_day;
		getline(cin, begin_day);
		cout << "Den ngay: ";
		string end_day;
		getline(cin, end_day);
		int kc_ngay = kc_giua_2_ngay(end_day,begin_day);
		int check = 0;
		cout << "\n\t\tTu ngay: " << begin_day << "  Den ngay: " << end_day << endl;
		cout << "\t\tNhan vien: " << tam->data.ho << " " << tam->data.ten;
		cout << "\n\t\tMa NV: " << tam->data.ma_nv << endl;
		for (node_hoa_don *k = tam->data.ds_hd.pHead; k != NULL; k = k->pNext)
		{
			if (kc_ngay >= kc_giua_2_ngay(end_day, k->data.ngay_lap_hoa_don) && kc_giua_2_ngay(end_day, k->data.ngay_lap_hoa_don) >= 0 && check == 0)
			{
				cout << setw(20) << "SO HD" << setw(20) << "Ngay lap" << setw(20) << "Loai HD" << setw(20) << "Tri Gia" << endl;
				check = 1;
			}	
			if (kc_ngay >= kc_giua_2_ngay(end_day, k->data.ngay_lap_hoa_don) && kc_giua_2_ngay(end_day, k->data.ngay_lap_hoa_don) >= 0)
			{
				cout << setw(20) << k->data.SOHD << setw(20) << k->data.ngay_lap_hoa_don << setw(20) << k->data.loai << setw(20) << tong_tien_khach_hang_phai_tra(k->data.ds_chi_tiet_hd) << endl;
			}
		}
		if (check == 0)
		{
			cout << "\n\tKhong ton tai hoa don tu ngay " << begin_day << " den ngay " << end_day;
		}
	}
}
int kc_giua_2_ngay(string ngay_tra, string ngay_mua)
{
	string day_tra;
	string month_tra;
	string year_tra;
	int begin_tra = 0;
	for (int i = 0; i < ngay_tra.length(); i++)
	{
		if (ngay_tra[i] == '/' && begin_tra == 0)
		{
			day_tra = ngay_tra.substr(begin_tra, i - begin_tra);
			begin_tra = i + 1;
		}
		else if (ngay_tra[i] == '/')
		{
			month_tra = ngay_tra.substr(begin_tra, i - begin_tra);
			begin_tra = i + 1;
		}
		// đang ở vị trí cuối chuỗi
		else if (i + 1 == ngay_tra.length() - 1)
		{
			year_tra = ngay_tra.substr(begin_tra);
		}
	}

	string day_mua;
	string month_mua;
	string year_mua;
	int begin_mua = 0;
	for (int i = 0; i < ngay_mua.length(); i++)
	{
		if (ngay_mua[i] == '/' && begin_mua == 0)
		{
			day_mua = ngay_mua.substr(begin_mua, i - begin_mua);
			begin_mua = i + 1;
		}
		else if (ngay_mua[i] == '/')
		{
			month_mua = ngay_mua.substr(begin_mua, i - begin_mua);
			begin_mua = i + 1;
		}
		// đang ở vị trí cuối chuỗi
		else if (i + 1 == ngay_mua.length() - 1)
		{
			year_mua = ngay_mua.substr(begin_mua);
		}
	}
	
	// chuyển thành ngày tháng năm
	int _ngay_tra = atoi(day_tra.c_str());
	int _thang_tra = atoi(month_tra.c_str());
	int _nam_tra = atoi(year_tra.c_str());

	int _ngay_mua = atoi(day_mua.c_str());
	int _thang_mua = atoi(month_mua.c_str());
	int _nam_mua = atoi(year_mua.c_str());

	int a = rdn(_nam_tra, _thang_tra, _ngay_tra);
	int b = rdn(_nam_mua, _thang_mua, _ngay_mua);
	return a - b;
}

void Thong_ke_doanh_thu_1_nam(DS_NHAN_VIEN ds_nv,string nam)
{
		cout << "\n\n\t\tBANG THONG KE DOANH THU NAM " << nam << endl;
		cout << setw(20) << "THANG" << setw(20) << "DOANH THU" ;
		for (int i = 1; i <= 12; i++)
		{
			// biến dùng để duyệt qua từng tháng trong năm
			string ngay_tam = "01//" + nam;
			if (i >= 10)
			{
				ngay_tam.insert(3, to_string(i));
			}
			else
			{
				ngay_tam.insert(3, "0");
				ngay_tam.insert(4, to_string(i));
			}
			float tong_doanh_thu_1_thang = 0;
			Doanh_thu_1_thang(ds_nv.t, ngay_tam, tong_doanh_thu_1_thang);
			cout << endl << setw(20) << i << setw(20) << tong_doanh_thu_1_thang;
		}
		
}

void Doanh_thu_1_thang(tree t, string thang_nam_de_so_sanh,float &tong_doanh_thu_1_thang)
{
	if (t != NULL)
	{
		Doanh_thu_1_thang(t->pLeft,thang_nam_de_so_sanh, tong_doanh_thu_1_thang);
		if (t->data.ds_hd.pHead != NULL)
		{
			for (node_hoa_don *k = t->data.ds_hd.pHead; k != NULL; k = k->pNext)
			{
				if (k->data.loai = 'X')
				{
					if (kt_trung_thang_nam(k->data.ngay_lap_hoa_don, thang_nam_de_so_sanh) == 1)
					{
						for (int i = 0; i < k->data.ds_chi_tiet_hd.sl; i++)
						{
							if (k->data.ds_chi_tiet_hd.ds[i].trang_thai == -2)
							{
								break;
							}
							tong_doanh_thu_1_thang += (k->data.ds_chi_tiet_hd.ds[i].don_gia * k->data.ds_chi_tiet_hd.ds[i].sl);
						}
					}
				}
			}
		}
		Doanh_thu_1_thang(t->pRight, thang_nam_de_so_sanh, tong_doanh_thu_1_thang);
	}
}
int kt_trung_thang_nam(string ngay_tra, string ngay_mua)
{
	string day_tra;
	string month_tra;
	string year_tra;
	int begin_tra = 0;
	for (int i = 0; i < ngay_tra.length(); i++)
	{
		if (ngay_tra[i] == '/' && begin_tra == 0)
		{
			day_tra = ngay_tra.substr(begin_tra, i - begin_tra);
			begin_tra = i + 1;
		}
		else if (ngay_tra[i] == '/')
		{
			month_tra = ngay_tra.substr(begin_tra, i - begin_tra);
			begin_tra = i + 1;
		}
		// đang ở vị trí cuối chuỗi
		else if (i + 1 == ngay_tra.length() - 1)
		{
			year_tra = ngay_tra.substr(begin_tra);
		}
	}

	string day_mua;
	string month_mua;
	string year_mua;
	int begin_mua = 0;
	for (int i = 0; i < ngay_mua.length(); i++)
	{
		if (ngay_mua[i] == '/' && begin_mua == 0)
		{
			day_mua = ngay_mua.substr(begin_mua, i - begin_mua);
			begin_mua = i + 1;
		}
		else if (ngay_mua[i] == '/')
		{
			month_mua = ngay_mua.substr(begin_mua, i - begin_mua);
			begin_mua = i + 1;
		}
		// đang ở vị trí cuối chuỗi
		else if (i + 1 == ngay_mua.length() - 1)
		{
			year_mua = ngay_mua.substr(begin_mua);
		}
	}

	if (strcmp(year_mua.c_str(), year_tra.c_str()) == 0 && strcmp(month_mua.c_str(), month_tra.c_str()) == 0)
	{
		return 1;
	}
	return -1;
}