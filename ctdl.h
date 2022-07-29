#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include <ctime>
// ============== Khai báo cấu trúc vật tư
struct VAT_TU
{
	string ma_vt;
	string ten_vt;
	string don_vi_tinh;
	float so_luong_ton;
};

struct  DSVT
{
	VAT_TU *ds[100];
	int sl = 0;
};
// ================= Khai báo cấu trúc danh sách chi tiết hoá đơn (mảng)
struct chi_tiet_hoa_don
{
	string ma_vt;
	float sl;
	int don_gia;
	float VAT;
	int	 trang_thai; // 1: đã nhập, 2: đã trả  LOẠI HOÁ ĐƠN : NHẬP
					 // -1: khách mua  -2: khách trả  LOẠI HOÁ ĐƠN: XUẤT
};
struct DS_CHI_TIET_HOA_DON
{
	chi_tiet_hoa_don ds[20];
	int sl = 0;
};
// ================= Khai báo cấu trúc danh sách hoá đơn (dslk đơn)
struct HOA_DON
{
	string SOHD;
	string ngay_lap_hoa_don;
	char loai; // 1: xuất , 2 : nhập
	// danh sách chi tiết hoá đơn
	DS_CHI_TIET_HOA_DON ds_chi_tiet_hd;
};

struct node_hoa_don
{
	HOA_DON data;
	node_hoa_don *pNext;
};

struct ds_hd
{
	node_hoa_don *pHead = NULL;
	node_hoa_don *pTail = NULL;
};
typedef struct ds_hd DS_HOA_DON;
// ================= Khai báo cấu trúc nhân viên (cây nhị phân tìm kiếm)
struct NHAN_VIEN
{
	int ma_nv;
	string ho;
	string ten;
	string phai;

	// danh sách hoá đơn
	DS_HOA_DON ds_hd;
};

struct node_nhan_vien
{
	NHAN_VIEN data;
	node_nhan_vien *pLeft;
	node_nhan_vien *pRight;
};

typedef node_nhan_vien *tree;
struct DS_NHAN_VIEN
{
	tree t = NULL;
	int sl = 0;
};
	