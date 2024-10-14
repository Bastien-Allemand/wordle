#include <iostream>
#include <ctime>

const char* words[] = { "pomme", "table", "livre", "chaud", "arbre" };
int leng = sizeof(words) / sizeof(words[0]);
const char* wordsplayed[5];
int u = 0;

void GetSecretWord(const char*& secretword) 
{
    static const char* preced = "";

    int num = rand() % leng;

    const char* word = words[num];

    if (strcmp(word, preced) == 0) 
    {
        GetSecretWord(secretword);
    }
    else {
        preced = word;
        secretword = word;
    }
}

void GetPlayerGuess(char* guessed) 
{
    do 
    {
        std::cout << "Entrez un mot de 5 lettres : ";

        std::cin >> guessed;

        std::cout << std::endl;

    } while (strlen(guessed) != 5);
}

void CompareWords(char* guessed, const char* secretword)
{
    for (int i = 0; guessed[i] != '\0'; i++) 
    {
        if (guessed[i] == secretword[i])
        {
            std::cout << "\033[32m" << guessed[i] << "\033[0m";
        }
        else
        {
            bool found = false;
            for (int y = 0; secretword[y] != '\0'; y++) 
            {
                if (guessed[i] == secretword[y])
                {
                    std::cout << "\033[33m" << guessed[i] << "\033[0m";
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                std::cout << "\033[31m" << guessed[i] << "\033[0m";
            }
        }
    }
    std::cout << std::endl;
}
int playgame() 
{
    const char* secretword;
    GetSecretWord(secretword);
    while (true)
    {
        char guessed[6];
        GetPlayerGuess(guessed);
        CompareWords(guessed, secretword);
        if (strcmp(guessed, secretword) == 0)
        {
            std::cout << "Bravo !" << std::endl;
            wordsplayed[u] = secretword;
            u++;
            if (u < 5) {
                playgame();
            }
            break;
        }
    }
    return 0;
}

int main()
{
    srand(time(0));
    playgame();
    return 0;
}