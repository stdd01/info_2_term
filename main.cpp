#include <iostream>
#include <string>

#include <vector>

using namespace std;

#define MAX_STRING_LENGTH 80

string divisions = "/,.";

vector<string> GetWordsList();

void DeleteDividers(string &sent, const string &dividers) {
    int found = 0;
    while (found < sent.size()) {
        found = sent.find_first_of(dividers);
        if (found != string::npos)
            sent.erase(found, 1);
    }
}


void DeleteDoubleSpaces(string &sent) {
    int pos = 0;
    while (pos != string::npos) {
        pos = sent.find("  ");
        if (pos >= 0) {
            sent.erase(pos, 1);
        }
    }
}

vector<string> GetInputWordsArray(vector<string> &array, string &sent) {
    int pos = sent.find(" ");
    while (pos > 0 && pos < sent.size()) {
        string word = sent.substr(0, pos);
        //cout << pos << " " << word << " |";
        array.push_back(word);
        sent.erase(0, pos + 1);
        //cout << sentense << endl;
        pos = sent.find(" ");
    }
    //добавляем последнее слово
    array.push_back(sent);

    return array;
}

bool HasdoubledLetters(string &sent) {
    for (int i = 0; i < sent.size(); i++) {

        char needle = (char) tolower(sent[i]);
        unsigned long int found = sent.rfind(needle);
        if (i != found) {
            return true;
        }
    }
    return false;
}

int main() {
//для ввода с клавиатуры
//   char input[MAX_STRING_LENGTH];
//   cout << "Please, enter your sentense: ";
//   cin.getline(input, MAX_STRING_LENGTH);
//   string sentense(input);

// для тестов
//string sentense("G*gas ,*jaJksd shd    *pds m,dddfdf,,d.");
    string sentense("G*gas. fd#d%f,cv   ббб,,,   df");

    //нужно ли заменить запятые на пробелы -- яявляются ли они разделителями слов?

    //clear sentense from ,.\/
    const string dividers("/,.'*#\%");//экранируем оператор форматного вывода \%
    DeleteDividers(sentense, dividers);
    //cout << sentense << endl;

    DeleteDoubleSpaces(sentense);
    //cout << sentense << endl;
    //выделяем слово слева до первого пробела и удаляем его из строки
    vector<string> resultList;

    GetInputWordsArray(resultList, sentense);
    cout << "Входной массив слов: ";
    for (string &word : resultList) {
        cout << word << " ";
    }

    string res;//выходная строка

    for (string &word : resultList) {
        if (HasdoubledLetters(word)) {
            res.append(word);
            res.append(" ");
        }
    }
//вариант с обычным for
//   for (int i = 0; i < resultList.size(); i++) {
//         if (HasdoubledLetters(resultList[i])) {
//           cout << resultList[i] << " " << endl;
//       };
//     }

    resultList.clear();

    if (!res.empty()) {
        cout << "\nРезультат: буквы повторяются в словах: " << res;
    } else cout << "\nРезультат: нет слов с повторяющимися буквами";

    return 0;
}
