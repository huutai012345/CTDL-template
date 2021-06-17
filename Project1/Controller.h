#include"CTDL.h"
#include"DoHoa.h"
#include"Handle.h"

string menuMain[] = {
"Them Doc Gia", 
"Xoa Doc Gia", 
"Hieu Chinh Doc Gia", 
"Xuat DSGD Theo Ho Ten",  
"Thoat"
};

void Menu()
{
	textcolor(240);
	int j = 17;
	for (int i = 0; i < sizeof(menuMain) / sizeof(*menuMain); i++)
	{	
			ToMauHCN(80, j, 50, 5, 4);
			gotoXY(85, j + 3);
			cout << menuMain[i];
			j = j + 5;
	}
}

void Run(DSDocGia& dsDG, DSDauSach& dsDS)
{	
	if (kbhit()) // hàm kbhit() là hàm xem người dùng có nhấn phím nào trong lúc chương trình đang chạy hay không
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72) // mã ascii mũi tên lên
			{
				if (pointer == 17)
				{
					Menu();
					pointer = 17 - 1 + sizeof(menuMain) / sizeof(*menuMain);
				}
				else
				{
					Menu();
					pointer--;
				}
			}
			else if (c == 80) // mã ascii mũi tên xuống
			{
				if (pointer == 17 - 1 + sizeof(menuMain) / sizeof(*menuMain))
				{
					Menu();
					pointer = 17;
				}
				else
				{
					Menu();
					pointer++;
				}
			}
		}
		else if (c == 13)
		{
			system("cls");
			system("color F0");

			switch (pointer)
			{
			case 17: {
				break;
			}
			case 18: {
				break;
				}
			case 19: {
				break;
			}
			case 20: {
				break;
			}
			case 21: {
				exit(0);
			}
			}

			system("cls");
			system("color F0");
			GiaoDienMain();
			Menu();
		}

		// to mau 
		ToMauHCN(80, 17+(pointer-17) * 5, 50, 5, 180);
		gotoXY(85, 20 + (pointer - 17) * 5);
		textcolor(180);
		cout << menuMain[pointer - 17];
		textcolor(7);
	}
}

void Init(DSDauSach& dsDS, DSDocGia& dsDG)
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	system("color F0");

	ShowCur(0);

	GiaoDienMain();
	Menu();

	ToMauHCN(80, 17 + (pointer - 17) * 5, 50, 5, 180);
	gotoXY(85, 20 + (pointer - 17) * 5);
	textcolor(180);
	cout << menuMain[0];
	textcolor(7);
}
