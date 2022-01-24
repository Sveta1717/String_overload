//В класс String добавить : -перегрузка операции =, -перегрузка операции == (лексикографическое сравнение двух строк)
//- перегрузка операции >, -перегрузка операции <, -перегрузка операции >=, -перегрузка операции <=
//-перегрузка операции !=, -перегрузка() (повторная инициализация строки)
//- перегрузка[](доступ к элементу строки по индексу, предусмотреть возможность обращения к несуществующему элементу.
//- перегрузка операции + (String + String), - перегрузка операции += (конкатенация String)
//- перегрузка операции += (конкатенация char*), - перегрузка операции + (String + char*)
//- перегрузка операции + (char* +String), - перегрузка операции + (String + char)
//- перегрузка операции + (char + String), - перегрузка операции << (ostream&, String) - показ на экран
//- перегрузка операции >> (istream&, String) - ввод с клавиатуры
//- перегрузка операции char* () - преобразование в char*
//-перегрузка операции int() - конвертация строки в целое число(если это возможно)
//- перегрузка операции double() - конвертация строки в вещественное число(если это возможно)

#include "String.h"

String::String(const char* text, unsigned int capacity)
{
    Initialize(text);
}

String::String()
{
    Initialize("*");
}

String::String(unsigned int capacity)
{
    Initialize("", capacity);
}

String::String(const String& original)
{
    Initialize(original.text, original.capacity);
}

String::~String()
{
    delete[] text;
}

void String::SetString(const char* text)
{
    length = strlen(text);
    if (length >= capacity)
    {
        delete[] this->text;
        capacity = length + 20;
        this->text = new char[capacity];
    }
    strcpy_s(this->text, length + 1, text);
}

const char* String::GetCharArray() const
{
    return text;
}

int String::GetLength() const // количество символов
{
    return length;
}

// метода SetLength не должно быть!

int String::GetCapacity() const // резерв памяти
{
    return capacity;
}

void String::Clear()
{
    text[0] = '\0';
    length = 0;
}

void String::ShrinkToFit()
{
    if (length + 1 == capacity)
    {
        return;
    }

    capacity = length + 1;
    char* temp = new char[capacity];
    strcpy_s(temp, capacity, text);
    delete[] text;
    text = temp;
}

char String::GetCharAt(unsigned int index)
{
    if (index > 0 && index < length + 1)
    {
        return text[index - 1];
    }
    else
    {
        return -1;
    }
}

void String::Print()
{
    cout << GetCharArray() << "\n";
}

void String::PrintLn()
{
    cout << GetCharArray();
    for (int i = 0; i < 2; i++)
    {
        cout << "\n";
       
    }
}

void String::GetLine()
{
    cout << "Enter the line\n";
    string line;
    getline(cin, line);
    cout << line << "\n";
}

int String::CompareTo(const String& text) const
{
    cout << "Enter the line\n";
    string line;
    getline(cin, line);
    int res;

    res = line.compare(this->text);

    return res;
}

int String::CompareTo(const char* line) const
{
    for (int i = 0; i < length + 1; i++)
    {
        if (this->text[i] == line[i] && sizeof(this->text) == sizeof(line))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void String::Concat(const String& text) const
{
    cout << "Enter the line\n";
    string line;
    getline(cin, line);

    cout << this->text + line;
}

void String::Concat(const char* line)
{
    cout << "Enter the line\n";
    string text = this->text;
    cout << text.append(line);
}

void String::Concat(int x)
{
    char s[7];
    char* l = _itoa(x, s, 10);

    string text = this->text;
    cout << text.append(l) << "\n";
}

void String::Concat(double y)
{
    string text = this->text;
    cout << text.append(to_string(y)) << "\n";
}

String* String::Split(const char* separator, int& pieces) const
{
    String* text = new String[pieces];
    int k = 1;
    pieces = k;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < strlen(separator); j++)
        {
            if (String::text[i] == ' ')
            {
                String::text[i] = separator[j];
                k++;
            }
        }
    }
    return &text[pieces];
}

String String::ToLower()
{
    for (int i = 0; i < length; i++)
    {
        if (text[i] > 'A' && text[i] < 'Z')
        {
            text[i] += 'z' - 'Z';
        }
        if (text[i] > 'А' && text[i] < 'Я')
        {
            text[i] += 'я' - 'Я';
        }
    }
    return text;
}

String String::ToUpper()
{
    for (int i = 0; i < length; i++)
    {
        if (text[i] > 'a' && text[i] < 'z')
        {
            text[i] += 'Z' - 'z';
        }
        if (text[i] > 'а' && text[i] < 'я')
        {
            text[i] += 'Я' - 'я';
        }
    }
    return text;
}

void String::SortAZ()
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        for (int j = 0; text[j] != '\0'; j++)
        {
            if (text[i] < text[j])
            {
                char temp = text[i];
                text[i] = text[j];
                text[j] = temp;
            }
        }
    }
}

void String::SortZA()
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        for (int j = 0; text[j] != '\0'; j++)
        {
            if (text[i] > text[j])
            {
                char temp = text[i];
                text[i] = text[j];
                text[j] = temp;
            }
        }
    }
}

void String::Trim()
{
    string text = this->text;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ' && text[length - 1] == ' ')
        {
            text.erase(i, 1);
        }
        else if (text[i] == '\0' && text[i - 1] == ' ')
        {
            text.erase(i - 1, 1);
        }
    }
}

void String::TrimEnd()
{
    string text = this->text;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ' && text[length - 1] == ' ')
        {
            text.erase(length - 1, 1);
        }
    }
}

void String::TrimStart()
{
    string text = this->text;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ' && text[length - 1] == ' ')
        {
            text.erase(i, 1);
        }
    }
}

void String::Remove(int x)
{
    string text = this->text;
    text.erase(x);
}

void String::Remove(int start, int count)
{
    string text = this->text;
    text.erase(start, count);
}

bool String::Contains(const String& text)
{
    cout << "Enter the line\n";
    string line;
    getline(cin, line);
    bool res;

    res = line.compare(this->text);

    return res;
}

bool String::EndsWith(const String line) const
{
    char* temp = new char[sizeof(line) + 1];
    unsigned int length_temp = strlen(temp);
    if (length_temp > length)
    {
        return false;
    }

    for (int i = length - length_temp; i <= length; i++)
    {

        if (strcmp(text, temp) == 0)
        {
            return true;
        }
    }
    delete[]temp;

    return false;
}

bool String::StartsWith(const String line) const
{
    char* temp = new char[sizeof(line) + 1];
    unsigned int length_temp = strlen(temp);
    if (length_temp > length)
    {
        return false;
    }

    for (int i = 0; i <= length_temp; i++)
    {

        if (strcmp(text, temp) == 0)
        {
            return true;
        }
    }
    delete[]temp;

    return false;
}

bool String::Equals(const String text) const
{
    cout << "Enter the line\n";
    string line;
    getline(cin, line);

    if (line == this->text)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int String::IndexOf(char ch)
{
    string text = this->text;
    return text.find_first_of(ch);
}

int String::LastIndexOf(char ch)
{
    string text = this->text;
    return text.find_last_of(ch);
}

int String::IndexOf(const String text) const
{
    cout << "Enter the line\n";
    string line;
    getline(cin, line);
    return line.find_first_of(this->text);
}

int String::LastIndexOf(const String text) const
{
    cout << "Enter the line\n";
    string line;
    getline(cin, line);
    return line.find_last_of(this->text);
}

void String::Replace(char R, char Z)
{
    for (int i = 0; i < length; i++)
    {
        if (text[i] == R)
        {
            text[i] = Z;
        }
    }
}

void String::Reverse()
{
    char* temp = new char[capacity];

    for (int i = 0; i < length; i++)
    {
        temp[i] = this->text[length - i - 1];
    }

    temp[length] = '\0';
    delete[] this->text;
    this->text = temp;
    
}

void String::Shuffle()
{
    for (int i = 0; i < length; i++)
    {
        int j = i + rand() % (length - i);
        char temp = text[j];
        text[j] = text[i];
        text[i] = temp;
    }
    cout << text << "\n";
}

void String::RandomFill()
{
    for (int i = 0; i < capacity; i++)
    {
        text[i] = rand() % 256;
        puts(text);
    }
}

void String::Initialize(const char* str, int capacity) {
    length = strlen(str);
    this->capacity = (capacity > length) ? capacity : length + 20;
    this->text = new char[this->capacity];
    strcpy_s(this->text, length + 1, str);
}

String& String::operator = (String& s)
{
    SetString(s.text);
    return *this;
}

bool String::operator == (const char* s)
{
    return strcmp(text, s) ? false : true;
}

bool String::operator > (String s)
{
    s.CompareTo(text);
    if (this > 0)
        return true;
    return false;
}

bool String::operator < (String s)
{
    s.CompareTo(text);
    if (this < 0) 
        return true;
    return false;
    
}

bool String::operator >=(String* s)
{    
    if (this > s || this == s)
        return true;
    return false;
}

bool String::operator <=(String* s)
{   
    if (this < s || this == s) 
        return true;
    return false;
}

bool String::operator !=(String* s)
{    
    if (this == s) 
        return false;
    return true;
}

String& String::operator ()(String& s)
{
    s.SetString(text);
    return *this;
}

char& String::operator [](int index)
{
    if (index >= this->capacity)
        return this->text[0];    
    return this->text[index];;
}

String* String::operator +(String& s)
{
    Concat(s);
    return this;
}

String* String::operator +(const char* s)
{
    Concat(s);
    return this;
}

void String::operator+=(const char* s)
{
    int new_capacity = capacity + strlen(s) + 1;
    char* new_string = new char[new_capacity];

    strcat(text, s);
    delete[] new_string;          
}

void String::operator+=(String& s)
{
    capacity += sizeof(s) + 1;
    char* new_string = new char[capacity];
    strcpy(new_string, text);
    strcat(new_string, s.GetCharArray());
    delete[] text;
    text = new_string;
}

String::operator char* ()
{
    char* temp = new char[255];
    strcpy_s(temp, length + 1, text);
    return temp;
}

String::operator int()
{
    return atoi(text);
}

String::operator double()
{

    return atof(text);
}

ostream& operator <<(ostream& out, String s)
{
    for (int i = 0; i < s.GetLength(); i++)
        out << (s.GetCharArray())[i];
    return out;
}
