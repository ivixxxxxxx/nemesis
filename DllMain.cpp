//=====================================================================================

#include "StdAfx.hpp"

using namespace ProtoGenesys;

//=====================================================================================



//=====================================================================================

void Init();
void Free();

void HookSteamUserAPI();
void HookSteamFriendsAPI();

void SetSteamID();

//=====================================================================================

HRESULT WINAPI hPresent(_In_ IDXGISwapChain* pSwapChain, _In_ UINT SyncInterval, _In_ UINT Flags);
typedef HRESULT(WINAPI* tPresent)(_In_ IDXGISwapChain* pSwapChain, _In_ UINT SyncInterval, _In_ UINT Flags);
tPresent oPresent;

void WINAPI hDrawIndexed(_In_ ID3D11DeviceContext* pContext, _In_ UINT IndexCount, _In_ UINT StartIndexLocation, _In_ INT BaseVertexLocation);
typedef void(WINAPI* tDrawIndexed)(_In_ ID3D11DeviceContext* pContext, _In_ UINT IndexCount, _In_ UINT StartIndexLocation, _In_ INT BaseVertexLocation);
tDrawIndexed oDrawIndexed;

void WINAPI hClearRenderTargetView(_In_ ID3D11DeviceContext* pContext, _In_ ID3D11RenderTargetView* pRenderTargetView, _In_ const FLOAT ColorRGBA[4]);
typedef void(WINAPI* tClearRenderTargetView)(_In_ ID3D11DeviceContext* pContext, _In_ ID3D11RenderTargetView* pRenderTargetView, _In_ const FLOAT ColorRGBA[4]);
tClearRenderTargetView oClearRenderTargetView;

void USERCALL hBulletHitEvent(int localnum, int sourcenum, int targetnum, int weapon, ImVec3* start, ImVec3* position, ImVec3* normal, ImVec3* alphanormal, int surface, int _event, int param, int contents, char bone);
typedef void(USERCALL* tBulletHitEvent)(int localnum, int sourcenum, int targetnum, int weapon, ImVec3* start, ImVec3* position, ImVec3* normal, ImVec3* alphanormal, int surface, int _event, int param, int contents, char bone);
tBulletHitEvent oBulletHitEvent = (tBulletHitEvent)dwBulletHitEvent;

void USERCALL hTransitionPlayerState(int localnum, sPlayerState* playerstate, LPVOID transplayerstate);
typedef void(USERCALL* tTransitionPlayerState)(int localnum, sPlayerState* playerstate, LPVOID transplayerstate);
tTransitionPlayerState oTransitionPlayerState = (tTransitionPlayerState)dwTransitionPlayerState;

void USERCALL hCalcEntityLerpPositions(int localnum, sCEntity* entity);
typedef void(USERCALL* tCalcEntityLerpPositions)(int localnum, sCEntity* entity);
tCalcEntityLerpPositions oCalcEntityLerpPositions = (tCalcEntityLerpPositions)dwCalcEntityLerpPositions;

int USERCALL hGetWorldTagMatrix(LPVOID pose, LPVOID dobj, WORD tag, ImVec3 matrix[], ImVec3* origin);
typedef int(USERCALL* tGetWorldTagMatrix)(LPVOID pose, LPVOID dobj, WORD tag, ImVec3 matrix[], ImVec3* origin);
tGetWorldTagMatrix oGetWorldTagMatrix = (tGetWorldTagMatrix)dwGetWorldTagMatrix;

LPVOID USERCALL hGetAddr(bool renew);
typedef LPVOID(USERCALL* tGetAddr)(bool renew);
tGetAddr oGetAddr = (tGetAddr)dwGetAddr;


int USERCALL hGetPlayerStatus(int localnum, std::uint64_t xuid);
typedef int(USERCALL* tGetPlayerStatus)(int localnum, std::uint64_t xuid);
tGetPlayerStatus oGetPlayerStatus = (tGetPlayerStatus)dwGetPlayerStatus;

bool FASTCALL hIsValidSteamID(CSteamID* steamid);
typedef bool(FASTCALL* tIsValidSteamID)(CSteamID* steamid);
tIsValidSteamID oIsValidSteamID = (tIsValidSteamID)dwIsValidSteamID;

void USERCALL hCreateScreenShot(int unk1, int unk2, int unk3, int unk4);
typedef void(USERCALL* tCreateScreenShot)(int unk1, int unk2, int unk3, int unk4);
tCreateScreenShot oCreateScreenShot = (tCreateScreenShot)dwCreateScreenShot;

LPSTR USERCALL hFriendPersonaNameFromXuid(LPSTR name, SIZE_T size, bool ascii);
typedef LPSTR(USERCALL* tFriendPersonaNameFromXuid)(LPSTR name, SIZE_T size, bool ascii);
tFriendPersonaNameFromXuid oFriendPersonaNameFromXuid = (tFriendPersonaNameFromXuid)dwFriendPersonaNameFromXuid;

CSteamID* FASTCALL hGetSteamID(LPVOID ecx, LPVOID edx, int unk);
typedef CSteamID* (FASTCALL* tGetSteamID)(LPVOID ecx, LPVOID edx, int unk);
tGetSteamID oGetSteamID;

LPCSTR FASTCALL hGetPersonaName(LPVOID ecx, LPVOID edx);
typedef LPCSTR(FASTCALL* tGetPersonaName)(LPVOID ecx, LPVOID edx);
tGetPersonaName oGetPersonaName;

int FASTCALL hGetFriendCount(LPVOID ecx, LPVOID edx, EFriendFlags friendflags);
typedef int(FASTCALL* tGetFriendCount)(LPVOID ecx, LPVOID edx, EFriendFlags friendflags);
tGetFriendCount oGetFriendCount;

void FASTCALL hGetFriendByIndex(LPVOID ecx, LPVOID edx, CSteamID* steamid, int index, EFriendFlags friendflags);
typedef void(FASTCALL* tGetFriendByIndex)(LPVOID ecx, LPVOID edx, CSteamID* steamid, int index, EFriendFlags friendflags);
tGetFriendByIndex oGetFriendByIndex;

EPersonaState FASTCALL hGetFriendPersonaState(LPVOID ecx, LPVOID edx, CSteamID steamid);
typedef EPersonaState(FASTCALL* tGetFriendPersonaState)(LPVOID ecx, LPVOID edx, CSteamID steamid);
tGetFriendPersonaState oGetFriendPersonaState;

LPCSTR FASTCALL hGetFriendPersonaName(LPVOID ecx, LPVOID edx, CSteamID steamid);
typedef LPCSTR(FASTCALL* tGetFriendPersonaName)(LPVOID ecx, LPVOID edx, CSteamID steamid);
tGetFriendPersonaName oGetFriendPersonaName;

bool FASTCALL hGetFriendGamePlayed(CSteamID steamid, int unk1, int unk2, FriendGameInfo_t* friendgameinfo);
typedef bool(FASTCALL* tGetFriendGamePlayed)(CSteamID steamid, int unk1, int unk2, FriendGameInfo_t* friendgameinfo);
tGetFriendGamePlayed oGetFriendGamePlayed;

int USERCALL hAtoi1(LPCSTR string);
int USERCALL hAtoi2(LPCSTR string);
LPVOID USERCALL hMemcpy(LPVOID dst, LPCVOID src, SIZE_T size);

std::uint64_t USERCALL hGetUserSteamIdAsXuid();
LPSTR USERCALL hFilterPersonaName(LPSTR name, bool ascii);

//=====================================================================================

FurtiveHook fhTransitionPlayerStateCall{ x86Instruction::CALL, (LPVOID)dwTransitionPlayerStateCall, &hTransitionPlayerState };
FurtiveHook fhGetWorldTagMatrixCall{ x86Instruction::CALL, (LPVOID)dwGetWorldTagMatrixCall, &hGetWorldTagMatrix };

FurtiveHook fhAtoiCall1{ x86Instruction::CALL, (LPVOID)dwAtoiCall1, &hAtoi1 };
FurtiveHook fhAtoiCall2{ x86Instruction::CALL, (LPVOID)dwAtoiCall2, &hAtoi2 };
FurtiveHook fhMemcpyCall{ x86Instruction::CALL, (LPVOID)dwMemcpyCall, &hMemcpy };

FurtiveHook fhGetUserSteamIDAsXUIDCall{ x86Instruction::CALL, (LPVOID)dwGetUserSteamIdAsXuidCall, &hGetUserSteamIdAsXuid };
FurtiveHook fhFilterPersonaNameCall{ x86Instruction::CALL, (LPVOID)dwFilterPersonaNameCall, &hFilterPersonaName };

//=====================================================================================

HRESULT WINAPI hPresent(_In_ IDXGISwapChain* swapchain, _In_ UINT syncinterval, _In_ UINT flags)
{
	_mainGui.Present(swapchain, syncinterval, flags);

	return oPresent(swapchain, syncinterval, flags);
}

//=====================================================================================

void WINAPI hDrawIndexed(_In_ ID3D11DeviceContext* pContext, _In_ UINT IndexCount, _In_ UINT StartIndexLocation, _In_ INT BaseVertexLocation)
{
	_mainGui.DrawIndexed(pContext, IndexCount, StartIndexLocation, BaseVertexLocation);

	oDrawIndexed(pContext, IndexCount, StartIndexLocation, BaseVertexLocation);
}

//=====================================================================================

void WINAPI hClearRenderTargetView(_In_ ID3D11DeviceContext* pContext, _In_ ID3D11RenderTargetView* pRenderTargetView, _In_ const FLOAT ColorRGBA[4])
{
	_mainGui.ClearRenderTargetView(pContext, pRenderTargetView, ColorRGBA);

	oClearRenderTargetView(pContext, pRenderTargetView, ColorRGBA);
}

//=====================================================================================

void USERCALL hBulletHitEvent(int localnum, int sourcenum, int targetnum, int weapon, ImVec3* start, ImVec3* position, ImVec3* normal, ImVec3* alphanormal, int surface, int _event, int param, int contents, char bone)
{
	oBulletHitEvent(localnum, sourcenum, targetnum, weapon, start, position, normal, alphanormal, surface, _event, param, contents, bone);

	_hooks.BulletHitEvent(localnum, sourcenum, targetnum, weapon, start, position, normal, alphanormal, surface, _event, param, contents, bone);
}

//=====================================================================================

void USERCALL hTransitionPlayerState(int localnum, sPlayerState* playerstate, LPVOID transplayerstate)
{
	_hooks.TransitionPlayerState(localnum, playerstate, transplayerstate);

	oTransitionPlayerState(localnum, playerstate, transplayerstate);
}

//=====================================================================================

void USERCALL hCalcEntityLerpPositions(int localnum, sCEntity* entity)
{
	oCalcEntityLerpPositions(localnum, entity);

	return _hooks.CalcEntityLerpPositions(localnum, entity);
}

//=====================================================================================

int USERCALL hGetWorldTagMatrix(LPVOID pose, LPVOID dobj, WORD tag, ImVec3 matrix[], ImVec3* origin)
{
	int iReturn = oGetWorldTagMatrix(pose, dobj, tag, matrix, origin);

	_hooks.GetWorldTagMatrix(pose, dobj, tag, matrix, origin);

	return iReturn;
}

//=====================================================================================

LPVOID USERCALL hGetAddr(bool renew)
{
	_hooks.GetAddr(renew);

	return oGetAddr(renew);
}

//=====================================================================================


//=====================================================================================

int USERCALL hGetPlayerStatus(int localnum, std::uint64_t xuid)
{
	return _hooks.GetPlayerStatus(localnum, xuid);
}

//=====================================================================================

bool FASTCALL hIsValidSteamID(CSteamID* steamid)
{
	return _hooks.IsValidSteamID(steamid);
}

//=====================================================================================

void USERCALL hCreateScreenShot(int unk1, int unk2, int unk3, int unk4)
{
	_hooks.CreateScreenShot(unk1, unk2, unk3, unk4);

	return oCreateScreenShot(unk1, unk2, unk3, unk4);
}

//=====================================================================================

LPSTR USERCALL hFriendPersonaNameFromXuid(LPSTR name, SIZE_T size, bool ascii)
{
	return oFriendPersonaNameFromXuid(name, 32, ascii);
}

//=====================================================================================

CSteamID* FASTCALL hGetSteamID(LPVOID ecx, LPVOID edx, int unk)
{
	return _hooks.GetSteamID(oGetSteamID(ecx, edx, unk));
}

//=====================================================================================

LPCSTR FASTCALL hGetPersonaName(LPVOID ecx, LPVOID edx)
{
	return _hooks.GetPersonaName(oGetPersonaName(ecx, edx));
}

//=====================================================================================

int FASTCALL hGetFriendCount(LPVOID ecx, LPVOID edx, EFriendFlags friendflags)
{
	_hooks.iFriendCount = oGetFriendCount(ecx, edx, friendflags);

	return _hooks.GetFriendCount(ecx, edx, friendflags) + _hooks.iFriendCount;
}

//=====================================================================================

void FASTCALL hGetFriendByIndex(LPVOID ecx, LPVOID edx, CSteamID* steamid, int index, EFriendFlags friendflags)
{
	if (index >= 0 && index < _hooks.iFriendCount)
		oGetFriendByIndex(ecx, edx, steamid, index, friendflags);

	if (index >= _hooks.iFriendCount && index < _hooks.iFriendCount + (int)_hooks.vFriends.size())
		_hooks.GetFriendByIndex(ecx, edx, steamid, index, friendflags);
}

//=====================================================================================

EPersonaState FASTCALL hGetFriendPersonaState(LPVOID ecx, LPVOID edx, CSteamID steamid)
{
	return _hooks.GetFriendPersonaState(ecx, edx, steamid);
}

//=====================================================================================

LPCSTR FASTCALL hGetFriendPersonaName(LPVOID ecx, LPVOID edx, CSteamID steamid)
{
	LPCSTR szName = _hooks.GetFriendPersonaName(ecx, edx, steamid);

	if (szName)
		return szName;

	return oGetFriendPersonaName(ecx, edx, steamid);
}

//=====================================================================================

bool FASTCALL hGetFriendGamePlayed(CSteamID steamid, int unk1, int unk2, FriendGameInfo_t* friendgameinfo)
{
	return _hooks.GetFriendGamePlayed(steamid, unk1, unk2, friendgameinfo);
}

//=====================================================================================

int USERCALL hAtoi1(LPCSTR string)
{
	return _hooks.Atoi1(std::atoi(string));
}

//=====================================================================================

int USERCALL hAtoi2(LPCSTR string)
{
	return _hooks.Atoi2(std::atoi(string));
}

//=====================================================================================

LPVOID USERCALL hMemcpy(LPVOID dst, LPCVOID src, SIZE_T size)
{
	return _hooks.Memcpy(dst, src, size);
}

//=====================================================================================

std::uint64_t USERCALL hGetUserSteamIdAsXuid()
{
	return _hooks.GetUserSteamIdAsXuid();
}

//=====================================================================================

LPSTR USERCALL hFilterPersonaName(LPSTR name, bool ascii)
{
	return _hooks.FilterPersonaName(name, ascii);
}

//=====================================================================================

#define AttachHook(original, hook) (DetourTransactionBegin(), DetourUpdateThread(GetCurrentThread()), DetourAttach((LPVOID*)&original, (LPVOID)hook), DetourTransactionCommit())
#define DetachHook(original, hook) (DetourTransactionBegin(), DetourUpdateThread(GetCurrentThread()), DetourDetach((LPVOID*)&original, (LPVOID)hook), DetourTransactionCommit())
void Init()
{
	//SetSteamID();

	while (!hGameOverlayRenderer.lpBaseOfDll || !hGameOverlayRenderer.EntryPoint || !hGameOverlayRenderer.SizeOfImage)
		hGameOverlayRenderer = GetModuleInfo("GameOverlayRenderer.dll");

	while (!oPresent)
		oPresent = (tPresent)Dereference(ReadPointer(FindPattern((std::uintptr_t)hGameOverlayRenderer.lpBaseOfDll, (std::uintptr_t)hGameOverlayRenderer.SizeOfImage, "\xFF\x15\x00\x00\x00\x00\x5B\x5D\xC2\x0C\x00", "xx????xxxxx"), 0x2));

	//_hooks.PatchAntiCheat();

	_console.AddLog("%s patching ac hook...", PREFIX_LOG);
	_console.AddLog("%s hooked all", PREFIX_LOG);
	_console.Init();

	_hooks.pUnhandledExceptionFilter = SetUnhandledExceptionFilter(NULL);
	_hooks.pVectoredExceptionHandler = AddVectoredExceptionHandler(TRUE, _hooks._thunkVectoredExceptionHandler.GetThunk());

	_hooks.dwConnectPaths = Dereference(dwConnectPathsDvar);
	Dereference(dwConnectPathsDvar) = cHooks::VEH_INDEX_CONNECTPATHS;

	_hooks.dwMouseAccel = Dereference(dwMouseAccelerationDvar);
	Dereference(dwMouseAccelerationDvar) = cHooks::VEH_INDEX_MOUSEACCEL;

	_hooks.dwDrawBigFPS = Dereference(dwDrawBigFPSDvar);
	Dereference(dwDrawBigFPSDvar) = cHooks::VEH_INDEX_DRAWBIGFPS;

	_hooks.dwMaxClients = Dereference(dwMaxClientsDvar);
	Dereference(dwMaxClientsDvar) = cHooks::VEH_INDEX_MAXCLIENTS;

	_hooks.dwNoDelta = Dereference(dwNoDeltaDvar);
	Dereference(dwNoDeltaDvar) = cHooks::VEH_INDEX_NODELTA;
	AttachHook(oPresent, hPresent);

	//furtive_crash::init();

	if (bIsSteamVersion)
	{
		while (strcmp((LPCSTR)dwVersionString, "43.1736.11"));

		//HookSteamUserAPI();
		//HookSteamFriendsAPI();
	}
}

//=====================================================================================

void Free()
{
	Dereference(dwConnectPathsDvar) = _hooks.dwConnectPaths;
	Dereference(dwMouseAccelerationDvar) = _hooks.dwMouseAccel;
	Dereference(dwDrawBigFPSDvar) = _hooks.dwDrawBigFPS;
	Dereference(dwMaxClientsDvar) = _hooks.dwMaxClients;
	Dereference(dwNoDeltaDvar) = _hooks.dwNoDelta;

	RemoveVectoredExceptionHandler(_hooks.pVectoredExceptionHandler);
	SetUnhandledExceptionFilter(_hooks.pUnhandledExceptionFilter);

	DetachHook(oPresent, hPresent);
	



	
	_mainGui._device->Release();
	_mainGui._deviceContext->Release();

	ImGui_ImplWin32_Shutdown();
	ImGui_ImplDX11_Shutdown();
	ImGui::DestroyContext();

	SetWindowLongPtr(_mainGui.hWindow, GWLP_WNDPROC, (std::intptr_t)_mainGui.oWindowProcess);
}

//=====================================================================================

void HookSteamUserAPI()
{
	while (!hSteamAPI.lpBaseOfDll || !hSteamAPI.EntryPoint || !hSteamAPI.SizeOfImage)
		hSteamAPI = GetModuleInfo("steam_api.dll");

	while (!_hooks.GetSteamUser)
		_hooks.GetSteamUser = (cHooks::tSteamUser)GetProcAddress((HMODULE)hSteamAPI.lpBaseOfDll, "SteamUser");

	while (!_hooks._steamUser)
		_hooks._steamUser = _hooks.GetSteamUser();

	oGetSteamID = (tGetSteamID)SwapVMT((std::uintptr_t)_hooks._steamUser, (std::uintptr_t)&hGetSteamID, 2);
}

//=====================================================================================

void HookSteamFriendsAPI()
{
	_hooks.RefreshFriends();

	while (!hSteamAPI.lpBaseOfDll || !hSteamAPI.EntryPoint || !hSteamAPI.SizeOfImage)
		hSteamAPI = GetModuleInfo("steam_api.dll");

	while (!_hooks.GetSteamFriends)
		_hooks.GetSteamFriends = (cHooks::tSteamFriends)GetProcAddress((HMODULE)hSteamAPI.lpBaseOfDll, "SteamFriends");
	
	while (!_hooks._steamFriends)
		_hooks._steamFriends = _hooks.GetSteamFriends();
	
	oGetPersonaName = (tGetPersonaName)SwapVMT((std::uintptr_t)_hooks._steamFriends, (std::uintptr_t)&hGetPersonaName, 0);
	oGetFriendCount = (tGetFriendCount)SwapVMT((std::uintptr_t)_hooks._steamFriends, (std::uintptr_t)&hGetFriendCount, 3);
	oGetFriendByIndex = (tGetFriendByIndex)SwapVMT((std::uintptr_t)_hooks._steamFriends, (std::uintptr_t)&hGetFriendByIndex, 4);
	oGetFriendPersonaState = (tGetFriendPersonaState)SwapVMT((std::uintptr_t)_hooks._steamFriends, (std::uintptr_t)&hGetFriendPersonaState, 6);
	oGetFriendPersonaName = (tGetFriendPersonaName)SwapVMT((std::uintptr_t)_hooks._steamFriends, (std::uintptr_t)&hGetFriendPersonaName, 7);
	oGetFriendGamePlayed = (tGetFriendGamePlayed)SwapVMT((std::uintptr_t)_hooks._steamFriends, (std::uintptr_t)&hGetFriendGamePlayed, 8);
}

//=====================================================================================

void SetSteamID()
{
	char szTempSteamID[20] = { NULL };

	GetPrivateProfileString("SteamID", "XUID", "", szTempSteamID, sizeof(szTempSteamID), (acut::GetExeDirectory() + DEFAULT_CFG).c_str());

	std::string szSteamID(szTempSteamID);

	if (!szSteamID.empty())
	{
		_hooks.qwXuidOverride = strtoll(szSteamID.c_str(), NULL, 10);

		fhGetUserSteamIDAsXUIDCall.SetHook();
	}
}

//=====================================================================================

BOOL APIENTRY DllMain(_In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID lpvReserved)
{
	DisableThreadLibraryCalls(hinstDLL);

	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		std::thread(Init).detach();
		return TRUE;

	case DLL_PROCESS_DETACH:
		exit(EXIT_SUCCESS);
		return TRUE;

	default:
		return FALSE;
	}
}

//=====================================================================================