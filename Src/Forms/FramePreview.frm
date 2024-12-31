VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Object = "{F0D2F211-CCB0-11D0-A316-00AA00688B10}#1.0#0"; "MSDATLST.OCX"
Object = "{CDE57A40-8B86-11D0-B3C6-00A0C90AEA82}#1.0#0"; "MSDATGRD.OCX"
Begin VB.Form frmPreview 
   Caption         =   "ISA/LUCHT Event Photo System"
   ClientHeight    =   8325
   ClientLeft      =   60
   ClientTop       =   630
   ClientWidth     =   11925
   ClipControls    =   0   'False
   ControlBox      =   0   'False
   LinkTopic       =   "Form1"
   Moveable        =   0   'False
   PaletteMode     =   1  'UseZOrder
   Picture         =   "FramePreview.frx":0000
   ScaleHeight     =   8325
   ScaleWidth      =   11925
   Begin MSComctlLib.ImageList imgMain 
      Left            =   11340
      Top             =   7530
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   32
      ImageHeight     =   32
      MaskColor       =   12632256
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628} 
         NumListImages   =   6
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "FramePreview.frx":030A
            Key             =   ""
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "FramePreview.frx":0624
            Key             =   ""
         EndProperty
         BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "FramePreview.frx":093E
            Key             =   ""
         EndProperty
         BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "FramePreview.frx":0C58
            Key             =   ""
         EndProperty
         BeginProperty ListImage5 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "FramePreview.frx":0F72
            Key             =   ""
         EndProperty
         BeginProperty ListImage6 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "FramePreview.frx":1294
            Key             =   ""
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.Toolbar tlbMain 
      Align           =   1  'Align Top
      Height          =   570
      Left            =   0
      TabIndex        =   13
      Top             =   0
      Width           =   11925
      _ExtentX        =   21034
      _ExtentY        =   1005
      ButtonWidth     =   1032
      ButtonHeight    =   1005
      Style           =   1
      ImageList       =   "imgMain"
      _Version        =   393216
      BeginProperty Buttons {66833FE8-8583-11D1-B16A-00C0F0283628} 
         NumButtons      =   5
         BeginProperty Button1 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Object.ToolTipText     =   "Take Picture"
            ImageIndex      =   1
         EndProperty
         BeginProperty Button2 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Object.ToolTipText     =   "Retake Picture"
            ImageIndex      =   5
         EndProperty
         BeginProperty Button3 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Object.ToolTipText     =   "Change Card"
            ImageIndex      =   2
         EndProperty
         BeginProperty Button4 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Object.ToolTipText     =   "Find Subject"
            ImageIndex      =   4
         EndProperty
         BeginProperty Button5 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Object.ToolTipText     =   "Order Form"
            ImageIndex      =   6
         EndProperty
      EndProperty
   End
   Begin VB.Frame fraOrder 
      Height          =   7515
      Left            =   30
      TabIndex        =   2
      Top             =   480
      Width           =   2325
      Begin VB.CommandButton cmdExposureVCR 
         Height          =   495
         Index           =   1
         Left            =   1770
         Picture         =   "FramePreview.frx":15AE
         Style           =   1  'Graphical
         TabIndex        =   19
         Top             =   1950
         Width           =   495
      End
      Begin VB.CommandButton cmdExposureVCR 
         Height          =   495
         Index           =   0
         Left            =   1230
         Picture         =   "FramePreview.frx":19F0
         Style           =   1  'Graphical
         TabIndex        =   18
         Top             =   1950
         Width           =   495
      End
      Begin VB.CommandButton cmdCalc 
         Height          =   495
         Index           =   1
         Left            =   1770
         Picture         =   "FramePreview.frx":1E32
         Style           =   1  'Graphical
         TabIndex        =   17
         Top             =   2640
         Width           =   495
      End
      Begin VB.CommandButton cmdCalc 
         Height          =   495
         Index           =   0
         Left            =   1770
         Picture         =   "FramePreview.frx":213C
         Style           =   1  'Graphical
         TabIndex        =   16
         Top             =   1230
         Width           =   495
      End
      Begin MSDataListLib.DataCombo dbcEventID 
         Bindings        =   "FramePreview.frx":2446
         DataField       =   "EventID"
         DataMember      =   "cmdSelectEvents"
         DataSource      =   "DE"
         Height          =   480
         Left            =   30
         TabIndex        =   15
         Top             =   390
         Width           =   2265
         _ExtentX        =   3995
         _ExtentY        =   847
         _Version        =   393216
         Enabled         =   0   'False
         Style           =   2
         ListField       =   "EventID"
         Text            =   ""
         Object.DataMember      =   "cmdSelectEvents"
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   13.5
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
      End
      Begin VB.CheckBox chkOverlay 
         Caption         =   "Graphic Overlay"
         Height          =   225
         Left            =   30
         TabIndex        =   12
         Top             =   5370
         Value           =   1  'Checked
         Width           =   1965
      End
      Begin MSDataGridLib.DataGrid dbgOrder 
         Height          =   1965
         Left            =   30
         TabIndex        =   11
         Top             =   3360
         Width           =   2235
         _ExtentX        =   3942
         _ExtentY        =   3466
         _Version        =   393216
         AllowUpdate     =   0   'False
         AllowArrows     =   0   'False
         HeadLines       =   1
         RowHeight       =   24
         FormatLocked    =   -1  'True
         BeginProperty HeadFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   12
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ColumnCount     =   5
         BeginProperty Column00 
            DataField       =   "ProductCode"
            Caption         =   "Product"
            BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
               Type            =   0
               Format          =   ""
               HaveTrueFalseNull=   0
               FirstDayOfWeek  =   0
               FirstWeekOfYear =   0
               LCID            =   1033
               SubFormatType   =   0
            EndProperty
         EndProperty
         BeginProperty Column01 
            DataField       =   "Quantity"
            Caption         =   "QTY"
            BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
               Type            =   0
               Format          =   ""
               HaveTrueFalseNull=   0
               FirstDayOfWeek  =   0
               FirstWeekOfYear =   0
               LCID            =   1033
               SubFormatType   =   0
            EndProperty
         EndProperty
         BeginProperty Column02 
            DataField       =   "CardNum"
            Caption         =   "CardNum"
            BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
               Type            =   0
               Format          =   ""
               HaveTrueFalseNull=   0
               FirstDayOfWeek  =   0
               FirstWeekOfYear =   0
               LCID            =   1033
               SubFormatType   =   0
            EndProperty
         EndProperty
         BeginProperty Column03 
            DataField       =   "EventID"
            Caption         =   "EventID"
            BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
               Type            =   0
               Format          =   ""
               HaveTrueFalseNull=   0
               FirstDayOfWeek  =   0
               FirstWeekOfYear =   0
               LCID            =   1033
               SubFormatType   =   0
            EndProperty
         EndProperty
         BeginProperty Column04 
            DataField       =   "ExposureNum"
            Caption         =   "ExposureNum"
            BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
               Type            =   0
               Format          =   ""
               HaveTrueFalseNull=   0
               FirstDayOfWeek  =   0
               FirstWeekOfYear =   0
               LCID            =   1033
               SubFormatType   =   0
            EndProperty
         EndProperty
         SplitCount      =   1
         BeginProperty Split0 
            ScrollBars      =   2
            SizeMode        =   1
            AllowRowSizing  =   0   'False
            AllowSizing     =   0   'False
            BeginProperty Column00 
               ColumnAllowSizing=   0   'False
               ColumnWidth     =   1005.165
            EndProperty
            BeginProperty Column01 
               ColumnAllowSizing=   0   'False
               ColumnWidth     =   1739.906
            EndProperty
            BeginProperty Column02 
               Object.Visible         =   0   'False
               ColumnWidth     =   1140.095
            EndProperty
            BeginProperty Column03 
               Object.Visible         =   0   'False
               ColumnWidth     =   1140.095
            EndProperty
            BeginProperty Column04 
               Object.Visible         =   0   'False
               ColumnWidth     =   1065.26
            EndProperty
         EndProperty
      End
      Begin VB.TextBox txtSubjectID 
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   13.5
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   480
         Left            =   30
         TabIndex        =   9
         Top             =   2640
         Width           =   1695
      End
      Begin VB.TextBox txtExposure 
         Enabled         =   0   'False
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   13.5
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   480
         Left            =   30
         TabIndex        =   7
         TabStop         =   0   'False
         Text            =   "1"
         Top             =   1950
         Width           =   1155
      End
      Begin VB.FileListBox filOverlay 
         Height          =   1845
         Left            =   30
         TabIndex        =   4
         Top             =   5610
         Width           =   2235
      End
      Begin VB.TextBox txtCardNum 
         Enabled         =   0   'False
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   13.5
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   480
         Left            =   30
         TabIndex        =   3
         TabStop         =   0   'False
         Text            =   "1"
         Top             =   1230
         Width           =   1695
      End
      Begin VB.Label lblLabel 
         Caption         =   "Event ID"
         Height          =   165
         Index           =   4
         Left            =   60
         TabIndex        =   14
         Top             =   150
         Width           =   1935
      End
      Begin VB.Label lblLabel 
         Caption         =   "Order Information"
         Height          =   195
         Index           =   3
         Left            =   30
         TabIndex        =   10
         Top             =   3150
         Width           =   1935
      End
      Begin VB.Label lblLabel 
         Caption         =   "Subject ID"
         Height          =   195
         Index           =   2
         Left            =   30
         TabIndex        =   8
         Top             =   2430
         Width           =   1935
      End
      Begin VB.Label lblLabel 
         Caption         =   "Exposure Number"
         Height          =   195
         Index           =   1
         Left            =   30
         TabIndex        =   6
         Top             =   1740
         Width           =   1935
      End
      Begin VB.Label lblLabel 
         Caption         =   "Card Number"
         Height          =   165
         Index           =   0
         Left            =   30
         TabIndex        =   5
         Top             =   990
         Width           =   1935
      End
   End
   Begin EzSNAP.usrComposite usrVideo 
      Height          =   7125
      Left            =   2400
      TabIndex        =   1
      Top             =   600
      Width           =   9495
      _extentx        =   16748
      _extenty        =   12197
   End
   Begin VB.Timer Timer1 
      Enabled         =   0   'False
      Interval        =   500
      Left            =   10860
      Top             =   7650
   End
   Begin MSComctlLib.StatusBar StatusBar1 
      Align           =   2  'Align Bottom
      Height          =   255
      Left            =   0
      TabIndex        =   0
      Top             =   8070
      Width           =   11925
      _ExtentX        =   21034
      _ExtentY        =   450
      _Version        =   393216
      BeginProperty Panels {8E3867A5-8586-11D1-B16A-00C0F0283628} 
         NumPanels       =   1
         BeginProperty Panel1 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
         EndProperty
      EndProperty
   End
   Begin VB.Label lblName 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   315
      Left            =   2400
      TabIndex        =   20
      Top             =   7740
      Width           =   7815
   End
   Begin VB.Menu mnuMain 
      Caption         =   "&File"
      Index           =   0
      Begin VB.Menu mnuFile 
         Caption         =   "Setup for &Event"
         Index           =   1
      End
      Begin VB.Menu mnuFile 
         Caption         =   "Setup Folders"
         Index           =   2
      End
      Begin VB.Menu mnuFile 
         Caption         =   "-"
         Index           =   4
      End
      Begin VB.Menu mnuFile 
         Caption         =   "E&xit"
         Index           =   5
      End
   End
   Begin VB.Menu mnuMain 
      Caption         =   "&Edit"
      Index           =   1
      Begin VB.Menu mnuEdit 
         Caption         =   "Product Codes"
         Index           =   1
      End
      Begin VB.Menu mnuEdit 
         Caption         =   "Event Codes"
         Index           =   2
      End
   End
End
Attribute VB_Name = "frmPreview"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'****************************************************************************
'**                                                                        **
'** Project.: Redmer Controls EZ-SNAP/2002 Windows                         **
'**                                                                        **
'** Module..: frmMain.frm - The main form in the application.  This form   **
'**           provides the main menu and core application functionality.   **
'**                                                                        **
'** Notes...: The main form is composed of re-usable objects that provide  **
'**           a sequential counter for syncronizing images (simulates an   **
'**           exposure counter in a traditional 35mm film camera), a file  **
'**           list box for navigating overlay images, and a graphic control**
'**           that displays a live video source combined with the currently**
'**           selected overlay graphic.                                    **
'**                                                                        **
'** (c) 1992-2002 Redmer Controls.  All rights reserved.                   **
'****************************************************************************
Option Explicit                             'Require explicit variable declaration

Private Sub chkOverlay_Click()

    filOverlay.Enabled = chkOverlay.Value
    filOverlay.Refresh
    
    usrVideo.VideoOverlayEnable = chkOverlay.Value

End Sub

Private Sub cmdCalc_Click(Index As Integer)
    'On Error Resume Next
    Select Case Index
        Case 0          'Calc for Card Number
            frmCalc.FieldIndex = txtCardNum
            frmCalc.Show vbModal
        Case 1          'Calc for Subject ID
            frmCalc.FieldIndex = txtSubjectID
            frmCalc.Show vbModal
    End Select
End Sub

Private Sub cmdExposureVCR_Click(Index As Integer)
    On Error Resume Next
    Select Case Index
        Case 0
            If oSettings.ExposureNum - 1 > 0 Then
                oSettings.ExposureNum = oSettings.ExposureNum - 1
            End If
        Case 1
            oSettings.ExposureNum = oSettings.ExposureNum + 1
    End Select
    UpdateExposureNum
End Sub

'****************************************************************************
'**                                                                        **
'** Routine.: frmMain - Load                                               **
'**                                                                        **
'** Notes...: This procedure is called on form load, it simply initializes **
'**           form controls.                                               **
'**                                                                        **
'****************************************************************************
Private Sub Form_Load()

    On Error Resume Next
    
    '--- Initialize Form Controls
    filOverlay.Path = sAppPath + "IMAGES\"  'Set default application path
    filOverlay.ListIndex = 0                'Load first overlay in list
    
End Sub


Private Sub Form_Initialize()
   UpdateExposureNum
End Sub


Private Sub mnuEdit_Click(Index As Integer)
    On Error Resume Next
    usrVideo.VideoEnabled = False
    Select Case Index
        Case 1
            frmProducts.Show vbModal
        Case 2
            frmEvents.Show vbModal
        Case 3
        Case 4
        Case 5
    End Select
    usrVideo.VideoEnabled = True
End Sub

'****************************************************************************
'**                                                                        **
'** Routine.: frmMain - mnuFile_Click   (Process File Menu Selections)     **
'**                                                                        **
'** Notes...: This procedure is simply a handler for the file menu.        **
'**                                                                        **
'****************************************************************************
Private Sub mnuFile_Click(Index As Integer)
    On Error Resume Next
    Select Case Index
    
        '---- Setup for event
        Case 1
            dbcEventID.Enabled = True
            dbcEventID.SetFocus
        Case 2
        Case 3
        
            If MsgBox("Are you sure?", vbApplicationModal + vbQuestion + vbYesNo, "Reset Exposure Number") = vbYes Then
                oSettings.ExposureNum = 1
                UpdateExposureNum
            End If
        
        Case 4
        Case 5          'Exit program
            
            If MsgBox("Are you sure?", vbApplicationModal + vbQuestion + vbYesNo, "Exit Program") = vbYes Then
               End
            End If
            
    End Select
End Sub

'****************************************************************************
'**                                                                        **
'** Routine.: frmMain - filOverlay_Click   (Move in Overlay File List Box) **
'**                                                                        **
'** Notes...: This procedure sets the VideoOverlay property of the ctlVideo**
'**           user control.  A change in the property value automatically  **
'**           loads the overlay image into the control.                    **
'**                                                                        **
'****************************************************************************
Private Sub filOverlay_Click()
    On Error Resume Next
    usrVideo.VideoOverlay = IIf(Right(filOverlay.Path, 1) <> "\", filOverlay.Path + "\" + filOverlay.FileName, filOverlay.Path + filOverlay.FileName)
End Sub

'****************************************************************************
'**                                                                        **
'** Routine.: frmMain - cmdTakePicture_Click  (Take Picture button pressed)**
'**                                                                        **
'** Notes...: This procedure handles the take picture event (button click).**
'**           The purpose of this event is to download the image from the  **
'**           camera, display it for validation, and increment the sequence**
'**           number if the image is acceptable.                           **
'**                                                                        **
'****************************************************************************
Private Sub cmdTakePicture_Click()
    On Error Resume Next
    
'    If usrUSBCamera.CameraActive = False Then
'        frmPhoto.Show vbModal
'    Else
'        MsgBox "Please disconnect camera prior to clicking this button!"
'    End If

End Sub

Private Sub tlbMain_ButtonClick(ByVal Button As MSComctlLib.Button)
    On Error Resume Next
    Select Case Button.Index
    
        '---- Take picture
        Case 1
            oSettings.ExposureNum = oSettings.ExposureNum + 1
            txtSubjectID.Text = ""
            txtSubjectID.SetFocus
            
        '---- Retake picture
        Case 2
            oSettings.ExposureNum = oSettings.ExposureNum + 1
            
        '---- Change Card Number
        Case 3
            ChangeCardNum
        
        '---- Find Subject
        Case 4
            usrVideo.VideoEnabled = False
            frmSubject.Show vbModal
            usrVideo.VideoEnabled = True
        
        '---- Order Entry
        Case 5
            usrVideo.VideoEnabled = False
            frmOrderEntry.Show vbModal
            usrVideo.VideoEnabled = True
    End Select
    
    UpdateExposureNum
    
End Sub


Private Sub dbcEventID_LostFocus()
    dbcEventID.Enabled = False
End Sub


Private Sub txtCardNum_LostFocus()
   ' On Error Resume Next
    If txtCardNum.Text = "" Then
        Exit Sub
    End If
    txtCardNum.Enabled = False
    txtSubjectID.SetFocus
    UpdateExposureNum
End Sub

Private Sub ChangeCardNum()
    'On Error Resume Next
    oSettings.ExposureNum = 1
    txtSubjectID.Text = ""
    With txtCardNum
        .Text = ""
        .Enabled = True
        .SetFocus
    End With
End Sub

Public Sub UpdateExposureNum()
   ' On Error Resume Next
    txtExposure.Text = Trim(Str$(oSettings.ExposureNum))
    
    With DE.Commands("cmdSelectCodes")
        .Parameters("prmCardNum") = Trim(txtCardNum.Text)
        .Parameters("prmEventID") = dbcEventID.BoundText
        .Parameters("prmSequence") = Val(txtExposure.Text)
    End With
    
    If DE.rscmdSelectCodes.State = adStateOpen Then
        DE.rscmdSelectCodes.Close
    End If
        
    DE.cmdSelectCodes txtCardNum.Text, dbcEventID.BoundText, Val(txtExposure.Text)
    DoEvents
    
    If Not DE.rscmdSelectCodes.BOF Then
        DE.rscmdSelectCodes.MoveFirst
    End If
    
    Set dbgOrder.DataSource = DE.rscmdSelectCodes
    dbgOrder.Refresh
 
    UpdateSubjectName
 
End Sub


Private Sub dbgOrder_DblClick()

    On Error Resume Next

    If DE.rscmdSelectCodes.State = adStateClosed Then
        DE.cmdSelectCodes txtCardNum.Text, dbcEventID.BoundText, Val(txtExposure.Text)
        Set dbgOrder.DataSource = DE.rscmdSelectCodes
        dbgOrder.Refresh
    End If
    
    DoEvents
    
    With DE.rscmdSelectCodes
        If DE.rscmdSelectCodes("Quantity").Value - 1 = 0 Then
            If MsgBox("Are you sure?", vbYesNo + vbDefaultButton2 + vbQuestion, "Remove Product Code") = vbYes Then
                Set dbgOrder.DataSource = Nothing
                dbgOrder.Refresh
                DE.rscmdSelectCodes.Delete adAffectCurrent
                If Not DE.rscmdSelectCodes.BOF Then
                    DE.rscmdSelectCodes.MoveFirst
                End If
            End If
        Else
            DE.rscmdSelectCodes("Quantity").Value = DE.rscmdSelectCodes("Quantity").Value - 1
        End If
    End With
    Set dbgOrder.DataSource = DE.rscmdSelectCodes
    dbgOrder.Refresh

End Sub

Public Sub UpdateSubjectName()
    
    On Error Resume Next
    
    Dim bFound As Boolean
    
    bFound = False
    With DE.rscmdSelectSubjects
    
        .Find "SubjectID=" + txtSubjectID.Text, 0, adSearchForward, 0
        If Not .EOF Then
            bFound = True
            lblName.Caption = .Fields("FirstName").Value + " " + .Fields("LastName").Value
        End If
    
    End With

End Sub

