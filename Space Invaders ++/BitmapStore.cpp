#include <assert.h>
#include"BitmapStore.h"

using namespace sf;
using namespace std;

BitmapStore* BitmapStore::m_s_Instance = nullptr;

BitmapStore::BitmapStore()
{
    assert(m_s_Instance == nullptr);
    m_s_Instance = this;
}

void BitmapStore::addBitmap(string const& filename)
{
    // Get a reference to m_Textures using m_s_Instance
    auto& bitmapsMap = m_s_Instance->m_BitmapsMap;

    // auto is the equivalent of map<string, Texture>
    // Create an iterator to hold a key-value-pair (kvp)
    // and search for the required kvp using the passed ni filename
    auto keyValuePair = bitmapsMap.find(filename);

    // auto is the equivalent to map<string, Texture>::iterator
    // No match found, then save the texture in the map
    if (keyValuePair == bitmapsMap.end())
    {
        // Create a new key value pair using the filename
        auto& texture = bitmapsMap[filename];

        // Load the texture from file
        texture.loadFromFile(filename);
    }
}

Texture& BitmapStore::getBitmap(string const& filename)
{
    // Get a reference to m_Textures using m_s_Instance
    auto& m = m_s_Instance->m_BitmapsMap;

    // auto is the equivalent of map<string, Texture>
    // Create an iterator to hold a key-value-pair (kvp)
    // and search for the required kvp using the passed ni filename
    auto keyValuePair = m.find(filename);

    // auto is the equivalent to map<string, Texture>::iterator
    // Did we find a match
    if (keyValuePair != m.end())
    {
        return keyValuePair->second;
    }
    else
    {
#ifdef debuggingOnConsole
        cout <<
            "BitmapStore::getBitmap()Texture not found."
            << endl;
#endif // debuggingOnConsole

        return keyValuePair->second;
    }
}