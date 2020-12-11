/***************************************************************
 * Name:      CupboardSizerMain.h
 * Purpose:   Defines Application Frame
 * Author:    JJ Maree ()
 * Created:   2020-12-11
 * Copyright: JJ Maree ()
 * License:
 **************************************************************/

#ifndef CUPBOARDSIZERMAIN_H
#define CUPBOARDSIZERMAIN_H

//(*Headers(CupboardSizerFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class CupboardSizerFrame: public wxFrame
{
    public:

        CupboardSizerFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~CupboardSizerFrame();

    private:

        //(*Handlers(CupboardSizerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(CupboardSizerFrame)
        static const long ID_BUTTON1;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        //*)

        //(*Declarations(CupboardSizerFrame)
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // CUPBOARDSIZERMAIN_H
