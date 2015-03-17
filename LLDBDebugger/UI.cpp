//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: UI.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "UI.h"


// Declare the bitmap loading function
extern void wxCrafternz79PnInitBitmapResources();

static bool bBitmapLoaded = false;


LLDBCallStackBase::LLDBCallStackBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafternz79PnInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer2 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer2);
    
    m_dvListCtrlBacktrace = new wxDataViewListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxDV_ROW_LINES|wxDV_SINGLE);
    
    boxSizer2->Add(m_dvListCtrlBacktrace, 1, wxALL|wxEXPAND, 2);
    
    m_dvListCtrlBacktrace->AppendTextColumn(_("#"), wxDATAVIEW_CELL_INERT, 40, wxALIGN_LEFT);
    m_dvListCtrlBacktrace->AppendTextColumn(_("Function"), wxDATAVIEW_CELL_INERT, 200, wxALIGN_LEFT);
    m_dvListCtrlBacktrace->AppendTextColumn(_("File"), wxDATAVIEW_CELL_INERT, 300, wxALIGN_LEFT);
    m_dvListCtrlBacktrace->AppendTextColumn(_("Line"), wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
    
    SetSizeHints(500,300);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_dvListCtrlBacktrace->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(LLDBCallStackBase::OnItemActivated), NULL, this);
    m_dvListCtrlBacktrace->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_CONTEXT_MENU, wxDataViewEventHandler(LLDBCallStackBase::OnContextMenu), NULL, this);
    
}

LLDBCallStackBase::~LLDBCallStackBase()
{
    m_dvListCtrlBacktrace->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(LLDBCallStackBase::OnItemActivated), NULL, this);
    m_dvListCtrlBacktrace->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_CONTEXT_MENU, wxDataViewEventHandler(LLDBCallStackBase::OnContextMenu), NULL, this);
    
}

LLDBOutputViewBase::LLDBOutputViewBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafternz79PnInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer10 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer10);
    
    m_notebook205 = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxBK_DEFAULT);
    wxImageList* m_notebook205_il = new wxImageList(16, 16);
    m_notebook205->AssignImageList(m_notebook205_il);
    
    boxSizer10->Add(m_notebook205, 1, wxEXPAND, 5);
    
    m_panelConsole = new wxPanel(m_notebook205, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    int m_panelConsoleImgIndex;
    m_panelConsoleImgIndex = m_notebook205_il->Add(wxXmlResource::Get()->LoadBitmap(wxT("terminal")));
    m_notebook205->AddPage(m_panelConsole, _("Console"), true, m_panelConsoleImgIndex);
    
    wxBoxSizer* boxSizer213 = new wxBoxSizer(wxVERTICAL);
    m_panelConsole->SetSizer(boxSizer213);
    
    m_stcConsole = new wxStyledTextCtrl(m_panelConsole, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), 0);
    // Configure the fold margin
    m_stcConsole->SetMarginType     (4, wxSTC_MARGIN_SYMBOL);
    m_stcConsole->SetMarginMask     (4, wxSTC_MASK_FOLDERS);
    m_stcConsole->SetMarginSensitive(4, true);
    m_stcConsole->SetMarginWidth    (4, 0);
    
    // Configure the tracker margin
    m_stcConsole->SetMarginWidth(1, 0);
    
    // Configure the symbol margin
    m_stcConsole->SetMarginType (2, wxSTC_MARGIN_SYMBOL);
    m_stcConsole->SetMarginMask (2, ~(wxSTC_MASK_FOLDERS));
    m_stcConsole->SetMarginWidth(2, 0);
    m_stcConsole->SetMarginSensitive(2, true);
    
    // Configure the line numbers margin
    m_stcConsole->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_stcConsole->SetMarginWidth(0,0);
    
    // Configure the line symbol margin
    m_stcConsole->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_stcConsole->SetMarginMask(3, 0);
    m_stcConsole->SetMarginWidth(3,0);
    // Select the lexer
    m_stcConsole->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_stcConsole->StyleClearAll();
    m_stcConsole->SetWrapMode(0);
    m_stcConsole->SetIndentationGuides(0);
    m_stcConsole->SetKeyWords(0, wxT(""));
    m_stcConsole->SetKeyWords(1, wxT(""));
    m_stcConsole->SetKeyWords(2, wxT(""));
    m_stcConsole->SetKeyWords(3, wxT(""));
    m_stcConsole->SetKeyWords(4, wxT(""));
    
    boxSizer213->Add(m_stcConsole, 1, wxALL|wxEXPAND, 2);
    
    m_textCtrlConsoleSend = new wxTextCtrl(m_panelConsole, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_PROCESS_ENTER);
    m_textCtrlConsoleSend->SetFocus();
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlConsoleSend->SetHint(_("Send commands to lldb"));
    #endif
    
    boxSizer213->Add(m_textCtrlConsoleSend, 0, wxALL|wxEXPAND, 2);
    
    m_pageBreakpoints = new wxPanel(m_notebook205, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    int m_pageBreakpointsImgIndex;
    m_pageBreakpointsImgIndex = m_notebook205_il->Add(wxXmlResource::Get()->LoadBitmap(wxT("breakpoint")));
    m_notebook205->AddPage(m_pageBreakpoints, _("Breakpoints"), false, m_pageBreakpointsImgIndex);
    
    wxBoxSizer* boxSizer211 = new wxBoxSizer(wxVERTICAL);
    m_pageBreakpoints->SetSizer(boxSizer211);
    
    m_auibar = new wxAuiToolBar(m_pageBreakpoints, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxAUI_TB_PLAIN_BACKGROUND|wxAUI_TB_DEFAULT_STYLE);
    m_auibar->SetToolBitmapSize(wxSize(16,16));
    
    boxSizer211->Add(m_auibar, 0, wxEXPAND, 5);
    
    m_auibar->AddTool(wxID_NEW, _("New breakpoint"), wxArtProvider::GetBitmap(wxART_PLUS, wxART_TOOLBAR, wxSize(16, 16)), wxNullBitmap, wxITEM_NORMAL, _("New breakpoint"), _("New breakpoint"), NULL);
    
    m_auibar->AddTool(wxID_DELETE, _("Delete Selected Breakpoint"), wxArtProvider::GetBitmap(wxART_MINUS, wxART_TOOLBAR, wxSize(16, 16)), wxNullBitmap, wxITEM_NORMAL, _("Delete Selected Breakpoint"), _("Delete Selected Breakpoint"), NULL);
    
    m_auibar->AddTool(wxID_CLEAR, _("Delete All Breakpoints"), wxArtProvider::GetBitmap(wxART_DELETE, wxART_TOOLBAR, wxSize(16, 16)), wxNullBitmap, wxITEM_NORMAL, _("Delete All Breakpoints"), _("Delete All Breakpoints"), NULL);
    m_auibar->Realize();
    
    m_dataview = new wxDataViewCtrl(m_pageBreakpoints, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxDV_ROW_LINES|wxDV_SINGLE);
    
    m_dataviewModel = new LLDBBreakpointModel;
    m_dataviewModel->SetColCount( 4 );
    m_dataview->AssociateModel(m_dataviewModel.get() );
    
    boxSizer211->Add(m_dataview, 1, wxALL|wxEXPAND, 2);
    
    m_dataview->AppendTextColumn(_("#"), m_dataview->GetColumnCount(), wxDATAVIEW_CELL_INERT, 40, wxALIGN_LEFT);
    m_dataview->AppendTextColumn(_("File"), m_dataview->GetColumnCount(), wxDATAVIEW_CELL_INERT, 200, wxALIGN_LEFT);
    m_dataview->AppendTextColumn(_("Line"), m_dataview->GetColumnCount(), wxDATAVIEW_CELL_INERT, 40, wxALIGN_LEFT);
    m_dataview->AppendTextColumn(_("Function"), m_dataview->GetColumnCount(), wxDATAVIEW_CELL_INERT, 200, wxALIGN_LEFT);
    
    SetSizeHints(500,300);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_textCtrlConsoleSend->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(LLDBOutputViewBase::OnSendCommandToLLDB), NULL, this);
    this->Connect(wxID_NEW, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(LLDBOutputViewBase::OnNewBreakpoint), NULL, this);
    this->Connect(wxID_NEW, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBOutputViewBase::OnNewBreakpointUI), NULL, this);
    this->Connect(wxID_DELETE, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBOutputViewBase::OnDeleteBreakpointUI), NULL, this);
    this->Connect(wxID_DELETE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(LLDBOutputViewBase::OnDeleteBreakpoint), NULL, this);
    this->Connect(wxID_CLEAR, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(LLDBOutputViewBase::OnDeleteAll), NULL, this);
    this->Connect(wxID_CLEAR, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBOutputViewBase::OnDeleteAllUI), NULL, this);
    m_dataview->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(LLDBOutputViewBase::OnBreakpointActivated), NULL, this);
    
}

LLDBOutputViewBase::~LLDBOutputViewBase()
{
    m_textCtrlConsoleSend->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(LLDBOutputViewBase::OnSendCommandToLLDB), NULL, this);
    this->Disconnect(wxID_NEW, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(LLDBOutputViewBase::OnNewBreakpoint), NULL, this);
    this->Disconnect(wxID_NEW, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBOutputViewBase::OnNewBreakpointUI), NULL, this);
    this->Disconnect(wxID_DELETE, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBOutputViewBase::OnDeleteBreakpointUI), NULL, this);
    this->Disconnect(wxID_DELETE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(LLDBOutputViewBase::OnDeleteBreakpoint), NULL, this);
    this->Disconnect(wxID_CLEAR, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(LLDBOutputViewBase::OnDeleteAll), NULL, this);
    this->Disconnect(wxID_CLEAR, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBOutputViewBase::OnDeleteAllUI), NULL, this);
    m_dataview->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(LLDBOutputViewBase::OnBreakpointActivated), NULL, this);
    
}

LLDBNewBreakpointDlgBase::LLDBNewBreakpointDlgBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafternz79PnInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer32 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer32);
    
    wxFlexGridSizer* flexGridSizer41 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer41->SetFlexibleDirection( wxBOTH );
    flexGridSizer41->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer41->AddGrowableCol(1);
    
    boxSizer32->Add(flexGridSizer41, 1, wxALL|wxEXPAND, 5);
    
    m_checkBoxFileLine = new wxCheckBox(this, wxID_ANY, _("File and Line:"), wxDefaultPosition, wxSize(-1,-1), wxALIGN_RIGHT);
    m_checkBoxFileLine->SetValue(false);
    
    flexGridSizer41->Add(m_checkBoxFileLine, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_textCtrlFile = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    m_textCtrlFile->SetToolTip(_("File name"));
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlFile->SetHint(wxT(""));
    #endif
    
    flexGridSizer41->Add(m_textCtrlFile, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
    
    m_textCtrlLine = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    m_textCtrlLine->SetToolTip(_("Line number"));
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlLine->SetHint(wxT(""));
    #endif
    
    flexGridSizer41->Add(m_textCtrlLine, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_checkBoxFuncName = new wxCheckBox(this, wxID_ANY, _("Function name:"), wxDefaultPosition, wxSize(-1,-1), wxALIGN_RIGHT);
    m_checkBoxFuncName->SetValue(false);
    
    flexGridSizer41->Add(m_checkBoxFuncName, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_textCtrlFunctionName = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlFunctionName->SetHint(wxT(""));
    #endif
    
    flexGridSizer41->Add(m_textCtrlFunctionName, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
    
    flexGridSizer41->Add(0, 0, 1, wxALL, 5);
    
    m_stdBtnSizer34 = new wxStdDialogButtonSizer();
    
    boxSizer32->Add(m_stdBtnSizer34, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_button36 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_button36->SetDefault();
    m_stdBtnSizer34->AddButton(m_button36);
    
    m_button38 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer34->AddButton(m_button38);
    m_stdBtnSizer34->Realize();
    
    SetSizeHints(-1,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_checkBoxFileLine->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(LLDBNewBreakpointDlgBase::OnCheckFileAndLine), NULL, this);
    m_textCtrlFile->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBNewBreakpointDlgBase::OnFileLineEnabledUI), NULL, this);
    m_textCtrlLine->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBNewBreakpointDlgBase::OnFileLineEnabledUI), NULL, this);
    m_checkBoxFuncName->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(LLDBNewBreakpointDlgBase::OnCheckFuncName), NULL, this);
    m_textCtrlFunctionName->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBNewBreakpointDlgBase::OnFuncNameUI), NULL, this);
    
}

LLDBNewBreakpointDlgBase::~LLDBNewBreakpointDlgBase()
{
    m_checkBoxFileLine->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(LLDBNewBreakpointDlgBase::OnCheckFileAndLine), NULL, this);
    m_textCtrlFile->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBNewBreakpointDlgBase::OnFileLineEnabledUI), NULL, this);
    m_textCtrlLine->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBNewBreakpointDlgBase::OnFileLineEnabledUI), NULL, this);
    m_checkBoxFuncName->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(LLDBNewBreakpointDlgBase::OnCheckFuncName), NULL, this);
    m_textCtrlFunctionName->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBNewBreakpointDlgBase::OnFuncNameUI), NULL, this);
    
}

LLDBLocalsViewBase::LLDBLocalsViewBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafternz79PnInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer67 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer67);
    
    m_auibar199 = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxAUI_TB_PLAIN_BACKGROUND|wxAUI_TB_DEFAULT_STYLE);
    m_auibar199->SetToolBitmapSize(wxSize(16,16));
    
    boxSizer67->Add(m_auibar199, 0, wxEXPAND, 5);
    
    m_auibar199->AddTool(wxID_NEW, _("Add Watch..."), wxArtProvider::GetBitmap(wxART_PLUS, wxART_TOOLBAR, wxSize(16, 16)), wxNullBitmap, wxITEM_NORMAL, _("Add Watch..."), _("Add Watch..."), NULL);
    
    m_auibar199->AddTool(wxID_DELETE, _("Delete Watch"), wxArtProvider::GetBitmap(wxART_DELETE, wxART_TOOLBAR, wxSize(16, 16)), wxNullBitmap, wxITEM_NORMAL, _("Delete Watch"), _("Delete Watch"), NULL);
    m_auibar199->Realize();
    
    SetMinSize( wxSize(200,200) );
    SetSizeHints(-1,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    this->Connect(wxID_NEW, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(LLDBLocalsViewBase::OnNewWatch), NULL, this);
    this->Connect(wxID_DELETE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(LLDBLocalsViewBase::OnDelete), NULL, this);
    this->Connect(wxID_DELETE, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBLocalsViewBase::OnDeleteUI), NULL, this);
    
}

LLDBLocalsViewBase::~LLDBLocalsViewBase()
{
    this->Disconnect(wxID_NEW, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(LLDBLocalsViewBase::OnNewWatch), NULL, this);
    this->Disconnect(wxID_DELETE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(LLDBLocalsViewBase::OnDelete), NULL, this);
    this->Disconnect(wxID_DELETE, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBLocalsViewBase::OnDeleteUI), NULL, this);
    
}

LLDBSettingDialogBase::LLDBSettingDialogBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafternz79PnInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer77 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer77);
    
    m_notebook87 = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxBK_DEFAULT);
    
    boxSizer77->Add(m_notebook87, 1, wxALL|wxEXPAND, 5);
    
    m_panel89 = new wxPanel(m_notebook87, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_notebook87->AddPage(m_panel89, _("General"), true);
    
    wxBoxSizer* boxSizer93 = new wxBoxSizer(wxVERTICAL);
    m_panel89->SetSizer(boxSizer93);
    
    wxArrayString m_pgMgrDisplayPropertiesArr;
    wxUnusedVar(m_pgMgrDisplayPropertiesArr);
    wxArrayInt m_pgMgrDisplayPropertiesIntArr;
    wxUnusedVar(m_pgMgrDisplayPropertiesIntArr);
    m_pgMgrDisplayProperties = new wxPropertyGridManager(m_panel89, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxPG_DESCRIPTION|wxPG_SPLITTER_AUTO_CENTER|wxPG_BOLD_MODIFIED);
    
    boxSizer93->Add(m_pgMgrDisplayProperties, 1, wxALL|wxEXPAND, 5);
    
    m_pgPropCatGeneral = m_pgMgrDisplayProperties->Append(  new wxPropertyCategory( _("Behaviour") ) );
    m_pgPropCatGeneral->SetHelpString(wxT(""));
    
    m_pgPropRaiseCodeLite = m_pgMgrDisplayProperties->AppendIn( m_pgPropCatGeneral,  new wxBoolProperty( _("Raise CodeLite when breakpoint hit"), wxPG_LABEL, 1) );
    m_pgPropRaiseCodeLite->SetHelpString(_("When a breakpoint is hit, notify the user raising CodeLite"));
    
    m_pgProp138 = m_pgMgrDisplayProperties->Append(  new wxPropertyCategory( _("Display") ) );
    m_pgProp138->SetHelpString(wxT(""));
    
    m_pgPropArraySize = m_pgMgrDisplayProperties->AppendIn( m_pgProp138,  new wxIntProperty( _("Max number of array elements"), wxPG_LABEL, 50) );
    m_pgPropArraySize->SetHelpString(_("The maximum number of eleements to display in arrays"));
    
    m_pgPropCallStackSize = m_pgMgrDisplayProperties->AppendIn( m_pgProp138,  new wxIntProperty( _("Backtrace frames"), wxPG_LABEL, 100) );
    m_pgPropCallStackSize->SetHelpString(_("Maximum number of frames to show in the callstack window"));
    
    m_panel91 = new wxPanel(m_notebook87, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_notebook87->AddPage(m_panel91, _("Types"), false);
    
    wxBoxSizer* boxSizer107 = new wxBoxSizer(wxVERTICAL);
    m_panel91->SetSizer(boxSizer107);
    
    m_stcTypes = new wxStyledTextCtrl(m_panel91, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), 0);
    #ifdef __WXMSW__
    // To get the newer version of the font on MSW, we use font wxSYS_DEFAULT_GUI_FONT with family set to wxFONTFAMILY_TELETYPE
    wxFont m_stcTypesFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_stcTypesFont.SetFamily(wxFONTFAMILY_TELETYPE);
    #else
    wxFont m_stcTypesFont = wxSystemSettings::GetFont(wxSYS_ANSI_FIXED_FONT);
    m_stcTypesFont.SetFamily(wxFONTFAMILY_TELETYPE);
    #endif
    m_stcTypes->SetFont(m_stcTypesFont);
    m_stcTypes->SetToolTip(_("LLDB has a data formatters subsystem that allows users to define custom display options for their variables\nYou can set here the types to pass to LLDB"));
    // Configure the fold margin
    m_stcTypes->SetMarginType     (4, wxSTC_MARGIN_SYMBOL);
    m_stcTypes->SetMarginMask     (4, wxSTC_MASK_FOLDERS);
    m_stcTypes->SetMarginSensitive(4, true);
    m_stcTypes->SetMarginWidth    (4, 0);
    
    // Configure the tracker margin
    m_stcTypes->SetMarginWidth(1, 0);
    
    // Configure the symbol margin
    m_stcTypes->SetMarginType (2, wxSTC_MARGIN_SYMBOL);
    m_stcTypes->SetMarginMask (2, ~(wxSTC_MASK_FOLDERS));
    m_stcTypes->SetMarginWidth(2, 0);
    m_stcTypes->SetMarginSensitive(2, true);
    
    // Configure the line numbers margin
    m_stcTypes->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_stcTypes->SetMarginWidth(0,0);
    
    // Configure the line symbol margin
    m_stcTypes->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_stcTypes->SetMarginMask(3, 0);
    m_stcTypes->SetMarginWidth(3,0);
    // Select the lexer
    m_stcTypes->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_stcTypes->StyleClearAll();
    for(int i=0; i<wxSTC_STYLE_MAX; ++i) {
        m_stcTypes->StyleSetFont(i, m_stcTypesFont);
    }
    m_stcTypes->SetWrapMode(0);
    m_stcTypes->SetIndentationGuides(0);
    m_stcTypes->SetKeyWords(0, wxT(""));
    m_stcTypes->SetKeyWords(1, wxT(""));
    m_stcTypes->SetKeyWords(2, wxT(""));
    m_stcTypes->SetKeyWords(3, wxT(""));
    m_stcTypes->SetKeyWords(4, wxT(""));
    
    boxSizer107->Add(m_stcTypes, 1, wxALL|wxEXPAND, 5);
    
    m_hyperLink111 = new wxHyperlinkCtrl(m_panel91, wxID_ANY, _("Learn more about LLDB types"), wxT("http://lldb.llvm.org/varformats.html"), wxDefaultPosition, wxSize(-1,-1), wxHL_DEFAULT_STYLE);
    m_hyperLink111->SetNormalColour(wxColour(wxT("#0000FF")));
    m_hyperLink111->SetHoverColour(wxColour(wxT("#0000FF")));
    m_hyperLink111->SetVisitedColour(wxColour(wxT("#FF0000")));
    
    boxSizer107->Add(m_hyperLink111, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_panel142 = new wxPanel(m_notebook87, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_notebook87->AddPage(m_panel142, _("Advanced"), false);
    
    wxBoxSizer* boxSizer160 = new wxBoxSizer(wxVERTICAL);
    m_panel142->SetSizer(boxSizer160);
    
    wxArrayString m_pgMgrAdvancedArr;
    wxUnusedVar(m_pgMgrAdvancedArr);
    wxArrayInt m_pgMgrAdvancedIntArr;
    wxUnusedVar(m_pgMgrAdvancedIntArr);
    m_pgMgrAdvanced = new wxPropertyGridManager(m_panel142, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxPG_DESCRIPTION|wxPG_SPLITTER_AUTO_CENTER|wxPG_BOLD_MODIFIED);
    
    boxSizer160->Add(m_pgMgrAdvanced, 1, wxALL|wxEXPAND, 5);
    
    m_pgProp165 = m_pgMgrAdvanced->Append(  new wxPropertyCategory( _("Debugger Proxy") ) );
    m_pgProp165->SetHelpString(wxT(""));
    
    m_pgMgrAdvancedArr.Clear();
    m_pgMgrAdvancedIntArr.Clear();
    m_pgMgrAdvancedArr.Add(_("Local proxy process (default)"));
    m_pgMgrAdvancedArr.Add(_("Remote proxy process over TCP/IP"));
    m_pgPropProxyType = m_pgMgrAdvanced->AppendIn( m_pgProp165,  new wxEnumProperty( _("Proxy type"), wxPG_LABEL, m_pgMgrAdvancedArr, m_pgMgrAdvancedIntArr, 0) );
    m_pgPropProxyType->SetHelpString(_("Debugging using LLDB is always done over a proxy process (i.e. codelite-lldb)\nHere you can select the type of the proxy to use (local or remote):\n* Local proxy is used by default to debug local processes (this is the default)\n* Remote proxy: use this method to connect to a remote codelite-lldb proxy server over TCP/IP"));
    
    m_pgProp169 = m_pgMgrAdvanced->Append(  new wxPropertyCategory( _("Remote proxy settings") ) );
    m_pgProp169->SetHelpString(wxT(""));
    
    m_pgPropProxyIP = m_pgMgrAdvanced->AppendIn( m_pgProp169,  new wxStringProperty( _("Address"), wxPG_LABEL, _("127.0.0.1")) );
    m_pgPropProxyIP->SetHelpString(_("The IP address on which the remote proxy server is accepting connections"));
    
    m_pgPropProxyPort = m_pgMgrAdvanced->AppendIn( m_pgProp169,  new wxIntProperty( _("Port"), wxPG_LABEL, 13610) );
    m_pgPropProxyPort->SetHelpString(_("The port number on which the remote proxy server is accepting connections"));
    
    m_stdBtnSizer79 = new wxStdDialogButtonSizer();
    
    boxSizer77->Add(m_stdBtnSizer79, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_button81 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer79->AddButton(m_button81);
    
    m_button83 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_button83->SetDefault();
    m_stdBtnSizer79->AddButton(m_button83);
    
    m_button175 = new wxButton(this, wxID_APPLY, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer79->AddButton(m_button175);
    m_stdBtnSizer79->Realize();
    
    SetSizeHints(500,400);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_pgMgrDisplayProperties->Connect(wxEVT_PG_CHANGED, wxPropertyGridEventHandler(LLDBSettingDialogBase::OnGeneralValueChanged), NULL, this);
    m_pgMgrAdvanced->Connect(wxEVT_PG_CHANGED, wxPropertyGridEventHandler(LLDBSettingDialogBase::OnAdvancedValueChanged), NULL, this);
    m_button83->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBSettingDialogBase::OnOKUI), NULL, this);
    m_button175->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LLDBSettingDialogBase::OnApply), NULL, this);
    m_button175->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBSettingDialogBase::OnOKUI), NULL, this);
    
}

LLDBSettingDialogBase::~LLDBSettingDialogBase()
{
    m_pgMgrDisplayProperties->Disconnect(wxEVT_PG_CHANGED, wxPropertyGridEventHandler(LLDBSettingDialogBase::OnGeneralValueChanged), NULL, this);
    m_pgMgrAdvanced->Disconnect(wxEVT_PG_CHANGED, wxPropertyGridEventHandler(LLDBSettingDialogBase::OnAdvancedValueChanged), NULL, this);
    m_button83->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBSettingDialogBase::OnOKUI), NULL, this);
    m_button175->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LLDBSettingDialogBase::OnApply), NULL, this);
    m_button175->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBSettingDialogBase::OnOKUI), NULL, this);
    
}

LLDBThreadsViewBase::LLDBThreadsViewBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafternz79PnInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer115 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer115);
    
    m_dvListCtrlThreads = new wxDataViewListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxDV_ROW_LINES|wxDV_SINGLE);
    
    boxSizer115->Add(m_dvListCtrlThreads, 1, wxALL|wxEXPAND, 2);
    
    m_dvListCtrlThreads->AppendTextColumn(_("#"), wxDATAVIEW_CELL_INERT, 70, wxALIGN_LEFT);
    m_dvListCtrlThreads->AppendTextColumn(_("Stop Reason"), wxDATAVIEW_CELL_INERT, 100, wxALIGN_LEFT);
    m_dvListCtrlThreads->AppendTextColumn(_("Function"), wxDATAVIEW_CELL_INERT, 150, wxALIGN_LEFT);
    m_dvListCtrlThreads->AppendTextColumn(_("File"), wxDATAVIEW_CELL_INERT, 200, wxALIGN_LEFT);
    m_dvListCtrlThreads->AppendTextColumn(_("Line"), wxDATAVIEW_CELL_INERT, 40, wxALIGN_LEFT);
    
    SetSizeHints(500,300);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_dvListCtrlThreads->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(LLDBThreadsViewBase::OnItemActivated), NULL, this);
    
}

LLDBThreadsViewBase::~LLDBThreadsViewBase()
{
    m_dvListCtrlThreads->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(LLDBThreadsViewBase::OnItemActivated), NULL, this);
    
}

LLDBTooltipBase::LLDBTooltipBase(wxWindow* parent,long style)
    : wxPopupWindow(parent, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafternz79PnInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer121 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer121);
    
    m_panel134 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL|wxBORDER_SIMPLE);
    
    boxSizer121->Add(m_panel134, 1, wxEXPAND, 5);
    
    wxBoxSizer* boxSizer136 = new wxBoxSizer(wxVERTICAL);
    m_panel134->SetSizer(boxSizer136);
    
    m_treeCtrl = new wxTreeCtrl(m_panel134, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTR_DEFAULT_STYLE);
    m_treeCtrl->SetBackgroundColour(wxColour(wxT("rgb(251,234,160)")));
    m_treeCtrl->SetForegroundColour(wxColour(wxT("rgb(33,33,33)")));
    
    boxSizer136->Add(m_treeCtrl, 1, wxALL|wxEXPAND, 1);
    
    m_panelStatus = new wxPanel(m_panel134, wxID_ANY, wxDefaultPosition, wxSize(-1,15), wxTAB_TRAVERSAL);
    
    boxSizer136->Add(m_panelStatus, 0, wxEXPAND, 1);
    
    m_timerCheckMousePos = new wxTimer;
    m_timerCheckMousePos->Start(25, false);
    
    SetSizeHints(300,200);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_treeCtrl->Connect(wxEVT_COMMAND_TREE_ITEM_EXPANDING, wxTreeEventHandler(LLDBTooltipBase::OnItemExpanding), NULL, this);
    m_panelStatus->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(LLDBTooltipBase::OnStatusBarLeftDown), NULL, this);
    m_panelStatus->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(LLDBTooltipBase::OnStatusBarLeftUp), NULL, this);
    m_panelStatus->Connect(wxEVT_MOTION, wxMouseEventHandler(LLDBTooltipBase::OnStatusBarMotion), NULL, this);
    m_panelStatus->Connect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(LLDBTooltipBase::OnStatusEnterWindow), NULL, this);
    m_panelStatus->Connect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(LLDBTooltipBase::OnStatusLeaveWindow), NULL, this);
    m_timerCheckMousePos->Connect(wxEVT_TIMER, wxTimerEventHandler(LLDBTooltipBase::OnCheckMousePosition), NULL, this);
    
}

LLDBTooltipBase::~LLDBTooltipBase()
{
    m_treeCtrl->Disconnect(wxEVT_COMMAND_TREE_ITEM_EXPANDING, wxTreeEventHandler(LLDBTooltipBase::OnItemExpanding), NULL, this);
    m_panelStatus->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(LLDBTooltipBase::OnStatusBarLeftDown), NULL, this);
    m_panelStatus->Disconnect(wxEVT_LEFT_UP, wxMouseEventHandler(LLDBTooltipBase::OnStatusBarLeftUp), NULL, this);
    m_panelStatus->Disconnect(wxEVT_MOTION, wxMouseEventHandler(LLDBTooltipBase::OnStatusBarMotion), NULL, this);
    m_panelStatus->Disconnect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(LLDBTooltipBase::OnStatusEnterWindow), NULL, this);
    m_panelStatus->Disconnect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(LLDBTooltipBase::OnStatusLeaveWindow), NULL, this);
    m_timerCheckMousePos->Disconnect(wxEVT_TIMER, wxTimerEventHandler(LLDBTooltipBase::OnCheckMousePosition), NULL, this);
    
    m_timerCheckMousePos->Stop();
    wxDELETE( m_timerCheckMousePos );

}

FolderMappingBaseDlg::FolderMappingBaseDlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafternz79PnInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer179 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer179);
    
    m_staticText197 = new wxStaticText(this, wxID_ANY, _("You are debugging on a remote machine. In order for codelite\nto be able to load files into the editor, codelite needs to map the folders on\nyour local machine to the folders on the remote machine"), wxDefaultPosition, wxSize(-1,-1), wxALIGN_CENTRE);
    m_staticText197->SetForegroundColour(wxColour(wxT("rgb(0,64,0)")));
    wxFont m_staticText197Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_staticText197Font.SetWeight(wxFONTWEIGHT_BOLD);
    m_staticText197->SetFont(m_staticText197Font);
    
    boxSizer179->Add(m_staticText197, 0, wxALL|wxEXPAND, 5);
    
    wxFlexGridSizer* flexGridSizer187 = new wxFlexGridSizer(0, 2, 0, 0);
    flexGridSizer187->SetFlexibleDirection( wxBOTH );
    flexGridSizer187->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer187->AddGrowableCol(1);
    
    boxSizer179->Add(flexGridSizer187, 1, wxALL|wxEXPAND, 5);
    
    m_staticText189 = new wxStaticText(this, wxID_ANY, _("Local Folder:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer187->Add(m_staticText189, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_dirPickerLocal = new wxDirPickerCtrl(this, wxID_ANY, wxEmptyString, _("Select a folder"), wxDefaultPosition, wxSize(-1,-1), wxDIRP_DEFAULT_STYLE|wxDIRP_USE_TEXTCTRL);
    m_dirPickerLocal->SetToolTip(_("Local Folder"));
    
    flexGridSizer187->Add(m_dirPickerLocal, 0, wxALL|wxEXPAND, 5);
    
    m_staticText193 = new wxStaticText(this, wxID_ANY, _("Remote Folder:"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer187->Add(m_staticText193, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_textCtrlRemote = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    m_textCtrlRemote->SetToolTip(_("Remote Folder"));
    #if wxVERSION_NUMBER >= 3000
    m_textCtrlRemote->SetHint(wxT(""));
    #endif
    
    flexGridSizer187->Add(m_textCtrlRemote, 0, wxALL|wxEXPAND, 5);
    
    m_stdBtnSizer181 = new wxStdDialogButtonSizer();
    
    boxSizer179->Add(m_stdBtnSizer181, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_button183 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_button183->SetDefault();
    m_stdBtnSizer181->AddButton(m_button183);
    
    m_button185 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer181->AddButton(m_button185);
    m_stdBtnSizer181->Realize();
    
    SetSizeHints(-1,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_button183->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FolderMappingBaseDlg::OnOKUI), NULL, this);
    
}

FolderMappingBaseDlg::~FolderMappingBaseDlg()
{
    m_button183->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(FolderMappingBaseDlg::OnOKUI), NULL, this);
    
}
