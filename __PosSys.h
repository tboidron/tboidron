#include <wx/wx.h>

class __PosSys : public wxApp
{
	public:
        __PosSys();
	public:
		virtual bool OnInit();
        bool OnActivate(wxActivateEvent&e);
        bool OnClose(wxCloseEvent&evt);
	public:
        virtual bool ProcessEvent(wxEvent&);
};
