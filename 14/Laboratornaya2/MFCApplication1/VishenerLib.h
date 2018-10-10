#pragma once
#include <string>
enum VishenerOperationType
{
	Encription = 0,
	Decription = 1
};
int VishenerEncodeDecode(VishenerOperationType type, std::string& text, std::wstring const& sKey, std::string& decriptedText);