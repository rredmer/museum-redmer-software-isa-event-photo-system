#if !defined(__KProSDKErrors_H__)
#define __KProSDKErrors_H__
////////////////////////////////////////////////////////////////////////////////
//
//	File:			KProSDKErrors.h
//
//	Author(s):		Jonathan Gary
//
//	Copyright:		Copyright (c) 2000 Eastman Kodak Company.
//					All Rights Reserved.
//
//	Source:			Original.
//
//	Description:	Interface of KProSDKErrors	
//
//	Change History:
//			3/3/2000	Started source.
//	
////////////////////////////////////////////////////////////////////////////////


// Toolkit errors
enum 
{
	KPDC_NoError 				= 0,
	KPDC_OK		 				= 0,
	KPDC_OSVersionErr 			= 101,	// The OS is not a supported release.
	KPDC_MemFullErr 			= 102,	// Memory allocation failed.
	KPDC_OpaqueRefErr 			= 103,	// An opaque reference does not refer
										// to an object of the correct type
										// for the function call.
	KPDC_SysConfigErr 			= 104,	// The required libraries or system extensions
										// are not installed on the system.
	KPDC_ParamErr 				= 105,	// One of the parameters has an invalid value.
	KPDC_OptionDisabledErr		= 106,	// The toolkit was initialized with this feature
										// disabled.
	KPDC_1394InUseErr			= 107,	// The IEEE 1394 extensions are in use by another
										// process.
	KPDC_AlreadyInitialized		= 108,	// The SDK is already initialized. The reference
										// returned is still usable, but you should check the
										// KPDCInitOptionsID attribute to see if the features
										// needed were set at initialization.
	KPDC_InternalQueueTimeoutErr = 195,	// Used internally, a queue timed out.
	KPDC_UnimplementedErr		= 196,	// That function is not implemented (yet).
	KPDC_InternalLogicError		= 197,	// Assertion failed. Please report as a bug!
	KPDC_UnhandledExceptionErr	= 198,	// Something internal threw an exception that was
										// not handled properly. Please report as a bug!
	KPDC_ToolkitErrsEOL			= 199
};

// Iterator errors
enum
{
	KPDC_IterEndOfListErr		= 200,	// There are no more items to iterate.
	KPDC_IterItemNotFoundErr	= 201,	// There are no with that name in the list.

	KPDC_IterErrsEOL			= 299
};

// Camera errors
enum
{
	KPDC_InvalidCommandErr		= 300,	// The command is not appropriate for the camera
										// model.
	KPDC_CommandFailedErr 		= 301,	// The camera could not perform the command.
	KPDC_CameraDisconnectedErr	= 302,	// The camera has been disconnected.
	KPDC_NoCaptureSessionErr	= 303,	// KPDCEndCaptureSession was called without a previous
										// call to KPDCStartCaptureSession.
	KPDC_CaptureSessionOpenErr	= 304,	// KPDCStartCaptureSession was called twice.
	KPDC_InvalidDriverIDErr		= 305,	// Internal error, using an id for a driver that is not loaded.
	KPDC_InquiryErr				= 306,	// The camera does not respond correctly to inquiry.
	KPDC_IOChecksumErr			= 307,	// The camera and host do not agree on the checksum.
	KPDC_PropertySetVerifyErr	= 308,	// After setting a property, reading it back does not verify.
	KPDC_CaptureTerminatedErr	= 309,	// A capture was pending whan KPDCEndCaptureSession was called.
										// The capture has been discarded!
	KPDC_CaptureLostErr			= 310,	// Because the KPDCCaptureStartNotificationFunc did not return a 
										// non-zero file reference handle, the capture was deleted from
										// the camera's memory. There was no place to store it.
	
	KPDC_CaptureCameraFileNameErr = 397, // The camera did not return a path to a file in the memory
										// folder during a capture session.
	KPDC_CaptureCopyInProgress	= 398,	// Not an error, see KPDCCaptureCopyNotificationFunc

	KPDC_CameraErrsEOL			= 399
};

// Camera driver errors
// status passed through Mac OS device manager must be negative values. 
enum
{
	KPDC_SBPErr					= -5500,	// An error is in the SBP-2 status block.
	KPDC_MaxBufferExceededErr 	= -5501,	// SDK asked to too big a block.
	KPDC_SBPFunctionRejectedErr	= -5502,	// The SBP-2 command was rejected.
	KPDC_NoUnsolEventsErr		= -5503,	// There are no unsolicited events waiting.
	KPDC_LoginFailedErr			= -5504,	// Could not log into the camera.
	KPDC_ReconnectFailedErr		= -5505,	// Could not reconnect to the camera after bus reset.
	KPDC_InUseErr				= -5507,	// The camera is in use by another process.
		
	KPDC_CameraDriverErrorsEOL	= -5599
};

// Attribute errors
enum
{
	KPDC_InvalidAttrIDErr		= 400,	// The object does not have that attribute.
	KPDC_AttrSizeErr			= 401,	// The attribute is too large for the supplied buffer.
	KPDC_AttrTypeErr			= 402,	// The type specified for an attribute's value is incorrect.
	KPDC_AttrOutOfRangeErr		= 403,	// The value supplied is out of range.
	KPDC_AttrReadOnlyErr		= 404,	// Cannot call KPDCSetAttributeValue for this attribute.
	KPDC_AttrNotAvailableErr	= 405,	// ID is OK, but object does not have available data.

	KPDC_AttrErrsEOL			= 499
};

// Image errors
enum
{
	KPDC_RectTooLargeErr		= 501,	// A rectangle exceeds the bounds of the image resolution.
	KPDC_InvalidResSourceErr	= 502,	// A resolution source parameter was not valid.
	KPDC_PixLayoutTooSmallErr	= 503, 	// The pixel layout is smaller than the requested rectangle.
	KPDC_BalanceOutputTooSmallErr = 504,// The output buffer KPDCSampleBalance is too small.
	KPDC_ImageCheckErr			= 505,	// Image check failed. File cannot be processed with this API.
	KPDC_UnsupportedPixelSize	= 506,	// The componentDepth field of a pixel layout is set to a size
										// that is not supported.
	KPDC_FileFormatError		= 507,	// The file contains invalid data or is formatted incorrectly.
	KPDC_UnsupportedNumCompsErr	= 508,	// KPDCPixelLayout numberOfComponents is not 3.
	KPDC_NULLCompPtrErr			= 509,	// KPDCPixelLayout had a null componentPtr.
	KPDC_InvalidRectErr			= 510,	// Rect is wrong.
	KPDC_FileIsNotValidDCRFile  = 511,  // File does not have needed identifying tags
	KPDC_TiffTagIsNotInFile  	= 512,  // File does not have the tiff tag needed for this function
	KPDC_UnsupportedModelErr  	= 513,  // This library does not open images from the camera that produced the 
										// 		given file.
	KPDC_SamplePixelTooBrightErr= 514,	// one or more pixels in sample area is too bright	
	KPDC_SamplePixelTooDarkErr 	= 515,	// one or more pixels in sample area is too dark
	KPDC_InvalidIlluminantErr	= 516,  // KPDCBaseIlluminant set previously is invalid 	
	KPDC_InvalidSharpenStrengthErr= 517,// KPDCSharpenStrengthID set previously is invalid 	
	KPDC_RectDoesntMatchPixelLayout= 518, // The inRect doesn't match numRows or numCols	
	KPDC_NotValidForMonochomeImage= 519,// This function works for color images only	
	KPDC_CompPointersOverlap	= 520,  // Component pointers overlap	
	KPDC_CompPointerIsntNull	= 521,  // Unused component pointers must be null	
	KPDC_PointerGoesBelowBuffer	= 522,  // Pointer value could be lower than specified buffer	
	KPDC_PointerGoesAboveBuffer	= 523,  // Pointer value could be higher than specified buffer
	KPDC_OffsetCantBeOdd		= 524,  // rowOffset or columnOffset are odd 	
	KPDC_BufferByteCountTooSmall= 525,  // inRect won't fit in buffer	
	KPDC_DCRDecompressFailed	= 526,  // Compressed image data has been corrupted, file unusable

	KPDC_ImageErrsEOL			= 599
};

// Directory item reference
enum
{
	KPDC_FileNotFoundErr		= 601,	// File not found. Check path!
	KPDC_FileInUseErr			= 602,	// File is in use.
	KPDC_FilePermissionsErr		= 603,	// Cannot write to read-only file.
	KPDC_EOFErr					= 604,	// Read or position past end of file.
	KPDC_NotAFolderErr			= 605,	// Operation invalid for files.

	KPDC_DirItemErrsEOL			= 699
};

#endif	//__KProSDKErrors_H__
