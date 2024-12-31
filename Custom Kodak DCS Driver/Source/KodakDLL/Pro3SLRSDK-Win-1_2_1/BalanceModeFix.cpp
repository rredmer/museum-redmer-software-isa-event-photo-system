
// This code snippet is a work around for an error in the ProBackSDK 
// version 1.2.1.6. For Pro Back images, that version always returned
// KPDCBalanceModeAuto upon a read of the value KPDCCameraBalanceModeID.
// This could cause a failure if the application attempts to set auto
// mode to the image, since images from the Pro Back cameras only 
// support KPDCBalanceModeDaylight.
//
// KPDCCameraBalanceModeID allows tha application to read the user's 
// setting on the camera GUI at the time the image was acquired.
// Many applications will not use KPDCCameraBalanceModeID.
//
// This code snippet is designed to work around this temporary error
// in SDK version 1.2.1.6 but also be compatible with the DCS 720x,
// DCS 760C, DCS 760M, and any future cameras that may properly 
// support auto balance mode. If KPDCCameraBalanceModeID returns
// KPDCBalanceModeAuto and KPDCAutoWhiteBalanceID fails, this code
// returns KPDCBalanceModeDaylight
//
// This code does NOT modify the image file. KPDCCameraBalanceModeID 
// is a read-only variable since it represents the user's setting
// on the camera GUI at the time the image was acquired.

KPDCStatus GetFixedCameraBalanceMode(KPDCProcs        *SDKProcs,
                                     KPDCImageRef    inImage,
                                     KPDCBalanceModes *outBalanceMode )
{
    KPDCStatus status = KPDC_OK; // error status for each SDK call, etc.
    KPDCStatus statusOfAuto = KPDC_OK; // error status for auto calls only.
    KPDCUInt32    attrSize = 0;    // size of any attribute; size is no. of elements (not bytes)
    KPDCDataType attrType = 0;    // data type of any attribute
    KPDCBool imageCanDoAuto = false;

    // get the currently set balance mode
    status = SDKProcs->GetAttributeInfo(inImage, KPDCCameraBalanceModeID, 
                                            &attrType, &attrSize);
    if (KPDC_OK == status)
    {
        status = SDKProcs->GetAttributeValue(inImage, KPDCCameraBalanceModeID, 
                                            &attrSize, outBalanceMode);
    }

    // if the image's balance mode is auto, test that auto balance is valid 
    if ((KPDC_OK == status) && (KPDCBalanceModeAuto == *outBalanceMode))
    {
        statusOfAuto = SDKProcs->GetAttributeInfo(inImage, KPDCCanDoAutoID, 
                                            &attrType, &attrSize);

        // if getting the attribute succeeded, now try to get the value
        if (KPDC_OK == statusOfAuto)
        {
            statusOfAuto = SDKProcs->GetAttributeValue(inImage, 
                                            KPDCCanDoAutoID, 
                                            &attrSize, &imageCanDoAuto);
        }

        // if either function failed above, set to daylight
        if ((KPDC_OK != statusOfAuto) || !imageCanDoAuto )
        {
            *outBalanceMode = KPDCBalanceModeDaylight;
        }
    }
                                            
    return (status);
}


