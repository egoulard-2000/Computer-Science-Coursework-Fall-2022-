/*
    Emile Goulard
    uID: u1244855
    CS3505 - Assignment 2

    Summary:
        This file is meant to implement the functions provided in 'HaruPDF.h' using the 
        variables. It simply creates a new .pdf file, writes any sequence of characters onto it,
        and then saves it to be viewed in File Explorer.
*/
#include "HaruPDF.h"

/*
    Constructor for HaruPDF
        - It takes a filename input as a sequence of characters to be stored as a string.
*/
HaruPDF::HaruPDF(char fname[256]) {
    /* make the file name with .pdf extention */
    strcpy (_fname, fname);
    strcat (_fname, ".pdf");

    /* create new pdf */
    _pdf = HPDF_New (NULL, NULL);

    /* add a new page object. */
    _page = HPDF_AddPage (_pdf);
    HPDF_Page_SetSize (_page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);

    /* setup the font */
    _font = HPDF_GetFont (_pdf, "Courier-Bold", NULL);
    HPDF_Page_SetTextLeading (_page, 20);
    HPDF_Page_SetGrayStroke (_page, 0);

    HPDF_Page_BeginText (_page);

    HPDF_Page_SetFontAndSize (_page, _font, 30);
}

/*
    This function is responsible for writing the sequence of characters (from the argument input during execution)
    to the .pdf page. It grabs the x and y values of the spiral text and applies an angle they follow around the spiral.
*/
void HaruPDF::writePDF(double x, double y, double deg, char buf[2]) {

    //double rad = deg * M_PI / 180; // This was causing the letters to not follow the spiral for some reason

    /* displays how the text will be put onto the page */
    HPDF_Page_SetTextMatrix(_page,
                                cos(deg), sin(deg), -sin(deg), cos(deg),
                                x, y);
    
    /* finally show the text */
    HPDF_Page_ShowText (_page, buf);
}

/*
    This function is self-explanatory.
*/
void HaruPDF::savePDF() {
    /* end the text document */
    HPDF_Page_EndText (_page);

    /* save the document to a file */
    HPDF_SaveToFile (_pdf, _fname);

    /* clean up */
    HPDF_Free (_pdf);
}