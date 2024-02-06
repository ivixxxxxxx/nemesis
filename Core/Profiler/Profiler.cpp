//=====================================================================================

#include "../../StdAfx.hpp"

//=====================================================================================

namespace ProtoGenesys
{
	cProfiler _profiler;

	bool cProfiler::SaveProfile(const std::string& path)
	{
		try
		{
			XML.create_document();
			std::wstring szFilePath;

			if (path.empty())
				szFilePath = acut::AnsiToWstring(acut::GetExeDirectory() + acut::FindAndReplaceString(DEFAULT_XML, " ", ""), CP_ACP);

			else
				szFilePath = acut::AnsiToWstring(path, CP_ACP);

			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.Mode", gAimBotMode->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.AutoZoom", gAutoZoom->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.AutoFire", gAutoFire->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.AutoWall", gAutoWall->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.ApplyPrediction", gApplyPrediction->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.AntiKillTeamMates", gAntiKillTeamMates->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.AntiKillIgnored", gAntiKillIgnored->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.SilentAim", gSilentAim->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.BoneScan", gBoneScan->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.TargetK9Unit", gTargetK9Unit->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.AntiAimPitch", gAntiAimPitch->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.AntiAimYaw", gAntiAimYaw->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.SortAlgorithmTargets", gSortAlgorithmTargets->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.SortAlgorithmBones", gSortAlgorithmBones->Current.iValue);

			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Mode", gWallHackMode->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Boxes", gBoxes->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Bones", gBones->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.SnapLines", gSnapLines->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Distances", gDistances->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Names", gNames->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Weapons", gWeapons->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Entities", gEntities->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.CrossHair", gCrossHair->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Compass", gCompass->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Radar", gRadar->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.BulletTracers", gBulletTracers->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.ThreatWarning", gThreatWarning->Current.iValue);

			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.ThirdPerson", gThirdPerson->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.OrbitalVsat", gOrbitalVsat->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.HardcoreHud", gHardcoreHud->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.DisableEmp", gDisableEmp->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.IdStealer", gIdStealer->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.AirStuckToggle", gAirStuckToggle->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.ReloadCancel", gReloadCancel->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.BoneScanPriorities", gBoneScanPriorities->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.BoneScanRiotShielders", gBoneScanRiotShielders->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.NameSpam", gNameSpam->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.Trickshot", gTrickShot->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.Lagometer", gLagometer->Current.iValue);

			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AimBone", gAimBone->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AimAngle", gAimAngle->Current.flValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.ShieldPitchShift", gShieldPitchShift->Current.flValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AntiAimPitchMinimum", gAntiAimPitchMinimum->Current.flValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AntiAimPitchMaximum", gAntiAimPitchMaximum->Current.flValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AimPower", gAimPower->Current.flValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AutoAimTime", gAutoAimTime->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AutoAimDelay", gAutoAimDelay->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AutoZoomDelay", gAutoZoomDelay->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AutoFireDelay", gAutoFireDelay->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.FakeLag", gFakeLag->Current.iValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.RecoilFactor", gRecoilFactor->Current.flValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.SpreadFactor", gSpreadFactor->Current.flValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.FlinchFactor", gFlinchFactor->Current.flValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.FieldOfView", gFieldOfView->Current.flValue);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.PointScale", gPointScale->Current.iValue);

			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AxisVisible.Red", gColorAxisVisible->Current.cValue.x);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AxisVisible.Green", gColorAxisVisible->Current.cValue.y);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AxisVisible.Blue", gColorAxisVisible->Current.cValue.z);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AxisVisible.Alpha", gColorAxisVisible->Current.cValue.w);

			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AxisInvisible.Red", gColorAxisInvisible->Current.cValue.x);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AxisInvisible.Green", gColorAxisInvisible->Current.cValue.y);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AxisInvisible.Blue", gColorAxisInvisible->Current.cValue.z);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AxisInvisible.Alpha", gColorAxisInvisible->Current.cValue.w);

			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AlliesVisible.Red", gColorAlliesVisible->Current.cValue.x);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AlliesVisible.Green", gColorAlliesVisible->Current.cValue.y);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AlliesVisible.Blue", gColorAlliesVisible->Current.cValue.z);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AlliesVisible.Alpha", gColorAlliesVisible->Current.cValue.w);

			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AlliesInvisible.Red", gColorAlliesInvisible->Current.cValue.x);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AlliesInvisible.Green", gColorAlliesInvisible->Current.cValue.y);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AlliesInvisible.Blue", gColorAlliesInvisible->Current.cValue.z);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AlliesInvisible.Alpha", gColorAlliesInvisible->Current.cValue.w);

			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Accents.Red", gColorAccents->Current.cValue.x);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Accents.Green", gColorAccents->Current.cValue.y);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Accents.Blue", gColorAccents->Current.cValue.z);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Accents.Alpha", gColorAccents->Current.cValue.w);

			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.CrossHair.Red", gColorCrossHair->Current.cValue.x);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.CrossHair.Green", gColorCrossHair->Current.cValue.y);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.CrossHair.Blue", gColorCrossHair->Current.cValue.z);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.CrossHair.Alpha", gColorCrossHair->Current.cValue.w);

			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Text.Red", gColorText->Current.cValue.x);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Text.Green", gColorText->Current.cValue.y);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Text.Blue", gColorText->Current.cValue.z);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Text.Alpha", gColorText->Current.cValue.w);

			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Shadow.Red", gColorShadow->Current.cValue.x);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Shadow.Green", gColorShadow->Current.cValue.y);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Shadow.Blue", gColorShadow->Current.cValue.z);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Shadow.Alpha", gColorShadow->Current.cValue.w);

			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.ThreatWarning.Red", gColorThreatWarning->Current.cValue.x);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.ThreatWarning.Green", gColorThreatWarning->Current.cValue.y);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.ThreatWarning.Blue", gColorThreatWarning->Current.cValue.z);
			XML.set(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.ThreatWarning.Alpha", gColorThreatWarning->Current.cValue.w);

			XML.write_document(szFilePath);

			return true;
		}

		catch (const std::runtime_error & error)
		{
			MessageBox(_mainGui.hWindow, error.what(), "Error", MB_OK | MB_ICONERROR);

			return false;
		}
	}
	/*
	//=====================================================================================
	*/
	bool cProfiler::LoadProfile(const std::string& path)
	{
		try
		{
			std::wstring szFilePath;

			if (path.empty())
				szFilePath = acut::AnsiToWstring(acut::GetExeDirectory() + acut::FindAndReplaceString(DEFAULT_XML, " ", ""), CP_ACP);

			else
				szFilePath = acut::AnsiToWstring(path, CP_ACP);

			if (GetFileAttributes(acut::WstringToAnsi(szFilePath, CP_ACP).c_str()) == INVALID_FILE_ATTRIBUTES)
				return false;

			XML.read_from_file(szFilePath);

			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.Mode", gAimBotMode->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.AutoZoom", gAutoZoom->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.AutoFire", gAutoFire->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.AutoWall", gAutoWall->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.ApplyPrediction", gApplyPrediction->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.AntiKillTeamMates", gAntiKillTeamMates->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.AntiKillIgnored", gAntiKillIgnored->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.SilentAim", gSilentAim->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.BoneScan", gBoneScan->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.TargetK9Unit", gTargetK9Unit->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.AntiAimPitch", gAntiAimPitch->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.AntiAimYaw", gAntiAimYaw->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.SortAlgorithmTargets", gSortAlgorithmTargets->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".AimBot.SortAlgorithmBones", gSortAlgorithmBones->Current.iValue);

			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Mode", gWallHackMode->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Boxes", gBoxes->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Bones", gBones->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.SnapLines", gSnapLines->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Distances", gDistances->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Names", gNames->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Weapons", gWeapons->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Entities", gEntities->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.CrossHair", gCrossHair->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Compass", gCompass->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.Radar", gRadar->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.BulletTracers", gBulletTracers->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".WallHack.ThreatWarning", gThreatWarning->Current.iValue);

			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.ThirdPerson", gThirdPerson->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.OrbitalVsat", gOrbitalVsat->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.HardcoreHud", gHardcoreHud->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.DisableEmp", gDisableEmp->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.IdStealer", gIdStealer->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.AirStuckToggle", gAirStuckToggle->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.ReloadCancel", gReloadCancel->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.BoneScanPriorities", gBoneScanPriorities->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.BoneScanRiotShielders", gBoneScanRiotShielders->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.NameSpam", gNameSpam->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.Trickshot", gTrickShot->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Miscellaneous.Lagometer", gLagometer->Current.iValue);

			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AimBone", gAimBone->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AimAngle", gAimAngle->Current.flValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.ShieldPitchShift", gShieldPitchShift->Current.flValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AntiAimPitchMinimum", gAntiAimPitchMinimum->Current.flValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AntiAimPitchMaximum", gAntiAimPitchMaximum->Current.flValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AimPower", gAimPower->Current.flValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AutoAimTime", gAutoAimTime->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AutoAimDelay", gAutoAimDelay->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AutoZoomDelay", gAutoZoomDelay->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.AutoFireDelay", gAutoFireDelay->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.FakeLag", gFakeLag->Current.iValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.RecoilFactor", gRecoilFactor->Current.flValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.SpreadFactor", gSpreadFactor->Current.flValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.FlinchFactor", gFlinchFactor->Current.flValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.FieldOfView", gFieldOfView->Current.flValue);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Tweaks.PointScale", gPointScale->Current.iValue);

			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AxisVisible.Red", gColorAxisVisible->Current.cValue.x);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AxisVisible.Green", gColorAxisVisible->Current.cValue.y);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AxisVisible.Blue", gColorAxisVisible->Current.cValue.z);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AxisVisible.Alpha", gColorAxisVisible->Current.cValue.w);

			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AxisInvisible.Red", gColorAxisInvisible->Current.cValue.x);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AxisInvisible.Green", gColorAxisInvisible->Current.cValue.y);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AxisInvisible.Blue", gColorAxisInvisible->Current.cValue.z);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AxisInvisible.Alpha", gColorAxisInvisible->Current.cValue.w);

			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AlliesVisible.Red", gColorAlliesVisible->Current.cValue.x);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AlliesVisible.Green", gColorAlliesVisible->Current.cValue.y);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AlliesVisible.Blue", gColorAlliesVisible->Current.cValue.z);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AlliesVisible.Alpha", gColorAlliesVisible->Current.cValue.w);

			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AlliesInvisible.Red", gColorAlliesInvisible->Current.cValue.x);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AlliesInvisible.Green", gColorAlliesInvisible->Current.cValue.y);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AlliesInvisible.Blue", gColorAlliesInvisible->Current.cValue.z);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.AlliesInvisible.Alpha", gColorAlliesInvisible->Current.cValue.w);

			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Accents.Red", gColorAccents->Current.cValue.x);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Accents.Green", gColorAccents->Current.cValue.y);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Accents.Blue", gColorAccents->Current.cValue.z);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Accents.Alpha", gColorAccents->Current.cValue.w);

			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.CrossHair.Red", gColorCrossHair->Current.cValue.x);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.CrossHair.Green", gColorCrossHair->Current.cValue.y);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.CrossHair.Blue", gColorCrossHair->Current.cValue.z);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.CrossHair.Alpha", gColorCrossHair->Current.cValue.w);

			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Text.Red", gColorText->Current.cValue.x);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Text.Green", gColorText->Current.cValue.y);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Text.Blue", gColorText->Current.cValue.z);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Text.Alpha", gColorText->Current.cValue.w);

			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Shadow.Red", gColorShadow->Current.cValue.x);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Shadow.Green", gColorShadow->Current.cValue.y);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Shadow.Blue", gColorShadow->Current.cValue.z);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.Shadow.Alpha", gColorShadow->Current.cValue.w);

			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.ThreatWarning.Red", gColorThreatWarning->Current.cValue.x);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.ThreatWarning.Green", gColorThreatWarning->Current.cValue.y);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.ThreatWarning.Blue", gColorThreatWarning->Current.cValue.z);
			XML.get_if_present(acut::FindAndReplaceString(PROGRAM_NAME, " ", "") + ".Colors.ThreatWarning.Alpha", gColorThreatWarning->Current.cValue.w);

			return true;
		}

		catch (const std::runtime_error & error)
		{
			MessageBox(_mainGui.hWindow, error.what(), "Error", MB_OK | MB_ICONERROR);

			return false;
		}
	}
	/*
	//=====================================================================================
	*/
	void cProfiler::DisableAll()
	{
		gAimBotMode->Current.iValue = AIMBOT_MODE_AUTO;
		gAutoZoom->Current.iValue = FALSE;
		gAutoFire->Current.iValue = TRUE;
		gAutoWall->Current.iValue = TRUE;
		gApplyPrediction->Current.iValue = TRUE;
		gAntiKillTeamMates->Current.iValue = FALSE;
		gAntiKillIgnored->Current.iValue = FALSE;
		gSilentAim->Current.iValue = TRUE;
		gBoneScan->Current.iValue = TRUE;
		gTargetK9Unit->Current.iValue = FALSE;
		gAntiAimPitch->Current.iValue = ANTIAIM_PITCH_OFF;
		gAntiAimYaw->Current.iValue = ANTIAIM_YAW_OFF;
		gSortAlgorithmTargets->Current.iValue = SORT_ALGORITHM_DISTANCE;
		gSortAlgorithmBones->Current.iValue = SORT_ALGORITHM_DISTANCE;

		gWallHackMode->Current.iValue = WALLHACK_MODE_AXIS;
		gBoxes->Current.iValue = PLAYER_BOXES_OFF;
		gBones->Current.iValue = PLAYER_BONES_OFF;
		gSnapLines->Current.iValue = PLAYER_SNAPLINES_OFF;
		gDistances->Current.iValue = FALSE;
		gNames->Current.iValue = FALSE;
		gWeapons->Current.iValue = FALSE;
		gEntities->Current.iValue = FALSE;
		gCrossHair->Current.iValue = FALSE;
		gCompass->Current.iValue = FALSE;
		gRadar->Current.iValue = FALSE;
		gBulletTracers->Current.iValue = FALSE;
		gThreatWarning->Current.iValue = FALSE;

		gThirdPerson->Current.iValue = TRUE;
		gOrbitalVsat->Current.iValue = FALSE;
		gHardcoreHud->Current.iValue = FALSE;
		gDisableEmp->Current.iValue = FALSE;
		gIdStealer->Current.iValue = FALSE;
		gAirStuckToggle->Current.iValue = FALSE;
		gReloadCancel->Current.iValue = FALSE;
		gBoneScanPriorities->Current.iValue = FALSE;
		gBoneScanRiotShielders->Current.iValue = FALSE;
		gNameSpam->Current.iValue = FALSE;
		gTrickShot->Current.iValue = FALSE;
		gLagometer->Current.iValue = FALSE;
	}
}

//=====================================================================================