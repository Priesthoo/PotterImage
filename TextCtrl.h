#include<wx/textctrl.h>

class Potter_Ctrl:public wxTextCtrl{
 public:
 Potter_Ctrl(wxWindow* parent,wxWindowID id,const wxString& emptystring,const wxPoint& pos,const wxSize& sz,long style):wxTextCtrl(parent,id,emptystring,pos,sz,style){
    
 }
};