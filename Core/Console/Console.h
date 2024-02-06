//=====================================================================================

#pragma once

#include "../Engine/Engine.hpp"

//=====================================================================================

#define PREFIX_ERROR "[ERROR]"
#define PREFIX_COMMAND "#"
#define PREFIX_WARNING "]"
#define PREFIX_LOG ">"

//=====================================================================================

namespace ProtoGenesys
{
	class cConsole
	{
	public:

		cConsole() : _thunkTextCallback(&cConsole::TextEditCallbackStub, this) {}
		~cConsole();

		struct sCmdLine
		{
			int iArgNum;
			char szCmdName[256], szCmdArgs[256][256];
		};

		char szInput[sizeof(sCmdLine)];
		bool bScrollToBottom;
		int iHistoryPos;
		ImVector<LPSTR> vItems, vHistory;
		ImVector<LPCSTR> vCommands;

		static int Stricmp(LPCSTR str1, LPCSTR str2)
		{
			int d;
			while ((d = tolower(*str2) - tolower(*str1)) == 0 && *str1)
			{
				str1++;
				str2++;
			}
			return d;
		}

		static int Strnicmp(LPCSTR str1, LPCSTR str2, int n)
		{
			int d = 0;
			while (n > 0 && (d = tolower(*str2) - tolower(*str1)) == 0 && *str1)
			{
				str1++;
				str2++;
				n--;
			}
			return d;
		}

		static LPSTR Strdup(LPCSTR str)
		{
			size_t len = strlen(str) + 1;
			void* buff = malloc(len);
			return (LPSTR)memcpy(buff, (const void*)str, len);
		}

		void Init();
		void ClearLog();
		void AddLog(LPCSTR format, ...) IM_FMTARGS(2);
		void Draw();

		void SplitCommandLine(LPCSTR in, sCmdLine* out);
		void ExecCommand(LPCSTR command);
		int TextEditCallbackStub(ImGuiTextEditCallbackData* data);
		int TextEditCallback(ImGuiTextEditCallbackData* data);

		Thunk<ImGuiInputTextCallback, cConsole> _thunkTextCallback;
	} extern _console;
}

//=====================================================================================