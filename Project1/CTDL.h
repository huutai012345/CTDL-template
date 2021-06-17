#pragma once
#pragma warning (disable:4996)

#include<iostream>
#include<fstream>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<string>
#include<string.h>
#include<iomanip>

using namespace std;

int pointer = 17; 
const int MaxNodes = 10000;
const int SoNgayDcMuon = 7; 
const int SoSachDcMuon = 3;
int* mangRanDom;
int soLgSoConLai = 0;
int soLgMT = 0;

struct Date
{
	int Ngay;
	int Thang;
	int Nam;
};

struct DanhMucSach
{
	string maS;
	int TrangThai;// 0: cho muon dc, 1: da cho muon, 2: da thanh li 
	string viTri;
};
struct NodeDMS
{
	DanhMucSach data;
	struct NodeDMS* pNext;
};
struct DSDanhMucSach
{
	NodeDMS* pHead;
	int soLg = 0;
};

struct DauSach
{
	string maDS;
	string TenSach;
	int soTrang;
	string TacGia;
	int NamXuatBan;
	string TheLoai;
	int soLgSach;
	DSDanhMucSach dsDMS;
};
struct DSDauSach
{
	int soLgDauS=0;
	DauSach* data[MaxNodes];
};

struct MuonTra
{
	string maS;
	Date NgayMuon;
	Date NgayTra;
	int TrangThai; // trang thai =0 la sach đang muon (chua tra), =1 la da tra, =2 : lam mat sach
};
struct NodeMT
{
	MuonTra data;
	struct NodeMT* pNext;
	struct NodeMT* pPrev;
};
struct DSMuonTra
{
	NodeMT* pHead;
	NodeMT* pTail;
	int soLg = 0;
};

struct DocGia
{
	int maDG;
	string Ho;
	string Ten;
	int Phai; // 1 Nam 2 Nu
	int TrangThai; //trang thai cua the 1 : la đang hoat dong , 0: la bi khoa
	int soLgSachDangMuon;
	DSMuonTra dsMT;
};
struct NodeDG
{
	DocGia data;
	NodeDG* pLeft;
	NodeDG* pRight;
};
struct DSDocGia
{
	NodeDG* root=NULL; //root
	int soLg=0;
};
