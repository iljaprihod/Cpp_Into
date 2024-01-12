#include <iostream>
#include <string>

using namespace std;

class Block
{
private:
    float hp;
    float modifier = 1;

public:
    string name;
    string texture;
    float hardness;
    float x, y, z;

    // Constructor
    Block(string n, string t, float h, float x, float y, float z) : name(n),
                                                                    texture(t), hardness(h)
    {
        hp = 100;
    }

    float get_hp()
    {
        return hp;
    }

    void apply_dmg(int val)
    {
        hp -= val * modifier + 12;
    }
};

class MinecraftTool
{
public:
    string name;
    float damageModifier; // Additional damage modifier

    MinecraftTool(string n, float dmgModifier = 1.0) : name(n), damageModifier(dmgModifier) {}

    void mine(Block &block)
    {
        int damageDealt;

        // Applying damage based on the block type
        if (block.name == "Stone")
        {
            damageDealt = static_cast<int>(10 * damageModifier * 2); // 2 times 
        else
        {
            damageDealt = static_cast<int>(10 * damageModifier); // Normal damage 
        }

        cout << name << " mined " << block.name << " and dealt " << damageDealt << " damage." << endl;
        block.apply_dmg(damageDealt);

        cout << "Remaining HP of " << block.name << ": " << block.get_hp() << endl;
    }

    void dig(Block &block)
    {
        int damageDealt;

        // Applying damage based on the block type
        if (block.name == "Dirt")
        {
            damageDealt = static_cast<int>(8 * damageModifier * 2); // 2 times
        }
        else
        {
            damageDealt = static_cast<int>(8 * damageModifier); // Normal damage 
        }

        cout << name << " dug " << block.name << " and dealt " << damageDealt << " damage." << endl;
        block.apply_dmg(damageDealt);

        cout << "Remaining HP of " << block.name << ": " << block.get_hp() << endl;
    }

    void attack(Block &block)
    {
        int damageDealt = static_cast<int>(15 * damageModifier); // Normal damage

        cout << name << " attacked " << block.name << " and dealt " << damageDealt << " damage." << endl;
        block.apply_dmg(damageDealt);

        cout << "Remaining HP of " << block.name << ": " << block.get_hp() << endl;
    }
};

int main()
{
    Block dirt("Dirt", "Brown", 0.5, 10, 10, 10);
    Block stone("Stone", "Grey", 1.5, 10, 10, 10);

    MinecraftTool pickaxe("Iron Pickaxe", 2.0);  // 2 times damage 
    MinecraftTool shovel("Diamond Shovel", 2.0); // 2 times damage

    pickaxe.mine(stone);
    shovel.dig(dirt);

    pickaxe.attack(dirt);
    shovel.attack(stone);

    return 0;
}