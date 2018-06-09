#pragma once
#include <memory>
#include <vector>

#include <Engine/Core/GlobalTypes.h>

namespace input
{
	class TextBuffer
	{
	public:
		TextBuffer();
		~TextBuffer();

		void init();
		void destroy();
		bool alive() const;

		void clear();
		const std::vector<char>& getBuffer() const;

	private:
		// InputSystem interface
		// {
		friend class InputSystem;
		void addChar(const char& ch);
		// }

		bool m_bAlive;

		std::vector<char> m_Buffer;
	};
}
