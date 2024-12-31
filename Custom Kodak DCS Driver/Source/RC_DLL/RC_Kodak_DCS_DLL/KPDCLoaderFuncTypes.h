#if !defined(__KPDCLoaderFuncTypes_H__)
#define __KPDCLoaderFuncTypes_H__
////////////////////////////////////////////////////////////////////////////////
//
//	File:			KPDCLoaderFuncTypes.h
//
//	Author(s):		Jonathan Gary
//
//	Copyright:		Copyright (c) 2000 Eastman Kodak Company.
//					All Rights Reserved.
//
//	Source:			Original.
//
//	Description:	Typedefs for all of the entry pointe in the new SDK's.
//
//	Change History:
//			12/8/2000	Started source.
//	
////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif

#include "KProDCSDK.h"
// Typedefs for all of the SDK entry points.

typedef KPDCStatus (*KPDCInitializeFunc)(KPDCUInt32 inOptionBits,
				KPDCLibMgrRef *outManagerRef);

typedef KPDCStatus (*KPDCTerminateFunc)(
				KPDCLibMgrRef inManagerRef);

typedef KPDCStatus (*KPDCFreeRefFunc)(
				KPDCOpaqueRef inItemRef);

typedef KPDCStatus (*KPDCSetCameraAddedNotificationFunc)(
				KPDCLibMgrRef inManagerRef,
				KPDCCameraAddedNotificationFunc inCameraAddedNotificationFunc,
				void* inUserData);

typedef KPDCStatus (*KPDCIteratorNextFunc)(
			KPDCIteratorRef inIteratorRef, 
			KPDCOpaqueRef *outNextItemRef);
			
typedef KPDCStatus (*KPDCIteratorFindFunc)(
			KPDCIteratorRef inIteratorRef,
			const char* inName, 
			KPDCOpaqueRef *outFoundItemRef);


typedef KPDCStatus (*KPDCIteratorResetFunc)(
			KPDCIteratorRef inIteratorRef);

typedef KPDCStatus (*KPDCGetAttributeInfoFunc)(
			KPDCOpaqueRef inRef,
			KPDCAttributeID inAttrID,
			KPDCDataType *outAttrType,
			KPDCUInt32 *outAttrSize);

typedef KPDCStatus (*KPDCGetAttributeValueFunc)(
			KPDCOpaqueRef inRef,
			KPDCAttributeID inAttrID,
			KPDCUInt32 *inOutAttrSize,
			void* outAttrValue);
			
typedef KPDCStatus (*KPDCSetAttributeValueFunc)(
			KPDCOpaqueRef inRef,
			KPDCAttributeID inAttrID,
			KPDCDataType inType,
			KPDCUInt32 inAttrSize,
			void* inAttrValue);

typedef KPDCStatus (*KPDCAllocCameraIteratorFunc)(
			KPDCOpaqueRef inManagerRef, 
			KPDCCameraIterRef *outCameraIterRef);

typedef KPDCStatus (*KPDCSendCommandFunc)(
			KPDCCameraRef inCameraRef, 
			KPDCUInt32 inCommand);

typedef KPDCStatus (*KPDCSetCameraEventNotificationFunc)(
				KPDCCameraRef inCameraRef, 
				KPDCCameraEventNotificationFunc inCameraEventNotificationFunc,
				void* inUserData);

typedef KPDCStatus (*KPDCAllocPropertyIteratorFunc)(
			KPDCCameraRef inCameraRef, 
			KPDCPropertyIterRef *outPropertyIterRef);

typedef KPDCStatus (*KPDCAllocDirectoryIteratorFunc)(
			KPDCOpaqueRef inCameraOrDirItemRef, 
			KPDCDirectoryIterRef *outDirIterRef);

typedef KPDCStatus (*KPDCAllocDirItemByPathFunc)(
			KPDCCameraRef inCamera,
			const char *inPath,
			KPDCDirItemRef *outDirItem);

typedef KPDCStatus (*KPDCCreateDirItemFunc)(
			KPDCDirItemRef inDirItem,
			const char *inName,
			KPDCBool inCreateAsFolder);

typedef KPDCStatus (*KPDCStartCaptureSessionFunc)(
			KPDCCameraRef						inCamera,
			KPDCCaptureStartNotificationFunc	inStartNotificationFunc,
			KPDCPreviewNotificationFunc			inPreviewNotificationFunc,
			KPDCCaptureCopyNotificationFunc		inCopyProgressNotificationFunc,
			void								*inUserData);
			
typedef KPDCStatus (*KPDCEndCaptureSessionFunc)(KPDCCameraRef inCameraRef);
			
typedef KPDCStatus (*KPDCSetDirectoryUpdateNotificationFunc)(
			KPDCDirectoryIterRef inDirIterRef, 
			KPDCDirUpdateNotificationFunc inNotificationFunc,
			void *inUserData);

typedef KPDCStatus (*KPDCDeleteDirItemFunc) (
			KPDCDirItemRef inDirItemRef);


typedef KPDCStatus (*KPDCAllocIORefFunc)(
			KPDCDirItemRef inDirItemRef,
			KPDCIORef *outIORef);

typedef KPDCStatus (*KPDCAllocIORefFromFileHandleRefFunc)(
			KPDCLibMgrRef inManagerRef,
			KPDCFileRefHandle inFileRefHandle,
			KPDCIORef *outIORef);


typedef KPDCStatus (*KPDCReadFunc)(
			KPDCIORef inIORef,
			KPDCUInt32 inCount,
			KPDCUInt8 *outBuffer);

typedef KPDCStatus (*KPDCWriteFunc)(
			KPDCIORef inIORef,
			KPDCUInt32 inCount,
			KPDCUInt8 *inBuffer);

typedef KPDCStatus (*KPDCSetPositionFunc)(
			KPDCIORef inIORef,
			KPDCUInt32 inOffset);

typedef KPDCStatus (*KPDCGetPositionFunc)(
			KPDCIORef inIORef,
			KPDCUInt32 *outOffset);


typedef KPDCStatus (*KPDCAllocImageFunc)(
			KPDCLibMgrRef inMgr, 
			KPDCIORef inIO, 
			KPDCImageRef *outImage);


typedef KPDCStatus (*KPDCGetImageRectangleFunc)(
			KPDCImageRef inImage, 
			KPDCInt32 inSourceRes, 
			const KPDCRect *inRect, 
			KPDCPixelLayout *inPixLayout, 
			KPDCProgressNotificationFunc inProgFunc,
			void *inUserData);


typedef KPDCStatus (*KPDCGetImageRectangleWithTestFunc)(
			KPDCImageRef inImage, 
			KPDCInt32 inSourceRes, 
			const KPDCRect *inRect, 
			KPDCPixelLayout *inPixLayout, 
			KPDCProgressNotificationFunc inProgFunc,
			void *inUserData,
			KPDCPointer	inStartOfBuffer,
			KPDCUInt32	inBufferByteCount,
			KPDCUInt32	inTotalChannelCount);


typedef KPDCStatus (*KPDCSampleBalanceFunc)(
			KPDCImageRef inImage, 
			KPDCUInt32 inResSource,
			const KPDCRect* inRect, 
			KPDCUInt16 *outSample, 
			KPDCUInt32* inOutSampleSize);


typedef KPDCStatus (*KPDCSavePersistentAttributesFunc)(
			KPDCImageRef inImage);


typedef KPDCStatus (*KPDCCheckImageFunc)(
			KPDCImageRef inImage);
			
////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif // __KPDCLoaderFuncTypes_H__