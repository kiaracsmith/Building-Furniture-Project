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
#include "Constants.h"

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
    void OnButton5Click(wxCommandEvent &event);
    void OnButton2Click(wxCommandEvent &event);
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
    static const long ID_BUTTON4;
    static const long ID_BUTTON5;
    static const long ID_LISTVIEW1;
    //*)

    //(*Declarations(Building_Furniture_ProjectFrame)
    wxButton* Button1;
    wxButton* Button2;
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


/*
=================================================================================
                                Classes
=================================================================================
*/
/*
Title: Preview Class
Description: Class that defines the linked list that is shown on the Preview Window.
*/
class PREV
{
public:
    typedef struct node
    {
        std::string a; //Part
        float b;       //Length
        float c;       //Width
        float d;       //Thickness

        node *next;
    } * nodePtr;
    nodePtr head;
    nodePtr current;
    nodePtr temp;

    List()
    {
        head = NULL;
        current = NULL;
        temp = NULL;
        return 0;
    }

    void AddNode(std::string a, float b, float c, float d)
    {
        nodePtr n = new node;
        n->next = NULL;

        n->a = a;
        n->b = b;
        n->c = c;
        n->d = d;

        if (head != NULL)
        {
            current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = n;
        }
        else
        {
            head = n;
        }
    }

    void PrintList()
    {
        current = head;
        while (current != NULL)
        {
            std::cout << current->a << "\t";
            std::cout << std::to_string(current->b) << "\t";
            std::cout << std::to_string(current->c) << "\t";
            std::cout << std::to_string(current->d) << "\n";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void DeleteAllNodes()
    {
        if (head != NULL)
        {
            temp = head->next;
            while (temp != NULL)
            {
                head->next = temp->next;
                temp->next = NULL;
                free(temp);
                temp = head->next;
            }
        }
    }
};

/*
=================================================================================
                                Varaible Constants
=================================================================================
*/


/*
=================================================================================
                                Function Handlers
=================================================================================
*/
std::string roundFunc(float a);
void BoardPrint(std::string NAME, BOARD A);
void StoreBoard(std::string DESC, std::string PART, BOARD A);
void StoreUnit(std::string DESC, float L, float H, float D, std::string COLOR, int qty);
std::string FloorUnit(float W, float H, float D, int t, std::string color, int n, int drawOpt);
static int createDB();
static int createTable();
static int callback(void *NotUsed, int argc, char **argv, char **azColName);
static int cbListUpdate(void *NotUsed, int argc, char **argv, char **azColName);


//Database Function Handlers

#endif // BUILDING_FURNITURE_PROJECTMAIN_H
