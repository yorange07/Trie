#include "Trie.hpp"
#include <iostream>

using namespace std;

int main()
{
    string words[] =
    {
        {"Hello"},
        {"Goodbye"},
        {"Thanks"},
        {"Allright"},
        {"Ok"},
        {"are"},
        {"How"},
        {"you"}
    };
    TrieNode * dict = getNewNode();
    for(auto& word : words)
        insert(dict, word);

    char but = 0;
    
    string massage;
    
    cout << "Введите слово" << endl;
    while (but != 'n')
    {

        string* curr_str = new string;
        getline(cin, *curr_str);
        string* str = new string;
        *str = searchForAdding(dict, *curr_str);
        if (*str != "0")
        {
            cout << "Вы имеете ввиду " << *str << "? (y - принять, n - пропустить)" << endl;
            char ed = 0;
            
            while (ed != 'y' && ed != 'n')
            {
                cin >> ed;
                switch(ed)
                {
                    case 'y':
                        massage = *str;
                        break;
                        
                    case 'n':
                        massage = *curr_str;
                        break;
                        
                    default:
                        cout << "Третьего не дано. Попробуйте снова!" << endl;
                        break;
                }
            }
        }
        
        else massage = *curr_str;
        
        cout << "Продолжить ввод? (y - да, n - нет)" << endl;
        
        cin >> but;
        switch(but)
        {
            case 'y':
                cout << "Введите слово" << endl;
                break;
                
            case 'n':
                cout << "Ввод окончен!" << endl;
                break;
                
            default:
                cout << "Третьего не дано. Попробуйте снова!" << endl;
                break;
        }
        
        getline(cin, *curr_str);
        str = nullptr;
        curr_str = nullptr;
        delete str;
        delete curr_str;
    }
    
    
    return 0;
}
