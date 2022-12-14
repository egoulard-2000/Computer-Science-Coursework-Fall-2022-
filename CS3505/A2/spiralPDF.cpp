/*
    Emile Goulard
    uID: u1244855
    CS3505 - Assignment 2

    Summary:
        This is the executable file that is responsible for printing text onto a pdf
        in a spiral formation. It then saves that into a 'spiralPDF.pdf' file to be viewed.

*/
#include "Spiral.h"
#include "HaruPDF.h"

/*
    The main executable in charge of creating our spiralPDF.pdf
*/
int main(int argc, char **argv) {
    // Better practice to use namespace within scope
    using namespace std;

    // Initial Check for proper number of arguments
    bool failCase = argc < 2;
    if(failCase) {
        cout << "Error: improper amount of arguments. Insert the Text to Display after compiling." << endl;
        exit(EXIT_FAILURE);
    }

    // Positioning variables
    double centerX = 210.0;
    double centerY = 300.0;
    double angle = 180.0;
    double radius = 40.0;

    // Spiral and PDF constructors (stack)
    Spiral spiralTest(centerX, centerY, angle, radius);
    HaruPDF pdf(argv[0]);
    
    // Grab the characters from the console string input
    const char* ARG_INPUT = argv[1];

    // Loop through those characters and adjust the angle/radius of them to create spiral effect on output .pdf
    for(unsigned int i = 0; i < strlen(ARG_INPUT); i++) {
        char buf[2];
        spiralTest++;

        double x = spiralTest.getTextX();
        double y = spiralTest.getTextY();
        double deg = spiralTest.getLetterAngle();
        buf[0] = ARG_INPUT[i];
        buf[1] = 0;

        pdf.writePDF(x, y, deg, buf);
    }

    // Lastly, save to a pdf
    pdf.savePDF();
    return 0;
}
