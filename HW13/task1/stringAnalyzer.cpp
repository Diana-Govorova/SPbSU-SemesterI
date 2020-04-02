#include <stdio.h>

bool isDigit(const char symbol)
{
	return symbol <= '9' && symbol >= '0';
}

enum class State
{
	WaitNumber,
	SeenNumberWaitNumber, 
	SeenPoint,
	SeenNumber,
	SeenE,
	SeenSign,
	WaitNumberAfterSign
};

bool isNumber(char* string)
{
	State state = State::WaitNumber;
	int i = -1;

	while (true)
	{
		i++;
		const char symbol = string[i];

		switch (state)
		{
		case State::WaitNumber:
		{
			if (isDigit(symbol))
			{
				state = State::SeenNumberWaitNumber;
			}
			else
			{
				return false;
			}
			break;
		}
		case State::SeenNumberWaitNumber:
		{
			if (isDigit(symbol))
			{
				state = State::SeenNumberWaitNumber;
			}
			else if (symbol == '.')
			{
				state = State::SeenPoint;
			}
			else if (symbol == 'E')
			{
				state = State::SeenE;
			}
			else if (symbol == '\0')
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		}
		case State::SeenPoint:
		{
			if (isDigit(symbol))
			{
				state = State::SeenNumber;
			}
			else
			{
				return false;
			}
			break;
		}
		case State::SeenNumber:
		{
			if (isDigit(symbol))
			{
				state = State::SeenNumber;
			}
			else if (symbol == 'E')
			{
				state = State::SeenE;
			}
			else if (symbol == '\0')
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		}
		case State::SeenE:
		{
			if (symbol == '-' || symbol == '+')
			{
				state = State::SeenSign;
			}
			else if (isDigit(symbol))
			{
				state = State::WaitNumberAfterSign;
			}
			else
			{
				return false;
			}
			break;
		}
		case State::SeenSign:
		{
			if (isDigit(symbol))
			{
				state = State::WaitNumberAfterSign;
			}
			else
			{
				return false;
			}
			break;
		}
		case State::WaitNumberAfterSign:
		{
			if (isDigit(symbol))
			{
				state = State::WaitNumberAfterSign;
			}
			else if (symbol == '\0')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		}
	}
}