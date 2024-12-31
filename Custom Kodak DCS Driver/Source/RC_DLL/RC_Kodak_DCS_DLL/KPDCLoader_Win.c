////////////////////////////////////////////////////////////////////////////////
//
//	File:			KPDCLoader_Win.c
//
//	Author(s):		Jonathan Gary
//
//	Copyright:		Copyright (c) 2000 Eastman Kodak Company.
//					All Rights Reserved.
//
//	Description:	Implementation of KPDCLoader for Win 32.	
//	
//	Change History:
//			12/11/2000	Creation. - Did on on a Mac. Some Windows dude will need to test it!
//	
////////////////////////////////////////////////////////////////////////////////

#include "KPDCLoader.h"
#include <string.h>


////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCLoader_Load		
//	Author:		Jon Gary		Date: 12/8/2000
//
//	Description:
//	Load the function pointers into the struct.
//
//	Complexity (Estimated):		0
//	Complexity (Implemented):	3
//
//	Parameters:
//		 In:	inLibraryName - the name of the library (file on windows, fragname on mac)
//		Out:	outSDKProcs - the structure into which the entry points are loaded.
//	  InOut:	
//	Returns:	Win32 errors as well as KPDC_ParamErr;
//	 Throws:	
////////////////////////////////////////////////////////////////////////////////

KPDCStatus KPDCLoader_Load(const char* inLibraryName, KPDCProcsPtr outSDKProcs)
{
	KPDCStatus status = KPDC_OK;

	//-----------------------------------------------
	// Check parameters
	//-----------------------------------------------
	if (NULL == inLibraryName) return KPDC_ParamErr;
	if (NULL == outSDKProcs) return KPDC_ParamErr;
	
	//-----------------------------------------------
	// Load the library
	//-----------------------------------------------
	
	memset(outSDKProcs, 0, sizeof(KPDCProcs));
	
	outSDKProcs->m_moduleHandle = LoadLibrary(inLibraryName);
	if (NULL == outSDKProcs->m_moduleHandle)
	{
		status = GetLastError();
		return status;
	}

	//-----------------------------------------------
	// Now tediously load each of the function pointers.
	//-----------------------------------------------
	do
	{
		outSDKProcs->Initialize = (KPDCInitializeFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCInitialize");
		if (NULL == outSDKProcs->Initialize)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->Terminate = (KPDCTerminateFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCTerminate");
		if (NULL == outSDKProcs->Terminate)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->FreeRef = (KPDCFreeRefFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCFreeRef");
		if (NULL == outSDKProcs->FreeRef)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->SetCameraAddedNotification = (KPDCSetCameraAddedNotificationFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCSetCameraAddedNotification");
		if (NULL == outSDKProcs->SetCameraAddedNotification)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->IteratorNext = (KPDCIteratorNextFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCIteratorNext");
		if (NULL == outSDKProcs->IteratorNext)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->IteratorFind = (KPDCIteratorFindFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCIteratorFind");
		if (NULL == outSDKProcs->IteratorFind)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->IteratorReset = (KPDCIteratorResetFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCIteratorReset");
		if (NULL == outSDKProcs->IteratorReset)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->GetAttributeInfo = (KPDCGetAttributeInfoFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCGetAttributeInfo");
		if (NULL == outSDKProcs->GetAttributeInfo)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->GetAttributeValue = (KPDCGetAttributeValueFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCGetAttributeValue");
		if (NULL == outSDKProcs->GetAttributeValue)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->SetAttributeValue = (KPDCSetAttributeValueFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCSetAttributeValue");
		if (NULL == outSDKProcs->SetAttributeValue)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->AllocCameraIterator = (KPDCAllocCameraIteratorFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCAllocCameraIterator");
		if (NULL == outSDKProcs->AllocCameraIterator)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->SendCommand = (KPDCSendCommandFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCSendCommand");
		if (NULL == outSDKProcs->SendCommand)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->SetCameraEventNotification = (KPDCSetCameraEventNotificationFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCSetCameraEventNotification");
		if (NULL == outSDKProcs->SetCameraEventNotification)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->AllocPropertyIterator = (KPDCAllocPropertyIteratorFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCAllocPropertyIterator");
		if (NULL == outSDKProcs->AllocPropertyIterator)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->AllocDirectoryIterator = (KPDCAllocDirectoryIteratorFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCAllocDirectoryIterator");
		if (NULL == outSDKProcs->AllocDirectoryIterator)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->AllocDirItemByPath = (KPDCAllocDirItemByPathFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCAllocDirItemByPath");
		if (NULL == outSDKProcs->AllocDirItemByPath)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->CreateDirItem = (KPDCCreateDirItemFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCCreateDirItem");
		if (NULL == outSDKProcs->CreateDirItem)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->StartCaptureSession = (KPDCStartCaptureSessionFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCStartCaptureSession");
		if (NULL == outSDKProcs->StartCaptureSession)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->EndCaptureSession = (KPDCEndCaptureSessionFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCEndCaptureSession");
		if (NULL == outSDKProcs->EndCaptureSession)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->SetDirectoryUpdateNotification = (KPDCSetDirectoryUpdateNotificationFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCSetDirectoryUpdateNotification");
		if (NULL == outSDKProcs->SetDirectoryUpdateNotification)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->DeleteDirItem = (KPDCDeleteDirItemFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCDeleteDirItem");
		if (NULL == outSDKProcs->DeleteDirItem)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->AllocIORef = (KPDCAllocIORefFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCAllocIORef");
		if (NULL == outSDKProcs->AllocIORef)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->AllocIORefFromFileHandleRef = (KPDCAllocIORefFromFileHandleRefFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCAllocIORefFromFileHandleRef");
		if (NULL == outSDKProcs->AllocIORefFromFileHandleRef)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->Read = (KPDCReadFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCRead");
		if (NULL == outSDKProcs->Read)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->Write = (KPDCWriteFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCWrite");
		if (NULL == outSDKProcs->Write)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->SetPosition = (KPDCSetPositionFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCSetPosition");
		if (NULL == outSDKProcs->SetPosition)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->GetPosition = (KPDCGetPositionFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCGetPosition");
		if (NULL == outSDKProcs->GetPosition)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->AllocImage = (KPDCAllocImageFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCAllocImage");
		if (NULL == outSDKProcs->AllocImage)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->GetImageRectangle = (KPDCGetImageRectangleFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCGetImageRectangle");
		if (NULL == outSDKProcs->GetImageRectangle)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->GetImageRectangleWithTest = (KPDCGetImageRectangleWithTestFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCGetImageRectangleWithTest");
		if (NULL == outSDKProcs->GetImageRectangleWithTest)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->SampleBalance = (KPDCSampleBalanceFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCSampleBalance");
		if (NULL == outSDKProcs->SampleBalance)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->SavePersistentAttributes = (KPDCSavePersistentAttributesFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCSavePersistentAttributes");
		if (NULL == outSDKProcs->SavePersistentAttributes)
		{
			status = GetLastError();
			break;
		}
		
		outSDKProcs->CheckImage = (KPDCCheckImageFunc)GetProcAddress(outSDKProcs->m_moduleHandle, "KPDCCheckImage");
		if (NULL == outSDKProcs->CheckImage)
		{
			status = GetLastError();
			break;
		}
		
	} while (0);
	
	return status;
}


////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCLoader_Unload		
//	Author:		Jon Gary		Date: 12/8/2000
//
//	Description:
//	Clean up a loaded library. This makes no calls!!
//
//	Complexity (Estimated):		0
//	Complexity (Implemented):	1
//
//	Parameters:
//		 In:	inSDKProcs - the structure into which the entry points are loaded.
//	Returns:	Win32 errors as well as KPDC_ParamErr;
//	 Throws:	
////////////////////////////////////////////////////////////////////////////////

KPDCStatus KPDCLoader_Unload(KPDCProcsPtr inSDKProcs)
{
	HMODULE modHandle = 0;
	
	if (NULL == inSDKProcs) return KPDC_ParamErr;

	modHandle = inSDKProcs->m_moduleHandle;
	FreeLibrary(modHandle);
	memset(inSDKProcs, 0, sizeof(KPDCProcs));
	
	return GetLastError();
}
