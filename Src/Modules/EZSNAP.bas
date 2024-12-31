Attribute VB_Name = "modEZSNAP"
'****************************************************************************
'**                                                                        **
'** Project.: Redmer Controls EZ-SNAP/2002 for Windows                     **
'**                                                                        **
'** Module..: Main.bas - The main module in the application.  This module  **
'**           simply displays the splash screen while initializing forms   **
'**           and controls.  This module is commonly used to initialize    **
'**           database bindings & validate the availability of resources.  **
'**                                                                        **
'** (c) 1992-2002 Redmer Controls.  All rights reserved.                   **
'****************************************************************************
Option Explicit                             'Require explicit variable declaration
Public bDebug As Boolean                    'Global debug mode
Public sAppPath As String                   'Global Application Path
Public oSettings As clsRegistry             'Global Settings

'--- Dimension global constants -------------------------------------------------------------
Global Const EZ_CAPTION As String = "RSC EZ-Link"           'Standard MSGBOX window caption
Global Const EZ_APPDATA As String = "EZSNAP.MDB"            'The name of the application database
Global Const EZ_APPCONFIG As String = "tbl_Configuration"   'The name of the configuration table
Global Const EZ_APPLOG As String = "tbl_Log_Info"           'The name of the log info table
Global Const EZ_APPPORTS As String = "tbl_Serial_Ports"     'The name of the serial port list table
Global Const EZ_MSG_TECH_SUPPORT As String = "Please contact technical support."
Global Const EZ_CONSTRING = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source="

'--- Dimension global variables -------------------------------------------------------------
Global dbApp As ADODB.Connection                            'Application database
Global sAppDbName As String
Global sTmpDbName As String
'****************************************************************************
'**                                                                        **
'** Routine.: Main.bas - Main                                              **
'**                                                                        **
'** Notes...: This procedure is called automatically on startup. It simply **
'**           displays the splash screen while initializing the main form. **
'**                                                                        **
'****************************************************************************
Public Sub Main()

    On Error GoTo ErrorHandler
    
    '--- Display the splash screen
    Load frmSplash                          'Load the splash screen
    frmSplash.Show                          'Display the splash screen
    DoEvents                                'Let Windows catch up
    
    '--- Initialize Globals
    sAppPath = IIf(Right(Trim(App.Path), 1) <> "\", Trim(App.Path) + "\", Trim(App.Path))
    Set oSettings = New clsRegistry
    oSettings.ExposureNum = oSettings.ExposureNum + 1
        
    '--- Construct path to EZSNAP database and verify the file exists
    If (Right(Trim$(App.Path), 1) = "\") Then           'Check for trailing backslash
        sAppDbName = Trim$(App.Path) + "Database\" + EZ_APPDATA       'If slash present, append db name
    Else                                                'Else no slash in path
        sAppDbName = Trim$(App.Path) + "\Database\" + EZ_APPDATA  'Add slash and db name"
    End If
    
    '--- Make sure the application database exists ------------------------------------------
    sTmpDbName = Dir$(sAppDbName, vbNormal)             'Look for the application database
    If (UCase$(sTmpDbName) <> EZ_APPDATA) Then          'Make sure the file exists
        MsgBox "Application data not found." & vbCr & "Please make sure " & sAppDbName & " is in " & App.Path & ".", _
                vbApplicationModal + vbOKOnly + vbExclamation, EZ_CAPTION
        End                                             'End the program
    End If
        
    DE.cnnMain.ConnectionString = EZ_CONSTRING & sAppDbName
    DE.cnnMain.Open
    
    Load frmCalc
    
    Load frmPreview
    Unload frmSplash
    frmPreview.Show
    Exit Sub
    
ErrorHandler:
    MsgBox "Error starting program.  Please check configuration.", vbApplicationModal + vbCritical + vbOKOnly, "Severe Error"
End Sub
