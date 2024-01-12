#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item {
public:
    string name;
    string description;
};

class Block {
public:
    string name;
    string texture;
    float hardness;

    Block(string name, string texture, float hardness)
        : name(name), texture(texture), hardness(hardness) {}
};

class Chest : public Block {
protected:
    vector<Item> content;
    bool lockStatus;

public:
    Chest(string chestName) : lockStatus(false), Block(chestName, "Chest", 0.5) {}

    void lock() { lockStatus = true; }
    void unlock() { lockStatus = false; }

    void add_item(Item item) { content.push_back(item); }

    void show_content() {
        if (!lockStatus) {
            for (const Item &elem : content) {
                cout << elem.name << endl;
            }
        } else {
            cout << "Chest is locked" << endl;
        }
    }
};

class EnderChest : public Chest {
private:
    static vector<Item> sharedContent;

public:
    EnderChest(int chestNumber) : Chest("endchest" + to_string(chestNumber)) {}

    void add_item_shared(Item item) { sharedContent.push_back(item); }

    void show_content_shared() {
        cout << "Shared Ender Chest Content:" << endl;
        for (const Item &elem : sharedContent) {
            cout << elem.name << endl;
        }
    }
};

vector<Item> EnderChest::sharedContent; // Initializing the static member variable

int main() {
    vector<EnderChest> enderChests;

    for (int i = 0; i < 3; ++i) {
        enderChests.emplace_back(i);
    }

    enderChests[0].add_item_shared(Item{"Ender Pearl", "A mysterious ender pearl"});
    enderChests[0].show_content_shared();

    enderChests[1].show_content_shared(); // Content is shared among all Ender Chests

    return 0;
}