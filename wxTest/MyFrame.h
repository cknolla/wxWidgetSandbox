#ifndef _MYFRAME_H_
#define _MYFRAME_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Panels.h"

class MyFrame : public wxFrame {
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

	LeftPanel *m_lp;
	RightPanel *m_rp;
	wxPanel *m_parent;
};

enum {
	ID_Hello = 1
};

#endif