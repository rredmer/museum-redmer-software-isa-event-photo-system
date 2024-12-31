#if !defined(__KPDCLoader_H__)
#define __KPDCLoader_H__
////////////////////////////////////////////////////////////////////////////////
//
//	File:			KPDCLoader.h
//
//	Author(s):		Jonathan Gary
//
//	Copyright:		Copyright (c) 2000 Eastman Kodak Company.
//					All Rights Reserved.
//
//	Source:			Original.
//
//	Description:	Interface of KPDCLoader	
//					This is a loader interface for "new style" SDKs, such
//					as the DCS ProBack and 760 SDK's.
//
//					To load a library, call KPDCLoader_Load, passing the
//					code fragment name (on the Mac) or the file path to the
//					DLL (on Windows) of the library.
//					Pass the address of a KPDCProcs structure so that the
//					call can fill in the function pointers.
//
//					When done with the library, you can call KPDCLoader_Unload to
//					release the library, though the OS will do this for you when
//					the application terminates.
//
//					IMPORTANT: These functions make no calls to the libraries they load.
//					They simply load the entry points.
//
//					To call through to the SDK, simply use the appropriate function
//					pointer as you would the original function, e.g.:
//
//						KPDCLibMgrRef	libMgrRef = NULL,
//						KPDCUInt32 		optionBits = KPDCInitOptionDefault;
//						KPDCStatus 		status = KPDC_OK;
//						status = KPDCInitialize(optionBits, &libMgrRef);
//
//					is the same as:
//
//						KPDCProcs		ansel;
//						KPDCLibMgrRef 	libMgrRef = NULL,
//						KPDCUInt32 		optionBits = KPDCInitOptionDefault;
//						KPDCStatus 		status = KPDC_OK;
//
//						status = KPDCLoader_Load("KodakDCSProBackLib", &ansel);
//						if (KPDC_OK == status)
//							status = ansel.Initialize(optionBits, &libMgrRef);
//
//					Naturally, the KPDCLoader_Load only happens once for each library.
//					it is not repeated for each call! 
//
//	Change History:
//			12/8/2000	Started source.
//	
////////////////////////////////////////////////////////////////////////////////

#include "KPDCLoaderFuncTypes.h"

#ifdef macintosh
#include <CodeFragments.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif


typedef struct KPDCProcs_struct
{
	KPDCInitializeFunc						Initialize;
	KPDCTerminateFunc						Terminate;
	KPDCFreeRefFunc							FreeRef;
	KPDCSetCameraAddedNotificationFunc		SetCameraAddedNotification;
	KPDCIteratorNextFunc					IteratorNext;
	KPDCIteratorFindFunc					IteratorFind;
	KPDCIteratorResetFunc					IteratorReset;
	KPDCGetAttributeInfoFunc				GetAttributeInfo;
	KPDCGetAttributeValueFunc				GetAttributeValue;
	KPDCSetAttributeValueFunc				SetAttributeValue;
	KPDCAllocCameraIteratorFunc				AllocCameraIterator;
	KPDCSendCommandFunc						SendCommand;
	KPDCSetCameraEventNotificationFunc		SetCameraEventNotification;
	KPDCAllocPropertyIteratorFunc			AllocPropertyIterator;
	KPDCAllocDirectoryIteratorFunc			AllocDirectoryIterator;
	KPDCAllocDirItemByPathFunc				AllocDirItemByPath;
	KPDCCreateDirItemFunc					CreateDirItem;
	KPDCStartCaptureSessionFunc				StartCaptureSession;
	KPDCEndCaptureSessionFunc				EndCaptureSession;
	KPDCSetDirectoryUpdateNotificationFunc	SetDirectoryUpdateNotification;
	KPDCDeleteDirItemFunc					DeleteDirItem;
	KPDCAllocIORefFunc						AllocIORef;
	KPDCAllocIORefFromFileHandleRefFunc		AllocIORefFromFileHandleRef;
	KPDCReadFunc							Read;
	KPDCWriteFunc							Write;
	KPDCSetPositionFunc						SetPosition;
	KPDCGetPositionFunc						GetPosition;
	KPDCAllocImageFunc						AllocImage;
	KPDCGetImageRectangleFunc				GetImageRectangle;
	KPDCGetImageRectangleWithTestFunc		GetImageRectangleWithTest;
	KPDCSampleBalanceFunc					SampleBalance;
	KPDCSavePersistentAttributesFunc		SavePersistentAttributes;
	KPDCCheckImageFunc						CheckImage;
	
	// Data members below are used for cleanup.
#ifdef macintosh
	CFragConnectionID						m_connectionID;
#endif

#ifdef _WIN32
	HMODULE									m_moduleHandle;
#endif

} KPDCProcs, *KPDCProcsPtr;


KPDCStatus KPDCLoader_Load(const char* inWinFilePathOrMacFragName, KPDCProcsPtr outSDKProcs);

KPDCStatus KPDCLoader_Unload(KPDCProcsPtr inSDKProcs);

#ifdef __cplusplus
}
#endif

#endif	//__KPDCLoader_H__
