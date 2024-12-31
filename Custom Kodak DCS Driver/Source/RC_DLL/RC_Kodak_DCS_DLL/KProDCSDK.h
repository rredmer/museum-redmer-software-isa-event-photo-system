#if !defined(__KProDCSDK_H__)
#define __KProDCSDK_H__
////////////////////////////////////////////////////////////////////////////////
//
//	File:			KProDCSDK.h
//
//	Copyright:		Copyright (c) 2000 Eastman Kodak Company.
//					All Rights Reserved.
//
//	Source:			Original.
//
//	Description:	Interface for Kodak Professional Digital Camera SDK
//					loadable libraries.
//
//	Change History:
//			12/28/99	Started source.
//	
////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif

#include "KProDCSDKTypes.h"
#include "KProDCSDKErrors.h"

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef macintosh
	#if !defined(KPDCENTRY) // Was KPDCEXPORT, JimS changed on Mike's direction
		#define KPDCENTRY   // Was KPDCEXPORT, JimS changed on Mike's direction
	#endif
#elif WIN32
	// Packing for data structure alignment: This ensures that applications
	// - will align the data structures the same way as the library does
	// - internally. The previous value is popped at the end of this file.
	#pragma pack (push, 8)
		
	// Definitions for exportation, exposes the interface
	#ifndef KPDCEXPORT
		#define KPDCEXPORT      __declspec (dllexport)
	#endif

	#ifndef KPDCIMPORT
		#define KPDCIMPORT		__declspec (dllimport)
	#endif

	// Build dependencies
	#ifdef DCSPRO3SLR_EXPORTS
		#ifndef KPDCENTRY
			#define KPDCENTRY		KPDCEXPORT
		#endif
	#elif  DCSPROBACK_EXPORTS
		#ifndef KPDCENTRY
			#define KPDCENTRY		KPDCEXPORT 
		#endif
	#else
		#ifndef KPDCENTRY
			#define KPDCENTRY		KPDCIMPORT
		#endif
	#endif
#endif

//#pragma export on
// Switched to export file.

////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCInitialize		
//
//	Description:
//	Initialize the SDK and return a reference to the manager for this library.
//	This function must be called once per process and balanced with a call
//	to KPDCTerminate.
//
//	Parameters:
//		 In:	inOptionBits - This parameter specifies a bit string. Each bit 
//					in the string representing a particular option for initialization.
//		Out:	outManagerRef - the address of an KPDCOpaqueRef in which a reference
//					to the library manager can be stored.
//	Returns:	Any of the tool kit errors.
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCInitialize(	KPDCUInt32		inOptionBits,
										KPDCLibMgrRef*	outManagerRef);


////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCTerminate		
//
//	Description:
//	Terminate the library, releasing all resources.
//
//	Parameters:
//		Out:	inManagerRef - The KPDCOpaqueRef for the library manager. Should be
//					the output of KPDCInitialize.
//	Returns:	Any of the tool kit errors.
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCTerminate(KPDCLibMgrRef inManagerRef);


////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCFreeRef		
//
//	Description:
//	Free the resources associated with the object referenced by inItemRef
//
//	Parameters:
//		 In:	inItemRef - The KPDCOpaqueRef for the item. Do not pass
//					the reference to the library manager to this function.
//					Use KPDCTerminate in that case.
//	Returns:	Any of the tool kit errors.
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCFreeRef(KPDCOpaqueRef inItemRef);
				
////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCSetCameraAddedNotification		
//
//	Description:
//	Set a callback to be called when a new camera is detected on the system.
//
//	Parameters:
//		 In:	inManagerRef - The KPDCOpaqueRef for the library manager.
//				inCameraAddedNotificationFunc - address of the notification routine.
//				inUserData - user data.
//	Returns:	Any of the tool kit errors.
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCSetCameraAddedNotification(
				KPDCLibMgrRef					inManagerRef,
				KPDCCameraAddedNotificationFunc inCameraAddedNotificationFunc,
				void*							inUserData);


////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCIteratorNext		
//
//	Description:
//	Return a reference to the next enumerated item. After creating a new iterator or
//	calling KPDCIteratorReset, this returns the first item. If there are no more items,
//	the outNextItemRef will not be valid.
//
//	Items returned are allocated and thus should be released by calling KPDCFreeRef.
//
//	Parameters:
//		 In:	inIteratorRef  - a reference to an iterator.
//		Out:	outNextItemRef - the address of an KPDCOpaqueRef in which a reference
//							to the next item can be stored.
//	Returns:	Any of the tool kit errors.
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCIteratorNext(	KPDCIteratorRef inIteratorRef, 
										KPDCOpaqueRef*	outNextItemRef);

////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCIteratorFind		
//
//	Description:
//	Return a reference to the first item with the name specified by inName. The 
//	iterator will point to the found item so that KPDCIteratorNext will return the 
//	item following the found item in the list.
//
//	Items returned are allocated and thus should be released by calling KPDCFreeRef.
//
//	Parameters:
//		 In:	inIteratorRef  - a reference to an iterator.
//				inName - the address of a null terminated, 8-bit ASCII string.
//		Out:	outFoundItemRef - the address of an KPDCOpaqueRef in which a reference
//							to the found item can be stored.
//	Returns:	Any of the tool kit errors, KPDC_IterItemNotFoundErr.
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCIteratorFind(	KPDCIteratorRef inIteratorRef,
										const char*		inName, 
										KPDCOpaqueRef*	outFoundItemRef);

////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCIteratorReset	
//
//	Description:
//	Reset the iterator to point to the beginning of the list.
//
//	Parameters:
//		 In:	inIteratorRef  - a reference to an iterator.
//	Returns:	Any of the tool kit errors,
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCIteratorReset(KPDCIteratorRef inIteratorRef);
			

////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCGetAttributeInfo	
//
//	Description:
//	Get the size and type for the specified attribute ID
//
//	Parameters:
//		 In:	inRef  - a reference to an object that has the attribute.
//				inAttrID - the ID of an attribute of the object referred to by inRef.
//		Out:	outAttrType - The type of the attribute.
//				outAttrSize - The size  of the attribute, in items of the size of the type.
//							The size in bytes is (sizeoftype(outAttrType) * outAttrSize).
//	Returns:	Any of the tool kit errors, KPDC_InvalidAttrIDErr
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCGetAttributeInfo(	KPDCOpaqueRef	inRef,
											KPDCAttributeID inAttrID,
											KPDCDataType*	outAttrType,
											KPDCUInt32*		outAttrSize);
			

////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCGetAttributeValue	
//
//	Description:
//	Get the value of the specified attribute ID
//
//	Parameters:
//		 In:	inRef  - a reference to an object that has the attribute.
//				inAttrID - the ID of an attribute of the object referred to by inRef.
//		Out:	outAttrValue - The value of the attribute.
//	  InOut:	inOutAttrSize - On entry, the size of the output buffer, upon return
//						the number of items in the output buffer.
//	Returns:	Any of the tool kit errors, KPDC_InvalidAttrIDErr
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCGetAttributeValue(	KPDCOpaqueRef	inRef,
											KPDCAttributeID inAttrID,
											KPDCUInt32*		inOutAttrSize,
											void*			outAttrValue);
			
////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCSetAttributeValue	
//
//	Description:
//	Set the value of the specified attribute ID
//
//	Parameters:
//		 In:	inRef  - a reference to an object that has the attribute.
//				inAttrID - the ID of an attribute of the object referred to by inRef.
//				inType - The type of the attribute.
//	 			inAttrSize - The size of the provided value buffer.
//				inAttrValue - The address of the attribute value.
//	Returns:	Any of the tool kit errors, KPDC_InvalidAttrIDErr
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCSetAttributeValue(	KPDCOpaqueRef	inRef,
											KPDCAttributeID inAttrID,
											KPDCDataType	inType,
											KPDCUInt32		inAttrSize,
											void*			inAttrValue);

///////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCAllocCameraIterator		
//
//	Description:
//	Create a camera iterator which can be used to check for connected cameras.
//	If there are no cameras, calling KPDCIteratorNext the first time will return 
//	KPDC_IterEndOfListErr.
//
//	Items returned by KPDCIteratorNext will be KPDCCameraRef's.
//
//	The iterator should be destroyed by calling KPDCFreeRef.
//
//	Parameters:
//		 In:	inManagerRef - The KPDCOpaqueRef for the library manager.
//		Out:	outCameraIterRef - the address of an KPDCOpaqueRef in which a reference
//							to a camera iterator will be stored.
//	Returns:	Any of the tool kit errors.
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCAllocCameraIterator(	
									KPDCOpaqueRef		inManagerRef, 
									KPDCCameraIterRef*	outCameraIterRef);


///////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCSendCommand		
//
//	Description:
//	Send a command to the camera.
//
//	Parameters:
//		 In:	inCameraRef - A reference to the camera.
//				inCommand - the command to issue.
//	Returns:	Any of the tool kit errors,
//				KPDC_InvalidCommandErr, KPDC_CommandFailedErr
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCSendCommand(	KPDCCameraRef	inCameraRef, 
										KPDCUInt32		inCommand);


////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCSetCameraEventNotification		
//
//	Description:
//	Set a callback to be called when a camera event occurs.
//
//	Parameters:
//		 In:	inCameraRef - The KPDCOpaqueRef for the camera.
//				inCameraEventNotificationFunc - address of the notification routine.
//				inUserData - user data.
//	Returns:	Any of the tool kit errors.
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCSetCameraEventNotification(
				KPDCCameraRef					inCameraRef, 
				KPDCCameraEventNotificationFunc inCameraEventNotificationFunc,
				void*							inUserData);


///////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCAllocPropertyIterator		
//
//	Description:
//	Create a property iterator which can be used to read the list of properties
//	from a camera.
//
//	Items returned by KPDCIteratorNext will be KPDCPropertyRef's.
//
//	The iterator should be destroyed by calling KPDCFreeRef.
//
//	Parameters:
//		 In:	inCameraRef - The KPDCOpaqueRef for the camera.
//		Out:	outPropertyIterRef - the address of an KPDCOpaqueRef in which a reference
//							to a property iterator will be stored.
//	Returns:	Any of the tool kit errors.
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCAllocPropertyIterator(
								KPDCCameraRef				inCameraRef, 
								KPDCPropertyIterRef*		outPropertyIterRef);


///////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCAllocDirectoryIterator		
//
//	Description:
//	Create a directory iterator which can be used to read the list of items
//	in a directory from a camera.
//
//	Items returned by KPDCIteratorNext will be KPDCDirItemRef's.
//
//	The iterator should be destroyed by calling KPDCFreeRef.
//
//	Parameters:
//		 In:	inCameraOrDirItemRef - The KPDCOpaqueRef of a camera or directory item.
//		Out:	outCameraIterRef - the address of an KPDCOpaqueRef in which a reference
//							to a camera iterator will be stored.
//	Returns:	Any of the tool kit errors.
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCAllocDirectoryIterator(
					KPDCOpaqueRef			inCameraOrDirItemRef, 
					KPDCDirectoryIterRef*	outDirIterRef);

////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCAllocDirItemByPath		
//	Author:		Jon Gary		Date: 1/28/2000
//
//	Description:
//	Create a directory item reference for an item in the camera's file system
//	using a full path to the item.
//
//	Parameters:
//		 In:	inCamera - the camera the file is on
//				inPath - C string containing the full path name
//		Out:	outDirItem - the address of a KPDCDirItemRef in which a reference
//				to a directory item will be stored.
//	Returns:	
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCAllocDirItemByPath(KPDCCameraRef	inCamera,
											const char*		inPath,
											KPDCDirItemRef*	outDirItem);

////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCCreateDirItem		
//	Author:		Jon Gary		Date: 10/12/2000
//
//	Description:
//	Create a directory item in the camera's file system
//	within the directory of the directory item provided. 
//	This function can create a file or folder.
//
//	Parameters:
//		 In:	inDirItem - the directory item of the folder the file should be
//					created in.
//				inName - C string containing the name of the item
//				inCreateAsFolder - if true, create a folder rather than a file.
//		Out:	
//	Returns:	
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCCreateDirItem(	KPDCDirItemRef	inDirItem,
										const char*		inName,
										KPDCBool		inCreateAsFolder);

////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCStartCaptureSession		
//	Author:		Jon Gary		Date: 1/27/2000
//
//	Description:
//	Setup all of the parameters needed to capture from camera memory to
//	host disk. After calling this function, every time the camera captures
//	an image, the preview will begin to stream to the inPreviewBuffer, with
//	notifications for segments of the image as they become available. After
//	the preview is complete, the rest of the file will be transferred. 
//  inCopyProgressNotificationFunc will be called to provide status and progress
//	information for the file copy.
//
//	Before calling this function, check the value of attribute KPDCSupportsCaptureSessionID
//	to determine if the camera supports this feature.
//
//	Parameters:
//		 In:	inCameraRef - the camera to capture from.
//
//
//				inStartNotificationFunc - function to be called when a capture has
//					started.
//
//				inPreviewNotificationFunc - function to be called when a section of
//					preview data is ready, so that the screen can be painted quickly.
//
//				inCopyProgressNotificationFunc - function to be called as the image 
//					file is moved to disk and is ready for access.
//
//				inUserData - your data to be passed to inStartNotificationFunc,
//					inPreviewNotificationFunc and inEndNotificationFunc functions.
//	Returns:	
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCStartCaptureSession(
		KPDCCameraRef							inCamera,
		KPDCCaptureStartNotificationFunc		inStartNotificationFunc,
		KPDCPreviewNotificationFunc				inPreviewNotificationFunc,
		KPDCCaptureCopyNotificationFunc			inCopyProgressNotificationFunc,
		void*									inUserData);
			
////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCEndCaptureSession		
//	Author:		Jon Gary		Date: 1/28/2000
//
//	Description:
//	Disables further automated capture processing. If a capture is in progress, 
//	this function will wait for the capture to complete.
//
//	Returns:	
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCEndCaptureSession(KPDCCameraRef inCameraRef);
			

///////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCSetDirectoryUpdateNotification		
//
//	Description:
//	Set a callback to receive notification when a file is added or removed from 
//	the directory referenced by the specified directory iterator.
//	User data parameter allows the caller to pass any additional information to
//	the callback for context.
//
//	Parameters:
//		 In:	inDirIterRef - The KPDCOpaqueRef of a directory iterator.
//				inNotificationFunc - The address of a function that matches
//					the KPDCDirUpdateNotificationFunc signature.
//				inUserData - User specified data.
//	Returns:	Any of the tool kit errors.
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCSetDirectoryUpdateNotification(
				KPDCDirectoryIterRef			inDirIterRef, 
				KPDCDirUpdateNotificationFunc	inNotificationFunc,
				void*							inUserData);

///////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCDeleteDirItem		
//
//	Description:
//	Delete the file or directory referenced by the directory item.
//
//	Parameters:
//		 In:	InDirItemRef must be a valid directory item reference.
//	Returns:	KPDC_FileNotFoundErr
//				KPDC_FileInUseErr
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCDeleteDirItem (KPDCDirItemRef inDirItemRef);


///////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCAllocIORef		
//
//	Description:
//	Create an KPDCIORef that can be used for performing IO to the file 
//	referenced by inDirItemRef. This function opens the file on the camera.
//	It must be closed by calling KPDCFreeRef.
//
//	Parameters:
//		 In:	inDirItemRef - The KPDCOpaqueRef of a directory item.
//		Out:	outIORef - KPDCIORef to use for IO functions.
//	Returns:	Any of the tool kit errors.
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCAllocIORef(KPDCDirItemRef	inDirItemRef,
									KPDCIORef*		outIORef);

///////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCAllocIORefFromFileHandleRef		
//
//	Description:
//	Create an KPDCIORef that can be used for performing IO to the file 
//	referenced by inDirItemRef. This function opens the file on the camera.
//	it will be closed by calling KPDCFreeRef.
//
//	Parameters:
//		 In:	inManagerRef - The KPDCOpaqueRef for the library manager.
//				inFileRefHandle - The file reference number of file HANDLE for an open file.
//		Out:	outIORef - KPDCIORef to use for IO functions.
//	Returns:	Any of the tool kit errors.
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCAllocIORefFromFileHandleRef(
				KPDCLibMgrRef		inManagerRef,
				KPDCFileRefHandle	inFileRefHandle,
				KPDCIORef*			outIORef);

///////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCRead		
//
//	Description:
//	Read inCount bytes from the file and place the data into outBuffer.
//
//	Parameters:
//		 In:	inIORef - An IO reference.
//				inCount - The number of bytes to read.
//		Out:	outBuffer - The address to read the data into.
//	Returns:	Any of the tool kit errors.
//				Any OS file manager errors.
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCRead(	KPDCIORef	inIORef,
								KPDCUInt32	inCount,
								KPDCUInt8*	outBuffer);

///////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCWrite		
//
//	Description:
//	Write inCount bytes to the file from outBuffer.
//
//	Parameters:
//		 In:	inIORef - An IO reference.
//				inCount - The number of bytes to write.
//				inBuffer - The address to write the data from.
//	Returns:	Any of the tool kit errors.
//				Any OS file manager errors.
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCWrite(	KPDCIORef	inIORef,
								KPDCUInt32	inCount,
								KPDCUInt8*	inBuffer);


///////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCSetPosition		
//
//	Description:
//	Set the position within the file at which the next read or write will start.
//
//	Parameters:
//		 In:	inIORef - An IO reference.
//				inOffset - The offset from the beginning of the file (byte 0).
//	Returns:	Any of the tool kit errors.
//				Any OS file manager errors.
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCSetPosition(	KPDCIORef	inIORef,
										KPDCUInt32 inOffset);

///////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCGetPosition		
//
//	Description:
//	Get the position within the file at which the next read or write will start.
//
//	Parameters:
//		 In:	inIORef - An IO reference.
//		Out:	outOffset - The offset from the beginning of the file (byte 0).
//	Returns:	Any of the tool kit errors.
//				Any OS file manager errors.
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCGetPosition(	KPDCIORef	inIORef,
										KPDCUInt32*	outOffset);

////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCAllocImage		
//	Author:		Jon Gary		Date: 2/9/2000
//
//	Description:
//	Allocate an image reference.
//
//	Parameters:
//		 In:	inMgr - The library manager reference.
//				inIO - The input/output object to read and write data from.
//		Out:	outImage - The address of a KPDCImageRef in which to store a 
//					reference to the new image.
//	Returns:	
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCAllocImage(KPDCLibMgrRef	inMgr, 
									KPDCIORef		inIO, 
									KPDCImageRef*	outImage);

////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCGetImageRectangle		
//
//	Description:
//	Read and process a rectangular region of the image file, providing progress
//	notifications as needed. This function does not perform resizing, but does
//	allow you to request data from either the thumbnail, preview or high
//	resolution image stores.
//
//	Parameters:
//		 In:	inImage - reference to an open image.
//				inSourceRes - the resolution source to use, see enum 
//					KPDCResolutionSource
//				inRect - the rectangle of interest on the image at rotation=0
//                The SDK is expects the rect to correspond to the convention:
//                   Number of rows = Bottom - Top     (also called "height")
//                   Number of columns = Right - Left  (also called "width")
//                To specify the first 100 lines of an image, top=0, bottom=100.
//
//				inPixLayout - the layout of the application's output buffer.
//				inProgFunc - a progress function.
//				inUserData - your data to be passed to the progress function.
//	Returns:	
//				KPDC_RectTooLarge
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCGetImageRectangle(
			KPDCImageRef					inImage, 
			KPDCInt32						inSourceRes, 
			const KPDCRect*					inRect, 
			KPDCPixelLayout*				inPixLayout, 
			KPDCProgressNotificationFunc	inProgFunc,
			void*							inUserData);


////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCGetImageRectangleWithTest		
//
//	Description:
//	Does the same thing as KPDCGetImageRectangle, described above, AFTER
//  testing the input parameters to prevent illegal parameters from causing
//  the SDK to write pixel data outside the application's specified buffer.
//
//  See the description for KPDCGetImageRectangle
//
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCGetImageRectangleWithTest(
			KPDCImageRef					inImage, 
			KPDCInt32						inSourceRes, 
			const KPDCRect*					inRect, 
			KPDCPixelLayout*				inPixLayout, 
			KPDCProgressNotificationFunc	inProgFunc,
			void*							inUserData,
			KPDCPointer						inStartOfBuffer,
			KPDCUInt32						inBufferByteCount,
			KPDCUInt32						inTotalChannelCount);


////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCSampleBalance		
//	Author:		Jon Gary		Date: 5/5/2000
//
//	Description:
//	Obtain the white balance sample for a given rectangle in the image.
//
//	Parameters:
//		 In:	inImage - A reference to an image.
//				inSourceRes - The resolution to read the image data from.
//				inRect - The rectangle of interest. If NULL, assume the whole image.
//				  inRect on the specified resolution image at rotation=0
//                The SDK is expects the rect to correspond to the convention:
//                   Number of rows = Bottom - Top     (also called "height")
//                   Number of columns = Right - Left  (also called "width")
//                To specify the first 100 lines of an image, top=0, bottom=100.
//		Out:	outTriplet - The address of an array of 3 unsigned 16-bit integers
//	  InOut:	
//	Returns:	KPDC_RectTooLargeErr
//				KPDC_InavlidResSourceErr
//				KPDC_BalanceOutputTooSmallErr
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCSampleBalance(	KPDCImageRef		inImage, 
										KPDCUInt32			inResSource,
										const KPDCRect*		inRect, 
										KPDCUInt16*			outSample, 
										KPDCUInt32*			inOutSampleSize);

////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCSavePersistentAttributes		
//	Author:		Jon Gary		Date: 5/5/2000
//
//	Description:
//	Save persistent attributes back to the image file.
//
//	Parameters:
//		 In:	inImage - A reference to an image.
//	Returns:	KPDC_FilePermissionsErr
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCSavePersistentAttributes(KPDCImageRef inImage);


////////////////////////////////////////////////////////////////////////////////
//
//	Function:	KPDCCheckImage		
//	Author:		Jon Gary		Date: 2/2/2000
//
//	Description:
//	Perform a quick check of the image file to see that it contains a 
//	valid image for this library. 
//
//	Parameters:
//		 In:	inImage - A reference to an image.
//	Returns:	KPDC_ImageCheckErr
////////////////////////////////////////////////////////////////////////////////

KPDCENTRY KPDCStatus KPDCCheckImage(KPDCImageRef inImage);


////////////////////////////////////////////////////////////////////////////////
// END
////////////////////////////////////////////////////////////////////////////////

#ifdef WIN32
#pragma pack (pop)
#endif


#ifdef __cplusplus
}
#endif

#ifdef macintosh
#pragma export reset
#endif

#endif	//__KProDCSDK_H__
