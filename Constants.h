#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED


#include <string>
#define DBLoc "./db/test.db"
/*
=================================================================================
                                Classes
=================================================================================
*/
/*
Title: Board Class
Description: Class that defines the boards
*/
class BOARD
{
public:
    float L, W, t;
    std::string material;
    int amount;
    /*
        Title: Board Constructor
        Input(s):
        y - Board Dimension (1)
        x - Board Dimension (2)
        z - Board Thickness
        color - Material Color
        qty  - Board Quantity

        Output(s):
        None
        */
    BOARD(int y, int x, int z = 16, std::string color = "White", int qty = 1)
    {
        L = (y < x) ? x : y;
        W = (y > x) ? x : y;
        t = z;
        material = color;
        amount = qty;
    }
};


#endif // CONSTANTS_H_INCLUDED
