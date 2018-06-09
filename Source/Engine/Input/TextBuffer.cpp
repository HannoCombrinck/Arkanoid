#include "TextBuffer.h"

#include <iostream>

using namespace std;

namespace input {

	TextBuffer::TextBuffer()
		: m_bAlive(false)
	{
	}

	TextBuffer::~TextBuffer()
	{
		m_Buffer.clear();
	}

	void TextBuffer::init()
	{
		m_bAlive = true;
	}

	bool TextBuffer::isAlive() const
	{
		return m_bAlive;
	}

	void TextBuffer::destroy()
	{
		m_bAlive = false;
		clear();
	}

	void TextBuffer::clear()
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

