 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */


/*
Thing 1) Treadmill
*/
struct Treadmill
{
    // current speed (float)
    float currentSpeedKph = 0.0f;
    // current inclination (float)
    float currentInclinationDegrees = 0.0f;
    // total distance simulated (float)
    float totalDistanceSimulatedKm = 0.0f;
    // session distance simulated (float)
    float sessionDistanceSimulatedKm = 0.0f;
    // maximum weight allowance (int)
    int maximumWeightAllowanceKg = 300;

    // display information for a value
    struct ValueDisplay
    {
        // name of the current value being displayed
        std::string name = "speed";
        // name of the unit of the current value being displayed
        std::string unit = "km/h";
        // the value being displayed
        float value = 0.0f;
        // the colour the value and unit should be displayed in
        std::string colour = "green";
        // font to be used for the display of this value
        std::string font = "Arial";

        // updates the current value
        void updateValue(float newValue);

        // changes font
        void changeFont(std::string font = "Arial", int fontSize = 18);

        // changes colour
        void changeColour(std::string color = "green");
    };

    ValueDisplay speedDisplay;

    ValueDisplay inclineDisplay;

    // rotate the belt    
    void rotateBelt(float speeedKph);

    // incline the surface
    void incline(float inclinationDegrees);

    // show a value
    void display(ValueDisplay displayValue);
};

/*
Thing 2) Helicopter
*/
struct Helicopter
{
    // number of main rotor blades (int)
    int numMainRotorBlades = 4;
    // number of seats (int)
    int numSeats = 4;
    // fuel capacity (float)
    float fuelCapacityL = 550.0f;
    //  maximum range (float)
    float maximumRangeKm = 650.0f;
    // colour (std::string)
    std::string colour = "white";

    // take off
    void ascend(float speedKph);
    
    // travel
    void travel(float speedKph, float bearingRads, float distanceKm);

    // land
    void descend(float speedKph);
};

/*
Thing 3) Cat
*/
struct Cat
{
    // fur pattern (std::string)
    std::string furPattern = "tabby";
    // fur colour (std::string)
    std::string furColour = "orange";
    // eye color (std::string)
    std::string eyeColor = "green";
    // sex (char)
    char sex = 'M';
    // age (int)
    int age = 3;

    // hunt
    bool hunt(std::string creature); // returns true if a creature was caught

    // eat
    void eat(float amountOfFoodKg);

    // purr
    void purr(float volumeDb);
};

/*
Thing 4) Liquid
*/
struct Liquid
{
    // boiling point (double)
    double boilingPointC = 100.0;
    // freezing point (double)
    double freezingPointC = 0.0;
    // volume (double) -- changed from surface tension
    double volumeL = 7;
    // viscocity (double)
    double viscocityCp = 0.89;
    // temperature (double)
    double temperatureC = 18.0;
    
    // freeze
    void freeze();

    // boil
    void boil();
    
    // evaporate
    double evaporate(float surfaceArea); // returns the volume evaporated
};   

/*
Thing 5) Roots
*/
struct Roots
{
    // primary roots (int)
    int primaryRoots = 1;
    // secondary roots (int)
    int secondaryRoots = 1500;
    // total volume (float)
    float totalVolumeL = 2600.0f;
    // total length (float)
    float totalLengthKm = 33.12f;
    // density (float)
    float densityKgPerL = 0.0615f;

    // absorb water
    void absorbWater(float volumeL);

    // absorb nutrients
    void absorbNutrients(float volumeL);
    
    // store energy
    float storeEnergy(float newEnergy); // returns the current total energy stored
};

/*
Thing 6) Trunk
*/
struct Trunk
{
    // bark thickness (float)
    float barkThicknessCm = 1.5f;
    // sapwood thickness (float)
    float sapwoodThicknessCm = 3.25f;
    // heartwood thicnkess (float)
    float heartwoodThicknessCm = 18.614f;
    // pith radius (float)
    float pithRadiusCm = 0.21565f;
    // total radius (float)
    float totalRadiusCm = 23.57965f;
    
    // transport water
    void transportWater(float volumeL);

    // transport nutrients
    void transportNutrients(float volumeL);
    
    // resist wind
    float resistWind(float speedKph); // returns trunk integrity (%)
};

/*
Thing 7) Branches
In retrospect, I was thinking in terms of collections, (i.e. a tree has many branches) but I conceived the UDT as a single branch.
*/
struct Branch
{
    // length (float)
    float lengthCm = 12.0f;
    // child branches (int)
    int childBranches = 5;
    // buds (int)
    int buds = 5;
    // leaves (int)
    int leaves = 50;
    // age (int)
    int age = 4;

    // support leaves
    void supportLeaves(int maxLeaves);

    // transport water
    void transportWater(float volumeL);

    // transport nutrients
    void transportNutrients(float volumeL);
};

/*
Thing 8) Leaves
As with the branches, I conceived the UDT as a single leaf.
*/
struct Leaf
{
    // length (float)
    float lengthCm = 6.5f;
    // width (float)
    float widthCm = 6.5f;
    // colour (std::string)
    std::string colour = "green";
    // veins (int)
    int veins = 16;
    // hydration level (float)
    float hydrationLevel = 0.85f;
    
    // grow
    void grow();

    // photosynthesize
    float photosynthesize(float sunlight); // returns glucose produced

    // change colour
    void changeColour(std::string newColour);
};

/*
Thing 9) Fruit
As with the branches, I conceived the UDT as a single fruit.
*/
struct Fruit
{
    // seeds (int)
    int seeds = 2;
    // endosperm level (float)
    float endospermLevel = 0.75f;
    // hydration level (float)
    float hydrationLevel = 0.85f;
    // epicarp thickness (float)
    float epicarpThicknessCm = 0.05f;
    // mesocarp thickness (float)
    float mesocarpThicknessCm = 0.05f;

    struct Seed 
    {
        // weight (float)
        float weightGrams = 0.5f;
        // seed coat integrity
        float coatIntegrity = 1.0f;
        // germination days (int)
        int germinationDays = 14;
        // stored energy (float)
        float storedEnergy = 1.0f;
        // days dormant
        int daysDormant = 0;

        // grow root
        bool growRoot(bool germinated = false); // returns true if root grown

        // grow a stem
        bool growStem(bool germinated = false); // returns true if stem grown

        // grow leaves
        int growLeaves(bool germinated = false, int numLeaves = 2); // returns number of leaves grown
    };

    // protect seed (raise a seed's coatIntegrity)
    void protectSeed(float increment);

    // disperse a seed
    void disperseSeed(Seed seed, float distanceKm);
    
    // feed seed
    float feedSeed(Seed seed, float energy); // returns the amount of food remaining in the fruit in micrograms
};

/*
Thing 10) Tree
This is a very unusual tree.
*/
struct Tree
{
    // 5 properties:
    // Root System
    Roots roots;
    // Trunk
    Trunk trunk;
    // Branch
    Branch branch;
    // Leaf
    Leaf leaf;
    // Fruit
    Fruit fruit;

    // Produce Leaves
    float produceLeaves(int numBranches); // returns the number of leaves produced

    // Procuce Flowers
    int produceFlowers(int numLeaves); // returns the number of flowers produced

    // Procuce Fruit
    void produceFruit(int numFlowers); // returns the number of fruits produced
};
   
int main()
{
    std::cout << "good to go!" << std::endl;
}
