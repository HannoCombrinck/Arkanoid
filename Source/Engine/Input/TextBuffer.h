#pragma once
#include <memory>
#include <vector>

#include <Engine/Core/GlobalTypes.h>

namespace input
{
	class InputSystem;
}

namespace input
{
	class TextBuffer
	{
	public:
		TextBuffer();
		~TextBuffer();

		void init(InputSystem* pInputSystem);
		void clean();

		const std::vector<char>& getBuffer() const;

	private:
		// InputSystem interface
		// {
		friend class InputSystem;
		void addChar(const char& ch);
		// }

		InputSystem* m_pInputSystem;
		std::vector<char> m_Buffer;
	};
}