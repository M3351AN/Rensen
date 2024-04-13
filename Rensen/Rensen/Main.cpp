#include "Head.h"
#include "CS2_SDK.h"
const string Rensen_ReleaseDate = "[2024-04-14 01:30]";//程序发布日期
const float Rensen_Version = 3.37;//程序版本
namespace Control_Var//套用到菜单的调试变量 (例如功能开关)
{
	EasyGUI::EasyGUI GUI_VAR; EasyGUI::EasyGUI_IO GUI_IO; BOOL Menu_Open = true;//初始化变量
	const string UI_LocalConfigPath = "Rensen.cfg";
	const string UI_DefaultConfig = "1\n6\n1\n1\n0\n1\n1\n100\n1\n1\n0\n100\n0\n0\n100\n0\n1\n100\n5\n1\n5\n0\n1\n150\n1\n0.015\n0.004\n1\n1\n2\n1\n250\n1\n0\n0\n1\n1\n0\n1\n0\n1\n1\n1\n1\n40\n80\n0\n255\n255\n255\n255\n1\n1\n1\n4\n260\n180\n26\n11\n1\n1\n1000\n10\n1\n1\n5\n5\n1\n1\n0\n0\n1\n1\n1\n0\n0\n1\n160\n800\n350\n0\n45\n0\n200\n200\n255\n250\n200\n200\n255\n2\n0\n1\n1\n3\n10\n10\n0\n1\n2\n10\n1\n500\n1\n1\n4\n1\n3\n1\n10\n100\n1\n1\n0\n1\n";//默认参数
	//----------------------------------------------------------------------------------------------
	BOOL UI_Visual_Res_2560;
	BOOL UI_Visual_Res_1920;
	BOOL UI_Visual_Res_1280;
	BOOL UI_Visual_Res_960;
	BOOL UI_Misc_LoadCloudConfig;
	BOOL UI_Setting_Menu_OPENLINKAuthor;
	BOOL UI_Setting_Menu_SaveLocalConfig;
	BOOL UI_Setting_Menu_StartCS;
	BOOL UI_Setting_Menu_QuitCS;
	BOOL UI_Setting_Menu_RestartMenu;
	BOOL UI_Setting_Menu_Unload;
	//以上变量不需要纳入参数------------------------------------------------------------------------
	BOOL UI_Legit_Aimbot = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 1));
	int UI_Legit_Aimbot_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 2));
	BOOL UI_Legit_Aimbot_JudgingWall = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 3));
	BOOL UI_Legit_Aimbot_RemoveRecoil = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 4));
	BOOL UI_Legit_Aimbot_TriggerOnAim = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 5));
	BOOL UI_Legit_Aimbot_AutoShoot = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 6));
	BOOL UI_Legit_Aimbot_AutoStop = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 7));
	int UI_Legit_Aimbot_AutoShootDelay = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 8));
	BOOL UI_Legit_AdaptiveAimbot = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 9));
	BOOL UI_Legit_Armory_ShowAimbotRange = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 10));
	BOOL UI_Legit_Armory_BodyAim_PISTOL = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 11));
	int UI_Legit_Armory_Range_PISTOL = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 12));
	float UI_Legit_Armory_Smooth_PISTOL = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 13));
	BOOL UI_Legit_Armory_BodyAim_RIFLE = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 14));
	int UI_Legit_Armory_Range_RIFLE = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 15));
	float UI_Legit_Armory_Smooth_RIFLE = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 16));
	BOOL UI_Legit_Armory_BodyAim_SNIPER = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 17));
	int UI_Legit_Armory_Range_SNIPER = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 18));
	float UI_Legit_Armory_Smooth_SNIPER = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 19));
	BOOL UI_Legit_Triggerbot = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 20));
	int UI_Legit_Triggerbot_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 21));
	BOOL UI_Legit_Triggerbot_AnyTarget = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 22));
	int UI_Legit_Triggerbot_ShootDelay = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 23));
	int UI_Legit_Triggerbot_ShootDuration = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 24));
	BOOL UI_Legit_PreciseAim = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 25));
	float UI_Legit_PreciseAim_DefaultSensitivity = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 26));
	float UI_Legit_PreciseAim_EnableSensitivity = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 27));
	BOOL UI_Legit_RemoveRecoil = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 28));
	BOOL UI_Legit_RemoveRecoil_LateralRepair = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 29));
	int UI_Legit_RemoveRecoil_StartBullet = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 30));
	BOOL UI_Legit_Backtracking = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 31));
	int UI_Legit_Backtracking_Time = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 32));
	BOOL UI_Visual_ESP = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 33));
	int UI_Visual_ESP_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 34));
	BOOL UI_Visual_ESP_Box = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 35));
	BOOL UI_Visual_ESP_Health = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 36));
	BOOL UI_Visual_ESP_ActiveWeapon = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 37));
	BOOL UI_Visual_ESP_Snapline = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 38));
	BOOL UI_Visual_ESP_Skeleton = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 39));
	BOOL UI_Visual_ESP_HeadDot = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 40));
	BOOL UI_Visual_ESP_State = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 41));
	BOOL UI_Visual_ESP_Name = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 42));
	BOOL UI_Visual_ESP_Drops = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 43));
	BOOL UI_Visual_ESP_OutFOV = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 44));
	int UI_Visual_ESP_OutFOV_Size = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 45));
	int UI_Visual_ESP_OutFOV_Radius = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 46));
	BOOL UI_Visual_ESP_CustomColor = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 47));
	Variable::Vector4 UI_Visual_ESP_CustomColor_Color = { Variable::string_int_(System::Get_File(UI_LocalConfigPath, 48)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 49)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 50)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 51)) };
	int UI_Visual_ESP_RenderSleep = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 52));
	BOOL UI_Visual_Radar = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 53));
	BOOL UI_Visual_Radar_FollowAngle = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 54));
	float UI_Visual_Radar_Range = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 55));
	int UI_Visual_Radar_Size = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 56));
	int UI_Visual_Radar_Alpha = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 57));
	Variable::Vector2 UI_Visual_Radar_Pos = { Variable::string_int_(System::Get_File(UI_LocalConfigPath, 58)), Variable::string_int_(System::Get_File(UI_LocalConfigPath, 59)) };
	BOOL UI_Misc_BunnyHop = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 60));
	BOOL UI_Misc_HitSound = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 61));
	int UI_Misc_HitSound_Tone = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 62));
	int	UI_Misc_HitSound_Length = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 63));
	BOOL UI_Visual_HitMark = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 64));
	BOOL UI_Visual_HitMark_Damage = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 65));
	int UI_Visual_HitMark_Range = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 66));
	int UI_Visual_HitMark_Length = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 67));
	BOOL UI_Misc_AutoKnife = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 68));
	BOOL UI_Misc_AutoTaser = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 69));
	int UI_Misc_AutoKnife_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 70));
	int UI_Misc_AutoTaser_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 71));
	BOOL UI_Misc_Watermark = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 72));
	BOOL UI_Misc_SniperCrosshair = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 73));
	BOOL UI_Misc_TeamCheck = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 74));
	BOOL UI_Misc_LockGameWindow = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 75));
	BOOL UI_Debug_ShowDebugWindow = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 76));
	BOOL UI_Misc_Sonar = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 77));
	int UI_Misc_Sonar_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 78));
	int UI_Misc_Sonar_Range_Far = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 79));
	int UI_Misc_Sonar_Range_Near = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 80));
	int UI_Misc_SelectedConfig = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 81));
	int UI_Setting_Menu_MenuKey = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 82));
	BOOL UI_Setting_Menu_CustomColor = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 83));
	Variable::Vector4 UI_Setting_Menu_MainColor = { Variable::string_int_(System::Get_File(UI_LocalConfigPath, 84)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 85)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 86)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 87)) };
	Variable::Vector4 UI_Visual_HitMark_Color = { Variable::string_int_(System::Get_File(UI_LocalConfigPath, 88)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 89)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 90)) };
	int UI_Visual_HitMark_Thickness = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 91));
	BOOL UI_Legit_Triggerbot_ShootWhenAccurate = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 92));
	BOOL UI_Misc_AntiAFKKick = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 93));
	BOOL UI_Legit_MagnetAim = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 94));
	float UI_Legit_MagnetAim_Smooth = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 95));
	float UI_Legit_AdaptiveAimbot_InitialSmooth = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 96));
	int UI_Misc_SniperCrosshair_Size = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 97));
	BOOL UI_Spoof_Spoof = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 98));
	BOOL UI_Spoof_AimbotTeam = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 99));
	int UI_Spoof_AimbotTeam_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 100));
	float UI_Spoof_AimbotTeam_Smooth = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 101));
	BOOL UI_Spoof_IncreaseRecoil = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 102));
	int UI_Spoof_IncreaseRecoil_Value = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 103));
	BOOL UI_Spoof_DropC4 = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 104));
	BOOL UI_Spoof_FakeAntiAim = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 105));
	int UI_Spoof_FakeAntiAim_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 106));
	BOOL UI_Spoof_KillDropSniper = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 107));
	float UI_Setting_Menu_MenuAnimation = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 108));
	BOOL UI_Visual_HitMark_KillEffect = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 109));
	int UI_Visual_HitMark_KillEffect_Quantity = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 110));
	int UI_Visual_HitMark_KillEffect_Range = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 111));
	int UI_Visual_ESP_Skeleton_Thickness = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 112));
	BOOL UI_Misc_ByPassOBS = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 113));
	BOOL UI_Misc_SavePerformance = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 114));
	BOOL UI_Legit_Aimbot_AutoScope = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 115));
	//----------------------------------------------------------------------------------------------
	void SaveLocalConfig() noexcept//保存本地参数
	{
		System::Create_File(UI_LocalConfigPath,
			to_string(UI_Legit_Aimbot) + "\n" +
			to_string(UI_Legit_Aimbot_Key) + "\n" +
			to_string(UI_Legit_Aimbot_JudgingWall) + "\n" +
			to_string(UI_Legit_Aimbot_RemoveRecoil) + "\n" +
			to_string(UI_Legit_Aimbot_TriggerOnAim) + "\n" +
			to_string(UI_Legit_Aimbot_AutoShoot) + "\n" +
			to_string(UI_Legit_Aimbot_AutoStop) + "\n" +
			to_string(UI_Legit_Aimbot_AutoShootDelay) + "\n" +
			to_string(UI_Legit_AdaptiveAimbot) + "\n" +
			to_string(UI_Legit_Armory_ShowAimbotRange) + "\n" +
			to_string(UI_Legit_Armory_BodyAim_PISTOL) + "\n" +
			to_string(UI_Legit_Armory_Range_PISTOL) + "\n" +
			to_string(UI_Legit_Armory_Smooth_PISTOL) + "\n" +
			to_string(UI_Legit_Armory_BodyAim_RIFLE) + "\n" +
			to_string(UI_Legit_Armory_Range_RIFLE) + "\n" +
			to_string(UI_Legit_Armory_Smooth_RIFLE) + "\n" +
			to_string(UI_Legit_Armory_BodyAim_SNIPER) + "\n" +
			to_string(UI_Legit_Armory_Range_SNIPER) + "\n" +
			to_string(UI_Legit_Armory_Smooth_SNIPER) + "\n" +
			to_string(UI_Legit_Triggerbot) + "\n" +
			to_string(UI_Legit_Triggerbot_Key) + "\n" +
			to_string(UI_Legit_Triggerbot_AnyTarget) + "\n" +
			to_string(UI_Legit_Triggerbot_ShootDelay) + "\n" +
			to_string(UI_Legit_Triggerbot_ShootDuration) + "\n" +
			to_string(UI_Legit_PreciseAim) + "\n" +
			to_string(UI_Legit_PreciseAim_DefaultSensitivity) + "\n" +
			to_string(UI_Legit_PreciseAim_EnableSensitivity) + "\n" +
			to_string(UI_Legit_RemoveRecoil) + "\n" +
			to_string(UI_Legit_RemoveRecoil_LateralRepair) + "\n" +
			to_string(UI_Legit_RemoveRecoil_StartBullet) + "\n" +
			to_string(UI_Legit_Backtracking) + "\n" +
			to_string(UI_Legit_Backtracking_Time) + "\n" +
			to_string(UI_Visual_ESP) + "\n" +
			to_string(UI_Visual_ESP_Key) + "\n" +
			to_string(UI_Visual_ESP_Box) + "\n" +
			to_string(UI_Visual_ESP_Health) + "\n" +
			to_string(UI_Visual_ESP_ActiveWeapon) + "\n" +
			to_string(UI_Visual_ESP_Snapline) + "\n" +
			to_string(UI_Visual_ESP_Skeleton) + "\n" +
			to_string(UI_Visual_ESP_HeadDot) + "\n" +
			to_string(UI_Visual_ESP_State) + "\n" +
			to_string(UI_Visual_ESP_Name) + "\n" +
			to_string(UI_Visual_ESP_Drops) + "\n" +
			to_string(UI_Visual_ESP_OutFOV) + "\n" +
			to_string(UI_Visual_ESP_OutFOV_Size) + "\n" +
			to_string(UI_Visual_ESP_OutFOV_Radius) + "\n" +
			to_string(UI_Visual_ESP_CustomColor) + "\n" +
			to_string(UI_Visual_ESP_CustomColor_Color.r) + "\n" +
			to_string(UI_Visual_ESP_CustomColor_Color.g) + "\n" +
			to_string(UI_Visual_ESP_CustomColor_Color.b) + "\n" +
			to_string(UI_Visual_ESP_CustomColor_Color.a) + "\n" +
			to_string(UI_Visual_ESP_RenderSleep) + "\n" +
			to_string(UI_Visual_Radar) + "\n" +
			to_string(UI_Visual_Radar_FollowAngle) + "\n" +
			to_string(UI_Visual_Radar_Range) + "\n" +
			to_string(UI_Visual_Radar_Size) + "\n" +
			to_string(UI_Visual_Radar_Alpha) + "\n" +
			to_string(UI_Visual_Radar_Pos.x) + "\n" +
			to_string(UI_Visual_Radar_Pos.y) + "\n" +
			to_string(UI_Misc_BunnyHop) + "\n" +
			to_string(UI_Misc_HitSound) + "\n" +
			to_string(UI_Misc_HitSound_Tone) + "\n" +
			to_string(UI_Misc_HitSound_Length) + "\n" +
			to_string(UI_Visual_HitMark) + "\n" +
			to_string(UI_Visual_HitMark_Damage) + "\n" +
			to_string(UI_Visual_HitMark_Range) + "\n" +
			to_string(UI_Visual_HitMark_Length) + "\n" +
			to_string(UI_Misc_AutoKnife) + "\n" +
			to_string(UI_Misc_AutoTaser) + "\n" +
			to_string(UI_Misc_AutoKnife_Key) + "\n" +
			to_string(UI_Misc_AutoTaser_Key) + "\n" +
			to_string(UI_Misc_Watermark) + "\n" +
			to_string(UI_Misc_SniperCrosshair) + "\n" +
			to_string(UI_Misc_TeamCheck) + "\n" +
			to_string(UI_Misc_LockGameWindow) + "\n" +
			to_string(UI_Debug_ShowDebugWindow) + "\n" +
			to_string(UI_Misc_Sonar) + "\n" +
			to_string(UI_Misc_Sonar_Key) + "\n" +
			to_string(UI_Misc_Sonar_Range_Far) + "\n" +
			to_string(UI_Misc_Sonar_Range_Near) + "\n" +
			to_string(UI_Misc_SelectedConfig) + "\n" +
			to_string(UI_Setting_Menu_MenuKey) + "\n" +
			to_string(UI_Setting_Menu_CustomColor) + "\n" +
			to_string(UI_Setting_Menu_MainColor.r) + "\n" +
			to_string(UI_Setting_Menu_MainColor.g) + "\n" +
			to_string(UI_Setting_Menu_MainColor.b) + "\n" +
			to_string(UI_Setting_Menu_MainColor.a) + "\n" +
			to_string(UI_Visual_HitMark_Color.r) + "\n" +
			to_string(UI_Visual_HitMark_Color.g) + "\n" +
			to_string(UI_Visual_HitMark_Color.b) + "\n" +
			to_string(UI_Visual_HitMark_Thickness) + "\n" +
			to_string(UI_Legit_Triggerbot_ShootWhenAccurate) + "\n" +
			to_string(UI_Misc_AntiAFKKick) + "\n" +
			to_string(UI_Legit_MagnetAim) + "\n" +
			to_string(UI_Legit_MagnetAim_Smooth) + "\n" +
			to_string(UI_Legit_AdaptiveAimbot_InitialSmooth) + "\n" +
			to_string(UI_Misc_SniperCrosshair_Size) + "\n" +
			to_string(UI_Spoof_Spoof) + "\n" +
			to_string(UI_Spoof_AimbotTeam) + "\n" +
			to_string(UI_Spoof_AimbotTeam_Key) + "\n" +
			to_string(UI_Spoof_AimbotTeam_Smooth) + "\n" +
			to_string(UI_Spoof_IncreaseRecoil) + "\n" +
			to_string(UI_Spoof_IncreaseRecoil_Value) + "\n" +
			to_string(UI_Spoof_DropC4) + "\n" +
			to_string(UI_Spoof_FakeAntiAim) + "\n" +
			to_string(UI_Spoof_FakeAntiAim_Key) + "\n" +
			to_string(UI_Spoof_KillDropSniper) + "\n" +
			to_string(UI_Setting_Menu_MenuAnimation) + "\n" +
			to_string(UI_Visual_HitMark_KillEffect) + "\n" +
			to_string(UI_Visual_HitMark_KillEffect_Quantity) + "\n" +
			to_string(UI_Visual_HitMark_KillEffect_Range) + "\n" +
			to_string(UI_Visual_ESP_Skeleton_Thickness) + "\n" +
			to_string(UI_Misc_ByPassOBS) + "\n" +
			to_string(UI_Misc_SavePerformance) + "\n" +
			to_string(UI_Legit_Aimbot_AutoScope) + "\n"
		);
	}
	void LoadCloudConfig(string FileName, string NormalURL = "https://github.com/Coslly/Misc/raw/main/About%20Rensen/") noexcept//加载Github云参数
	{
		System::URL_READ URL_CONFIG = { "Cache_CloudConfig" };
		if (URL_CONFIG.StoreMem(NormalURL + FileName + (string)".cfg?raw=true"))
		{
			UI_Legit_Aimbot = Variable::string_int_(URL_CONFIG.Read(1));
			UI_Legit_Aimbot_Key = Variable::string_int_(URL_CONFIG.Read(2));
			UI_Legit_Aimbot_JudgingWall = Variable::string_int_(URL_CONFIG.Read(3));
			UI_Legit_Aimbot_RemoveRecoil = Variable::string_int_(URL_CONFIG.Read(4));
			UI_Legit_Aimbot_TriggerOnAim = Variable::string_int_(URL_CONFIG.Read(5));
			UI_Legit_Aimbot_AutoShoot = Variable::string_int_(URL_CONFIG.Read(6));
			UI_Legit_Aimbot_AutoStop = Variable::string_int_(URL_CONFIG.Read(7));
			UI_Legit_Aimbot_AutoShootDelay = Variable::string_int_(URL_CONFIG.Read(8));
			UI_Legit_AdaptiveAimbot = Variable::string_int_(URL_CONFIG.Read(9));
			UI_Legit_Armory_ShowAimbotRange = Variable::string_int_(URL_CONFIG.Read(10));
			UI_Legit_Armory_BodyAim_PISTOL = Variable::string_int_(URL_CONFIG.Read(11));
			UI_Legit_Armory_Range_PISTOL = Variable::string_int_(URL_CONFIG.Read(12));
			UI_Legit_Armory_Smooth_PISTOL = Variable::string_float_(URL_CONFIG.Read(13));
			UI_Legit_Armory_BodyAim_RIFLE = Variable::string_int_(URL_CONFIG.Read(14));
			UI_Legit_Armory_Range_RIFLE = Variable::string_int_(URL_CONFIG.Read(15));
			UI_Legit_Armory_Smooth_RIFLE = Variable::string_float_(URL_CONFIG.Read(16));
			UI_Legit_Armory_BodyAim_SNIPER = Variable::string_int_(URL_CONFIG.Read(17));
			UI_Legit_Armory_Range_SNIPER = Variable::string_int_(URL_CONFIG.Read(18));
			UI_Legit_Armory_Smooth_SNIPER = Variable::string_float_(URL_CONFIG.Read(19));
			UI_Legit_Triggerbot = Variable::string_int_(URL_CONFIG.Read(20));
			UI_Legit_Triggerbot_Key = Variable::string_int_(URL_CONFIG.Read(21));
			UI_Legit_Triggerbot_AnyTarget = Variable::string_int_(URL_CONFIG.Read(22));
			UI_Legit_Triggerbot_ShootDelay = Variable::string_int_(URL_CONFIG.Read(23));
			UI_Legit_Triggerbot_ShootDuration = Variable::string_int_(URL_CONFIG.Read(24));
			UI_Legit_PreciseAim = Variable::string_int_(URL_CONFIG.Read(25));
			UI_Legit_PreciseAim_DefaultSensitivity = Variable::string_float_(URL_CONFIG.Read(26));
			UI_Legit_PreciseAim_EnableSensitivity = Variable::string_float_(URL_CONFIG.Read(27));
			UI_Legit_RemoveRecoil = Variable::string_int_(URL_CONFIG.Read(28));
			UI_Legit_RemoveRecoil_LateralRepair = Variable::string_int_(URL_CONFIG.Read(29));
			UI_Legit_RemoveRecoil_StartBullet = Variable::string_int_(URL_CONFIG.Read(30));
			UI_Legit_Backtracking = Variable::string_int_(URL_CONFIG.Read(31));
			UI_Legit_Backtracking_Time = Variable::string_int_(URL_CONFIG.Read(32));
			UI_Visual_ESP = Variable::string_int_(URL_CONFIG.Read(33));
			UI_Visual_ESP_Key = Variable::string_int_(URL_CONFIG.Read(34));
			UI_Visual_ESP_Box = Variable::string_int_(URL_CONFIG.Read(35));
			UI_Visual_ESP_Health = Variable::string_int_(URL_CONFIG.Read(36));
			UI_Visual_ESP_ActiveWeapon = Variable::string_int_(URL_CONFIG.Read(37));
			UI_Visual_ESP_Snapline = Variable::string_int_(URL_CONFIG.Read(38));
			UI_Visual_ESP_Skeleton = Variable::string_int_(URL_CONFIG.Read(39));
			UI_Visual_ESP_HeadDot = Variable::string_int_(URL_CONFIG.Read(40));
			UI_Visual_ESP_State = Variable::string_int_(URL_CONFIG.Read(41));
			UI_Visual_ESP_Name = Variable::string_int_(URL_CONFIG.Read(42));
			UI_Visual_ESP_Drops = Variable::string_int_(URL_CONFIG.Read(43));
			UI_Visual_ESP_OutFOV = Variable::string_int_(URL_CONFIG.Read(44));
			UI_Visual_ESP_OutFOV_Size = Variable::string_int_(URL_CONFIG.Read(45));
			UI_Visual_ESP_OutFOV_Radius = Variable::string_int_(URL_CONFIG.Read(46));
			UI_Visual_ESP_CustomColor = Variable::string_int_(URL_CONFIG.Read(47));
			UI_Visual_ESP_CustomColor_Color = { Variable::string_int_(URL_CONFIG.Read(48)),Variable::string_int_(URL_CONFIG.Read(49)),Variable::string_int_(URL_CONFIG.Read(50)),Variable::string_int_(URL_CONFIG.Read(51)) };
			UI_Visual_ESP_RenderSleep = Variable::string_int_(URL_CONFIG.Read(52));
			UI_Visual_Radar = Variable::string_int_(URL_CONFIG.Read(53));
			UI_Visual_Radar_FollowAngle = Variable::string_int_(URL_CONFIG.Read(54));
			UI_Visual_Radar_Range = Variable::string_float_(URL_CONFIG.Read(55));
			UI_Visual_Radar_Size = Variable::string_int_(URL_CONFIG.Read(56));
			UI_Visual_Radar_Alpha = Variable::string_int_(URL_CONFIG.Read(57));
			UI_Visual_Radar_Pos = { Variable::string_int_(URL_CONFIG.Read(58)), Variable::string_int_(URL_CONFIG.Read(59)) };
			UI_Misc_BunnyHop = Variable::string_int_(URL_CONFIG.Read(60));
			UI_Misc_HitSound = Variable::string_int_(URL_CONFIG.Read(61));
			UI_Misc_HitSound_Tone = Variable::string_int_(URL_CONFIG.Read(62));
			UI_Misc_HitSound_Length = Variable::string_int_(URL_CONFIG.Read(63));
			UI_Visual_HitMark = Variable::string_int_(URL_CONFIG.Read(64));
			UI_Visual_HitMark_Damage = Variable::string_int_(URL_CONFIG.Read(65));
			UI_Visual_HitMark_Range = Variable::string_int_(URL_CONFIG.Read(66));
			UI_Visual_HitMark_Length = Variable::string_int_(URL_CONFIG.Read(67));
			UI_Misc_AutoKnife = Variable::string_int_(URL_CONFIG.Read(68));
			UI_Misc_AutoTaser = Variable::string_int_(URL_CONFIG.Read(69));
			UI_Misc_AutoKnife_Key = Variable::string_int_(URL_CONFIG.Read(70));
			UI_Misc_AutoTaser_Key = Variable::string_int_(URL_CONFIG.Read(71));
			UI_Misc_Watermark = Variable::string_int_(URL_CONFIG.Read(72));
			UI_Misc_SniperCrosshair = Variable::string_int_(URL_CONFIG.Read(73));
			UI_Misc_TeamCheck = Variable::string_int_(URL_CONFIG.Read(74));
			UI_Misc_LockGameWindow = Variable::string_int_(URL_CONFIG.Read(75));
			UI_Debug_ShowDebugWindow = Variable::string_int_(URL_CONFIG.Read(76));
			UI_Misc_Sonar = Variable::string_int_(URL_CONFIG.Read(77));
			UI_Misc_Sonar_Key = Variable::string_int_(URL_CONFIG.Read(78));
			UI_Misc_Sonar_Range_Far = Variable::string_int_(URL_CONFIG.Read(79));
			UI_Misc_Sonar_Range_Near = Variable::string_int_(URL_CONFIG.Read(80));
			UI_Misc_SelectedConfig = Variable::string_int_(URL_CONFIG.Read(81));
			UI_Setting_Menu_MenuKey = Variable::string_int_(URL_CONFIG.Read(82));
			UI_Setting_Menu_CustomColor = Variable::string_int_(URL_CONFIG.Read(83));
			UI_Setting_Menu_MainColor = { Variable::string_int_(URL_CONFIG.Read(84)),Variable::string_int_(URL_CONFIG.Read(85)),Variable::string_int_(URL_CONFIG.Read(86)),Variable::string_int_(URL_CONFIG.Read(87)) };
			UI_Visual_HitMark_Color = { Variable::string_int_(URL_CONFIG.Read(88)) ,Variable::string_int_(URL_CONFIG.Read(89)) ,Variable::string_int_(URL_CONFIG.Read(90)) };
			UI_Visual_HitMark_Thickness = Variable::string_int_(URL_CONFIG.Read(91));
			UI_Legit_Triggerbot_ShootWhenAccurate = Variable::string_int_(URL_CONFIG.Read(92));
			UI_Misc_AntiAFKKick = Variable::string_int_(URL_CONFIG.Read(93));
			UI_Legit_MagnetAim = Variable::string_int_(URL_CONFIG.Read(94));
			UI_Legit_MagnetAim_Smooth = Variable::string_float_(URL_CONFIG.Read(95));
			UI_Legit_AdaptiveAimbot_InitialSmooth = Variable::string_float_(URL_CONFIG.Read(96));
			UI_Misc_SniperCrosshair_Size = Variable::string_int_(URL_CONFIG.Read(97));
			UI_Spoof_Spoof = Variable::string_int_(URL_CONFIG.Read(98));
			UI_Spoof_AimbotTeam = Variable::string_int_(URL_CONFIG.Read(99));
			UI_Spoof_AimbotTeam_Key = Variable::string_int_(URL_CONFIG.Read(100));
			UI_Spoof_AimbotTeam_Smooth = Variable::string_float_(URL_CONFIG.Read(101));
			UI_Spoof_IncreaseRecoil = Variable::string_int_(URL_CONFIG.Read(102));
			UI_Spoof_IncreaseRecoil_Value = Variable::string_int_(URL_CONFIG.Read(103));
			UI_Spoof_DropC4 = Variable::string_int_(URL_CONFIG.Read(104));
			UI_Spoof_FakeAntiAim = Variable::string_int_(URL_CONFIG.Read(105));
			UI_Spoof_FakeAntiAim_Key = Variable::string_int_(URL_CONFIG.Read(106));
			UI_Spoof_KillDropSniper = Variable::string_int_(URL_CONFIG.Read(107));
			UI_Setting_Menu_MenuAnimation = Variable::string_float_(URL_CONFIG.Read(108));
			UI_Visual_HitMark_KillEffect = Variable::string_int_(URL_CONFIG.Read(109));
			UI_Visual_HitMark_KillEffect_Quantity = Variable::string_int_(URL_CONFIG.Read(110));
			UI_Visual_HitMark_KillEffect_Range = Variable::string_int_(URL_CONFIG.Read(111));
			UI_Visual_ESP_Skeleton_Thickness = Variable::string_int_(URL_CONFIG.Read(112));
			UI_Misc_ByPassOBS = Variable::string_int_(URL_CONFIG.Read(113));
			UI_Misc_SavePerformance = Variable::string_int_(URL_CONFIG.Read(114));
			UI_Legit_Aimbot_AutoScope = Variable::string_int_(URL_CONFIG.Read(115));
			URL_CONFIG.Release();
		}
	}
	//----------------------------------------------------------------------------------------------
	namespace Debug_Control_Var//测试调试用的控件变量 (按钮 滑条 选择框 按键选择框 控制台控件)
	{
		string SystemCommand; BOOL SendSystemCommand, ClearCommand;
		BOOL Checkbox_1, Checkbox_2;
		int KeySelector_1, KeySelector_2, Slider_1;
		float Slider_2;
		BOOL Button_1, Button_2;
	}
}
using namespace Control_Var;
void Thread_Menu() noexcept//菜单线程 (提供给使用者丰富的自定义选项)
{
	System::Log("Load Thread: Thread_Menu()");
	GUI_VAR.Window_Create(1010, 790, "Rensen", true);//创建置顶GUI绘制窗口
	while (true)
	{
		GUI_VAR.Window_SetTitle(System::Rand_String(10));//随机菜单窗口标题
		static int UI_Panel = 0;//大区块选择
		static vector<int> UI_WindowSize = { 0,0 };//窗体大小(用于开关动画)
		if (!Menu_Open)UI_WindowSize = { 0,0 };//关闭窗体时
		GUI_VAR.Window_SetSize({ (int)Variable::Animation<class CLASS_Menu_Open_Animation_X>(UI_WindowSize[0],UI_Setting_Menu_MenuAnimation),(int)Variable::Animation<class CLASS_Menu_Open_Animation_Y>(UI_WindowSize[1],UI_Setting_Menu_MenuAnimation) });//窗口大小动画
		if (!GUI_VAR.Window_Move() && Menu_Open)//不在移动窗口时绘制GUI
		{
			if (UI_Setting_Menu_CustomColor)//自定义颜色(单色)
			{
				GUI_VAR.Global_Set_EasyGUI_Color(UI_Setting_Menu_MainColor);//设置主题颜色
				GUI_VAR.GUI_BackGround(4);//自定义颜色星空背景主题
			}
			else GUI_VAR.GUI_BackGround(3);//默认(彩虹)
			GUI_VAR.GUI_Block_Panel(20, 20, 100, GUI_VAR.Window_GetSize().y - 40, "", { "Legit","Visual","Misc","Setting","Debug" }, UI_Panel);
			if (UI_Panel == 0)//Legit
			{
				const auto Block_Aimbot = GUI_VAR.GUI_Block(150, 30, 340, "Aim bot");
				GUI_VAR.GUI_Checkbox(Block_Aimbot, 1, "Enabled", UI_Legit_Aimbot);
				GUI_VAR.GUI_KeySelector<class CLASS_Rensen_Menu_1>(Block_Aimbot, 1, UI_Legit_Aimbot_Key);
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 20,Block_Aimbot.y }, 2, "Judging wall", UI_Legit_Aimbot_JudgingWall);
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 20,Block_Aimbot.y }, 3, "Remove recoil", UI_Legit_Aimbot_RemoveRecoil);
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 20,Block_Aimbot.y }, 4, "Trigger on aiming", UI_Legit_Aimbot_TriggerOnAim);
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 20,Block_Aimbot.y }, 5, "Auto shoot", UI_Legit_Aimbot_AutoShoot, { 255,150,150 });
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 40,Block_Aimbot.y }, 6, "Auto stop", UI_Legit_Aimbot_AutoStop, { 255,150,150 });
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 40,Block_Aimbot.y }, 7, "Auto scope", UI_Legit_Aimbot_AutoScope, { 255,150,150 });
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_2>({ Block_Aimbot.x + 20,Block_Aimbot.y }, 8, "Auto shoot delay", 0, 500, UI_Legit_Aimbot_AutoShootDelay, "ms", { 255,150,150 });
				GUI_VAR.GUI_Checkbox(Block_Aimbot, 9, "Adaptive aimbot", UI_Legit_AdaptiveAimbot, { 200,200,150 });
				GUI_VAR.GUI_Slider<float, class CLASS_Rensen_Menu_3>(Block_Aimbot, 10, "Initial smooth", 0, 20, UI_Legit_AdaptiveAimbot_InitialSmooth, "", { 200,200,150 });
				const auto Block_Armory = GUI_VAR.GUI_Block(150, 390, 370, "Armory");
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 1, "Show range", UI_Legit_Armory_ShowAimbotRange);
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 2, "PISTOL Body aim (else head)", UI_Legit_Armory_BodyAim_PISTOL);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_4>({ Block_Armory.x - 10,Block_Armory.y }, 3, "PISTOL range", 0, 100, UI_Legit_Armory_Range_PISTOL, "%");
				GUI_VAR.GUI_Slider<float, class CLASS_Rensen_Menu_5>({ Block_Armory.x - 10,Block_Armory.y }, 4, "PISTOL smooth", 0, 40, UI_Legit_Armory_Smooth_PISTOL);
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 5, "RIFLE Body aim (else head)", UI_Legit_Armory_BodyAim_RIFLE);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_6>({ Block_Armory.x - 10,Block_Armory.y }, 6, "RIFLE range", 0, 100, UI_Legit_Armory_Range_RIFLE, "%");
				GUI_VAR.GUI_Slider<float, class CLASS_Rensen_Menu_7>({ Block_Armory.x - 10,Block_Armory.y }, 7, "RIFLE smooth", 0, 40, UI_Legit_Armory_Smooth_RIFLE);
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 8, "SNIPER Body aim (else head)", UI_Legit_Armory_BodyAim_SNIPER);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_8>({ Block_Armory.x - 10,Block_Armory.y }, 9, "SNIPER range", 0, 100, UI_Legit_Armory_Range_SNIPER, "%");
				GUI_VAR.GUI_Slider<float, class CLASS_Rensen_Menu_9>({ Block_Armory.x - 10,Block_Armory.y }, 10, "SNIPER smooth", 0, 40, UI_Legit_Armory_Smooth_SNIPER);
				const auto Block_Triggerbot = GUI_VAR.GUI_Block(580, 30, 190, "Trigger bot");
				GUI_VAR.GUI_Checkbox(Block_Triggerbot, 1, "Enabled", UI_Legit_Triggerbot);
				GUI_VAR.GUI_KeySelector<class CLASS_Rensen_Menu_10>(Block_Triggerbot, 1, UI_Legit_Triggerbot_Key);
				GUI_VAR.GUI_Checkbox({ Block_Triggerbot.x + 20,Block_Triggerbot.y }, 2, "Any target", UI_Legit_Triggerbot_AnyTarget);
				GUI_VAR.GUI_Checkbox({ Block_Triggerbot.x + 20,Block_Triggerbot.y }, 3, "Shoot when accurate", UI_Legit_Triggerbot_ShootWhenAccurate);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_11>(Block_Triggerbot, 4, "Shoot delay", 1, 500, UI_Legit_Triggerbot_ShootDelay, "ms");
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_12>(Block_Triggerbot, 5, "Shoot duration", 1, 1000, UI_Legit_Triggerbot_ShootDuration, "ms");
				const auto Block_PreciseAim = GUI_VAR.GUI_Block(580, 240, 130, "Precise aim");
				GUI_VAR.GUI_Checkbox(Block_PreciseAim, 1, "Enabled", UI_Legit_PreciseAim);
				GUI_VAR.GUI_Slider<float, class CLASS_Rensen_Menu_13>(Block_PreciseAim, 2, "Default sensitivity", 0, 0.022, UI_Legit_PreciseAim_DefaultSensitivity);
				GUI_VAR.GUI_Slider<float, class CLASS_Rensen_Menu_14>(Block_PreciseAim, 3, "Enable sensitivity", 0, 0.015, UI_Legit_PreciseAim_EnableSensitivity);
				const auto Block_RemoveRecoil = GUI_VAR.GUI_Block(580, 390, 130, "Remove recoil");
				GUI_VAR.GUI_Checkbox(Block_RemoveRecoil, 1, "Enabled", UI_Legit_RemoveRecoil);
				GUI_VAR.GUI_Checkbox({ Block_RemoveRecoil.x + 20,Block_RemoveRecoil.y }, 2, "Lateral repair", UI_Legit_RemoveRecoil_LateralRepair);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_15>(Block_RemoveRecoil, 3, "Start bullet", 1, 10, UI_Legit_RemoveRecoil_StartBullet);
				const auto Block_MagnetAim = GUI_VAR.GUI_Block(580, 540, 100, "Magnet aim");
				GUI_VAR.GUI_Checkbox(Block_MagnetAim, 1, "Enabled", UI_Legit_MagnetAim);
				GUI_VAR.GUI_Slider<float, class CLASS_Rensen_Menu_16>(Block_MagnetAim, 2, "Smooth", 0.5, 6.6666, UI_Legit_MagnetAim_Smooth);
				const auto Block_Backtracking = GUI_VAR.GUI_Block(580, 660, 100, "Back tracking");
				GUI_VAR.GUI_Checkbox(Block_Backtracking, 1, "Enabled", UI_Legit_Backtracking);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_17>(Block_Backtracking, 2, "Maximum time", 0, 500, UI_Legit_Backtracking_Time, "ms");
				GUI_VAR.GUI_Tips(Block_Aimbot, 1, "Help you quickly aim at the target.");
				GUI_VAR.GUI_Tips({ Block_Aimbot.x + 10,Block_Aimbot.y }, 5, "Prefer Ragebot.", { 255,150,150 });
				GUI_VAR.GUI_Tips(Block_Aimbot, 9, "More biological than normal aimbot.", { 200,200,150 });
				GUI_VAR.GUI_Tips(Block_Triggerbot, 1, "Shoot when aiming at the enemy.");
				GUI_VAR.GUI_Tips(Block_PreciseAim, 1, "Reduce the sensitivity of the reticle when aiming at the enemy.");
				GUI_VAR.GUI_Tips({ Block_RemoveRecoil.x + 10,Block_RemoveRecoil.y }, 2, "Operations that only return landscape.");
				GUI_VAR.GUI_Tips(Block_MagnetAim, 1, "Slow aiming without triggering key conditions. (Hard to see)");
				GUI_VAR.GUI_Tips(Block_Backtracking, 1, "Take advantage of network latency to have a bigger hitbox.");
				UI_WindowSize = { 1010,790 };
			}
			else if (UI_Panel == 1)//Visual
			{
				const auto Block_ESP = GUI_VAR.GUI_Block(150, 30, 520, "Extra sensory perception");
				GUI_VAR.GUI_Checkbox(Block_ESP, 1, "Enabled", UI_Visual_ESP);
				GUI_VAR.GUI_KeySelector<class CLASS_Rensen_Menu_18>(Block_ESP, 1, UI_Visual_ESP_Key);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 2, "Box", UI_Visual_ESP_Box);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 3, "Health bar", UI_Visual_ESP_Health);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 4, "Weapon text", UI_Visual_ESP_ActiveWeapon);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 5, "Line", UI_Visual_ESP_Snapline);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 6, "Skeleton", UI_Visual_ESP_Skeleton);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_19>(Block_ESP, 7, "Thickness", 1, 5, UI_Visual_ESP_Skeleton_Thickness, "px");
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 8, "Head dot", UI_Visual_ESP_HeadDot);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 9, "State", UI_Visual_ESP_State);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 10, "Name", UI_Visual_ESP_Name);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 11, "Drops", UI_Visual_ESP_Drops);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 12, "Out of FOV arrow", UI_Visual_ESP_OutFOV);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_20>(Block_ESP, 13, "Size", 20, 70, UI_Visual_ESP_OutFOV_Size, "px");
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_21>(Block_ESP, 14, "Radius", 0, 100, UI_Visual_ESP_OutFOV_Radius, "%");
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 15, "Custom color", UI_Visual_ESP_CustomColor);
				GUI_VAR.GUI_ColorSelector(Block_ESP, 15, UI_Visual_ESP_CustomColor_Color);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_22>(Block_ESP, 16, "Draw delay", 1, 20, UI_Visual_ESP_RenderSleep, "ms");
				const auto Block_Hitmark = GUI_VAR.GUI_Block(580, 30, 280, "Hit mark");
				GUI_VAR.GUI_Checkbox(Block_Hitmark, 1, "Enabled", UI_Visual_HitMark);
				GUI_VAR.GUI_ColorSelector(Block_Hitmark, 1, UI_Visual_HitMark_Color);
				GUI_VAR.GUI_Checkbox({ Block_Hitmark.x + 20,Block_Hitmark.y }, 2, "Show damage", UI_Visual_HitMark_Damage);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_23>(Block_Hitmark, 3, "Range", 3, 100, UI_Visual_HitMark_Range, "px");
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_24>(Block_Hitmark, 4, "Length", 3, 100, UI_Visual_HitMark_Length, "px");
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_25>(Block_Hitmark, 5, "Thickness", 1, 10, UI_Visual_HitMark_Thickness, "px");
				GUI_VAR.GUI_Checkbox({ Block_Hitmark.x + 20,Block_Hitmark.y }, 6, "Lightning effect", UI_Visual_HitMark_KillEffect);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_26>(Block_Hitmark, 7, "Quantity", 10, 500, UI_Visual_HitMark_KillEffect_Quantity);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_27>(Block_Hitmark, 8, "Range", 10, 500, UI_Visual_HitMark_KillEffect_Range);
				const auto Block_Radar = GUI_VAR.GUI_Block(580, 330, 190, "Radar");
				GUI_VAR.GUI_Checkbox(Block_Radar, 1, "Enabled", UI_Visual_Radar);
				GUI_VAR.GUI_Checkbox({ Block_Radar.x + 20,Block_Radar.y }, 2, "Follow angle", UI_Visual_Radar_FollowAngle);
				GUI_VAR.GUI_Slider<float, class CLASS_Rensen_Menu_28>(Block_Radar, 3, "Range", 0.2, 40, UI_Visual_Radar_Range);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_29>(Block_Radar, 4, "Size", 150, 500, UI_Visual_Radar_Size, "px");
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_30>(Block_Radar, 5, "Alpha", 100, 240, UI_Visual_Radar_Alpha);
				GUI_VAR.GUI_Tips(Block_ESP, 1, "Learn enemy coordinates through walls. (Full screen cannot be used)");
				GUI_VAR.GUI_Tips(Block_Hitmark, 1, "Effect that triggers when hitting the player.");
				GUI_VAR.GUI_Tips(Block_Radar, 1, "Exterior window radar. (Full screen cannot be used)");
				UI_WindowSize = { 1010,580 };
			}
			else if (UI_Panel == 2)//Misc
			{
				const auto Block_Misc = GUI_VAR.GUI_Block(150, 30, 550, "Misc");
				GUI_VAR.GUI_Checkbox(Block_Misc, 1, "Bunny hop", UI_Misc_BunnyHop);
				GUI_VAR.GUI_Checkbox(Block_Misc, 2, "Hit sound", UI_Misc_HitSound);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_31>(Block_Misc, 3, "Tone", 10, 5000, UI_Misc_HitSound_Tone);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_32>(Block_Misc, 4, "Length", 10, 100, UI_Misc_HitSound_Length);
				GUI_VAR.GUI_Checkbox(Block_Misc, 5, "Sonar", UI_Misc_Sonar);
				GUI_VAR.GUI_KeySelector<class CLASS_Rensen_Menu_33>(Block_Misc, 5, UI_Misc_Sonar_Key);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_34>(Block_Misc, 6, "Range far", 500, 1000, UI_Misc_Sonar_Range_Far);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_35>(Block_Misc, 7, "Range near", 0, 500, UI_Misc_Sonar_Range_Near);
				GUI_VAR.GUI_Checkbox(Block_Misc, 8, "Knife bot", UI_Misc_AutoKnife);
				GUI_VAR.GUI_KeySelector<class CLASS_Rensen_Menu_36>(Block_Misc, 8, UI_Misc_AutoKnife_Key);
				GUI_VAR.GUI_Checkbox(Block_Misc, 9, "Taser bot", UI_Misc_AutoTaser);
				GUI_VAR.GUI_KeySelector<class CLASS_Rensen_Menu_37>(Block_Misc, 9, UI_Misc_AutoTaser_Key);
				GUI_VAR.GUI_Checkbox(Block_Misc, 10, "Water mark", UI_Misc_Watermark);
				GUI_VAR.GUI_Checkbox(Block_Misc, 11, "Sniper crosshair", UI_Misc_SniperCrosshair);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_38>(Block_Misc, 12, "Size", 10, 30, UI_Misc_SniperCrosshair_Size, "px");
				GUI_VAR.GUI_Checkbox(Block_Misc, 13, "Anti AFK kick", UI_Misc_AntiAFKKick);
				GUI_VAR.GUI_Checkbox(Block_Misc, 14, "Lock game window", UI_Misc_LockGameWindow);
				GUI_VAR.GUI_Checkbox(Block_Misc, 15, "Hide from OBS", UI_Misc_ByPassOBS);
				GUI_VAR.GUI_Checkbox(Block_Misc, 16, "Save performance", UI_Misc_SavePerformance);
				GUI_VAR.GUI_Checkbox(Block_Misc, 17, "Global team check", UI_Misc_TeamCheck, { 200,200,150 });
				const auto Block_Resolution = GUI_VAR.GUI_Block(580, 30, 160, "Screen resolution");
				GUI_VAR.GUI_Button(Block_Resolution, 1, "2560 * 1440", UI_Visual_Res_2560, 78);
				GUI_VAR.GUI_Button(Block_Resolution, 2, "1920 * 1080", UI_Visual_Res_1920, 78);
				GUI_VAR.GUI_Button(Block_Resolution, 3, "1280 * 1024", UI_Visual_Res_1280, 78);
				GUI_VAR.GUI_Button(Block_Resolution, 4, "1280 * 960", UI_Visual_Res_960, 83);
				const auto Block_CloudConfig = GUI_VAR.GUI_Block(580, 210, 150, "Cloud config");
				GUI_VAR.GUI_Button(Block_CloudConfig, 1, "Load config", UI_Misc_LoadCloudConfig, 80);
				GUI_VAR.GUI_List(Block_CloudConfig, 2, { "Legit","Rage","Legit - no visual" }, UI_Misc_SelectedConfig);
				auto Block_Spoof = GUI_VAR.GUI_Block(580, 380, 280, "Spoof");
				GUI_VAR.GUI_Checkbox(Block_Spoof, 1, "Enabled", UI_Spoof_Spoof, { 200,200,150 });//恶搞功能总开关
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 2, "Aim at teammate", UI_Spoof_AimbotTeam);
				GUI_VAR.GUI_KeySelector<class CLASS_Rensen_Menu_39>(Block_Spoof, 2, UI_Spoof_AimbotTeam_Key);
				GUI_VAR.GUI_Slider<float, class CLASS_Rensen_Menu_40>({ Block_Spoof.x + 20,Block_Spoof.y }, 3, "Smooth", 0, 20, UI_Spoof_AimbotTeam_Smooth);
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 4, "Increase recoil", UI_Spoof_IncreaseRecoil);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_41>({ Block_Spoof.x + 20,Block_Spoof.y }, 5, "Strength", 50, 1000, UI_Spoof_IncreaseRecoil_Value, "px");
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 6, "Unable to pick up C4", UI_Spoof_DropC4);
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 7, "Fake anti aim", UI_Spoof_FakeAntiAim);
				GUI_VAR.GUI_KeySelector<class CLASS_Rensen_Menu_42>(Block_Spoof, 7, UI_Spoof_FakeAntiAim_Key);
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 8, "Kill drop sniper", UI_Spoof_KillDropSniper);
				GUI_VAR.GUI_Tips(Block_Misc, 2, "Play Beep when hitting player.");
				GUI_VAR.GUI_Tips(Block_Misc, 5, "Makes a subtle sound when approaching an enemy.");
				GUI_VAR.GUI_Tips(Block_Misc, 8, "Auto attack when conditions such as distance and blood volume are met.");
				GUI_VAR.GUI_Tips(Block_Misc, 14, "Lock the game window to the front.");
				GUI_VAR.GUI_Tips(Block_Misc, 16, "Reduce the load on the CPU.");
				GUI_VAR.GUI_Tips({ Block_Resolution.x + 10,Block_Resolution.y }, 1, "Flexible switching of window resolution.");
				GUI_VAR.GUI_Tips({ Block_CloudConfig.x + 10,Block_CloudConfig.y }, 1, "Load parameter files stored in Github.");
				GUI_VAR.GUI_Tips(Block_Spoof, 1, "Prank local player. (global switch)");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 2, "Aimbot for teammate.");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 4, "Enhanced upward deflection of firearms.");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 6, "Drop it when picking up C4.");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 7, "Rotate view......");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 8, "Drop the weapon when killing an enemy with a sniper rifle.");
				UI_WindowSize = { 1010,690 };
			}
			else if (UI_Panel == 3)//Setting
			{
				const auto Block_About = GUI_VAR.GUI_Block(150, 30, 160, "About");
				GUI_VAR.GUI_Text(Block_About, 1, "Rensen", GUI_VAR.Global_Get_EasyGUI_Color());
				GUI_VAR.GUI_Text({ Block_About.x + 47,Block_About.y }, 1, "for Counter-Strike 2 (External)", { 100,100,100 });
				GUI_VAR.GUI_Text(Block_About, 2, "Version: " + Variable::Float_Precision(Rensen_Version), { 100,100,100 });
				GUI_VAR.GUI_Text(Block_About, 3, "Release date: " + Rensen_ReleaseDate, { 100,100,100 });
				GUI_VAR.GUI_Text(Block_About, 4, "Author: https://github.com/Coslly", { 100,100,100 });
				GUI_VAR.GUI_Button_Small({ Block_About.x + 10,Block_About.y }, 4, UI_Setting_Menu_OPENLINKAuthor);
				GUI_VAR.GUI_Tips({ Block_About.x + 10,Block_About.y }, 1, "No ban record so far in 2020!!!", { 150,255,150 });
				const auto Block_Menu = GUI_VAR.GUI_Block(150, 210, 280, "Menu");
				GUI_VAR.GUI_Text(Block_Menu, 1, "Menu key");
				GUI_VAR.GUI_KeySelector<class CLASS_Rensen_Menu_43>(Block_Menu, 1, UI_Setting_Menu_MenuKey);
				GUI_VAR.GUI_Checkbox(Block_Menu, 2, "Menu color", UI_Setting_Menu_CustomColor);
				GUI_VAR.GUI_ColorSelector_a(Block_Menu, 2, UI_Setting_Menu_MainColor);
				if (UI_Setting_Menu_MainColor.a < 100)UI_Setting_Menu_MainColor.a = 100;//限制透明度
				GUI_VAR.GUI_Slider<float, class CLASS_Rensen_Menu_44>(Block_Menu, 3, "Menu animation speed", 1.5, 5, UI_Setting_Menu_MenuAnimation);
				GUI_VAR.GUI_Button(Block_Menu, 4, "Save local config", UI_Setting_Menu_SaveLocalConfig, 65);
				GUI_VAR.GUI_Button(Block_Menu, 5, "Start CS", UI_Setting_Menu_StartCS, 85);
				GUI_VAR.GUI_Button(Block_Menu, 6, "Quit CS", UI_Setting_Menu_QuitCS, 90);
				GUI_VAR.GUI_Button(Block_Menu, 7, "Restart menu", UI_Setting_Menu_RestartMenu, 75);
				GUI_VAR.GUI_Button(Block_Menu, 8, "Unload", UI_Setting_Menu_Unload, 95);
				GUI_VAR.GUI_Tips({ Block_Menu.x + 10,Block_Menu.y }, 4, "If you want to reset the default config you can delete Rensen.cfg in the same folder.");
				UI_WindowSize = { 580,520 };
			}
			else if (UI_Panel == 4)//Debug
			{
				const auto Block_PlayerList = GUI_VAR.GUI_Block(150, 30, 790, "Player list", 330);
				static BOOL UI_Debug_PlayerList_ReloadList = false; static vector<string> PlayerNameList = {}; static int SelectPlayer = 0; static string PlayerName = "";
				GUI_VAR.GUI_Slider<int, class CLASS_Debug_PlayerID>(Block_PlayerList, 1, "Player ID", 0, 64, SelectPlayer);
				GUI_VAR.GUI_Button_Small({ Block_PlayerList.x + 10,Block_PlayerList.y }, 1, UI_Debug_PlayerList_ReloadList);
				if (UI_Debug_PlayerList_ReloadList || System::Sleep_Tick<class CLASS_DEBUG_AUTO_RELOAD_PLAYERLIST_>(3000)) { PlayerNameList = {}; for (short i = 0; i <= 64; ++i)PlayerNameList.push_back(Advanced::Player_Name(i)); System::Log("Debug: Reload player list"); }//刷新玩家列表页面
				GUI_VAR.GUI_InputText<class CLASS_Debug_PlayerName>(Block_PlayerList, 2, PlayerName);
				if (PlayerName != "" && PlayerName != "None") { for (short i = 0; i <= 64; ++i)if (PlayerName == Advanced::Player_Name(i))SelectPlayer = i; }//人物名称搜索
				GUI_VAR.GUI_List(Block_PlayerList, 3, PlayerNameList, SelectPlayer, 27);
				GUI_VAR.GUI_Tips({ Block_PlayerList.x + 12,Block_PlayerList.y }, 1, "Reload player list.");
				GUI_VAR.GUI_Tips({ Block_PlayerList.x + 12,Block_PlayerList.y }, 2, "Search player name.");
				const auto Block_Info = GUI_VAR.GUI_Block(510, 30, 490, "Info", 330);
				const auto Player_Pawn = Advanced::Traverse_Player(SelectPlayer);
				Variable::Vector4 Debug_PawnColor = { 0,0,0 };//人物数据地址绘制颜色
				if (Player_Pawn.Pawn() == Global_LocalPlayer.Pawn())Debug_PawnColor = { 100,100,255 };//自身
				else if (Player_Pawn.TeamNumber() == Global_LocalPlayer.TeamNumber())Debug_PawnColor = { 0,255,0 };//同队
				else if (Player_Pawn.TeamNumber() != Global_LocalPlayer.TeamNumber())Debug_PawnColor = { 255,0,0 };//不同队
				if (Player_Pawn.Health() == 0)Debug_PawnColor = { 150,150,150 };//无效或是死亡
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 1, "client.dll -> " + Variable::Hex_String(Module_client));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 2, "Pawn -> " + Variable::Hex_String(Player_Pawn.Pawn()), Debug_PawnColor);
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 3, "Name: " + Advanced::Player_Name(SelectPlayer));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 4, "Health: " + to_string(Player_Pawn.Health()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 5, "Armor: " + to_string(Player_Pawn.Armor()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 6, "TeamNum: " + to_string(Player_Pawn.TeamNumber()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 7, "IDEntIndex: " + to_string(Player_Pawn.IDEntIndex()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 8, "Flags: " + to_string(Player_Pawn.Flags()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 9, "ShotsFired: " + to_string(Player_Pawn.ShotsFired()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 10, "MoveSpeed: " + to_string(Player_Pawn.MoveSpeed()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 11, "Spotted: " + to_string(Player_Pawn.Spotted()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 12, "Scoped: " + to_string(Player_Pawn.Scoped()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 13, "ActiveWeapon: " + Player_Pawn.ActiveWeaponName() + " (" + to_string(Player_Pawn.ActiveWeapon()) + ")");
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 14, "Origin: ");
				auto PlayerOrigin = Player_Pawn.Origin(); GUI_VAR.GUI_PosSelector({ Block_Info.x - 100,Block_Info.y }, 14, PlayerOrigin);
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 15, "Angle: ");
				auto PlayerViewAngle = Base::ViewAngles(); GUI_VAR.GUI_PosSelector({ Block_Info.x - 100,Block_Info.y }, 15, PlayerViewAngle);
				GUI_VAR.GUI_Tips({ Block_Info.x + 3,Block_Info.y }, 1, "Cloud offsets date: [" + CS2_Offsets::Offsets_Date + "]");
				//-----------------------------------------------------------------------------------------------------------------------------测试控件-------
				const auto Block_DebugControl = GUI_VAR.GUI_Block(510, 540, 280, "Debug control", 330);
				GUI_VAR.GUI_Checkbox(Block_DebugControl, 1, "Show console window", UI_Debug_ShowDebugWindow);
				GUI_VAR.GUI_Button_Small({ Block_DebugControl.x - 2,Block_DebugControl.y }, 1, Debug_Control_Var::ClearCommand);
				GUI_VAR.GUI_InputText<class CLASS_Rensen_Menu_36>({ Block_DebugControl.x - 15,Block_DebugControl.y }, 2, Debug_Control_Var::SystemCommand);
				GUI_VAR.GUI_Button_Small({ Block_DebugControl.x - 2,Block_DebugControl.y }, 2, Debug_Control_Var::SendSystemCommand);
				GUI_VAR.GUI_Checkbox(Block_DebugControl, 3, "Checkbox 1", Debug_Control_Var::Checkbox_1);
				GUI_VAR.GUI_KeySelector<class CLASS_Rensen_DebugControl_1>({ Block_DebugControl.x - 70,Block_DebugControl.y }, 3, Debug_Control_Var::KeySelector_1);
				GUI_VAR.GUI_Checkbox(Block_DebugControl, 4, "Checkbox 2", Debug_Control_Var::Checkbox_2);
				GUI_VAR.GUI_KeySelector<class CLASS_Rensen_DebugControl_2>({ Block_DebugControl.x - 70,Block_DebugControl.y }, 4, Debug_Control_Var::KeySelector_2);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_DebugControl_3>({ Block_DebugControl.x - 15,Block_DebugControl.y }, 5, "Slider int", -100, 100, Debug_Control_Var::Slider_1);
				GUI_VAR.GUI_Slider<float, class CLASS_Rensen_DebugControl_4>({ Block_DebugControl.x - 15,Block_DebugControl.y }, 6, "Slider float", -50, 50, Debug_Control_Var::Slider_2);
				GUI_VAR.GUI_Button({ Block_DebugControl.x - 15,Block_DebugControl.y }, 7, "Button 1", Debug_Control_Var::Button_1);
				GUI_VAR.GUI_Button({ Block_DebugControl.x - 15,Block_DebugControl.y }, 8, "Button 2", Debug_Control_Var::Button_2);
				GUI_VAR.GUI_Tips(Block_DebugControl, 1, "Clear console.");
				GUI_VAR.GUI_Tips(Block_DebugControl, 2, "Send command to system.");
				GUI_VAR.GUI_Tips(Block_DebugControl, 3, "GUI Draw FPS: " + to_string(GUI_VAR.Window_FPS() + System::Rand_Number(0, 1)) + "." + to_string(System::Rand_Number(100, 999)) + "  (" + to_string(GUI_VAR.Window_FPS()) + ")");//绘制GUI绘制帧数
				if (Debug_Control_Var::ClearCommand)system("cls");//清除控制台
				if (Debug_Control_Var::SendSystemCommand)//向系统发送指令
				{
					cout << Debug_Control_Var::SystemCommand << endl;//打印控制台
					if (Variable::String_Find(Debug_Control_Var::SystemCommand, "/"))//检测是否是命令
					{
						string Last_Send_STR = Debug_Control_Var::SystemCommand; Last_Send_STR.erase(0, 1);//擦除/
						system(Last_Send_STR.c_str());
					}
					else System::Log("Misc: Invalid command. Please add / in front of.", true);
				}
				if (Debug_Control_Var::Button_1 || Debug_Control_Var::Button_2)System::Log("Debug: Click button");
				if (Debug_Control_Var::Button_1)
				{
					System::Log("Username: " + System::Get_UserName());//打印用户名
					System::Log("Computername: " + System::Get_ComputerName());//打印用户电脑名
					System::Log("IP V4: " + System::Get_IPv4Address());//打印用户IPV4
				}
				UI_WindowSize = { 870,850 };
			}
			GUI_VAR.Draw_GUI(Debug_Control_Var::Checkbox_2);//最终绘制GUI画板
			if (UI_Misc_SavePerformance)Sleep(10);//节省电脑占用性能
			if (true)//按钮事件接收
			{
				if (UI_Visual_Res_2560)Window::Set_Resolution(2560, 1440);//设置显示器像素
				else if (UI_Visual_Res_1920)Window::Set_Resolution(1920, 1080);
				else if (UI_Visual_Res_1280)Window::Set_Resolution(1280, 1024);
				else if (UI_Visual_Res_960)Window::Set_Resolution(1280, 960);
				if (UI_Misc_LoadCloudConfig)//加载Github上的云参数
				{
					const auto Config_ID = UI_Misc_SelectedConfig;//防止套用的参数套写变量
					if (UI_Misc_SelectedConfig == 0)LoadCloudConfig("Legit");
					else if (UI_Misc_SelectedConfig == 1)LoadCloudConfig("Rage");
					else if (UI_Misc_SelectedConfig == 2)LoadCloudConfig("Legit No Visual");
					System::Log("Misc: LoadCloudConfig [" + to_string(Config_ID) + "]");
				}
				if (UI_Setting_Menu_OPENLINKAuthor)//打开作者Github主题页面
				{
					System::Open_Website("https://github.com/Coslly");
					System::Log("Setting: OpenGithubURL");
				}
				if (UI_Setting_Menu_SaveLocalConfig)//保存当前所设置的参数
				{
					SaveLocalConfig();
					System::Log("Setting: SaveConfig");
				}
				if (UI_Setting_Menu_StartCS)//启动CS
				{
					if (CS2_MEM.Get_ProcessHWND() == 0)System::Open_Website("steam://rungameid/730");
					System::Log("Setting: StartCS");
				}
				if (UI_Setting_Menu_QuitCS)//关闭CS
				{
					if (CS2_MEM.Get_ProcessHWND() != 0)Window::Kill_Window(CS2_MEM.Get_ProcessHWND());
					System::Log("Setting: QuitCS");
				}
				if (UI_Setting_Menu_RestartMenu)//重启菜单
				{
					System::Self_Restart();
					System::Log("Setting: RestartMenu");
				}
				if (UI_Setting_Menu_Unload)//关闭菜单
				{
					Window::NVIDIA_Overlay();
					System::Log("Setting: Unload");
					exit(0);
				}
			}
		}
	}
}
void Thread_Misc() noexcept//杂项线程 (一些菜单事件处理和杂项功能)
{
	System::Log("Load Thread: Thread_Misc()");
	Window::Windows Window_Watermark; const auto Window_Watermark_HWND = Window_Watermark.Create_RenderBlock_Alpha(Window::Get_Resolution().x, 50, "Rensen - Watermark");//创建水印透明窗口
	Window::Render Window_Watermark_Render; Window_Watermark_Render.CreatePaint(Window_Watermark_HWND, 0, 0, Window::Get_Resolution().x, 50);
	ReLoad(true);//刷新CS2_SDK内存数据 (快速初始化)
	while (true)
	{
		ReLoad();//刷新CS2_SDK内存数据
		Global_TeamCheck = UI_Misc_TeamCheck;//队伍判断(文件跨越修改变量)
		if (UI_Misc_LockGameWindow && !Menu_Open)SetForegroundWindow(CS2_HWND);//锁定CS窗口到最前端
		if (UI_Debug_ShowDebugWindow)ShowWindow(GetConsoleWindow(), true);//显示控制台
		else ShowWindow(GetConsoleWindow(), false);//隐藏控制台
		if (UI_Misc_Watermark)//水印
		{
			Window_Watermark.Set_WindowPos(0, 0);
			if (System::Sleep_Tick<class WaterMark_Window_Sleep_Class_>(200))//降低CPU占用
			{
				Window_Watermark.Set_WindowTitle(System::Rand_String(10));//随机水印窗口标题
				static string WaterMark_String = "";
				short WaterMark_String_Size = strlen(WaterMark_String.c_str()) * 4.8;
				if (!CS2_HWND)WaterMark_String = "Rensen | CS not found | " + System::Get_UserName() + " | " + System::Time_String();
				else { WaterMark_String = "Rensen | " + System::Get_UserName() + " | " + System::Time_String(); WaterMark_String_Size = strlen(WaterMark_String.c_str()) * 5.2; }
				const Variable::Vector2 Watermark_Pos = { Window::Get_Resolution().x - WaterMark_String_Size - 10,10 };
				Window_Watermark_Render.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });
				Window_Watermark_Render.RenderA_SolidRect(Watermark_Pos.x, Watermark_Pos.y, WaterMark_String_Size, 14, { 1,1,1,150 });
				if (UI_Setting_Menu_CustomColor)
				{
					Window_Watermark_Render.RenderA_GradientRect(Watermark_Pos.x, Watermark_Pos.y, WaterMark_String_Size / 2, 1, GUI_IO.GUIColor / 2, GUI_IO.GUIColor);
					Window_Watermark_Render.RenderA_GradientRect(Watermark_Pos.x + WaterMark_String_Size / 2, Watermark_Pos.y, WaterMark_String_Size / 2, 1, GUI_IO.GUIColor, GUI_IO.GUIColor / 2);
				}
				else {
					Window_Watermark_Render.RenderA_GradientRect(Watermark_Pos.x, Watermark_Pos.y, WaterMark_String_Size / 2, 1, { GUI_IO.GUIColor_Rainbow[0], GUI_IO.GUIColor_Rainbow[1], GUI_IO.GUIColor_Rainbow[2],255 }, { GUI_IO.GUIColor_Rainbow[3], GUI_IO.GUIColor_Rainbow[4], GUI_IO.GUIColor_Rainbow[5],255 });
					Window_Watermark_Render.RenderA_GradientRect(Watermark_Pos.x + WaterMark_String_Size / 2, Watermark_Pos.y, WaterMark_String_Size / 2, 1, { GUI_IO.GUIColor_Rainbow[3], GUI_IO.GUIColor_Rainbow[4], GUI_IO.GUIColor_Rainbow[5],255 }, { GUI_IO.GUIColor_Rainbow[6], GUI_IO.GUIColor_Rainbow[7], GUI_IO.GUIColor_Rainbow[8],255 });
				}
				Window_Watermark_Render.Render_String(Watermark_Pos.x + 3, Watermark_Pos.y + 1, WaterMark_String, "Small Fonts", 12, { 255,255,255 }, false);
				Window_Watermark_Render.DrawPaint(true);
			}
		}
		else Window_Watermark.Set_WindowPos(99999, 99999);
		if (Global_IsShowWindow && Global_LocalPlayer.Health())//一些杂项功能
		{
			const auto Local_Pos = Global_LocalPlayer.Origin();//本地人物坐标
			const auto Local_ActiveWeaponID = Global_LocalPlayer.ActiveWeapon();//本地人物手持武器ID
			//----------------------------------------------------------------------------------------------------------------------------------------
			for (int i = 0; i <= 20; ++i)//重复遍历 增加容错率
			{
				if (UI_Misc_BunnyHop && System::Get_Key(VK_SPACE) && Global_LocalPlayer.Flags() & (1 << 0))//连跳
				{//开关 & 按下空格 & 当本地人物触及到地面
					ExecuteCommand("+jump");//跳跃
					Sleep(1);
					ExecuteCommand("-jump");
				}
			}
			//----------------------------------------------------------------------------------------------------------------------------------------
			if (UI_Misc_HitSound)//击打音效
			{
				static auto OldDamage = 0; static auto OldKill = 0;
				const auto Damage = Advanced::Local_RoundDamage();//伤害
				const auto Kill = Advanced::Local_RoundDamage(true);//击杀
				if (Global_LocalPlayer.Health() && (Damage > OldDamage || Damage < OldDamage))//当伤害或是击杀值变化则返回
				{
					if (Kill > OldKill)Beep(UI_Misc_HitSound_Tone, UI_Misc_HitSound_Length);//Kill
					else if (Damage > OldDamage)Beep(UI_Misc_HitSound_Tone, UI_Misc_HitSound_Length);//Hit
					OldDamage = Damage; OldKill = Kill;
				}
			}
			//----------------------------------------------------------------------------------------------------------------------------------------
			if (UI_Misc_AutoKnife && (UI_Misc_AutoKnife_Key == 0 || System::Get_Key(UI_Misc_AutoKnife_Key)) && (Local_ActiveWeaponID == 42 || Local_ActiveWeaponID == 59 || Local_ActiveWeaponID >= 500))//自动刀
			{
				for (short i = 0; i < Global_ValidClassID.size(); ++i)
				{
					const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);
					if (!Advanced::Check_Enemy(PlayerPawn))continue;//多点检测
					const auto Player_Pos = PlayerPawn.Origin();//敌人坐标
					const auto Angle = Variable::CalculateAngle(Local_Pos + Global_LocalPlayer.ViewOffset(), PlayerPawn.BonePos(3), Base::ViewAngles());
					if (Variable::Coor_Dis_3D(Local_Pos, Player_Pos) <= 65 && hypot(Angle.x, Angle.y) <= 50)//判断距离(世界坐标, 本地人物视角)
					{
						if (PlayerPawn.Health() <= 55 && PlayerPawn.Health() > 30)//血量判断重刀还是轻刀
						{
							ExecuteCommand("+attack2");
							Sleep(1);
							ExecuteCommand("-attack2");
						}
						else {
							ExecuteCommand("+attack");
							Sleep(1);
							ExecuteCommand("-attack");
						}
					}
				}
			}
			//----------------------------------------------------------------------------------------------------------------------------------------
			if (UI_Misc_AutoTaser && (UI_Misc_AutoTaser_Key == 0 || System::Get_Key(UI_Misc_AutoTaser_Key)) && Local_ActiveWeaponID == 31)//自动电击枪
			{
				for (short i = 0; i < Global_ValidClassID.size(); ++i)
				{
					const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);
					if (!Advanced::Check_Enemy(PlayerPawn))continue;//多点检测
					const auto Player_Pos = PlayerPawn.Origin();//敌人坐标
					if (Variable::Coor_Dis_3D(Local_Pos, Player_Pos) <= 180 && PlayerPawn.Pawn() == Global_LocalPlayer.IDEntIndex_Pawn().Pawn())//判断距离 && 瞄准
					{
						ExecuteCommand("+attack");
						Sleep(1);
						ExecuteCommand("-attack");
					}
				}
			}
			//----------------------------------------------------------------------------------------------------------------------------------------
			if (UI_Misc_AntiAFKKick && System::Sleep_Tick<class CLASS_MISC_ANTIAFKKICK_>(5000)) { System::Mouse_Move(1, 0); Sleep(1); System::Mouse_Move(-1, 0); }//防止挂机踢出游戏脚本
			//----------------------------------------------------------------------------------------------------------------------------------------
			if (UI_Spoof_Spoof)//恶搞功能
			{
				//--------------------------------------
				if (UI_Spoof_AimbotTeam && System::Get_Key(UI_Spoof_AimbotTeam_Key))//瞄准队友
				{
					float Aim_Range = 8;//瞄准范围
					for (short i = 0; i < Global_ValidClassID.size(); ++i)//人物ID遍历
					{
						const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);//遍历的人物Pawn
						if (PlayerPawn.Pawn() == Global_LocalPlayer.Pawn() || !PlayerPawn.Health() || PlayerPawn.TeamNumber() != Global_LocalPlayer.TeamNumber())continue;//检查是否队友
						const auto Angle = Variable::CalculateAngle(Global_LocalPlayer.Origin() + Global_LocalPlayer.ViewOffset(), PlayerPawn.BonePos(6), Base::ViewAngles() + Global_LocalPlayer.AimPunchAngle() * 2);
						const auto Fov = hypot(Angle.x, Angle.y);
						if (!Angle.IsZero() && Fov <= Aim_Range) { Aim_Range = Fov; System::Mouse_Move(-Angle.y * (40 - UI_Spoof_AimbotTeam_Smooth), Angle.x * (40 - UI_Spoof_AimbotTeam_Smooth)); }
					}
				}
				//--------------------------------------
				if (UI_Spoof_IncreaseRecoil && System::Get_ValueBigger<int, class CLASS_MISC_Spoof_IncreaseRecoil_>(Global_LocalPlayer.ShotsFired()))System::Mouse_Move(0, -1 * UI_Spoof_IncreaseRecoil_Value);//加强后坐力
				//--------------------------------------
				if (UI_Spoof_DropC4 && Global_LocalPlayer.ActiveWeapon() == 49)ExecuteCommand("drop");//无法拾取C4
				//--------------------------------------
				if (UI_Spoof_FakeAntiAim && System::Get_Key(UI_Spoof_FakeAntiAim_Key))Advanced::Move_to_Angle(9999, 9999);//陀螺
				//--------------------------------------
				if (UI_Spoof_KillDropSniper)//丢枪狙
				{
					static auto OldKill = 0; const auto Kill = Advanced::Local_RoundDamage(true);//击杀
					if (Kill > OldKill && Global_LocalPlayer.ActiveWeapon(true) == 3 && Global_LocalPlayer.ShotsFired() == 1)ExecuteCommand("drop");//丢弃武器
					if (Kill != OldKill)OldKill = Kill;
				}
				//--------------------------------------
			}
			//----------------------------------------------------------------------------------------------------------------------------------------
			Sleep(1);//降低CPU占用
		}
		else Sleep(20);//降低CPU占用
	}
}
void Thread_Funtion_Aimbot() noexcept//功能线程: 瞄准机器人
{
	System::Log("Load Thread: Thread_Funtion_Aimbot()");
	while (true)
	{
		System::Sleep_ns(600);//比Sleep更快的函数为了更加自然平滑
		if (Global_IsShowWindow && UI_Legit_Aimbot && System::Get_Key(UI_Legit_Aimbot_Key) && Global_LocalPlayer.Health())
		{
			static short Aim_Range, Aim_Parts; static float Aim_Smooth;//瞄准范围,瞄准部位,瞄准平滑度
			BOOL SpottedPlayer_Quantity = false;//是否有实体暴露 (用于优先瞄准暴露的实体)
			const auto LocalPlayer_ActiveWeapon_ID = Global_LocalPlayer.ActiveWeapon();//本地人物手持武器ID
			const auto LocalPlayer_ActiveWeapon_Type = Global_LocalPlayer.ActiveWeapon(true);//本地人物手持武器类型
			if (LocalPlayer_ActiveWeapon_Type == 1)//手枪
			{
				if (UI_Legit_Armory_BodyAim_PISTOL)Aim_Parts = 3; else Aim_Parts = 6;
				Aim_Range = UI_Legit_Armory_Range_PISTOL / 5;
				Aim_Smooth = 40 - UI_Legit_Armory_Smooth_PISTOL;
			}
			else if (LocalPlayer_ActiveWeapon_Type == 2)//步枪
			{
				if (UI_Legit_Armory_BodyAim_RIFLE)Aim_Parts = 3; else Aim_Parts = 6;
				Aim_Range = UI_Legit_Armory_Range_RIFLE / 5;
				Aim_Smooth = 40 - UI_Legit_Armory_Smooth_RIFLE;
			}
			else if (LocalPlayer_ActiveWeapon_Type == 3)//狙击枪
			{
				if (UI_Legit_Armory_BodyAim_SNIPER)Aim_Parts = 3; else Aim_Parts = 6;
				Aim_Range = UI_Legit_Armory_Range_SNIPER / 5;
				Aim_Smooth = 40 - UI_Legit_Armory_Smooth_SNIPER;
			}
			else continue;//如果是无效的武器则重新来过(刀,道具,电击枪等)
			if (Aim_Range == 0)continue;//范围为0时则重新来过
			if (Aim_Smooth == 0)Aim_Smooth = 1;//最小平滑度
			const auto Local_AimPunchAngle = Global_LocalPlayer.AimPunchAngle();
			Aim_Range = Aim_Range + -Local_AimPunchAngle.x;
			static Variable::Vector3 Recoil_Angle;//后坐力角度
			if (UI_Legit_Aimbot_RemoveRecoil)Recoil_Angle = Base::ViewAngles() + Local_AimPunchAngle * 2;//移除后坐力
			else Recoil_Angle = Base::ViewAngles();
			const auto CrosshairId = Advanced::Check_Enemy(Global_LocalPlayer.IDEntIndex_Pawn());//瞄准的实体Pawn
			for (short i = 0; i < Global_ValidClassID.size(); ++i)//遍历优先瞄准暴露的实体
			{
				if (SpottedPlayer_Quantity)continue;//如果有了暴露的实体则直接返回
				const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);//遍历的人物Pawn
				if (!Advanced::Check_Enemy(PlayerPawn))continue;//队伍判断
				const auto Angle = Variable::CalculateAngle(Global_LocalPlayer.Origin() + Global_LocalPlayer.ViewOffset(), PlayerPawn.BonePos(Aim_Parts), Recoil_Angle);//最终瞄准角度
				if (hypot(Angle.x, Angle.y) <= Aim_Range && PlayerPawn.Spotted())SpottedPlayer_Quantity = true;
			}
			for (short i = 0; i < Global_ValidClassID.size(); ++i)//人物ID遍历
			{
				const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);//遍历的人物Pawn
				if (!Advanced::Check_Enemy(PlayerPawn) || (UI_Legit_Aimbot_TriggerOnAim && !CrosshairId) || ((UI_Legit_Aimbot_JudgingWall || SpottedPlayer_Quantity) && !PlayerPawn.Spotted()))continue;
				const auto Angle = Variable::CalculateAngle(Global_LocalPlayer.Origin() + Global_LocalPlayer.ViewOffset(), PlayerPawn.BonePos(Aim_Parts), Recoil_Angle);//最终瞄准角度
				const auto FovG = hypot(Angle.x, Angle.y);//圆圈范围计算
				if (!Angle.IsZero() && FovG <= Aim_Range)//范围判断
				{
					Aim_Range = FovG - 2;//防止锁住两个或多个人
					if (Global_LocalPlayer.Scoped() && LocalPlayer_ActiveWeapon_Type == 3)System::Mouse_Move(-Angle.y * Aim_Smooth * 3.5, Angle.x * Aim_Smooth * 3.5);
					else System::Mouse_Move(-Angle.y * Aim_Smooth, Angle.x * Aim_Smooth);
					if (UI_Legit_Aimbot_AutoShoot && CrosshairId && (!UI_Legit_Aimbot_AutoStop || Advanced::Stop_Move()) && FovG <= 0.8)//AutoShoot & AutoStop
					{
						if (LocalPlayer_ActiveWeapon_Type == 3 && LocalPlayer_ActiveWeapon_ID != 11 && LocalPlayer_ActiveWeapon_ID != 38)System::Key_Con(UI_Legit_Aimbot_Key, false);//单发狙击枪射击后释放按键
						if (UI_Legit_Aimbot_AutoScope && LocalPlayer_ActiveWeapon_Type == 3 && !Global_LocalPlayer.Scoped())//自动开镜
						{
							ExecuteCommand("+attack2");
							Sleep(1);
							ExecuteCommand("-attack2");
						}
						ExecuteCommand("+attack");
						if (LocalPlayer_ActiveWeapon_ID == 64)Sleep(250);//R8无法开枪修复
						else Sleep(1);
						ExecuteCommand("-attack");
						if (UI_Legit_Aimbot_Key == 2 && LocalPlayer_ActiveWeapon_Type == 1) { System::Mouse_Con(2, false); Sleep(1); System::Key_Con(2, true); }//自瞄按键在右键且是手枪则脚本持续开火状态 (可有可无)
						Sleep(UI_Legit_Aimbot_AutoShootDelay);//自动开枪延迟 (缓解后座力)
					}
				}
			}
		}
		else Sleep(20);
	}
}
void Thread_Funtion_AdaptiveAimbot() noexcept//功能线程: 生物瞄准机器人(更加自然的效果)
{
	System::Log("Load Thread: Thread_Funtion_AdaptiveAimbot()");
	while (true)
	{
		System::Sleep_ns(5000);//比Sleep更快的函数为了更加自然平滑
		if (Global_IsShowWindow && UI_Legit_AdaptiveAimbot && System::Get_Key(VK_LBUTTON) && Global_LocalPlayer.Health() && Global_LocalPlayer.ActiveWeapon(true) == 2)//当CS窗口在最前端 && 本地人物活着 && 按键按下 && 步枪
		{
			float Aim_Range = 3; int Aim_Bone = 6; const auto PunchAngle = Global_LocalPlayer.AimPunchAngle();
			if (abs(PunchAngle.x) * 2 >= Aim_Range)Aim_Range = abs(PunchAngle.x) * 1.5;//计算开枪之后附加后坐力的范围
			for (short i = 0; i < Global_ValidClassID.size(); ++i)//人物ID遍历
			{
				const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);//遍历的人物Pawn
				if (!Advanced::Check_Enemy(PlayerPawn) || !PlayerPawn.Spotted())continue;//当没有被发现则重新来过
				if (PlayerPawn.Health() < 60)Aim_Bone = 4;//低血时瞄准躯干 (降低爆头率)
				const auto Angle = Variable::CalculateAngle(Global_LocalPlayer.Origin() + Global_LocalPlayer.ViewOffset(), PlayerPawn.BonePos(Aim_Bone), Base::ViewAngles() + PunchAngle * 2);//最终瞄准角度 (6: 头部)
				const auto FovG = hypot(Angle.x, Angle.y);//圆圈范围计算
				if (!Angle.IsZero() && FovG <= Aim_Range)//范围判断
				{
					Aim_Range = FovG;//防止锁住两个或多个人
					if (Global_LocalPlayer.ShotsFired() > 1 && (System::Get_Key(VK_CONTROL) || FovG <= 1.8) && PlayerPawn.MoveSpeed() <= 180)System::Mouse_Move(-Angle.y * 30, Angle.x * 30);
					else System::Mouse_Move(-Angle.y * (20 - UI_Legit_AdaptiveAimbot_InitialSmooth), Angle.x * (20 - UI_Legit_AdaptiveAimbot_InitialSmooth));
				}
			}
		}
		else Sleep(20);
	}
}
void Thread_Funtion_Triggerbot() noexcept//功能线程: 自动扳机
{
	System::Log("Load Thread: Thread_Funtion_Triggerbot()");
	while (true)
	{
		if (Global_IsShowWindow && UI_Legit_Triggerbot && System::Get_Key(UI_Legit_Triggerbot_Key) && Global_LocalPlayer.Health())//当CS窗口在最前端 && 本地人物活着 && 按键按下
		{
			System::Sleep_ns(1000);//纳秒级延时
			const auto Local_ActiveWeaponID = Global_LocalPlayer.ActiveWeapon();//本地人物手持武器序号
			const auto Local_ActiveWeaponType = Global_LocalPlayer.ActiveWeapon(true);//本地人物手持武器类型
			if (Local_ActiveWeaponID == 42 || Local_ActiveWeaponID == 59 || Local_ActiveWeaponID >= 500 || Local_ActiveWeaponID == 31)continue;//过滤特殊武器 (刀子, 电击枪)
			else if (((UI_Legit_Triggerbot_AnyTarget && Global_LocalPlayer.IDEntIndex() != -1) || Advanced::Check_Enemy(Global_LocalPlayer.IDEntIndex_Pawn())) && (!UI_Legit_Triggerbot_ShootWhenAccurate || Local_ActiveWeaponType == 1 || Advanced::Stop_Move(50, false)))//当瞄准的人是敌人
			{
				ExecuteCommand("+attack");//Shoot!! 开枪!!
				Sleep(UI_Legit_Triggerbot_ShootDuration);
				ExecuteCommand("-attack");
				Sleep(UI_Legit_Triggerbot_ShootDelay);
			}
		}
		else Sleep(20);
	}
}
void Thread_Funtion_AssisteAim() noexcept//功能线程: 精确瞄准
{
	System::Log("Load Thread: Thread_Funtion_AssisteAim()");
	while (true)
	{
		if (Global_IsShowWindow && Global_LocalPlayer.Health())//当CS窗口在最前端 && 本地人物活着
		{
			System::Sleep_ns(2000);//纳秒级延时 (加快循环速度)
			if (UI_Legit_PreciseAim)//精确瞄准
			{
				const auto Local_ActiveWeaponID = Global_LocalPlayer.ActiveWeapon();//本地人物手持武器ID
				if (Local_ActiveWeaponID == 42 || Local_ActiveWeaponID == 59 || Local_ActiveWeaponID >= 500) { ExecuteCommand("m_yaw " + to_string(UI_Legit_PreciseAim_DefaultSensitivity)); Sleep(10); continue; }//过滤特殊武器 (刀类)
				if (Advanced::Check_Enemy(Global_LocalPlayer.IDEntIndex_Pawn()))ExecuteCommand("m_yaw " + to_string(UI_Legit_PreciseAim_EnableSensitivity));
				else ExecuteCommand("m_yaw " + to_string(UI_Legit_PreciseAim_DefaultSensitivity));
			}
			if (UI_Legit_MagnetAim && System::Is_MousePos_InMid(CS2_HWND) && !System::Get_Key(VK_LBUTTON) && Global_LocalPlayer.ActiveWeapon() != 0)//磁吸瞄准
			{
				float Aim_Range = 5;
				for (short i = 0; i < Global_ValidClassID.size(); ++i)//人物ID遍历
				{
					const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);//遍历的人物Pawn
					if (!Advanced::Check_Enemy(PlayerPawn) || !PlayerPawn.Spotted())continue;//简单的实体判断
					const auto Angle = Variable::CalculateAngle(Global_LocalPlayer.Origin() + Global_LocalPlayer.ViewOffset(), PlayerPawn.BonePos(6), Base::ViewAngles());
					const auto Fov = hypot(Angle.x, Angle.y);
					if (Global_LocalPlayer.IDEntIndex_Pawn().Pawn() == PlayerPawn.Pawn() && Fov <= 0.6)continue;//范围光线判断
					if (!Angle.IsZero() && Fov <= Aim_Range) { Aim_Range = Fov; System::Mouse_Move(-Angle.y * (6.6666 - UI_Legit_MagnetAim_Smooth), Angle.x * (6.6666 - UI_Legit_MagnetAim_Smooth)); }
				}
			}
		}
		else Sleep(20);
	}
}
void Thread_Funtion_RemoveRecoil() noexcept//功能线程: 移除后坐力
{
	System::Log("Load Thread: Thread_Funtion_RemoveRecoil()");
	while (true)
	{
		if (Global_IsShowWindow && UI_Legit_RemoveRecoil && Global_LocalPlayer.Health())//移除后坐力
		{
			Sleep(1);
			static auto OldPunch = Variable::Vector3{};
			if (System::Get_Key(VK_LBUTTON) && Global_LocalPlayer.ShotsFired() >= UI_Legit_RemoveRecoil_StartBullet)//判断开出的子弹数
			{
				const auto AimPunch = Global_LocalPlayer.AimPunchAngle();//RecoilAngle
				const auto NewPunch = Variable::Vector3{ OldPunch.x - AimPunch.x * 2,OldPunch.y - AimPunch.y * 2,0 };
				if (UI_Legit_RemoveRecoil_LateralRepair)System::Mouse_Move(-NewPunch.y * 40, 0);//只处理X坐标
				else System::Mouse_Move(-NewPunch.y * 40, NewPunch.x * 28);//X,Y
				OldPunch.x = AimPunch.x * 2;
				OldPunch.y = AimPunch.y * 2;
			}
			else OldPunch.x = OldPunch.y = 0;
		}
		else Sleep(20);
	}
}
void Thread_Funtion_PlayerESP() noexcept//功能线程: 透视和一些视觉杂项
{
	System::Log("Load Thread: Thread_Funtion_PlayerESP()");
	auto Rensen_ESP_RenderWindow = Window::NVIDIA_Overlay();//初始化英伟达覆盖
	Window::Windows SpareRenderWindow;
	if (!Rensen_ESP_RenderWindow)//当没有找到英伟达覆盖时 (不是英伟达显卡)
	{
		System::Log("Error: NVIDIA overlay window not found (Used Generate Alternative Window instead)", true);//未找到英伟达覆盖时报错
		Rensen_ESP_RenderWindow = SpareRenderWindow.Create_RenderBlock_Alpha(0, 0, "NVIDIA overlay (Rensen)");//创建代替覆盖窗口
	}
	Window::Render ESP_Paint; ESP_Paint.CreatePaint(Rensen_ESP_RenderWindow, 0, 0, Window::Get_Resolution().x, Window::Get_Resolution().y);//创建内存画板
	while (true)
	{
		Sleep(UI_Visual_ESP_RenderSleep);
		if (SpareRenderWindow.Get_HWND() != 0)SpareRenderWindow.Fix_inWhile();//当已创建窗口时进入消息循环
		const auto CS_Scr_Res = Window::Get_WindowResolution(CS2_HWND);
		MoveWindow(Rensen_ESP_RenderWindow, CS_Scr_Res.b, CS_Scr_Res.a, CS_Scr_Res.r, CS_Scr_Res.g, true);//修改 Pos & Size
		ESP_Paint.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });//清除画板
		if (CS2_HWND && (Menu_Open || Global_IsShowWindow))//当CS窗口在最前端 && 菜单在最前端
		{
			if (Menu_Open)Sleep(20);//节省CPU性能 (可有可无)
			if (UI_Visual_ESP && (UI_Visual_ESP_Key == 0 || System::Get_Key(UI_Visual_ESP_Key)))//ESP 透视
			{
				auto Draw_Color = GUI_IO.GUIColor;
				if (UI_Visual_ESP_CustomColor)Draw_Color = UI_Visual_ESP_CustomColor_Color;
				const auto Local_Matrix = Base::ViewMatrix(); const auto Local_Angles = Base::ViewAngles(); const auto Local_Position = Global_LocalPlayer.Origin();
				for (short i = 0; i < Global_ValidClassID.size(); ++i)
				{
					const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);
					if (!Advanced::Check_Enemy(PlayerPawn))continue;//多点检测
					const auto Top_Pos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, PlayerPawn.BonePos(6) + Variable::Vector3{ 0, 0, 8 }, Local_Matrix);
					const auto Entity_Position = PlayerPawn.Origin();
					if (Top_Pos.x < -100 || Top_Pos.x > CS_Scr_Res.r + 100)//检测是否在屏幕内
					{
						if (UI_Visual_ESP_OutFOV && Global_LocalPlayer.Health())//方向指示器
						{
							auto Screen_Pos = Variable::Ang_Pos(CS_Scr_Res.g / ((120 - (float)UI_Visual_ESP_OutFOV_Radius) / 10), Local_Angles.y - 90 + atan2((Local_Position.x - Entity_Position.x), (Local_Position.y - Entity_Position.y)) * (180 / acos(-1)));
							Screen_Pos = { CS_Scr_Res.r / 2 - Screen_Pos[0] * ((float)CS_Scr_Res.r / (float)CS_Scr_Res.g),CS_Scr_Res.g / 2 + Screen_Pos[1] };
							ESP_Paint.RenderA_GradientCircle(Screen_Pos[0], Screen_Pos[1], UI_Visual_ESP_OutFOV_Size, { 0,0,0,100 }, { 0,0,0,0 });
							ESP_Paint.RenderA_GradientCircle(Screen_Pos[0], Screen_Pos[1], UI_Visual_ESP_OutFOV_Size, Draw_Color.D_Alpha(System::RainbowColor(3).r), { 0,0,0,0 });
							if (UI_Visual_ESP_ActiveWeapon)ESP_Paint.Render_String(Screen_Pos[0] - 8, Screen_Pos[1] - 4, PlayerPawn.ActiveWeaponName(), "Small Fonts", 9, { 100,100,100 });
						}
						continue;//不绘制ESP 重来
					}
					const auto Bottom_Pos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, PlayerPawn.Origin() - Variable::Vector3{ 0, 0, 6 }, Local_Matrix);
					const auto Hight = Bottom_Pos.y - Top_Pos.y;
					const auto Width = Hight * 0.25;
					const auto Left = Top_Pos.x - Width;
					const auto Right = Top_Pos.x + Width;
					if (Variable::Coor_Dis_3D(Local_Position, Entity_Position) <= 4000)//距离检测 降低CPU占用
					{
						if (UI_Visual_ESP_Snapline)ESP_Paint.RenderA_GradientLine(CS_Scr_Res.r / 2, CS_Scr_Res.g, Left + (Right - Left) / 2, Bottom_Pos.y, { 0,0,0,0 }, Draw_Color.D_Alpha(150));//射线
						if (UI_Visual_ESP_Skeleton)//骨骼
						{
							static const vector<short> Bone_Flags = { 6,5,4,13,14,15,14,13,4,8,9,10,9,8,4,3,2,1,25,26,27,26,25,1,22,23,24,24 };
							for (short i = 0; i <= Bone_Flags.size() - 2; ++i)
							{
								const auto Bone_ScreenPos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, PlayerPawn.BonePos(Bone_Flags[i]), Local_Matrix);
								const auto Bone_ScreenPos_ = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, PlayerPawn.BonePos(Bone_Flags[i + 1]), Local_Matrix);
								ESP_Paint.Render_Line(Bone_ScreenPos.x, Bone_ScreenPos.y, Bone_ScreenPos_.x, Bone_ScreenPos_.y, Draw_Color / 2, UI_Visual_ESP_Skeleton_Thickness);
							}
						}
					}
					if (UI_Visual_ESP_HeadDot)//头点
					{
						const auto Head_ScrPos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, PlayerPawn.BonePos(6), Local_Matrix);
						ESP_Paint.RenderA_GradientCircle(Head_ScrPos.x, Head_ScrPos.y, 10, Draw_Color.D_Alpha(100), { 0,0,0,0 });
					}
					if (UI_Visual_ESP_Box)//方框
					{
						ESP_Paint.RenderA_HollowRect(Left, Top_Pos.y, Right - Left, Bottom_Pos.y - Top_Pos.y, { 0,0,0,130 }, 3);
						ESP_Paint.RenderA_HollowRect(Left, Top_Pos.y, Right - Left, Bottom_Pos.y - Top_Pos.y, Draw_Color.D_Alpha(200));
					}
					if (UI_Visual_ESP_Health)//血条
					{
						const auto PlayerHealth = PlayerPawn.Health();
						auto Health_Ma = PlayerHealth * 0.01;
						if (PlayerHealth > 100)Health_Ma = 1;
						else if (PlayerHealth < 0)Health_Ma = 0;//限制值 防止绘制出错
						ESP_Paint.RenderA_SolidRect(Left - 6, Top_Pos.y - 1, 4, Bottom_Pos.y - Top_Pos.y + 3, { 0,0,0,130 });
						if (UI_Visual_ESP_CustomColor)ESP_Paint.RenderA_SolidRect(Left - 5, Bottom_Pos.y - Hight * Health_Ma, 2, Bottom_Pos.y - (Bottom_Pos.y - Hight * Health_Ma) + 1, Draw_Color.D_Alpha(200));
						else ESP_Paint.RenderA_GradientRect(Left - 5, Bottom_Pos.y - Hight * Health_Ma, 2, Bottom_Pos.y - (Bottom_Pos.y - Hight * Health_Ma) + 1, { (int)(1 - Health_Ma * 255),(int)(255 * Health_Ma),0,200 }, { 255,0,0,200 }, true);
						if (PlayerHealth < 100 && PlayerHealth > 0)ESP_Paint.Render_SmpStr(Left - 8, Bottom_Pos.y - Hight * Health_Ma - 6, to_string(PlayerHealth), { 150,150,150 }, { 0 }, false);
					}
					const auto Player_ClippingWeapon_Name = PlayerPawn.ActiveWeaponName();//人物手持武器名称
					if (UI_Visual_ESP_State)//人物状态
					{
						auto i = 0;//Line pos
						if (PlayerPawn.Armor()) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "HK", { 200,200,200 }, { 0 }, false); ++i; }
						if (Player_ClippingWeapon_Name == "C4") { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "C4", { 255,0,0 }, { 0 }, 0); ++i; }
						if (PlayerPawn.Scoped() && (Player_ClippingWeapon_Name == "AWP" || Player_ClippingWeapon_Name == "SSG08")) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "ZOOM", { 0,120,255 }, { 0 }, false); ++i; }
						if (PlayerPawn.Spotted()) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "HIT", { 200,200,200 }, { 0 }, false); ++i; }
						if (PlayerPawn.ShotsFired() > 0) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "SHOT", { 200,200,200 }, { 0 }, false); ++i; }
						if (!(PlayerPawn.Flags() & (1 << 0))) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "AIR", { 200,200,200 }, { 0 }, false); ++i; }
						if (Variable::Coor_Dis_3D(Local_Position, Entity_Position) >= 2500) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "INV", { 100,0,255 }, { 0 }, false); ++i; }
					}
					if (UI_Visual_ESP_ActiveWeapon)ESP_Paint.Render_SmpStr(Left, Bottom_Pos.y, Player_ClippingWeapon_Name, { 200,200,200 }, { 0 }, false);//手持武器
					if (UI_Visual_ESP_Name)ESP_Paint.RenderA_String(Left - 2, Top_Pos.y - 15, Advanced::Player_Name(Global_ValidClassID[i]), "Segoe UI", 11, { 255,255,255,255 });//名称
				}
			}
			if (UI_Legit_Aimbot && UI_Legit_Armory_ShowAimbotRange && Global_LocalPlayer.Health())//Aimbot Range 自瞄范围绘制
			{
				auto Circle_Range = 0;
				const auto Local_ActiveWeaponType = Global_LocalPlayer.ActiveWeapon(true);//本地人物手持武器类型
				if (Local_ActiveWeaponType == 1)Circle_Range = UI_Legit_Armory_Range_PISTOL * 5;
				else if (Local_ActiveWeaponType == 2)Circle_Range = UI_Legit_Armory_Range_RIFLE * 5;
				else if (Local_ActiveWeaponType == 3) { if (Global_LocalPlayer.Scoped())Circle_Range = UI_Legit_Armory_Range_SNIPER * 14; else Circle_Range = UI_Legit_Armory_Range_SNIPER * 5; }
				if (Circle_Range)Circle_Range = Circle_Range + Global_LocalPlayer.AimPunchAngle().x * -25;
				ESP_Paint.Render_HollowCircle(CS_Scr_Res.r / 2, CS_Scr_Res.g / 2, Variable::Animation<class Render_Aimbot_Range_Animation>(Circle_Range, 2), GUI_IO.GUIColor / 5);
			}
			if (UI_Visual_HitMark && Global_LocalPlayer.Health())//命中标记
			{
				static short Mark_DMG = 0;//造成的伤害
				static Variable::Vector4 Mark_Color, EffectColor;//绘制颜色
				Mark_Color = Mark_Color - Variable::Vector4{ 10, 10, 10 }; Mark_Color = Mark_Color.Re_Col();//准星透明化动画
				EffectColor = EffectColor - Variable::Vector4{ 8, 8, 8 }; EffectColor = EffectColor.Re_Col();//特效透明化动画
				static auto OldDamage = 0; static auto OldKill = 0;
				const auto Damage = Advanced::Local_RoundDamage();//伤害
				const auto Kill = Advanced::Local_RoundDamage(true);//击杀
				const auto IDEnt_Pos = Global_LocalPlayer.IDEntIndex_Pawn().BonePos(5); static auto Target_Pos = IDEnt_Pos;//特效目标坐标
				if (Damage > OldDamage || Damage < OldDamage)//当伤害变化
				{
					if (Kill > OldKill && Global_LocalPlayer.ShotsFired()) { EffectColor = UI_Visual_HitMark_Color; }//Kill
					if (Damage > OldDamage) { Mark_Color = UI_Visual_HitMark_Color; Mark_DMG = Damage - OldDamage; }//Hit
					OldDamage = Damage; OldKill = Kill;//刷新
				}
				if (UI_Visual_HitMark_KillEffect)//闪电击杀效果
				{
					if (EffectColor.r != 0 || EffectColor.g != 0 || EffectColor.b != 0)//3D特效
					{
						const auto Range = UI_Visual_HitMark_KillEffect_Range;//爆炸半径 范围
						const auto Player_Matrix = Base::ViewMatrix();//本地人物视角矩阵
						for (short i = 0; i <= UI_Visual_HitMark_KillEffect_Quantity; ++i)//绘制粒子线条
						{
							srand(i * Kill);//随机种子
							const auto Effect_Pos = Variable::WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, Target_Pos, Player_Matrix);//起点坐标
							const auto Effect_Pos_To = Variable::WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, { Target_Pos.x + rand() % Range - Range / 2,Target_Pos.y + rand() % Range - Range / 2,Target_Pos.z + rand() % Range - Range / 2 }, Player_Matrix);
							ESP_Paint.Render_Line(Effect_Pos.x, Effect_Pos.y, Effect_Pos_To.x, Effect_Pos_To.y, EffectColor);
						}
					}
					else if (IDEnt_Pos.x != 0)Target_Pos = IDEnt_Pos;
				}
				if (Mark_Color.r != 0 || Mark_Color.g != 0 || Mark_Color.b != 0)//2D准星
				{
					const short Range = UI_Visual_HitMark_Range, Length = UI_Visual_HitMark_Length, Width = UI_Visual_HitMark_Thickness;//绘制设置(距离,长度,粗细)
					ESP_Paint.Render_Line(CS_Scr_Res.r / 2 - Range, CS_Scr_Res.g / 2 - Range, CS_Scr_Res.r / 2 - Range - Length, CS_Scr_Res.g / 2 - Range - Length, Mark_Color, Width);
					ESP_Paint.Render_Line(CS_Scr_Res.r / 2 + Range, CS_Scr_Res.g / 2 + Range, CS_Scr_Res.r / 2 + Range + Length, CS_Scr_Res.g / 2 + Range + Length, Mark_Color, Width);
					ESP_Paint.Render_Line(CS_Scr_Res.r / 2 + Range, CS_Scr_Res.g / 2 - Range, CS_Scr_Res.r / 2 + Range + Length, CS_Scr_Res.g / 2 - Range - Length, Mark_Color, Width);
					ESP_Paint.Render_Line(CS_Scr_Res.r / 2 - Range, CS_Scr_Res.g / 2 + Range, CS_Scr_Res.r / 2 - Range - Length, CS_Scr_Res.g / 2 + Range + Length, Mark_Color, Width);
					if (UI_Visual_HitMark_Damage)ESP_Paint.Render_String(CS_Scr_Res.r / 2 - 5, CS_Scr_Res.g / 2 + Range + 10, to_string(Mark_DMG), "Small Fonts", 11, Mark_Color, false);
				}
			}
			if (UI_Misc_SniperCrosshair && Global_LocalPlayer.ActiveWeapon(true) == 3 && !Global_LocalPlayer.Scoped()) { ESP_Paint.RenderA_GradientCircle(CS_Scr_Res.r / 2, CS_Scr_Res.g / 2, UI_Misc_SniperCrosshair_Size, GUI_IO.GUIColor.D_Alpha(150), { 0,0,0,0 }); }//狙击枪准星
			if (Menu_Open)Sleep(5);//菜单打开时降低绘制速度以降低CPU使用率
		}
		else Sleep(20);
		ESP_Paint.DrawPaint();
	}
}
void Thread_Funtion_EntityESP() noexcept//功能线程: 实体透视
{
	System::Log("Load Thread: Thread_Funtion_EntityESP()");
	Window::Windows RenderWindow; Window::Render WEP_Render;
	const auto Render_Window_HWND = RenderWindow.Create_RenderBlock(Window::Get_Resolution().x, Window::Get_Resolution().y, "Rensen - EntityESP");
	RenderWindow.Set_WindowAttributes({ 0,0,0 });//窗口过滤颜色和透明度
	WEP_Render.CreatePaint(Render_Window_HWND, 0, 0, Window::Get_Resolution().x, Window::Get_Resolution().y);
	while (true)
	{
		Sleep(UI_Visual_ESP_RenderSleep);
		RenderWindow.Set_WindowTitle(System::Rand_String(10));//随机实体透视窗口标题
		const auto CS_Scr_Res = Window::Get_WindowResolution(CS2_HWND);
		WEP_Render.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });//刷新绘制画板
		if (CS2_HWND && UI_Visual_ESP && (UI_Visual_ESP_Key == 0 || System::Get_Key(UI_Visual_ESP_Key)) && UI_Visual_ESP_Drops && (Menu_Open || Global_IsShowWindow) && Global_LocalPlayer.Health())//当CS窗口在最前端 && 本地人物活着
		{
			if (Menu_Open)Sleep(50);//节省CPU性能 (可有可无)
			auto Draw_Color = GUI_IO.GUIColor;
			if (UI_Visual_ESP_CustomColor)Draw_Color = UI_Visual_ESP_CustomColor_Color;
			MoveWindow(Render_Window_HWND, CS_Scr_Res.b, CS_Scr_Res.a, CS_Scr_Res.r, CS_Scr_Res.g, TRUE);//Pos & Size
			const auto Entitylist = Base::EntityList(); const auto Local_Origin = Global_LocalPlayer.Origin(); const auto Local_ViewMatrix = Base::ViewMatrix();
			static vector<short> Class_ID = {};//有效实体ID
			if (System::Get_Key(0x47) || System::Sleep_Tick<class CLASS_Drops_ESP_Reload_ClassID_>(500))//特殊算法为了提高绘制效率
			{
				short Show_Quantity = 0;//计算绘制的实体数量
				Class_ID = {};//刷新有效实体ID
				for (short i = 65; i <= 1024; ++i)//class id 65-1024
				{
					if (Show_Quantity > 40)continue;//限制数量
					const Base::PlayerPawn Entity = Base::Convert(Entitylist, i);
					if (!Entity.Pawn())continue;
					const auto Entity_Pos = Entity.Origin();
					if (Entity_Pos.x == 0 || Entity_Pos.y == 0 || Variable::Coor_Dis_3D(Local_Origin, Entity_Pos) > 2000)continue;//实体之间距离检测
					const auto Entity_ScrPos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, Entity.Origin(), Local_ViewMatrix);
					if (Entity_ScrPos.x < -300 || Entity_ScrPos.x > CS_Scr_Res.r + 300)continue;//检测实体是否在屏幕内
					if (Entity.ActiveWeaponName(true, Entity.Pawn()) == "NONE" && !Variable::String_Find(Entity.EntityName(), "_projectile"))continue;//检测实体名称是否有效
					if (Entity.EntityName() == "hegrenade_projectile" && !System::Get_ValueChangeState<float, class CLASS_Drops_ESP_Delete_StopedEntity_>(Entity_Pos.x))continue;//排除手雷缓存 (受累爆炸后不在移动时就是留下的缓存)
					Class_ID.push_back(i); ++Show_Quantity;//计算有效实体数量
					System::Sleep_ns(20);//降低CPU占用
				}
			}
			if (Class_ID.size() > 0)
			{
				for (short i = 0; i < Class_ID.size(); ++i)//只遍历有效实体
				{
					const Base::PlayerPawn Entity = Base::Convert(Entitylist, Class_ID[i]);
					const auto Entity_Pos = Entity.Origin();
					if (Entity_Pos.x == 0 || Entity_Pos.y == 0)continue;//过滤掉无效坐标
					const auto Entity_ScrPos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, Entity_Pos, Local_ViewMatrix);
					auto Entity_Name = Entity.EntityName();
					if (Variable::String_Find(Entity_Name, "_projectile"))//飞行的道具绘制
					{
						Entity_Name.erase(Entity_Name.length() - 11, 11);//删除_projectile
						Entity_Name = Variable::String_Upper(Entity_Name);//转换大写
						if (Entity_Name == "SMOKEGRENADE")//烟雾弹范围绘制
						{
							Entity_Name = "SMOKE";
							const auto Pos_1 = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, { Entity_Pos.x - (float)floor(sin(System::Tick() / 1000.f) * 180),Entity_Pos.y - (float)floor(cos(System::Tick() / 1000.f) * 180), Entity_Pos.z }, Local_ViewMatrix);
							const auto Pos_2 = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, { Entity_Pos.x + (float)floor(sin(System::Tick() / 1000.f) * 180),Entity_Pos.y + (float)floor(cos(System::Tick() / 1000.f) * 180), Entity_Pos.z }, Local_ViewMatrix);
							const auto Pos_3 = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, { Entity_Pos.x + (float)floor(cos(System::Tick() / 1000.f) * 180),Entity_Pos.y - (float)floor(sin(System::Tick() / 1000.f) * 180), Entity_Pos.z }, Local_ViewMatrix);
							const auto Pos_4 = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, { Entity_Pos.x - (float)floor(cos(System::Tick() / 1000.f) * 180),Entity_Pos.y + (float)floor(sin(System::Tick() / 1000.f) * 180), Entity_Pos.z }, Local_ViewMatrix);
							WEP_Render.Render_Line(Pos_1.x, Pos_1.y, Pos_2.x, Pos_2.y, Draw_Color);
							WEP_Render.Render_Line(Pos_3.x, Pos_3.y, Pos_4.x, Pos_4.y, Draw_Color);
						}
						else if (Entity_Name == "FLASHBANG")Entity_Name = "FLASH";//过滤字符串
						WEP_Render.RenderA_GradientCircle(Entity_ScrPos.x, Entity_ScrPos.y, 15, { 1,1,1 }, Draw_Color, floor(sin((float)System::Tick() / 150) * 40 + 40) / 100 - 0.2);
						WEP_Render.Render_SmpStr(Entity_ScrPos.x - 13, Entity_ScrPos.y, Entity_Name, { 200,200,200 }, { 1,1,1 });
					}
					else WEP_Render.Render_SmpStr(Entity_ScrPos.x - 15, Entity_ScrPos.y, Entity.ActiveWeaponName(true, Entity.Pawn()), { 200,200,200 }, { 1,1,1 });//武器绘制
				}
			}
			else Sleep(100);
		}
		else { MoveWindow(Render_Window_HWND, 0, 0, 0, 0, TRUE); Sleep(20); }
		WEP_Render.DrawPaint(true);
	}
}
void Thread_Funtion_Radar() noexcept//功能线程: 雷达
{
	System::Log("Load Thread: Thread_Funtion_Radar()");
	Window::Windows Radar_Window; const auto RadarRenderWindow = Radar_Window.Create_Window(UI_Visual_Radar_Size, UI_Visual_Radar_Size + 15, "Rensen - Radar", true);//创建雷达绘制窗口
	Window::Render Radar_Paint; Radar_Paint.CreatePaint(RadarRenderWindow, 0, 0, 500, 500 + 15);//创建绘制画板
	Radar_Window.Set_WindowPos(UI_Visual_Radar_Pos.x, UI_Visual_Radar_Pos.y);//套用参数的雷达位置
	while (true)
	{
		Sleep(10);//降低CPU占用
		Radar_Window.Set_WindowTitle(System::Rand_String(10));//随机雷达窗口标题
		static short Radar_Size_; const short RadarSizeAnimation = Variable::Animation<class Class_Radar_Window_Size>(Radar_Size_, 2.5);
		if ((Global_IsShowWindow || Menu_Open || Window::Get_WindowEnable(Radar_Window.Get_HWND())) && UI_Visual_Radar)//当CS窗口在最前端
		{
			Radar_Size_ = UI_Visual_Radar_Size; UI_Visual_Radar_Pos = Radar_Window.Get_WindowPos();
			if (!Radar_Window.Window_Move(15))//移动雷达窗口
			{
				const float RadarRangeAnimation = Variable::Animation<class Class_Radar_Window_Range>(UI_Visual_Radar_Range, 2.5);//窗口动画
				const auto LocalPlayerPos = Global_LocalPlayer.Origin(); const auto ViewAngle = Base::ViewAngles();
				Radar_Paint.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });//背景
				if (UI_Visual_Radar_FollowAngle)Radar_Paint.Render_GradientTriangle({ RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15 ,(int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 135, 0)[0], (int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 135, 0)[1] ,(int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 225, 0)[0], (int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 225, 0)[1] }, GUI_IO.GUIColor / 4, { 0,0,0 }, { 0,0,0 });
				else Radar_Paint.Render_GradientTriangle({ RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15 ,(int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngle.y, 45)[0], (int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngle.y, 45)[1] ,(int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngle.y, 135)[0], (int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngle.y, 135)[1] }, GUI_IO.GUIColor / 4, { 0,0,0 }, { 0,0,0 });//本地人物视野
				Radar_Paint.Render_HollowCircle(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 100 * 3.5, { 255,255,255 }, 2);//自身圆圈
				for (short i = 0; i < Global_ValidClassID.size(); ++i)
				{
					const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);
					if (!Advanced::Check_Enemy(PlayerPawn))continue;//多点检测
					const auto EntityPos = PlayerPawn.Origin();
					static vector<float> 敌人屏幕坐标;
					if (UI_Visual_Radar_FollowAngle)敌人屏幕坐标 = { RadarSizeAnimation / 2 - Variable::Ang_Pos(Variable::Coor_Dis_2D(LocalPlayerPos, EntityPos), ViewAngle.y - 90 + atan2((LocalPlayerPos.x - EntityPos.x), (LocalPlayerPos.y - EntityPos.y)) * (180 / acos(-1)))[0] / RadarRangeAnimation,RadarSizeAnimation / 2 + 15 + Variable::Ang_Pos(Variable::Coor_Dis_2D(LocalPlayerPos, EntityPos), ViewAngle.y - 90 + atan2((LocalPlayerPos.x - EntityPos.x), (LocalPlayerPos.y - EntityPos.y)) * (180 / acos(-1)))[1] / RadarRangeAnimation };
					else 敌人屏幕坐标 = { RadarSizeAnimation / 2 - (LocalPlayerPos.x - EntityPos.x) / RadarRangeAnimation,RadarSizeAnimation / 2 + 15 + (LocalPlayerPos.y - EntityPos.y) / RadarRangeAnimation };
					if (敌人屏幕坐标[0] > RadarSizeAnimation)敌人屏幕坐标[0] = RadarSizeAnimation;//边缘限制 (无法离开绘制区域)
					else if (敌人屏幕坐标[0] < 0) 敌人屏幕坐标[0] = 0;
					if (敌人屏幕坐标[1] > RadarSizeAnimation + 15)敌人屏幕坐标[1] = RadarSizeAnimation + 15;
					else if (敌人屏幕坐标[1] < 15)敌人屏幕坐标[1] = 15;
					if (PlayerPawn.Spotted())Radar_Paint.Render_SolidCircle(敌人屏幕坐标[0], 敌人屏幕坐标[1], RadarSizeAnimation / 100 * 3.5, GUI_IO.GUIColor, GUI_IO.GUIColor);//敌人圆圈
					else Radar_Paint.Render_HollowCircle(敌人屏幕坐标[0], 敌人屏幕坐标[1], RadarSizeAnimation / 100 * 3.5, GUI_IO.GUIColor);
				}
				Radar_Paint.Render_GradientRect(0, 0, Radar_Window.Get_WindowSize().x, 14, GUI_IO.GUIColor / 2, GUI_IO.GUIColor / 4, false);
				Radar_Paint.Render_GradientRect(0, 14, Radar_Window.Get_WindowSize().x, 1, GUI_IO.GUIColor / 4, GUI_IO.GUIColor / 2, false);//标题背景
				Radar_Paint.Render_String(3 + 1, 1 + 1, "Rensen - Radar", "Small Fonts", 12, { 0,0,0 }, false);//标题阴影
				Radar_Paint.Render_String(3, 1, "Rensen - Radar", "Small Fonts", 12, GUI_IO.GUIColor, false);//标题
				Radar_Paint.DrawPaint();//最终绘制雷达画板
			}
		}
		else Radar_Size_ = 0;
		Radar_Window.Set_WindowSize(RadarSizeAnimation, RadarSizeAnimation + 15);
		Radar_Window.Set_WindowAlpha(Variable::Animation<class Class_Radar_Window_Alpha>(UI_Visual_Radar_Alpha, 2.5));
	}
}
void Thread_Funtion_Sonar() noexcept//功能线程: 声呐(距离检测)
{
	System::Log("Load Thread: Thread_Funtion_Sonar()");
	while (true)
	{
		Sleep(1);
		if (Global_IsShowWindow && UI_Misc_Sonar && (UI_Misc_Sonar_Key == 0 || System::Get_Key(UI_Misc_Sonar_Key)) && Global_LocalPlayer.Health())//当CS窗口在最前端 && 本地人物活着
		{
			const auto Local_Pos = Global_LocalPlayer.Origin();//本地人物坐标
			for (short i = 0; i <= 64; ++i)
			{
				System::Sleep_ns(150);
				if (UI_Misc_Sonar_Key != 0 && !System::Get_Key(UI_Misc_Sonar_Key))continue;//提高效率
				const auto PlayerPawn = Advanced::Traverse_Player(i);
				if (!Advanced::Check_Enemy(PlayerPawn))continue;//多点检测
				const auto Pos_Dis = Variable::Coor_Dis_2D(Local_Pos, PlayerPawn.Origin());//敌人坐标距离
				if (Pos_Dis <= UI_Misc_Sonar_Range_Near)Beep(300, 20);//Near range 近距离
				else if (Pos_Dis <= UI_Misc_Sonar_Range_Far)Beep(150, 20);//Far range 远距离
				if (Pos_Dis <= UI_Misc_Sonar_Range_Far)Sleep(20);//断开间隔
			}
		}
		else Sleep(20);
	}
}
int main() noexcept//主线程 (加载多线程, 一些杂项功能)
{
	System::Anti_Debugger("Debugging is disabled after compilation is completed.");//防止逆向破解
	BOOL Attest = false;//认证变量
	System::URL_READ UserID_READ = { "Cache_UserID" };
	if (UserID_READ.StoreMem("https://github.com/Coslly/Misc/raw/main/About%20Rensen/UserID.uid?raw=true"))//Github读取有效用户ID
	{
		const auto Local_UserName = System::Get_UserName();
		if (Local_UserName == "22684" || Local_UserName == "SAMSUNG") { System::Log("Certification: Whitelist passed"); Attest = true; }//白名单过滤
		for (short i = 0; i <= 500; i++) { if (Local_UserName == UserID_READ.Read(i) || Variable::String_Upper(Local_UserName) == "BYPASS")Attest = true; }//修改认证
		UserID_READ.Release();//释放缓存
	}
	if (Attest == false) { Window::Message_Box("Rensen - " + System::Get_UserName(), "Your identity cannot be passed.", MB_ICONSTOP); exit(0); }//未被认证则直接退出
	//----------------------------------------------------------------------------------------------------------------------------------
	Beep(100, 50);//开启音效
	System::Anti_click();//控制台不被暂停
	Window::Hide_ConsoleWindow();//隐藏控制台
	system("cls");//清空控制台
	printf("Welcome to Rensen for Counter-Strike 2 cheat.\nThe Rensen project is a version converted from FreeCS.\nNo team author By: https://github.com/Coslly\nThe following information returned is debugging information.\n");//作者留言
	System::Log("Load Thread: main()");
	Sleep(200);//修复重启进程冲突
	if (!System::Judge_File(UI_LocalConfigPath)) { System::Create_File(UI_LocalConfigPath, UI_DefaultConfig); System::Self_Restart(); }//创建默认参数文件 (当未找到参数文件时)
	thread Thread_Menu_ = thread(Thread_Menu);
	thread Thread_Misc_ = thread(Thread_Misc);
	Sleep(50);//防止重启卡线程 (以下为功能函数线程)
	thread Thread_Funtion_Aimbot_ = thread(Thread_Funtion_Aimbot);
	thread Thread_Funtion_AdaptiveAimbot_ = thread(Thread_Funtion_AdaptiveAimbot);
	thread Thread_Funtion_Triggerbot_ = thread(Thread_Funtion_Triggerbot);
	thread Thread_Funtion_AssisteAim_ = thread(Thread_Funtion_AssisteAim);
	thread Thread_Funtion_RemoveRecoil_ = thread(Thread_Funtion_RemoveRecoil);
	thread Thread_Funtion_PlayerESP_ = thread(Thread_Funtion_PlayerESP);
	thread Thread_Funtion_EntityESP_ = thread(Thread_Funtion_EntityESP);
	thread Thread_Funtion_Radar_ = thread(Thread_Funtion_Radar);
	thread Thread_Funtion_Sonar_ = thread(Thread_Funtion_Sonar);
	while (true)//菜单动画和关闭快捷键
	{
		if (System::Get_Key(VK_INSERT) && System::Get_Key(VK_DELETE)) { Beep(100, 30); Window::NVIDIA_Overlay(); exit(0); }//快速关闭键 (防止卡线程)
		static short MenuWindowAlpha = 0;
		if (Menu_Open)MenuWindowAlpha = MenuWindowAlpha + UI_Setting_Menu_MainColor.a / UI_Setting_Menu_MenuAnimation / 2;//窗体透明度动画
		else MenuWindowAlpha = MenuWindowAlpha - UI_Setting_Menu_MainColor.a / UI_Setting_Menu_MenuAnimation / 2;
		if (MenuWindowAlpha >= UI_Setting_Menu_MainColor.a)MenuWindowAlpha = UI_Setting_Menu_MainColor.a;
		else if (MenuWindowAlpha <= 0)MenuWindowAlpha = 0;
		GUI_VAR.Window_SetAlpha(MenuWindowAlpha);//修改菜单透明度
		if (!System::Key_Toggle<class CLASS_Main_Rensen_MenuKey>(UI_Setting_Menu_MenuKey)) { GUI_VAR.Window_Show(); Menu_Open = true; }
		else { if (MenuWindowAlpha == 0)GUI_VAR.Window_Hide(); Menu_Open = false; }
		GUI_IO = GUI_VAR.Get_IO();//刷新GUI状态数据
		if (!UI_Setting_Menu_CustomColor)GUI_IO.GUIColor = { GUI_IO.GUIColor_Rainbow[3],GUI_IO.GUIColor_Rainbow[4],GUI_IO.GUIColor_Rainbow[5] };//GUI主题颜色到功能函数
		Sleep(1);
	}
}