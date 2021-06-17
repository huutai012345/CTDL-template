int DemChuSo(int n)
{
	int dem = 0;
	while (n > 0)
	{
		n = n / 10;
		dem++;
	}
	return dem;
}
char Chuyen1SoSangKiTu(int n)
{
	switch (n)
	{
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 0:
		return '0';
	}
}
int TachLayMaSach(string str)
{
	string str1;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (str[i] == '_')
		{
			break;
		}
		str1.push_back(str[i]);
	}
	return atoi(str1.c_str());
}
void DinhDangChuoi(string& str)
{
	//Xoa khoang trong
	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0);
	}
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + (str.length() - 1));
	}

	for (int i = 1; i < str.length() - 1; i++)
	{
		if (str[i + 1] == ' ' && str[i] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
	//Viet thuong all lai
	for (int i = 0; i < str.length(); i++)
	{
		if ((65 <= str[i] && str[i] <= 90) && str[i] != ' ')
		{
			str[i] = str[i] + 32;
		}
	}
	//Viet hoa
	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0 && (97 <= str[i] && str[i] <= 122))
		{
			str[0] = str[0] - 32;
		}
		if (str[i] == ' ' && (97 <= str[i+1] && str[i + 1] <= 122))
		{
			str[i + 1] = str[i + 1] - 32;
		}
	}

}
	
string ChuyenSoSangString(int n)
{
	string str;
	int a;
	while (n > 0)
	{
		a = n % 10;
		Chuyen1SoSangKiTu(a);
		str.insert(str.begin() + 0, Chuyen1SoSangKiTu(a));
		n = n / 10;
	}
	return str;
}
string NoiChuoi(string str, int n)
{
	string str2;
	str2 = str;
	string str1 = ChuyenSoSangString(n);
	str2.push_back('_');
	for (int i = 0; i < str1.length(); i++)
	{
		str2.push_back(str1[i]);
	}
	return str2;
}
string TachLayMaDauSach(string str)
{
	string str1="";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '_')
		{
			break;
		}
		str1.push_back(str[i]);
	}
	return str1;
}


string XuLyNhapMa(int lenghtMax = 48)
{
	string input;
	ShowCur(1);
	gotoXY(whereX(), whereY());
	while (true)
	{
		char c = getch();
		if ((c >= 48 && c <= 57) || c == '_' || (c >= 65 && c <= 90) && input.length()< lenghtMax)
		{
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if (c >= 97 && c <= 122)
		{
			c = c - 32;
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if (c == 8 && input.length() > 0)
		{
			input.erase(input.begin() + input.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 27)
		{
			input.clear();
			ShowCur(0);
			return input;
		}
		else if (c == 13 && input.length() > 0)// nếu là phím enter
		{
			ShowCur(0);
			return input;
		}
	}
}
string XuLyNhapChu()
{
	string input;
	ShowCur(1);
	gotoXY(whereX(), whereY());
	while (true)
	{
		char c = getch();
		if ((c >= 48 && c <= 57) || (c >= 97 && c <= 122) || c == '_' || (c >= 65 && c <= 90) && input.length() < 6)
		{
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if (c == 32 && input.length() != 0 && input[input.length() - 1] != ' ')
		{
			input.insert(input.begin() + input.length(), ' ');
			cout << c;
		}
		else if (c == 8 && input.length() > 0)
		{
			input.erase(input.begin() + input.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 27)
		{
			input.clear();
			ShowCur(0);
			return input;
		}
		else if (c == 13 && input.length() > 0)// nếu là phím enter
		{
			ShowCur(0);
			return input;
		}
	}
}
int XuLyNhapSo()
{
	int n;
	ShowCur(1);
	gotoXY(whereX(), whereY());
	string x="";
	char c;
	while (true)
	{
		c = getch();
		if ((c >= 48 && c <= 57))// nếu là số thì
		{
			x.insert(x.begin() + x.length(), c);
			cout << c;
		}
		else if (c == 8 && x.length()>0)
		{
			x.erase(x.begin() + x.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 27)
		{
			ShowCur(0);
			return -1;
		}
		else if (c == 13 && x.length() > 0)// nếu là phím enter
		{
		
			n = atoi(x.c_str());
			ShowCur(0);
			return n;
		}
		
	}
}

void XuLyNhapMa(string& input, int toadoX, int& toadoY,int lenghtMax=48)
{
	char c;
	ShowCur(1);
	while (true)
	{
		c = getch();
		if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90)) && input.length() < lenghtMax)
		{
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if ((c >= 97 && c <= 122) && input.length() < 6)
		{
			c = c - 32;
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if (c == 8 && input.length()>0)
		{
			input.erase(input.begin() + input.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 13 && input.length() > 0)// nếu là phím enter
		{
			toadoY = toadoY + 3;
			ShowCur(0);
			return;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 80)
			{
				toadoY = toadoY + 3;
				ShowCur(0);
				return;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				ShowCur(0);
				return;
			}
		}
	}
}
void XuLyNhapSo(int& n, int toadoX, int& toadoY)
{
	string x;
	x = ChuyenSoSangString(n);
	char c;
	ShowCur(1);
	while (true)
	{
		c = getch();
		if (c >= 48 && c <= 57)// nếu là số thì
		{
			x.insert(x.begin() + x.length(), c);
			cout << c;
		}
		else if (c == 8 && x.length()>0)
		{
			x.erase(x.begin() + x.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 13 && x.length() > 0)// nếu là phím enter
		{
			toadoY = toadoY + 3;
			n = atoi(x.c_str());
			ShowCur(0);
			return;
		}
		else if (c == -32)
		{
			c = getch();
			
			if (c == 80)
			{
				if (x.empty())
				{
					n = 0;
				}
				else
				{
					n = atoi(x.c_str());
				}
				toadoY = toadoY + 3;
				ShowCur(0);
				return;
			}
			else if (c == 72)
			{
				if (x.empty())
				{
					n = 0;
				}
				else
				{
					n = atoi(x.c_str());
				}
				toadoY = toadoY - 3;
				ShowCur(0);
				return;
			}
		}
	}
}
void XuLyNhapChu(string& input, int toadoX, int& toadoY, int lenghtMax)
{
	char c;
	ShowCur(1);
	while (true)
	{
		char c = _getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)) && input.length() < lenghtMax)
		{
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if (c == 8 && input.length()>0)
		{
			input.erase(input.begin() + input.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 32 && input.length() < lenghtMax && input.length() != 0 && input[input.length()-1] != ' ')
		{
			input.insert(input.begin() + input.length(), ' ');
			cout << c;
		}
		else if (c == 13 && input.length() > 0)// nếu là phím enter
		{
			toadoY = toadoY + 3;
			ShowCur(0);
			return;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 80)
			{
				toadoY = toadoY + 3;
				ShowCur(0);
				return;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				ShowCur(0);
				return;
			}
		}
	}
}

void ToMauHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauText)
{
	textcolor(mauText);
	for (int i = toadoY + 1; i < toadoY + chieucao; i++)
	{
		for (int j = toadoX + 1; j < chieudai + toadoX; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
	textcolor(7);
}
void GiaoDienThongBao(string x)
{
	ToMauHCN(80, 17, 50, 10, 95);
	textcolor(95);
	gotoXY(81, 20);
	cout << string((49 - x.length()) / 2, ' ') + x;
	getch();
	textcolor(7);
}
void tachLayTenVaHo(string str, string& ten, string& ho)
{
	int k = 0;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			k = i;
			break;
		}
	}

	for (int i = 0; i < k; i++)
	{
		ho += str[i];
	}

	for (int i = k + 1; i < str.length(); i++)
	{
		ten += str[i];
	}
}
