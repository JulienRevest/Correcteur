#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> getWords(std::string input)
{
    input += ' ';
    std::string word = "";
    std::vector<std::string> output;
    for (auto x : input)
    {
        if (x == ' ')
        {
            word.insert(word.begin(), '#');
            word.append("# ");
            output.push_back(word);
            word.clear();
        }
        else
            word += x;
    }
    return output;
}

std::vector<std::string> getTrigrams(std::string input) {
    std::vector<std::string> output;
    for (int i = 0; i < input.length(); ++i)
    {
        if (i % 3 == 0)
        {
            std::string trigram = input.substr(i, i + 3);
            trigram.erase(trigram.find_last_not_of(" \t\n\r\f\v") + 1);
            output.push_back(trigram);
        }
    }
    return output;
}

int main()
{
    std::cout << "Write a phrase\n";
    std::string line;
    std::string input;
    std::ifstream dictionnary("liste.de.mots.francais.frgut.txt");
    std::getline(std::cin, input);
    if (dictionnary.is_open())
    {
        std::vector<std::string> out = getWords(input);
        for (int i = 0; i < out.size(); ++i)
        {
            std::cout << out[i] << " | Trigrammes: ";
            std::vector<std::string> trigrams = getTrigrams(out[i]);
            for (int j = 0; j < trigrams.size(); ++j)
            {
                std::cout << trigrams[j] << ",";
            }
            std::cout << std::endl;
        }
        /*
        while (std::getline(dictionnary, line))
        {
            std::cout << line << '\n';
        }
        dictionnary.close();*/
    }
    else
        std::cout << "Unable to open dictionnary" << std::endl;

    std::cin.get();
    return 0;
}