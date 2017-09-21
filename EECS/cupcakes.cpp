/**
 * cupcakes.cpp
 *
 * <#Aheer Alvi#>
 * <#aaheer#>
 *
 * EECS 183: Project 1
 * Fall 2017
 *
 * Takes user input for number of people to serve, outputs
 * the necessary number of cupcake batches, a shopping list
 * and the total cost of all the items on the list.
 */


#include <iostream>
#include <cmath>
#include <string>


using namespace std;

int calculatePackage(int num1, int num2);

string pluralize(string singular, string plural, int number);

int main() {
    // Variable declarations
    int pplToServe = 0;
    int batches = 0;
    double totalCost = 0;

    // Constants for prices of shopping items
    const double PRICE_FLOUR = 3.09;
    const double PRICE_GRANSUGAR = 2.98; 
    const double PRICE_BUTTER = 2.5;
    const double PRICE_SOURCREAM = 1.29;
    const double PRICE_EGGS = 2.68;
    const double PRICE_POWDSUGAR = 1.18;
    const double PRICE_VANILLA = 4.12;


    // Prompt user, store input
    cout << "How many people do you need to serve? ";
    cin >> pplToServe;
    
    // Calculate the number of batches and store
    batches = calculatePackage(pplToServe, 12);
    
    // Output the required number of batches
    cout << "\n\nYou need to make: " << batches << " " << 
        pluralize("batch", "batches", batches) << " of cupcakes" << endl;

    /* Determine the quantity of items needed
    * Many of the items are doubles to allow for halves and conversions
    * The units of these variables are as follows:
    * flour: cup, granSugar: cup, butter: cup, sourCream: cup, 
    * eggs: egg, powderedSugar: cups, vanilla: tsp.
    */
    double flour = 1.5 * batches;
    double granSugar = batches;
    double butter = 1.5 * batches;
    double sourCream = 0.5 * batches;
    int eggs = 3 * batches;
    double powderedSugar = 2.5 * batches;
    double vanilla = 4.5 * batches;

    /* Convert all items into the units used for shopping
    * Note that the units are not converted directly to the units for shopping 
    * This was done so if I choose to do the S'more project later it'll
    * be easier to make sense of the code this way.
    * Subsequently round up all the numbers
    * The units are as follows:
    * flour: lbs, granSugar: lbs, butter: lbs, sourCream: oz, eggs: egg
    * powderedSugar: lbs, vanilla: oz
    */
    flour /= 4;
    granSugar /= 2;
    butter /= 2;
    sourCream *= 8;
    powderedSugar /= 2.75;
    vanilla /= 6;

    flour = ceil(flour);
    granSugar = ceil(granSugar);
    butter = ceil(butter);
    sourCream = ceil(sourCream);
    powderedSugar = ceil(powderedSugar);
    vanilla = ceil(vanilla);
    
    // Convert all items into bags or containers
    flour = calculatePackage(flour, 5);
    granSugar = calculatePackage(granSugar, 5);
    sourCream = calculatePackage(sourCream, 8);
    eggs = calculatePackage(eggs, 12);
    powderedSugar = calculatePackage(powderedSugar, 2);
    vanilla = calculatePackage(vanilla, 2);
    
    // Print out the necessary values and comments on the shopping list
    cout << "\nShopping List for \"Best Ever\" Vanilla Cupcakes";
    cout << "\n----------------------------------------------\n";
    cout << "\t" << flour << " " << pluralize("bag", "bags", flour) << " of flour\n";
    cout << "\t" << granSugar << " " << pluralize("bag", "bags", granSugar) 
        << " of granulated sugar\n";
    cout << "\t" << butter << " " << pluralize("pound", "pounds", butter) << " of butter\n";
    cout << "\t" << sourCream << " " << pluralize("container", "containers", sourCream) 
        << " of sour cream\n";
    cout << "\t" << eggs << " " << pluralize("dozen", "dozen", eggs) << " eggs\n";
    cout << "\t" << powderedSugar << " " << pluralize("bag", "bags", powderedSugar) 
        << " of powdered sugar\n";
    cout << "\t" << vanilla << " " << pluralize("bottle", "bottles", vanilla) << " of vanilla\n";
    
    // Find the cost of items 
    totalCost = flour * PRICE_FLOUR + granSugar * PRICE_GRANSUGAR + butter * PRICE_BUTTER +
        sourCream * PRICE_SOURCREAM + eggs * PRICE_EGGS + powderedSugar * PRICE_POWDSUGAR + 
        vanilla * PRICE_VANILLA;

    cout << "\nTotal expected cost of ingredients: $" << totalCost << endl;

    cout << "\nHave a great party!";
    

}

// Necessary functions below;

/**
 * Calculates the number of num2-sized units needed for a specific product
 *
 * Requires: num1 is the number of objects (eggs, cupcakes, etc) needed.
 *           num2 is the size of the package (dozen eggs, batch of cupcakes)
 * Modifies: Nothing.
 * Returns: The number of num2-sized units needed to meet the needs of the baker.
 */
int calculatePackage(int num1, int num2) {
    return (int) (ceil((double)num1/num2));
}

/**
 * Pluralizes a word if needed.
 *
 * Requires: singular is the singular form of the word.
 *           plural is the plural form of the word.
 *           number determines how many things there are; must be >= 1.
 * Modifies: Nothing.
 * Effects:  Returns return the singular form of the word if number == 1.
 *           Otherwise, returns the plural form.
 */
string pluralize(string singular, string plural, int number) {
    return (number==1) ? singular : plural;
}

