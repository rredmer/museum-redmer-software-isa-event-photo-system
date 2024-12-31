VERSION 5.00
Begin VB.Form frmCalc 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Touchpad"
   ClientHeight    =   4185
   ClientLeft      =   2445
   ClientTop       =   1035
   ClientWidth     =   2490
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   Moveable        =   0   'False
   ScaleHeight     =   4185
   ScaleWidth      =   2490
   Begin VB.CommandButton cmdNumber 
      Caption         =   "Clear"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   645
      Index           =   12
      Left            =   60
      TabIndex        =   12
      Top             =   3510
      Width           =   2385
   End
   Begin VB.CommandButton cmdNumber 
      Caption         =   "Backspace"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   645
      Index           =   11
      Left            =   60
      TabIndex        =   11
      Top             =   2820
      Width           =   2385
   End
   Begin VB.CommandButton cmdNumber 
      Caption         =   "9"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   645
      Index           =   10
      Left            =   1680
      TabIndex        =   10
      Top             =   60
      Width           =   765
   End
   Begin VB.CommandButton cmdNumber 
      Caption         =   "8"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   645
      Index           =   9
      Left            =   870
      TabIndex        =   9
      Top             =   60
      Width           =   765
   End
   Begin VB.CommandButton cmdNumber 
      Caption         =   "7"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   645
      Index           =   8
      Left            =   60
      TabIndex        =   8
      Top             =   60
      Width           =   765
   End
   Begin VB.CommandButton cmdNumber 
      Caption         =   "6"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   645
      Index           =   7
      Left            =   1680
      TabIndex        =   7
      Top             =   750
      Width           =   765
   End
   Begin VB.CommandButton cmdNumber 
      Caption         =   "5"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   645
      Index           =   6
      Left            =   870
      TabIndex        =   6
      Top             =   750
      Width           =   765
   End
   Begin VB.CommandButton cmdNumber 
      Caption         =   "4"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   645
      Index           =   5
      Left            =   60
      TabIndex        =   5
      Top             =   750
      Width           =   765
   End
   Begin VB.CommandButton cmdNumber 
      Caption         =   "3"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   645
      Index           =   4
      Left            =   1680
      TabIndex        =   4
      Top             =   1440
      Width           =   765
   End
   Begin VB.CommandButton cmdNumber 
      Caption         =   "2"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   645
      Index           =   3
      Left            =   870
      TabIndex        =   3
      Top             =   1440
      Width           =   765
   End
   Begin VB.CommandButton cmdNumber 
      Caption         =   "1"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   645
      Index           =   2
      Left            =   60
      TabIndex        =   2
      Top             =   1440
      Width           =   765
   End
   Begin VB.CommandButton cmdNumber 
      Caption         =   "0"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   645
      Index           =   1
      Left            =   60
      TabIndex        =   1
      Top             =   2130
      Width           =   765
   End
   Begin VB.CommandButton cmdNumber 
      Caption         =   "Enter"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   645
      Index           =   0
      Left            =   870
      TabIndex        =   0
      Top             =   2130
      Width           =   1575
   End
End
Attribute VB_Name = "frmCalc"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim oText As TextBox

Private Sub cmdNumber_Click(Index As Integer)
    On Error Resume Next
    Select Case Index
        Case 0  'Enter
            Me.Hide
        Case 1 To 10
            oText.Text = oText.Text & Chr(47 + Index)
        Case 11 'Backspace
            If Len(oText.Text) > 0 Then
                oText.Text = Left(oText.Text, Len(oText.Text) - 1)
            End If
        Case 12 'Clear
            oText.Text = ""
    End Select
End Sub

Public Property Let FieldIndex(oTarget As Object)
    Set oText = oTarget
End Property

Public Property Get FieldIndex() As Object
    Set FieldIndex = oText
End Property

