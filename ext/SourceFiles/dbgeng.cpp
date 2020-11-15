#include <Windows.h>
#include <DbgEng.h>
#include <stdio.h>

#ifndef DEBUG
#define DEBUG
#endif

#define EXT_MAJOR_VER	1
#define EXT_MINOR_VER	0

HRESULT
CALLBACK
DebugExtensionInitialize(PULONG Version, PULONG Flags)
{
	*Version = DEBUG_EXTENSION_VERSION(EXT_MAJOR_VER, EXT_MINOR_VER);
	*Flags = 0;

	return S_OK;
}

void
CALLBACK
DebugExtensionNotify(ULONG Notify, ULONG64 Argument)
{
	UNREFERENCED_PARAMETER(Argument);

#ifdef DEBUG
	AllocConsole();
	freopen("CONOUT$", "wb", stdout);
#endif

	switch(Notify)
	{
	case DEBUG_NOTIFY_SESSION_ACTIVE:
		break;
	case DEBUG_NOTIFY_SESSION_INACTIVE:
		break;
	case DEBUG_NOTIFY_SESSION_ACCESSIBLE:
		break;
	case DEBUG_NOTIFY_SESSION_INACCESSIBLE:
		break;
	}
	return;
}

void
CALLBACK
DebugExtensionUninitialize(void)
{
#ifdef DEBUG
	FreeConsole();
#endif
}