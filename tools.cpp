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

    MinecraftTool(string n) : name(n) {}

    void mine(Block &block)
    {
        cout << name << " is mining " << block.name << "..." << endl;
        block.apply_dmg(10);
        cout << "Remaining HP of " << block.name << ": " << block.get_hp() << endl;
    }

    void dig(Block &block)
    {
        cout << name << " is digging " << block.name << "..." << endl;
        block.apply_dmg(8);
        cout << "Remaining HP of " << block.name << ": " << block.get_hp() << endl;
    }

    void attack(Block &block)
    {
        cout << name << " is attacking " << block.name << "..." << endl;
        block.apply_dmg(15);
        cout << "Remaining HP of " << block.name << ": " << block.get_hp() << endl;
    }
};

int main()
{
    Block dirt("Dirt", "Brown", 0.5, 10, 10, 10);
    Block stone("Stone", "Grey", 1.5, 10, 10, 10);

    MinecraftTool pickaxe("Iron Pickaxe");
    MinecraftTool shovel("Diamond Shovel");

    pickaxe.mine(dirt);
    shovel.dig(dirt);

    pickaxe.attack(stone);
    shovel.attack(stone);

    return 0;
}