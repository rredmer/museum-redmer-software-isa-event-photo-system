VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Object = "{CDE57A40-8B86-11D0-B3C6-00A0C90AEA82}#1.0#0"; "MSDATGRD.OCX"
Begin VB.Form frmOrderEntry 
   Caption         =   "Order Entry"
   ClientHeight    =   8490
   ClientLeft      =   2460
   ClientTop       =   450
   ClientWidth     =   9510
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   Moveable        =   0   'False
   ScaleHeight     =   8490
   ScaleWidth      =   9510
   Begin MSDataGridLib.DataGrid dbgProducts 
      Bindings        =   "OrderEntry.frx":0000
      Height          =   7635
      Left            =   30
      TabIndex        =   1
      Top             =   810
      Width           =   9435
      _ExtentX        =   16642
      _ExtentY        =   13467
      _Version        =   393216
      AllowUpdate     =   0   'False
      AllowArrows     =   0   'False
      HeadLines       =   1
      RowHeight       =   21
      FormatLocked    =   -1  'True
      BeginProperty HeadFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "Arial"
         Size            =   12
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      DataMember      =   "cmdSelectProductCodes"
      Caption         =   "PRODUCT CODES"
      ColumnCount     =   8
      BeginProperty Column00 
         DataField       =   "ProductCode"
         Caption         =   "Code"
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
         DataField       =   "ShortDescription"
         Caption         =   "Label"
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
         DataField       =   "LongDescription"
         Caption         =   "Description"
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
         DataField       =   "Quantity"
         Caption         =   "Quantity"
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
         DataField       =   "Units"
         Caption         =   "Units"
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
      BeginProperty Column05 
         DataField       =   "Price"
         Caption         =   "Price"
         BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
            Type            =   1
            Format          =   """$""#,##0.00"
            HaveTrueFalseNull=   0
            FirstDayOfWeek  =   0
            FirstWeekOfYear =   0
            LCID            =   1033
            SubFormatType   =   2
         EndProperty
      EndProperty
      BeginProperty Column06 
         DataField       =   "ExtendedPrice"
         Caption         =   "Extended Price"
         BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
            Type            =   1
            Format          =   """$""#,##0.00"
            HaveTrueFalseNull=   0
            FirstDayOfWeek  =   0
            FirstWeekOfYear =   0
            LCID            =   1033
            SubFormatType   =   2
         EndProperty
      EndProperty
      BeginProperty Column07 
         DataField       =   "Secured"
         Caption         =   "Secured"
         BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
            Type            =   5
            Format          =   ""
            HaveTrueFalseNull=   1
            TrueValue       =   "True"
            FalseValue      =   "False"
            NullValue       =   ""
            FirstDayOfWeek  =   0
            FirstWeekOfYear =   0
            LCID            =   1033
            SubFormatType   =   7
         EndProperty
      EndProperty
      SplitCount      =   1
      BeginProperty Split0 
         ScrollBars      =   2
         AllowRowSizing  =   0   'False
         AllowSizing     =   0   'False
         BeginProperty Column00 
            ColumnAllowSizing=   0   'False
            ColumnWidth     =   1005.165
         EndProperty
         BeginProperty Column01 
            ColumnWidth     =   1244.976
         EndProperty
         BeginProperty Column02 
            ColumnWidth     =   1739.906
         EndProperty
         BeginProperty Column03 
            ColumnWidth     =   989.858
         EndProperty
         BeginProperty Column04 
            ColumnWidth     =   645.165
         EndProperty
         BeginProperty Column05 
            ColumnWidth     =   1080
         EndProperty
         BeginProperty Column06 
            ColumnWidth     =   1154.835
         EndProperty
         BeginProperty Column07 
            ColumnWidth     =   989.858
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.ImageList ImageList1 
      Left            =   8880
      Top             =   90
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   32
      ImageHeight     =   32
      MaskColor       =   12632256
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628} 
         NumListImages   =   4
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "OrderEntry.frx":0011
            Key             =   ""
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "OrderEntry.frx":0333
            Key             =   ""
         EndProperty
         BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "OrderEntry.frx":0655
            Key             =   ""
         EndProperty
         BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "OrderEntry.frx":0977
            Key             =   ""
         EndProperty
      EndProperty
   End
   Begin MSComctlLib.Toolbar tlbProducts 
      Align           =   1  'Align Top
      Height          =   780
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   9510
      _ExtentX        =   16775
      _ExtentY        =   1376
      ButtonWidth     =   1032
      ButtonHeight    =   1376
      Style           =   1
      ImageList       =   "ImageList1"
      _Version        =   393216
      BeginProperty Buttons {66833FE8-8583-11D1-B16A-00C0F0283628} 
         NumButtons      =   1
         BeginProperty Button1 {66833FEA-8583-11D1-B16A-00C0F0283628} 
            Caption         =   "Exit"
            Object.ToolTipText     =   "Return to preview"
            ImageIndex      =   4
         EndProperty
      EndProperty
   End
End
Attribute VB_Name = "frmOrderEntry"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False


Private Sub dbgProducts_DblClick()

    Dim bFound As Boolean

    With DE.rscmdSelectCodes
        bFound = False
        If Not .BOF Then
            .MoveFirst
        End If
        Do While Not .EOF
             If .Fields("ProductCode").Value = DE.rscmdSelectProductCodes("ProductCode").Value Then
                bFound = True
                .Fields("Quantity") = .Fields("Quantity") + 1
                .Update
                Exit Do
            End If
            .MoveNext
        Loop
        
        If Not bFound Then
            .AddNew
            .Fields("EventID").Value = frmPreview.dbcEventID.BoundText
            .Fields("CardNum").Value = frmPreview.txtCardNum.Text
            .Fields("ExposureNum").Value = frmPreview.txtExposure.Text
            .Fields("ProductCode").Value = DE.rscmdSelectProductCodes("ProductCode").Value
            .Fields("Quantity").Value = 1
            .Update
        End If
        
    End With

    frmPreview.dbgOrder.Refresh
    
End Sub


Private Sub tlbProducts_ButtonClick(ByVal Button As MSComctlLib.Button)
    On Error Resume Next
    Me.Hide
End Sub
