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
    Treadmill (int weightAllowance = 150);

    float currentSpeedKph = 0.0f;
    float currentInclinationDegrees = 0.0f;
    float totalDistanceSimulatedKm = 0.0f;
    float sessionDistanceSimulatedKm = 0.0f;
    int maximumWeightAllowanceKg;

    struct ValueDisplay
    {
        ValueDisplay();

        std::string name = "speed";
        std::string unit = "km/h";
        float value = 0.0f;
        std::string colour = "green";
        std::string font = "Arial";
        int fontSize = 12;

        void updateValue (float newValue);
        void changeFont (std::string newFont = "Arial", int newFontSize = 18);
        void changeColour (std::string newColor = "green");
    };

    ValueDisplay speedDisplay;
    ValueDisplay inclineDisplay;

    void rotateBelt (float speeedKph);
    void incline (float inclinationDegrees);
    void display (ValueDisplay displayValue);
};

Treadmill::Treadmill (int weightAllowance)
{
    maximumWeightAllowanceKg = weightAllowance;
    speedDisplay.name = "speed";
    speedDisplay.unit = "km/h";
    inclineDisplay.name = "incline";
    inclineDisplay.unit = "degrees";    
    inclineDisplay.colour = "red";    
    std::cout << "A Treadmill has been constructed!" << std::endl;
}

void Treadmill::rotateBelt (float speedKph)
{
    currentSpeedKph = speedKph;
    std::cout << "Away we go (at " << currentSpeedKph << " km/h)!" << std::endl;
}

void Treadmill::incline (float inclinationDegrees)
{
    currentInclinationDegrees = inclinationDegrees;
    std::cout << "Prepare to climb!" << std::endl;
}

void Treadmill::display (ValueDisplay displayValue)
{
    std::cout << displayValue.name << ": " << displayValue.value << " " << displayValue.unit << std::endl;
}


Treadmill::ValueDisplay::ValueDisplay()
{    
    std::cout << "A ValueDisplay has been constructed!" << std::endl;
}

void Treadmill::ValueDisplay::updateValue (float newValue)
{
    value = newValue;
    std::cout << "New " << name << ": " << value << " " << unit << std::endl;
}

void Treadmill::ValueDisplay::changeFont (std::string newFont, int newFontSize)
{
    font = newFont;
    fontSize = newFontSize;
}

void Treadmill::ValueDisplay::changeColour (std::string newColor)
{
    colour = newColor;
}


struct Helicopter
{
    Helicopter (int numSeats, int numRotors, float fuelCapacity, float maxRange);

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
    void descend (float speedKph, float timeInSeconds);
};

Helicopter::Helicopter (int seats, int rotors, float fuelCapacity, float maxRange)
{
    numSeats = seats;
    numMainRotorBlades = rotors;
    fuelCapacityL = fuelCapacity;
    maximumRangeKm = maxRange;
    colour = "Always Blue";
    std::cout << "A Helicopter has been constructed!" << std::endl;
}

void Helicopter::ascend (float speedKph, float timeInSeconds)
{
    altitude += (speedKph / 3600) * timeInSeconds;
    std::cout << "Ascending to " << altitude << " feet";
}

void Helicopter::descend (float speedKph, float timeInSeconds)
{
    altitude += (speedKph / 3600) * timeInSeconds;
    std::cout << "Descending to " << altitude << " feet";
}

void Helicopter::travel (float speedKph, float bearingRads, float distanceKm)
{
    latitude += (speedKph / 3600) * distanceKm * bearingRads;
    longitude += (speedKph / 3600) * distanceKm * bearingRads;
}


struct Cat
{
    Cat (std::string pattern, std::string colour);

    std::string furPattern = "tabby";
    std::string furColour = "orange";
    std::string eyeColor = "green";
    char sex = 'F';
    int age = 3;

    bool hunt (std::string creature);
    void eat (float amountOfFoodKg);
    void purr (float volumeDb);
};

Cat::Cat (std::string pattern, std::string colour)
{
    furPattern = pattern;
    furColour = colour;
    std::cout << "A Cat has been constructed!" << std::endl;
}

bool Cat::hunt (std::string creature)
{
    std::cout << "The cat is hunting a " << creature << "!" << std::endl;    
    
    if (creature == "mouse")
    {
        std::cout << "The cat pounces and catches a mouse!" << std::endl;
        return true;
    }
    
    if (creature == "bird")
    {
        std::cout << "The cat leaps into the air, snagging a bird with its paw." << std::endl;
        return true;
    }

    std::cout << "The cat chases the " << creature << ", but is unable to catch it." << std::endl;
    
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
    Liquid (double boilingPoint, double freezingPoint, double viscocity);

    double boilingPointC = 100.0;
    double freezingPointC = 0.0;
    double volumeL = 7;
    double viscocityCp = 0.89;
    double temperatureC = 18.0;
    
    void freeze();
    void boil();
    double evaporate(double surfaceArea);
};

Liquid::Liquid (double boilingPoint, double freezingPoint, double viscocity)
{
    boilingPointC = boilingPoint;
    freezingPointC = freezingPoint;
    viscocityCp = viscocity;
    std::cout << "A Liquid has been constructed!" << std::endl;
}

void Liquid::freeze()
{
    temperatureC = freezingPointC;
    std::cout << "Brrrrrrr" << std::endl;
}

void Liquid::boil()
{
    temperatureC = boilingPointC;
    std::cout << "Bubbly" << std::endl;
}

double Liquid::evaporate (double surfaceArea)
{
    std::cout << "**POOF**" << std::endl;
    return surfaceArea * viscocityCp * (temperatureC - freezingPointC);
}


struct Roots
{
    Roots();

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

Roots::Roots()
{
    std::cout << "Roots have been constructed!" << std::endl;
}

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
    std::cout << "Energy level increased to " << energy << std::endl;
    
    return energy;
}


struct Trunk
{
    Trunk (float barkCm, float sapwoodCm, float heartwoodCm, float pithCm);

    float barkThicknessCm = 1.5f;
    float sapwoodThicknessCm = 3.25f;
    float heartwoodThicknessCm = 18.614f;
    float pithRadiusCm = 0.21565f;
    float totalRadiusCm = 23.57965f;

    void transportWater (float volumeL);
    void transportNutrients (float volumeL);
    float resistWind (float speedKph);    
};

Trunk::Trunk (float barkCm, float sapwoodCm, float heartwoodCm, float pithCm)
{
    barkThicknessCm = barkCm;
    sapwoodThicknessCm = sapwoodCm;
    heartwoodThicknessCm = heartwoodCm;
    pithRadiusCm = pithCm;
    totalRadiusCm = barkThicknessCm + sapwoodThicknessCm + heartwoodThicknessCm + pithRadiusCm;
    std::cout << "A Trunk has been constructed!" << std::endl;
}

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
    Branch (float length);

    float lengthCm;
    int childBranches;
    int buds;
    int leaves;
    int age = 0;

    void supportLeaves (int maxLeaves);
    void transportWater (float volumeL);
    void transportNutrients (float volumeL);
};

Branch::Branch (float length)
{
    lengthCm = length;
    childBranches = 2;
    buds = childBranches;
    leaves = childBranches * buds;
    std::cout << "A Branch has been constructed!" << std::endl;
}

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
    Leaf();

    float lengthCm = 0.5f;
    float widthCm = 0.5f;
    std::string colour = "green";
    int veins = 5;
    float hydrationLevel = 0.85f;
    
    void grow();
    float photosynthesize (float sunlight);
    void changeColour (std::string newColour);
};

Leaf::Leaf()
{
    std::cout << "A Leaf has been constructed!" << std::endl;
}

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
        std::cout << "A leaf photosynthesized." << std::endl;
        
        return energy;
    }
    
    std::cout << "No sunlight detected." << std::endl;
    
    return 0.0f;
}

void Leaf::changeColour (std::string newColour)
{
    colour = newColour;
    std::cout << "Leaf is now " << colour << "." << std::endl;
}


struct Fruit
{
    Fruit();

    float endospermLevel = 0.05f;
    float hydrationLevel = 0.05f;
    float epicarpThicknessCm = 0.05f;
    float mesocarpThicknessCm = 0.05f;

    struct Seed 
    {
        Seed();

        float weightGrams = 0.05f;
        float coatIntegrity = 1.0f;
        int germinationDays = 0;
        float storedEnergy = 0.0f;
        int daysDormant = 0;
        int totalLeaves = 0;

        bool growRoot (bool germinated = false);
        bool growStem (bool germinated = false);
        int growLeaves (bool germinated = false, int numLeaves = 2);
    };

    Seed seed;

    void protectSeed (float increment);
    Seed disperseSeed (float distanceKm);
    float feedSeed (float energy);
};

Fruit::Fruit()
{
    std::cout << "A Fruit has been constructed!" << std::endl;
}

void Fruit::protectSeed (float increment)
{
    epicarpThicknessCm += increment;
    mesocarpThicknessCm += increment / 2.0f;
    seed.weightGrams += increment / 10.0f;
}

Fruit::Seed Fruit::disperseSeed (float distanceKm)
{
    seed.daysDormant = 0;
    seed.germinationDays = 0;
    seed.coatIntegrity -= distanceKm / 100.0f;

    return seed;
}

float Fruit::feedSeed (float energy)
{
    seed.storedEnergy += energy;
    
    return seed.storedEnergy;
}


Fruit::Seed::Seed()
{
    std::cout << "A Seed has been constructed!" << std::endl;
}

bool Fruit::Seed::growRoot (bool germinated)
{
    if (germinated)
    {
        if (coatIntegrity < 0.75f)
        {
            storedEnergy -= 0.04f;
            coatIntegrity -= 0.05f;
            std::cout << "Root grows!" << std::endl;
            
            return true;
        }

        coatIntegrity -= 0.03f;
    }

    return false;
}

bool Fruit::Seed::growStem (bool germinated)
{
    if (germinated)
    {
        if (coatIntegrity < 0.5f)
        {
            storedEnergy -= 0.07f;
            coatIntegrity -= 0.075f;
            std::cout << "Stem grows!" << std::endl;

            return true;
        }

        coatIntegrity -= 0.04f;
    }

    return false;
}

int Fruit::Seed::growLeaves (bool germinated, int numLeaves)
{
    if (germinated)
    {
        if (coatIntegrity < 0.25f)
        {
            storedEnergy -= 0.04f;
            coatIntegrity = 0;
            totalLeaves += numLeaves;
            std::cout << totalLeaves << " leaves are growing!" << std::endl;
        }
    }

    return totalLeaves;
}


struct Tree
{
    Tree (float barkCm, float sapwoodCm, float heartwoodCm, float pithCm, float branchLength);

    Roots roots;
    Trunk trunk;
    Branch branch;
    Leaf leaf;
    Fruit fruit;

    int produceLeaves (int numBranches);
    int produceFlowers (int numLeaves);
    void produceFruit (int numFlowers);
};

Tree::Tree(float barkCm, float sapwoodCm, float heartwoodCm, float pithCm, float branchLength) 
    : 
    trunk (barkCm, sapwoodCm, heartwoodCm, pithCm), 
    branch (branchLength)
{
    std::cout << "A Tree has been constructed!" << std::endl;
}

int Tree::produceLeaves (int numBranches)
{
    return numBranches * 15;
}

int Tree::produceFlowers (int numLeaves)
{
    std::cout << "Pretty" << std::endl;
    return numLeaves / 3;
}

void Tree::produceFruit (int numFlowers)
{
    for (int i = 0; i < numFlowers; ++i)
    {
        std::cout << "Fruit produced!" << std::endl;
    }
}


int main()
{
    Example::main();

    //add your code here
    
    std::cout << "good to go!" << std::endl;
}
