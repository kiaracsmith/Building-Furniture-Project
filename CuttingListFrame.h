#ifndef CUTTINGLISTFRAME_H
#define CUTTINGLISTFRAME_H

//(*Headers(CuttingListFrame)
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/menu.h>
//*)
#include <wx/textfile.h>
#include <string>
#include <iostream>

class CuttingListFrame : public wxFrame
{
public:
	CuttingListFrame(wxWindow *parent, wxWindowID id = wxID_ANY, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize);
	virtual ~CuttingListFrame();

	//(*Declarations(CuttingListFrame)
	wxFileDialog* FileDialog1;
	wxGrid* Grid1;
	wxMenu* Menu1;
	wxMenu* Menu2;
	wxMenuBar* MenuBar1;
	wxMenuItem* MenuItem1;
	wxMenuItem* MenuItem2;
	wxMenuItem* MenuItem3;
	//*)

protected:
	//(*Identifiers(CuttingListFrame)
	static const long ID_GRID1;
	static const long REFRESH_ID1;
	static const long CSV1;
	static const long PDF1;
	//*)

private:
	//(*Handlers(CuttingListFrame)
	void OnButton1Click(wxCommandEvent &event);
	void UpdateList();
	void OnButton1Click1(wxCommandEvent& event);
	void REFRESHBUTTON(wxCommandEvent &event);
	void PDF_Export(wxCommandEvent &event);
	void CSV_Export(wxCommandEvent &event);
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
class CT
{
public:
	typedef struct node
	{
		std::string a;
		float b;	   //Width
		float c;	   //Depth
		float d;	   //Height
		std::string e; //Color
		int f;		   //Quantity
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

	void AddNode(std::string a, float b, float c, float d, std::string e, int f)
	{
		nodePtr n = new node;
		n->next = NULL;

		n->a = a;
		n->b = b;
		n->c = c;
		n->d = d;
		n->e = e;
		n->f = f;
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
			std::cout << std::to_string(current->d) << "\t";
			std::cout << current->e << "\t";
			std::cout << std::to_string(current->f) << "\n";
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
static int cbCutListUpdate(void *NotUsed, int argc, char **argv, char **azColName);

#endif
