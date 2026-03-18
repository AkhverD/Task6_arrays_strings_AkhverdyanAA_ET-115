// СТРОКИ

int main() {
    // с setlocale по какой-то причине
    // некорректно выводит русский язык, 
    // поэтому использую это
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string str;
    cout << "Введите строку: ";
    getline(cin, str);

    // создаем массив со словами с запасом, также счетчик,
    // чтобы точно знать, сколько слов в строке
    string words[100];
    int count = 0;

    // разбиваем строку
    string word = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            word += str[i];
        }
        else {
            if (word != "") {
                words[count] = word;
                count++;
                word = "";
            }
        }
    }

    // добавляем последнее слово (обрабатываем
    // отдельно, потому что строка пробелом не
    // заканчивается
    if (word != "") {
        words[count] = word;
        count++;
    }

    // ищем индексы самого короткого и длинного слов
    int min = 0, max = 0;

    for (int i = 1; i < count; i++) {
        if (words[i].length() < words[min].length())
            min = i;

        if (words[i].length() > words[max].length())
            max = i;
    }

    // меняем местами самое длинное и короткое слова
    string temp = words[min];
    words[min] = words[max];
    words[max] = temp;


    for (int i = 0; i < count; i++) {
        cout << words[i] << " ";
    }
    cout << endl;

    system("pause");

    return 0;
}
