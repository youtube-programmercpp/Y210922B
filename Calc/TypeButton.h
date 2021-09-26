#pragma once
#include <Windows.h>
enum class ValueType;
class TypeButton
{
	HWND hWnd;
public:
	TypeButton(HWND hWnd) noexcept;
	void ChangeType() noexcept;
	operator ValueType() const noexcept;
};

