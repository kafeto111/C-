#include <iostream>
#include <string>
#include <list>
#include <vector>



using namespace std;

enum ItemSet {
    MysticRelicsn,
    Ethereal,
    Shadow,
    Celestial,
    //tank
    Dragon,
    Ancient,
    Stormbringer,
    Phoenix,
    //warrior
    Timeless,
    Frostbound,
    Vanguard,
    Arcane
};

string getItemSetName(ItemSet set) {
    switch (set) {
    case MysticRelicsn: return "Mystic Relics";
    case Ethereal: return "Ethereal";
    case Shadow: return "Shadow";
    case Celestial: return "Celestial";
    case Dragon: return "Dragon";
    case Ancient: return "Ancient";
    case Stormbringer: return "Stormbringer";
    case Phoenix: return "Phoenix";
    case Timeless: return "Timeless";
    case Frostbound: return "Frostbound";
    case Vanguard: return "Vanguard";
    case Arcane: return "Arcane";
    default: return "Unknown";
    }
}

class Item {
public:
    string Name;
    double AP;
    double AD;
    double Health;
    double Defence;
    double Mana;
    double CritChance;
    double MR;
    ItemSet Set;

    Item(const string& name, double ap, double ad, double health, double defence, double mana, double critChance, double mr, ItemSet set)
        : Name(name), AP(ap), AD(ad), Health(health), Defence(defence), Mana(mana), CritChance(critChance), MR(mr), Set(set) {}

    virtual ~Item() {}
};

class Helmet : public Item {
public:
    Helmet(const string& name, double ap, double ad, double health, double defence, double mana, double critChance, double mr, ItemSet set)
        : Item(name, ap, ad, health, defence, mana, critChance, mr, set) {}
};

class Chestplate : public Item {
public:
    Chestplate(const string& name, double ap, double ad, double health, double defence, double mana, double critChance, double mr, ItemSet set)
        : Item(name, ap, ad, health, defence, mana, critChance, mr, set) {}
};

class Pants : public Item {
public:
    Pants(const string& name, double ap, double ad, double health, double defence, double mana, double critChance, double mr, ItemSet set)
        : Item(name, ap, ad, health, defence, mana, critChance, mr, set) {}
};

class Boots : public Item {
public:
    Boots(const string& name, double ap, double ad, double health, double defence, double mana, double critChance, double mr, ItemSet set)
        : Item(name, ap, ad, health, defence, mana, critChance, mr, set) {}
};

class Weapon : public Item {
    double DmgBoots;
public:
    Weapon(const string& name, double ap, double ad, double health, double defence, double mana, double critChance, double mr, ItemSet set, double DmgBoost)
        : Item(name, ap, ad, health, defence, mana, critChance, mr, set) {
        this->DmgBoots = DmgBoost;
    }
    double ApplySpecialAbility(double baseDamage)
    {
        return baseDamage + DmgBoots;
    }
};

class Character {
public:
    string Name;
    string Class;
    double AP;
    double AD;
    double Health;
    double Defence;
    double Mana;
    double MR;
    Helmet* EquippedHelmet = nullptr;
    Chestplate* EquippedChestplate = nullptr;
    Pants* EquippedPants = nullptr;
    Boots* EquippedBoots = nullptr;
    Weapon* EquippedWeapon = nullptr;
    double Attack();
    void RecieveDamage(double damage);

    void setString(const string& name, const string& cls) {
        this->Name = name;
        this->Class = cls;
    }

    void setDoubles(double ap, double ad, double health, double defence, double mana, double mr) {
        this->AP = ap;
        this->AD = ad;
        this->Health = health;
        this->Defence = defence;
        this->Mana = mana;
        this->MR = mr;
    }

    // Default implementation for EquipItem
   
};
double Character::Attack() {
    // Implement the logic for calculating attack damage
    // For example:
    double totalDamage = this->AD; // AD is the attack damage of the character
    if (EquippedWeapon != nullptr) {
        totalDamage += EquippedWeapon->AD; // Assuming Damage is a member variable of the Weapon class
    }
    return totalDamage;
}

void Character::RecieveDamage(double damage) {
    // Update the character's health based on the received damage
    // For example:
    double totalDamageTaken = damage ; // Subtract defense from incoming damage
    if (totalDamageTaken > 0) {
        this->Health -= totalDamageTaken; // Update health
        if (this->Health < 0) {
            this->Health = 0; // Ensure health doesn't go below zero
        }
    }
}


class Warrior : public Character {
public:
    Warrior(const string& name) {
        setString(name, "Warrior");
        setDoubles(50, 10, 100, 5, 200, 10);
    }
    double Attack()
    {
        return EquippedWeapon->ApplySpecialAbility(AD);
    }
    void ReceiveDamage(double damage)
    {
        Health -= damage;
        if (Health<=0)
        {
            cout << Name << "is defeater";
        }
    }

   
};

class Mage : public Character {
public:
    Mage(const string& name) {
        setString(name, "Mage");
        setDoubles(50, 10, 100, 5, 200, 10);
    }
    double Attack()
    {
        return EquippedWeapon->ApplySpecialAbility(AD);
    }
    void ReceiveDamage(double damage)
    {
        Health -= damage;
        if (Health <= 0)
        {
            cout << Name << "is defeater";
        }
    }
   
};


class Tank : public Character {
public:
    Tank(const string& name) {
        setString(name, "Tank");
        setDoubles(50, 10, 100, 5, 200, 10);
    }
    double Attack()
    {
        return EquippedWeapon->ApplySpecialAbility(AD);
    }
    void ReceiveDamage(double damage)
    {
        Health -= damage;
        if (Health <= 0)
        {
            cout << Name << "is defeater";
        }
    }
   
};

void displayHelmets(Character* charecter)
{
    list<Item>Helmets;

    if (charecter->Class == "Mage")
    {

        Helmets.push_back(Item("Helmet A", 20, 30, 40, 50, 60, 70, 30, ItemSet::Ancient));
        Helmets.push_back(Item("Helmet B", 4, 0, 8, 6, 0, 2.5, 4, ItemSet::Ethereal));
        Helmets.push_back(Item("Helmet C", 6, 0, 12, 4, 0, 1.5, 2, ItemSet::Shadow));
        Helmets.push_back(Item("Helmet D", 7, 0, 9, 7, 0, 3, 5, ItemSet::Celestial));


        for (const auto& helmet : Helmets) {
            std::cout << "Name: " << helmet.Name << endl;
            cout << "AP: " << helmet.AP << endl;
            cout << "AD: " << helmet.AD << endl;
            cout << "Health: " << helmet.Health << endl;
            cout << "Defence: " << helmet.Defence << endl;
            cout << "Mana: " << helmet.Mana << endl;
            cout << "Crit Chance: " << helmet.CritChance << endl;
            cout << "MR: " << helmet.MR << endl;
            cout << "Set: " << getItemSetName(helmet.Set) << endl;
            cout << "---------------------" << endl;
            cout << "---------------------------" << endl;

        }
    }
    else if (charecter->Class == "Tank")
    {
        Helmets.push_back(Item("Test A", 5, 0, 10, 5, 0, 2, 5, ItemSet::Dragon));
        Helmets.push_back(Item("Helmet B", 4, 0, 8, 6, 0, 2.5, 4, ItemSet::Ancient));
        Helmets.push_back(Item("Helmet C", 6, 0, 12, 4, 0, 1.5, 2, ItemSet::Stormbringer));
        Helmets.push_back(Item("Helmet D", 7, 0, 9, 7, 0, 3, 5, ItemSet::Phoenix));
        for (const auto& helmet : Helmets) {
            cout << "Name: " << helmet.Name << endl;
            cout << "AP: " << helmet.AP << endl;
            cout << "AD: " << helmet.AD << endl;
            cout << "Health: " << helmet.Health << endl;
            cout << "Defence: " << helmet.Defence << endl;
            cout << "Mana: " << helmet.Mana << endl;
            cout << "Crit Chance: " << helmet.CritChance << endl;
            cout << "MR: " << helmet.MR << endl;
            cout << "Set: " << getItemSetName(helmet.Set) << endl;
            cout << "---------------------" << endl;
            cout << "---------------------------" << endl;

        }

    }
    else if (charecter->Class == "Warrior")
    {
        Helmets.push_back(Item("Helmet A", 5, 0, 10, 5, 0, 2, 3, ItemSet::Timeless));
        Helmets.push_back(Item("Helmet B", 4, 0, 8, 6, 0, 2.5, 4, ItemSet::Frostbound));
        Helmets.push_back(Item("Helmet C", 6, 0, 12, 4, 0, 1.5, 2, ItemSet::Vanguard));
        Helmets.push_back(Item("Helmet D", 7, 0, 9, 7, 0, 3, 5, ItemSet::Arcane));
        for (const auto& helmet : Helmets) {
            cout << "Name: " << helmet.Name << endl;
            cout << "AP: " << helmet.AP << endl;
            cout << "AD: " << helmet.AD << endl;
            cout << "Health: " << helmet.Health << endl;
            cout << "Defence: " << helmet.Defence << endl;
            cout << "Mana: " << helmet.Mana << endl;
            cout << "Crit Chance: " << helmet.CritChance << endl;
            cout << "MR: " << helmet.MR << endl;
            cout << "Set: " << getItemSetName(helmet.Set) << endl;
            cout << "---------------------" << endl;
            cout << "---------------------------" << endl;

        }

    }





};
void displayChestplate(Character* charecter)
{
    list<Item>Chestplate;
    if (charecter->Class == "Mage")
    {
        Chestplate.push_back(Item("Chestplate A", 1, 10, 30, 10, 0, 2, 4, ItemSet::MysticRelicsn));
        Chestplate.push_back(Item("Chestplate B", 0, 12, 25, 12, 0, 1.8, 5, ItemSet::Ethereal));
        Chestplate.push_back(Item("Chestplate C", 0, 8, 35, 8, 0, 2.5, 5, ItemSet::Shadow));
        Chestplate.push_back(Item("Chestplate D", 0, 9, 40, 9, 0, 2.2, 2, ItemSet::Celestial));

        for (const auto& chestplate : Chestplate) {
            cout << "Name: " << chestplate.Name << endl;
            cout << "AP: " << chestplate.AP << endl;
            cout << "AD: " << chestplate.AD << endl;
            cout << "Health: " << chestplate.Health << endl;
            cout << "Defence: " << chestplate.Defence << endl;
            cout << "Mana: " << chestplate.Mana << endl;
            cout << "Crit Chance: " << chestplate.CritChance << endl;
            cout << "MR: " << chestplate.MR << endl;
            cout << "Set: " << getItemSetName(chestplate.Set) << endl;
            cout << "---------------------" << endl;
        }
    }
    else if (charecter->Class == "Tank")
    {
        Chestplate.push_back(Item("Chestplate A", 0, 10, 30, 10, 0, 2, 4, ItemSet::Dragon));
        Chestplate.push_back(Item("Chestplate B", 0, 12, 25, 12, 0, 1.8, 5, ItemSet::Ancient));
        Chestplate.push_back(Item("Chestplate C", 0, 8, 35, 8, 0, 2.5, 5, ItemSet::Stormbringer));
        Chestplate.push_back(Item("Chestplate D", 0, 9, 40, 9, 0, 2.2, 2, ItemSet::Phoenix));

        for (const auto& chestplate : Chestplate) {
            cout << "Name: " << chestplate.Name << endl;
            cout << "AP: " << chestplate.AP << endl;
            cout << "AD: " << chestplate.AD << endl;
            cout << "Health: " << chestplate.Health << endl;
            cout << "Defence: " << chestplate.Defence << endl;
            cout << "Mana: " << chestplate.Mana << endl;
            cout << "Crit Chance: " << chestplate.CritChance << endl;
            cout << "MR: " << chestplate.MR << endl;
            cout << "Set: " << getItemSetName(chestplate.Set) << endl;
            cout << "---------------------" << endl;
        }
    }
    else if (charecter->Class == "Warrior")
    {
        Chestplate.push_back(Item("Chestplate A", 0, 10, 30, 10, 0, 2, 4, ItemSet::Timeless));
        Chestplate.push_back(Item("Chestplate B", 0, 12, 25, 12, 0, 1.8, 3, ItemSet::Frostbound));
        Chestplate.push_back(Item("Chestplate C", 0, 8, 35, 8, 0, 2.5, 5, ItemSet::Vanguard));
        Chestplate.push_back(Item("Chestplate D", 0, 9, 40, 9, 0, 2.2, 2, ItemSet::Arcane));
        for (const auto& chestplate : Chestplate) {
            cout << "Name: " << chestplate.Name << endl;
            cout << "AP: " << chestplate.AP << endl;
            cout << "AD: " << chestplate.AD << endl;
            cout << "Health: " << chestplate.Health << endl;
            cout << "Defence: " << chestplate.Defence << endl;
            cout << "Mana: " << chestplate.Mana << endl;
            cout << "Crit Chance: " << chestplate.CritChance << endl;
            cout << "MR: " << chestplate.MR << endl;
            cout << "Set: " << getItemSetName(chestplate.Set) << endl;
            cout << "---------------------" << endl;
        }
    }
}
void displayPants(Character* charecter)
{
    list<Item>Panths;
    if (charecter->Class == "Mage")
    {
        Panths.push_back(Item("Pants A", 1, 5, 20, 5, 0, 1, 2, ItemSet::MysticRelicsn));
        Panths.push_back(Item("Pants B", 6, 4, 18, 6, 0, 1.2, 3, ItemSet::Ethereal));
        Panths.push_back(Item("Pants C", 4, 6, 22, 4, 0, 0.8, 5, ItemSet::Shadow));
        Panths.push_back(Item("Pants D", 5, 7, 19, 5, 0, 1.5, 4, ItemSet::Celestial));
        for (const auto& pants : Panths) {
            cout << "Name: " << pants.Name << endl;
            cout << "AP: " << pants.AP << endl;
            cout << "AD: " << pants.AD << endl;
            cout << "Health: " << pants.Health << endl;
            cout << "Defence: " << pants.Defence << endl;
            cout << "Mana: " << pants.Mana << endl;
            cout << "Crit Chance: " << pants.CritChance << endl;
            cout << "MR: " << pants.MR << endl;
            cout << "Set: " << getItemSetName(pants.Set) << endl;
            cout << "---------------------" << endl;
        }
    }
    else if (charecter->Class == "Tank")
    {
        Panths.push_back(Item("Pants A", 5, 5, 20, 5, 0, 1, 2, ItemSet::Dragon));
        Panths.push_back(Item("Pants B", 6, 4, 18, 6, 0, 1.2, 3, ItemSet::Ancient));
        Panths.push_back(Item("Pants C", 4, 6, 22, 4, 0, 0.8, 5, ItemSet::Stormbringer));
        Panths.push_back(Item("Pants D", 5, 7, 19, 5, 0, 1.5, 4, ItemSet::Phoenix));
        for (const auto& pants : Panths) {
            cout << "Name: " << pants.Name << endl;
            cout << "AP: " << pants.AP << endl;
            cout << "AD: " << pants.AD << endl;
            cout << "Health: " << pants.Health << endl;
            cout << "Defence: " << pants.Defence << endl;
            cout << "Mana: " << pants.Mana << endl;
            cout << "Crit Chance: " << pants.CritChance << endl;
            cout << "MR: " << pants.MR << endl;
            cout << "Set: " << getItemSetName(pants.Set) << endl;
            cout << "---------------------" << endl;
        }
    }
    else if (charecter->Class == "Warrior")
    {
        Panths.push_back(Item("Pants A", 5, 5, 20, 5, 0, 1, 2, ItemSet::Timeless));
        Panths.push_back(Item("Pants B", 6, 4, 18, 6, 0, 1.2, 3, ItemSet::Frostbound));
        Panths.push_back(Item("Pants C", 4, 6, 22, 4, 0, 0.8, 2, ItemSet::Vanguard));
        Panths.push_back(Item("Pants D", 5, 7, 19, 5, 0, 1.5, 4, ItemSet::Arcane));
        for (const auto& pants : Panths) {
            cout << "Name: " << pants.Name << endl;
            cout << "AP: " << pants.AP << endl;
            cout << "AD: " << pants.AD << endl;
            cout << "Health: " << pants.Health << endl;
            cout << "Defence: " << pants.Defence << endl;
            cout << "Mana: " << pants.Mana << endl;
            cout << "Crit Chance: " << pants.CritChance << endl;
            cout << "MR: " << pants.MR << endl;
            cout << "Set: " << getItemSetName(pants.Set) << endl;
            cout << "---------------------" << endl;
        }

    }
}
void displayBoots(Character* charecter)
{
    list<Item>Boots;
    if (charecter->Class == "Mage")
    {
        Boots.push_back(Item("Boots A", 1, 3, 15, 3, 0, 0.5, 1, ItemSet::MysticRelicsn));
        Boots.push_back(Item("Boots B", 4, 2, 13, 4, 0, 0.7, 2, ItemSet::Ethereal));
        Boots.push_back(Item("Boots C", 2, 4, 17, 2, 0, 0.3, 1, ItemSet::Shadow));
        Boots.push_back(Item("Boots D", 3, 5, 16, 3, 0, 0.9, 5, ItemSet::Celestial));
        for (const auto& boots : Boots) {
            cout << "Name: " << boots.Name << endl;
            cout << "AP: " << boots.AP << endl;
            cout << "AD: " << boots.AD << endl;
            cout << "Health: " << boots.Health << endl;
            cout << "Defence: " << boots.Defence << endl;
            cout << "Mana: " << boots.Mana << endl;
            cout << "Crit Chance: " << boots.CritChance << endl;
            cout << "MR: " << boots.MR << endl;
            cout << "Set: " << getItemSetName(boots.Set) << endl;
            cout << "---------------------" << endl;
        }

    }
    else if (charecter->Class == "Tank")
    {

        Boots.push_back(Item("Boots A", 3, 3, 15, 3, 0, 0.5, 1, ItemSet::Dragon));
        Boots.push_back(Item("Boots B", 4, 2, 13, 4, 0, 0.7, 2, ItemSet::Ancient));
        Boots.push_back(Item("Boots C", 2, 4, 17, 2, 0, 0.3, 1, ItemSet::Stormbringer));
        Boots.push_back(Item("Boots D", 3, 5, 16, 3, 0, 0.9, 5, ItemSet::Phoenix));
        for (const auto& boots : Boots) {
            cout << "Name: " << boots.Name << endl;
            cout << "AP: " << boots.AP << endl;
            cout << "AD: " << boots.AD << endl;
            cout << "Health: " << boots.Health << endl;
            cout << "Defence: " << boots.Defence << endl;
            cout << "Mana: " << boots.Mana << endl;
            cout << "Crit Chance: " << boots.CritChance << endl;
            cout << "MR: " << boots.MR << endl;
            cout << "Set: " << getItemSetName(boots.Set) << endl;
            cout << "---------------------" << endl;
        }
    }
    else if (charecter->Class == "Warrior")
    {
        Boots.push_back(Item("Boots A", 3, 3, 15, 3, 0, 0.5, 1, ItemSet::Timeless));
        Boots.push_back(Item("Boots B", 4, 2, 13, 4, 0, 0.7, 2, ItemSet::Frostbound));
        Boots.push_back(Item("Boots C", 2, 4, 17, 2, 0, 0.3, 1, ItemSet::Vanguard));
        Boots.push_back(Item("Boots D", 3, 5, 16, 3, 0, 0.9, 2, ItemSet::Arcane));
        for (const auto& boots : Boots) {
            cout << "Name: " << boots.Name << endl;
            cout << "AP: " << boots.AP << endl;
            cout << "AD: " << boots.AD << endl;
            cout << "Health: " << boots.Health << endl;
            cout << "Defence: " << boots.Defence << endl;
            cout << "Mana: " << boots.Mana << endl;
            cout << "Crit Chance: " << boots.CritChance << endl;
            cout << "MR: " << boots.MR << endl;
            cout << "Set: " << getItemSetName(boots.Set) << endl;
            cout << "---------------------" << endl;
        }

    }
}
void displayWeapon(Character* character)
{
    list<Item>Weapon;
    if (character->Class == "Mage")
    {
        Weapon.push_back(Item("Weapon A", 1, 10, 0, 0, 10, 1, 2, ItemSet::MysticRelicsn));
        Weapon.push_back(Item("Weapon B", 12, 8, 0, 0, 12, 1.2, 3, ItemSet::Ethereal));
        Weapon.push_back(Item("Weapon C", 8, 12, 0, 0, 8, 0.8, 2, ItemSet::Shadow));
        Weapon.push_back(Item("Weapon D", 11, 11, 0, 0, 11, 1.1, 0, ItemSet::Celestial));
        for (const auto& weapon : Weapon) {
            cout << "Name: " << weapon.Name << endl;
            cout << "AP: " << weapon.AP << endl;
            cout << "AD: " << weapon.AD << endl;
            cout << "Health: " << weapon.Health << endl;
            cout << "Defence: " << weapon.Defence << endl;
            cout << "Mana: " << weapon.Mana << endl;
            cout << "Crit Chance: " << weapon.CritChance << endl;
            cout << "MR: " << weapon.MR << endl;
            cout << "Set: " << getItemSetName(weapon.Set) << endl;
            cout << "---------------------" << endl;
        }
    }
    else if (character->Class == "Warrior")
    {
        Weapon.push_back(Item("Weapon A", 10, 10, 0, 0, 10, 1, 2, ItemSet::Timeless));
        Weapon.push_back(Item("Weapon B", 12, 8, 0, 0, 12, 1.2, 3, ItemSet::Frostbound));
        Weapon.push_back(Item("Weapon C", 8, 12, 0, 0, 8, 0.8, 2, ItemSet::Vanguard));
        Weapon.push_back(Item("Weapon D", 11, 11, 0, 0, 11, 1.1, 4, ItemSet::Arcane));
        for (const auto& weapon : Weapon) {
            cout << "Name: " << weapon.Name << endl;
            cout << "AP: " << weapon.AP << endl;
            cout << "AD: " << weapon.AD << endl;
            cout << "Health: " << weapon.Health << endl;
            cout << "Defence: " << weapon.Defence << endl;
            cout << "Mana: " << weapon.Mana << endl;
            cout << "Crit Chance: " << weapon.CritChance << endl;
            cout << "MR: " << weapon.MR << endl;
            cout << "Set: " << getItemSetName(weapon.Set) << endl;
            cout << "---------------------" << endl;
        }
    }
    else if (character->Class == "Tank")
    {
        Weapon.push_back(Item("Weapon A", 10, 10, 0, 0, 10, 1, 2, ItemSet::Dragon));
        Weapon.push_back(Item("Weapon B", 12, 8, 0, 0, 12, 1.2, 3, ItemSet::Ancient));
        Weapon.push_back(Item("Weapon C", 8, 12, 0, 0, 8, 0.8, 2, ItemSet::Stormbringer));
        Weapon.push_back(Item("Weapon D", 11, 11, 0, 0, 11, 1.1, 0, ItemSet::Phoenix));
        for (const auto& weapon : Weapon) {
            cout << "Name: " << weapon.Name << endl;
            cout << "AP: " << weapon.AP << endl;
            cout << "AD: " << weapon.AD << endl;
            cout << "Health: " << weapon.Health << endl;
            cout << "Defence: " << weapon.Defence << endl;
            cout << "Mana: " << weapon.Mana << endl;
            cout << "Crit Chance: " << weapon.CritChance << endl;
            cout << "MR: " << weapon.MR << endl;
            cout << "Set: " << getItemSetName(weapon.Set) << endl;
            cout << "---------------------" << endl;
        }
    }
}
void MageItems(Character* character) {
    list <Item> choosedItem;
    int EthernalSet = 0;
    int ShadowSet = 0;
    int Celestial = 0;
    int MysticRelicsn = 0;


    if (character->Class == "Mage") {
        displayHelmets(character);
        cout << "What helmet you want to equip";
        int HelmetChoise;
        cin >> HelmetChoise;
        switch (HelmetChoise)
        {
        case 1:
            choosedItem.push_back(Helmet("Helmet A", 0, 0, 5, 3, 0, 1.5, 1, ItemSet::Ethereal));
            EthernalSet += 1;
            break;
        case 2:
            choosedItem.push_back(Helmet("Helmet B", 8, 0, 3, 2, 0, 1.0, 2, ItemSet::Shadow));
            ShadowSet += 1;
            break;
        case 3:
            choosedItem.push_back(Helmet("Helmet B", 8, 0, 3, 2, 0, 1.0, 2, ItemSet::Celestial));
            Celestial += 1;
            break;
        case 4:
            choosedItem.push_back(Helmet("Helmet D", 4, 0, 6, 2, 0, 1.0, 2, ItemSet::MysticRelicsn));
            MysticRelicsn += 1;
            break;

        default:
            cout << "enter a valid number";
            break;
        }

        displayChestplate(character);
        cout << "What chestplate you want to equip";
        int ChestplateChoise;
        cin >> ChestplateChoise;
        switch (ChestplateChoise)
        {
        case 1:
            choosedItem.push_back(Chestplate("Chestplate A", 0, 3, 20, 20, 5, 1, 1, ItemSet::Ethereal));
            EthernalSet += 1;
            break;
        case 2:
            choosedItem.push_back(Chestplate("Chestplate B", 2, 3, 8, 5, 2, 1.5, 2, ItemSet::Shadow));
            ShadowSet += 1;
            break;
        case 3:
            choosedItem.push_back(Chestplate("Chestplate C", 5, 5, 12, 6, 3, 2.5, 3, ItemSet::Celestial));
            Celestial += 1;
            break;
        case 4:
            choosedItem.push_back(Chestplate("Chestplate D", 6, 7, 14, 8, 4, 3.5, 4, ItemSet::MysticRelicsn));
            MysticRelicsn += 1;
            break;

        default:
            cout << "enter a valid number";
            break;
        }

        displayPants(character);
        cout << "What pants you want to equip";
        int pantsChoise;
        cin >> pantsChoise;
        switch (pantsChoise)
        {
        case 1:
            choosedItem.push_back(Pants("Pants A", 0, 5, 15, 10, 5, 2.5, 3, ItemSet::Ethereal));
            EthernalSet += 1;
            break;
        case 2:
            choosedItem.push_back(Pants("Pants B", 15, 10, 20, 15, 10, 3.5, 4, ItemSet::Shadow));
            ShadowSet += 1;
            break;
        case 3:
            choosedItem.push_back(Pants("Pants C", 20, 15, 25, 20, 15, 4.5, 5, ItemSet::Celestial));
            Celestial += 1;
            break;
        case 4:
            choosedItem.push_back(Pants("Pants D", 25, 20, 30, 25, 20, 5.5, 6, ItemSet::MysticRelicsn));
            MysticRelicsn += 1;
            break;

        default:
            cout << "enter a valid number";
            break;
        }

        displayBoots(character);
        cout << "What boots you want to equip";
        int bootsChoise;
        cin >> bootsChoise;
        switch (bootsChoise)
        {
        case 1:
            choosedItem.push_back(Boots("Boots A", 0, 5, 5, 5, 5, 5, 5, ItemSet::Ethereal));
            EthernalSet += 1;
            break;
        case 2:
            choosedItem.push_back(Boots("Boots B", 10, 10, 10, 10, 10, 10, 10, ItemSet::Shadow));
            ShadowSet += 1;
            break;
        case 3:
            choosedItem.push_back(Boots("Boots C", 15, 15, 15, 15, 15, 15, 15, ItemSet::Celestial));
            Celestial += 1;
            break;
        case 4:
            choosedItem.push_back(Boots("Boots D", 20, 20, 20, 20, 20, 20, 20, ItemSet::MysticRelicsn));
            MysticRelicsn += 1;
            break;

        default:
            cout << "enter a valid number";
            break;
        }

        displayWeapon(character);
        cout << "What weapon you want to equip";
        int weaponChoise;
        cin >> weaponChoise;
        switch (weaponChoise)
        {
        case 1:
            choosedItem.push_back(Weapon("Weapon A", 50, 50, 50, 50, 50, 50, 50, ItemSet::Ethereal,1));
            EthernalSet += 1;
            break;
        case 2:
            choosedItem.push_back(Weapon("Weapon B", 50, 60, 60, 60, 60, 60, 60, ItemSet::Shadow,1));
            ShadowSet += 1;
            break;
        case 3:
            choosedItem.push_back(Weapon("Weapon C", 70, 70, 70, 70, 70, 70, 70, ItemSet::Celestial,1));
            Celestial += 1;
            break;
        case 4:
            choosedItem.push_back(Weapon("Weapon D", 80, 80, 80, 80, 80, 80, 80, ItemSet::MysticRelicsn,1));
            MysticRelicsn += 1;
            break;

        default:
            cout << "enter a valid number";
            break;
        }




    }

    cout << "Items chosen for the character:" << endl;
    for (const auto& item : choosedItem) {
        cout << "Name: " << item.Name << ", Stats: " << getItemSetName(item.Set) << endl;






    }

    if (EthernalSet == 5)
    {
        character->Health += 10000;
    }
    else  if (ShadowSet == 5)
    {
        character->AP += 10;
    }
    else if (Celestial == 5)
    {
        character->Defence *= 2;
    }
    else if (MysticRelicsn == 5)
    {
        character->AD += 20;
    }

    for (const auto& item : choosedItem) {
        character->Health += item.Health;
        character->AP += item.AP;
        character->AD = item.AD;
        character->Defence += item.Defence;
        character->Mana += item.Mana;
        character->MR += item.MR;
    }


    cout << character->Health;

};
void TankItems(Character* character) {
    list <Item> choosedItem;
    int Dragon = 0;
    int Ancient = 0;
    int Stormbringer = 0;
    int Phoenix = 0;


    if (character->Class == "Tank") {
        displayHelmets(character);
        cout << "What helmet you want to equip";
        int HelmetChoise;
        cin >> HelmetChoise;
        switch (HelmetChoise)
        {
        case 1:
            choosedItem.push_back(Helmet("Test A", 5, 0, 10, 5, 0, 2, 5, ItemSet::Dragon));
            Dragon += 1;
            break;
        case 2:
            choosedItem.push_back(Helmet("Helmet B", 4, 0, 8, 6, 0, 2.5, 4, ItemSet::Ancient));
            Ancient += 1;
            break;
        case 3:
            choosedItem.push_back(Helmet("Helmet C", 6, 0, 12, 4, 0, 1.5, 2, ItemSet::Stormbringer));
            Stormbringer += 1;
            break;
        case 4:
            choosedItem.push_back(Helmet("Helmet D", 7, 0, 9, 7, 0, 3, 5, ItemSet::Phoenix));

            Phoenix += 1;
            break;

        default:
            cout << "enter a valid number";
            break;
        }

        displayChestplate(character);
        cout << "What chestplate you want to equip";
        int ChestplateChoise;
        cin >> ChestplateChoise;
        switch (ChestplateChoise)
        {
        case 1:
            choosedItem.push_back(Chestplate("Chestplate A", 0, 10, 30, 10, 0, 2, 4, ItemSet::Dragon));

            Dragon += 1;
            break;
        case 2:
            choosedItem.push_back(Chestplate("Chestplate B", 0, 12, 25, 12, 0, 1.8, 5, ItemSet::Ancient));
            Ancient += 1;
            break;
        case 3:
            choosedItem.push_back(Chestplate("Chestplate C", 0, 8, 35, 8, 0, 2.5, 5, ItemSet::Stormbringer));
            Stormbringer += 1;
            break;
        case 4:
            choosedItem.push_back(Chestplate("Chestplate D", 0, 9, 40, 9, 0, 2.2, 2, ItemSet::Phoenix));
            Phoenix += 1;
            break;

        default:
            cout << "enter a valid number";
            break;
        }

        displayPants(character);
        cout << "What pants you want to equip";
        int pantsChoise;
        cin >> pantsChoise;
        switch (pantsChoise)
        {
        case 1:
            choosedItem.push_back(Pants("Pants A", 5, 5, 20, 5, 0, 1, 2, ItemSet::Dragon));
            Dragon += 1;
            break;
        case 2:
            choosedItem.push_back(Pants("Pants B", 6, 4, 18, 6, 0, 1.2, 3, ItemSet::Ancient));
            Ancient += 1;
            break;
        case 3:
            choosedItem.push_back(Pants("Pants C", 4, 6, 22, 4, 0, 0.8, 5, ItemSet::Stormbringer));
            Stormbringer += 1;
            break;
        case 4:
            choosedItem.push_back(Pants("Pants D", 5, 7, 19, 5, 0, 1.5, 4, ItemSet::Phoenix));
            Phoenix += 1;
            break;

        default:
            cout << "enter a valid number";
            break;
        }

        displayBoots(character);
        cout << "What boots you want to equip";
        int bootsChoise;
        cin >> bootsChoise;
        switch (bootsChoise)
        {
        case 1:
            choosedItem.push_back(Boots("Boots A", 3, 3, 15, 3, 0, 0.5, 1, ItemSet::Dragon));
            Dragon += 1;
            break;
        case 2:
            choosedItem.push_back(Boots("Boots A", 3, 3, 15, 3, 0, 0.5, 1, ItemSet::Dragon));
            Ancient += 1;
            break;
        case 3:
            choosedItem.push_back(Boots("Boots A", 3, 3, 15, 3, 0, 0.5, 1, ItemSet::Dragon));
            Stormbringer += 1;
            break;
        case 4:
            choosedItem.push_back(Boots("Boots A", 3, 3, 15, 3, 0, 0.5, 1, ItemSet::Dragon));
            Phoenix += 1;
            break;

        default:
            cout << "enter a valid number";
            break;
        }

        displayWeapon(character);
        cout << "What weapon you want to equip";
        int weaponChoise;
        cin >> weaponChoise;
        switch (weaponChoise)
        {
        case 1:
            choosedItem.push_back(Weapon("Weapon A", 10, 10, 0, 0, 10, 1, 2, ItemSet::Dragon,1));
            Dragon += 1;
            break;
        case 2:
            choosedItem.push_back(Weapon("Weapon B", 12, 8, 0, 0, 12, 1.2, 3, ItemSet::Ancient,1));
            Ancient += 1;
            break;
        case 3:
            choosedItem.push_back(Weapon("Weapon C", 8, 12, 0, 0, 8, 0.8, 2, ItemSet::Stormbringer,1));
            Stormbringer += 1;
            break;
        case 4:
            choosedItem.push_back(Weapon("Weapon D", 11, 11, 0, 0, 11, 1.1, 0, ItemSet::Phoenix,1));
            Phoenix += 1;
            break;

        default:
            cout << "enter a valid number";
            break;
        }




    }

    cout << "Items chosen for the character:" << endl;
    for (const auto& item : choosedItem) {
        cout << "Name: " << item.Name << ", Stats: " << getItemSetName(item.Set) << endl;






    }

    if (Dragon == 5)
    {
        character->Health += 10000;
    }
    else  if (Ancient == 5)
    {
        character->AP += 10;
    }
    else if (Stormbringer == 5)
    {
        character->Defence *= 2;
    }
    else if (Phoenix == 5)
    {
        character->AD += 20;
    }

    for (const auto& item : choosedItem) {
        character->Health += item.Health;
        character->AP += item.AP;
        character->AD = item.AD;
        character->Defence += item.Defence;
        character->Mana += item.Mana;
        character->MR += item.MR;
    }


    cout << character->Health;

};
void WarriorItems(Character* character) {
    list <Item> choosedItem;
    int Timeless = 0;
    int Frostbound = 0;
    int Vanguard = 0;
    int Arcane = 0;


    if (character->Class == "Warrior") {
        displayHelmets(character);
        cout << "What helmet you want to equip";
        int HelmetChoise;
        cin >> HelmetChoise;
        switch (HelmetChoise)
        {
        case 1:
            choosedItem.push_back(Helmet("Helmet A", 5, 0, 10, 5, 0, 2, 3, ItemSet::Timeless));
            Timeless += 1;
            break;
        case 2:
            choosedItem.push_back(Helmet("Helmet B", 4, 0, 8, 6, 0, 2.5, 4, ItemSet::Frostbound));;
            Frostbound += 1;
            break;
        case 3:
            choosedItem.push_back(Helmet("Helmet C", 6, 0, 12, 4, 0, 1.5, 2, ItemSet::Vanguard));
            Vanguard += 1;
            break;
        case 4:
            choosedItem.push_back(Helmet("Helmet D", 7, 0, 9, 7, 0, 3, 5, ItemSet::Arcane));
            Arcane += 1;
            break;

        default:
            cout << "enter a valid number";
            break;
        }

        displayChestplate(character);
        cout << "What chestplate you want to equip";
        int ChestplateChoise;
        cin >> ChestplateChoise;
        switch (ChestplateChoise)
        {
        case 1:
            choosedItem.push_back(Chestplate("Chestplate A", 0, 10, 30, 10, 0, 2, 4, ItemSet::Timeless));
            Timeless += 1;
            break;
        case 2:
            choosedItem.push_back(Chestplate("Chestplate B", 0, 12, 25, 12, 0, 1.8, 3, ItemSet::Frostbound));
            Frostbound += 1;
            break;
        case 3:
            choosedItem.push_back(Chestplate("Chestplate C", 0, 8, 35, 8, 0, 2.5, 5, ItemSet::Vanguard));
            Vanguard += 1;
            break;
        case 4:
            choosedItem.push_back(Chestplate("Chestplate D", 0, 9, 40, 9, 0, 2.2, 2, ItemSet::Arcane));
            Arcane += 1;
            break;

        default:
            cout << "enter a valid number";
            break;
        }

        displayPants(character);
        cout << "What pants you want to equip";
        int pantsChoise;
        cin >> pantsChoise;
        switch (pantsChoise)
        {
        case 1:
            choosedItem.push_back(Pants("Pants A", 5, 5, 20, 5, 0, 1, 2, ItemSet::Timeless));
            Timeless += 1;
            break;
        case 2:
            choosedItem.push_back(Pants("Pants B", 6, 4, 18, 6, 0, 1.2, 3, ItemSet::Frostbound));
            Frostbound += 1;
            break;
        case 3:
            choosedItem.push_back(Pants("Pants C", 4, 6, 22, 4, 0, 0.8, 2, ItemSet::Vanguard));
            Vanguard += 1;
            break;
        case 4:
            choosedItem.push_back(Pants("Pants D", 5, 7, 19, 5, 0, 1.5, 4, ItemSet::Arcane));
            Arcane += 1;
            break;

        default:
            cout << "enter a valid number";
            break;
        }

        displayBoots(character);
        cout << "What boots you want to equip";
        int bootsChoise;
        cin >> bootsChoise;
        switch (bootsChoise)
        {
        case 1:
            choosedItem.push_back(Boots("Boots A", 3, 3, 15, 3, 0, 0.5, 1, ItemSet::Timeless));
            Timeless += 1;
            break;
        case 2:
            choosedItem.push_back(Boots("Boots B", 4, 2, 13, 4, 0, 0.7, 2, ItemSet::Frostbound));
            Frostbound += 1;
            break;
        case 3:
            choosedItem.push_back(Boots("Boots C", 2, 4, 17, 2, 0, 0.3, 1, ItemSet::Vanguard));
            Vanguard += 1;
            break;
        case 4:
            choosedItem.push_back(Boots("Boots D", 3, 5, 16, 3, 0, 0.9, 2, ItemSet::Arcane));
            Arcane += 1;
            break;

        default:
            cout << "enter a valid number";
            break;
        }

        displayWeapon(character);
        cout << "What weapon you want to equip";
        int weaponChoise;
        cin >> weaponChoise;
        switch (weaponChoise)
        {
        case 1:
            choosedItem.push_back(Weapon("Weapon A", 10, 10, 0, 0, 10, 1, 2, ItemSet::Timeless,1));
            Timeless += 1;
            break;
        case 2:
            choosedItem.push_back(Weapon("Weapon B", 12, 8, 0, 0, 12, 1.2, 3, ItemSet::Frostbound,1));
            Frostbound += 1;
            break;
        case 3:
            choosedItem.push_back(Weapon("Weapon C", 8, 12, 0, 0, 8, 0.8, 2, ItemSet::Vanguard,1));
            Vanguard += 1;
            break;
        case 4:
            choosedItem.push_back(Weapon("Weapon D", 11, 11, 0, 0, 11, 1.1, 4, ItemSet::Arcane,1));
            Arcane += 1;
            break;

        default:
            cout << "enter a valid number";
            break;
        }




    }

    cout << "Items chosen for the character:" << endl;
    for (const auto& item : choosedItem) {
        cout << "Name: " << item.Name << ", Stats: " << getItemSetName(item.Set) << endl;






    }

    if (Timeless == 5)
    {
        character->Health += 10000;
    }
    else  if (Frostbound == 5)
    {
        character->AP += 10;
    }
    else if (Vanguard == 5)
    {
        character->Defence *= 2;
    }
    else if (Arcane == 5)
    {
        character->AD += 20;
    }

    for (const auto& item : choosedItem) {
        character->Health += item.Health;
        character->AP += item.AP;
        character->AD = item.AD;
        character->Defence += item.Defence;
        character->Mana += item.Mana;
        character->MR += item.MR;
    }


    cout<<"Hp:" << character->Health<<endl;
    cout << "AP:" << character ->AP << endl;
    cout << "AD:" << character ->AD << endl;
    cout << "Deffence:" << character ->Defence << endl;
    cout << "Mana:" << character ->Mana << endl;
    cout << "Mr:" << character ->MR << endl;

};







Character* ChooseCharacter() {
    cout << "Choose your character:" << endl;
    cout << "1. Mage" << endl;
    cout << "2. Warrior" << endl;
    cout << "3. Tank" << endl;

    int chosenCharacter;
    cin >> chosenCharacter;

    cout << "Choose your character name: ";
    string name;
    cin >> name;

    Character* character = nullptr;
    Character player;
    list<Item> choosedItems;
 
    switch (chosenCharacter) {
    case 1:
        character = new Mage(name);
        MageItems(character);

       


       
        
        break;
    case 2:
        character = new Warrior(name);
        WarriorItems(character);

      


        break;
    case 3:
        character = new Tank(name);
        TankItems(character);

       


        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }
    
    return character;
}
class Arena
{
    Character FightA;
    Character FightB;
public:

    // Constructor
    Arena(Character a, Character b)
    {
        FightA = a;
        FightB = b;
    }

    // StartFight method
    void StartFight()
    {
        while (FightA.Health > 0 && FightB.Health > 0)
        {
            double damageDealtByA = FightA.Attack();
            FightB.RecieveDamage(damageDealtByA); // Fixed typo here: RecieveDamage to ReceiveDamage
            if (FightB.Health <= 0)
            {
                cout << "Fighter " << FightA.Name << " wins!" << endl;
               cout<< FightA.Health;
                break;
            }
            double damageDealtByB = FightB.Attack();
            FightA.RecieveDamage(damageDealtByB); // Fixed typo here: RecieveDamage to ReceiveDamage
            if (FightA.Health <= 0)
            {
                cout << "Fighter " << FightB.Name << " wins!" << endl;
               cout<< FightB.Health;
                break;
            }
        }
    }
};

// Define your Arena function
void ArenaFunction()
{
    cout << "Enter a num of battles: ";
    int Battles;
    cin >> Battles;
    int oneWins = 0, twoWins = 0;
    for (size_t i = 0; i < Battles; i++)
    {
        Character* myCharacter = ChooseCharacter();
        Character* myCharacter2 = ChooseCharacter();

        cout << "Fight between " << myCharacter->Name << " and " << myCharacter2->Name << endl;

        // Create an Arena object with the chosen characters
        Arena arena(*myCharacter, *myCharacter2);

        // Start the fight
        arena.StartFight();

        // Free memory allocated for characters
        delete myCharacter;
        delete myCharacter2;
    }
};


//template  is not right its not doing the input properly

int main() {
  
    ArenaFunction();
    //main >><<
 
        

        return 0;
    
}

