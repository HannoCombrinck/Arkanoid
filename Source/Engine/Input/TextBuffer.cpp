#include "TextBuffer.h"

#include <iostream>

#include <Engine/Input/InputSystem.h>

using namespace std;

namespace input {

	TextBuffer::TextBuffer()
		: m_pInputSystem(0)
	{
	}

	TextBuffer::~TextBuffer()
	{
		m_Buffer.clear();
	}

	void TextBuffer::init(InputSystem* pInputSystem)
	{
		m_pInputSystem = pInputSystem;
	}

	void TextBuffer::created()
	{
	}

	void TextBuffer::clean()
	{
		m_Buffer.clear();
	}

	const std::vector<char>& TextBuffer::getBuffer() const
	{
		return m_Buffer;
	}

	void TextBuffer::addChar(const char & ch)
	{
		m_Buffer.push_back(ch);
	}

}

