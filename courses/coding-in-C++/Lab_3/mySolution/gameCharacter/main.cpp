#include "character.hpp"
#include "Item.hpp"
#include "subCharacters.hpp"
#include "weapon.hpp"

int main() {
    std::cout << "========== GAME CHARACTER SYSTEM TEST ==========" << std::endl << std::endl;


    // Create different character types as specified in Lab 3 Section IV
    std::cout << "=== Creating Characters ===" << std::endl;

    // Warrior with weapon skill points
    Warrior warrior("Aragorn", 3, 120, 50);
    std::cout << "Created Warrior: " << warrior.getName() << std::endl;

    // Mage with mana points
    Mage mage("Gandalf", 5, 80, 100);
    std::cout << "Created Mage: " << mage.getName() << std::endl;

    // Healer (derived from Mage)
    Healer healer("Elrond", 4, 90, 80);
    std::cout << "Created Healer: " << healer.getName() << std::endl;

    // Thief (derived from Warrior)
    Thief thief("Bilbo", 2, 60, 30);
    std::cout << "Created Thief: " << thief.getName() << std::endl;

    std::cout << std::endl;

    // Test printStatus for all characters
    std::cout << "=== Character Status Display ===" << std::endl;
    warrior.printStatus();
    std::cout << std::endl;
    mage.printStatus();
    std::cout << std::endl;
    healer.printStatus();
    std::cout << std::endl;
    thief.printStatus();
    std::cout << std::endl;

    // Test method chaining and regeneration
    std::cout << "=== Testing Method Chaining and Regeneration ===" << std::endl;

    std::cout << "Warrior before regeneration:" << std::endl;
    warrior.printStatus();
    std::cout << std::endl;

    // Method chaining: levelUp, regenWeaponPoints, healthUp
    warrior.regenWeaponPoints(20).levelUp(1).healthUp(10);
    std::cout << "Warrior after chaining levelUp(1).regenWeaponPoints(20).healthUp(10):" << std::endl;
    warrior.printStatus();
    std::cout << std::endl;

    std::cout << "Mage before regeneration:" << std::endl;
    mage.printStatus();
    std::cout << std::endl;

    // Method chaining for Mage
    mage.regenManaPoints(50).levelUp(2).healthDown(15);
    std::cout << "Mage after chaining levelUp(2).regenManaPoints(50).healthDown(15):" << std::endl;
    mage.printStatus();
    std::cout << std::endl;

    // Test inventory management
    std::cout << "=== Testing Inventory Management ===" << std::endl;

    // Create some items
    Item potion("Health Potion", "Consumable");
    Item sword("Iron Sword", "Weapon");
    Item shield("Wooden Shield", "Armor");
    Item gold("Gold Coin", "Currency");

    std::cout << "Adding items to Warrior's inventory..." << std::endl;
    warrior.addItemToInventory(&potion);
    warrior.addItemToInventory(&sword);
    warrior.addItemToInventory(&shield);

    std::cout << "Warrior inventory slots used: " << warrior.getNumOfUsedSlots() << "/10" << std::endl;
    std::cout << "Item at index 0: " << warrior.getItemfromInventory(0)->getName() << std::endl;
    std::cout << "Item at index 1: " << warrior.getItemfromInventory(1)->getName() << std::endl;
    std::cout << "Item at index 2: " << warrior.getItemfromInventory(2)->getName() << std::endl;
    std::cout << std::endl;

    // Test Healer's healing ability (friend class access)
    std::cout << "=== Testing Healer's Healing Ability ===" << std::endl;

    std::cout << "Warrior health before healing: (checking via printStatus)" << std::endl;
    warrior.printStatus();
    std::cout << std::endl;

    std::cout << "Mage health before healing:" << std::endl;
    mage.printStatus();
    std::cout << std::endl;

    // Healer heals Warrior
    healer.heal(warrior);
    std::cout << "Healer healed Warrior:" << std::endl;
    warrior.printStatus();
    std::cout << std::endl;

    // Healer heals Mage
    healer.heal(mage);
    std::cout << "Healer healed Mage:" << std::endl;
    mage.printStatus();
    std::cout << std::endl;

    // Test Thief's stealing ability
    std::cout << "=== Testing Thief's Stealing Ability ===" << std::endl;

    std::cout << "Thief inventory before stealing: " << thief.getNumOfUsedSlots() << "/10 slots" << std::endl;
    std::cout << "Warrior inventory before stealing: " << warrior.getNumOfUsedSlots() << "/10 slots" << std::endl;

    // Thief steals from Warrior (steal method should use public inventory methods)
    thief.steal(warrior, 1);  // Steal item at index 0

    std::cout << "After thief steals from warrior:" << std::endl;
    std::cout << "Thief inventory: " << thief.getNumOfUsedSlots() << "/10 slots" << std::endl;
    std::cout << "Warrior inventory: " << warrior.getNumOfUsedSlots() << "/10 slots" << std::endl;

    if (thief.getNumOfUsedSlots() > 0) {
        std::cout << "Thief stole: " << thief.getItemfromInventory(0)->getName() << std::endl;
    }
    std::cout << std::endl;

    // Special task: Add all characters into one array and print levels
    std::cout << "=== Special Task: Character Array and Levels ===" << std::endl;

    // Create an array of Character pointers (polymorphism)
    Character* characters[4] = {&warrior, &mage, &healer, &thief};

    std::cout << "Character levels in array:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "Character " << i + 1 << " (" << characters[i]->getName() << ") Level: " << characters[i]->getLevel() << std::endl;
    }
    std::cout << std::endl;

    // Test weapon functionality (if implemented)
    std::cout << "=== Testing Weapon Functionality ===" << std::endl;

    // Create a weapon
    Weapon excalibur("Excalibur", 75);
    warrior.addItemToInventory(&excalibur);

    std::cout << "Warrior added Excalibur to inventory" << std::endl;
    std::cout << "Warrior has weapon: " << (warrior.getWeaponFromInventory() != nullptr ? "Yes" : "No") << std::endl;

    if (warrior.getWeaponFromInventory()) {
        std::cout << "Weapon name: " << warrior.getWeaponFromInventory()->getName() << std::endl;
    }
    std::cout << std::endl;

    // Final status display
    std::cout << "=== Final Character Status ===" << std::endl;
    warrior.printStatus();
    std::cout << std::endl;
    mage.printStatus();
    std::cout << std::endl;
    healer.printStatus();
    std::cout << std::endl;
    thief.printStatus();
    std::cout << std::endl;

    std::cout << "========== END OF GAME CHARACTER SYSTEM TEST ==========" << std::endl;

    return 0;
}
