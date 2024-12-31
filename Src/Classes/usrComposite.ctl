VERSION 5.00
Object = "{00120003-B1BA-11CE-ABC6-F5B2E79D9E3F}#1.0#0"; "ltocx12n.ocx"
Object = "{00120023-B1BA-11CE-ABC6-F5B2E79D9E3F}#1.0#0"; "ltcap12n.ocx"
Begin VB.UserControl usrComposite 
   ClientHeight    =   7245
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   9495
   ScaleHeight     =   483
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   633
   Begin LEADCapLibCtl.LEADCap vidLive 
      Height          =   255
      Left            =   9450
      OleObjectBlob   =   "usrComposite.ctx":0000
      TabIndex        =   3
      Top             =   30
      Width           =   45
   End
   Begin LEADLib.LEAD imglive 
      Height          =   255
      Left            =   9480
      TabIndex        =   2
      Top             =   6330
      Visible         =   0   'False
      Width           =   45
      _Version        =   65539
      _ExtentX        =   79
      _ExtentY        =   450
      _StockProps     =   229
      ScaleHeight     =   17
      ScaleWidth      =   3
      DataField       =   ""
      BitmapDataPath  =   ""
      AnnDataPath     =   ""
      PanWinTitle     =   "PanWindow"
      CLeadCtrl       =   0
   End
   Begin LEADLib.LEAD imgMain 
      Height          =   7185
      Left            =   30
      TabIndex        =   1
      Top             =   30
      Width           =   9405
      _Version        =   65539
      _ExtentX        =   16589
      _ExtentY        =   12674
      _StockProps     =   229
      ScaleHeight     =   479
      ScaleWidth      =   627
      DataField       =   ""
      BitmapDataPath  =   ""
      AnnDataPath     =   ""
      PanWinTitle     =   "PanWindow"
      CLeadCtrl       =   0
   End
   Begin VB.ComboBox DriverCombo 
      Height          =   315
      Left            =   6360
      Style           =   2  'Dropdown List
      TabIndex        =   0
      Top             =   6630
      Visible         =   0   'False
      Width           =   3255
   End
End
Attribute VB_Name = "usrComposite"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
'****************************************************************************
'**                                                                        **
'** Project.: Redmer Controls EZ-SNAP/2002 Windows                         **
'**                                                                        **
'** Module..: ctlVideo - Video Overlay Control                             **
'**                                                                        **
'** Notes...: This object provides video overlay functionilty using Lead-  **
'**           Tools Multimedia controls to combine a transparent image with**
'**           images provided by a frame-grab control.                     **
'**                                                                        **
'** (c) 1992-2002 Redmer Controls.  All rights reserved.                   **
'****************************************************************************
Option Explicit                             'Require explicit variable declaration

'--- Declare Resource File Constants
Private Const iResBASE As Long = 50000      'Base Index of resource strings in file
Private Const iResVideoUnlock As Long = iResBASE + 1
Private Const iResVideoErrorCaption As Long = iResBASE + 2
Private Const iResVideoNoDrivers As Long = iResBASE + 3
Private Const iResVideoNoDevice As Long = iResBASE + 4
Private Const iResVideoNoSetup As Long = iResBASE + 5
Private Const iResVideoNoOverlay As Long = iResBASE + 6
Private Const iResVideoOverlayError As Long = iResBASE + 7
Private Const iMsgFlags As Integer = vbApplicationModal + vbCritical + vbOKOnly

'--- Declare Resource File Strings
Private sResVideoUnlock As String           'LeadTools Multimedia Unlock Code
Private sResVideoErrorCaption As String     'Standard Error Caption
Private sResVideoNoDrivers As String        'Error - No Drivers found message
Private sResVideoNoDevice As String         'Error - No Device found message
Private sResVideoNoSetup As String          'Error - No Video Setup Feature message
Private sResVideoNoOverlay As String        'Error - Error Loading Video Overlay File - not found
Private sResVideoOverlayError As String     'Error - Error Loading Video Overlay File

'--- Declare Object Properties & Locals
Private sOverlayFile As String              'The name of the overlay graphic file
Private iActiveIndex As Integer             'Index of capture device in Windows Enumeration
Private bOverlayMode As Boolean



'****************************************************************************
'**                                                                        **
'** Routine.: ctlVideo - User Control Initialize                           **
'**                                                                        **
'** Notes...: This procedure initializes the control.  It loads control-   **
'**           specific strings from the resource file and sets default     **
'**           values.                                                      **
'**                                                                        **
'****************************************************************************
Private Sub UserControl_Initialize()
    
    On Error Resume Next
    bOverlayMode = True
    GetResources                            'Retrieve resources (MUST BE FIRST CALL)
    GetVideoSources                         'Retrieve video sources

End Sub

'****************************************************************************
'**                                                                        **
'** Routine.: ctlVideo - GetResources                                      **
'**                                                                        **
'** Notes...: This procedure retrieves resources from the resource file    **
'**           into object-scoped variables.  The resource file simplifies  **
'**           internationalization and code maintenance.                   **
'**                                                                        **
'****************************************************************************
Private Sub GetResources()
    On Error Resume Next
    sResVideoUnlock = Trim(LoadResString(iResVideoUnlock))
    sResVideoErrorCaption = Trim(LoadResString(iResVideoErrorCaption))
    sResVideoNoDrivers = Trim(LoadResString(iResVideoNoDrivers))
    sResVideoNoDevice = Trim(LoadResString(iResVideoNoDevice))
    sResVideoNoSetup = Trim(LoadResString(iResVideoNoSetup))
    sResVideoNoOverlay = Trim(LoadResString(iResVideoNoOverlay))
    sResVideoOverlayError = Trim(LoadResString(iResVideoOverlayError))
End Sub

'****************************************************************************
'**                                                                        **
'** Routine.: ctlVideo - GetOverlay                                        **
'**                                                                        **
'** Notes...: This procedure retrieves a specified overlay graphic from    **
'**           The current overlay path.  It also defines a region for      **
'**           transparency (grey background).                              **
'**                                                                        **
'****************************************************************************
Private Sub GetOverlay()
    
    On Error GoTo ErrorHandler
    
    If Not bOverlayMode Then
        imgMain.Bitmap = 0
        Exit Sub
    End If
    
    '--- Initialize the main imaging control
    If Dir(sOverlayFile, vbNormal) <> "" Then
        With imgMain
            .Load sOverlayFile, 24, 1, 1
            .SetRgnColor RGB(127, 127, 127), L_RGN_SET
            .PaintSizeMode = PAINTSIZEMODE_FITSIDES
        End With
    Else
        MsgBox sResVideoNoOverlay, iMsgFlags, sResVideoErrorCaption
    End If
    Exit Sub
ErrorHandler:
    MsgBox sResVideoOverlayError, iMsgFlags, sResVideoErrorCaption
End Sub

'****************************************************************************
'**                                                                        **
'** Routine.: ctlVideo - User Control Initialize                           **
'**                                                                        **
'** Notes...: This procedure retrieves video capture sources from the OS.  **
'**                                                                        **
'****************************************************************************
Private Sub GetVideoSources()
    
    On Error Resume Next
    Dim nRet As Integer                     'Return value of call to video connect

    '--- Initialize the LEADTOOLS Video Capture Control (vidLive)
    With vidLive
   
        '--- Unlock support - this following key has been purchased from LEAD Technologies.
        .UnlockSupport L_SUPPORT_MULTIMEDIA, "HKw9JLjh7"
        
        '--- Enumerate the video drivers (calls the CapDriver Event)
        .CapEnumDrivers
        .EnableMethodErrors = True
        If DriverCombo.ListCount = 0 Then
            MsgBox sResVideoNoDrivers, iMsgFlags, sResVideoErrorCaption
        Else
        
            '---- USE 1 FOR USB, 0 FOR NOGATECH PCMCIA CARD
            DriverCombo.ListIndex = 0
            nRet = .CapConnect(DriverCombo.ListIndex)
           If (nRet <> 0) Then
               MsgBox sResVideoNoDevice, iMsgFlags, sResVideoErrorCaption
           End If
        End If
        .CapCaptureAudio = False            'Do not capture audio - this only slows us down
        .CapDisplayMode = DISPLAY_PREVIEW   'Mode MUST be set to preview, this fires the capVideoData event
        .EnableCaptureEvents = True         'Enable events - we need these to perform the overlay
        .CapPreviewRate = 20                'Set the preview rate
    End With
End Sub

'****************************************************************************
'**                                                                        **
'** Routine.: ctlVideo - vidLive_CapDriver                                 **
'**                                                                        **
'** Notes...: This procedure stores the names of video capture drivers in  **
'**           a combo box control.  This is an event procedure that is     **
'**           called by the LEADTOOLS Capture Control (.CapEnumDrivers)    **
'**           method.  The order of the drivers depends upon the Windows   **
'**           enumeration.  The Combo box may be used in future versions   **
'**           to provide for user configuration.                           **
'**                                                                        **
'****************************************************************************
Private Sub vidLive_CapDriver(ByVal iDriver As Integer, ByVal pszName As String)
    On Error GoTo ErrorHandler
    DriverCombo.AddItem pszName, iDriver
    Exit Sub
ErrorHandler:
End Sub

'****************************************************************************
'**                                                                        **
'** Routine.: ctlVideo - vidLive_CapVideoData                              **
'**                                                                        **
'** Notes...: This procedure is called by the LEADTOOLS Capture Control    **
'**           for each frame received into the video buffer.  The LEADTOOLS**
'**           control ONLY fires this event when the following conditions  **
'**           are met: 1) The capture control must be visible and displayed**
'**           on the screen, 2) The control must be connected to a video   **
'**           driver, 3) The EnableCaptureEvents property must be set TRUE,**
'**           4) The capture control must be in DISPLAY_PREVIEW mode.      **
'**           This routine accepts a pointer to the bitmap currently in the**
'**           capture frame buffer.  It sets that as the bitmap for a      **
'**           LEAD imaging control, resizes it fit the main control used to**
'**           display the overlay, then it combines it with the main       **
'**           control (in transparent regions only).                       **
'**           IMPORTANT:  THIS EVENT IS FIRED FOR EACH FRAME AND MAY FIRE  **
'**           UP TO 30 TIMES PER SECOND.  THE CODE IN THIS ROUTINE MUST    **
'**           MINIMIZE CPU/DISK OR THE APPLICATION WILL LOCK UP.           **
'**                                                                        **
'****************************************************************************
Private Sub vidLive_CapVideoData(ByVal hDib As Long, ByVal lTime As Long)
    If bOverlayMode Then
        With imglive
            .SetDIB hDib
            '.Size imgMain.Width, imgMain.Height, RESIZE_NORMAL
            .Size imgMain.BitmapWidth, imgMain.BitmapHeight, RESIZE_NORMAL
            imgMain.Combine 0, 0, imgMain.BitmapWidth, imgMain.BitmapHeight, .Bitmap, 0, 0, CB_OP_ADD + CB_DST_0
        End With
    Else
        imgMain.SetDIB hDib
    End If
End Sub

'****************************************************************************
'**                                                                        **
'** Routine.: ctlVideo - DriverCombo_Click                                 **
'**                                                                        **
'** Notes...: This procedure changes the current video driver.  It is not  **
'**           currently implemented, but retained here for future use.     **
'**                                                                        **
'****************************************************************************
Private Sub DriverCombo_Click()
    On Error Resume Next
    If iActiveIndex <> DriverCombo.ListIndex Then
        iActiveIndex = DriverCombo.ListIndex
        vidLive.CapDisconnect
        vidLive.CapConnect iActiveIndex
    End If
End Sub

'****************************************************************************
'**                                                                        **
'** Routine.: ctlVideo - VideoDriverSetup                                  **
'**                                                                        **
'** Notes...: This procedure calls the setup routine for the currently     **
'**           selected video capture driver.  It is a public method that   **
'**           is intended to be called from an application menu.           **
'**                                                                        **
'****************************************************************************
Public Sub VideoDriverSetup()
    On Error Resume Next
    
    '--- If a setup option is exposed by the video driver for the application
    If vidLive.IsOptionAvailable(DLG_VIDFORMAT) Then
        '--- Display the driver-specific setup option
        vidLive.CapDisplayDialog DLG_VIDFORMAT, 0, 0
    Else
        MsgBox sResVideoNoSetup, iMsgFlags, sResVideoErrorCaption
    End If

End Sub

'****************************************************************************
'**                                                                        **
'** Routine.: ctlVideo - VideoOverlay Property                             **
'**                                                                        **
'** Notes...: These procedures set and retrieve the VideoOverlay property. **
'**                                                                        **
'****************************************************************************
Public Property Let VideoOverlay(sFileName As String)
    sOverlayFile = sFileName                'Store property
    GetOverlay                              'Load the Overlay graphic file
End Property
Public Property Get VideoOverlay() As String
    VideoOverlay = sOverlayFile             'Retrieve property
End Property
Public Property Let VideoOverlayEnable(bMode As Boolean)
    bOverlayMode = bMode
    GetOverlay                              'Load the Overlay graphic file
End Property
Public Property Get VideoOverlayEnable() As Boolean
    VideoOverlayEnable = bOverlayMode
End Property

Public Property Let VideoEnabled(bVideoOn As Boolean)
    vidLive.Visible = bVideoOn
End Property

Public Property Get VideoEnabled() As Boolean
    VideoEnabled = vidLive.Visible
End Property



