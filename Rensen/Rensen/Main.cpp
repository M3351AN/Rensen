#include "Head.h"
#include "CS2_SDK.h"
const string Rensen_ReleaseDate = "[2024-02-04 00:00]";//程序发布日期
const float Rensen_Version = 2.83;//程序版本
namespace Config_Var//套用到菜单的调试变量(例如功能开关)
{
	EasyGUI::EasyGUI GUI_VAR; EasyGUI::EasyGUI_IO GUI_IO; BOOL Menu_Open = true;//初始化变量
	const string UI_LocalConfigPath = "Rensen.cfg";
	const string UI_DefaultConfig = "1\n6\n1\n1\n0\n1\n1\n100\n1\n1\n0\n100\n0\n0\n100\n0\n1\n100\n5\n1\n5\n0\n1\n150\n1\n0.015\n0.004\n1\n1\n2\n1\n250\n1\n0\n0\n1\n1\n0\n1\n0\n1\n1\n1\n1\n40\n80\n0\n255\n255\n255\n255\n1\n1\n1\n4\n260\n180\n26\n11\n1\n1\n1000\n10\n1\n1\n5\n5\n1\n1\n0\n0\n1\n1\n1\n0\n0\n1\n160\n800\n350\n0\n45\n0\n200\n200\n255\n250\n200\n200\n255\n2\n";//默认参数
	//----------------------------------------------------------------------------------------------
	BOOL UI_Visual_Res_3840;
	BOOL UI_Visual_Res_2560;
	BOOL UI_Visual_Res_1920;
	BOOL UI_Visual_Res_1440;
	BOOL UI_Visual_Res_1280;
	BOOL UI_Visual_Res_960;
	BOOL UI_Visual_Res_800;
	BOOL UI_Misc_ClearDebugWindow;
	BOOL UI_Misc_LoadCloudConfig;
	BOOL UI_Setting_Menu_OPENLINKAuthor;
	BOOL UI_Setting_Menu_SaveLocalConfig;
	BOOL UI_Setting_Menu_StartCS;
	BOOL UI_Setting_Menu_QuitCS;
	BOOL UI_Setting_Menu_RestartMenu;
	BOOL UI_Setting_Menu_Close;
	//以上为按钮变量---------------------------------------------------------------------------------
	BOOL UI_Legit_Aimbot = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 1));
	int UI_Legit_Aimbot_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 2));
	BOOL UI_Legit_Aimbot_JudgingWall = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 3));
	BOOL UI_Legit_Aimbot_RemoveRecoil = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 4));
	BOOL UI_Legit_Aimbot_TriggerOnAim = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 5));
	BOOL UI_Legit_Aimbot_AutoShoot = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 6));
	BOOL UI_Legit_Aimbot_AutoStop = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 7));
	int UI_Legit_Aimbot_AutoShootDelay = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 8));
	BOOL UI_Legit_Aimbot_AdaptiveAimbot = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 9));
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
	BOOL UI_Misc_HitMark = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 64));
	BOOL UI_Misc_HitMark_Damage = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 65));
	int UI_Misc_HitMark_Range = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 66));
	int UI_Misc_HitMark_Length = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 67));
	BOOL UI_Misc_AutoKnife = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 68));
	BOOL UI_Misc_AutoTaser = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 69));
	int UI_Misc_AutoKnife_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 70));
	int UI_Misc_AutoTaser_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 71));
	BOOL UI_Misc_Watermark = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 72));
	BOOL UI_Misc_SniperCrosshair = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 73));
	BOOL UI_Misc_TeamCheck = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 74));
	BOOL UI_Misc_LockGameWindow = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 75));
	BOOL UI_Misc_ShowDebugWindow = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 76));
	BOOL UI_Misc_Sonar = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 77));
	int UI_Misc_Sonar_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 78));
	int UI_Misc_Sonar_Range_Far = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 79));
	int UI_Misc_Sonar_Range_Near = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 80));
	int UI_Misc_SelectedConfig = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 81));
	int UI_Setting_Menu_MenuKey = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 82));
	BOOL UI_Setting_Menu_CustomColor = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 83));
	Variable::Vector4 UI_Setting_Menu_MainColor = { Variable::string_int_(System::Get_File(UI_LocalConfigPath, 84)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 85)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 86)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 87)) };
	Variable::Vector4 UI_Misc_HitMark_Color = { Variable::string_int_(System::Get_File(UI_LocalConfigPath, 88)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 89)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 90)) };
	int UI_Misc_HitMark_Width = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 91));
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
			to_string(UI_Legit_Aimbot_AdaptiveAimbot) + "\n" +
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
			to_string(UI_Misc_HitMark) + "\n" +
			to_string(UI_Misc_HitMark_Damage) + "\n" +
			to_string(UI_Misc_HitMark_Range) + "\n" +
			to_string(UI_Misc_HitMark_Length) + "\n" +
			to_string(UI_Misc_AutoKnife) + "\n" +
			to_string(UI_Misc_AutoTaser) + "\n" +
			to_string(UI_Misc_AutoKnife_Key) + "\n" +
			to_string(UI_Misc_AutoTaser_Key) + "\n" +
			to_string(UI_Misc_Watermark) + "\n" +
			to_string(UI_Misc_SniperCrosshair) + "\n" +
			to_string(UI_Misc_TeamCheck) + "\n" +
			to_string(UI_Misc_LockGameWindow) + "\n" +
			to_string(UI_Misc_ShowDebugWindow) + "\n" +
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
			to_string(UI_Misc_HitMark_Color.r) + "\n" +
			to_string(UI_Misc_HitMark_Color.g) + "\n" +
			to_string(UI_Misc_HitMark_Color.b) + "\n" +
			to_string(UI_Misc_HitMark_Width) + "\n"
		);
	}
	void LoadCloudConfig(string FileName) noexcept//加载Github云参数
	{
		System::URL_READ URL_CONFIG = { "CloudConfig" };
		if (URL_CONFIG.StoreMem("https://github.com/Coslly/Misc/raw/main/About%20Rensen/" + FileName + (string)".cfg?raw=true"))
		{
			UI_Legit_Aimbot = Variable::string_int_(URL_CONFIG.Read(1));
			UI_Legit_Aimbot_Key = Variable::string_int_(URL_CONFIG.Read(2));
			UI_Legit_Aimbot_JudgingWall = Variable::string_int_(URL_CONFIG.Read(3));
			UI_Legit_Aimbot_RemoveRecoil = Variable::string_int_(URL_CONFIG.Read(4));
			UI_Legit_Aimbot_TriggerOnAim = Variable::string_int_(URL_CONFIG.Read(5));
			UI_Legit_Aimbot_AutoShoot = Variable::string_int_(URL_CONFIG.Read(6));
			UI_Legit_Aimbot_AutoStop = Variable::string_int_(URL_CONFIG.Read(7));
			UI_Legit_Aimbot_AutoShootDelay = Variable::string_int_(URL_CONFIG.Read(8));
			UI_Legit_Aimbot_AdaptiveAimbot = Variable::string_int_(URL_CONFIG.Read(9));
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
			UI_Misc_HitMark = Variable::string_int_(URL_CONFIG.Read(64));
			UI_Misc_HitMark_Damage = Variable::string_int_(URL_CONFIG.Read(65));
			UI_Misc_HitMark_Range = Variable::string_int_(URL_CONFIG.Read(66));
			UI_Misc_HitMark_Length = Variable::string_int_(URL_CONFIG.Read(67));
			UI_Misc_AutoKnife = Variable::string_int_(URL_CONFIG.Read(68));
			UI_Misc_AutoTaser = Variable::string_int_(URL_CONFIG.Read(69));
			UI_Misc_AutoKnife_Key = Variable::string_int_(URL_CONFIG.Read(70));
			UI_Misc_AutoTaser_Key = Variable::string_int_(URL_CONFIG.Read(71));
			UI_Misc_Watermark = Variable::string_int_(URL_CONFIG.Read(72));
			UI_Misc_SniperCrosshair = Variable::string_int_(URL_CONFIG.Read(73));
			UI_Misc_TeamCheck = Variable::string_int_(URL_CONFIG.Read(74));
			UI_Misc_LockGameWindow = Variable::string_int_(URL_CONFIG.Read(75));
			UI_Misc_ShowDebugWindow = Variable::string_int_(URL_CONFIG.Read(76));
			UI_Misc_Sonar = Variable::string_int_(URL_CONFIG.Read(77));
			UI_Misc_Sonar_Key = Variable::string_int_(URL_CONFIG.Read(78));
			UI_Misc_Sonar_Range_Far = Variable::string_int_(URL_CONFIG.Read(79));
			UI_Misc_Sonar_Range_Near = Variable::string_int_(URL_CONFIG.Read(80));
			UI_Misc_SelectedConfig = Variable::string_int_(URL_CONFIG.Read(81));
			UI_Setting_Menu_MenuKey = Variable::string_int_(URL_CONFIG.Read(82));
			UI_Setting_Menu_CustomColor = Variable::string_int_(URL_CONFIG.Read(83));
			UI_Setting_Menu_MainColor = { Variable::string_int_(URL_CONFIG.Read(84)),Variable::string_int_(URL_CONFIG.Read(85)),Variable::string_int_(URL_CONFIG.Read(86)),Variable::string_int_(URL_CONFIG.Read(87)) };
			UI_Misc_HitMark_Color = { Variable::string_int_(URL_CONFIG.Read(88)) ,Variable::string_int_(URL_CONFIG.Read(89)) ,Variable::string_int_(URL_CONFIG.Read(90)) };
			UI_Misc_HitMark_Width = Variable::string_int_(URL_CONFIG.Read(91));
			URL_CONFIG.Release();
		}
	}
}
using namespace Config_Var;
void Thread_Menu() noexcept//菜单线程 (提供给使用者丰富的自定义选项)
{
	System::Log("Load Thread: Thread_Menu()");
	GUI_VAR.Window_Create(1010, 700, System::Rand_String(10), true);//创建置顶GUI绘制窗口
	while (true)
	{
		static int UI_Panel = 0;//大区块选择
		static vector<int> UI_WindowSize = { 0 ,0 };//窗体大小(用于开关动画)
		if (!Menu_Open)UI_WindowSize = { 0,0 };//关闭窗体时
		GUI_VAR.Window_SetSize({ (int)Variable::Animation<class Menu_Open_Animation_X>(UI_WindowSize[0],2.5),(int)Variable::Animation<class Menu_Open_Animation_Y>(UI_WindowSize[1],2.5) });//窗口大小动画
		if (!GUI_VAR.Window_Move() && Menu_Open)//不在移动窗口时绘制GUI
		{
			if (UI_Setting_Menu_CustomColor)//自定义颜色(单色)
			{
				GUI_VAR.Global_Set_EasyGUI_Color(UI_Setting_Menu_MainColor);//设置主题颜色
				GUI_VAR.GUI_BackGround(1369);//自定义颜色背景主题
			}
			else GUI_VAR.GUI_BackGround(1368);//默认(彩虹)
			GUI_VAR.GUI_Block_Panel(20, 20, 100, GUI_VAR.Window_GetSize().y - 40, "", { "Legit","Visual","Misc","Setting","Debug" }, UI_Panel);
			if (UI_Panel == 0)//Legit
			{
				const auto Block_Aimbot = GUI_VAR.GUI_Block(150, 30, 280, "Aim bot");
				GUI_VAR.GUI_Checkbox(Block_Aimbot, 1, "Enabled", UI_Legit_Aimbot);
				GUI_VAR.GUI_KeySelector<class CLASS_Rensen_Menu_1>(Block_Aimbot, 1, UI_Legit_Aimbot_Key);
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 20,Block_Aimbot.y }, 2, "Judging wall", UI_Legit_Aimbot_JudgingWall);
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 20,Block_Aimbot.y }, 3, "Remove recoil", UI_Legit_Aimbot_RemoveRecoil);
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 20,Block_Aimbot.y }, 4, "Trigger on aiming", UI_Legit_Aimbot_TriggerOnAim);
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 20,Block_Aimbot.y }, 5, "Auto shoot", UI_Legit_Aimbot_AutoShoot, { 255,150,150 });
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 40,Block_Aimbot.y }, 6, "Auto stop", UI_Legit_Aimbot_AutoStop, { 255,150,150 });
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_2>({ Block_Aimbot.x + 20,Block_Aimbot.y }, 7, "Auto shoot delay", 0, 500, UI_Legit_Aimbot_AutoShootDelay, "ms", { 255,150,150 });
				GUI_VAR.GUI_Checkbox(Block_Aimbot, 8, "Adaptive aimbot", UI_Legit_Aimbot_AdaptiveAimbot, { 200,200,150 });
				const auto Block_Armory = GUI_VAR.GUI_Block(150, 330, 340, "Armory");
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 1, "Show range", UI_Legit_Armory_ShowAimbotRange);
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 2, "PISTOL Body aim (else head)", UI_Legit_Armory_BodyAim_PISTOL);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_3>({ Block_Armory.x - 10,Block_Armory.y }, 3, "PISTOL range", 0, 100, UI_Legit_Armory_Range_PISTOL, "%");
				GUI_VAR.GUI_Slider<float, class CLASS_Rensen_Menu_4>({ Block_Armory.x - 10,Block_Armory.y }, 4, "PISTOL smooth", 0, 40, UI_Legit_Armory_Smooth_PISTOL);
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 5, "RIFLE Body aim (else head)", UI_Legit_Armory_BodyAim_RIFLE);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_5>({ Block_Armory.x - 10,Block_Armory.y }, 6, "RIFLE range", 0, 100, UI_Legit_Armory_Range_RIFLE, "%");
				GUI_VAR.GUI_Slider<float, class CLASS_Rensen_Menu_6>({ Block_Armory.x - 10,Block_Armory.y }, 7, "RIFLE smooth", 0, 40, UI_Legit_Armory_Smooth_RIFLE);
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 8, "SNIPER Body aim (else head)", UI_Legit_Armory_BodyAim_SNIPER);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_7>({ Block_Armory.x - 10,Block_Armory.y }, 9, "SNIPER range", 0, 100, UI_Legit_Armory_Range_SNIPER, "%");
				GUI_VAR.GUI_Slider<float, class CLASS_Rensen_Menu_8>({ Block_Armory.x - 10,Block_Armory.y }, 10, "SNIPER smooth", 0, 40, UI_Legit_Armory_Smooth_SNIPER);
				const auto Block_Triggerbot = GUI_VAR.GUI_Block(580, 30, 160, "Trigger bot");
				GUI_VAR.GUI_Checkbox(Block_Triggerbot, 1, "Enabled", UI_Legit_Triggerbot);
				GUI_VAR.GUI_KeySelector<class CLASS_Rensen_Menu_9>(Block_Triggerbot, 1, UI_Legit_Triggerbot_Key);
				GUI_VAR.GUI_Checkbox({ Block_Triggerbot.x + 20,Block_Triggerbot.y }, 2, "Any target", UI_Legit_Triggerbot_AnyTarget);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_10>(Block_Triggerbot, 3, "Shoot delay", 1, 500, UI_Legit_Triggerbot_ShootDelay, "ms");
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_11>(Block_Triggerbot, 4, "Shoot duration", 1, 1000, UI_Legit_Triggerbot_ShootDuration, "ms");
				const auto Block_PreciseAim = GUI_VAR.GUI_Block(580, 210, 130, "Precise aim");
				GUI_VAR.GUI_Checkbox(Block_PreciseAim, 1, "Enabled", UI_Legit_PreciseAim);
				GUI_VAR.GUI_Slider<float, class CLASS_Rensen_Menu_12>(Block_PreciseAim, 2, "Default sensitivity", 0, 0.022, UI_Legit_PreciseAim_DefaultSensitivity);
				GUI_VAR.GUI_Slider<float, class CLASS_Rensen_Menu_13>(Block_PreciseAim, 3, "Enable sensitivity", 0, 0.015, UI_Legit_PreciseAim_EnableSensitivity);
				const auto Block_RemoveRecoil = GUI_VAR.GUI_Block(580, 360, 130, "Remove recoil");
				GUI_VAR.GUI_Checkbox(Block_RemoveRecoil, 1, "Enabled", UI_Legit_RemoveRecoil);
				GUI_VAR.GUI_Checkbox({ Block_RemoveRecoil.x + 20,Block_RemoveRecoil.y }, 2, "Lateral repair", UI_Legit_RemoveRecoil_LateralRepair);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_14>(Block_RemoveRecoil, 3, "Start bullet", 1, 10, UI_Legit_RemoveRecoil_StartBullet);
				const auto Block_Backtracking = GUI_VAR.GUI_Block(580, 510, 100, "Back tracking");
				GUI_VAR.GUI_Checkbox(Block_Backtracking, 1, "Enabled", UI_Legit_Backtracking);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_15>(Block_Backtracking, 2, "Maximum time", 0, 500, UI_Legit_Backtracking_Time, "ms");
				GUI_VAR.GUI_Tips(Block_Aimbot, 1, "Help you quickly aim at the target.");
				GUI_VAR.GUI_Tips({ Block_Aimbot.x + 10,Block_Aimbot.y }, 5, "Prefer Ragebot.", { 255,150,150 });
				GUI_VAR.GUI_Tips(Block_Aimbot, 8, "More biological than normal aimbot.", { 200,200,150 });
				GUI_VAR.GUI_Tips(Block_Triggerbot, 1, "Shoot when aiming at the enemy.");
				GUI_VAR.GUI_Tips(Block_PreciseAim, 1, "Reduce the sensitivity of the reticle when aiming at the enemy.");
				GUI_VAR.GUI_Tips({ Block_RemoveRecoil.x + 10,Block_RemoveRecoil.y }, 2, "Operations that only return landscape.");
				GUI_VAR.GUI_Tips(Block_Backtracking, 1, "Take advantage of network latency to have a bigger hitbox.");
				UI_WindowSize = { 1010,700 };
			}
			else if (UI_Panel == 1)//Visual
			{
				const auto Block_ESP = GUI_VAR.GUI_Block(150, 30, 490, "Extra sensory perception");
				GUI_VAR.GUI_Checkbox(Block_ESP, 1, "Enabled", UI_Visual_ESP);
				GUI_VAR.GUI_KeySelector<class CLASS_Rensen_Menu_16>(Block_ESP, 1, UI_Visual_ESP_Key);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 2, "Box", UI_Visual_ESP_Box);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 3, "Health bar", UI_Visual_ESP_Health);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 4, "Weapon text", UI_Visual_ESP_ActiveWeapon);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 5, "Snap line", UI_Visual_ESP_Snapline);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 6, "Skeleton", UI_Visual_ESP_Skeleton);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 7, "Head dot", UI_Visual_ESP_HeadDot);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 8, "State", UI_Visual_ESP_State);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 9, "Name", UI_Visual_ESP_Name);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 10, "Drops", UI_Visual_ESP_Drops);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 11, "Out of FOV arrow", UI_Visual_ESP_OutFOV);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_17>(Block_ESP, 12, "Size", 20, 70, UI_Visual_ESP_OutFOV_Size, "px");
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_18>(Block_ESP, 13, "Radius", 0, 100, UI_Visual_ESP_OutFOV_Radius, "%");
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 14, "Custom color", UI_Visual_ESP_CustomColor);
				GUI_VAR.GUI_ColorSelector(Block_ESP, 14, UI_Visual_ESP_CustomColor_Color);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_19>(Block_ESP, 15, "Draw delay", 1, 20, UI_Visual_ESP_RenderSleep, "ms");
				const auto Block_Resolution = GUI_VAR.GUI_Block(580, 30, 250, "Screen resolution");
				GUI_VAR.GUI_Button(Block_Resolution, 1, "3840 * 2160", UI_Visual_Res_3840, 78);
				GUI_VAR.GUI_Button(Block_Resolution, 2, "2560 * 1440", UI_Visual_Res_2560, 78);
				GUI_VAR.GUI_Button(Block_Resolution, 3, "1920 * 1080", UI_Visual_Res_1920, 78);
				GUI_VAR.GUI_Button(Block_Resolution, 4, "1440 * 1080", UI_Visual_Res_1440, 78);
				GUI_VAR.GUI_Button(Block_Resolution, 5, "1280 * 1024", UI_Visual_Res_1280, 78);
				GUI_VAR.GUI_Button(Block_Resolution, 6, "1280 * 960", UI_Visual_Res_960, 83);
				GUI_VAR.GUI_Button(Block_Resolution, 7, "800 * 600", UI_Visual_Res_800, 87);
				const auto Block_Misc_Radar_ = GUI_VAR.GUI_Block(580, 300, 190, "Radar");
				GUI_VAR.GUI_Checkbox(Block_Misc_Radar_, 1, "Enabled", UI_Visual_Radar);
				GUI_VAR.GUI_Checkbox({ Block_Misc_Radar_.x + 20,Block_Misc_Radar_.y }, 2, "Follow angle", UI_Visual_Radar_FollowAngle);
				GUI_VAR.GUI_Slider<float, class CLASS_Rensen_Menu_20>(Block_Misc_Radar_, 3, "Radar range", 0.2, 25, UI_Visual_Radar_Range);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_21>(Block_Misc_Radar_, 4, "Radar size", 150, 500, UI_Visual_Radar_Size, "px");
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_22>(Block_Misc_Radar_, 5, "Radar alpha", 100, 230, UI_Visual_Radar_Alpha);
				GUI_VAR.GUI_Tips(Block_ESP, 1, "Learn enemy coordinates through walls. (ESP Full screen cannot be used)");
				GUI_VAR.GUI_Tips({ Block_Resolution.x + 10,Block_Resolution.y }, 1, "Flexible switching of window resolution.");
				GUI_VAR.GUI_Tips(Block_Misc_Radar_, 1, "Exterior window radar. (Full screen cannot be used)");
				UI_WindowSize = { 1010,550 };
			}
			else if (UI_Panel == 2)//Misc
			{
				const auto Block_Misc = GUI_VAR.GUI_Block(150, 30, 520, "Misc");
				GUI_VAR.GUI_Checkbox(Block_Misc, 1, "Bunny hop", UI_Misc_BunnyHop);
				GUI_VAR.GUI_Checkbox(Block_Misc, 2, "Hit sound", UI_Misc_HitSound);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_23>(Block_Misc, 3, "Tone", 10, 5000, UI_Misc_HitSound_Tone);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_24>(Block_Misc, 4, "Length", 10, 100, UI_Misc_HitSound_Length);
				GUI_VAR.GUI_Checkbox(Block_Misc, 5, "Hit mark", UI_Misc_HitMark);
				GUI_VAR.GUI_ColorSelector(Block_Misc, 5, UI_Misc_HitMark_Color);
				GUI_VAR.GUI_Checkbox({ Block_Misc.x + 20,Block_Misc.y }, 6, "Show damage", UI_Misc_HitMark_Damage);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_25>(Block_Misc, 7, "Range", 3, 100, UI_Misc_HitMark_Range);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_26>(Block_Misc, 8, "Length", 3, 100, UI_Misc_HitMark_Length);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_27>(Block_Misc, 9, "Width", 1, 10, UI_Misc_HitMark_Width);
				GUI_VAR.GUI_Checkbox(Block_Misc, 10, "Knife bot", UI_Misc_AutoKnife);
				GUI_VAR.GUI_KeySelector<class CLASS_Rensen_Menu_28>(Block_Misc, 10, UI_Misc_AutoKnife_Key);
				GUI_VAR.GUI_Checkbox(Block_Misc, 11, "Taser bot", UI_Misc_AutoTaser);
				GUI_VAR.GUI_KeySelector<class CLASS_Rensen_Menu_29>(Block_Misc, 11, UI_Misc_AutoTaser_Key);
				GUI_VAR.GUI_Checkbox(Block_Misc, 12, "Water mark", UI_Misc_Watermark);
				GUI_VAR.GUI_Checkbox(Block_Misc, 13, "Sniper crosshair", UI_Misc_SniperCrosshair);
				GUI_VAR.GUI_Checkbox(Block_Misc, 14, "Global team check", UI_Misc_TeamCheck, { 200,200,150 });
				GUI_VAR.GUI_Checkbox(Block_Misc, 15, "Lock game window", UI_Misc_LockGameWindow);
				GUI_VAR.GUI_Checkbox(Block_Misc, 16, "Show console window", UI_Misc_ShowDebugWindow);
				GUI_VAR.GUI_Button_Small(Block_Misc, 16, UI_Misc_ClearDebugWindow);
				const auto Block_Sonar = GUI_VAR.GUI_Block(580, 30, 130, "Sonar");
				GUI_VAR.GUI_Checkbox(Block_Sonar, 1, "Enabled", UI_Misc_Sonar);
				GUI_VAR.GUI_KeySelector<class CLASS_Rensen_Menu_30>(Block_Sonar, 1, UI_Misc_Sonar_Key);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_31>(Block_Sonar, 2, "Range far", 500, 1000, UI_Misc_Sonar_Range_Far);
				GUI_VAR.GUI_Slider<int, class CLASS_Rensen_Menu_32>(Block_Sonar, 3, "Range near", 0, 500, UI_Misc_Sonar_Range_Near);
				const auto Block_CloudConfig = GUI_VAR.GUI_Block(580, 180, 330, "Cloud config");
				GUI_VAR.GUI_Button(Block_CloudConfig, 1, "Load config", UI_Misc_LoadCloudConfig, 80);
				GUI_VAR.GUI_List(Block_CloudConfig, 2, { "Legit","Rage","Legit - no visual" }, UI_Misc_SelectedConfig, 10);
				GUI_VAR.GUI_Tips(Block_Misc, 10, "Auto attack when conditions such as distance and blood volume are met.");
				GUI_VAR.GUI_Tips(Block_Misc, 15, "Lock the game window to the front.");
				GUI_VAR.GUI_Tips({ Block_Misc.x + 2,Block_Misc.y }, 16, "Clear console.");
				GUI_VAR.GUI_Tips(Block_Sonar, 1, "Makes a subtle sound when approaching an enemy.");
				GUI_VAR.GUI_Tips({ Block_CloudConfig.x + 10,Block_CloudConfig.y }, 1, "Load parameter files stored in Github.");
				UI_WindowSize = { 1010,580 };
			}
			else if (UI_Panel == 3)//Setting
			{
				const auto Block_About = GUI_VAR.GUI_Block(150, 30, 160, "About");
				GUI_VAR.GUI_Text(Block_About, 1, "Rensen", GUI_VAR.Global_Get_EasyGUI_Color());
				GUI_VAR.GUI_Text({ Block_About.x + 47,Block_About.y }, 1, "for Counter-Strike 2 (External)", { 100,100,100 });
				GUI_VAR.GUI_Text(Block_About, 2, "Version: " + to_string(Rensen_Version), { 100,100,100 });
				GUI_VAR.GUI_Text(Block_About, 3, "Release date: " + Rensen_ReleaseDate, { 100,100,100 });
				GUI_VAR.GUI_Text(Block_About, 4, "Author: https://github.com/Coslly", { 100,100,100 });
				GUI_VAR.GUI_Tips({ Block_About.x + 10,Block_About.y }, 1, "No ban record so far in 2020.", { 150,255,150 });
				GUI_VAR.GUI_Button_Small({ Block_About.x + 10,Block_About.y }, 4, UI_Setting_Menu_OPENLINKAuthor);
				const auto Block_Menu = GUI_VAR.GUI_Block(150, 210, 250, "Menu");
				GUI_VAR.GUI_Text(Block_Menu, 1, "Menu key"); GUI_VAR.GUI_KeySelector<class Rensen_Menu_1>(Block_Menu, 1, UI_Setting_Menu_MenuKey);
				GUI_VAR.GUI_Checkbox(Block_Menu, 2, "Menu color", UI_Setting_Menu_CustomColor);
				GUI_VAR.GUI_ColorSelector_a(Block_Menu, 2, UI_Setting_Menu_MainColor);
				if (UI_Setting_Menu_MainColor.a < 150)UI_Setting_Menu_MainColor.a = 150;//限制透明度
				GUI_VAR.GUI_Button(Block_Menu, 3, "Save local config", UI_Setting_Menu_SaveLocalConfig, 65);
				GUI_VAR.GUI_Button(Block_Menu, 4, "Start CS", UI_Setting_Menu_StartCS, 85);
				GUI_VAR.GUI_Button(Block_Menu, 5, "Quit CS", UI_Setting_Menu_QuitCS, 90);
				GUI_VAR.GUI_Button(Block_Menu, 6, "Restart menu", UI_Setting_Menu_RestartMenu, 75);
				GUI_VAR.GUI_Button(Block_Menu, 7, "Close", UI_Setting_Menu_Close, 95);
				GUI_VAR.GUI_Tips({ Block_Menu.x + 10,Block_Menu.y }, 3, "If you want to reset the default config you can delete Rensen.cfg in the same folder.");
				UI_WindowSize = { 580,490 };
			}
			else if (UI_Panel == 4)//Debug
			{
				const auto Block_PlayerList = GUI_VAR.GUI_Block(150, 30, 490, "Player list", 330);
				static BOOL UI_Debug_PlayerList_ReloadList = false; static vector<string> PlayerNameList = {}; static int SelectPlayer = 0;
				GUI_VAR.GUI_Slider<int, class CLASS_Debug_PlayerID>(Block_PlayerList, 1, "Player ID", 0, 64, SelectPlayer);
				GUI_VAR.GUI_Button_Small({ Block_PlayerList.x + 10,Block_PlayerList.y }, 1, UI_Debug_PlayerList_ReloadList);
				if (UI_Debug_PlayerList_ReloadList) { PlayerNameList = {}; for (short i = 0; i <= 64; ++i)PlayerNameList.push_back(Advanced::Player_Name(i)); System::Log("Debug: ReloadPlayerList"); }//刷新玩家列表页面
				GUI_VAR.GUI_List(Block_PlayerList, 2, PlayerNameList, SelectPlayer, 16);
				GUI_VAR.GUI_Tips({ Block_PlayerList.x + 12,Block_PlayerList.y }, 1, "Reload player list.");
				const auto Block_Info = GUI_VAR.GUI_Block(510, 30, 490, "Info", 330);
				const auto Player_Pawn = Advanced::Traverse_Player(SelectPlayer);
				Variable::Vector4 Debug_PawnColor = { 0,0,0 };//人物数据地址绘制颜色
				if (Player_Pawn.Pawn() == Global_LocalPlayer.Pawn())Debug_PawnColor = { 100,100,255 };//自身
				else if (Player_Pawn.TeamNumber() == Global_LocalPlayer.TeamNumber())Debug_PawnColor = { 0,255,0 };//同队
				else if (Player_Pawn.TeamNumber() != Global_LocalPlayer.TeamNumber())Debug_PawnColor = { 255,0,0 };//不同队
				if (Player_Pawn.Health() == 0)Debug_PawnColor = { 100,100,100 };//无效或是死亡
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 1, "client.dll -> " + to_string(Module_client));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 2, "Pawn: " + to_string(Player_Pawn.Pawn()), Debug_PawnColor);
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
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 13, "ActiveWeapon: " + Player_Pawn.ActiveWeaponName() + "(" + to_string(Player_Pawn.ActiveWeapon()) + ")");
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 14, "Origin: ");
				auto PlayerOrigin = Player_Pawn.Origin(); GUI_VAR.GUI_PosSelector({ Block_Info.x - 100,Block_Info.y }, 14, PlayerOrigin);
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 15, "Angle: ");
				auto PlayerViewAngle = Base::ViewAngles(); GUI_VAR.GUI_PosSelector({ Block_Info.x - 100,Block_Info.y }, 15, PlayerViewAngle);
				GUI_VAR.GUI_Tips({ Block_Info.x + 3,Block_Info.y }, 1, "Cloud offsets date: [" + CS2_Offsets::Offsets_Date + "]");
				UI_WindowSize = { 870,550 };
			}
			GUI_VAR.Draw_GUI();//最终绘制GUI画板
			if (true)//按钮事件接收
			{
				if (UI_Visual_Res_3840)Window::Set_Resolution(3840, 2160);//设置显示器像素
				else if (UI_Visual_Res_2560)Window::Set_Resolution(2560, 1440);
				else if (UI_Visual_Res_1920)Window::Set_Resolution(1920, 1080);
				else if (UI_Visual_Res_1440)Window::Set_Resolution(1440, 1080);
				else if (UI_Visual_Res_1280)Window::Set_Resolution(1280, 1024);
				else if (UI_Visual_Res_960)Window::Set_Resolution(1280, 960);
				else if (UI_Visual_Res_800)Window::Set_Resolution(800, 600);
				if (UI_Misc_ClearDebugWindow)system("cls");//清除控制台
				if (UI_Misc_LoadCloudConfig)//加载Github上的云参数
				{
					const auto Config_ID = UI_Misc_SelectedConfig;
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
				if (UI_Setting_Menu_Close)//关闭菜单
				{
					Window::NVIDIA_Overlay();
					System::Log("Setting: Close");
					exit(0);
				}
			}
		}
	}
}
void Thread_Misc() noexcept//杂项线程 (一些菜单事件处理和杂项功能)
{
	System::Log("Load Thread: Thread_Misc()");
	Window::Windows Window_Watermark; const auto Window_Watermark_HWND = Window_Watermark.Create_RenderBlock_Alpha(Window::Get_Resolution().x, 50, System::Rand_String(11));//创建水印透明窗口
	Window::Render Window_Watermark_Render; Window_Watermark_Render.CreatePaint(Window_Watermark_HWND, 0, 0, Window::Get_Resolution().x, 50);
	ReLoad(true);//刷新CS2_SDK内存数据 (初始化)
	while (true)
	{
		ReLoad();//刷新CS2_SDK内存数据
		Global_TeamCheck = UI_Misc_TeamCheck;//队伍判断(文件跨越修改变量)
		if (UI_Misc_LockGameWindow && !Menu_Open)SetForegroundWindow(CS2_HWND);//锁定CS窗口到最前端
		if (UI_Misc_ShowDebugWindow)ShowWindow(GetConsoleWindow(), true);//显示控制台
		else ShowWindow(GetConsoleWindow(), false);//隐藏控制台
		if (UI_Misc_Watermark)//水印
		{
			Window_Watermark.Set_WindowPos(0, 0);
			if (System::Sleep_Tick<class WaterMark_Window_Sleep_Class_>(200))//降低CPU占用
			{
				static string WaterMark_String = "";
				short WaterMark_String_Size = strlen(WaterMark_String.c_str()) * 4.8;
				if (!CS2_HWND)WaterMark_String = "Rensen | CS not found | " + System::Time_String();
				else { WaterMark_String = "Rensen | " + System::Time_String(); WaterMark_String_Size = strlen(WaterMark_String.c_str()) * 5.2; }
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
		else Window_Watermark.Set_WindowPos(9999, 9999);
		if (Global_IsShowWindow && Global_LocalPlayer.Health())//一些杂项功能
		{
			const auto Local_Pos = Global_LocalPlayer.Origin();//本地人物坐标
			const auto Local_ActiveWeaponID = Global_LocalPlayer.ActiveWeapon();//本地人物手持武器ID
			//--------------------------------------
			if (UI_Misc_BunnyHop && System::Get_Key(VK_SPACE) && Global_LocalPlayer.Flags() & (1 << 0))//连跳
			{//开关 & 按下空格 & 当本地人物触及到地面
				Send_CMD("+jump");//跳跃
				Sleep(1);
				Send_CMD("-jump");
			}
			//--------------------------------------
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
			//--------------------------------------
			if (UI_Misc_AutoKnife && (UI_Misc_AutoKnife_Key == 0 || System::Get_Key(UI_Misc_AutoKnife_Key)) && (Local_ActiveWeaponID == 42 || Local_ActiveWeaponID == 59 || Local_ActiveWeaponID >= 500))//自动刀
			{
				for (short i = 0; i < Global_ValidClassID.size(); ++i)
				{
					const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);
					if (!Advanced::Check_Enemy(PlayerPawn))//多点检测
						continue;
					const auto Player_Pos = PlayerPawn.Origin();//敌人坐标
					const auto Angle = Variable::CalculateAngle(Local_Pos + Global_LocalPlayer.ViewOffset(), PlayerPawn.BonePos(3), Base::ViewAngles());
					if (Variable::Coor_Dis_3D(Local_Pos, Player_Pos) <= 60 && hypot(Angle.x, Angle.y) <= 50)//判断距离
					{
						if (PlayerPawn.Health() <= 55 && PlayerPawn.Health() > 30)//血量判断重刀还是轻刀
						{
							Send_CMD("+attack2");
							Sleep(1);
							Send_CMD("-attack2");
						}
						else {
							Send_CMD("+attack");
							Sleep(1);
							Send_CMD("-attack");
						}
					}
				}
			}
			//--------------------------------------
			if (UI_Misc_AutoTaser && (UI_Misc_AutoTaser_Key == 0 || System::Get_Key(UI_Misc_AutoTaser_Key)) && Local_ActiveWeaponID == 31)//自动电击枪
			{
				for (short i = 0; i < Global_ValidClassID.size(); ++i)
				{
					const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);
					if (!Advanced::Check_Enemy(PlayerPawn))//多点检测
						continue;
					const auto Player_Pos = PlayerPawn.Origin();//敌人坐标
					if (Variable::Coor_Dis_3D(Local_Pos, Player_Pos) <= 150 && PlayerPawn.Pawn() == Global_LocalPlayer.IDEntIndex_Pawn().Pawn())//判断距离 && 瞄准
					{
						Send_CMD("+attack");
						Sleep(1);
						Send_CMD("-attack");
					}
				}
			}
			//--------------------------------------
		}
		Sleep(5);//降低CPU占用
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
			for (short i = 0; i < Global_ValidClassID.size(); ++i)//人物ID遍历
			{
				const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);//遍历的人物Pawn
				if (!Advanced::Check_Enemy(PlayerPawn) || (UI_Legit_Aimbot_TriggerOnAim && !CrosshairId) || (UI_Legit_Aimbot_JudgingWall && !PlayerPawn.Spotted()))
					continue;
				const auto Angle = Variable::CalculateAngle(Global_LocalPlayer.Origin() + Global_LocalPlayer.ViewOffset(), PlayerPawn.BonePos(Aim_Parts), Recoil_Angle);//最终瞄准角度
				const auto FovG = hypot(Angle.x, Angle.y);//圆圈范围计算
				if (!Angle.IsZero() && FovG <= Aim_Range)//范围判断
				{
					Aim_Range = FovG - 2;//防止锁住两个或多个人
					if (Global_LocalPlayer.Scoped())System::Mouse_Move(-Angle.y * Aim_Smooth * 3.5, Angle.x * Aim_Smooth * 3.5);
					else System::Mouse_Move(-Angle.y * Aim_Smooth, Angle.x * Aim_Smooth);
					if (UI_Legit_Aimbot_AutoShoot && CrosshairId && (!UI_Legit_Aimbot_AutoStop || Advanced::Stop_Move()) && FovG <= 0.8)//AutoShoot & AutoStop
					{
						if (LocalPlayer_ActiveWeapon_Type == 3)System::Key_Con(UI_Legit_Aimbot_Key, false);//狙击枪释放
						Send_CMD("+attack");
						if (LocalPlayer_ActiveWeapon_ID == 64)Sleep(250);//R8无法开枪修复
						else Sleep(1);
						Send_CMD("-attack");
						Sleep(UI_Legit_Aimbot_AutoShootDelay);//Auto Shoot Interval
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
		if (Global_IsShowWindow && UI_Legit_Aimbot_AdaptiveAimbot && System::Get_Key(VK_LBUTTON) && Global_LocalPlayer.Health() && Global_LocalPlayer.ActiveWeapon(true) == 2)//当CS窗口在最前端 && 本地人物活着 && 按键按下 && 步枪
		{
			float Aim_Range = 2.5; const auto PunchAngle = Global_LocalPlayer.AimPunchAngle();
			if (abs(PunchAngle.x) * 2 >= Aim_Range)Aim_Range = abs(PunchAngle.x) * 1.5;//计算开枪之后附加后坐力的范围
			for (short i = 0; i < Global_ValidClassID.size(); ++i)//人物ID遍历
			{
				const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);//遍历的人物Pawn
				if (!Advanced::Check_Enemy(PlayerPawn) || !PlayerPawn.Spotted())//当没有被发现则重新来过
					continue;
				const auto Angle = Variable::CalculateAngle(Global_LocalPlayer.Origin() + Global_LocalPlayer.ViewOffset(), PlayerPawn.BonePos(6), Base::ViewAngles() + PunchAngle * 2);//最终瞄准角度 (6: 头部)
				const auto FovG = hypot(Angle.x, Angle.y);//圆圈范围计算
				if (!Angle.IsZero() && FovG <= Aim_Range)//范围判断
				{
					Aim_Range = FovG;//防止锁住两个或多个人
					if (Global_LocalPlayer.ShotsFired() > 1 && (System::Get_Key(VK_CONTROL) || FovG <= 1.5) && PlayerPawn.MoveSpeed() <= 200)System::Mouse_Move(-Angle.y * 30, Angle.x * 30);
					else System::Mouse_Move(-Angle.y * 5, Angle.x * 5);
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
			System::Sleep_ns(600);//纳秒级延时
			const auto Local_ActiveWeaponID = Global_LocalPlayer.ActiveWeapon();//本地人物手持武器ID
			if (Local_ActiveWeaponID == 42 || Local_ActiveWeaponID == 59 || Local_ActiveWeaponID >= 500 || Local_ActiveWeaponID == 31)//过滤特殊武器
				continue;
			else if ((UI_Legit_Triggerbot_AnyTarget && Global_LocalPlayer.IDEntIndex() != -1) || Advanced::Check_Enemy(Global_LocalPlayer.IDEntIndex_Pawn()))//当瞄准的人是敌人
			{
				Send_CMD("+attack");//Shoot!! 开枪!!
				Sleep(UI_Legit_Triggerbot_ShootDuration);
				Send_CMD("-attack");
				Sleep(UI_Legit_Triggerbot_ShootDelay);
			}
		}
		else Sleep(20);
	}
}
void Thread_Funtion_PreciseAim() noexcept//功能线程: 精确瞄准
{
	System::Log("Load Thread: Thread_Funtion_PreciseAim()");
	while (true)
	{
		if (Global_IsShowWindow && UI_Legit_PreciseAim && Global_LocalPlayer.Health())//当CS窗口在最前端 && 本地人物活着
		{
			System::Sleep_ns(2000);//纳秒级延时
			const auto Local_ActiveWeaponID = Global_LocalPlayer.ActiveWeapon();//本地人物手持武器ID
			if (Local_ActiveWeaponID == 42 || Local_ActiveWeaponID == 59 || Local_ActiveWeaponID >= 500)//过滤特殊武器 (刀类)
			{
				Send_CMD("m_yaw " + to_string(UI_Legit_PreciseAim_DefaultSensitivity)); Sleep(10);
				continue;//重来
			}
			if (Advanced::Check_Enemy(Global_LocalPlayer.IDEntIndex_Pawn()))Send_CMD("m_yaw " + to_string(UI_Legit_PreciseAim_EnableSensitivity));
			else Send_CMD("m_yaw " + to_string(UI_Legit_PreciseAim_DefaultSensitivity));
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
void Thread_Funtion_ESP() noexcept//功能线程: 透视和一些视觉杂项
{
	System::Log("Load Thread: Thread_Funtion_ESP()");
	const auto FreeCS_ESP_RenderWindow = Window::NVIDIA_Overlay();//初始化英伟达覆盖
	Window::Render ESP_Paint; ESP_Paint.CreatePaint(FreeCS_ESP_RenderWindow, 0, 0, Window::Get_Resolution().x, Window::Get_Resolution().y);
	while (true)
	{
		Sleep(UI_Visual_ESP_RenderSleep);
		const auto CS_Scr_Res = Window::Get_WindowResolution(CS2_HWND);
		MoveWindow(FreeCS_ESP_RenderWindow, CS_Scr_Res.b, CS_Scr_Res.a, CS_Scr_Res.r, CS_Scr_Res.g, TRUE);//修改 Pos & Size
		ESP_Paint.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });//清除画板
		if (CS2_HWND && (Menu_Open || Global_IsShowWindow))//当CS窗口在最前端 && 菜单在最前端
		{
			if (UI_Visual_ESP && (UI_Visual_ESP_Key == 0 || System::Get_Key(UI_Visual_ESP_Key)))//ESP 透视
			{
				auto Draw_Color = GUI_IO.GUIColor;
				if (UI_Visual_ESP_CustomColor)Draw_Color = UI_Visual_ESP_CustomColor_Color;
				const auto Local_Matrix = Base::ViewMatrix(); const auto Local_Angles = Base::ViewAngles(); const auto Local_Position = Global_LocalPlayer.Origin();
				for (short i = 0; i < Global_ValidClassID.size(); ++i)
				{
					const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);
					if (!Advanced::Check_Enemy(PlayerPawn))//多点检测
						continue;
					const auto Top_Pos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, PlayerPawn.BonePos(6) + Variable::Vector3{0, 0, 8}, Local_Matrix);
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
					const auto Bottom_Pos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, PlayerPawn.Origin() - Variable::Vector3{0, 0, 6}, Local_Matrix);
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
								ESP_Paint.Render_Line(Bone_ScreenPos.x, Bone_ScreenPos.y, Bone_ScreenPos_.x, Bone_ScreenPos_.y, Draw_Color / 2);
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
						if (PlayerHealth < 100 && PlayerHealth > 0)ESP_Paint.Render_SmpStr(Left - 8, Bottom_Pos.y - Hight * Health_Ma - 6, to_string(PlayerHealth), { 150,150,150 }, { 0 }, 0);
					}
					const auto Player_ClippingWeapon_Name = PlayerPawn.ActiveWeaponName();//人物手持武器名称
					if (UI_Visual_ESP_State)//人物状态
					{
						auto i = 0;//Line pos
						if (PlayerPawn.Armor()) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "HK", { 200,200,200 }, { 0 }, 0); ++i; }
						if (Player_ClippingWeapon_Name == "C4") { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "C4", { 255,0,0 }, { 0 }, 0); ++i; }
						if (PlayerPawn.Scoped() && (Player_ClippingWeapon_Name == "AWP" || Player_ClippingWeapon_Name == "SSG08")) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "ZOOM", { 0,120,255 }, { 0 }, 0); ++i; }
						if (PlayerPawn.Spotted()) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "HIT", { 200,200,200 }, { 0 }, 0); ++i; }
						if (PlayerPawn.ShotsFired() > 0) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "SHOT", { 200,200,200 }, { 0 }, 0); ++i; }
						if (!(PlayerPawn.Flags() & (1 << 0))) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "AIR", { 200,200,200 }, { 0 }, 0); ++i; }
						if (Variable::Coor_Dis_3D(Local_Position, Entity_Position) >= 2500) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "INV", { 100,0,255 }, { 0 }, 0); ++i; }
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
			if (UI_Misc_HitMark && Global_LocalPlayer.Health())//命中标记
			{
				static short Mark_DMG = 0;//造成的伤害
				static Variable::Vector4 Mark_Color = 0;//绘制图标颜色
				Mark_Color = Mark_Color - Variable::Vector4{10, 10, 10}; Mark_Color = Mark_Color.Re_Col();//透明化动画
				static auto OldDamage = 0; const auto Damage = Advanced::Local_RoundDamage();//伤害
				if (Damage > OldDamage || Damage < OldDamage)//当伤害变化
				{
					if (Damage > OldDamage) { Mark_Color = UI_Misc_HitMark_Color; Mark_DMG = Damage - OldDamage; }//Hit
					OldDamage = Damage;//刷新
				}
				const short Range = UI_Misc_HitMark_Range, Length = UI_Misc_HitMark_Length, Width = UI_Misc_HitMark_Width;//绘制设置(距离,长度)
				if (Mark_Color.r != 0 || Mark_Color.g != 0 || Mark_Color.b != 0)//有颜色时绘制
				{
					ESP_Paint.Render_Line(CS_Scr_Res.r / 2 - Range, CS_Scr_Res.g / 2 - Range, CS_Scr_Res.r / 2 - Range - Length, CS_Scr_Res.g / 2 - Range - Length, Mark_Color, Width);
					ESP_Paint.Render_Line(CS_Scr_Res.r / 2 + Range, CS_Scr_Res.g / 2 + Range, CS_Scr_Res.r / 2 + Range + Length, CS_Scr_Res.g / 2 + Range + Length, Mark_Color, Width);
					ESP_Paint.Render_Line(CS_Scr_Res.r / 2 + Range, CS_Scr_Res.g / 2 - Range, CS_Scr_Res.r / 2 + Range + Length, CS_Scr_Res.g / 2 - Range - Length, Mark_Color, Width);
					ESP_Paint.Render_Line(CS_Scr_Res.r / 2 - Range, CS_Scr_Res.g / 2 + Range, CS_Scr_Res.r / 2 - Range - Length, CS_Scr_Res.g / 2 + Range + Length, Mark_Color, Width);
					if (UI_Misc_HitMark_Damage)ESP_Paint.Render_String(CS_Scr_Res.r / 2 - 5, CS_Scr_Res.g / 2 + Range + 10, to_string(Mark_DMG), "Small Fonts", 11, Mark_Color, false);
				}
			}
			if (UI_Misc_SniperCrosshair && Global_LocalPlayer.ActiveWeapon(true) == 3 && !Global_LocalPlayer.Scoped()) { ESP_Paint.RenderA_GradientCircle(CS_Scr_Res.r / 2, CS_Scr_Res.g / 2, 10, GUI_IO.GUIColor.D_Alpha(100), { 0,0,0,0 }); }//狙击枪准星
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
	const auto Render_Window_HWND = RenderWindow.Create_RenderBlock(Window::Get_Resolution().x, Window::Get_Resolution().y, System::Rand_String(12));
	RenderWindow.Set_WindowAttributes({ 0,0,0 }, 180);
	WEP_Render.CreatePaint(Render_Window_HWND, 0, 0, Window::Get_Resolution().x, Window::Get_Resolution().y);
	while (true)
	{
		Sleep(UI_Visual_ESP_RenderSleep);
		const auto CS_Scr_Res = Window::Get_WindowResolution(CS2_HWND);
		WEP_Render.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });//Clear Paint
		if (CS2_HWND && UI_Visual_ESP && (UI_Visual_ESP_Key == 0 || System::Get_Key(UI_Visual_ESP_Key)) && UI_Visual_ESP_Drops && (Menu_Open || Global_IsShowWindow) && Global_LocalPlayer.Health())//当CS窗口在最前端 && 本地人物活着
		{
			auto Draw_Color = GUI_IO.GUIColor;
			if (UI_Visual_ESP_CustomColor)Draw_Color = UI_Visual_ESP_CustomColor_Color;
			MoveWindow(Render_Window_HWND, CS_Scr_Res.b, CS_Scr_Res.a, CS_Scr_Res.r, CS_Scr_Res.g, TRUE);//Pos & Size
			const auto Entitylist = Base::EntityList(); const auto Local_Origin = Global_LocalPlayer.Origin(); const auto Local_ViewMatrix = Base::ViewMatrix();
			static vector<short> Class_ID = {};//有效实体ID
			if (System::Sleep_Tick<class Drops_ESP_Reload_ClassID_>(150))//特殊算法为了提高绘制效率
			{
				short Show_Quantity = 0;//计算绘制的实体数量
				Class_ID = {};//刷新有效实体ID
				for (short i = 64; i <= 1024; ++i)//class id 64-1024
				{
					if (Show_Quantity > 40)//限制数量
						continue;
					const Base::PlayerPawn Entity = Base::Convert(Entitylist, i);
					if (!Entity.Pawn())
						continue;
					const auto Entity_Pos = Entity.Origin();
					if (Entity_Pos.x == 0 || Variable::Coor_Dis_3D(Local_Origin, Entity_Pos) > 2000)//距离检测
						continue;
					const auto Entity_ScrPos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, Entity.Origin(), Local_ViewMatrix);
					if (Entity_ScrPos.x < -200 || Entity_ScrPos.x > CS_Scr_Res.r + 200)//检测是否在屏幕内
						continue;
					if (Entity.ActiveWeaponName(true, Entity.Pawn()) == "NONE" && !Variable::String_Find(Entity.EntityName(), "_projectile"))//检测名称是否有效
						continue;
					Class_ID.push_back(i);
					++Show_Quantity;
					System::Sleep_ns(20);//降低CPU占用
				}
			}
			if (Class_ID.size() > 0)
			{
				for (short i = 0; i < Class_ID.size(); ++i)//只遍历有效实体
				{
					const Base::PlayerPawn Entity = Base::Convert(Entitylist, Class_ID[i]);
					if (Entity.Origin().x == 0)//过滤掉无效坐标
						continue;
					const auto Entity_ScrPos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, Entity.Origin(), Local_ViewMatrix);
					auto Entity_Name = Entity.EntityName();
					if (Variable::String_Find(Entity_Name, "_projectile"))//飞行的道具绘制
					{
						Entity_Name.erase(Entity_Name.length() - 11, 11);//删除_projectile
						WEP_Render.RenderA_GradientCircle(Entity_ScrPos.x, Entity_ScrPos.y, 20, { 1,1,1 }, Draw_Color, floor(sin((float)GetTickCount64() / 150) * 40 + 40) / 100 - 0.2);
						WEP_Render.Render_SmpStr(Entity_ScrPos.x - 15, Entity_ScrPos.y, Variable::String_Upper(Entity_Name), { 200,200,200 }, { 1,1,1 });
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
	Window::Windows Radar_Window; const auto RadarRenderWindow = Radar_Window.Create_Window(UI_Visual_Radar_Size, UI_Visual_Radar_Size + 15, System::Rand_String(13), true);//创建雷达绘制窗口
	Window::Render Radar_Paint; Radar_Paint.CreatePaint(RadarRenderWindow, 0, 0, 500, 500 + 15);//创建绘制画板
	Radar_Window.Set_WindowPos(UI_Visual_Radar_Pos.x, UI_Visual_Radar_Pos.y);//套用参数的雷达位置
	while (true)
	{
		Sleep(10);//降低CPU占用
		static short Radar_Size_; const short RadarSizeAnimation = Variable::Animation<class Class_Radar_Window_Size>(Radar_Size_, 3);
		if ((Global_IsShowWindow || Menu_Open || Window::Get_WindowEnable(Radar_Window.Get_HWND())) && UI_Visual_Radar)//当CS窗口在最前端
		{
			Radar_Size_ = UI_Visual_Radar_Size; UI_Visual_Radar_Pos = Radar_Window.Get_WindowPos();
			if (!Radar_Window.Window_Move(15))
			{
				const float RadarRangeAnimation = Variable::Animation<class Class_Radar_Window_Range>(UI_Visual_Radar_Range, 3);
				const auto LocalPlayerPos = Global_LocalPlayer.Origin(); const auto ViewAngle = Base::ViewAngles();
				Radar_Paint.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });//背景
				Radar_Paint.Render_GradientRect(0, 0, Radar_Window.Get_WindowSize().x, 14, GUI_IO.GUIColor / 2, GUI_IO.GUIColor / 4, false);
				Radar_Paint.Render_GradientRect(0, 14, Radar_Window.Get_WindowSize().x, 1, GUI_IO.GUIColor / 4, GUI_IO.GUIColor / 2, false);//标题背景
				Radar_Paint.Render_String(3 + 1, 1 + 1, "Radar", "Small Fonts", 12, { 0,0,0 }, false);
				Radar_Paint.Render_String(3, 1, "Radar", "Small Fonts", 12, GUI_IO.GUIColor, false);//标题
				if (UI_Visual_Radar_FollowAngle)Radar_Paint.Render_GradientTriangle({ RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15 ,(int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 135, 0)[0], (int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 135, 0)[1] ,(int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 225, 0)[0], (int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 225, 0)[1] }, GUI_IO.GUIColor / 5, { 0,0,0 }, { 0,0,0 });
				else Radar_Paint.Render_GradientTriangle({ RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15 ,(int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngle.y, 45)[0], (int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngle.y, 45)[1] ,(int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngle.y, 135)[0], (int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngle.y, 135)[1] }, GUI_IO.GUIColor / 5, { 0,0,0 }, { 0,0,0 });//Self Aimpos
				Radar_Paint.Render_HollowCircle(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 100 * 3.5, { 255,255,255 }, 1);//自身圆圈
				for (short i = 0; i < Global_ValidClassID.size(); ++i)
				{
					const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);
					if (!Advanced::Check_Enemy(PlayerPawn))//多点检测
						continue;
					const auto EntityPos = PlayerPawn.Origin();
					static vector<float> 敌人屏幕坐标;
					if (UI_Visual_Radar_FollowAngle)敌人屏幕坐标 = { RadarSizeAnimation / 2 - Variable::Ang_Pos(Variable::Coor_Dis_2D(LocalPlayerPos, EntityPos), ViewAngle.y - 90 + atan2((LocalPlayerPos.x - EntityPos.x), (LocalPlayerPos.y - EntityPos.y)) * (180 / acos(-1)))[0] / RadarRangeAnimation,RadarSizeAnimation / 2 + 15 + Variable::Ang_Pos(Variable::Coor_Dis_2D(LocalPlayerPos, EntityPos), ViewAngle.y - 90 + atan2((LocalPlayerPos.x - EntityPos.x), (LocalPlayerPos.y - EntityPos.y)) * (180 / acos(-1)))[1] / RadarRangeAnimation };
					else 敌人屏幕坐标 = { RadarSizeAnimation / 2 - (LocalPlayerPos.x - EntityPos.x) / RadarRangeAnimation,RadarSizeAnimation / 2 + 15 + (LocalPlayerPos.y - EntityPos.y) / RadarRangeAnimation };
					if (敌人屏幕坐标[0] > RadarSizeAnimation)敌人屏幕坐标[0] = RadarSizeAnimation;
					else if (敌人屏幕坐标[0] < 0) 敌人屏幕坐标[0] = 0;
					if (敌人屏幕坐标[1] > RadarSizeAnimation + 15)敌人屏幕坐标[1] = RadarSizeAnimation + 15;
					else if (敌人屏幕坐标[1] < 15)敌人屏幕坐标[1] = 15;
					if (PlayerPawn.Spotted())Radar_Paint.Render_SolidCircle(敌人屏幕坐标[0], 敌人屏幕坐标[1], RadarSizeAnimation / 100 * 3.5, GUI_IO.GUIColor, GUI_IO.GUIColor, 1);//敌人圆圈
					else Radar_Paint.Render_HollowCircle(敌人屏幕坐标[0], 敌人屏幕坐标[1], RadarSizeAnimation / 100 * 3.5, GUI_IO.GUIColor, 1);
				}
				Radar_Paint.DrawPaint();
			}
		}
		else Radar_Size_ = 0;
		Radar_Window.Set_WindowSize(RadarSizeAnimation, RadarSizeAnimation + 15);
		Radar_Window.Set_WindowAlpha(Variable::Animation<class Class_Radar_Window_Alpha>(UI_Visual_Radar_Alpha, 3));
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
				if (!Advanced::Check_Enemy(PlayerPawn))//多点检测
					continue;
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
	BOOL Attest = false;//认证变量
	System::URL_READ UserID_READ = { "UserID" };
	if (UserID_READ.StoreMem("https://github.com/Coslly/Misc/raw/main/About%20Rensen/UserID.uid?raw=true"))//Github读取有效用户ID
	{
		const auto Local_UserName = System::Get_UserName();
		for (short i = 0; i <= 100; i++) { if (Local_UserName == UserID_READ.Read(i) || Variable::String_Upper(Local_UserName) == "BYPASS")Attest = true; }//修改认证
		UserID_READ.Release();
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
	if (!System::Judge_File(UI_LocalConfigPath)) { System::Create_File(UI_LocalConfigPath, UI_DefaultConfig); System::Self_Restart(); }//创建默认参数文件
	thread Thread_Menu_ = thread(Thread_Menu);
	thread Thread_Misc_ = thread(Thread_Misc);
	Sleep(50);//防止重启卡线程(以下为功能函数线程)
	thread Thread_Funtion_Aimbot_ = thread(Thread_Funtion_Aimbot);
	thread Thread_Funtion_AdaptiveAimbot_ = thread(Thread_Funtion_AdaptiveAimbot);
	thread Thread_Funtion_Triggerbot_ = thread(Thread_Funtion_Triggerbot);
	thread Thread_Funtion_PreciseAim_ = thread(Thread_Funtion_PreciseAim);
	thread Thread_Funtion_RemoveRecoil_ = thread(Thread_Funtion_RemoveRecoil);
	thread Thread_Funtion_ESP_ = thread(Thread_Funtion_ESP);
	thread Thread_Funtion_EntityESP_ = thread(Thread_Funtion_EntityESP);
	thread Thread_Funtion_Radar_ = thread(Thread_Funtion_Radar);
	thread Thread_Funtion_Sonar_ = thread(Thread_Funtion_Sonar);
	while (true)//菜单动画和关闭快捷键
	{
		if (System::Get_Key(VK_INSERT) && System::Get_Key(VK_DELETE)) { Beep(100, 30); Window::NVIDIA_Overlay(); exit(0); }//快速关闭键(防止卡线程)
		const auto MenuWindowAlpha_ = Variable::Animation<class Main_Rensen_MenuAlpha_Animation>(UI_Setting_Menu_MainColor.a, 1.3);//菜单透明度动画
		static short MenuWindowAlpha = 0;
		if (Menu_Open)MenuWindowAlpha = MenuWindowAlpha + MenuWindowAlpha_ / 10;
		else MenuWindowAlpha = MenuWindowAlpha - MenuWindowAlpha_ / 10;
		if (MenuWindowAlpha >= MenuWindowAlpha_)MenuWindowAlpha = MenuWindowAlpha_;
		else if (MenuWindowAlpha <= 0)MenuWindowAlpha = 0;
		GUI_VAR.Window_SetAlpha(MenuWindowAlpha);//修改菜单透明度
		if (UI_Setting_Menu_CustomColor)GUI_VAR.Global_Set_EasyGUI_Color(UI_Setting_Menu_MainColor);//自定义菜单颜色
		if (!System::Key_Toggle<class Main_Rensen_MenuKey>(UI_Setting_Menu_MenuKey)) { GUI_VAR.Window_Show(); Menu_Open = true; }
		else { if (MenuWindowAlpha == 0)GUI_VAR.Window_Hide(); Menu_Open = false; }
		GUI_IO = GUI_VAR.Get_IO();//刷新GUI状态数据
		if (!UI_Setting_Menu_CustomColor)GUI_IO.GUIColor = { GUI_IO.GUIColor_Rainbow[3],GUI_IO.GUIColor_Rainbow[4],GUI_IO.GUIColor_Rainbow[5] };//GUI主题颜色到功能函数
		Sleep(1);
	}
}