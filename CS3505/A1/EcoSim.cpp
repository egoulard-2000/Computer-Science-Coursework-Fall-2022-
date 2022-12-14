/*
Emile Goulard
uID: u1244855

CS3505
A1: An Ecological Simulation

Summary: 
    Calculates the Rabbit and Fox populations, updates them, and then
    plots them in an ascii chart.

*/
#include <iostream>
#include <cmath>

using namespace std;

void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes);
void plotPopulations(double numRabbits, double numFoxes, double fractionalScaleFactor);
void plotCharacter(int, char);
void incrementCounter(int* counter);
void runSimulation(int numOfIterations, double rabbitPopulation, double foxPopulation);

int main() {

    //Local variables to run the simulation
    double rabbitPopulation, foxPopulation;
    static const int numOfIterations = 500;

    //Ask for user input
    cout << "Please enter initial rabbit population and fox population: " << endl;
    cin >> rabbitPopulation >> foxPopulation;

    //Check if user did correct input in terminal
    if(cin.fail()) {
        cout << "ERROR: Please enter rabbit THEN fox population in numerical format" << endl;
    }

    //Start running based on input
    runSimulation(numOfIterations, rabbitPopulation, foxPopulation);
}

/*
    Using the Lotka-Volterra equation, this function finds the new population of rabbits and foxes.
*/
void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes) {
    //New rabbit and fox population variables and
    //Formula for change in population (delta will be new amount)
    double deltaRabbits = g * numRabbits * (1 - numRabbits / K) - p * numRabbits * numFoxes;
    double deltaFoxes = c * p * numRabbits * numFoxes - (m * numFoxes);

    //Update the current populations
    numRabbits += deltaRabbits;
    numFoxes += deltaFoxes;
}

/*
    This function plots the population of rabbits, 'r, and foxes, 'F', with a fractional scaling.
    The first position begins at 0 in terminal.
*/
void plotPopulations(double numRabbits, double numFoxes, double fractionalScaleFactor) {
    //Characters to draw
    char rabbitChar = 'r', foxChar = 'F', overlapChar = '*';

    //Positions of characters (+1 is to offset a little to the right since we start at 0)
    int rabbitCharPosition = floor(numRabbits * fractionalScaleFactor);
    int foxCharPosition = floor(numFoxes * fractionalScaleFactor);

    //Check the positions to see which character belongs on either side of the graph
    if(rabbitCharPosition < foxCharPosition) {
        //Since rabbit is on left-side, plot rabbit first and then fox
        plotCharacter(rabbitCharPosition, rabbitChar);
        plotCharacter(foxCharPosition - rabbitCharPosition - 1, foxChar);
    }
    else if (rabbitCharPosition > foxCharPosition) {
        //Since fox is on left-side, plot fox first and then rabbit
        plotCharacter(foxCharPosition, foxChar);
        plotCharacter(rabbitCharPosition - foxCharPosition - 1, rabbitChar);
    }
    else {
        //They overlap, thus place an '*' in either rabbit or fox position
        plotCharacter(rabbitCharPosition, overlapChar);
    }
}

/*
    Places a character by a certain amount of spaces in the terminal.
    If the number of spaces is less than 1, it just prints the character.
*/
void plotCharacter(int numberOfSpaces, char c) {
    //Loops to output number of spaces
    for(int i = 0; i < numberOfSpaces; i++) {
        cout << ' ';
    }

    //output character after
    cout << c;
}

/*
    Simulates the change of rabbit and fox population over the course of # of interations.
*/
void runSimulation(int numOfIterations, double rabbitPopulation, double foxPopulation) {
    //Variables for population fluctuation
    double rabbitGrowth = 0.2;
    double predationRate = 0.0022;
    double foxPreyConversion = 0.6;
    double foxMortalityRate = 0.2;
    double carryCapacity = 1000.0;
    double fractionalScaleFactor = 0.1;

    //Initial plot of population
    plotPopulations(rabbitPopulation, foxPopulation, fractionalScaleFactor);
    cout << endl; //endline after for bar chart look

    //This iteration will update the graph and plot the new change until the population is gone or the iteration is expired
    int counter = 0;
    while(counter < numOfIterations && rabbitPopulation > 0 && foxPopulation > 0) {
        updatePopulations(rabbitGrowth, predationRate, foxPreyConversion, foxMortalityRate, carryCapacity, rabbitPopulation, foxPopulation);
        
        plotPopulations(rabbitPopulation, foxPopulation, fractionalScaleFactor);
        cout << endl; //endline after for bar chart look

        int* c = &counter;
        incrementCounter(c);
    }
}

/*
    Helper function that simply increments a counter.
*/
void incrementCounter(int* counter) {
    *counter += 1;
}