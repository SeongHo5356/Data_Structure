#include <iostream>

using namespace std;

template <class ItemType>
struct LineType 
{
	ItemType line[80];
	LineType<ItemType>* back;
	LineType<ItemType>* next;
};

template <class ItemType>
class TextEditor
{
public:
	TextEditor()// Class constructor
	{
		Header = new LineType<ItemType>;
		Trailer = new LineType<ItemType>;
		Header->line = ". . . This is Top . . .";
		Trailer->line = ". . . This is Bottom . . .";
		Header->next = Trailer;
		Trailer->back = Header;

		currentLine = Header;
	}
	~TextEditor()// Class destructor
	{

	}

	void GoToTop()
	{
		if (Header->next == Trailer)
		{
			currentLine = Header;
		}
		else {
			currentLine = Trailer;
			while (currentLine->back != NULL)
			{
				currentLine = currentLine->back;
			}
		}
	}


	void GoToBottom()
	{
		if (Header->next == Trailer) {
			currentLine = Trailer;
		}
		else {
			currentLine = Header;
			while (currentLine->next != NULL)
			{
				currentLine = currentLine->next;
			}
		}
	}

	void InsertItem(char newline[])
	{
		LineType<ItemType>* temp = new LineType<ItemType>;
		temp->line = newline;

		if (Header->next = Trailer)
		{
			Header->next = temp;
			Trailer->back = temp;
			temp->back = Header;
			temp->next = Trailer;
		}

		else
		{
			temp->back = currentLine;
			temp->next = currentLine->next;

			currentLine->next = temp;
			currentLine->next->back = temp;

			currentLine = currentLine->next;

		}

	}

private:

	LineType<ItemType>* currentLine;
	LineType<ItemType>* Header;
	LineType<ItemType>* Trailer;

};

