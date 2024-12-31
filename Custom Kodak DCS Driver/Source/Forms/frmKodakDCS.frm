VERSION 5.00
Begin VB.Form frmKodakDCS 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Kodak DCS Interface"
   ClientHeight    =   7590
   ClientLeft      =   45
   ClientTop       =   435
   ClientWidth     =   10410
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   7590
   ScaleWidth      =   10410
   StartUpPosition =   3  'Windows Default
   Begin VB.Frame frmInfo 
      Caption         =   "Interface Status"
      Height          =   2805
      Left            =   60
      TabIndex        =   0
      Top             =   60
      Width           =   4935
      Begin VB.Label lblCameraSerialNo 
         BackColor       =   &H8000000E&
         BorderStyle     =   1  'Fixed Single
         Height          =   255
         Left            =   1380
         TabIndex        =   4
         Top             =   600
         Width           =   3465
      End
      Begin VB.Label lblLabel 
         Caption         =   "Serial Number"
         Height          =   255
         Index           =   1
         Left            =   90
         TabIndex        =   3
         Top             =   630
         Width           =   1425
      End
      Begin VB.Label lblLibStatus 
         BackColor       =   &H8000000E&
         BorderStyle     =   1  'Fixed Single
         Caption         =   "Library Status"
         Height          =   255
         Left            =   1380
         TabIndex        =   2
         Top             =   300
         Width           =   3465
      End
      Begin VB.Label lblLabel 
         Caption         =   "Library Status"
         Height          =   255
         Index           =   0
         Left            =   90
         TabIndex        =   1
         Top             =   300
         Width           =   1425
      End
   End
End
Attribute VB_Name = "frmKodakDCS"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'------------------------------------------------------------------------------
'
'  Component..: Redmer Controls Kodak DCS Interface
'
'  Description: This form is implemented as a complete object for interfacing
'               Visual Basic with the Kodak DCS Series digital camera DLLs.  The
'               DLL is loaded automatically upon form load and unloaded upon
'               form termination.  The DLL is written in Microsoft C and is
'               located in the same project directory as this source.  The
'               production DLL file must be in the \WINDOWS\SYSTEM32 directory.
'
'  Author.....: Ronald D. Redmer
'
' (c) 2002 Redmer Controls Inc., All Rights Reserved.
'------------------------------------------------------------------------------
Option Explicit                             'Require variable declaration
        
Private Declare Function RC_Kodak_Load _
        Lib "RC_Kodak_DCS_DLL" Alias "_RC_Kodak_Load@4" (index As Long) As Long

Private Declare Function RC_Kodak_Unload _
        Lib "RC_Kodak_DCS_DLL" Alias "_RC_Kodak_Unload@0" () As Long
        
Private Declare Function RC_Kodak_GetCamera _
        Lib "RC_Kodak_DCS_DLL" Alias "_RC_Kodak_GetCamera@4" (ByRef sSerial As String) As Long
        
Private Declare Function RC_Kodak_FreeCamera _
        Lib "RC_Kodak_DCS_DLL" Alias "_RC_Kodak_FreeCamera@0" () As Long
        
'DllExport char * _stdcall RC_Kodak_GetCamera(void)
       
Private iDLLStatus As Integer               'Set to 0 when DLL is loaded properly

Private Sub Form_Load()
'    On Error GoTo ErrorHandler
    
    Dim sSerial As String
    Dim iStatus As Long
    
    sSerial = ""
    
    iDLLStatus = RC_Kodak_Load(0)
    
    iStatus = RC_Kodak_GetCamera(sSerial)
    MsgBox Str(iStatus)
    
    lblCameraSerialNo.Caption = sSerial
    
    UpdateStatus
    Exit Sub
ErrorHandler:
    MsgBox "Error loading Kodak Interface DLL", vbApplicationModal + vbCritical + vbOKOnly, "Error"
End Sub


Private Sub Form_Terminate()
    On Error GoTo ErrorHandler
    Dim iStatus As Integer                  'Status returned from DLL Call
    
    RC_Kodak_FreeCamera
    
    iStatus = RC_Kodak_Unload()
    Exit Sub
ErrorHandler:
    MsgBox "Error unloading Kodak Interface DLL", vbApplicationModal + vbCritical + vbOKOnly, "Error"
End Sub


Private Sub UpdateStatus()
    On Error Resume Next
    
    '--- Validate library status
    If iDLLStatus = 0 Then
        lblLibStatus.Caption = "Active"
    Else
        lblLibStatus.Caption = "Inactive.  Status=" & Trim(Str(iDLLStatus))
    End If
    lblLibStatus.Refresh
End Sub
