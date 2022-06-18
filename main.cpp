#include "ingridients.h"
#include <iostream>

int main() {
        string file;
        cout << "Enter path or name of file >> ";
        cin >> file;
        IngridientBags ingridientBags;
        ingridientBags.fill(file);
        Combinator combinator(ingridientBags);
        combinator.show();
        system("Pause > null");
        return 0; 
}