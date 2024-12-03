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

struct Treadmill
{
    float currentSpeedKph = 0.0f;
    float currentInclinationDegrees = 0.0f;
    float totalDistanceSimulatedKm = 0.0f;
    float sessionDistanceSimulatedKm = 0.0f;
    int maximumWeightAllowanceKg = 300;

    struct ValueDisplay
    {
        std::string name = "speed";
        std::string unit = "km/h";
        float value = 0.0f;
        std::string colour = "green";
        std::string font = "Arial";

        void updateValue(float newValue);
        void changeFont(std::string font = "Arial", int fontSize = 18);
        void changeColour(std::string color = "green");
    };

    ValueDisplay speedDisplay;
    ValueDisplay inclineDisplay;
    void rotateBelt(float speeedKph);
    void incline(float inclinationDegrees);
    void display(ValueDisplay displayValue);
};

struct Helicopter
{
    int numMainRotorBlades = 4;
    int numSeats = 4;
    float fuelCapacityL = 550.0f;
    float maximumRangeKm = 650.0f;
    std::string colour = "white";

    void ascend(float speedKph);    
    void travel(float speedKph, float bearingRads, float distanceKm);
    void descend(float speedKph);
};

struct Cat
{
    std::string furPattern = "tabby";
    std::string furColour = "orange";
    std::string eyeColor = "green";
    char sex = 'M';
    int age = 3;

    bool hunt(std::string creature);
    void eat(float amountOfFoodKg);
    void purr(float volumeDb);
};

struct Liquid
{
    double boilingPointC = 100.0;
    double freezingPointC = 0.0;
    double volumeL = 7;
    double viscocityCp = 0.89;
    double temperatureC = 18.0;
    
    void freeze();
    void boil();
    double evaporate(float surfaceArea);
};   

struct Roots
{
    int primaryRoots = 1;
    int secondaryRoots = 1500;
    float totalVolumeL = 2600.0f;
    float totalLengthKm = 33.12f;
    float densityKgPerL = 0.0615f;

    void absorbWater(float volumeL);
    void absorbNutrients(float volumeL);
    float storeEnergy(float newEnergy);
};

struct Trunk
{
    float barkThicknessCm = 1.5f;
    float sapwoodThicknessCm = 3.25f;
    float heartwoodThicknessCm = 18.614f;
    float pithRadiusCm = 0.21565f;
    float totalRadiusCm = 23.57965f;
    
    void transportWater(float volumeL);
    void transportNutrients(float volumeL);
    float resistWind(float speedKph);
};

struct Branch
{
    float lengthCm = 12.0f;
    int childBranches = 5;
    int buds = 5;
    int leaves = 50;
    int age = 4;

    void supportLeaves(int maxLeaves);
    void transportWater(float volumeL);
    void transportNutrients(float volumeL);
};

struct Leaf
{
    float lengthCm = 6.5f;
    float widthCm = 6.5f;
    std::string colour = "green";
    int veins = 16;
    float hydrationLevel = 0.85f;
    
    void grow();
    float photosynthesize(float sunlight);
    void changeColour(std::string newColour);
};

struct Fruit
{
    int seeds = 2;
    float endospermLevel = 0.75f;
    float hydrationLevel = 0.85f;
    float epicarpThicknessCm = 0.05f;
    float mesocarpThicknessCm = 0.05f;

    struct Seed 
    {
        float weightGrams = 0.5f;
        float coatIntegrity = 1.0f;
        int germinationDays = 14;
        float storedEnergy = 1.0f;
        int daysDormant = 0;

        bool growRoot(bool germinated = false);
        bool growStem(bool germinated = false);
        int growLeaves(bool germinated = false, int numLeaves = 2);
    };

    void protectSeed(float increment);
    void disperseSeed(Seed seed, float distanceKm);
    float feedSeed(Seed seed, float energy);
};

struct Tree
{
    Roots roots;
    Trunk trunk;
    Branch branch;
    Leaf leaf;
    Fruit fruit;

    float produceLeaves(int numBranches);
    int produceFlowers(int numLeaves);
    void produceFruit(int numFlowers);
};
   
int main()
{
    std::cout << "good to go!" << std::endl;
}
