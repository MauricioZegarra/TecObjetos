#include <iostream>
#include <string>
using namespace std;

class Recipe {
protected:
    string name;
    string ingredients;
public:
    virtual void prepare() = 0;
    virtual void cook() = 0;
    virtual void serve() = 0;
};

class ItalianRecipe : public Recipe {
public:
    ItalianRecipe() { name = "Pasta"; ingredients = "Tomato, Basil, Cheese"; }
    void prepare() { cout << "Preparing Italian Recipe: " << name << endl; }
    void cook() { cout << "Cooking with: " << ingredients << endl; }
    void serve() { cout << "Serving " << name << endl; }
};

class MexicanRecipe : public Recipe {
public:
    MexicanRecipe() { name = "Tacos"; ingredients = "Tortilla, Beef, Cheese"; }
    void prepare() { cout << "Preparing Mexican Recipe: " << name << endl; }
    void cook() { cout << "Cooking with: " << ingredients << endl; }
    void serve() { cout << "Serving " << name << endl; }
};

class RecipeFactory {
public:
    static Recipe* createRecipe(int type) {
        switch (type) {
            case 1: return new ItalianRecipe();
            case 2: return new MexicanRecipe();
            default: return nullptr;
        }
    }
};

int main() {
    int type;
    cout << "Enter recipe type (1 for Italian, 2 for Mexican): ";
    cin >> type;
    Recipe *recipe = RecipeFactory::createRecipe(type);
    if (recipe) {
        recipe->prepare();
        recipe->cook();
        recipe->serve();
        delete recipe;
    } else {
        cout << "Invalid recipe type!" << endl;
    }
    return 0;
}
