#include "character.hpp"
#include "subCharacters.hpp"
#include "Item.hpp"
#include "weapon.hpp"
#include <iostream>

void printSeparator(const std::string& title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================" << std::endl;
}

void printSubSection(const std::string& title) {
    std::cout << "\n--- " << title << " ---" << std::endl;
}

int main() {

    // ============================================================
    // SECTION 1: CHARACTER CREATION (Inheritance Test)
    // ============================================================
    printSeparator("1. CHARACTER CREATION (Inheritance)");

    // Note: constructors no longer take hasWeapon - it defaults to false
    // Mage(name, level, healthPoints, manaSkill)
    // Warrior(name, level, healthPoints, weaponSkill)
    // Healer(name, level, healthPoints, manaSkill)   -> inherits Mage
    // Thief(name, level, healthPoints, weaponSkill)  -> inherits Warrior
    Mage    gandalf("Gandalf",  5, 100, 50);
    Warrior conan  ("Conan",    6, 150, 40);
    Healer  elara  ("Elara",    4,  80, 60);
    Thief   garrett("Garrett",  5, 120, 45);

    std::cout << "Created 4 characters: Mage, Warrior, Healer, Thief" << std::endl;

    // ============================================================
    // SECTION 2: BASE-CLASS METHODS (Character)
    // ============================================================
    printSeparator("2. BASE CLASS METHODS (Character)");

    printSubSection("getName() / getLevel()");
    std::cout << "Name:  " << gandalf.getName()  << std::endl;
    std::cout << "Level: " << gandalf.getLevel() << std::endl;

    printSubSection("levelUp(3) - with method chaining");
    gandalf.levelUp(3).levelUp(1);  // chained call -> +4 levels
    std::cout << "Level after levelUp(3).levelUp(1): " << gandalf.getLevel() << std::endl;

    printSubSection("levelDown(2)");
    gandalf.levelDown(2);
    std::cout << "Level after levelDown(2): " << gandalf.getLevel() << std::endl;

    printSubSection("healthUp(30) / healthDown(10) - with method chaining");
    gandalf.healthUp(30).healthDown(10);  // chained -> net +20
    std::cout << "(Health changes applied - see printStatus below)" << std::endl;

    // ============================================================
    // SECTION 3: INVENTORY MANAGEMENT
    // ============================================================
    printSeparator("3. INVENTORY MANAGEMENT");

    printSubSection("isInventoryFull() - empty inventory");
    std::cout << "Inventory full? " << (gandalf.isInventoryFull() ? "yes" : "no") << std::endl;

    printSubSection("addItemToInventory() - regular items");
    Item potion("Health Potion");
    Item scroll("Magic Scroll");
    Item gem   ("Ruby Gem");
    gandalf.addItemToInventory(&potion);
    gandalf.addItemToInventory(&scroll);
    gandalf.addItemToInventory(&gem);
    std::cout << "Added 3 items. Used slots: " << gandalf.getNumOfUsedSlots() << std::endl;

    printSubSection("addItemToInventory() - Weapon (hasWeapon flag)");
    Weapon staff("Wizard Staff", 25);
    gandalf.addItemToInventory(&staff);
    std::cout << "Added a weapon. Used slots: " << gandalf.getNumOfUsedSlots() << std::endl;

    printSubSection("addItemToInventory() - second Weapon (should fail)");
    Weapon wand("Magic Wand", 15);
    gandalf.addItemToInventory(&wand);   // expect: "Only one Weapon is allowed!"

    printSubSection("getItemfromInventory(index) - valid indices");
    std::cout << "Item at index 0: " << gandalf.getItemfromInventory(0)->getName() << std::endl;
    std::cout << "Item at index 1: " << gandalf.getItemfromInventory(1)->getName() << std::endl;
    std::cout << "Item at index 2: " << gandalf.getItemfromInventory(2)->getName() << std::endl;

    printSubSection("getItemfromInventory(index) - out-of-range index");
    Item* invalid = gandalf.getItemfromInventory(99);
    std::cout << "Item at index 99: " << (invalid == nullptr ? "nullptr (OK)" : "something") << std::endl;

    printSubSection("getWeaponFromInventory()");
    Item* weaponPtr = gandalf.getWeaponFromInventory();
    if (weaponPtr != nullptr) {
        std::cout << "Equipped weapon: " << weaponPtr->getName()
                  << " (Type: " << weaponPtr->getType() << ")" << std::endl;
    } else {
        std::cout << "No weapon equipped." << std::endl;
    }

    printSubSection("getNumOfUsedSlots()");
    std::cout << "Used slots: " << gandalf.getNumOfUsedSlots() << "/10" << std::endl;

    // ============================================================
    // SECTION 4: VIRTUAL METHOD - printStatus()
    // ============================================================
    printSeparator("4. VIRTUAL METHOD printStatus() (Polymorphism)");

    printSubSection("Mage::printStatus()");
    gandalf.printStatus();

    printSubSection("Warrior::printStatus()");
    Weapon sword("Steel Sword", 35);
    conan.addItemToInventory(&sword);
    conan.printStatus();

    // ============================================================
    // SECTION 5: MAGE-SPECIFIC METHOD
    // ============================================================
    printSeparator("5. MAGE-SPECIFIC: regenManaPoints() (chained)");

    std::cout << "Gandalf regenerates mana twice (chained)..." << std::endl;
    gandalf.regenManaPoints(15).regenManaPoints(10);   // method chaining
    gandalf.printStatus();

    // ============================================================
    // SECTION 6: WARRIOR-SPECIFIC METHOD
    // ============================================================
    printSeparator("6. WARRIOR-SPECIFIC: regenWeaponPoints() (chained)");

    std::cout << "Conan trains his weapon skill twice (chained)..." << std::endl;
    conan.regenWeaponPoints(10).regenWeaponPoints(10);
    conan.printStatus();

    // ============================================================
    // SECTION 7: HEALER (Mage subclass) - friend access
    // ============================================================
    printSeparator("7. HEALER: heal() - using friend access (chained)");

    printSubSection("Healer heals another character (multiple times, chained)");
    std::cout << "Conan gets healed by Elara 3 times in a chain..." << std::endl;
    elara.heal(conan).heal(conan).heal(conan);

    printSubSection("Healer heals himself");
    std::cout << "Elara heals herself..." << std::endl;
    elara.heal(elara);

    printSubSection("Healer status (inherits Mage::printStatus)");
    elara.printStatus();

    // ============================================================
    // SECTION 8: changeWeaponStatus()
    // ============================================================
    printSeparator("8. changeWeaponStatus() - manual flag toggle");

    Mage flagMage("FlagTester", 1, 50, 10);
    Weapon dagger1("Dagger A", 10);
    flagMage.addItemToInventory(&dagger1);
    std::cout << "Added 1st weapon - hasWeapon flag set internally." << std::endl;

    // Reset flag manually so we can add another weapon
    flagMage.changeWeaponStatus(false);
    std::cout << "Manually reset flag via changeWeaponStatus(false)." << std::endl;

    Weapon dagger2("Dagger B", 12);
    flagMage.addItemToInventory(&dagger2);
    std::cout << "Used slots after adding 2nd weapon: "
              << flagMage.getNumOfUsedSlots() << std::endl;

    // ============================================================
    // SECTION 9: removeItemfromInventory(index)
    // ============================================================
    printSeparator("9. removeItemfromInventory(int index)");

    Mage rmMage("RemovalTester", 1, 50, 10);
    Item itemA("Item-A");
    Item itemB("Item-B");
    Item itemC("Item-C");
    rmMage.addItemToInventory(&itemA);
    rmMage.addItemToInventory(&itemB);
    rmMage.addItemToInventory(&itemC);
    std::cout << "Inventory before remove: " << rmMage.getNumOfUsedSlots() << " items" << std::endl;

    printSubSection("Remove valid index (1)");
    Item* removed = rmMage.removeItemfromInventory(1);
    if (removed != nullptr) {
        std::cout << "Removed: " << removed->getName() << std::endl;
    }
    std::cout << "Inventory after remove: " << rmMage.getNumOfUsedSlots() << " items" << std::endl;

    printSubSection("Remove from empty slot");
    Item* nothing = rmMage.removeItemfromInventory(1);   // already empty
    std::cout << "Result: " << (nothing == nullptr ? "nullptr (OK)" : "unexpected") << std::endl;

    printSubSection("Remove from invalid index (99)");
    Item* outOfRange = rmMage.removeItemfromInventory(99);
    std::cout << "Result: " << (outOfRange == nullptr ? "nullptr (OK)" : "unexpected") << std::endl;

    // ============================================================
    // SECTION 10: THIEF (Warrior subclass) - steal()
    // ============================================================
    printSeparator("10. THIEF: steal() from other characters");

    // Give Conan some items so the thief has something to steal
    Item gold("Gold Coin");
    Item map_("Treasure Map");
    conan.addItemToInventory(&gold);
    conan.addItemToInventory(&map_);
    std::cout << "Conan now has " << conan.getNumOfUsedSlots() << " items." << std::endl;
    std::cout << "Garrett has " << garrett.getNumOfUsedSlots() << " items (empty)." << std::endl;

    printSubSection("Successful steal (thief skill > target level)");
    // Garrett's weaponSkill (45) > Conan's level (6) -> should succeed
    int conanItemsBefore   = conan.getNumOfUsedSlots();
    int garrettItemsBefore = garrett.getNumOfUsedSlots();
    garrett.steal(conan, 0);
    std::cout << "Conan   items: " << conanItemsBefore   << " -> " << conan.getNumOfUsedSlots()   << std::endl;
    std::cout << "Garrett items: " << garrettItemsBefore << " -> " << garrett.getNumOfUsedSlots() << std::endl;

    printSubSection("Steal a weapon (verify hasWeapon flag transfer)");
    // Conan still has the Steel Sword - Garrett has no weapon yet.
    // Search Conan's inventory for a slot containing a weapon.
    int weaponIdx = -1;
    for (int i = 0; i < 10; i++) {
        Item* it = conan.getItemfromInventory(i);
        if (it != nullptr && it->getType() == "Weapon") {
            weaponIdx = i;
            break;
        }
    }
    std::cout << "Conan's weapon is in slot: " << weaponIdx << std::endl;
    if (weaponIdx >= 0) {
        garrett.steal(conan, weaponIdx);
        std::cout << "Conan weapon now: "
                  << (conan.getWeaponFromInventory() ? conan.getWeaponFromInventory()->getName() : "none")
                  << std::endl;
        std::cout << "Garrett weapon now: "
                  << (garrett.getWeaponFromInventory() ? garrett.getWeaponFromInventory()->getName() : "none")
                  << std::endl;
    } else {
        std::cout << "(weapon not found in Conan's inventory - skipping)" << std::endl;
    }

    printSubSection("Failed steal (target too strong)");
    // Boost Conan to a level higher than garrett's weaponSkill
    conan.levelUp(50);
    std::cout << "Conan's level boosted to: " << conan.getLevel() << std::endl;
    garrett.steal(conan, 1);   // expect: "Target is to Strong"

    printSubSection("Failed steal - chained (thief inventory full)");
    Thief packrat("Packrat", 1, 50, 100);
    Item fillerItems[10];
    for (int i = 0; i < 10; i++) {
        fillerItems[i] = Item("Filler" + std::to_string(i));
        packrat.addItemToInventory(&fillerItems[i]);
    }
    std::cout << "Packrat full? " << (packrat.isInventoryFull() ? "yes" : "no") << std::endl;
    Mage victim("Victim", 1, 50, 10);
    Item loot("Lootable");
    victim.addItemToInventory(&loot);
    packrat.steal(victim, 0).steal(victim, 0);  // chained, both should fail

    // ============================================================
    // SECTION 11: SPECIAL TASK - Array of characters (polymorphism)
    // ============================================================
    printSeparator("11. SPECIAL TASK: Array of Characters");

    std::cout << "Storing all characters in one array (Character*)..." << std::endl << std::endl;

    Character* party[4] = { &gandalf, &conan, &elara, &garrett };

    std::cout << "Levels of all party members:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "  [" << i << "] " << party[i]->getName()
                  << " - Level " << party[i]->getLevel() << std::endl;
    }

    printSubSection("Polymorphic printStatus() through base pointer");
    for (int i = 0; i < 4; i++) {
        std::cout << "\n>>> " << party[i]->getName() << " <<<" << std::endl;
        party[i]->printStatus();
    }

    // ============================================================
    // SECTION 12: removeLastItem()
    // ============================================================
    printSeparator("12. removeLastItem()");

    // Use heap-allocated item because removeLastItem calls delete
    Mage testMage("TestMage", 1, 50, 10);
    Item* heapItem = new Item("Disposable");
    testMage.addItemToInventory(heapItem);
    std::cout << "TestMage used slots before remove: " << testMage.getNumOfUsedSlots() << std::endl;
    testMage.removeLastItem();
    std::cout << "TestMage used slots after  remove: " << testMage.getNumOfUsedSlots() << std::endl;

    printSubSection("removeLastItem() on empty inventory");
    testMage.removeLastItem();   // expect: "Inventory empty..."

    // ============================================================
    // DONE
    // ============================================================
    printSeparator("ALL TESTS COMPLETED");

    return 0;
}