/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




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

        void updateValue (float newValue);
        void changeFont (std::string font = "Arial", int fontSize = 18);
        void changeColour (std::string color = "green");
    };

    ValueDisplay speedDisplay;
    ValueDisplay inclineDisplay;

    void rotateBelt (float speeedKph);
    void incline (float inclinationDegrees);
    void display (ValueDisplay displayValue);
};

void Treadmill::rotateBelt (float speedKph)
{
    currentSpeedKph = speedKph;    
}

void Treadmill::incline (float inclinationDegrees)
{
    currentInclinationDegrees = inclinationDegrees;
}

void Treadmill::display (ValueDisplay displayValue)
{
    std::cout << displayValue.name << ": " << displayValue.value << " " << displayValue.unit << std::endl;
}


struct Helicopter
{
    float altitude = 0.0f;
    float longitude = 0.0f;
    float latitude = 0.0f;
    int numMainRotorBlades = 4;
    int numSeats = 4;
    float fuelCapacityL = 550.0f;
    float maximumRangeKm = 650.0f;
    std::string colour = "white";

    void ascend (float speedKph, float timeInSeconds);
    void travel (float speedKph, float bearingRads, float distanceKm);
    void descend (float speedKph);
};

void Helicopter::ascend (float speedKph, float timeInSeconds)
{
    altitude += (speedKph / 3600) * timeInSeconds;
}

void Helicopter::travel (float speedKph, float bearingRads, float distanceKm)
{
    latitude += (speedKph / 3600) * distanceKm * bearingRads;
    longitude += (speedKph / 3600) * distanceKm * bearingRads;    
}

struct Cat
{
    std::string furPattern = "tabby";
    std::string furColour = "orange";
    std::string eyeColor = "green";
    char sex = 'M';
    int age = 3;

    bool hunt (std::string creature);
    void eat (float amountOfFoodKg);
    void purr (float volumeDb);
};

bool Cat::hunt (std::string creature)
{
    if (creature == "mouse")
        return true;
    
    if (creature == "bird")
        return true;
    
    return false;
}

void Cat::eat (float amountOfFoodKg)
{
    if (amountOfFoodKg > 0.0f)
        std::cout << "nom nom nom" << std::endl;
    else 
        std::cout << "meow" << std::endl;    
}

void Cat::purr (float volumeDb)
{
    if (volumeDb <= 0.0f)
    {
        std::cout << std::endl;
    }
    else if (volumeDb <= 50.0f)
    {
        std::cout << "purrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr" << std::endl;
    }
    else
    {
        std::cout << "PURRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;     
    }
}

struct Liquid
{
    double boilingPointC = 100.0;
    double freezingPointC = 0.0;
    double volumeL = 7;
    double viscocityCp = 0.89;
    double temperatureC = 18.0;
    
    void freeze();
    void boil();
    double evaporate(double surfaceArea);
};

void Liquid::freeze()
{
    temperatureC = freezingPointC;
}

void Liquid::boil()
{
    temperatureC = boilingPointC;
}

double Liquid::evaporate (double surfaceArea)
{
    return surfaceArea * viscocityCp * (temperatureC - freezingPointC);
}

struct Roots
{
    int primaryRoots = 1;
    int secondaryRoots = 1500;
    float totalVolumeL = 2600.0f;
    float totalLengthKm = 33.12f;
    float densityKgPerL = 0.0615f;
    float hydration = 0.5f;
    float energy = 0.5f;
    float nutrients = 0.5f;

    void absorbWater (float volumeL);
    void absorbNutrients (float volumeL);
    float storeEnergy (float newEnergy);
};

void Roots::absorbWater (float volumeL)
{
    hydration = hydration + (volumeL + densityKgPerL) / densityKgPerL;
}

void Roots::absorbNutrients (float volumeL)
{
    nutrients = nutrients + (volumeL + densityKgPerL) / densityKgPerL;
}

float Roots::storeEnergy (float newEnergy)
{
    energy = energy + newEnergy;
    
    return energy;
}

struct Trunk
{
    float barkThicknessCm = 1.5f;
    float sapwoodThicknessCm = 3.25f;
    float heartwoodThicknessCm = 18.614f;
    float pithRadiusCm = 0.21565f;
    float totalRadiusCm = 23.57965f;

    void transportWater (float volumeL);
    void transportNutrients (float volumeL);
    float resistWind (float speedKph);    
};

void Trunk::transportWater (float volumeL) 
{
    std::cout << "Trunk Transported " << volumeL << "L of water to brances." << std::endl;
}

void Trunk::transportNutrients (float volumeL)
{
    std::cout << "Trunk Transported " << volumeL << "L of nutrients to branches." << std::endl;
}

float Trunk::resistWind (float speedKph) 
{
    float integrity = totalRadiusCm / 25.0f;
    float factor = 1 - integrity;
    float windResistance = integrity * 0.8f;
    
    while (speedKph > 1.0f)
    {
        speedKph /= 2.0f;
    }
    
    if (windResistance < speedKph)
    {
        integrity -= factor;
        std::cout << "Wind force too high, trunk integrity reduced to " << integrity << std::endl;
        pithRadiusCm = pithRadiusCm * integrity;
        barkThicknessCm = barkThicknessCm * integrity;
        sapwoodThicknessCm = sapwoodThicknessCm * integrity;
        heartwoodThicknessCm = heartwoodThicknessCm * integrity;
        totalRadiusCm = pithRadiusCm + barkThicknessCm + sapwoodThicknessCm + heartwoodThicknessCm;
    } 
    else
    {
        std::cout << "Wind resisted, trunk integrity unchanged." << std::endl;
    }
    
    return integrity;
}

struct Branch
{
    float lengthCm = 12.0f;
    int childBranches = 5;
    int buds = 5;
    int leaves = 50;
    int age = 4;

    void supportLeaves (int maxLeaves);
    void transportWater (float volumeL);
    void transportNutrients (float volumeL);
};

void Branch::supportLeaves (int maxLeaves)
{
    if (maxLeaves > leaves)
        leaves = maxLeaves;
    else 
        leaves += 1;
}

void Branch::transportWater (float volumeL)
{
    std::cout << "Branch Transported " << volumeL << "L of water to leaves." << std::endl;
}

void Branch::transportNutrients (float volumeL)
{
    std::cout << "Branch Transported " << volumeL << "L of nutrients to leaves." << std::endl;
}

struct Leaf
{
    float lengthCm = 6.5f;
    float widthCm = 6.5f;
    std::string colour = "green";
    int veins = 16;
    float hydrationLevel = 0.85f;
    
    void grow();
    float photosynthesize (float sunlight);
    void changeColour (std::string newColour);
};

void Leaf::grow()
{
    lengthCm += 0.005f;
    widthCm += 0.004f;
    hydrationLevel -= 0.01f;
}

float Leaf::photosynthesize (float sunlight)
{
    if (sunlight > 0.0f)
    {
        float energy = sunlight * hydrationLevel;
        hydrationLevel -= 0.02f;
        return energy;
    }
    
    std::cout << "No sunlight detected." << std::endl;
    
    return 0.0f;
}

void Leaf::changeColour (std::string newColour)
{
    colour = newColour;
}

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

        bool growRoot (bool germinated = false);
        bool growStem (bool germinated = false);
        int growLeaves (bool germinated = false, int numLeaves = 2);
    };

    void protectSeed (float increment);
    void disperseSeed (Seed seed, float distanceKm);
    float feedSeed (Seed seed, float energy);
};

void Fruit::protectSeed (float increment)
{
    epicarpThicknessCm += increment;
    mesocarpThicknessCm += increment / 2.0f;
}

void Fruit::disperseSeed (Seed seed, float distanceKm)
{
    seed.daysDormant = 0;
    seed.germinationDays = 0;
    
    if (seeds > 0)
        seeds -= 1;
    
    seed.coatIntegrity -= distanceKm / 100.0f;
}

float Fruit::feedSeed (Seed seed, float energy)
{
    seed.storedEnergy += energy;
    
    return seed.storedEnergy;
}

struct Tree
{
    Roots roots;
    Trunk trunk;
    Branch branch;
    Leaf leaf;
    Fruit fruit;

    int produceLeaves (int numBranches);
    int produceFlowers (int numLeaves);
    void produceFruit (int numFlowers);
};

int produceLeaves (int numBranches)
{
    return numBranches * 15;
}

int produceFlowers (int numLeaves)
{
    return numLeaves / 3;
}

int main()
{
    Example::main();

    //add your code here
    
    std::cout << "good to go!" << std::endl;
}
