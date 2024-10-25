#include<wx/dialog.h>
#include<wx/statline.h>
#include<wx/button.h>
#include<wx/stattext.h>
#include<wx/sizer.h>
#include<wx/textctrl.h>
#include<wx/spinctrl.h>
#include<wx/checkbox.h>
#include<wx/fontpicker.h>
#include<wx/clrpicker.h>
#include<wx/slider.h>
#ifndef DIALOG_H
#define DIALOG_H
#endif 
//These are the unique identifiers that will be used to identify the wxControl within the wxWindow.....
const int c=29;
const int c1=30;
const int c2=31;
const int c3=32;
const int c4=33;
const int c5=39;
const int c6=40;
const int c7=41;
const int sp=34;
const int sp1=35;
const int crl=36; 
const int b1=37;
const int cp1=38;
//Type:Messagebus,
//Purpose:To display Message at a specified location(pt) with a particular size..
class MessageBus:public wxDialog{
    public:
    MessageBus(wxWindow* win,const wxString& title,const wxString& content,const wxPoint& pt,const wxSize& sz):wxDialog(win,wxID_ANY,title,pt,sz,wxDEFAULT_DIALOG_STYLE){
   CreateControls(content);
   Show(true);
   ShowModal();
   }
    void CreateControls(const wxString& str){
      wxStaticText* stext=new wxStaticText(this,wxID_ANY,str);
      wxButton* bton=new wxButton(this,wxID_OK,wxT("Ok"));
      wxButton* bton1=new wxButton(this,wxID_CANCEL,wxT("Cancel"));
      wxBoxSizer* bsizer=new wxBoxSizer(wxVERTICAL);
      wxBoxSizer* bsizer1=new wxBoxSizer(wxHORIZONTAL);
      SetSizer(bsizer);
      bsizer->Add(10,10,0,wxLEFT|wxALL,0);
      bsizer->Add(stext,0,wxLEFT|wxALL,10);
      bsizer->Add(bsizer1,0,wxRIGHT|wxALL,5);
      bsizer1->Add(bton,wxALIGN_CENTER_VERTICAL|wxALL,5);
      bsizer1->Add(bton1,0,wxALIGN_CENTER_VERTICAL|wxALL,5);
    }

};
class TextPosDialog:public wxDialog{
  private:
  wxTextAttr attr;
  int sptrlvalue;
  int sptrlvalue1;
  wxTextCtrl* tcrl;


  void SetTextAttr(const wxTextAttr& attr1 ){
    this->attr=attr1;
  }
  void SetSpinCtrlValue(const int& value){
    this->sptrlvalue=value;
  }
  void SetSpinCtrlValue1(const int& value){
    this->sptrlvalue1=value;
  }
  
  void OK(wxCommandEvent& evt){
    InitAllValue();
    EndModal(wxID_OK);
    return;
  }
  
  public:
  TextPosDialog(wxWindow* parent,const wxTextAttr& myattr,const int& a,const int& a0):wxDialog(parent,wxID_ANY,wxT("Text Alignment"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER){
     
     SetBackgroundColour(wxColour(240,240,240));
     CreateControls(myattr,a,a0);
     Show(true);
    ShowModal();
     this->Bind(wxEVT_BUTTON,&OK,this,wxID_OK);
  }
 void CreateControls(const wxTextAttr& attr,const int a,const int a0){
    wxStaticText* stext=new wxStaticText(this,wxID_ANY,wxT("Align Text"),wxDefaultPosition,wxDefaultSize);
    wxStaticText* stext1=new wxStaticText(this,wxID_ANY,wxT("Range of Text"),wxDefaultPosition,wxDefaultSize);
    wxStaticText* stext2=new wxStaticText(this,wxID_ANY,wxT("StartPos:"));
    wxStaticText* stext3=new wxStaticText(this,wxID_ANY,wxT("EndPos: "));
    wxStaticText* stext4=new wxStaticText(this,wxID_ANY,wxT("Preview:"));
    wxStaticLine* sline=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    wxStaticLine* sline1=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    wxStaticLine* sline2=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    wxCheckBox* cbox=new wxCheckBox(this,c,wxT("Align Left"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
    wxCheckBox* cbox1=new wxCheckBox(this,c1,wxT("Align right"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
    wxCheckBox* cbox2=new wxCheckBox(this,c2,wxT("Align Center"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
    wxCheckBox* cbox3=new wxCheckBox(this,c3,wxT("Align Justified"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE); 
    wxSpinCtrl* spctrl=new wxSpinCtrl(this,sp,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000,0);
    wxSpinCtrl* spctrl1=new wxSpinCtrl(this,sp1,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000,0);
    spctrl->SetValue(a);
    spctrl1->SetValue(a0);
    wxTextAttr textattr;
    textattr.SetAlignment(attr.GetAlignment());
    wxTextCtrl* textctrl=new wxTextCtrl;
    if(textattr.GetAlignment()==wxTEXT_ALIGNMENT_LEFT){
        textctrl->Create(this,c4,wxEmptyString,wxDefaultPosition,wxSize(300,100),wxTE_LEFT|wxTE_MULTILINE|wxHSCROLL);
    }
    else if(textattr.GetAlignment()==wxTEXT_ALIGNMENT_RIGHT){
        textctrl->Create(this,c4,wxEmptyString,wxDefaultPosition,wxSize(300,100),wxTE_RIGHT|wxTE_MULTILINE|wxHSCROLL);
    }
    else if(textattr.GetAlignment()==wxTEXT_ALIGNMENT_CENTER){
        textctrl->Create(this,c4,wxEmptyString,wxDefaultPosition,wxSize(300,100),wxTE_CENTER|wxTE_MULTILINE|wxHSCROLL);
    }
    else{
       textctrl->Create(this,c4,wxEmptyString,wxDefaultPosition,wxSize(300,100),wxTE_MULTILINE|wxHSCROLL);
    } 
    textctrl->AppendText(wxT("Grace Of God"));
    wxTextAttr txtattr;
    txtattr.SetAlignment(attr.GetAlignment());
    if(txtattr.GetAlignment()==wxTEXT_ALIGNMENT_LEFT){
      cbox->SetValue(true);
      cbox1->SetValue(false);
      cbox2->SetValue(false);
      cbox3->SetValue(false);
    }
    else if(txtattr.GetAlignment()==wxTEXT_ALIGNMENT_CENTER){
      cbox->SetValue(false);
      cbox1->SetValue(false);
      cbox2->SetValue(true);
      cbox3->SetValue(false);
    }
    else if(txtattr.GetAlignment()==wxTEXT_ALIGNMENT_RIGHT){
      cbox->SetValue(false);
      cbox1->SetValue(true);
      cbox2->SetValue(false);
      cbox3->SetValue(false);
    }
    else if(txtattr.GetAlignment()==wxTEXT_ALIGNMENT_JUSTIFIED){
      cbox->SetValue(false);
      cbox1->SetValue(false);
      cbox2->SetValue(false);
      cbox3->SetValue(true);
    }
    

    wxButton* bton= new wxButton(this,wxID_OK,wxT("&Ok"));
    wxBoxSizer* bsizer=new wxBoxSizer(wxVERTICAL);   
    SetSizer(bsizer);
    wxBoxSizer* bsizer1=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer2=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer3=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer4=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer5=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer6=new wxBoxSizer(wxHORIZONTAL);
    bsizer->Add(bsizer1,0,wxLEFT,5);
    bsizer1->Add(stext,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer1->Add(sline,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(10,10,0,wxALIGN_CENTER_HORIZONTAL|wxALL,0);
    bsizer->Add(bsizer2,0,wxLEFT,10);
    bsizer2->Add(cbox,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(20,20,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(cbox1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(10,10,0,wxALIGN_CENTER_HORIZONTAL|wxALL,0);
    bsizer->Add(bsizer3,0,wxLEFT,10);
    bsizer3->Add(cbox2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(20,20,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(cbox3,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,5);
    bsizer->Add(bsizer4,0,wxLEFT|wxALL,5);
    bsizer4->Add(stext1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer4->Add(sline1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(bsizer5,0,wxLEFT|wxALL,10);
    bsizer5->Add(stext2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer5->Add(spctrl,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer5->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer5->Add(stext3,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer5->Add(spctrl1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT,5);
    bsizer->Add(bsizer6,0,wxLEFT,5);
    bsizer6->Add(stext4,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer6->Add(sline2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT,0);
    bsizer->Add(textctrl,0,wxLEFT|wxALL,10);
    bsizer->Add(bton,0,wxRIGHT|wxALL,5);
    
}
wxTextAttr GetTextAttr() const{
   return attr;
}
int GetSpinCtrlValue() const {
   return sptrlvalue;
} 
 int GetSpinCtrlValue1() const {
    return sptrlvalue1;
 }
void InitAllValue(){
    wxCheckBox* cbox=(wxCheckBox*)FindWindow(c);
    wxCheckBox* cbox1=(wxCheckBox*)FindWindow(c1);
    wxCheckBox* cbox2=(wxCheckBox*)FindWindow(c2);
    wxCheckBox* cbox3=(wxCheckBox*)FindWindow(c3);
    wxSpinCtrl* spinctrl=(wxSpinCtrl*)FindWindow(sp);
    wxSpinCtrl* spinctrl1=(wxSpinCtrl*)FindWindow(sp1);
    wxTextCtrl* ctrl=(wxTextCtrl*)FindWindow(c4);
    if((cbox->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked())){
       attr.SetAlignment(wxTEXT_ALIGNMENT_LEFT);
       sptrlvalue=spinctrl->GetValue();
       sptrlvalue1=spinctrl1->GetValue();
       return;
    }
     if((cbox1->IsChecked()) && !(cbox->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked())){
       attr.SetAlignment(wxTEXT_ALIGNMENT_RIGHT);
       sptrlvalue=spinctrl->GetValue();
       sptrlvalue1=spinctrl1->GetValue();
       return;
    }
     if((cbox2->IsChecked()) && !(cbox1->IsChecked()) && !(cbox->IsChecked()) && !(cbox3->IsChecked())){
       attr.SetAlignment(wxTEXT_ALIGNMENT_CENTER);
       sptrlvalue=spinctrl->GetValue();
       sptrlvalue1=spinctrl1->GetValue();
       return;
    }
     if((cbox3->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox->IsChecked())){
       attr.SetAlignment(wxTEXT_ALIGNMENT_JUSTIFIED);
       sptrlvalue=spinctrl->GetValue();
       sptrlvalue1=spinctrl1->GetValue();
       return;
    }
}

};

class TextPosFontDialog: public wxDialog{
   private:
   wxTextAttr attr;
   int Sptrlvalue;
   int Sptrlvalue1;

   public:
    wxTextAttr GetTextAttr() const{
    return attr;
    }
    int GetSptrlvalue() const{
    return Sptrlvalue;
    }
    int GetSptrlvalue1() const{
    return Sptrlvalue1;
    }
   void OkPressed(wxCommandEvent& evt){
    InitAllValues();
    EndModal(wxID_OK);
    return;
   }
   
//Constructor For TextPosFontDialog
   TextPosFontDialog(wxWindow* parent,wxFontPickerCtrl* tcrl,const int& a,const int& a0):wxDialog(parent,wxID_ANY,wxT("Apply Positional Fonts"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER){
     
     SetBackgroundColour(wxColour(240,240,240));
     CreateControls(tcrl,a,a0);
     Show(true);
     ShowModal();
     Bind(wxEVT_BUTTON,&OkPressed,this,wxID_OK);
   }
   void CreateControls(wxFontPickerCtrl* font,const int& a,const int& a0){
    wxStaticText* stext=new wxStaticText(this,wxID_ANY,wxT("Apply Font attributes to range of position"));
    wxStaticText* stext0=new wxStaticText(this,wxID_ANY,wxT("Range of Text"));
    wxStaticText* stext1=new wxStaticText(this,wxID_ANY,wxT("StartPos:"));
    wxStaticText* stext2=new wxStaticText(this,wxID_ANY,wxT("EndPos:"));
    wxStaticText* stext3=new wxStaticText(this,wxID_ANY,wxT("Preview:"));
    wxStaticLine* sline=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    wxStaticLine* sline1=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    wxTextCtrl* tcrl=new wxTextCtrl(this,crl,wxEmptyString,wxDefaultPosition,wxSize(300,100),wxTE_MULTILINE|wxTE_RICH|wxHSCROLL);
    wxSpinCtrl* spctrl=new wxSpinCtrl(this,sp,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000000,0);
    wxSpinCtrl* spctrl1=new wxSpinCtrl(this,sp1,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000000,0);
    wxStaticText* st=new wxStaticText(this,wxID_ANY,wxT("Font Picker:"));
    wxFontPickerCtrl* button=new wxFontPickerCtrl(this,b1);
    wxButton* button1=new wxButton(this,wxID_OK,wxT("Ok"));
    spctrl->SetValue(a);
    spctrl1->SetValue(a0);
    wxTextAttr attr1;
    attr1.SetFont(font->GetSelectedFont());
    attr1.SetTextColour(font->GetSelectedColour());
    tcrl->SetDefaultStyle(attr1);
    button->SetSelectedFont(font->GetSelectedFont());
    button->SetSelectedColour(font->GetSelectedColour());
    wxBoxSizer* bsizer=new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* bsizer1=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer2=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer3=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer4=new wxBoxSizer(wxHORIZONTAL);
    SetSizer(bsizer);
    bsizer->Add(stext,0,wxLEFT|wxALL,10);
    bsizer->Add(10,10,0,wxLEFT,0);
    bsizer->Add(bsizer1,0,wxLEFT|wxALL,10);
    bsizer1->Add(stext0,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer1->Add(sline,0,wxALIGN_CENTER_VERTICAL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer2,0,wxLEFT,10);
    bsizer2->Add(stext1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(spctrl,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(stext2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(spctrl1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT,0);
    bsizer->Add(bsizer4,0,wxLEFT|wxALL,5);
    bsizer4->Add(st,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer4->Add(button,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(bsizer3,0,wxLEFT,5);
    bsizer3->Add(stext3,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(sline1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(tcrl,0,wxLEFT|wxALL,5);
    bsizer->Add(button1,0,wxRIGHT|wxALL,10);
    tcrl->AppendText(wxT("Grace Of God"));
    }
void InitAllValues(){
  wxSpinCtrl* sptrl=(wxSpinCtrl*)FindWindow(sp);
  wxSpinCtrl* sptrlone=(wxSpinCtrl*)FindWindow(sp1);
    Sptrlvalue=sptrl->GetValue();
  Sptrlvalue1=sptrlone->GetValue();
   wxFontPickerCtrl* fontpicker=(wxFontPickerCtrl*)FindWindow(b1);
      wxTextCtrl* tcrl=(wxTextCtrl*)FindWindow(crl);
      attr.SetFont(fontpicker->GetSelectedFont());
     attr.SetTextColour(fontpicker->GetSelectedColour());
     tcrl->SetDefaultStyle(attr);
  return;  
}
};
class TextUnderlinedDialog:public wxDialog{
private:
  int a2;
  int a3;
  wxTextAttr textattr;
  void Ok(wxCommandEvent& evt){
   InitAllValues(textattr);
   EndModal(wxID_OK);
  }
public:
  TextUnderlinedDialog(wxWindow*parent,const wxTextAttr& attr,const int& a,const int& a0):wxDialog(parent,wxID_ANY,wxT("Underline Style"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER){
   CreateControls(attr,a,a0);
   Show(true);
   ShowModal();
   Bind(wxEVT_BUTTON,&Ok,this,wxID_OK);
  }
  void CreateControls(const wxTextAttr& attr,const int& a,const int& a0){
   wxStaticText*stext=new wxStaticText(this,wxID_ANY,wxT("Apply Underline style to a range of position"));
   wxStaticText* stext1=new wxStaticText(this,wxID_ANY,wxT("Types of Underline Style"));
   wxStaticText* stext2=new wxStaticText(this,wxID_ANY,wxT("Range of Pos:"));
   wxStaticText* stext3=new wxStaticText(this,wxID_ANY,wxT("StartPos:"));
   wxStaticText* stext4=new wxStaticText(this,wxID_ANY,wxT("EndPos:"));
   wxStaticText* stext5=new wxStaticText(this,wxID_ANY,wxT("Preview:"));
   wxStaticText* stext6=new wxStaticText(this,wxID_ANY,wxT("Underline Colour:"));
   wxStaticLine* sline=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
   wxStaticLine* sline1=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
   wxStaticLine* sline2=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
   wxCheckBox* cbox=new wxCheckBox(this,c,wxT("Double"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
   wxCheckBox* cbox1=new wxCheckBox(this,c1,wxT("Solid"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
   wxCheckBox* cbox2=new wxCheckBox(this,c2,wxT("None"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
   wxCheckBox* cbox3=new wxCheckBox(this,c3,wxT("Special"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
   wxSpinCtrl* spctrl=new wxSpinCtrl(this,sp,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000000,0);
   wxSpinCtrl* spctrl1=new wxSpinCtrl(this,sp1,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000000,0);
   spctrl->SetValue(a);
   spctrl1->SetValue(a0);
    wxTextAttr tatrr;
   tatrr.SetFont(attr.GetFont());
   textattr.SetFont(attr.GetFont());
   tatrr.SetFontUnderlined(attr.GetUnderlineType(),attr.GetUnderlineColour());

    if(tatrr.GetUnderlineType()==wxTEXT_ATTR_UNDERLINE_DOUBLE){
      cbox->SetValue(true);
      cbox1->SetValue(false);
      cbox2->SetValue(false);
      cbox3->SetValue(false);
    }
    else if(tatrr.GetUnderlineType()==wxTEXT_ATTR_UNDERLINE_NONE){
      cbox->SetValue(false);
      cbox1->SetValue(false);
      cbox2->SetValue(true);
      cbox3->SetValue(false);
    }
    else if(tatrr.GetUnderlineType()==wxTEXT_ATTR_UNDERLINE_SOLID){
      cbox->SetValue(false);
      cbox1->SetValue(true);
      cbox2->SetValue(false);
      cbox3->SetValue(false);
    }
    else if(tatrr.GetUnderlineType()==wxTEXT_ATTR_UNDERLINE_SPECIAL){
      cbox->SetValue(false);
      cbox1->SetValue(false);
      cbox2->SetValue(false);
      cbox3->SetValue(true);
    }
   wxTextCtrl* tcrl=new wxTextCtrl(this,crl,wxEmptyString,wxDefaultPosition,wxSize(300,100),wxTE_MULTILINE|wxTE_RICH|wxHSCROLL);
   wxColourPickerCtrl* cptrl=new wxColourPickerCtrl(this,cp1);
   tcrl->SetDefaultStyle(tatrr);

   tcrl->AppendText(wxT("Glory To God For Grace"));
   wxButton* bton=new wxButton(this,wxID_OK,wxT("Ok"));

   cptrl->SetColour(tatrr.GetUnderlineColour());
   wxBoxSizer* bsizer=new wxBoxSizer(wxVERTICAL);
   wxBoxSizer* bsizer1=new wxBoxSizer(wxHORIZONTAL);
   wxBoxSizer* bsizer2=new wxBoxSizer(wxHORIZONTAL);
   wxBoxSizer* bsizer3=new wxBoxSizer(wxHORIZONTAL);
   wxBoxSizer* bsizer4=new wxBoxSizer(wxHORIZONTAL);
   wxBoxSizer* bsizer5=new wxBoxSizer(wxHORIZONTAL);
   wxBoxSizer* bsizer6=new wxBoxSizer(wxHORIZONTAL);
   wxBoxSizer* bsizer7=new wxBoxSizer(wxHORIZONTAL);
   SetSizer(bsizer);
   bsizer->Add(stext,0,wxLEFT|wxALL,10);
   bsizer->Add(bsizer1,0,wxLEFT|wxALL,10);
   bsizer1->Add(stext1,0,wxALIGN_CENTER_VERTICAL|wxALL,5);
   bsizer1->Add(sline,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer->Add(10,10,0,wxLEFT|wxALL,0);
   bsizer->Add(bsizer2,0,wxLEFT|wxALL,10);
   bsizer2->Add(cbox,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer2->Add(10,10,0,wxALIGN_CENTER_VERTICAL,10);
   bsizer2->Add(cbox1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer->Add(5,5,0,wxLEFT|wxALL,0);
   bsizer->Add(bsizer3,0,wxLEFT|wxALL,10);
   bsizer3->Add(cbox2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer3->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,10);
   bsizer3->Add(cbox3,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer->Add(bsizer4,0,wxLEFT|wxALL,5);
   bsizer4->Add(stext6,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer4->Add(cptrl,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer->Add(bsizer5,0,wxLEFT|wxALL,5);
   bsizer5->Add(stext2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer5->Add(sline1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer->Add(10,10,0,wxLEFT|wxALL,0);
   bsizer->Add(bsizer6,0,wxLEFT|wxALL,10);
   bsizer6->Add(stext3,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer6->Add(spctrl,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer6->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer6->Add(stext4,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer6->Add(spctrl1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer->Add(bsizer7,0,wxLEFT,5);
   bsizer7->Add(stext5,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer7->Add(sline2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
   bsizer->Add(tcrl,0,wxLEFT|wxALL,5);
   bsizer->Add(10,10,0,wxLEFT|wxALL,0);
   bsizer->Add(bton,0,wxLEFT|wxALL,5);
   
   return;
  }
  int GetOne() const{
   return a2;
  }
  int Gettwo() const{
   return a3;
  }
  wxTextAttr GetCurrentTextAttr() const{
   return textattr;
  }
  
   void InitAllValues(const wxTextAttr& att){
    wxCheckBox* cbox=(wxCheckBox*)FindWindow(c);
    wxCheckBox* cbox1=(wxCheckBox*)FindWindow(c1);
    wxCheckBox* cbox2=(wxCheckBox*)FindWindow(c2);
    wxCheckBox* cbox3=(wxCheckBox*)FindWindow(c3);
    wxSpinCtrl* spinctrl=(wxSpinCtrl*)FindWindow(sp);
    wxSpinCtrl* spinctrl1=(wxSpinCtrl*)FindWindow(sp1);
    wxColourPickerCtrl* ctrl=(wxColourPickerCtrl*)FindWindow(cp1);
    if((cbox->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked())){
      textattr.SetFont(att.GetFont());
      textattr.SetFontUnderlined(wxTEXT_ATTR_UNDERLINE_DOUBLE,ctrl->GetColour());
       a2=spinctrl->GetValue();
       a3=spinctrl1->GetValue();
       return;
    }
     if((cbox1->IsChecked()) && !(cbox->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked())){
       textattr.SetFont(att.GetFont());
       textattr.SetFontUnderlined(wxTEXT_ATTR_UNDERLINE_SOLID,ctrl->GetColour());
       a2=spinctrl->GetValue();
       a3=spinctrl1->GetValue();
       return;
    }
     if((cbox2->IsChecked()) && !(cbox1->IsChecked()) && !(cbox->IsChecked()) && !(cbox3->IsChecked())){
       textattr.SetFont(att.GetFont());
       textattr.SetFontUnderlined(wxTEXT_ATTR_UNDERLINE_NONE,ctrl->GetColour());
       a2=spinctrl->GetValue();
       a3=spinctrl1->GetValue();
       return;
    }
     if((cbox3->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox->IsChecked())){
       textattr.SetFont(att.GetFont());
       textattr.SetFontUnderlined(wxTEXT_ATTR_UNDERLINE_SPECIAL,ctrl->GetColour());
       a2=spinctrl->GetValue();
       a3=spinctrl1->GetValue();
       return;
    }
}

};
class TextBulletStyleDialog:public wxDialog{
  private:
  int a1;
  int a2;
  wxTextAttr myattr;
  void Ok(wxCommandEvent& evt){
    InitAllValues(myattr);
    EndModal(wxID_OK);
  }
   public:
  TextBulletStyleDialog(wxWindow* win,const wxTextAttr& attr,const int& a,const int& a0):wxDialog(win,wxID_ANY,wxT("Apply Bullet Style"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER){
      CreateControls(attr,a,a0);
      Show(true);
      ShowModal();
     Bind(wxEVT_BUTTON,&Ok,this,wxID_OK);
  
  }
  int GetOne() const{
    return a1;
  }
   int GetTwo() const{
   return a2;
   }
   wxTextAttr GetCurrentTextAttr() const{
    return myattr;
   }
   
   
   
   void CreateControls(const wxTextAttr& attr,const int& a,const int& b){
      wxStaticText* stext=new wxStaticText(this,wxID_ANY,wxT("Apply Bullet Style to a range of text"));
      wxStaticText* stext1=new wxStaticText(this,wxID_ANY,wxT("Text Effect Style:"));
      wxStaticText* stext2=new wxStaticText(this,wxID_ANY,wxT("Range of Text:"));
      wxStaticText* stext3=new wxStaticText(this,wxID_ANY,wxT("Preview:"));
      wxStaticText* stext4=new wxStaticText(this,wxID_ANY,wxT("StartPos:"));
      wxStaticText* stext5=new wxStaticText(this,wxID_ANY,wxT("EndPos:"));
      wxStaticLine* sline=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
      wxStaticLine* sline1=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
      wxStaticLine* sline2=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
      wxCheckBox* cbox=new wxCheckBox(this,c,wxT("Arabic"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
      wxCheckBox* cbox1=new wxCheckBox(this,c1,wxT("UpperLetters(A..Z)"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
      wxCheckBox* cbox2=new wxCheckBox(this,c2,wxT("LowerLetters(a..z)"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
      wxCheckBox* cbox3=new wxCheckBox(this,c3,wxT("RomanUpper"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
      wxCheckBox* cbox4=new wxCheckBox(this,c4,wxT("RomanLower"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
      wxCheckBox* cbox5=new wxCheckBox(this,c5,wxT("Symbol"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
      wxCheckBox* cbox6=new wxCheckBox(this,c6,wxT("Right Parenthesis"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
      wxCheckBox* cbox7=new wxCheckBox(this,c7,wxT("Period"),wxDefaultPosition,wxDefaultSize,wxCHK_2STATE);
      wxSpinCtrl* spctrl=new wxSpinCtrl(this,sp,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000000,0);
      wxSpinCtrl* spctrl1=new wxSpinCtrl(this,sp1,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000000,0);
      spctrl->SetValue(a);
      spctrl1->SetValue(b);
      wxTextAttr textattr;
      myattr.SetFont(attr.GetFont());
      textattr.SetFont(attr.GetFont());
      textattr.SetBulletStyle(attr.GetBulletStyle());
     if(textattr.GetBulletStyle()==wxTEXT_ATTR_BULLET_STYLE_ARABIC){
        cbox->SetValue(true);
        cbox1->SetValue(false);
        cbox2->SetValue(false);
        cbox3->SetValue(false);
        cbox4->SetValue(false);
        cbox5->SetValue(false);
        cbox6->SetValue(false);
        cbox7->SetValue(false);
      }
     else if(textattr.GetBulletStyle()==(wxTEXT_ATTR_BULLET_STYLE_ARABIC|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS)){
        cbox->SetValue(true);
        cbox1->SetValue(false);
        cbox2->SetValue(false);
        cbox3->SetValue(false);
        cbox4->SetValue(false);
        cbox5->SetValue(false);
        cbox6->SetValue(true);
        cbox7->SetValue(false);
      }
      else if(textattr.GetBulletStyle()==(wxTEXT_ATTR_BULLET_STYLE_ARABIC|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS|wxTEXT_ATTR_BULLET_STYLE_PERIOD)){
        cbox->SetValue(true);
        cbox1->SetValue(false);
        cbox2->SetValue(false);
        cbox3->SetValue(false);
        cbox4->SetValue(false);
        cbox5->SetValue(false);
        cbox6->SetValue(true);
        cbox7->SetValue(true);
      }
     else if(textattr.GetBulletStyle()==wxTEXT_ATTR_BULLET_STYLE_LETTERS_UPPER){
        cbox->SetValue(false);
        cbox1->SetValue(true);
        cbox2->SetValue(false);
        cbox3->SetValue(false);
        cbox4->SetValue(false);
        cbox5->SetValue(false);
        cbox6->SetValue(false);
        cbox7->SetValue(false);
      }
      else if(textattr.GetBulletStyle()==(wxTEXT_ATTR_BULLET_STYLE_LETTERS_UPPER|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS)){
        cbox->SetValue(false);
        cbox1->SetValue(true);
        cbox2->SetValue(false);
        cbox3->SetValue(false);
        cbox4->SetValue(false);
        cbox5->SetValue(false);
        cbox6->SetValue(true);
        cbox7->SetValue(false);
      }
      else if(textattr.GetBulletStyle()==(wxTEXT_ATTR_BULLET_STYLE_LETTERS_UPPER|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS|wxTEXT_ATTR_BULLET_STYLE_PERIOD)){
        cbox->SetValue(false);
        cbox1->SetValue(true);
        cbox2->SetValue(false);
        cbox3->SetValue(false);
        cbox4->SetValue(false);
        cbox5->SetValue(false);
        cbox6->SetValue(true);
        cbox7->SetValue(true);
      }
      else if(textattr.GetBulletStyle()==wxTEXT_ATTR_BULLET_STYLE_LETTERS_LOWER){
        cbox->SetValue(false);
        cbox1->SetValue(false);
        cbox2->SetValue(true);
        cbox3->SetValue(false);
        cbox4->SetValue(false);
        cbox5->SetValue(false);
        cbox6->SetValue(false);
        cbox7->SetValue(false);
      }
       else if(textattr.GetBulletStyle()==(wxTEXT_ATTR_BULLET_STYLE_LETTERS_LOWER|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS)){
        cbox->SetValue(false);
        cbox1->SetValue(false);
        cbox2->SetValue(true);
        cbox3->SetValue(false);
        cbox4->SetValue(false);
        cbox5->SetValue(false);
        cbox6->SetValue(true);
        cbox7->SetValue(false);
      }
      else if(textattr.GetBulletStyle()==(wxTEXT_ATTR_BULLET_STYLE_LETTERS_LOWER|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS|wxTEXT_ATTR_BULLET_STYLE_PERIOD)){
        cbox->SetValue(false);
        cbox1->SetValue(false);
        cbox2->SetValue(true);
        cbox3->SetValue(false);
        cbox4->SetValue(false);
        cbox5->SetValue(false);
        cbox6->SetValue(true);
        cbox7->SetValue(true);
      }
      else if(textattr.GetBulletStyle()==wxTEXT_ATTR_BULLET_STYLE_ROMAN_UPPER){
        cbox->SetValue(false);
        cbox1->SetValue(false);
        cbox2->SetValue(false);
        cbox3->SetValue(true);
        cbox4->SetValue(false);
        cbox5->SetValue(false);
        cbox6->SetValue(false);
        cbox7->SetValue(false);
      }
      else if(textattr.GetBulletStyle()==(wxTEXT_ATTR_BULLET_STYLE_ROMAN_UPPER|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS)){
        cbox->SetValue(false);
        cbox1->SetValue(false);
        cbox2->SetValue(false);
        cbox3->SetValue(true);
        cbox4->SetValue(false);
        cbox5->SetValue(false);
        cbox6->SetValue(true);
        cbox7->SetValue(false);
      }
       else if(textattr.GetBulletStyle()==(wxTEXT_ATTR_BULLET_STYLE_ROMAN_UPPER|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS|wxTEXT_ATTR_BULLET_STYLE_PERIOD)){
        cbox->SetValue(false);
        cbox1->SetValue(false);
        cbox2->SetValue(false);
        cbox3->SetValue(true);
        cbox4->SetValue(false);
        cbox5->SetValue(false);
        cbox6->SetValue(true);
        cbox7->SetValue(true);
      }
      else if(textattr.GetBulletStyle()==wxTEXT_ATTR_BULLET_STYLE_ROMAN_LOWER){
        cbox->SetValue(false);
        cbox1->SetValue(false);
        cbox2->SetValue(false);
        cbox3->SetValue(false);
        cbox4->SetValue(true);
        cbox5->SetValue(false);
        cbox6->SetValue(false);
        cbox7->SetValue(false);
      }
      else if(textattr.GetBulletStyle()==(wxTEXT_ATTR_BULLET_STYLE_ROMAN_LOWER|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS)){
        cbox->SetValue(false);
        cbox1->SetValue(false);
        cbox2->SetValue(false);
        cbox3->SetValue(false);
        cbox4->SetValue(true);
        cbox5->SetValue(false);
        cbox6->SetValue(true);
        cbox7->SetValue(false);
      }
      else if(textattr.GetBulletStyle()==(wxTEXT_ATTR_BULLET_STYLE_ROMAN_LOWER|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS|wxTEXT_ATTR_BULLET_STYLE_PERIOD)){
        cbox->SetValue(false);
        cbox1->SetValue(false);
        cbox2->SetValue(false);
        cbox3->SetValue(false);
        cbox4->SetValue(true);
        cbox5->SetValue(false);
        cbox6->SetValue(true);
        cbox7->SetValue(true);
      }
      else if(textattr.GetBulletStyle()==wxTEXT_ATTR_BULLET_STYLE_SYMBOL){
        cbox->SetValue(false);
        cbox1->SetValue(false);
        cbox2->SetValue(false);
        cbox3->SetValue(false);
        cbox4->SetValue(false);
        cbox5->SetValue(true);
        cbox6->SetValue(false);
        cbox7->SetValue(false);
      }
     else if(textattr.GetBulletStyle()==(wxTEXT_ATTR_BULLET_STYLE_SYMBOL|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS)){
        cbox->SetValue(false);
        cbox1->SetValue(false);
        cbox2->SetValue(false);
        cbox3->SetValue(false);
        cbox4->SetValue(false);
        cbox5->SetValue(true);
        cbox6->SetValue(true);
        cbox7->SetValue(false);
      }
      else if(textattr.GetBulletStyle()==(wxTEXT_ATTR_BULLET_STYLE_SYMBOL|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS|wxTEXT_ATTR_BULLET_STYLE_PERIOD)){
        cbox->SetValue(false);
        cbox1->SetValue(false);
        cbox2->SetValue(false);
        cbox3->SetValue(false);
        cbox4->SetValue(false);
        cbox5->SetValue(true);
        cbox6->SetValue(true);
        cbox7->SetValue(true);
      }


    wxTextCtrl* tcrl=new wxTextCtrl(this,crl,wxEmptyString,wxDefaultPosition,wxSize(300,100),wxTE_MULTILINE|wxTE_RICH|wxHSCROLL);
    tcrl->SetDefaultStyle(textattr);
    tcrl->AppendText(wxT("Grace Of God"));
    tcrl->SetStyle(0,13,textattr);
    wxButton* bton=new wxButton(this,wxID_OK,wxT("OK"));
    wxBoxSizer* bsizer=new wxBoxSizer(wxVERTICAL);   
    SetSizer(bsizer);
    wxBoxSizer* bsizer1=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer2=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer3=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer4=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer5=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer6=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer7=new wxBoxSizer(wxHORIZONTAL);
    bsizer->Add(stext,0,wxLEFT|wxALL,10);
    bsizer->Add(5,5,0,wxLEFT|wxALL,5);
    bsizer->Add(bsizer1,0,wxLEFT|wxALL,5);
    bsizer1->Add(stext1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer1->Add(sline,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer2,0,wxLEFT|wxALL,10);
    bsizer2->Add(cbox,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,10);
    bsizer2->Add(cbox1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(cbox2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer3,0,wxLEFT|wxALL,10);
    bsizer3->Add(cbox3,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,10);
    bsizer3->Add(cbox4,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(cbox5,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer7,0,wxLEFT|wxALL,10);
    bsizer7->Add(cbox6,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer7->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer7->Add(cbox7,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer4,0,wxLEFT|wxALL,5);
    bsizer4->Add(stext2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer4->Add(sline1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer5,0,wxLEFT|wxALL,10);
    bsizer5->Add(stext4,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer5->Add(spctrl,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer5->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer5->Add(stext5,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer5->Add(spctrl1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer6,0,wxLEFT|wxALL,5);
    bsizer6->Add(stext3,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer6->Add(sline2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(tcrl,0,wxLEFT|wxALL,5);
    bsizer->Add(bton,0,wxLEFT|wxALL,10);   
}
  void InitAllValues(const wxTextAttr& att){
    wxCheckBox* cbox=(wxCheckBox*)FindWindow(c);
    wxCheckBox* cbox1=(wxCheckBox*)FindWindow(c1);
    wxCheckBox* cbox2=(wxCheckBox*)FindWindow(c2);
    wxCheckBox* cbox3=(wxCheckBox*)FindWindow(c3);
    wxCheckBox* cbox4=(wxCheckBox*)FindWindow(c4);
    wxCheckBox* cbox5=(wxCheckBox*)FindWindow(c5);
    wxCheckBox* cbox6=(wxCheckBox*)FindWindow(c6);
    wxCheckBox* cbox7=(wxCheckBox*)FindWindow(c7);
    wxSpinCtrl* spinctrl=(wxSpinCtrl*)FindWindow(sp);
    wxSpinCtrl* spinctrl1=(wxSpinCtrl*)FindWindow(sp1);
    if((cbox->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked()) && !(cbox4->IsChecked()) && !(cbox5->IsChecked()) && !(cbox6->IsChecked()) && !(cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ARABIC);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }
  if((cbox->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked()) && !(cbox4->IsChecked()) && !(cbox5->IsChecked()) && (cbox6->IsChecked()) && !(cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ARABIC|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }

 if((cbox->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked()) && !(cbox4->IsChecked()) && !(cbox5->IsChecked()) && (cbox6->IsChecked()) && (cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ARABIC|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS|wxTEXT_ATTR_BULLET_STYLE_PERIOD);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }
   if(!(cbox->IsChecked()) && (cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked()) && !(cbox4->IsChecked()) && !(cbox5->IsChecked()) && !(cbox6->IsChecked()) && !(cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_LETTERS_UPPER);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }
    if(!(cbox->IsChecked()) && (cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked()) && !(cbox4->IsChecked()) && !(cbox5->IsChecked()) && (cbox6->IsChecked()) && !(cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_LETTERS_UPPER|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }
   if(!(cbox->IsChecked()) && (cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked()) && !(cbox4->IsChecked()) && !(cbox5->IsChecked()) && (cbox6->IsChecked()) && (cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_LETTERS_UPPER|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS|wxTEXT_ATTR_BULLET_STYLE_PERIOD);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }
  if(!(cbox->IsChecked()) && !(cbox1->IsChecked()) && (cbox2->IsChecked()) && !(cbox3->IsChecked()) && !(cbox4->IsChecked()) && !(cbox5->IsChecked()) && !(cbox6->IsChecked()) && !(cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_LETTERS_LOWER);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }
   if(!(cbox->IsChecked()) && !(cbox1->IsChecked()) && (cbox2->IsChecked()) && !(cbox3->IsChecked()) && !(cbox4->IsChecked()) && !(cbox5->IsChecked()) && (cbox6->IsChecked()) && !(cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_LETTERS_LOWER|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }
    if(!(cbox->IsChecked()) && !(cbox1->IsChecked()) && (cbox2->IsChecked()) && !(cbox3->IsChecked()) && !(cbox4->IsChecked()) && !(cbox5->IsChecked()) && (cbox6->IsChecked()) && (cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_LETTERS_LOWER|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS|wxTEXT_ATTR_BULLET_STYLE_PERIOD);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }
    if(!(cbox->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && (cbox3->IsChecked()) && !(cbox4->IsChecked()) && !(cbox5->IsChecked()) && !(cbox6->IsChecked()) && !(cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ROMAN_UPPER);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }
     if(!(cbox->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && (cbox3->IsChecked()) && !(cbox4->IsChecked()) && !(cbox5->IsChecked()) && (cbox6->IsChecked()) && !(cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ROMAN_UPPER|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }
   if(!(cbox->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && (cbox3->IsChecked()) && !(cbox4->IsChecked()) && !(cbox5->IsChecked()) && (cbox6->IsChecked()) && (cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ROMAN_UPPER|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS|wxTEXT_ATTR_BULLET_STYLE_PERIOD);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }
     if(!(cbox->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked()) && (cbox4->IsChecked()) && !(cbox5->IsChecked()) && !(cbox6->IsChecked()) && !(cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ROMAN_LOWER);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }   
    if(!(cbox->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked()) && (cbox4->IsChecked()) && !(cbox5->IsChecked()) && (cbox6->IsChecked()) && !(cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ROMAN_LOWER|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }
  if(!(cbox->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked()) && (cbox4->IsChecked()) && !(cbox5->IsChecked()) && (cbox6->IsChecked()) && (cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ROMAN_LOWER|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS|wxTEXT_ATTR_BULLET_STYLE_PERIOD);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }
    if(!(cbox->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked()) && !(cbox4->IsChecked()) && (cbox5->IsChecked()) && !(cbox6->IsChecked()) && !(cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_SYMBOL);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }
  if(!(cbox->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked()) && !(cbox4->IsChecked()) && (cbox5->IsChecked()) && (cbox6->IsChecked()) && !(cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_SYMBOL|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }
   if(!(cbox->IsChecked()) && !(cbox1->IsChecked()) && !(cbox2->IsChecked()) && !(cbox3->IsChecked()) && !(cbox4->IsChecked()) && (cbox5->IsChecked()) && (cbox6->IsChecked()) && (cbox7->IsChecked())){
      myattr.SetFont(att.GetFont());
      myattr.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ROMAN_LOWER|wxTEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS|wxTEXT_ATTR_BULLET_STYLE_PERIOD);
       a1=spinctrl->GetValue();
       a2=spinctrl1->GetValue();
       return;
  }
   
  }
};
class LineSpacingDialog:public wxDialog{
  private:
  int currentvalue;
  int firstvalue;
  int secondvalue;
  public:
  int GetCurrentValue() const{
    return currentvalue;
  }
  int GetFirstValue() const{
    return firstvalue;
  }
  int GetSecondValue() const{
    return secondvalue;
  }
  void Ok(wxCommandEvent& evt){
    InitAllValues();
    EndModal(wxID_OK);
    return;
  }
  LineSpacingDialog(wxWindow* parent,const int& a0,const int& first,const int& second):wxDialog(parent,wxID_ANY,wxT("Line Spacing"),wxPoint(400,200),wxDefaultSize,wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER){
     CreateControls(a0,first,second);
     Show();
     ShowModal();
     Bind(wxEVT_BUTTON,&Ok,this,wxID_OK);
  }
  void CreateControls(const int a0,const int& first,const int& second){
    wxStaticText* stext=new wxStaticText(this,wxID_ANY,wxT("Specify The Spacing value"));
    wxStaticText* stext1=new wxStaticText(this,wxID_ANY,wxT("Spacing value"));
    wxStaticText* stext2=new wxStaticText(this,wxID_ANY,wxT("Range of values"));
    wxStaticText* stext3=new wxStaticText(this,wxID_ANY,wxT("StartPos:"));
    wxStaticText* stext4=new wxStaticText(this,wxID_ANY,wxT("EndPos:"));
    wxSpinCtrl* spinctrl=new wxSpinCtrl(this,sp,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000);
    wxSpinCtrl* spinctrl1=new wxSpinCtrl(this,sp1,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000);
    wxStaticLine* sline=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    wxStaticLine* sline1=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    spinctrl->SetValue(first);  //Setting the initial value at object creation..
    spinctrl1->SetValue(second);  //Setting the initial value at object creation....
    wxSlider* slider=new wxSlider(this,c,0,0,50,wxDefaultPosition,wxSize(300,-1),wxSL_AUTOTICKS|wxSL_HORIZONTAL|wxSL_LABELS);
    slider->SetValue(a0);
    wxButton*bton=new wxButton(this,wxID_OK,wxT("Ok"));
    wxButton* bton1=new wxButton(this,wxID_CANCEL,wxT("Cancel"));
    wxBoxSizer* bsizer=new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* bsizer1=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer2=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer3=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer4=new wxBoxSizer(wxHORIZONTAL);
    SetSizer(bsizer);
    bsizer->Add(stext,0,wxLEFT|wxALL,10);
    bsizer->Add(bsizer1,0,wxLEFT|wxALL,5);
    bsizer1->Add(stext1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer1->Add(sline,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(slider,0,wxLEFT|wxALL,10);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer2,0,wxLEFT|wxALL,5);
    bsizer2->Add(stext2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(sline1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(bsizer3,0,wxLEFT|wxALL,10);
    bsizer3->Add(stext3,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(spinctrl,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(stext4,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(spinctrl1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer4,0,wxLEFT|wxALL,5);
    bsizer4->Add(bton,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer4->Add(bton1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);


  }
  void InitAllValues(){
  wxSpinCtrl* sptrl=(wxSpinCtrl*)FindWindow(sp);
  wxSpinCtrl* sptrl1=(wxSpinCtrl*)FindWindow(sp1);
  wxSlider* slider=(wxSlider*)FindWindow(c);
  currentvalue=slider->GetValue();
  firstvalue=sptrl->GetValue();
  secondvalue=sptrl1->GetValue(); 
  return;
  }
};
class RightIndentDialog:public wxDialog{
  private:
  
  void ChangeSliderValue(wxScrollEvent& evt){
     wxTextCtrl* textctrl=(wxTextCtrl*)FindWindow(crl);
    *textctrl<<evt.GetPosition();
    return;
  }
  void Ok(wxCommandEvent& evt){
    InitAllValues();
    EndModal(wxID_OK);
    return;
  }
  int currentvalue;
  int start;
  int end;
  public:
  
  RightIndentDialog(wxWindow* win,const int& a0,const int& a1,const  int a2):wxDialog(win,wxID_ANY,wxT("RightIndentDialog"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER){
     CreateControls(a0,a1,a2);
     Show(true);
     ShowModal();
     Bind(wxEVT_BUTTON,&Ok,this,wxID_OK);
    Bind(wxEVT_SCROLL_THUMBTRACK,&ChangeSliderValue,this,c);
  }
  void CreateControls(const int a0,const int& first,const int& second){
    wxStaticText* stext=new wxStaticText(this,wxID_ANY,wxT("Specify The RightIndent value"));
    wxStaticText* stext1=new wxStaticText(this,wxID_ANY,wxT("Right Indentation  value"));
    wxStaticText* stext2=new wxStaticText(this,wxID_ANY,wxT("Range of values"));
    wxStaticText* stext3=new wxStaticText(this,wxID_ANY,wxT("StartPos:"));
    wxStaticText* stext4=new wxStaticText(this,wxID_ANY,wxT("EndPos:"));
    wxStaticText* stext5=new wxStaticText(this,wxID_ANY,wxT("Indent current value:"));
    wxSpinCtrl* spinctrl=new wxSpinCtrl(this,sp,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000);
    wxSpinCtrl* spinctrl1=new wxSpinCtrl(this,sp1,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000);
    wxStaticLine* sline=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    wxStaticLine* sline1=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    spinctrl->SetValue(first);  //Setting the initial value at object creation..
    spinctrl1->SetValue(second);  //Setting the initial value at object creation....
    wxSlider* slider=new wxSlider(this,c,0,0,100,wxDefaultPosition,wxSize(400,-1),wxSL_AUTOTICKS|wxSL_HORIZONTAL);
    wxTextCtrl* textctrl=new wxTextCtrl(this,crl,wxEmptyString,wxDefaultPosition,wxSize(50,20));
    slider->SetValue(a0);
    *textctrl<<slider->GetValue();
    wxButton*bton=new wxButton(this,wxID_OK,wxT("Ok"));
    wxButton* bton1=new wxButton(this,wxID_CANCEL,wxT("Cancel"));
    wxBoxSizer* bsizer=new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* bsizer1=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer2=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer3=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer4=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer5=new wxBoxSizer(wxHORIZONTAL);
    SetSizer(bsizer);
    bsizer->Add(stext,0,wxLEFT|wxALL,10);
    bsizer->Add(bsizer1,0,wxLEFT|wxALL,5);
    bsizer1->Add(stext1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer1->Add(sline,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(slider,0,wxLEFT|wxALL,10);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer5,0,wxLEFT|wxALL,5);
    bsizer5->Add(stext5,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer5->Add(textctrl,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer2,0,wxLEFT|wxALL,5);
    bsizer2->Add(stext2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(sline1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(bsizer3,0,wxLEFT|wxALL,10);
    bsizer3->Add(stext3,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(spinctrl,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(stext4,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(spinctrl1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer4,0,wxLEFT|wxALL,5);
    bsizer4->Add(bton,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer4->Add(bton1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);


  }
int GetCurrentValue(){ //Get current value.
  return currentvalue;
}
int GetStartValue(){    //Get start value
  return start;
}
int GetEndValue(){
  return end;
}
void InitAllValues(){
  wxSpinCtrl* sptrl=(wxSpinCtrl*)FindWindow(sp);
  wxSpinCtrl* sptrl1=(wxSpinCtrl*)FindWindow(sp1);
  wxSlider* slider=(wxSlider*)FindWindow(c);
  currentvalue=slider->GetValue();
  start=sptrl->GetValue();
  end=sptrl1->GetValue();
  wxTextCtrl* textctrl=(wxTextCtrl*)FindWindow(crl);
  *textctrl<<currentvalue;
}
    
};
class LeftIndentDialog:public wxDialog{
  private:
  void ChangeSliderValue(wxScrollEvent& evt){
     wxTextCtrl* textctrl=(wxTextCtrl*)FindWindow(crl);
    *textctrl<<evt.GetPosition();
    return;
  }
  void Ok(wxCommandEvent& evt){
    InitAllValues();
    EndModal(wxID_OK);
    return;
  }
  int currentvalue;
  int start;
  int end;
  public:
  
  LeftIndentDialog(wxWindow* win,const int& a0,const int& a1,const  int a2):wxDialog(win,wxID_ANY,wxT("LeftIndentDialog"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER){
     CreateControls(a0,a1,a2);
     Show(true);
     ShowModal();
     Bind(wxEVT_SCROLL_THUMBTRACK,&ChangeSliderValue,this,c);
     Bind(wxEVT_BUTTON,&Ok,this,wxID_OK);
  }
  void CreateControls(const int a0,const int& first,const int& second){
    wxStaticText* stext=new wxStaticText(this,wxID_ANY,wxT("Specify The LeftIndent value"));
    wxStaticText* stext1=new wxStaticText(this,wxID_ANY,wxT("Left Indentation  value"));
    wxStaticText* stext2=new wxStaticText(this,wxID_ANY,wxT("Range of values"));
    wxStaticText* stext3=new wxStaticText(this,wxID_ANY,wxT("StartPos:"));
    wxStaticText* stext4=new wxStaticText(this,wxID_ANY,wxT("EndPos:"));
    wxStaticText* stext5=new wxStaticText(this,wxID_ANY,wxT("Indent current value:"));
    wxSpinCtrl* spinctrl=new wxSpinCtrl(this,sp,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000);
    wxSpinCtrl* spinctrl1=new wxSpinCtrl(this,sp1,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS,-1,1000000);
    wxStaticLine* sline=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    wxStaticLine* sline1=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    spinctrl->SetValue(first);  //Setting the initial value at object creation..
    spinctrl1->SetValue(second);  //Setting the initial value at object creation....
    wxSlider* slider=new wxSlider(this,c,0,0,100,wxDefaultPosition,wxSize(400,-1),wxSL_AUTOTICKS|wxSL_HORIZONTAL);
    wxTextCtrl* textctrl=new wxTextCtrl(this,crl,wxEmptyString,wxDefaultPosition,wxSize(50,20));
    slider->SetValue(a0);
    *textctrl<<slider->GetValue();
    wxButton*bton=new wxButton(this,wxID_OK,wxT("Ok"));
    wxButton* bton1=new wxButton(this,wxID_CANCEL,wxT("Cancel"));
    wxBoxSizer* bsizer=new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* bsizer1=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer2=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer3=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer4=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer5=new wxBoxSizer(wxHORIZONTAL);
    SetSizer(bsizer);
    bsizer->Add(stext,0,wxLEFT|wxALL,10);
    bsizer->Add(bsizer1,0,wxLEFT|wxALL,5);
    bsizer1->Add(stext1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer1->Add(sline,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(slider,0,wxLEFT|wxALL,10);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer5,0,wxLEFT|wxALL,5);
    bsizer5->Add(stext5,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer5->Add(textctrl,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer2,0,wxLEFT|wxALL,5);
    bsizer2->Add(stext2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(sline1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(bsizer3,0,wxLEFT|wxALL,10);
    bsizer3->Add(stext3,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(spinctrl,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(stext4,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(spinctrl1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer4,0,wxLEFT|wxALL,5);
    bsizer4->Add(bton,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer4->Add(bton1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);


  }
int GetCurrentValue(){ //Get current value.
  return currentvalue;
}
int GetStartValue(){    //Get start value
  return start;
}
int GetEndValue(){
  return end;
}
void InitAllValues(){
  wxSpinCtrl* sptrl=(wxSpinCtrl*)FindWindow(sp);
  wxSpinCtrl* sptrl1=(wxSpinCtrl*)FindWindow(sp1);
  wxSlider* slider=(wxSlider*)FindWindow(c);
  currentvalue=slider->GetValue();
  start=sptrl->GetValue();
  end=sptrl1->GetValue();
  wxTextCtrl* textctrl=(wxTextCtrl*)FindWindow(crl);
  *textctrl<<currentvalue;
}
    
};
class RemoveDialog:public wxDialog{
  private:
  int start;
  int end;
  void PressedOk(wxCommandEvent& evt){
    InitAllValues();
    EndModal(wxID_OK);
  }
  public:
  RemoveDialog(wxWindow* win,const int& a1,const int& a2):wxDialog(win,wxID_ANY,wxT("Remove String of Characters"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER){
    CreateControls(a1,a2);
    Show(true);
    ShowModal();
  }
  void CreateControls(const int& a0,const int& a1 ){
    wxStaticText* heading=new wxStaticText(this,wxID_ANY,wxT("Specify Range of Position of Characters"));
    wxStaticText* stext2=new wxStaticText(this,wxID_ANY,wxT("Range Of Position"));
    wxStaticLine* sline=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    wxStaticText* stext=new wxStaticText(this,wxID_ANY,wxT("Start Pos:"));
    wxStaticText* stext1=new wxStaticText(this,wxID_ANY,wxT("EndPos:"));
    wxSpinCtrl* sptrl=new wxSpinCtrl(this,sp,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS);
    wxSpinCtrl* sptrl1=new wxSpinCtrl(this,sp1,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS);
    wxButton* bton=new wxButton(this,wxID_OK,wxT("Ok"));
    wxButton* bton1=new wxButton(this,wxID_CANCEL,wxT("Cancel"));
    sptrl->SetValue(a0);
    sptrl1->SetValue(a1);
    wxBoxSizer* bsizer=new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* bsizer1=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer2=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer3=new wxBoxSizer(wxHORIZONTAL);
    SetSizer(bsizer);
    bsizer->Add(heading,0,wxLEFT|wxALL,5);
    bsizer->Add(5,5,0,wxLEFT|wxALL,5);
    bsizer->Add(bsizer1,0,wxLEFT|wxALL,5);
    bsizer1->Add(stext2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer1->Add(sline,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(bsizer2,0,wxLEFT|wxALL,10);
    bsizer2->Add(stext,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(sptrl,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(stext1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(sptrl1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer3,0,wxLEFT|wxALL,5);
    bsizer3->Add(bton,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(bton1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
  }
  int GetStart() const {
    return start;
  }
  int GetEnd() const{
   return end;
  }
  void InitAllValues(){
 wxSpinCtrl* sptrl=(wxSpinCtrl*)FindWindow(sp);
 wxSpinCtrl* sptrl1=(wxSpinCtrl*)FindWindow(sp1);
  start=sptrl->GetValue();
  end=sptrl1->GetValue();     
  }
};
class ReplaceDialog:public wxDialog{
  private:
  wxString str;
  int start;
  int end;
  void PressOk(wxCommandEvent& evt){
    InitAllValues();
    EndModal(wxID_OK);
  }
  public:
  ReplaceDialog(wxWindow* win,const int& start,const int& end):wxDialog(win,wxID_ANY,wxT("ReplaceDialog"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER){
     CreateControls(start,end);
     Show(true);
     ShowModal();
  }
  void CreateControls(const int& a0,const int& a1 ){
    wxStaticText* heading=new wxStaticText(this,wxID_ANY,wxT("The value which replaces the range of position of characters:"));
    wxTextCtrl* textctrl=new wxTextCtrl(this,crl,wxEmptyString,wxDefaultPosition,wxSize(300,20));
    wxStaticText* stext2=new wxStaticText(this,wxID_ANY,wxT("Range Of Position"));
    wxStaticLine* sline=new wxStaticLine(this,wxID_ANY,wxDefaultPosition,wxSize(300,-1));
    wxStaticText* stext=new wxStaticText(this,wxID_ANY,wxT("Start Pos:"));
    wxStaticText* stext1=new wxStaticText(this,wxID_ANY,wxT("EndPos:"));
    wxSpinCtrl* sptrl=new wxSpinCtrl(this,sp,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS);
    wxSpinCtrl* sptrl1=new wxSpinCtrl(this,sp1,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxSP_ARROW_KEYS);
    wxButton* bton=new wxButton(this,wxID_OK,wxT("Ok"));
    wxButton* bton1=new wxButton(this,wxID_CANCEL,wxT("Cancel"));
    sptrl->SetValue(a0);
    sptrl1->SetValue(a1);
    wxBoxSizer* bsizer=new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* bsizer1=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer2=new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* bsizer3=new wxBoxSizer(wxHORIZONTAL);
    SetSizer(bsizer);
    bsizer->Add(heading,0,wxLEFT|wxALL,5);
    bsizer->Add(1,1,0,wxLEFT|wxALL,1);
    bsizer->Add(textctrl,0,wxLEFT|wxALL,5);
    bsizer->Add(5,5,0,wxLEFT|wxALL,5);
    bsizer->Add(bsizer1,0,wxLEFT|wxALL,5);
    bsizer1->Add(stext2,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer1->Add(sline,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(bsizer2,0,wxLEFT|wxALL,10);
    bsizer2->Add(stext,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(sptrl,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(10,10,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(stext1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer2->Add(sptrl1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer->Add(5,5,0,wxLEFT|wxALL,0);
    bsizer->Add(bsizer3,0,wxLEFT|wxALL,5);
    bsizer3->Add(bton,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
    bsizer3->Add(bton1,0,wxALIGN_CENTER_VERTICAL|wxALL,0);
  }
  int GetStartValue() const{
    return start;
  }
  int GetEndValue() const{
    return end;
  }
  wxString GetReplaceValue() const{
    return str;
  }
  bool HasReplaceValue() const{
    if(str==wxT("")){
      return false;
    }
    return true;
  }
 void InitAllValues(){
  wxTextCtrl* textctrl=(wxTextCtrl*)FindWindow(crl);
  wxSpinCtrl* sptrl=(wxSpinCtrl*)FindWindow(sp);
  wxSpinCtrl* sptrl1=(wxSpinCtrl*)FindWindow(sp1);
  start=sptrl->GetValue();
  end=sptrl1->GetValue();
  str=textctrl->GetValue();
  return;
 }
};