#pragma once
#include <iostream>
#include <string>

class OutOfRangeException : public std::exception
{
private:
	std::string info;

public:

	OutOfRangeException(int index){
		info = "Выход за пределы инициализированной области памяти! Значение некорректного поля = " + std::to_string(index);
	}

	const char* what() const noexcept override{
		return info.c_str();
	}
};

