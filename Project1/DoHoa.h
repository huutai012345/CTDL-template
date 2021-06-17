void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}

void VeHCN(int toadoX, int toadoY, int chieudai, int chieucao)
{
	textcolor(240);
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}
}
void Logo(int toadoX, int toadoY)
{
	string str;
	ifstream FileIn;
	FileIn.open("inputTittle.txt", ios::in);
	int h = toadoY;
	SetColor(6);
	while (true)
	{
		getline(FileIn, str);
		gotoXY(toadoX, h++);
		cout << str << endl;
		if (FileIn.eof())
		{
			break;
		}
	}
	textcolor(7);
	FileIn.close();
}

void GiaoDienXuatDSDauSach(int toadoX, int toadoY, int n)
{
	int chieucao = 3 + 2 * n;
	int chieudai = 124;
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}


	// gach xuong
	for (int i = toadoX + 1; i < chieudai + toadoX; i++)
	{
		if (i == toadoX + 5|| i == toadoX + 16 || i == toadoX + 52 || i == toadoX + 59 || i == toadoX + 85
			|| i == toadoX + 94 || i == toadoX + 115)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j == toadoY)
					cout << char(194);
				else if (j == chieucao + toadoY)
					cout << char(193);
				else
					cout << (char)179;
			}
		}
	}


	// gach ngang
	for (int j = 3; j < chieucao; j = j + 2)
	{
		for (int i = toadoX; i <= chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX)
				cout << (char)195;
			else if (i == chieudai + toadoX)
				cout << (char)180;
			else if (i == toadoX + 5 || i == toadoX + 16 || i == toadoX + 52 || i == toadoX + 59 || i == toadoX + 85
				|| i == toadoX + 94 || i == toadoX + 115)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}


	gotoXY(toadoX + 1, toadoY + 1);
	cout << "STT";
	gotoXY(toadoX + 6, toadoY + 1);
	cout << "Ma";
	gotoXY(toadoX + 6, toadoY + 2);
	cout << "Dau Sach";
	gotoXY(toadoX + 17, toadoY + 1);
	cout << "Ten Sach";
	gotoXY(toadoX + 53, toadoY + 1);
	cout << "So";
	gotoXY(toadoX + 53, toadoY + 2);
	cout << "Trang";
	gotoXY(toadoX + 60, toadoY + 1);
	cout << "Tac Gia";
	gotoXY(toadoX + 86, toadoY + 1);
	cout << "Nam";
	gotoXY(toadoX + 86, toadoY + 2);
	cout << "Xuat Ban";
	gotoXY(toadoX + 95, toadoY + 1);
	cout << "The Loai";
	gotoXY(toadoX + 116, toadoY + 1);
	cout << "So Luong";
}
void GiaoDenXuatDauSachTheoTheLoai(int toadoX, int toadoY, int n)
{
	int chieucao = 3 + 2 * n;
	int chieudai = 124;
	
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}


	// gach xuong
	for (int i = toadoX + 1; i < chieudai + toadoX; i++)
	{
		if (i == toadoX + 11 || i == toadoX + 52 || i == toadoX + 59 || i == toadoX + 85 
			|| i == toadoX + 94 || i == toadoX + 115)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j == toadoY)
					cout << char(194);
				else if (j == chieucao + toadoY)
					cout << char(193);
				else
					cout << (char)179;
			}
		}
	}


	// gach ngang
	for (int j = 3; j < chieucao; j = j + 2)
	{
		for (int i = toadoX; i <= chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX)
				cout << (char)195;
			else if (i == chieudai + toadoX)
				cout << (char)180;
			else if (i == toadoX + 11 || i == toadoX + 52 || i == toadoX + 59 || i == toadoX + 85 
				|| i == toadoX + 94 || i == toadoX + 115)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}

	gotoXY(toadoX + 1, toadoY + 1);
	cout << "Ma";
	gotoXY(toadoX + 1, toadoY + 2);
	cout << "Dau Sach";
	gotoXY(toadoX + 12, toadoY + 1);
	cout << "Ten Sach";
	gotoXY(toadoX + 53, toadoY + 1);
	cout << "So";
	gotoXY(toadoX + 53, toadoY + 2);
	cout << "Trang";
	gotoXY(toadoX + 60, toadoY + 1);
	cout << "Tac Gia";
	gotoXY(toadoX + 86, toadoY + 1);
	cout << "Nam";
	gotoXY(toadoX + 86, toadoY + 2);
	cout << "Xuat Ban";
	gotoXY(toadoX + 95, toadoY + 1);
	cout << "Vi Tri";
	gotoXY(toadoX + 116, toadoY + 1);
	cout << "So Luong";
}
void GiaoDienXuat10DauSachMuonMax(int toadoX, int toadoY)
{
	int chieucao = 3 + 2 * 10;
	int chieudai = 106;

	
	textcolor(180);
	gotoXY(toadoX + 1, toadoY + 1);
	cout << "Ma Dau Sach";
	gotoXY(toadoX + 16, toadoY + 1);
	cout << "Ten Sach" ;
	gotoXY(toadoX + 57, toadoY + 1);
	cout << "So Trang" ;
	gotoXY(toadoX + 67, toadoY + 1);
	cout << "Tac Gia";
	gotoXY(toadoX + 93, toadoY + 1);
	cout << "So Lan Muon ";

	
	for (int i = toadoX ; i < chieudai + toadoX; i++)
	{
		if (i == toadoX + 15 || i == toadoX + 56 || i == toadoX + 66 || i == toadoX + 92 )
		{
			for (int j = toadoY; j < chieucao + toadoY+1 ; j++)
			{
				gotoXY(i, j);
				if (j < toadoY + 3)
				{
					textcolor(180);
				}
				else
					textcolor(224);
				cout << (char)179;
				textcolor(7);
			}
		}
	}
	textcolor(224);
	for (int j = 5; j < chieucao; j = j + 2)
	{
		for (int i = toadoX+1; i < chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX + 15 || i == toadoX + 56 || i == toadoX + 66 || i == toadoX + 92)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}
}
void GiaoDienXuatDSDocGia(int toadoX, int toadoY, int n)
{
	int chieucao = 3 + 2 * n;
	int chieudai = 85;
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}


	// gach xuong
	for (int i = toadoX + 1; i < chieudai + toadoX; i++)
	{
		if (i == toadoX + 10 || i == toadoX + 50 || i == toadoX + 60 || i == toadoX + 72 )
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j == toadoY)
					cout << char(194);
				else if (j == chieucao + toadoY)
					cout << char(193);
				else
					cout << (char)179;
			}
		}
	}


	// gach ngang
	for (int j = 3; j < chieucao; j = j + 2)
	{
		for (int i = toadoX; i <= chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX)
				cout << (char)195;
			else if (i == chieudai + toadoX)
				cout << (char)180;
			else if (i == toadoX + 10 || i == toadoX + 50 || i == toadoX + 60 || i == toadoX + 72)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}

	gotoXY(toadoX + 1, toadoY + 1);
	cout << "Ma The";
	gotoXY(toadoX + 11, toadoY + 1);
	cout << "Ho va Ten";
	gotoXY(toadoX + 51, toadoY + 1);
	cout << "Phai";
	gotoXY(toadoX + 61, toadoY + 1);
	cout << "Trang Thai";
	gotoXY(toadoX + 73, toadoY + 1);
	cout << "So Sach";
	gotoXY(toadoX + 73, toadoY + 2);
	cout << "Dang Muon";
}
void GiaoDienXuatDanhSachMuon(int toadoX, int toadoY, int n)
{
	int chieucao = 3 + 2 * n;
	int chieudai = 100;
	
	
	textcolor(180);
	gotoXY(toadoX + 1, toadoY + 1);
	cout << "Ma Sach";
	gotoXY(toadoX + 21, toadoY + 1);
	cout << "Ten Sach";
	gotoXY(toadoX + 62, toadoY + 1);
	cout << "Ngay Muon" ;
	gotoXY(toadoX + 82, toadoY + 1);
	cout << "Trang Thai";

	
	// gach xuong
	for (int i = toadoX + 1; i < chieudai + toadoX; i++)
	{
		if (i == toadoX + 20 || i == toadoX + 61 || i == toadoX + 81)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j < toadoY + 3)
				{
					textcolor(180);
				}
				else
					textcolor(224);
				cout << (char)179;
				textcolor(7);
			}
		}
	}
	textcolor(224);
	// gach ngang
	for (int j = 5; j < chieucao; j = j + 2)
	{
		for (int i = toadoX+1; i < chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX + 20 || i == toadoX + 61 || i == toadoX + 81 )
				cout << (char)197;
			else
				cout << (char)196;
		}
	}
}
void GiaoDienMain()
{
	Logo(50, 5);
}
void GiaoDienNhapDauSach(int toadoX, int toadoY)
{
	textcolor(240);
	gotoXY(toadoX-35, toadoY + 1);
	cout << "Nhap Ma Dau Sach:";
	gotoXY(toadoX - 35, toadoY + 4);
	cout << "Nhap Ten Sach:";
	gotoXY(toadoX - 35, toadoY + 7);
	cout << "Nhap So Trang:";
	gotoXY(toadoX - 35, toadoY + 10);
	cout << "Nhap Tac Gia:";
	gotoXY(toadoX - 35, toadoY + 13);
	cout << "Nhap Nam Xuat Ban:";
	gotoXY(toadoX - 35, toadoY + 16);
	cout << "Nhap The Loai:";
	gotoXY(toadoX - 35, toadoY + 19);
	cout << "Nhap Vi Tri Cua Dau Sach:";
	gotoXY(toadoX - 35, toadoY + 22);
	cout << "Nhap So Luong Sach Cua Dau Sach:";
	gotoXY(toadoX + 15, toadoY + 25);
	cout << "Xac Nhan";
	gotoXY(toadoX + 30, toadoY + 25);
	cout << "Cancel";

	VeHCN(toadoX , toadoY, 50, 2);
	VeHCN(toadoX , toadoY + 3, 50, 2);
	VeHCN(toadoX , toadoY + 6, 50, 2);
	VeHCN(toadoX , toadoY + 9, 50, 2);
	VeHCN(toadoX , toadoY + 12, 50, 2);
	VeHCN(toadoX , toadoY + 15, 50, 2);
	VeHCN(toadoX , toadoY + 18, 50, 2);
	VeHCN(toadoX , toadoY + 21, 50, 2);
}
void GiaoDienThemDocGia(int toadoX, int toadoY)
{
	gotoXY(toadoX -20, 15);
	cout << "Ma The:";
	gotoXY(toadoX - 20, 18);
	cout << "Nhap Ho va Ten Lot:";
	gotoXY(toadoX - 20, 21);
	cout << "Nhap Ten:";
	gotoXY(toadoX - 20, 24);
	cout << "Phai(1:Nam,2:Nu):";

	gotoXY(toadoX + 15, toadoY + 10);
	cout << "Xac Nhan";
	gotoXY(toadoX + 30, toadoY + 10);
	cout << "Cancel";

	VeHCN(toadoX , toadoY - 3, 50, 2);
	VeHCN(toadoX , toadoY, 50, 2);
	VeHCN(toadoX , toadoY + 3, 50, 2);
	VeHCN(toadoX , toadoY + 6, 50, 2);
	
}
void GiaoDienXuatDSDMS(int toadoX, int toadoY, int n)
{
	int chieucao = 3 + 2 * n;
	int chieudai = 75;

	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}


	// gach xuong
	for (int i = toadoX + 1; i < chieudai + toadoX; i++)
	{
		if (i == toadoX + 25 || i == toadoX + 50)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j == toadoY)
					cout << char(194);
				else if (j == chieucao + toadoY)
					cout << char(193);
				else
					cout << (char)179;
			}
		}
	}


	// gach ngang
	for (int j = 3; j < chieucao; j = j + 2)
	{
		for (int i = toadoX; i <= chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX)
				cout << (char)195;
			else if (i == chieudai + toadoX)
				cout << (char)180;
			else if (i == toadoX + 25 || i == toadoX + 50)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}

	gotoXY(toadoX + 1, toadoY + 1);
	cout << "Ma Sach";
	gotoXY(toadoX + 26, toadoY + 1);
	cout << "Trang Thai";
	gotoXY(toadoX + 51, toadoY + 1);
	cout << "Vi Tri";
}
