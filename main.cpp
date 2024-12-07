/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable that IS NOT initialized in-class
    float b { 2.f }; //a member variable that IS initialized in-class
    UDT() : a(0) { } // 'constructor-initializer-list' initializing the member that wasn't initialized in-class.
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //2) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()



struct Treadmill
{
    Treadmill (float weightAllowance = 150.0f);

    float currentSpeedKph = 0.0f;
    float currentInclinationDegrees = 0.0f;
    float totalDistanceSimulatedKm = 0.0f;
    float sessionDistanceSimulatedKm = 0.0f;
    float maximumWeightAllowanceKg;

    struct ValueDisplay
    {
        ValueDisplay (float val, std::string valName, std::string valUnit);

        std::string name = "";
        std::string unit = "";
        float value = 0.0f;
        std::string colour = "green";
        std::string font = "Arial";
        int fontSize = 12;

        void updateValue (float newValue);
        void changeFont (std::string newFont = "Arial", int newFontSize = 18);
        void changeColour (std::string newColor = "green");
    };

    ValueDisplay speedDisplay{ 0.0f, "speed", "km/h" };
    ValueDisplay inclineDisplay{ 0.0f, "incline", "degrees" };

    void rotateBelt (float speeedKph);
    void incline (float inclinationDegrees);
    void display (ValueDisplay displayValue);
};

Treadmill::Treadmill (float weightAllowance)
{
    maximumWeightAllowanceKg = weightAllowance;
    inclineDisplay.colour = "red";
    std::cout << "A Treadmill has been constructed!" << std::endl;
}

void Treadmill::rotateBelt (float speedKph)
{
    std::cout << "Current Session distance: " << sessionDistanceSimulatedKm << " km!" << std::endl;
    currentSpeedKph = speedKph;
    speedDisplay.updateValue (currentSpeedKph);
    std::cout << "Away we go (at " << currentSpeedKph << " km/h)!" << std::endl;
}

void Treadmill::incline (float inclinationDegrees)
{
    currentInclinationDegrees = inclinationDegrees;
    inclineDisplay.updateValue (currentInclinationDegrees);
    std::cout << "Prepare to climb!" << std::endl;
}

void Treadmill::display (ValueDisplay displayValue)
{
    std::cout << displayValue.name << ": " << displayValue.value << " " << displayValue.unit << std::endl;
}


Treadmill::ValueDisplay::ValueDisplay (float val, std::string valName, std::string valUnit)
{
    value = val;
    name = valName;
    unit = valUnit;
    std::cout << "A ValueDisplay has been constructed!" << std::endl;
}

void Treadmill::ValueDisplay::updateValue (float newValue)
{
    std::cout << "Changing " << name << " from " << value << " to " << newValue << " " << unit << std::endl;
    value = newValue;    
}

void Treadmill::ValueDisplay::changeFont (std::string newFont, int newFontSize)
{
    std::cout << "Changing font from " << font << " " << fontSize << "pt to " << newFont << " " << newFontSize << "pt" << std::endl;
    font = newFont;
    fontSize = newFontSize;
}

void Treadmill::ValueDisplay::changeColour (std::string newColor)
{
    colour = newColor;
}


struct Helicopter
{
    Helicopter (int numSeats = 4, int numRotors = 4, float fuelCapacity = 550.0f, float maxRange = 650.0f);

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
    altitude += (speedKph / 3600) * timeInSeconds * 1000 * 3;
    std::cout << "Ascending to " << altitude << " feet" << std::endl;
}

void Helicopter::descend (float speedKph, float timeInSeconds)
{
    altitude -= (speedKph / 3600) * timeInSeconds * 1000 * 3;
    std::cout << "Descending to " << altitude << " feet" << std::endl;
}

void Helicopter::travel (float speedKph, float bearingRads, float distanceKm)
{
    std::cout << "Travelling from: " << longitude << " long, " << latitude << " lat" << std::endl;
    latitude += (speedKph / 3600) * distanceKm * bearingRads;
    longitude += (speedKph / 3600) * distanceKm * bearingRads;
}


struct Cat
{
    Cat (std::string pattern, std::string colour);

    std::string furPattern = "tabby";
    std::string furColour = "orange";
    std::string eyeColour = "green";
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
    std::cout << "The " << eyeColour << "-eyed cat is hunting a " << creature << "!" << std::endl;

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
    double evaporate (double surfaceArea);
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
    std::cout << volumeL << "L of liquid became solid." << std::endl;
}

void Liquid::boil()
{
    temperatureC = boilingPointC;
    std::cout << "Bubbly" << std::endl;
}

double Liquid::evaporate (double surfaceArea)
{
    std::cout << "**POOF**" << std::endl;
    return surfaceArea * viscocityCp * (temperatureC - boilingPointC);
}


struct Roots
{
    Roots();

    int primaryRoots;
    int secondaryRoots;
    float totalVolumeL;
    float totalLengthKm;
    float densityKgPerL;
    float hydration;
    float energy;
    float nutrients;

    void absorbWater (float volumeL);
    void absorbNutrients (float volumeL);
    float storeEnergy (float newEnergy);
};

Roots::Roots() :
    primaryRoots (1),
    secondaryRoots (1500),
    totalVolumeL (2600.0f),
    totalLengthKm (33.12f),
    densityKgPerL (0.0615f),
    hydration (0.5f),
    energy (0.5f),
    nutrients (0.5f)
{
    std::cout << "Roots have been constructed!" << std::endl;
}

void Roots::absorbWater (float volumeL)
{
    hydration = hydration + (volumeL + densityKgPerL) / densityKgPerL;
    std::cout << totalVolumeL << "L of roots have been hydrated" << std::endl;
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
    std::cout << totalRadiusCm * 2 << "cm trunk integrity: " << integrity << std::endl;

    while (speedKph > 1.0f)
    {
        speedKph /= 2.0f;
    }
        
    float windResistance = integrity * 0.8f;

    if (windResistance < speedKph)
    {
        integrity -= (1 - integrity);
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
    int childBranches = 0;
    int buds = 0;
    int leaves = 0;
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

    std::cout << age << " year old branch supports " << leaves << " leaves." << std::endl;
}

void Branch::transportWater (float volumeL)
{
    std::cout << "Branch Transported " << volumeL << "L of water to " << leaves << " leaves." << std::endl;
}

void Branch::transportNutrients (float volumeL)
{
    std::cout << "Branch Transported " << volumeL << "L of nutrients to " << leaves << " leaves." << std::endl;
}


struct Leaf
{
    Leaf();

    float lengthCm;
    float widthCm;
    std::string colour;
    int veins;
    float hydrationLevel;

    void grow();
    float photosynthesize (float sunlight);
    void changeColour (std::string newColour);
};

Leaf::Leaf() :
    lengthCm (0.5f),
    widthCm (0.5f),
    colour ("green"),
    veins (5),
    hydrationLevel (0.85f)
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
    std::cout << "Leaf changing from " << colour << " to " << newColour << std::endl;
    colour = newColour;    
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
    std::cout << "Hydration level: " << hydrationLevel << std::endl;
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
        std::cout << "Coat Integrity: " << coatIntegrity << std::endl;
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
         std::cout << "Coat Integrity: " << coatIntegrity << std::endl;
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
         std::cout << "Coat Integrity: " << coatIntegrity << std::endl;
        if (coatIntegrity < 0.25f)
        {
            storedEnergy -= 0.04f;
            coatIntegrity = 0;
            totalLeaves += numLeaves;
            std::cout << totalLeaves << " leaves are growing!" << std::endl;
        }

        coatIntegrity -= 0.02f;
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

Tree::Tree (float barkCm, float sapwoodCm, float heartwoodCm, float pithCm, float branchLength) :
    trunk (barkCm, sapwoodCm, heartwoodCm, pithCm),
    branch (branchLength)
{
    std::cout << "A Tree has been constructed!" << std::endl;
}

int Tree::produceLeaves (int numBranches)
{
    std::cout << "Tree has a branch length of " << branch.lengthCm << " cm with " << branch.leaves << " leaves." << std::endl;
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
    std::cout << std::endl;

    Treadmill::ValueDisplay maxWeightDisplay{ 200.0f, "max weight", "kg" };
    maxWeightDisplay.changeFont ("Times New Roman", 24);
    maxWeightDisplay.changeColour ("Blue");
    std::cout << maxWeightDisplay.name << " (" << maxWeightDisplay.font << ", " << maxWeightDisplay.fontSize << "pt, " << maxWeightDisplay.colour << "): " << maxWeightDisplay.value << " " << maxWeightDisplay.unit << std::endl;

    std::cout << std::endl;

    maxWeightDisplay.changeColour ("Orange");
    maxWeightDisplay.updateValue (250.0f);
    maxWeightDisplay.changeFont ("Helvetica", 18);

    std::cout << std::endl;

    Treadmill treadmill{ maxWeightDisplay.value };
    std::cout << "Treadmill: maximumWeightAllowanceKg: " << treadmill.maximumWeightAllowanceKg << std::endl;
    std::cout << "Treadmill: currentSpeedKph: " << treadmill.currentSpeedKph << std::endl;
    std::cout << "Treadmill: currentInclinationDegrees: " << treadmill.currentInclinationDegrees << std::endl;
    std::cout << "Treadmill: totalDistanceSimulatedKm: " << treadmill.totalDistanceSimulatedKm << std::endl;
    std::cout << "Treadmill: sessionDistanceSimulatedKm: " << treadmill.sessionDistanceSimulatedKm << std::endl;

    std::cout << std::endl;

    treadmill.rotateBelt (10.0f);
    treadmill.incline (5.0f);
    treadmill.display (treadmill.speedDisplay);
    treadmill.display (treadmill.inclineDisplay);
    treadmill.display (maxWeightDisplay);

    std::cout << std::endl;

    Helicopter helicopter{ 6, 2, 1000.0f, 800.0f };
    std::cout << "Helicopter: altitude: " << helicopter.altitude << std::endl;
    std::cout << "Helicopter: longitude: " << helicopter.longitude << std::endl;
    std::cout << "Helicopter: latitude: " << helicopter.latitude << std::endl;
    std::cout << "Helicopter: numMainRotorBlades: " << helicopter.numMainRotorBlades << std::endl;
    std::cout << "Helicopter: numSeats: " << helicopter.numSeats << std::endl;
    std::cout << "Helicopter: fuelCapacityL: " << helicopter.fuelCapacityL << std::endl;
    std::cout << "Helicopter: maximumRangeKm: " << helicopter.maximumRangeKm << std::endl;
    std::cout << "Helicopter: colour: " << helicopter.colour << std::endl;

    std::cout << std::endl;

    helicopter.ascend (100.0f, 90.0f);
    helicopter.travel (200.0f, 1.0f, 100.0f);
    helicopter.descend (100.0f, 70.0f);

    std::cout << std::endl;

    Cat tuxedoCat{ "tuxedo", "black" };
    std::cout << "Cat: furPattern: " << tuxedoCat.furPattern << std::endl;
    std::cout << "Cat: furColour: " << tuxedoCat.furColour << std::endl;
    std::cout << "Cat: eyeColour: " << tuxedoCat.eyeColour << std::endl;
    std::cout << "Cat: age: " << tuxedoCat.age << std::endl;
    std::cout << "Cat: sex: " << tuxedoCat.sex << std::endl;

    std::cout << std::endl;

    if (tuxedoCat.hunt ("mouse"))
        std::cout << "The cat caught the mouse!" << std::endl;

    if (!tuxedoCat.hunt ("red dot"))
        std::cout << "The cat is still chasing the red dot." << std::endl;

    tuxedoCat.eat (0.5f);
    tuxedoCat.purr (50.0f);

    std::cout << std::endl;

    Liquid water{ 100.0, 0.0, 0.89 };
    std::cout << "Liquid: boilingPointC: " << water.boilingPointC << std::endl;
    std::cout << "Liquid: freezingPointC: " << water.freezingPointC << std::endl;
    std::cout << "Liquid: volumeL: " << water.volumeL << std::endl;
    std::cout << "Liquid: viscocityCp: " << water.viscocityCp << std::endl;
    std::cout << "Liquid: temperatureC: " << water.temperatureC << std::endl;

    std::cout << std::endl;

    water.freeze();
    water.boil();
    std::cout << std::endl << water.evaporate (13.0) << " L of water remain." << std::endl;

    std::cout << std::endl;

    Roots roots;
    std::cout << "Roots: primaryRoots: " << roots.primaryRoots << std::endl;
    std::cout << "Roots: secondaryRoots: " << roots.secondaryRoots << std::endl;
    std::cout << "Roots: totalVolumeL: " << roots.totalVolumeL << std::endl;
    std::cout << "Roots: totalLengthKm: " << roots.totalLengthKm << std::endl;
    std::cout << "Roots: densityKgPerL: " << roots.densityKgPerL << std::endl;
    std::cout << "Roots: hydration: " << roots.hydration << std::endl;
    std::cout << "Roots: energy: " << roots.energy << std::endl;
    std::cout << "Roots: nutrients: " << roots.nutrients << std::endl;

    std::cout << std::endl;

    roots.absorbWater (10.0f);
    roots.absorbNutrients (5.0f);
    std::cout << std::endl << roots.storeEnergy (0.5f) << " total energy stored." << std::endl;
    std::cout << std::endl << roots.storeEnergy (0.5f) << " total energy stored." << std::endl;

    std::cout << std::endl;

    Trunk trunk{ 2.0f, 4.0f, 20.0f, 0.5f };
    std::cout << "Trunk: barkThicknessCm: " << trunk.barkThicknessCm << std::endl;
    std::cout << "Trunk: sapwoodThicknessCm: " << trunk.sapwoodThicknessCm << std::endl;
    std::cout << "Trunk: heartwoodThicknessCm: " << trunk.heartwoodThicknessCm << std::endl;
    std::cout << "Trunk: pithRadiusCm: " << trunk.pithRadiusCm << std::endl;
    std::cout << "Trunk: totalRadiusCm: " << trunk.totalRadiusCm << std::endl;

    std::cout << std::endl;

    trunk.transportWater (10.0f);
    trunk.transportNutrients (5.0f);
    std::cout << std::endl << trunk.resistWind (50.0f) << " remaining trunk integrity." << std::endl;

    std::cout << std::endl;

    Branch branch{ 10.0f };
    std::cout << "Branch: lengthCm: " << branch.lengthCm << std::endl;
    std::cout << "Branch: childBranches: " << branch.childBranches << std::endl;
    std::cout << "Branch: buds: " << branch.buds << std::endl;
    std::cout << "Branch: leaves: " << branch.leaves << std::endl;
    std::cout << "Branch: age: " << branch.age << std::endl;

    std::cout << std::endl;

    branch.supportLeaves (20);
    branch.transportWater (5.0f);
    branch.transportNutrients (2.5f);

    std::cout << std::endl;

    Leaf leaf;
    std::cout << "Leaf: lengthCm: " << leaf.lengthCm << std::endl;
    std::cout << "Leaf: widthCm: " << leaf.widthCm << std::endl;
    std::cout << "Leaf: colour: " << leaf.colour << std::endl;
    std::cout << "Leaf: veins: " << leaf.veins << std::endl;
    std::cout << "Leaf: hydrationLevel: " << leaf.hydrationLevel << std::endl;

    std::cout << std::endl;

    leaf.grow();
    std::cout << std::endl << leaf.photosynthesize (100.0f) << " energy produced." << std::endl;
    leaf.changeColour ("red");

    std::cout << std::endl;

    Fruit fruit;
    std::cout << "Fruit: endospermLevel: " << fruit.endospermLevel << std::endl;
    std::cout << "Fruit: hydrationLevel: " << fruit.hydrationLevel << std::endl;
    std::cout << "Fruit: epicarpThicknessCm: " << fruit.epicarpThicknessCm << std::endl;
    std::cout << "Fruit: mesocarpThicknessCm: " << fruit.mesocarpThicknessCm << std::endl;

    std::cout << std::endl;

    fruit.protectSeed (0.1f);
    std::cout << std::endl << fruit.feedSeed (0.5f) << " total energy stored." << std::endl;

    std::cout << std::endl;

    Fruit::Seed newSeed = fruit.disperseSeed (10.0f);
    std::cout << "Seed: weightGrams: " << newSeed.weightGrams << std::endl;
    std::cout << "Seed: coatIntegrity: " << newSeed.coatIntegrity << std::endl;
    std::cout << "Seed: germinationDays: " << newSeed.germinationDays << std::endl;
    std::cout << "Seed: storedEnergy: " << newSeed.storedEnergy << std::endl;
    std::cout << "Seed: daysDormant: " << newSeed.daysDormant << std::endl;
    std::cout << "Seed: totalLeaves: " << newSeed.totalLeaves << std::endl;

    std::cout << std::endl;

    Tree tree{ 2.0f, 4.0f, 20.0f, 0.5f, 10.0f };
    std::cout << std::endl << tree.produceLeaves (5) << " leaves produced." << std::endl;
    std::cout << std::endl << tree.produceFlowers (15) << " flowers produced." << std::endl;
    tree.produceFruit (5);

    tree.fruit.seed.growRoot (false);
    tree.fruit.seed.growStem (false);
    tree.fruit.seed.growLeaves (false, 10);

    std::cout << std::endl;

    Fruit::Seed seed;
    std::cout << "Seed: weightGrams: " << seed.weightGrams << std::endl;
    std::cout << "Seed: coatIntegrity: " << seed.coatIntegrity << std::endl;
    std::cout << "Seed: germinationDays: " << seed.germinationDays << std::endl;
    std::cout << "Seed: storedEnergy: " << seed.storedEnergy << std::endl;
    std::cout << "Seed: daysDormant: " << seed.daysDormant << std::endl;
    std::cout << "Seed: totalLeaves: " << seed.totalLeaves << std::endl;

    std::cout << std::endl;

    while (!seed.growRoot (true))
    {
        std::cout << "Seed root is not yet ready." << std::endl;
        std::cout << "Time passes..." << std::endl;
    }

    while (!seed.growStem (true))
    {
        std::cout << "Seed stem is not yet ready." << std::endl;
        std::cout << "Time passes..." << std::endl;
    }

    while (seed.growLeaves (true, 10) < 10)
    {
        std::cout << "Seed leaves are not yet ready." << std::endl;
        std::cout << "Time passes..." << std::endl;
    }

    seed.growLeaves (true, 10);

    std::cout << std::endl;

    std::cout << "good to go!" << std::endl;
}
