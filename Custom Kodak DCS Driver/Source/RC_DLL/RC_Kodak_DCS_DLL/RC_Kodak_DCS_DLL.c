/*---------------------------------------------------------------------------
**
**  System.....: RC Kodak DCS Camera Library
**
**  Module.....: RC_Kodak_DCS_DLL.C
**
**  Description: Kodak DCS Camera Implemented in DLL for Microsoft Visual
**               Basic.
**
**  Environment: Microsoft Visual Studio .NET Version 7.00 (C++)
**
**  Notes......: This requires the Kodak DCS DLLs (DCSPro3SLR.dll) to be in
**               the WINDOWS\SYSTEM32 directory (WINROOT).  The Kodak Camera
**               Management software must be installed and operational.
**
**  (c) 2002 Redmer Controls Inc.  All Rights Reserved.
**-------------------------------------------------------------------------*/
#include <windows.h>
#include <winreg.h>
#include <winerror.h>

#include <io.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

#include "KPDCLoader.h"

// #define RC_TEST_HARNESS		1

#define DllExport __declspec( dllexport )

KPDCProcs		proBack;
KPDCLibMgrRef libMgrRef;
KPDCCameraIterRef camIter; 
KPDCCameraRef camera; 
KPDCInt32		sdkVersion[3];
char serialNumber[40]; 

#ifdef RC_TEST_HARNESS
	int RC_Kodak_Load( int *index )
#else
	DllExport int _stdcall RC_Kodak_Load( int *index )
#endif
{
	KPDCStatus 		status = KPDC_OK;
	KPDCUInt32		attrSize = 3;
//	KPDCUInt32 		optionBits = KPDCInitOptionDefault;		//|KPDCInitOptionEnableIEEE1394;
	KPDCUInt32 		optionBits = KPDCInitOptionEnableIEEE1394;

	status = KPDCLoader_Load("c:\\Kodak\\DCSPro3SLR.dll", &proBack);
	// status = KPDCLoader_Load("DCSPro3SLR.dll", &proBack);

	if (KPDC_OK == status)
		status = proBack.Initialize(optionBits, &libMgrRef);
		
	if (KPDC_OK == status)
		status = proBack.GetAttributeValue(libMgrRef, KPDCLibVersionID, &attrSize, &sdkVersion);

	return status;
}

#ifdef RC_TEST_HARNESS
	int RC_Kodak_Unload(void)
#else
	DllExport int _stdcall RC_Kodak_Unload(void)
#endif
{
	KPDCStatus 		status = KPDC_OK;

	status = proBack.Terminate(libMgrRef);
		
	if (KPDC_OK == status)
		KPDCLoader_Unload(&proBack);

	return status;
}


#ifdef RC_TEST_HARNESS
	int RC_Kodak_GetCamera(char *sHostSerial)
#else
	DllExport int _stdcall RC_Kodak_GetCamera(char *sHostSerial)
#endif
{
	KPDCStatus status = KPDC_OK; 
	KPDCUInt32 serialNumberLen = 0; 
	KPDCDataType serialNumType; 

	// Allocate a camera iterator 
	status = proBack.AllocCameraIterator(libMgrRef, &camIter); 
	if (status != KPDC_OK) 
		return -1;

	// get the first camera 
	status = proBack.IteratorNext(camIter, &camera); 
	if (status != KPDC_OK) 
		return -2;

	// Find out how big the serial number attribute is. 
	status = proBack.GetAttributeInfo(camera, KPDCSerialNumberStringID, &serialNumType, &serialNumberLen); 
	if (status != KPDC_OK) 
		return -3;

	// Allocate a buffer big enough to contain the attribute. 
//	serialNumber = malloc(serialNumberLen); 

	strcpy(serialNumber, "");

//	if (serialNumber == NULL) 
//		myOutOfMemoryError(); 

	// Get the value of the attribute. 
	status = proBack.GetAttributeValue(camera, KPDCSerialNumberStringID, &serialNumberLen, serialNumber); 

	strncpy(sHostSerial, serialNumber, serialNumberLen);

	return status;
}


#ifdef RC_TEST_HARNESS
	int RC_Kodak_FreeCamera(void)
#else
	DllExport int _stdcall RC_Kodak_FreeCamera(void)
#endif
{
	// Done with the camera, free it up 
	proBack.FreeRef(camera); 
	proBack.FreeRef(camIter);
	return 0;
}


#ifdef RC_TEST_HARNESS
	int RC_Kodak_MoveCameraFiles(char *cFileName)
#else
	DllExport int _stdcall RC_Kodak_MoveCameraFiles(char *cFileName)
#endif
{
	int status = 0;
	KPDCDirectoryIterRef dirIter, topDirItem;
	KPDCDirItemRef dirItem;
	KPDCIORef io;
	KPDCImageRef outImage;
	KPDCUInt32 fileSize;
	KPDCUInt32 fileSizeSize = 1;
	KPDCUInt8  *buffer = NULL;
	int out;
	int iFileNo = 0;
	unsigned int blockSize = 500000;
	char path[512];
	char cDirName[128];
	char fileName[50];
	long outbytes = 0;
	long curBlock = 0;
	int iDone = 0;
	int iNumFiles = 0;

	strcpy(path, serialNumber);
	strcat(path, "/CARD2/FOLDER01");

	strcpy(cDirName, "C:\\ImageBuffer\\IMG");

	status = proBack.AllocDirItemByPath(camera, path, &topDirItem);

	if (status != KPDC_OK)
		return -1;

	status = proBack.AllocDirectoryIterator(topDirItem, &dirIter);
	if (status != KPDC_OK)
		return -2;

	while (status == KPDC_OK)
	{
		status = proBack.IteratorNext(dirIter, &dirItem);
		if (status == KPDC_OK)
		{
			//--- Determine File Attributes
			status = proBack.GetAttributeValue(dirItem, KPDCDirItemSizeID, &fileSizeSize, &fileSize);
			if (status != KPDC_OK)
				return -3;
			
			status = proBack.AllocIORef(dirItem, &io);
			if (status != KPDC_OK)
				return -4;

			iFileNo++;
			status = proBack.SetPosition(io, 0);

			buffer = (KPDCUInt8 *) malloc(blockSize+1);
			sprintf(fileName, "%s_%2.2d.DCR", cDirName, iFileNo);
			out = _open(fileName, _O_RDWR | _O_CREAT | _O_BINARY);
			if (out != -1)
			{
				iDone = 0;
				outbytes = 0;

				while (outbytes != fileSize)
				{
					if (outbytes + blockSize > fileSize)
						curBlock = fileSize-outbytes;
					else
						curBlock = blockSize;

					status = proBack.Read(io, curBlock, buffer);

					_write(out, buffer, curBlock);
					outbytes = outbytes + curBlock;

				}
				iNumFiles++;
			}
			free(buffer);
			proBack.FreeRef(io);
			_close(out);
			status = proBack.DeleteDirItem(dirItem);

			proBack.FreeRef(dirItem);
		}
	}
	proBack.FreeRef(dirIter);
	proBack.FreeRef(topDirItem);
	return iNumFiles;
}
