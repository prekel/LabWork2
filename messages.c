#include "messages.h"

struct errmessages errormessages = {
		{"Команда не найдена",             "Command not found"},
		{"Введено неверное значение(-ия)", "Invalid value(-s) entered"},
		{"Введено неверное значение",      "Invalid value entered"},
		{"Значение не введено",            "Value not entered"},
		{"Введено слишком много значений", "Too many values entered"},
		{"Введено слишком мало значений",  "Too few values entered"},
		{"Значения массива не определены", "Values not entered"},
		{"Не указан размер массива", "No array size specified"}
};

struct mssages messages = {
		{"Введите элемент №",                                    "Enter element #"},
		{"Общее сопротивление при последовательном соединении:", "Total resistance with serial connection:  "},
		{"Общее сопротивление при параллельном соединении:    ", "Total resistance with parallel connection:"},
};