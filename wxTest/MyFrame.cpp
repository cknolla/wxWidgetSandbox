#include "MyFrame.h"

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
		"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT, "&Quit...\tCtrl-Q");
	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");
	/*
	wxPanel *panel = new wxPanel(this, wxID_ANY);

	wxButton *button = new wxButton(panel, wxID_EXIT, wxT("Quit dis shit"),
		wxPoint(20, 20));
	Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MyFrame::OnExit));
	button->SetFocus();
	*/
	m_parent = new wxPanel(this, wxID_ANY);

	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

	m_lp = new LeftPanel(m_parent);
	m_rp = new RightPanel(m_parent);
	m_lp->SetBackgroundColour(wxColour("#ffffff"));

	hbox->Add(m_lp, 1, wxEXPAND | wxALL, 1);
	hbox->Add(m_rp, 1, wxEXPAND | wxALL, 10);

	m_parent->SetSizer(hbox);
	Centre();
}
void MyFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("This is a wxWidgets' Hello world sample",
		"About Hello World", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello world from wxWidgets!");
}