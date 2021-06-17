#include"Controller.h"

int main()
{
	DSDauSach dsDS;
	DSDocGia dsDG;
	Init(dsDS, dsDG);
	while (true)
	{
		Run(dsDG, dsDS);
	}
	return 0;
}
