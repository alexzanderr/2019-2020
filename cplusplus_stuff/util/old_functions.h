#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <windows.h>
#include <climits>
#include <cctype>
#include <ctime>
#include <cstdlib>

#include "typedef.h"

using namespace std;

inline int ReturnRandomValueInSpecifiedInterval(UCI &max)
{
    static bool initialization = true;
    if(initialization)
    {
        srand(time(0));
        initialization = false;
    }
    return rand() % max + 1;
}

UCI SIXTY = 60;
UCI MATRIX_ROWS = 10;
UCI MATRIX_COLS = 10;
UCI TEN_THOUSAND = 1e+4;
CD EPSILON = 1e-6;
CI MINUS_ONE_VALUE = -1;

template <typename T = string>
T StringReplaceLastGroup_of_inserted_CharactersFounded(const T &word, const T &old_string, const T &new_string)
{
    T returned_word = word;
    UCI old_string_size = old_string.size();
    int index = returned_word.rfind(old_string);
    if(index >= 0)
    {
        returned_word.replace(index, old_string_size, new_string);
    }
    return returned_word;
}

template <typename T = string>
T StringReplaceFirstGroup_of_inserted_CharactersFounded(const T &word, const T &old_string, const T &new_string)
{
    T returned_word = word;
    UCI old_string_size = old_string.size();
    int index = returned_word.find(old_string);
    if(index >= 0)
    {
        returned_word.replace(index, old_string_size, new_string);
    }
    return returned_word;
}

template <typename T = string>
T StringReplaceAllGroup_of_inserted_CharactersFound(const T &word, const T &old_string, const T &new_string)
{
    string returned_word = word;
    UCI old_string_size = old_string.size();
    for(int index = returned_word.find(old_string); index >= 0; index = returned_word.find(old_string, index + 1))
    {
        returned_word.replace(index, old_string_size, new_string);
    }
    return returned_word;
}

template <typename T = string>
T StringInitializationWith_inserted_Character(const T &word, CC &insert_char)
{
    T returned_word = word;
    UCI size = word.size() - 2;
    returned_word.replace(1, size, size, insert_char);
    return returned_word;
}

template <typename T = string>
T StringUpdateWithInsertedCharacterFromFullLine(const T &word, CC &insert_char, CC &character)
{
    T word_copy = word;
    T returned_word = StringInitializationWith_inserted_Character<>(word_copy, character);
    int index = word.find(insert_char, 0);
    while(index >= 0)
    {
        if(returned_word[index] == '-')
        {
            returned_word[index] = insert_char;
        }
        index = word.find(insert_char, index + 1);
    }
    return returned_word;
}



template <typename T>
void PrintParameter(const T &param)
{
    cout << param << " ";
}

template <typename T = char>
void ArrayOfCharactersToTitleCaseConversion_TemplateFunction(T *array)
{
    bool toUpperConv = true;
    for(size_t index = 0; array[index] != '\0'; index++)
    {
        T currentChar = array[index];
        if(isspace(currentChar))
        {
            toUpperConv = true;
            continue;
        }
        else if(!isalpha(currentChar))
        {
            continue;
        }
        if(toUpperConv)
        {
            array[index] = toupper(currentChar);  // prima litera din cuvant este mare
            toUpperConv = false;
        }
        else
        {
            array[index] = tolower(currentChar); // celelalte litere sunt mici
        }
    }
}

template <typename T, typename R = int>
R BinarySearch_for_index_of_Element(const T *array, UCI &size, const T &element)
{
    UI start_index = 0;
    UI stop_index = size - 1;
    while(start_index < stop_index)
    {
        UI middle_index = (start_index + stop_index) / 2;
        if(array[middle_index] == element)
        {
            return middle_index;
        }
        else if(array[middle_index] < element)
        {
            start_index = middle_index + 1;
        }
        else
        {
            stop_index = middle_index - 1;
        }
    }
    return MINUS_ONE_VALUE;
}

template <typename T, typename B = bool>
B BinarySearch(const T *array, UCI &size, const T &element)
{
    UI start_index = 0;
    UI stop_index = size - 1;
    while(start_index < stop_index)
    {
        UI middle_index = (start_index + stop_index) / 2;
        if(array[middle_index] == element)
        {
            return true;
        }
        else if(array[middle_index] < element)
        {
            start_index = middle_index + 1;
        }
        else
        {
            stop_index = middle_index - 1;
        }
    }
    return false;
}

template <typename T = int>
T ReturnNumber_of_Pairs_From_Array_that_match_the_diophantine_Ecuation
    (const T *array, UCI &size, UCI &a, UCI &b, UCI &c)
{
    T array_copy[size];
    T pairs = 0;
    for(size_t index = 0; index < size; index++)
    {
        array_copy[index] = array[index];
    }
    for(size_t index = 0; index < size; index++)
    {
        if(array_copy[index] != MINUS_ONE_VALUE)
        {
            const T x = array_copy[index];
            const T y = sqrt((c - (a * x * x)) / b);
            if(BinarySearch(array_copy, size, y))
            {
                pairs++;
                array_copy[index] = MINUS_ONE_VALUE;
                array_copy[BinarySearch_for_index_of_Element(array_copy, size, y)] = MINUS_ONE_VALUE;
            }
            if(a == b)
            {
                pairs++;
            }
        }
    }
    return pairs;
}

template <typename T = int>
T Amount_from_1_to_N(UCI &limit)
{
    T amount = 0;
    for(size_t index = 1; index <= limit; index++)
    {
        amount += index;
    }
    return amount;
}

template <typename T = int>
T Multiplication_from_1_to_N(UCI &limit)
{
    T multiplication = 1;
    for(size_t index = 1; index <= limit; index++)
    {
        multiplication *= index;
    }
    return multiplication;
}

template <typename T>
T ArrayAverage_of_Elements_TemplateFunction(const T *array, UCI& size)
{
    T amount = array[0];
    for(size_t index = 1; index < size; index)
    {
        amount += array[index];
    }
    return double(amount) / double(size);
}

template <typename T = int>
T* FibonacciArrayPrintNumber_of_Elements(const T &n_elemets)
{
	UI f1 = 1;
	UI f2 = 0;
	UI arrayElem = 0;
	LI arrayAmount = 0;
	arrayAmount += f1;
	int *fibonacciArray = new int [n_elemets + 2];
    fibonacciArray[0] = f2;
    fibonacciArray[1] = f1;
    cout << "[FibonacciArray]: < " << f2 << " " << f1 << " ";
	for(size_t index = 0; index < n_elemets; index++)
	{
		arrayElem = f1 + f2;
		arrayAmount += arrayElem;
		fibonacciArray[index + 2] = arrayElem;
		cout << arrayElem << " ";
		f2 = f1;
		f1 = arrayElem;
	}
	cout << ">\n[FibonacciArray_INFO]: <N_Elements: " << n_elemets << ">___<ArrayAmount: " << arrayAmount << ">___" << endl;
	return fibonacciArray;
}

template <typename T = double>
T ConvertInch2Milimeters(const T &inch)
{
    return 25.4 * inch;
}
template <typename T = double>
T ConvertInch2Centimeters(const T &inch)
{
    return 2.54 * inch;
}
template <typename T = double>
T ConvertInch2Decimeters(const T &inch)
{
    return 0.254 * inch;
}
template <typename T = double>
T ConvertInch2Meters(const T &inch)
{
    return 0.0254 * inch;
}
template <typename T = double>
T ConvertMilimeters2Inch(const T &milimeters)
{
    return milimeters / 25.4;
}
template <typename T = double>
T ConvertCentimeters2Inch(const T &centimeters)
{
    return centimeters / 2.54;
}
template <typename T = double>
T ConvertDecimeters2Inch(const T &decimeters)
{
    return decimeters / 0.254;
}
template <typename T = double>
T ConvertMeters2Inch(const T &meters)
{
    return meters / 0.0254;
}

template <typename T>
bool EvenValueUsingPointer(const T &param)
{
    return param % 2 == 0;
}

template <typename T>
bool BoolMaxBetween_2_Numbers(const T &f_param, const T &s_param)
{
    return f_param > s_param;
}
template <typename T>
bool BoolMinBetween_2_Numbers(const T &f_param, const T &s_param)
{
    return f_param < s_param;
}
template <typename T>
T Return_data_type_T_MAX_Between_2_Numbers(const T &f_param, const T &s_param)
{
    return f_param > s_param;
}
template <typename T>
T Return_data_type_T_MIN_Between_2_Numbers(const T &f_param, const T &s_param)
{
    return f_param < s_param;
}

template <typename T>
T* ReturnAdressUsingPointersToMaxBetween_2_Numbers(const T *f_param, const T *s_param)
{
    return f_param > s_param;
}

template <typename T>
T& ReturnReferenceToMaxBetween_2_Numbers(const T &f_param, const T &s_param)
{
    return f_param > s_param;
}

template <typename T>
T& ArrayReturn_reference_of_element_at_specified_index(const T *array, UCI &index)
{
    return array[index];
}

template <typename T>
T ReturnAmount_of_2_Numbers(const T &f_param, const T &s_param)
{
    return f_param + s_param;
}

template <typename T>
T ReturnSubstraction_of_2_Numbers(const T &f_param, const T &s_param)
{
    return f_param - s_param;
}

template <typename T>
T ReturnMultiplication_of_2_Numbers(const T &f_param, const T &s_param)
{
    return f_param * s_param;
}

template <typename T>
T ReturnDivision_of_2_Numbers(const T &f_param, const T &s_param)
{
    if(s_param == 0)
    {
        return MINUS_ONE_VALUE;
    }
    return f_param / s_param;
}

template <typename T>
T ReturnValueTo_the_power_of_2_Function(const T &param)
{
    return param * param;
}

template <typename T>
void ArrayMaxAndMinLimitsUsingPointers(const T *start, const T *stop, const T *min, const T *max)
{
    *min = *start;
    *max = *start;
    for(T *index = start + 1; index != stop; index++)
    {
        if(*index < *min)
        {
            *min = *index;
        }
        if(*index > *max)
        {
            *max = *index;
        }
    }
}

template <typename T>
void ArrayCountOfPositives_Negatives_And_Zero_Elements_UsingPointers(const T *start, const T *stop, UI *positives, UI *negatives, UI *zeros)
{
    *positives = 0;
    *negatives = 0;
    *zeros = 0;
    for(T *index = start; index != stop; index++)
    {
        if(DecimalEqualVerification(1e-3, *index))
        {
            (*zeros)++;
        }
        else if(*index < 0)
        {
            (*negatives)++;
        }
        else
        {
            (*positives)++;
        }
    }
}

template <typename T>
T ArrayMultiplicationOfPositiveElements(const T *start, const T *stop)
{
    T amount = *start;
    for(T *index = start + 1; index != stop; index++)
    {
        if(*index > 0)
        {
            amount *= *index;
        }
    }
    return amount;
}

template <typename T>
T ArrayAmountOfNegativeElements(const T *start, const T *stop)
{
    T amount = *start;
    for(T *index = start + 1; index != stop; index++)
    {
        if(*index < 0)
        {
            amount += *index;
        }
    }
    return amount;
}

template <typename T>
void ApplyDiscountToArrayProductsByPointers(const T *start, const T *stop, const T &perc_disc, const T &min)
{
    for(T *index = start; index != stop; index++)
    {
        if(*index > min)
        {
            *index *= (1 - perc_disc);
        }
    }
}

template <typename T>
T ReturnArrayAmountUsingPointers(const T *start, const T *stop)
{
    T amount = *start;
    for(T *index = start + 1; index != stop; index++)
    {
        amount += *index;
    }
    return amount;
}

template <typename T>
void ArrayMaxAndMinLimits(const T *array, UCI &size, T &min, T &max)
{
    ArrayMinElement(array, size, min);
    ArrayMaxElement(array, size, max);
}

template <typename T>
void ArrayMinElement(const T *array, UCI &size, T &min)
{
    min = array[0];
    for(size_t index = 0; index < size; index++)
    {
        if(array[index] > min)
        {
            min = array[index];
        }
    }
}

template <typename T>
void ArrayMaxElement(const T *array, UCI &size, T &max)
{
    max = array[0];
    for(size_t index = 0; index < size; index++)
    {
        if(array[index] > max)
        {
            max = array[index];
        }
    }
}

template <typename T>
void ArrayPositiveElementsCounting(const T *array, UCI &size, UI &positive_elements)
{
    positive_elements = 0;
    for(size_t index = 0; index < size; index++)
    {
        if(array[index] > 0)
        {
            positive_elements++;
        }
    }
}

template <typename T>
void SwapFunctionForPointersByPointers(T **f_pointer, T **s_pointer)
{
    T *auxiliary = *f_pointer;
    *f_pointer = *s_pointer;
    *s_pointer = auxiliary;
}

template <typename T>
T** AllocateMatrix(UCI &rows, UCI &cols)
{
    T **matrix = new T *[rows];
    for(size_t index = 0; index < rows; index++)
    {
        matrix[index] = new T [cols];
    }
    return matrix;
}

template <typename T = int>
void InitializeMatrix(T **matrix, UCI &rows, UCI &cols)
{
    for(size_t f_index = 0; f_index < rows; f_index++)
    {
        for(size_t s_index = 0; s_index < cols; s_index++)
        {
            matrix[f_index][s_index] = ReturnRandomValueInSpecifiedInterval(TEN_THOUSAND);
        }
    }
}

template <typename T>
void PrintMatrix(T **matrix, UCI &rows, UCI &cols)
{
    for(size_t f_index = 0; f_index < rows; f_index++)
    {
        for(size_t s_index = 0; s_index < cols; s_index++)
        {
            cout << matrix[f_index][s_index] << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

template <typename T>
void DeleteMatrix(T **&matrix, UCI &rows)
{
    for(size_t index = 0; index < rows; index++)
    {
        delete [] matrix[index];
    }
    delete [] matrix;
    matrix = nullptr;
}

template <typename T>
void ArrayReverseFromFirstHalfToSecondHalfUsingPointers(const T *start, const T *stop)
{
    for(T *index = start, *f_index = stop - 1; index < f_index; index++, f_index--)
    {
        SwapFunctionByPointerWithInteger_Double_Character(index, f_index);
    }
}

template <typename T>
void PrintArrayByPointer(const T *start, const T *stop)
{
    cout << "{" << *start;
    for(T *index = start + 1; index != stop; index++)
    {
        cout << ", " << *index;
    }
    cout << "}\n" << endl;
}

template <typename T>
void SwapFunctionByPointerWithInteger_Double_Character(T *f_value, T *s_value)
{
    T auxiliary = *f_value;
    *f_value = *s_value;
    *s_value = auxiliary;
}

inline void PrintArrayOfCharacters(CC *array)
{
    cout << array << "\n" << endl;
}

bool ArrayOfCharacter_cmp_Max_UsingPointers(CC *f_array, CC *s_array);
bool ArrayOfCharacter_cmp_Min_UsingPointers(CC *f_array, CC *s_array);

char* ArrayOfCharactersReplaceAllOldStringsWithNewOnes(CC *src_array, CC *old_string, CC *new_string);
char* ArrayOfCharactersReplaceFirstOldStringsWithNewOnes(CC *src_array, CC *old_string, CC *new_string);
char* ArrayOfCharactersReplaceLastOldStringsWithNewOnes(CC *src_array, CC *old_string, CC *new_string);

char* ArrayOfCharactersToTitleCaseFunction(CC *src_array);
char* ArrayOfCharactersToLowerCaseFunction(CC *src_array);
char* ArrayOfCharactersToUpperCaseFunction(CC *src_array);

void ReverseArrayOfCharacterFromFirstHalfToSecondHalfForPointersByPointers(char **array, UCI &size);
void ConcatenationArrayOfCharacterUsingPointers_DST_SOURCE(char *dst_array, CC *src_array);
void CopyArrayOfCharacterUsingPointers_DST_SOURCE(char *dst_array, CC *src_array);

char* ReturnEmailOfUserAndDomain(CC *user, CC *domain);

int FindLengthOfCharacterArrayByPointer(CC *array);

void IntegerArrayReverseFromFirstHalfToSecondHalf(int array[], UCI &size);
void ConversionTimeToHoursAndMinutes(UCI &time, int &hours, int &minutes);

int IntegerArrayAmount(CI array[], UCI &size);
int IntegerFindArrayElement(CI array[], UCI &size, CI &value);
bool IntegerEqualArrays(CI f_array[], CI s_array[], UCI &size);
void IntegerPrintArray(CI array[], UCI &size);

void IntegerArrayPermutationToLeftOneTime(int array[], UCI &size);
void IntegerArrayPermutationToLeft_K_Times(int array[], UCI &size, UI &K_position);
void IntegerArrayPermutationToRight_One_Time(int array[], UCI &size);
void IntegerArrayPermutationToRight_K_Times(int array[], UCI &size, UI &K_position);

int IntegerArrayMaximumElement(CI array[], UCI &size);
int IntegerArrayMinimumElement(CI array[], UCI &size);
bool IntegerArrayAscendingVerification(CI array[], UCI &size);
bool IntegerArrayDescendingVerification(CI array[], UCI &size);
void IntegerArrayInitializationWithRandomValues(int array[], UCI &size);
void IntegerArrayCopy(int dst_array[], CI src_array[], UCI &size);


void TriangleDrawWithChar(UCI &height);
void TriangleDrawWithString(UCI &height);
void ArrowDrawWithChar(UCI &height);
void ArrowDrawWithString(UCI &height);

int FirstDivisor(UCI &number);

void PrintMultiplesOfNumber(UCI &number, UCI &start, UCI &count);

bool Vowel(char letter);

char Mark(UCI &mark);

bool PrimeNumber(UCI &number);

int MaxBetween3Numbers(UCI &a, UCI &b, UCI &c);

int Abs(const int &x) {
    return x > 0 ? x : -x;
}

inline bool DecimalEqualVerification(CD &decimalPrecision, UCI &firstValue, UCI &secondValue = 0)
{
    return Abs(firstValue - secondValue) < decimalPrecision;
}

bool BisectYear(UCI &year);

int BiggestCommonDivisor(int a, int b);

void DisplayASCIICODE();

inline double ReturnCelsius2Fahrenheiht(CD &celsius)
{
    return celsius * 9 / 5 + 32;
}
inline double ReturnFahrenheiht2Celsius(CD &fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}

inline double ApplyTVA_Reference(CD &price, CD &perc_tva)
{
    return price * (1 + perc_tva);
}
inline double ApplyDiscount_Reference(CD &price, CD &perc_disc)
{
    return price * (1 - perc_disc);
}

inline void ApplyTVA_Pointer(double *price, CD &perc_tva)
{
    *price *= (1 + perc_tva);
}
inline void ApplyDiscount_Pointer(double *price, CD &perc_disc)
{
    *price *= (1 - perc_disc);
}

void ApplyDiscount_And_TVA_Reference(double &price, CD &discount);
void ApplyDiscount_And_TVA_Pointer(double *price, CD &discount);


//----------------------------------------------------------------------------------------------

// after call to new memory functions write delete to the current variable

bool ArrayOfCharacter_cmp_Max_UsingPointers(CC *f_array, CC *s_array)
{
    return strcmp(f_array, s_array) > 0;
}

bool ArrayOfCharacter_cmp_Min_UsingPointers(CC *f_array, CC *s_array)
{
    return strcmp(f_array, s_array) < 0;
}

char* ArrayOfCharactersReplaceLastOldStringsWithNewOnes(CC *src_array, CC *old_string, CC *new_string)
{
    UCI size_old_string = strlen(old_string);
    UCI size_src_array = strlen(src_array) + 1;
    char *returned_array = new char [size_src_array];
    strcpy(returned_array, src_array);
    char *last_p = nullptr;
    for(char *index = strstr(returned_array, old_string); index != nullptr; )
    {
        last_p = index;
        index = strstr(index + size_old_string, old_string);
    }
    if(last_p != nullptr)
    {
        strncpy(last_p, new_string, size_old_string);
    }
    return returned_array;
}

char* ArrayOfCharactersReplaceFirstOldStringsWithNewOnes(CC *src_array, CC *old_string, CC *new_string)
{
    UCI size_old_string = strlen(old_string);
    UCI size_src_array = strlen(src_array) + 1;
    char *returned_array = new char [size_src_array];
    strcpy(returned_array, src_array);
    char *index = strstr(returned_array, old_string);
    if(index != nullptr)
    {
        strncpy(index, new_string, size_old_string);
    }
    return returned_array;
}

char* ArrayOfCharactersReplaceAllOldStringsWithNewOnes(CC *src_array, CC *old_string, CC *new_string)
{
    UCI size_old_string = strlen(old_string);
    UCI size_src_array = strlen(src_array) + 1;
    char *returned_array = new char [size_src_array];
    strcpy(returned_array, src_array);
    for(char *index = strstr(returned_array, old_string); index != nullptr; )
    {
        strncpy(index, new_string, size_old_string);
        index = strstr(index + size_old_string, old_string);
    }
    return returned_array;
}

char* ArrayOfCharactersToTitleCaseFunction(CC *src_array)
{
    UCI size = strlen(src_array) + 1;
    char *returned_array = new char [size];
    bool convert = true;
    for(size_t index = 0; index < size; index++)
    {
        if(convert)
        {
            returned_array[index] = toupper(src_array[index]);
            convert = false;
        }
        else
        {
            returned_array[index] = src_array[index];
        }

        convert = src_array[index] == ' ';
    }
    return returned_array;
}

char* ArrayOfCharactersToLowerCaseFunction(CC *src_array)
{
    UCI size = strlen(src_array) + 1;
    char *returned_array = new char [size];
    for(size_t index = 0; index < size; index++)
    {
        returned_array[index] = tolower(src_array[index]);
    }
    return returned_array;
}

char* ArrayOfCharactersToUpperCaseFunction(CC *src_array)
{
    UCI size = strlen(src_array) + 1;
    char *returned_array = new char [size];
    for(size_t index = 0; index < size; index++)
    {
        returned_array[index] = toupper(src_array[index]);
    }
    return returned_array;
}

void ReverseArrayOfCharacterFromFirstHalfToSecondHalfForPointersByPointers(char **array, UCI &size)
{
    for(size_t index = 0, f_index = size - 1; index < f_index; index++, f_index--)
    {
        SwapFunctionForPointersByPointers<char>(&array[index], &array[f_index]);
    }
}

void ConcatenationArrayOfCharacterUsingPointers_DST_SOURCE(char *dst_array, CC *src_array)
{
    CopyArrayOfCharacterUsingPointers_DST_SOURCE(dst_array + strlen(dst_array), src_array);
}

void CopyArrayOfCharacterUsingPointers_DST_SOURCE(char *dst_array, CC *src_array)
{
    do
    {
        *dst_array++ = *src_array++;
    }
    while(*src_array != '\0');
}

char* ReturnEmailOfUserAndDomain(CC *user, CC *domain)
{
    char *email = new char [strlen(user) + strlen(domain) + 2];
    strcpy(email, user);
    strcat(email,"@");
    strcat(email, domain);
    return email;
    // after call write this :
    // delete [] email;
    // email = nullptr;
}

int FindLengthOfCharacterArrayByPointer(CC *array)
{
    int length = 0;
    for(; *array != '\0'; array++)
    {
        length++;
    }
    return length;
}

void IntegerArrayReverseFromFirstHalfToSecondHalf(int array[], UCI &size)
{
    for(size_t index = 0, f_index = size - 1; index < f_index; index++, f_index--)
    {
        SwapFunctionByPointerWithInteger_Double_Character<int>(&array[index], &array[f_index]);
    }
}

void ConversionTimeToHoursAndMinutes(UCI &time, int &hours, int &minutes)
{
    hours = time / SIXTY;
    minutes = time % SIXTY;
}

void ApplyDiscount_And_TVA_Reference(double &price, CD &discount)
{
    price *= (1 - discount);
    ApplyTVA_Reference(price, discount);
}

void ApplyDiscount_And_TVA_Pointer(double *price, CD &discount)
{
    *price *= (1 - discount);
    ApplyTVA_Pointer(price, discount);
}

void PrintMatrixOfCharacters(CC matrix[][MATRIX_ROWS], UCI &size)
{
    for(size_t index = 0; index < size; index++)
    {
        cout << matrix[index] << "\n";
    }
    cout << endl;
}

void CharacterArrayVowel2Digit(char array[])
{
    UCI size = strlen(array);
    for(size_t index = 0; index < size; index++)
    {
        switch(toupper(array[index]))
        {
        case 'A':
            array[index] = '4';
            break;
        case 'E':
            array[index] = '3';
            break;
        case 'I':
            array[index] = '1';
            break;
        case 'O':
            array[index] = '0';
            break;
        case 'U':
            array[index] = '9';
            break;
        }
    }
}

void IntegerArrayCopy(int dst_array[], CI src_array[], UCI &size)
{
    for(size_t index = 0; index < size; index++)
    {
        dst_array[index] = src_array[index];
    }
}

void IntegerArrayInitializationWithRandomValues(int array[], UCI &size)
{
    srand(time(0));
    for(size_t index = 0; index < size; index++)
    {
        array[index] = ReturnRandomValueInSpecifiedInterval(TEN_THOUSAND);
    }
}

bool IntegerArrayAscendingVerification(CI array[], UCI &size)
{
    for(size_t index = 1; index < size; index++)
    {
        if(array[index - 1] > array[index])
        {
            return false;
        }
    }
    return true;
}

bool IntegerArrayDescendingVerification(CI array[], UCI &size)
{
    for(size_t index = 1; index < size; index++)
    {
        if(array[index - 1] < array[index])
        {
            return false;
        }
    }
    return true;
}

int IntegerArrayMaximumElement(CI array[], UCI &size)
{
    int max = array[0];
    for(size_t index = 1; index < size; index++)
    {
        if(array[index] > max)
        {
            max = array[index];
        }
    }
    return max;
}

int IntegerArrayMinimumElement(CI array[], UCI &size)
{
    int min = array[0];
    for(size_t index = 1; index < size; index++)
    {
        if(array[index] < min)
        {
            min = array[index];
        }
    }
    return min;
}

void IntegerArrayPermutationToLeft_One_Time(int array[], UCI &size)
{
    CI last = array[0];
    for(size_t index = 1; index < size; index++)
    {
        array[index - 1] = array[index];
    }
    array[size - 1] = last;
}

void IntegerArrayPermutationToLeft_K_Times(int array[], UCI &size, UI &K_position)
{
    K_position %= size;
    for(; K_position > 0; K_position--)
    {
        IntegerArrayPermutationToLeft_One_Time(array, size);
    }
}

void IntegerArrayPermutationToRight_One_Time(int array[], UCI &size)
{
    CI temp = array[size - 1];
    for(size_t index = size - 1; index > 0; index--)
    {
        array[index] = array[index - 1];
    }
    array[0] = temp;
}

void IntegerArrayPermutationToRight_K_Times(int array[], UCI &size, UI &K_position)
{
    K_position %= size;
    for(; K_position > 0; K_position--)
    {
        IntegerArrayPermutationToRight_One_Time(array, size);
    }
}

void IntegerPrintArray(CI array[], UCI &size)
{
    cout << "{";
    if(size > 0)
    {
        cout << array[0];
    }
    for(size_t index = 1; index < size; index++)
    {
        cout << ", " << array[index];
    }
    cout << "}\n" << endl;
}

int IntegerFindArrayElement(CI array[], UCI &size, CI &value)
{
    for(size_t index = 0; index < size; index++)
    {
        if(array[index] == value)
        {
            return index;
        }
    }
    return MINUS_ONE_VALUE;
}

int IntegerArrayAmount(CI array[], UCI &size)
{
    int amount = array[0];
    for(size_t index = 1; index < size; index++)
    {
        amount += array[index];
    }
    return amount;
}

bool IntegerEqualArrays(CI f_array[], CI s_array[], UCI &size)
{
    for(size_t index = 0; index < size; index++)
    {
        if(f_array[index] != s_array[index])
        {
            return false;
        }
    }
    return true;
}

void TriangleDrawWithChar(UCI &height)
{
    cout << "[Insert character to draw]: \n";
    UCH characterToDraw;
    cin >> characterToDraw;
    cout << "\n";
    for(size_t i = 0; i < height; i++)
    {
        UCI stop = height - i;
        for(size_t j = 0; j < stop; j++)
        {
            cout << characterToDraw;
        }
        cout << "\n";
    }
    cout << "\n" << endl;
}


void TriangleDrawWithString(UCI &height)
{
    cout << "[Insert string to draw]: \n";
    string characterToDraw;
    cin >> characterToDraw;
    cout << "\n";
    for(size_t i = 0; i < height; i++)
    {
        UCI stop = height - i;
        for(size_t j = 0; j < stop; j++)
        {
            cout << characterToDraw;
        }
        cout << "\n";
    }
    cout << "\n" << endl;
}


void ArrowDrawWithChar(UCI &height)
{
    cout << "[Insert character to draw]: \n";
    UCH characterToDraw;
    cin >> characterToDraw;
    cout << "\n";
    UI stop = 1;
    for(size_t i = 0; i < height; i++, stop = i + 1)
    {
        UI stop = i + 1;
        if(i > height / 2)
        {
            stop = height - i;
        }
        for(size_t j = 0; j < stop; j++)
        {
            cout << characterToDraw;
        }
        cout << "\n";
    }
    cout << "\n" << endl;
}

void ArrowDrawWithString(UCI &height)
{
    cout << "[Insert string to draw]: \n";
    string characterToDraw;
    cin >> characterToDraw;
    cout << "\n";
    UI stop = 1;
    for(size_t i = 0; i < height; i++, stop = i + 1)
    {
        UI stop = i + 1;
        if(i > height / 2)
        {
            stop = height - i;
        }
        for(size_t j = 0; j < stop; j++)
        {
            cout << characterToDraw;
        }
        cout << "\n";
    }
    cout << "\n" << endl;
}

int FirstDivisor(UCI &number)
{
    for(size_t i = 2; i < number; i++)
    {
        if(number % i == 0)
        {
            return i;
        }
    }
    return 1;
}

void PrintMultiplesOfNumber(UCI &number, UCI &start, UCI &count)
{
    UI delta = 1;
    size_t crt = 0;
    for(size_t i = start; crt < count; i = i + delta)
    {
        if(i % number == 0)
        {
            cout << i << " ";
            delta = number;
            crt++;
        }
    }
    cout << "\n" << endl;
}

bool Vowel(char letter)
{
    switch(toupper(letter))
    {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return true;
    }
    return false;
}

char Mark(UCI &mark)
{
    if(mark > 10)
    {
        return 'N';
    }
    else if(mark >= 9)
    {
        return 'E';
    }
    else if(mark >= 7)
    {
        return 'B';
    }
    else if(mark >= 5)
    {
        return 'S';
    }
    else
    {
        return 'I';
    }
}

bool PrimeNumber(UCI &number)
{
    if(number < 2)
    {
        return false;
    }
    if((number % 2 == 0) and (number > 2))
    {
        return false;
    }
    for(size_t divisor = 3; (divisor * divisor) <= number; divisor += 2)
    {
        if(number % divisor == 0)
        {
            return false;
        }
    }
    return true;
}

int MaxBetween3Numbers(CI &a, CI &b, CI &c)
{
    CI firstMax = a > b ? a : b;
    return firstMax > c ? firstMax : c;
}

bool BisectYear(UCI &year)
{
    if((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
    {
        return true;
    }
    return false;
}

int BiggestCommonDivisor(int a, int b)
{
    int temp;
    while(a % b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return b;
}

void DisplayASCIICODE()
{
    for(UCH ch = 0; ; ch++)
    {
        cout << int(ch) << " = " << ch << "\n";
        if(ch == UCHAR_MAX)
        {
            cout << "\n" << endl;
            return;
        }
    }
}