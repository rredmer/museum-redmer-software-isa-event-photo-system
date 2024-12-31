#if !defined(__KProSDKTypes_H__)
#define __KProSDKTypes_H__
////////////////////////////////////////////////////////////////////////////////
//
//  File:           KProSDKTypes.h
//
//  Copyright:      Copyright (c) 2000 Eastman Kodak Company.
//                  All Rights Reserved.
//
//  Source:         Original.
//
//  Description:    Type definitions for the Kodak Professional digital camera
//                  tool kit.   
//
//  Change History:
//          3/3/2000    Started source.
//  
////////////////////////////////////////////////////////////////////////////////


#ifdef macintosh
#include <ConditionalMacros.h>
#include <MacTypes.h>
#include <Files.h>

#elif WIN32
#include <windows.h>
#pragma warning (disable : 4786)
#define nil		NULL
#endif


#if PRAGMA_ONCE
#pragma once
#endif

#if PRAGMA_STRUCT_ALIGN
#pragma options align=power
#endif


////////////////////////////////////////////////////////////////////////////////
// Basic typedefs
////////////////////////////////////////////////////////////////////////////////

typedef unsigned long   KPDCUInt32;
typedef unsigned long   KPDCFourCharCode;
typedef signed long     KPDCInt32;
typedef signed long     KPDCTime;

typedef unsigned short  KPDCUInt16;
typedef signed short    KPDCInt16;

typedef unsigned char   KPDCByte;
typedef unsigned char   KPDCUInt8;
typedef signed char     KPDCInt8;

typedef float           KPDCFloat;

typedef int             KPDCBool;

typedef KPDCUInt8*      KPDCPointer;


////////////////////////////////////////////////////////////////////////////////
// KPDCRect
//
// When the application passes a KPDCRect to the SDK, the SDK is expecting the
// fields to correspond to the following convention:
//   The rectangle specifies a bounding box for the region of interest:
//      Number of rows = Bottom - Top     (also called "height")
//      Number of columns = Right - Left  (also called "width")
//   To specify the first 100 lines of an image, top=0 and bottom=100.
//
////////////////////////////////////////////////////////////////////////////////
typedef struct 
{
    KPDCInt32 top;
    KPDCInt32 left;
    KPDCInt32 bottom;
    KPDCInt32 right;
} KPDCRect;

////////////////////////////////////////////////////////////////////////////////
// KPDCPixelLayout
// This structure describes the layout of a buffer containing image data.
////////////////////////////////////////////////////////////////////////////////

typedef enum
{
    KPDCRed = 0,                // Currently, RGB is all we got.
    KPDCGreen = 1,
    KPDCBlue = 2,
    
    KPDCMaxNumComponents = 8    // The maximum number of components conceivable.
} KPDCColorComponents;

typedef struct
{
    KPDCInt32   numberOfComponents;     // Must be 3.
    KPDCInt32   componentDepth;         // The number of bits per pixel
                                        // per component. Must be 16.
                                        // The data is actually 12 bits, and uses the
                                        // lower 12 bits of the 16-bit word.
                                        // Use the KPDCScaleBy16ID attribute for 16-bit format.
    KPDCInt32   columnOffset;           // The offset between the beginning
                                        // of a component for one pixel and the
                                        // beginning of the same component for the
                                        // pixel in the next column of the same
                                        // row. The offset is in bytes.
    KPDCInt32   rowOffset;              // The offset between the beginning of
                                        // a component for one pixel and the
                                        // beginning of the same component for the
                                        // pixel in the same column of the next
                                        // row. The offset is in bytes. 
    KPDCInt32   numRows;                // Row range that data is valid, i.e. height.
    KPDCInt32   numColumns;             // Column range that data is valid, i.e. width.
    KPDCPointer componentPtr[KPDCMaxNumComponents];
                                        // Array of pointers to the components, indexed
                                        // by KPDCColorComponents.
    KPDCInt32   reserved1;              // Reserved, always set to 0.
    KPDCInt32   reserved2;              // Reserved, always set to 0.
} KPDCPixelLayout;

////////////////////////////////////////////////////////////////////////////////
// KPDCResolutionSource
// This is used to select the source of image data when used with the 
// KPDCGetImageRectangle call. Data can be pulled from the high resolution
// image, the preview image and the thumbnail.
////////////////////////////////////////////////////////////////////////////////

typedef enum
{
    KPDCHiResSource = 0,
    KPDCPreviewSource = 1,
    KPDCThumbnailSource = 2
} KPDCResolutionSource;


////////////////////////////////////////////////////////////////////////////////
// KPDCFileRefHandle
// This type is conditionally specified to the parameter to the native file IO
// call for the target operating system.
////////////////////////////////////////////////////////////////////////////////

#if defined(macintosh)
    typedef short KPDCFileRefHandle;    // file reference number

#elif defined(WIN32)
    typedef HANDLE KPDCFileRefHandle;   // file HANDLE

#else
    #error "Need typedef for KPDCOSFileRefHandle for this platform."
#endif

////////////////////////////////////////////////////////////////////////////////
// KPDCCALLBACK
// This macro should include any keywords needed to define an inter-DLL 
// callback.
////////////////////////////////////////////////////////////////////////////////

#if defined(macintosh) && TARGET_RT_MAC_CFM
	// CFM Mac applications - all function pointers are TVectors.
	#define KPDCCALLBACK

#elif defined(WIN32)
	// Windows uses CALLBACK
	#define KPDCCALLBACK CALLBACK

#else
    #error "Need typedef for KPDCCALLBACK for this platform."
#endif



////////////////////////////////////////////////////////////////////////////////
// KPDCOpaqueRef
// A KPDCOpaqueRef is a reference to an object produced by an KProDCSDK API call.
// You should assume nothing about the value of the reference and you should not
// treat it as a pointer.
////////////////////////////////////////////////////////////////////////////////

typedef void*           KPDCOpaqueRef;          // Opaque reference
typedef KPDCOpaqueRef   KPDCLibMgrRef;          // reference to a library manager
typedef KPDCOpaqueRef   KPDCIteratorRef;        // reference to an iterator
typedef KPDCIteratorRef KPDCCameraIterRef;      // reference to a camera iterator
typedef KPDCOpaqueRef   KPDCCameraRef;          // reference to a camera
typedef KPDCIteratorRef KPDCPropertyIterRef;    // reference to a property iterator
typedef KPDCOpaqueRef   KPDCPropertyRef;        // reference to a property
typedef KPDCIteratorRef KPDCDirectoryIterRef;   // reference to a directory iterator
typedef KPDCOpaqueRef   KPDCDirItemRef;         // reference to an item in a directory
typedef KPDCOpaqueRef   KPDCIORef;              // reference to an input/output object
typedef KPDCOpaqueRef   KPDCImageRef;           // reference to an image

////////////////////////////////////////////////////////////////////////////////
// Attributes. Any object may have attributes
////////////////////////////////////////////////////////////////////////////////

typedef KPDCUInt32  KPDCAttributeID;    // An ID for an attribute
typedef KPDCUInt32  KPDCDataType;       // The type of an attribute or property. 
                                        // Must have a value from KPDCDataTypes.
                                        
////////////////////////////////////////////////////////////////////////////////
// The following enumerates the types used for attributes and property values.
////////////////////////////////////////////////////////////////////////////////

typedef enum
{
    KPDCDataTypeUnknown     = 0,    // This thing has no type!
    KPDCDataTypeBool        = 1,    // type code for a bool
    KPDCDataTypeInt32       = 2,    // type code for a 32-bit integer
    KPDCDataTypeString      = 3,    // type code for a string of 8-bit characters
    								//   attrSize will be 0 or (strlen(s)+1)
    KPDCDataTypeEnum        = 4,    // type code for an enum, represented in a 32-bit integer
    KPDCDataTypeByteBlock   = 5,    // type code for a block of bytes.
    KPDCDataTypeTime        = 6,    // type code for a time, seconds since Jan 1, 1970 or delta.
    KPDCDataTypeGroupSeparator = 7, // type code for a group separator.
    KPDCDataTypeInt32Array  = 8,    // type code for a 32-bit integer array
    KPDCDataTypeInt16Array  = 9,   // type code for a 16-bit integer array
    KPDCDataTypeFloat       = 10,   // type code for a floating point number
    KPDCDataTypeInt8        = 11,   // type code for an 8-bit integer
    KPDCDataTypeUInt8       = 12,   // type code for an unsigned 8-bit integer
    KPDCDataTypeInt16       = 13,    // type code for a 16-bit integer
    KPDCDataTypeUInt16      = 14,   // type code for an unsigned 16-bit integer
    KPDCDataTypeUInt32      = 15,   // type code for an unsigned 32-bit integer
    KPDCDataType4CharCode   = 16,   // type code for a four character code (Mac OSType)
                                    //      - same as unsigned long.
    KPDCDataTypeUInt16Array = 17,   // type code for an unsigned 16-bit integer array
    KPDCDataTypeRect		= 18,	// type code for KPDCRect ( four KPDCInt32 )
    
    KPDCDataTypes_end
} KPDCDataTypes;

////////////////////////////////////////////////////////////////////////////////
// Attribute ID's for the library manager.
// All are read only.
////////////////////////////////////////////////////////////////////////////////

typedef enum
{
    KPDCSupportedModelsID   = 100,  // KPDCDataTypeInt32Array, array of models from the
                                    // KPDCModelCodes enum.
    KPDCLibVersionID        = 110,  // KPDCDataTypeInt32Array - array of three numbers,
                                    // major, minor and fix version codes.
    KPDCImageFileTypeID     = 111,  // KPDCDataType4CharCode - the Mac OS file type you 
                                    // should use when creating or opening files for use 
                                    // with this library.
    KPDCImageFileExtensionID = 112, // KPDCDataTypeString - the file name extension you 
                                    // should use when creating or opening files for use
                                    // with this library.
                                    // attrSize will be 0 or (strlen(s)+1)
                                    
    KPDCInitOptionsID		= 113,  // KPDCDataTypeUInt32 - the value passed as the
    								// option bits to the KPDCInitialize function.

    KPDCLibMgrAttributes_end
} KPDCLibMgrAttributes;

typedef enum
{
    KPDC_ProBackCamera          = 0x4000,
    KPDC_DCS760                 = 0x0760,
    KPDC_DCS720X                = 0x0720,
    KPDC_SCS2000                = 0x0721,
    KPDC_DCS760M                = 0x0761,
    KPDCModelCodes_end
} KPDCModelCodes;

////////////////////////////////////////////////////////////////////////////////
// Attribute ID's for properties.
// Note: In order to provide access to the text labels for enumerated property
//      values, the ID range 0 - 1000 are reserved for enum values.
//      Use the KPDCPropEnumValueLabelID macro to generate the attribute ID
//      for the label for the value of an enumerated property.
// All but KPDCPropValueID are read-only
//
// KPDCDataTypeString values will have attrSize = 0 or (strlen(s)+1)
//
////////////////////////////////////////////////////////////////////////////////

typedef enum
{
    KPDCPropEnumLabelBaseID = 0,        // See KPDCPropEnumValueLabelID macro below.
    KPDCPropEnumLabelMaxID  = 1000,     

    KPDCPropNameID          = 1001,     // KPDCDataTypeString, Name (internal name) - 
    KPDCPropTitleID         = 1002,     // KPDCDataTypeString, Title (for UI display) - 
    KPDCPropTypeID          = 1003,     // KPDCDataTypeInt32, Type - , used for KPDCDataType 
                                        //  along with KPDCPropValueID.
    KPDCPropValueID         = 1004,     // Value - type depends on attribute KPDCPropTypeID, read-write
    KPDCPropAccessBitsID    = 1006,     // KPDCDataTypeUInt32, Access flags
    KPDCPropMinValueID      = 1007,     // KPDCDataTypeInt32, Min value for integer properties
    KPDCPropMaxValueID      = 1008,     // KPDCDataTypeInt32, Max value for integer and enum properties
    KPDCPropTipID           = 1009,     // KPDCDataTypeString, Help string - 
    KPDCPropMaxSizeID		= 1010,		// KPDCDataTypeInt32 - max. capacity of the attribute

    KPDCPropertyAttributes_end
} KPDCPropertyAttributes;

typedef enum
{
    KPDCPropertyAccessWriteEnabled  = 0x00000001,   // If bit 0 (LSB) is set, property can be modified.
    KPDCPropertyAccessUserAccess    = 0x00000002     // If bit 1 is set, property may be displayed to the user.
} KPDCPropertyAccessFlags;

// To use this macro, get the value for the property and then use the value
// as an argument to KPDCPropEnumValueLabelID to get the attribute ID
// for the label, which is a string attribute.
#define KPDCPropEnumValueLabelID(enumVal) (KPDCPropEnumLabelBaseID + enumVal)

////////////////////////////////////////////////////////////////////////////////
// Attribute ID's for white balance
// They all return a KPDCDataTypeUInt16Array, with a size of 3.
////////////////////////////////////////////////////////////////////////////////

typedef enum
{
    KPDCWhiteBalanceID              = 300,  // This determines the white balance for
                                            // subsequent KPDCGetImageRectangle calls, read/write, 
                                            // persistent
    KPDCTungstenWhiteBalanceID      = 301,  // To get the tungsten balance, read-only
    KPDCFlashWhiteBalanceID         = 302,  // To get the flash balance, read-only
    KPDCFluorescentWhiteBalanceID   = 303,  // To get the Fluorescent balance, read-only
    KPDCCustomWhiteBalanceID        = 304,  // To get the custom balance, read-only
    KPDCDaylightWhiteBalanceID      = 305,  // To get the daylight balance, read-only
    KPDCAutoWhiteBalanceID      	= 306,  // To get the Auto balance, read-only
    
    KPDCAvailableWhiteBalancesID    = 320,  // list of KPDCBalanceModes for this image. read-only
    
    KPDCWhiteBalanceAttributes_end
} KPDCWhiteBalanceAttributes;

////////////////////////////////////////////////////////////////////////////////
// Attributes for image size
// They are all KPDCDataTypeUInt16
////////////////////////////////////////////////////////////////////////////////

typedef enum
{
    KPDCHiResWidthID                = 401,      // width of the high res image, read-only
    KPDCHiResHeightID               = 402,      // height of the high res image, read-only 
    KPDCPreviewWidthID              = 403,      // width of the preview image, read-only
    KPDCPreviewHeightID             = 404,      // height of the preview image, read-only
    KPDCThumbnailWidthID            = 405,      // width of the thumbnail, read-only
    KPDCThumbnailHeightID           = 406,      // height of the thumbnail, read-only
    
    KPDCImageSizeAttributes_end
} KPDCImageSizeAttributes;


////////////////////////////////////////////////////////////////////////////////
// Other image processing attributes.
////////////////////////////////////////////////////////////////////////////////

typedef enum
{
    KPDCExposureGainID              = 1800, // KPDCFloat, read-write, persistent
                                            // 0.0 = none.
    KPDCExposureGainMinID           = 1801, // KPDCFloat, read-only (negative value!)
    KPDCExposureGainMaxID           = 1802, // KPDCFloat, read-only
    KPDCAutoExpGainID      			= 1803, // KPDCFloat, read only, 0.0=none 

    KPDCSharpenStrengthID           = 1810, // KPDCInt32, read-write, persistent, 
                                            // 0 = off, 100 = max. See KPDCSharpenStrengths
    KPDCSharpenEnableID	        	= 1811,	// KPDCBool read-only, Photographer selected sharpen on

    KPDCSharpenStrengthDefaultID    = 1812, // KPDCInt32, read-only, value first time image is opened
                                            // only needs to be used to force return to first state
 
    KPDCNoiseFilterStrengthID       = 1820, // KPDCInt32, read-write, persistent, for KPDCNoiseFilterModeMoire
                                            // 0 = off, 100 = max.

    KPDCAvailableNoiseFilterModesID	= 1821, // KPDCInt32Array of enums KPDCNoiseFilterModes read-only
    
    KPDCNoiseFilterModeID			= 1822, // KPDCInt32 enums KPDCNoiseFilterModes read-write persistent

    KPDCNoiseFilterStrengthDefaultID =1823, // KPDCInt32, read-only, value first time image is opened
                                            // only needs to be used to force return to first state

    KPDCNoiseFilterModeDefaultID	= 1824, // KPDCInt32 enums KPDCNoiseFilterModes read-only
                                            // only needs to be used to force return to first state
     
    KPDCCaptureISOID                = 1830, // KPDCInt32, read-only
    
    KPDCCameraBalanceModeID			= 1840, // KPDCInt32, read-only, see KPDCBalanceModes

    KPDCBaseIlluminantID			= 1841, // KPDCInt32, read-write, persistent
    										// see KPDCIlluminants. App must control this.
    										
    KPDCAtCaptureIlluminantID       = 1842, // KPDCInt32, read-only, set by photographer
    										// see KPDCIlluminants
    KPDCAutoIlluminantID     		= 1843, // KPDCInt32, read-only
    										// see KPDCIlluminants
    KPDCCustomIlluminantID    		= 1844, // KPDCInt32, read-only
    										// see KPDCIlluminants
    KPDCWhiteBalFileDataID			= 1845, // KPDCDataTypeByteBlock uses current KPDCWhiteBalanceID
    										// and other internal information to gets the data for a
    										// custom White balance file for the camera. The application
    										// must write the data to a file.    

    KPDCAvailableIlluminantsID		= 1846, // list of KPDCIlluminants for this image. read-only

    KPDCCanDoAutoID					= 1850,	// KPDCBool, read-only. If true, KPDCAutoIlluminantID,
    										// KPDCAutoExpGainID, and KPDCAutoWhiteBalanceID are valid
    										// If false, those values are invalid or return error.
    
    KPDCScaleBy16ID					= 1950,	// For full range 16-bit output, make non-zero.
    										// KPDCBool, read-write, default off.

    KPDCChannelsPerPixelID			= 1951,	// KPDCInt32, read-only obviously 3 for color

    KPDCImageProcAttributes_end
} KPDCImageProcAttributes;

//------------------------------------------------
// Convenience constants for sharpening levels.
//------------------------------------------------

typedef enum
{
    KPDCSharpenOff                  = 0,
    KPDCSharpenLow                  = 33,
    KPDCSharpenMedium               = 66,
    KPDCSharpenHigh                 = 100
} KPDCSharpenStrengths;

//------------------------------------------------
// Convenience constants for moire noise filter levels.
//------------------------------------------------

typedef enum
{
    KPDCNoiseFilterOff              = 0,
    KPDCNoiseFilterHigh             = 100
} KPDCNoiseFilterStrengths;

//------------------------------------------------
// Convenience constants for noise filter modes.
//------------------------------------------------

typedef enum
{
    KPDCNoiseFilterModeOff          = 0,
    KPDCNoiseFilterModeBasic        = 1,
    KPDCNoiseFilterModeChroma       = 2,
    KPDCNoiseFilterModeMoire        = 3,
    KPDCNoiseFilterMode_end    
} KPDCNoiseFilterModes;

//------------------------------------------------
// These are the values for the KPDCCaptureIlluminantID attribute
//------------------------------------------------

typedef enum
{
    KPDCDaylightIllum		= 0,    // The only illuminant valid for ProBack
    KPDCTungstenIllum		= 1,    // Tungsten default 
    KPDCFluorescentIllum	= 2,    // Fluorescent default 
    KPDCFlashIllum			= 3,    // Flash default

    KPDCIlluminants_end
} KPDCIlluminants;


//------------------------------------------------
// These are the values for the KPDCCameraBalanceModeID attribute
//------------------------------------------------

typedef enum
{
	KPDCBalanceModeDaylight		= 0,
	KPDCBalanceModeTungsten		= 1,
	KPDCBalanceModeFluorescent	= 2,
	KPDCBalanceModeFlash		= 3,
	KPDCBalanceModeCustom		= 4,
	KPDCBalanceModeAuto			= 5,

	KPDCBalanceModeEnd
} KPDCBalanceModes;

////////////////////////////////////////////////////////////////////////////////
// Metadata attributes
////////////////////////////////////////////////////////////////////////////////

//------------------------------------------------
// Convenience constants for image resolution units.
//------------------------------------------------

typedef enum
{
    KPDCResUnitsUnknown				= 0, // app can not write this value
    KPDCResUnitsPixelsPerInch		= 1,
    KPDCResUnitsPixelsPerCM			= 2,
    
    KPDCResUnits_end
} KPDCResolutionUnits;


//------------------------------------------------
// These values are saved to and restored from the image file, but are
// not used internally by the SDK
//------------------------------------------------

typedef enum
{
    KPDCIPTCRec2ID                  = 1900, // KPDCDataTypeByteBlock, IPTC Record 2. Count must be mod 4
    KPDCUserMetaDataID              = 1901, // KPDCDataTypeByteBlock, caller defined.
    										// Should contain a unique code and version
    										// number so different apps or different versions
    										// won't cause erroneous behavior.
    KPDCSourceProfileID				= 1902, // used by the application
    KPDCLookProfileID				= 1903, // used by the application
    KPDCDestinationProfileID		= 1904, // used by the application
    KPDCImageDescriptionID			= 1905, // used by the application
    
    // simple data types saved by KPDCSavePersistentAttributes
    KPDCOpenedWithPersistentAttribsID = 1920, // boolean, read-only, persistent params were restored
    KPDCImageTagID					= 1921,	// KPDCDataTypeBool  user "tags" image
    KPDCRotateAngleID				= 1922, // 0, 90, 180, or 270 are only valid values
    KPDCROIRectID					= 1923, // a KPDCRect in space of full size image.
    										// Although not used by SDK, SDK will test for
    										// valid values during "set" command
    KPDCXResolutionID				= 1924, // R/W float, units spec'd by KPDCResolutionUnitsID
    KPDCYResolutionID				= 1925, // R/W float, units spec'd by KPDCResolutionUnitsID
    KPDCResolutionUnitsID			= 1926, // R/W enum, KPDCResolutionUnits. If the app
    										// changes units, it should also change XRes and YRes 
    
    KPDCImageMetaDataAttributes_end
} KPDCImageMetaDataAttributes;



////////////////////////////////////////////////////////////////////////////////
// Read-Only Camera attributes
// KPDCDataTypeString values will have attrSize = 0 or (strlen(s)+1)
////////////////////////////////////////////////////////////////////////////////

typedef enum
{
	// NOTE: The values of KPDCCameraAttributes are also KPDCImageAttributes

    KPDCSerialNumberStringID        = 501,  // KPDCDataTypeString, Serial number of the camera, 
    KPDCModelStringID               = 502,  // KPDCDataTypeString, model of the camera, 
    KPDCFirmwareStringID			= 503,	// KPDCDataTypeString, firmware version string, 
    
    KPDCSupportsCaptureSessionID	= 504,	// KPDCDataTypeBool, true if camera supports 
    										//		KPDCStartCaptureSession api.
    KPDCCameraAttributes_end
} KPDCCameraAttributes;



////////////////////////////////////////////////////////////////////////////////
// Read-only image attributes, directly from TIFF tags
// KPDCDataTypeString values will have attrSize = 0 or (strlen(s)+1)
////////////////////////////////////////////////////////////////////////////////

typedef enum
{
	// NOTE: The values of KPDCCameraAttributes are also KPDCImageAttributes
	
    KPDCMakeStringID			= 520, //KPDCDataTypeString, should be "Kodak" 
    KPDCDateTimeStringID		= 521, //KPDCDataTypeString 
    KPDCArtistStringID			= 523, //KPDCDataTypeString 
    KPDCCopyrightStringID		= 524, //KPDCDataTypeString
    KPDCDateTimeOriginalStringID = 525,//KPDCDataTypeString
    KPDCOriginalFileNameStringID = 526,//KPDCDataTypeString 
    KPDCCameraSettingsStringID	= 527, //KPDCDataTypeString 
    KPDCImageNumberID			= 528, //KPDCDataTypeUInt32 
    KPDCBatteryLevelID			= 529, //KPDCDataTypeFloat
    KPDCAvailableResolutionsID	= 530, //KPDCDataTypeInt32Array
    KPDCGPSStringID				= 531, //KPDCDataTypeString
    KPDCModelEnumID             = 532, //KPDCDataTypeInt32, KPDCModelCodes model of the camera, 

    KPDCImageAttributes_end
} KPDCImageAttributes;



////////////////////////////////////////////////////////////////////////////////
// KPDCDirItem attributes
// KPDCDataTypeString values will have attrSize = 0 or (strlen(s)+1)
////////////////////////////////////////////////////////////////////////////////

typedef enum
{
    KPDCDirItemNameID           = 601,          // name of file, KPDCDataTypeString, read-write
    KPDCDirItemSizeID           = 602,          // file size in bytes, KPDCDataTypeInt32, read-only
    KPDCDirItemModDateID        = 603,
    KPDCDirItemIsFolderID		= 604,			// KPDCBool, whether or not item is a folder
    KPDCDirItemIsReadOnlyID		= 605,			// KPDCBool, whether or not item is read-only
    
    KPDCDirItemAttributes_end
} KPDCDirItemAttributes;

////////////////////////////////////////////////////////////////////////////////
// Initialization option bits
////////////////////////////////////////////////////////////////////////////////

typedef enum
{
    KPDCInitOptionDefault           = 0,
    KPDCInitOptionEnableIEEE1394    = 0x00000001    // Set this bit if a camera connection is needed.
} KPDCInitalizationOptions;


////////////////////////////////////////////////////////////////////////////////
// Camera commands
////////////////////////////////////////////////////////////////////////////////

typedef enum
{
    KPDC_TakePictureCmd = 0x08,            // Ask the camera to take a picture.
    
    KPDCCameraCommands_end
} KPDCCameraCommands;

////////////////////////////////////////////////////////////////////////////////
// KPDCIORef permissions
////////////////////////////////////////////////////////////////////////////////

typedef enum
{
    KPDCIORefPermReadOnly = 0,
    KPDCIORefPermReadWrite = 1
} KPDCIORefPermissions;

////////////////////////////////////////////////////////////////////////////////
// KPDCStatus
// The data type for status codes.
////////////////////////////////////////////////////////////////////////////////

typedef int KPDCStatus;

////////////////////////////////////////////////////////////////////////////////
// KPDCCameraEvents
// The following are events generated by the camera driver. The comments after the code
// specify the meaning of integer parameter 1 and string parameter 2 that
// are passed to the KPDCCameraEventNotificationFunc.
// To receive camera events, call KPDCSetCameraEventNotification
////////////////////////////////////////////////////////////////////////////////

typedef enum
{
//  Name                Code        Parameter1      Parameter2
//  ---------------     -----       --------------  ---------------
    KPDCCardMount       = 1,    //  NA              Card Name
    KPDCCardUnmount     = 2,    //  NA              Card Name
    KPDCFolderChanged   = 3,    //  NA              Folder Path
    KPDCFolderContent   = 4,    //  NA              NA
    KPDCShutterOpen     = 5,    //  NA              NA
    KPDCCaptureStart    = 6,    //  NA              New File Path
    KPDCPreviewProgress = 7,    //  Lines Written   NA
    KPDCCaptureEnd      = 8,    //  Status          NA
    KPDCAddFile         = 9,    //  NA              File Path
    KPDCDeleteFile      = 10,   //  NA              File Path
    KPDCCaptureError    = 11,   //  Status          NA
    
    // KPDCCameraUnplugged is synthesized, since the camera is gone.
    KPDCCameraUnplugged = 100,  //  NA              NA
    
    // Only used internally.
    KPDCCameraPlugged 	= 101,  //  NA              NA
    
    // Only used when an error occurs trying to get event information from the
    // camera or driver.
    KPDCCameraEventError = 102,	//	Error code		NA
    
    KPDCCameraEvents_end
} KPDCCameraEvents;


////////////////////////////////////////////////////////////////////////////////
// Callbacks
////////////////////////////////////////////////////////////////////////////////


typedef void ( KPDCCALLBACK *KPDCDirUpdateNotificationFunc)(
            void *userData, 
            int inEvent);		// See KPDCCameraEvents avove.


typedef void (KPDCCALLBACK *KPDCCameraAddedNotificationFunc)(
            void *userData);

typedef void (KPDCCALLBACK *KPDCCameraEventNotificationFunc)(
            KPDCUInt32  inEvent,                    // the event code, see KPDCCameraEvents
            KPDCUInt32  inParam1,                   // events may have an integer parameter
            const char  *inParam2,                  // events may have a string parameter
            KPDCUInt32  inParam2Length,
            void        *userData);
            
typedef int (KPDCCALLBACK *KPDCProgressNotificationFunc)(
            void        *userData,
            KPDCInt32   inTotal,
            KPDCInt32   inCurrent);
            
            
////////////////////////////////////////////////////////////////////////////////
// Capture Session Callbacks
////////////////////////////////////////////////////////////////////////////////

//------------------------------------------------
// KPDCCaptureStartNotificationFunc
// When this notification is called, a capture has been initiated, but the image
// does not yet exist. 
//------------------------------------------------

typedef KPDCStatus  (KPDCCALLBACK *KPDCCaptureStartNotificationFunc)(
    void                *userData,          // your data
    void                **outImageUserData, // your image-specific data
    KPDCPixelLayout     *outPreviewBuffer,  // The layout for where you want
                                            // the preview image data stored.
    KPDCFileRefHandle   *outFileRef);       // the ref num or handle of the opened
                                            // destination file.
            

//------------------------------------------------
// KPDCPreviewNotificationFunc
// When this notification is called, the rectangular segment of the 
// preview specified by inSegmentRect is available.
//------------------------------------------------

typedef KPDCStatus (KPDCCALLBACK *KPDCPreviewNotificationFunc)(
    void            *userData,          // your data
    void            *inImageUserData,   // your image-specific data
    const KPDCRect  *inSegmentRect);    // area of the preview that is ready.   

//------------------------------------------------
// KPDCCaptureCopyNotificationFunc
// This function is called repeatedly as a file is copied from the
// camera to the file specified by your KPDCCaptureStartNotificationFunc.
// If the inStatus parameter is KPDC_CaptureCopyInProgress, you can 
// use the inPercentDone as a progress indicator. 
// If the inStatus is KPDC_OK, then the file is complete. Other values
// indicate an error occured copying the file.
// When this notification is called, the image is ready on disk. 
//------------------------------------------------

typedef KPDCStatus (KPDCCALLBACK *KPDCCaptureCopyNotificationFunc)(
    void        *userData,          // your data
    void        *inImageUserData,   // your image-specific data,
    KPDCInt32	inPercentDone,		// portion of file copied
    KPDCStatus  inStatus);          // status or error code.


#if PRAGMA_ALIGN
#pragma options align=reset
#endif


#endif  //__KProSDKTypes_H__

