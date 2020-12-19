/***************************************************************
* Name:      Building_Furniture_ProjectMain.h
* Purpose:   Defines Application Frame
* Author:    JJ Maree ()
* Created:   2020-12-11
* Copyright: JJ Maree ()
* License:
**************************************************************/

#ifndef BUILDING_FURNITURE_PROJECTMAIN_H
#define BUILDING_FURNITURE_PROJECTMAIN_H

//(*Headers(Building_Furniture_ProjectFrame)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/listctrl.h>
#include <wx/spinctrl.h>
#include <wx/statbox.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)
class Building_Furniture_ProjectFrame : public wxFrame
{
public:
    Building_Furniture_ProjectFrame(wxWindow *parent, wxWindowID id = -1);
    virtual ~Building_Furniture_ProjectFrame();

private:
    //(*Handlers(Building_Furniture_ProjectFrame)
    void OnQuit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    void OnClose(wxCloseEvent &event);
    void OnButton1Click(wxCommandEvent &event);
    void OnSpinCtrl1Change(wxSpinEvent &event);
    void OnChoice1Select(wxCommandEvent &event);
    void OnButton4Click(wxCommandEvent &event);
    void OnListBox1Select(wxCommandEvent &event);
    void OnListView1BeginDrag(wxListEvent &event);
    void ListUpdate();


    //*)
    //(*Identifiers(Building_Furniture_ProjectFrame)
    static const long ID_STATICBOX3;
    static const long ID_STATICBOX1;
    static const long ID_BUTTON1;
    static const long ID_STATICTEXT1;
    static const long ID_CHOICE1;
    static const long ID_CHOICE2;
    static const long ID_STATICTEXT2;
    static const long ID_STATICBOX2;
    static const long ID_STATICTEXT3;
    static const long ID_STATICTEXT4;
    static const long ID_SPINCTRL1;
    static const long ID_SPINCTRL2;
    static const long ID_SPINCTRL3;
    static const long ID_STATICTEXT5;
    static const long ID_STATICLINE1;
    static const long ID_BUTTON2;
    static const long ID_BUTTON3;
    static const long ID_BUTTON4;
    static const long ID_BUTTON5;
    static const long ID_LISTVIEW1;
    //*)

    //(*Declarations(Building_Furniture_ProjectFrame)
    wxButton* Button1;
    wxButton* Button2;
    wxButton* Button3;
    wxButton* Button4;
    wxButton* Button5;
    wxChoice* Choice1;
    wxChoice* Choice2;
    wxListView* ListView1;
    wxSpinCtrl* SpinCtrl1;
    wxSpinCtrl* SpinCtrl2;
    wxSpinCtrl* SpinCtrl3;
    wxStaticBox* StaticBox1;
    wxStaticBox* StaticBox2;
    wxStaticBox* StaticBox3;
    wxStaticLine* StaticLine1;
    wxStaticText* StaticText1;
    wxStaticText* StaticText2;
    wxStaticText* StaticText3;
    wxStaticText* StaticText4;
    wxStaticText* StaticText5;
    //*)

    DECLARE_EVENT_TABLE()
};

#endif // BUILDING_FURNITURE_PROJECTMAIN_H
