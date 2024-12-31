#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


int main(void);

char sHostSerial[100];

int main()
{
	int iStatus = 0;				// Return Code

	printf("\nRC Kodak DCS Library Test Harness\nVersion 1.0");
	printf("\n---------------------------------");


	//---- Load the DLL
	iStatus = RC_Kodak_Load(0);
	printf("\nKodak_Load returned: %d", iStatus);

	iStatus = RC_Kodak_GetCamera(sHostSerial);
	printf("\nKodak_GetCamera returned: %d [%s]", iStatus, sHostSerial);

	iStatus = RC_Kodak_MoveCameraFiles("D:\\TEST");
	printf("\nKodak_MoveCameraFiles returned: %d", iStatus);

	iStatus = RC_Kodak_FreeCamera();

	//---- Unload the DLL
	iStatus = RC_Kodak_Unload();
	printf("\nKodak_Unload returned: %d", iStatus);

	getch();

	return 0;
}