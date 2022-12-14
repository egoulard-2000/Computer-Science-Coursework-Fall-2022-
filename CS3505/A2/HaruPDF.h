/*
    Emile Goulard
    uID: u1244855
    CS3505 - Assignment 2

    Summary:
        This is the header file that defines the HaruPDF Class.
        Refer to the HaruPDF class comment for more information.

*/

#ifndef HARUPDF_H
#define HARUPDF_H
#include "hpdf.h"

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
    HaruPDF Class to be extended in 'HaruPDF.cpp' file.

    It contains variables necessary for writing and saving characters onto a '.pdf' extension file.
*/
class HaruPDF {
    private:
        HPDF_Doc  _pdf;
        HPDF_Page _page;
        HPDF_Font _font;
        char _fname[256];

    public:
        HaruPDF(char fname[256]);
        void writePDF(double x, double y, double rad, char buf[2]);
        void savePDF();
};

#endif