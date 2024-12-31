VERSION 5.00
Object = "{6FBA474E-43AC-11CE-9A0E-00AA0062BB4C}#1.0#0"; "sysinfo.ocx"
Begin VB.UserControl ctlUSBCamera 
   ClientHeight    =   705
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   1725
   ScaleHeight     =   705
   ScaleWidth      =   1725
   Begin VB.Timer timDownload 
      Interval        =   800
      Left            =   690
      Top             =   60
   End
   Begin SysInfoLib.SysInfo sysUSB 
      Left            =   60
      Top             =   60
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
   End
End
Attribute VB_Name = "ctlUSBCamera"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
'****************************************************************************
'**                                                                        **
'** Project.: Redmer Controls EZ-SNAP/2002 Windows                         **
'**                                                                        **
'** Module..: ctlUSBCamera - USB Device-Level Interface for Camera.        **
'**                                                                        **
'** Notes...: This object provides a simple interface to support the USB   **
'**           and PCMCIA Hot-Swappable Device Context.  It maintains a     **
'**           status for these types of devices and may serve as a wrapper **
'**           for future lower-level device driver interfaces.             **
'**                                                                        **
'** History.:                                                              **
'**           11-01-00 RDR Created program.                                **
'**                                                                        **
'** (c) 1992-2002 Redmer Controls.  All rights reserved.                   **
'****************************************************************************
Option Explicit                             'Require explicit variable declaration

Private sDeviceName As String               'Registered Device Name
Private sEventName As String                'Name of event from device
Private lDeviceType As Long                 'Registered Device Type
Private lDeviceID As Long                   'Registered Device ID
Private lDeviceData As Long                 'Data from Device
Private bDeviceReady As Boolean             'Status of Device
Private lTimeout As Long                    'Timeout counter

'****************************************************************************
'**                                                                        **
'** Routine.: ctlUSBCamera - User Control Initialize                       **
'**                                                                        **
'** Notes...: This procedure initializes the control.  It loads control-   **
'**           specific strings from the resource file and sets default     **
'**           values.                                                      **
'**                                                                        **
'****************************************************************************
Private Sub UserControl_Initialize()
    On Error Resume Next
    sEventName = ""
    sDeviceName = ""
    lDeviceType = 0
    lDeviceID = 0
    lDeviceData = 0
    bDeviceReady = False                    'Initialize device status.
End Sub

'****************************************************************************
'**                                                                        **
'** Routine.: ctlUSBCamera - sysUSB_DeviceArrival                          **
'**                                                                        **
'** Notes...: This procedure is an event that fires when a device is added **
'**           to the system (hot-swap).                                    **
'**                                                                        **
'****************************************************************************
Private Sub sysUSB_DeviceArrival(ByVal DeviceType As Long, ByVal DeviceID As Long, ByVal DeviceName As String, ByVal DeviceData As Long)
    sDeviceName = DeviceName
    lDeviceType = DeviceType
    lDeviceID = DeviceID
    lDeviceData = DeviceData
    bDeviceReady = True
    GetPhoto
End Sub

'****************************************************************************
'**                                                                        **
'** Routine.: ctlUSBCamera - sysUSB_DeviceOtherEvent                       **
'**                                                                        **
'** Notes...: This procedure is an event that fires on a device event.     **
'**                                                                        **
'****************************************************************************
Private Sub sysUSB_DeviceOtherEvent(ByVal DeviceType As Long, ByVal EventName As String, ByVal DataPointer As Long)
'    MsgBox EventName
End Sub

'****************************************************************************
'**                                                                        **
'** Routine.: ctlUSBCamera - sysUSB_DeviceRemoveComplete                   **
'**                                                                        **
'** Notes...: This procedure is an event that fires when a device is taken **
'**           out of the system (hot-swap).                                **
'**                                                                        **
'****************************************************************************
Private Sub sysUSB_DeviceRemoveComplete(ByVal DeviceType As Long, ByVal DeviceID As Long, ByVal DeviceName As String, ByVal DeviceData As Long)
    sDeviceName = DeviceName
    lDeviceType = DeviceType
    lDeviceID = DeviceID
    lDeviceData = DeviceData
    bDeviceReady = False
End Sub

'****************************************************************************
'**                                                                        **
'** Routine.: frmPhoto - GetPhoto                                          **
'**                                                                        **
'** Notes...: This procedure attempts to download a file from the camera.  **
'**                                                                        **
'****************************************************************************
Private Sub GetPhoto()
    'On Error Resume Next
    Dim fs As New FileSystemObject
    Dim sTempFolder As String
    
    sTempFolder = "C:\WINDOWS\TEMP\CAMEXP\TRANSFER"
    
    '--- Uncomment the following line to clear the temp image folder on download
    'fs.DeleteFile sTempFolder + "\*.*", True
    'Set fs = Nothing
    'DoEvents
    
    frmMain.usrVideo.VideoEnabed = False
    
    '--- Wait for Digital Camera Window to Display
'    lTimeout = 0
'    timDownload.Enabled = True
'    Do While frmMain.usrUSBCamera.CameraActive = False
'        If lTimeout > 100 Then
'            Exit Do
'        End If
'        DoEvents
'    Loop
'    timDownload.Enabled = False
'    If bdeviceactive = True Then
        
        '--- The following line of code downloads the images using WinBatch
        Shell "C:\PROGRAM FILES\WINBATCH\SYSTEM\WinBatch.EXE " + sAppPath + "NikonDownload.wbt", vbHide
        
        DoEvents
    
        frmMain.Timer1.Enabled = True
    
'    End If
    
End Sub


Private Sub timDownload_Timer()
    lTimeout = lTimeout + 1
End Sub


'****************************************************************************
'**                                                                        **
'** Routine.: ctlUSBCamera - Property Procedures                           **
'**                                                                        **
'** Notes...: These procedures simply set and retrieve object properties.  **
'**                                                                        **
'****************************************************************************
Public Property Let CameraActive(bStatus As Boolean)
    bDeviceReady = bStatus
End Property
Public Property Get CameraActive() As Boolean
    CameraActive = bDeviceReady
End Property

