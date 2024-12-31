VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsRegistry"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
'****************************************************************************
'**                                                                        **
'** Project.: Redmer Controls EZ-SNAP/2002 Windows                         **
'**                                                                        **
'** Module..: clsPersist - Persist Application Variables.                  **
'**                                                                        **
'** Notes...: This object provides a simple interface for storing and      **
'**           retrieving application variables in either INI files or the  **
'**           Windows Registry.  The intent is to provide seamless support **
'**           for either method (eventually!).                             **
'**                                                                        **
'** (c) 1992-2002 Redmer Controls.  All rights reserved.                   **
'****************************************************************************
Option Explicit                             'Require explicit variable declaration

Private Const sAppName As String = "EZSNAP"
Private Const sSection As String = "Settings"
Private Const sKeyEventCode As String = "EventID"
Private Const sKeyExposureNum As String = "ExposureNum"
Private Const sKeyLowResOverlayPath As String = "OLowRes"
Private Const sKeyHiResOverlayPath As String = "OHiRes"
Private Const sKeyCameraPath As String = "Camera"
Private Const sKeyFinalPath As String = "Final"

Private iExposureNum As Integer             'Exposure number
Private sEventCode As String                'Code for the event
Private sLowResOverlayPath As String        'Path to low resolution overlay images
Private sHiResOverlayPath As String         'Path to high resolution overlay images
Private sCameraPath As String               'Path to location of images on camera (or download location)
Private sFinalPath As String                'Path to store final images in (Merged)

Private Sub Class_Initialize()
    On Error Resume Next
    iExposureNum = 0                        'Initialize the exposure number
    sEventCode = ""                         'Initialize the event code
End Sub

Public Property Let EventCode(sEvent As String)
    On Error Resume Next
    sEventCode = sEvent
    SaveSetting sAppName, sSection, sKeyEventCode, sEventCode
End Property
Public Property Get EventCode() As String
    On Error Resume Next
    EventCode = GetSetting(sAppName, sSection, sKeyEventCode, "DEF")
End Property

Public Property Let ExposureNum(iExposure As Integer)
    On Error Resume Next
    iExposureNum = iExposure
    SaveSetting sAppName, sSection, sKeyExposureNum, Str$(iExposureNum)
End Property
Public Property Get ExposureNum() As Integer
    On Error Resume Next
    ExposureNum = Val(GetSetting(sAppName, sSection, sKeyExposureNum, Str$(iExposureNum)))
End Property

