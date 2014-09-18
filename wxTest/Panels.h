#ifndef _PANELS_H_
#define _PANELS_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class LeftPanel : public wxPanel {
public:
	wxButton *m_plus;
	wxButton *m_minus;
	wxPanel *m_parent;
	int count;

	LeftPanel(wxPanel *parent);

	void OnPlus(wxCommandEvent & event);
	void OnMinus(wxCommandEvent & event);
};

class RightPanel : public wxPanel {
public:
	wxStaticText *m_text;

	RightPanel(wxPanel *parent);

	void OnSetText(wxCommandEvent & event);
};

enum {
	ID_PLUS = 101,
	ID_MINUS = 102
};

#endif