#include<wx/wx.h>
#include<ID.h>
#include<TextCtrl.h>
#include<wx/filedlg.h>
#include<wx/wfstream.h>
#include<wx/fontdlg.h>
#include<PotterDialog.h>
#include<wx/fontpicker.h>
#include<wx/textfile.h>
#include<wx/file.h>
using namespace ID;
typedef wxTextFile wxTextFileHandler;
class MyApp:public wxApp{
  public:
  bool OnInit() override;
};
wxIMPLEMENT_APP(MyApp);

class MyFrame:public wxFrame{
    private:
    wxString wxstr;
    //For Text Font Dialog
    int startone;
    int endone;
    wxTextAttr myattr;
    //For Text Alignment Dialog
    int startnew;
    int endnew;
    //For Underlined Font Dialog
    int n0;
    int n1;
    wxTextAttr myattr1;
    //For BulletStyle dialog....
    int n2;
    int n3;
    wxTextAttr myattr2;
    //For File Saving and Reading.....
    wxTextFileHandler filehandle;
    //For LineSpacing Dialog
    int start;
    int end;
    int currentvalue;
    //For Right Indentation 
    int s1;
    int s2;
    int currentvalue1;
    //For Left Indentation 
    int start1;
    int end1;
    int currentvaluetwo;
    //For Removing characters...
    int remove1;
    int remove2;
    //For Replacing Characters
    int replace1;
    int replace2;

   void TextChanged(wxCommandEvent& evt){     //For text Entry
   Potter_Ctrl* ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
   wxPoint pt=ptrl->PositionToCoords(ptrl->GetInsertionPoint());
   SetStatusText(wxString::Format(wxT("Line:%d,Col:%d,Pos:%d"),pt.y,pt.x,ptrl->GetInsertionPoint()));
   Refresh();
   return;
}
 void AutoSave(wxCommandEvent& evt){    //For autosave
   Potter_Ctrl* ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
    if(wxstr==wxT("")){
        MessageBus bus(this,wxT("File is empty"),wxT("Please Open a File "),wxPoint(400,400),wxSize(400,150));
        Refresh();
        return;
    }
    if((GetMenuBar()->FindItem(ID::t5)->IsChecked()) &&(wxstr!=wxT(""))){
        if(ptrl->GetValue()!=wxT("")){
            wxString str=ptrl->GetValue();
            wxTempFile file(wxstr);
            if(!file.IsOpened()){
                file.Open(wxstr);
            }
            file.Write(str);
            file.Flush();
            file.Commit();
}
   MessageBus bus(this,wxT("Auto Save Success"),wxT("File is Saved already"),wxPoint(400,400),wxSize(400,120));
        return;
    }

 }
 void OpenFile(wxCommandEvent& evt) {     //To open a file 
    wxFileDialog dialog(this,wxT("Open File"),wxT("C:\\"),wxEmptyString,wxT("*.txt"),wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    wxTextCtrl*tcrl=(wxTextCtrl*)GetToolBar()->FindControl(ID::t10);
    Potter_Ctrl* ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
    if(dialog.ShowModal()==wxID_OK){
    wxString str=dialog.GetPath();
    wxstr=str;
    if(wxstr==wxT("")){
        MessageBus bus(this,wxT("Open a file"),wxT("Please Open a File "),wxPoint(400,400),wxSize(400,150));
        return;
    }
    filehandle.Open(wxstr);
    if(filehandle.IsOpened()){
        tcrl->SetValue(wxstr);
    }
    if(!filehandle.Exists()){
        MessageBus bus(this,wxT("Invalid File"),wxT("The Selected File does not exist "),wxPoint(400,400),wxSize(400,150));
        return;
    }
    wxString str1=filehandle.GetFirstLine();
    while(!filehandle.Eof()){
        *ptrl<<str1;
        str1=filehandle.GetNextLine();
}
  
    return;
 }
 }
void CloseFile(wxCommandEvent& evt){
   Potter_Ctrl* ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
   if(ptrl->GetValue()==wxT("") && wxstr==wxT("")){
    MessageBus bus(this,wxT("Cannot Close File"),wxT("Please Open a file to enable this feature"),wxPoint(400,400),wxSize(400,120));
    return;
   }
   if(filehandle.IsOpened()){
    filehandle.Write();           //Write to the currently opened file...
   }
}
void CreateFile(wxCommandEvent& evt){

}

void ClearEditor(wxCommandEvent& evt){
   Potter_Ctrl* ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
   ptrl->Clear();
}
void ClearDisplayEntry(wxCommandEvent& evt){
    wxTextCtrl* tcrl=(wxTextCtrl*)GetToolBar()->FindControl(ID::t10);
    tcrl->Clear();
}
void ClearAll(wxCommandEvent& evt){
    Potter_Ctrl* ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
    wxTextCtrl* tcrl=(wxTextCtrl*)GetToolBar()->FindControl(ID::t10);
    ptrl->Clear();
    tcrl->Clear();
}
void CloseWindow(wxCommandEvent& evt){
    if(filehandle.IsOpened()){ //Check If File is Currently Opened
        MessageBus bus(this,wxT("PotterDialog"),wxT("Do you Want to save changes"),wxPoint(400,400),wxSize(400,150));
       if(bus.ShowModal()==wxID_OK){
         filehandle.Write();
         Close();
         return;
       }
       else if(bus.ShowModal()==wxID_CLOSE){
        filehandle.Close();  //closes file and lose all changes made to file..
        Close();   //Close Window...
        return;
       }

    }

    Close();
}


  void SaveFile(wxCommandEvent& evt){// Save Files
  Potter_Ctrl*ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
  wxTextCtrl* tcrl=(wxTextCtrl*)GetToolBar()->FindControl(ID::t10);
   wxFileDialog filedialog(this,wxT("Save File"),wxT("C:\\"),wxEmptyString,wxT("*.txt"),wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
   if(filedialog.ShowModal()==wxID_OK){
    wxString wstr=filedialog.GetPath();
    //Check if the User has not opened any file for writing..
    if(wxstr==wxT("")) {
      wxTempFile file(wstr);
      if(!file.IsOpened()){  //if file is not opened,open it..
        file.Open(wstr);
      }
      if(ptrl->GetValue()==wxT("")){
        MessageBus bus(this,wxT("Empty Editor"),wxT("Editor is empty"),wxPoint(400,400),wxSize(300,120));
        return;
      }    
    wxString str1=ptrl->GetValue();
    if(str1==wxT("")){
        MessageBus bus(this,wxT("Uninitialization"),wxT("Internal error,Failed in initialization"),wxPoint(400,400),wxSize(400,120));
        return;
    }
    file.Write(str1);
    file.Flush();
    file.Commit();       //SucessFully Writing To file
    return;
} 
    filehandle.Write();   //Writing Contents into the file...
    wxTempFile tempfile(wstr);
    if(!tempfile.IsOpened()){
        tempfile.Open(wstr);/// if file is not opened,Open File.. 
    }
   if(ptrl->GetValue()!=wxT("")){
    wxString str2=ptrl->GetValue(); //Get the content of the Text Editor;
    tempfile.Write(str2);
    tempfile.Flush();
    tempfile.Commit();  
    return;    
   }
   else{
    MessageBus bus(this,wxT("Empty Editor"),wxT("The Editor is Empty,Fill it with Values"),wxPoint(400,400),wxSize(400,120));
    return;
   }
  } 
  
}
  
  

 void FontAllText(wxCommandEvent& evt){
    Potter_Ctrl* ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
    wxFontPickerCtrl* fontpicker=(wxFontPickerCtrl*)GetToolBar()->FindItem(ID::t13);
    wxFontData fontdata;
    fontdata.SetInitialFont(fontpicker->GetSelectedFont());
    fontdata.SetColour(fontpicker->GetSelectedColour());
    wxTextAttr attr3;
    wxFontDialog fontdialog(this,fontdata);
    if(fontdialog.ShowModal()==wxID_OK){
        fontpicker->SetSelectedFont(fontdialog.GetFontData().GetChosenFont());
        fontpicker->SetSelectedColour(fontdialog.GetFontData().GetColour());
        attr3.SetFont(fontpicker->GetSelectedFont());
         attr3.SetTextColour(fontpicker->GetSelectedColour());
        ptrl->SetDefaultStyle(attr3);
        Refresh();
        return;
    }
 }


void Display(wxCommandEvent& evt){
    wxTextCtrl* tcrl=(wxTextCtrl*)GetToolBar()->FindControl(ID::t10);
    Potter_Ctrl*ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
    if(tcrl->GetValue()==wxT("")){
        MessageBus bus(this,wxT("Text Entry is Empty"),wxT("Please Open a File "),wxPoint(400,400),wxSize(400,150));
        Refresh();
        return;
    }
    if(ptrl->GetValue()==wxT("")){
        wxString str=tcrl->GetValue();
        wxTextFile file(str);
        if(!file.IsOpened()){
            file.Open();    //if file is not opened, open it.... 
        }
        wxString str1=file.GetFirstLine();
        while(!file.Eof()){
            *ptrl<<str1;
            str1=file.GetNextLine();
        }
        return;
    }
      ptrl->Clear();   //this will automatically clear the current editor...
      wxString str=tcrl->GetValue();
        wxTextFile file(str);
        if(!file.IsOpened()){
            file.Open();    //if file is not opened, open it.... 
        }
        wxString str1=file.GetFirstLine();
        while(!file.Eof()){
            *ptrl<<str1;
            str1=file.GetNextLine();
        }
         MessageBus bus(this,wxT("Success"),wxT("Writing to editor was successful"),wxPoint(400,400),wxSize(400,150));
        return;
    }

    
 void SetFrameFileName(const wxString& str){
        wxstr=str;
    }
 wxString GetFrameFileName() const{
    return wxstr;
 }
 void TextPos(wxCommandEvent& evt){
    Potter_Ctrl* ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
    TextPosDialog dialog(this,myattr,startnew,endnew);
    long start,end;
    wxTextAttr attr;
    if(dialog.ShowModal()==wxID_OK){
    start=(long)dialog.GetSpinCtrlValue();
    end=(long)dialog.GetSpinCtrlValue1();
    attr=dialog.GetTextAttr();
    }
    myattr.SetAlignment(attr.GetAlignment());
    startnew=start;
    endnew=end;
    ptrl->SetStyle(start,end,myattr);
    Refresh();
}
  void TextPosFont(wxCommandEvent& evt){
    Potter_Ctrl* ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
    wxFontPickerCtrl* fontpicker=(wxFontPickerCtrl*)GetToolBar()->FindItem(ID::t13);
    TextPosFontDialog textposfontdialog(this,fontpicker,startone,endone);
    long start,end;
    wxTextAttr attr;
    if(textposfontdialog.ShowModal()==wxID_OK){
        start=textposfontdialog.GetSptrlvalue();
        end=textposfontdialog.GetSptrlvalue1();
        attr=textposfontdialog.GetTextAttr();
    }
   fontpicker->SetSelectedFont(attr.GetFont());
   fontpicker->SetSelectedColour(attr.GetTextColour());
   startone=start;
   endone=end;
   ptrl->SetStyle(start,end,attr);
    Refresh();
  }
  void TextUnderlined(wxCommandEvent& evt){
  Potter_Ctrl * ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
   wxFontPickerCtrl* fontpicker=(wxFontPickerCtrl*)GetToolBar()->FindItem(ID::t13);
  long start,end;
  wxTextAttr attr;
  TextUnderlinedDialog text(this,myattr1,n0,n1);
  if(text.ShowModal()==wxID_OK){
    start=text.GetOne();
    end=text.Gettwo();
    attr.SetFont(fontpicker->GetSelectedFont());
    attr.SetFontUnderlined(text.GetCurrentTextAttr().GetUnderlineType(),text.GetCurrentTextAttr().GetUnderlineColour());
  }
  n0=start;
  n1=end;
   myattr1.SetFont(fontpicker->GetSelectedFont());
  myattr1.SetFontUnderlined(attr.GetUnderlineType(),attr.GetUnderlineColour());
  ptrl->SetStyle(start,end,attr);
    return;
  }
  void TextEffect(wxCommandEvent& evt){
    Potter_Ctrl* ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
    wxFontPickerCtrl* fontpicker=(wxFontPickerCtrl*)GetToolBar()->FindItem(ID::t13);
     long start=0;
     long end=0;
     wxTextAttr attr;
     TextBulletStyleDialog text(this,myattr2,n2,n3);
     if(text.ShowModal()==wxID_OK){
        start=text.GetOne();
        end=text.GetTwo();
        attr.SetBulletStyle(text.GetCurrentTextAttr().GetBulletStyle());
     }
     myattr2.SetFont(fontpicker->GetSelectedFont());
     myattr2.SetBulletStyle(attr.GetBulletStyle());
     n2=start;
     n3=end;
     ptrl->SetStyle(start,end,attr);
     return;

  }
  void LineSpacing(wxCommandEvent& evt){
    int a=0;   //current value
    int b=0;   //first value
    int h=0;   //second value
    LineSpacingDialog linespacedialog(this,currentvalue,start,end);
    Potter_Ctrl* ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
    if(linespacedialog.ShowModal()==wxID_OK){
       a=linespacedialog.GetCurrentValue();
       b=linespacedialog.GetFirstValue();
       h=linespacedialog.GetSecondValue();
    }
    currentvalue=a;
    start=b;
    end=h;
    wxTextAttr linespaceattr;
    
    if(myattr1.HasFontUnderlined()){
        linespaceattr.SetFontUnderlined(myattr1.GetFontUnderlined());
    }
    linespaceattr=myattr2;
    linespaceattr.SetLineSpacing(currentvalue);
    ptrl->SetStyle(a,b,linespaceattr);

  }
  void RightIndent(wxCommandEvent& evt){
    Potter_Ctrl* ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
    wxFontPickerCtrl* fontpicker=(wxFontPickerCtrl*)GetToolBar()->FindItem(ID::t13);
    int s3=0;
    int s4=0;
    int currentvalue2;
    RightIndentDialog rightindentdialog(this,currentvalue1,s1,s2);
    if(rightindentdialog.ShowModal()==wxID_OK){
        s3=rightindentdialog.GetStartValue();
        s4=rightindentdialog.GetEndValue();
        currentvalue2=rightindentdialog.GetCurrentValue();
}
  s1=s3;
  s2=s4;
  currentvalue1=currentvalue2;
  wxTextAttr text;
  text=myattr2;
  if(myattr1.HasFontUnderlined()){
    text.SetFontUnderlined(myattr1.GetFontUnderlined());
  }
  text.SetFont(fontpicker->GetSelectedFont());
  text.SetTextColour(fontpicker->GetSelectedColour());
  text.SetRightIndent(currentvalue2);
  ptrl->SetStyle(s3,s4,text);
}
 void LeftIndent(wxCommandEvent& evt){
    Potter_Ctrl* ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
    wxFontPickerCtrl* fontpicker=(wxFontPickerCtrl*)GetToolBar()->FindItem(ID::t13);
    int s3=0;
    int s4=0;
    int currentvalue2=0;
    LeftIndentDialog rightindentdialog(this,currentvaluetwo,start1,end1);
    if(rightindentdialog.ShowModal()==wxID_OK){
        s3=rightindentdialog.GetStartValue();
        s4=rightindentdialog.GetEndValue();
        currentvalue2=rightindentdialog.GetCurrentValue();
}
  start1=s3;
  end1=s4;
  currentvaluetwo=currentvalue2;
  wxTextAttr text;
  text=myattr2;
  if(myattr1.HasFontUnderlined()){
    text.SetFontUnderlined(myattr1.GetFontUnderlined());
  }
  text.SetFont(fontpicker->GetSelectedFont());
  text.SetTextColour(fontpicker->GetSelectedColour());
  text.SetLeftIndent(currentvalue2);
  ptrl->SetStyle(s3,s4,text);
}
void Remove(wxCommandEvent& evt){
    Potter_Ctrl* ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
    int f=0;
    int f1=0;
    RemoveDialog removedialog(this,remove1,remove2);
    if(removedialog.ShowModal()==wxID_OK){
        f=removedialog.GetStart();
        f1=removedialog.GetEnd();
}
   remove1=f;
   remove2=f1;
   ptrl->Remove(f,f1);
   return;
}
void Replace(wxCommandEvent& evt){
Potter_Ctrl* ptrl=(Potter_Ctrl*)FindWindow(ID::t0);
    int f=0;
    int f1=0;
    wxString str;
    ReplaceDialog replacedialog(this,replace1,replace2);
    if(replacedialog.ShowModal()==wxID_OK){
        f=replacedialog.GetStartValue();
        f1=replacedialog.GetEndValue();
           replace1=f;
          replace2=f1;
      if(replacedialog.HasReplaceValue()){
        str= replacedialog.GetReplaceValue();
        ptrl->Replace(f,f1,str);
        }
        return;
}
}
 
    public:
    MyFrame():wxFrame(nullptr,wxID_ANY,wxT("Potter_text")){
    startone=0;
    endone=0;
    startnew=0;
    endnew=0;
    n0=0;
    n1=0;
    n2=0;
    n3=0;
    start=0;
    end=0;
    wxPanel* panel=new wxPanel(this);
    wxBoxSizer* bsizer=new wxBoxSizer(wxVERTICAL);
    bsizer->Add(panel,2,wxEXPAND|wxALL,0);
    SetSizerAndFit(bsizer);
    Potter_Ctrl* ptrl=new Potter_Ctrl(panel,ID::t0,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxTE_MULTILINE|wxTE_RICH);
    wxBoxSizer* bsizer1=new wxBoxSizer(wxVERTICAL);
    bsizer1->Add(ptrl,2,wxEXPAND|wxALL,0);
    panel->SetSizerAndFit(bsizer1);
    wxMenu*nmenu=new wxMenu;
    nmenu->Append(ID::t1,wxT("Open File"));
    nmenu->Append(ID::t2,wxT("Save File"));
    nmenu->Append(ID::t3,wxT("Clear Editor"));
    nmenu->Append(ID::t13,wxT("Clear All"));
    nmenu->Append(ID::t4,wxT("Close File"),wxT("This Menu automatically saves the content of the Text Editor on Closing"));
    nmenu->Append(ID::t12,wxT("Clear Display Entry"));
    nmenu->AppendCheckItem(ID::t5,wxT("Auto Save"));
    nmenu->Append(ID::t6,wxT("Close Window"));
    wxMenu* nmenu1=new wxMenu;
    nmenu1->Append(ID::t7,wxT("Apply Font"),wxT("This menu item allows you to apply font rendering to all text in the Text Editor"));
    nmenu1->Append(ID::t8,wxT("Positional Font Rendering"),wxT("This menu item allow you to font rendering to a specified line's text in a text Editor"));
    nmenu1->Append(ID::t9,wxT("Positional Text Alignment"));
    nmenu1->Append(ID::t14,wxT("Positional Underline Style"));
    nmenu1->Append(ID::t15,wxT("Positional Bullet Style "));
    nmenu1->Append(ID::t16,wxT("Positional Line Spacing"));
    nmenu1->Append(ID::t17,wxT("Positional Right Indentation"));
    nmenu1->Append(ID::t18,wxT("Positonal Left Indentation"));
    nmenu1->Append(ID::t19,wxT("Remove Characters"),wxT("Specify range of position of characters to remove"));
    nmenu1->Append(ID::t20,wxT("Replace Characters"),wxT("Write Value with the Text Field To Replace The Range Of Position Of Characters"));
    wxMenuBar* nmbar=new wxMenuBar;
    nmbar->Append(nmenu,wxT("File")); 
    nmbar->Append(nmenu1,wxT("Edit"));
    SetMenuBar(nmbar);
    CreateStatusBar();
    CreateToolBar();
    wxToolBar* tbar=GetToolBar();
    wxTextCtrl* tcrl=new wxTextCtrl(tbar,ID::t10,wxEmptyString,wxDefaultPosition,wxSize(300,25));
    GetToolBar()->AddControl(tcrl);
    tbar->Realize();
    wxButton* tbutton=new wxButton(tbar,ID::t11,wxT("Display"));
    GetToolBar()->AddControl(tbutton);
    tbar->Realize();
    tbar->AddSeparator();
    wxFontPickerCtrl* fontpicker=new wxFontPickerCtrl(tbar,ID::t13);
    tbar->AddControl(fontpicker);
    tbar->Realize();
    ptrl->Bind(wxEVT_TEXT,&TextChanged,this);
    Bind(wxEVT_MENU,&OpenFile,this,ID::t1);
    Bind(wxEVT_MENU,&AutoSave,this,ID::t5);
    Bind(wxEVT_MENU,&SaveFile,this,ID::t2);
    tbar->Bind(wxEVT_BUTTON,&Display,this,ID::t11);
    Bind(wxEVT_MENU,&ClearEditor,this,ID::t3);
    Bind(wxEVT_MENU,&ClearAll,this,ID::t13);
    Bind(wxEVT_MENU,&ClearDisplayEntry,this,t12);  
    Bind(wxEVT_MENU,&CloseWindow,this,t6);
    Bind(wxEVT_MENU,&FontAllText,this,ID::t7);
    Bind(wxEVT_MENU,&TextPos,this,ID::t9);
    Bind(wxEVT_MENU,&TextPosFont,this,ID::t8);
    Bind(wxEVT_MENU,&TextUnderlined,this,ID::t14);
    Bind(wxEVT_MENU,&TextEffect,this,ID::t15);
    Bind(wxEVT_MENU,&CloseFile,this,ID::t4);
    Bind(wxEVT_MENU,&LineSpacing,this,ID::t16);
    Bind(wxEVT_MENU,&RightIndent,this,ID::t17);
    Bind(wxEVT_MENU,&LeftIndent,this,ID::t18);
    Bind(wxEVT_MENU,&Remove,this,ID::t19);
    Bind(wxEVT_MENU,&Replace,this,ID::t20);
    }
};

bool MyApp::OnInit(){
    MyFrame* myframe=new MyFrame;
    myframe->SetSize(500,500);
    myframe->Show(true);
    return true;
} 