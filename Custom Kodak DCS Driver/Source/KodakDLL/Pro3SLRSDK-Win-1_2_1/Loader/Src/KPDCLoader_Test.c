#include <stdio.h>

#include "KPDCLoader.h"

int main(int argc, char *argv[])
{
	KPDCProcs		proBack;
	KPDCLibMgrRef 	libMgrRef = NULL;
	KPDCUInt32 		optionBits = KPDCInitOptionDefault;
	KPDCStatus 		status = KPDC_OK;
	KPDCInt32		sdkVersion[3];
	KPDCUInt32		attrSize = 3;
	status = KPDCLoader_Load("KodakDCSProBackLib", &proBack);
	

	
	if (KPDC_OK == status)
		status = proBack.Initialize(optionBits, &libMgrRef);
		
	if (KPDC_OK == status)
		status = proBack.GetAttributeValue(libMgrRef, KPDCLibVersionID, &attrSize, &sdkVersion);

	if (KPDC_OK == status)
	{
		printf("Loaded SDK version %d.%d.%d\n", sdkVersion[0], sdkVersion[1], sdkVersion[2]);
	}
	else
	{
		printf("Loaded SDK  failed, status = %d\n", status);
	}
	
	if (KPDC_OK == status)
		status = proBack.Terminate(libMgrRef);
		
	if (KPDC_OK == status)
		KPDCLoader_Unload(&proBack);

	if (KPDC_OK == status)
	{
		printf("Unloaded SDK version %d.%d.%d OK!\n", sdkVersion[0], sdkVersion[1], sdkVersion[2]);
	}
	else
	{
		printf("Unload SDK  failed, status = %d\n", status);
	}
	
	return status;
}