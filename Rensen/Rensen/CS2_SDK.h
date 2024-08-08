#include "Head.h"
BOOL TeamCheck = false;//人物所处队伍变量
namespace CS2_SDK//开发者工具库(防止和基础函数冲突)
{
	HWND CS2_HWND = NULL;
	System::Memory CS2_MEM = { "cs2.exe" };
	auto Module_client = CS2_MEM.Get_Module("client.dll");//模块地址: 本地
	auto Module_engine = CS2_MEM.Get_Module("engine.dll");//模块地址: 引擎
	auto Module_server = CS2_MEM.Get_Module("server.dll");//模块地址: 服务器
	vector<short> Global_ValidClassID = { NULL };//有效实体
	BOOL Global_IsShowWindow = false;//窗口显示
	BOOL Global_TeamCheck = false;//团队过滤
	void ExecuteCommand(string Command_Str) noexcept//发送指令到CS控制台
	{
		COPYDATASTRUCT m_cData; m_cData.cbData = strlen(Command_Str.c_str()) + 1; m_cData.dwData = 0; m_cData.lpData = (void*)Command_Str.c_str();
		SendMessage(CS2_MEM.Get_ProcessHWND(), WM_COPYDATA, 0, (LPARAM)&m_cData);//发送命令
		//-----------------------------------------------------------------------------------
		if (Command_Str == "+jump")System::Key_Con_HWND(CS2_HWND, VK_SPACE, true);
		else if (Command_Str == "-jump")System::Key_Con_HWND(CS2_HWND, VK_SPACE, false);
		if (Command_Str == "+duck")System::Key_Con_HWND(CS2_HWND, VK_CONTROL, true);
		else if (Command_Str == "-duck")System::Key_Con_HWND(CS2_HWND, VK_CONTROL, false);
		if (Command_Str == "+lookatweapon")System::Key_Con_HWND(CS2_HWND, 0x46, true);
		else if (Command_Str == "-lookatweapon")System::Key_Con_HWND(CS2_HWND, 0x46, false);
		if (Command_Str == "drop")System::Key_Click_HWND(CS2_HWND, 0x47, true);
		if (Command_Str == "+attack")mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		else if (Command_Str == "-attack")mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		if (Command_Str == "+attack2")mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
		else if (Command_Str == "-attack2")mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
		if (Command_Str == "+forward")System::Key_Con_HWND(CS2_HWND, 0x57, true);//W
		else if (Command_Str == "-forward")System::Key_Con_HWND(CS2_HWND, 0x57, false);
		if (Command_Str == "+back")System::Key_Con_HWND(CS2_HWND, 0x53, true);//S
		else if (Command_Str == "-back")System::Key_Con_HWND(CS2_HWND, 0x53, false);
		if (Command_Str == "+left")System::Key_Con_HWND(CS2_HWND, 0x41, true);//A
		else if (Command_Str == "-left")System::Key_Con_HWND(CS2_HWND, 0x41, false);
		if (Command_Str == "+right")System::Key_Con_HWND(CS2_HWND, 0x44, true);//D
		else if (Command_Str == "-right")System::Key_Con_HWND(CS2_HWND, 0x44, false);
	}
	namespace CS2_Offsets//CS2固定偏移量 (游戏更新时需要同时更新 https://github.com/a2x/cs2-dumper.git)
	{
		string Offsets_Date = "[0000-00-00 00:00]";
		uintptr_t dwLocalPlayerController = 0x1A0E9C8;
		uintptr_t dwLocalPlayerPawn = 0x1824A18;
		uintptr_t dwEntityList = 0x19BEED0;
		uintptr_t dwViewAngles = 0x1A2E268;
		uintptr_t dwViewMatrix = 0x1A20CF0;
		uintptr_t m_hPlayerPawn = 0x7DC;
		uintptr_t m_iTeamNum = 0x3C3;
		uintptr_t m_ArmorValue = 0x22D0;
		uintptr_t m_iHealth = 0x324;
		uintptr_t m_iIDEntIndex = 0x13A8;
		uintptr_t m_fFlags = 0x3CC;
		uintptr_t m_iShotsFired = 0x22B4;
		uintptr_t m_vecVelocity = 0x3E0;
		uintptr_t m_bSpotted = 0x2290;//m_entitySpottedState + m_bSpotted
		uintptr_t m_bIsScoped = 0x22A0;
		uintptr_t m_pClippingWeapon = 0x12F0;
		uintptr_t m_pGameSceneNode = 0x308;
		uintptr_t m_vecOrigin = 0x88;
		uintptr_t m_aimPunchCache = 0x14F0;
		uintptr_t m_vecViewOffset = 0xC50;
		uintptr_t m_dwBoneMatrix = 0x1F0;//m_modelState + 0x80
		uintptr_t m_iszPlayerName = 0x630;
		uintptr_t m_pActionTrackingServices = 0x700;
		uintptr_t m_iNumRoundKills = 0x110;
		uintptr_t m_unTotalRoundDamageDealt = 0x118;
		uintptr_t m_iItemDefinitionIndex = 0x129A;//m_AttributeManager + m_Item + m_iItemDefinitionIndex
		uintptr_t m_angEyeAngles = 0x1388;
	}
	namespace Base//基础内存函数
	{
		uintptr_t EntityList() noexcept { return CS2_MEM.Read<uintptr_t>(Module_client + CS2_Offsets::dwEntityList); }//实体列表
		uintptr_t Convert(uintptr_t EntityList, uintptr_t Player) noexcept { return CS2_MEM.Read<uintptr_t>(CS2_MEM.Read<uintptr_t>(EntityList + 8 * ((Player & 0x7FFF) >> 9) + 16) + 120 * (Player & 0x1FF)); }//各种转换
		class PlayerPawn//玩家Pawn内存类
		{
		private:uintptr_t m_PlayerPawn = 0; public:PlayerPawn(uintptr_t dwPlayerPawn) noexcept { m_PlayerPawn = dwPlayerPawn; };
			   uintptr_t Pawn() const noexcept { return m_PlayerPawn; }//人物地址
			   short Health() const noexcept { return CS2_MEM.Read<short>(m_PlayerPawn + CS2_Offsets::m_iHealth); }//人物血量
			   short Armor() const noexcept { return CS2_MEM.Read<short>(m_PlayerPawn + CS2_Offsets::m_ArmorValue); }//人物护甲
			   short TeamNumber() const noexcept { return CS2_MEM.Read<short>(m_PlayerPawn + CS2_Offsets::m_iTeamNum); }//人物队伍
			   short IDEntIndex() const noexcept { return CS2_MEM.Read<short>(m_PlayerPawn + CS2_Offsets::m_iIDEntIndex); }//人物瞄准的实体ID
			   PlayerPawn IDEntIndex_Pawn() const noexcept//瞄准实体的人物Pawn
			   {
				   const auto Index = CS2_MEM.Read<short>(m_PlayerPawn + CS2_Offsets::m_iIDEntIndex);
				   if (Index <= 10000)return Convert(EntityList(), Index); else return 0;
			   }
			   short Flags() const noexcept { return CS2_MEM.Read<short>(m_PlayerPawn + CS2_Offsets::m_fFlags); }//人物状态
			   short ShotsFired() const noexcept { return CS2_MEM.Read<short>(m_PlayerPawn + CS2_Offsets::m_iShotsFired); }//人物开枪子弹数量
			   short Spotted() const noexcept { return CS2_MEM.Read<short>(m_PlayerPawn + CS2_Offsets::m_bSpotted); }//人物发现状态
			   short Scoped() const noexcept { const auto Scoped = CS2_MEM.Read<short>(m_PlayerPawn + CS2_Offsets::m_bIsScoped); if (Scoped == 65536)return 0; else return Scoped; }//人物狙击枪开镜
			   short ActiveWeapon(BOOL Type = 0) const noexcept//人物手持武器(类型,ID)
			   {
				   const auto ClippingWeapon = CS2_MEM.Read<short>(CS2_MEM.Read<uintptr_t>(m_PlayerPawn + CS2_Offsets::m_pClippingWeapon) + CS2_Offsets::m_iItemDefinitionIndex);
				   if (Type)//武器类型 0:无效 1:手枪 2:连射枪 3:狙击枪 4:霰弹枪
				   {
					   switch (ClippingWeapon)
					   {
					   case 1: return 1;
					   case 2: return 1;
					   case 3: return 1;
					   case 4: return 1;
					   case 7: return 2;
					   case 8: return 2;
					   case 9: return 3;
					   case 10: return 2;
					   case 11: return 3;
					   case 13: return 2;
					   case 14: return 2;
					   case 16: return 2;
					   case 17: return 2;
					   case 19: return 2;
					   case 23: return 2;
					   case 24: return 2;
					   case 25: return 4;
					   case 26: return 2;
					   case 27: return 4;
					   case 28: return 2;
					   case 29: return 4;
					   case 30: return 1;
					   case 32: return 1;
					   case 33: return 2;
					   case 34: return 2;
					   case 35: return 4;
					   case 36: return 1;
					   case 38: return 3;
					   case 39: return 2;
					   case 40: return 3;
					   case 60: return 2;
					   case 61: return 1;
					   case 63: return 1;
					   case 64: return 1;
					   default: return 0;
					   }
				   }
				   else return ClippingWeapon;
			   }
			   float MoveSpeed() const noexcept { const auto Velocity = CS2_MEM.Read<Variable::Vector3>(m_PlayerPawn + CS2_Offsets::m_vecVelocity); return hypot(Velocity.x, Velocity.y); }//人物移动速度
			   string ActiveWeaponName(BOOL Use_WeaponBase = false, uintptr_t WeaponBase = 0) const noexcept//人物手持武器名称
			   {
				   auto ClippingWeapon = CS2_MEM.Read<short>(CS2_MEM.Read<uintptr_t>(m_PlayerPawn + CS2_Offsets::m_pClippingWeapon) + CS2_Offsets::m_iItemDefinitionIndex);
				   if (Use_WeaponBase)ClippingWeapon = CS2_MEM.Read<short>(WeaponBase + CS2_Offsets::m_iItemDefinitionIndex);
				   if (ClippingWeapon >= 500 && ClippingWeapon <= 600)return "KNIFE";
				   switch (ClippingWeapon)
				   {
				   case 1: return "DEAGLE";
				   case 2: return "DUAL BERETTAS";
				   case 3: return "FN57";
				   case 4: return "GLOCK";
				   case 7: return "AK47";
				   case 8: return "AUG";
				   case 9: return "AWP";
				   case 10: return "FAMAS";
				   case 11: return "G3SG1";
				   case 13: return "GALILAR";
				   case 14: return "M249";
				   case 16: return "M4A1";
				   case 17: return "MAC10";
				   case 19: return "P90";
				   case 23: return "MP5";
				   case 24: return "UMP45";
				   case 25: return "XM1014";
				   case 26: return "BIZON";
				   case 27: return "MAG7";
				   case 28: return "NEGEV";
				   case 29: return "SAWED";
				   case 30: return "TEC9";
				   case 31: return "TASER";
				   case 32: return "P2000";
				   case 33: return "MP7";
				   case 34: return "MP9";
				   case 35: return "NOVA";
				   case 36: return "P250";
				   case 38: return "SCAR20";
				   case 39: return "SG553";
				   case 40: return "SSG08";
				   case 42: return "KNIFE";
				   case 43: return "FLASH";
				   case 44: return "GRENADE";
				   case 45: return "SMOKE";
				   case 46: return "MOLOTOV";
				   case 47: return "DECOY";
				   case 48: return "INCGRNNADE";
				   case 49: return "C4";
				   case 59: return "KNIFE";
				   case 60: return "M4A1-S";
				   case 61: return "USP-S";
				   case 63: return "CZ75";
				   case 64: return "REVOLVER";
				   default: return "NONE";
				   }
			   }
			   string EntityName() const noexcept { return CS2_MEM.Read_str(CS2_MEM.Read<uintptr_t>(CS2_MEM.Read<uintptr_t>(m_PlayerPawn + 0x10) + 0x20)); }//实体名称(非人物)
			   Variable::Vector3 Velocity() const noexcept { return CS2_MEM.Read<Variable::Vector3>(m_PlayerPawn + CS2_Offsets::m_vecVelocity); }//人物单方向移动速度
			   Variable::Vector3 Origin() const noexcept { return CS2_MEM.Read<Variable::Vector3>(CS2_MEM.Read<uintptr_t>(m_PlayerPawn + CS2_Offsets::m_pGameSceneNode) + CS2_Offsets::m_vecOrigin); }//人物世界坐标
			   Variable::Vector3 AimPunchAngle() const noexcept//人物手持武器后坐力
			   {
				   struct UtlVec { DWORD64 count; DWORD64 data; }; const auto PunchCache = CS2_MEM.Read<UtlVec>(m_PlayerPawn + CS2_Offsets::m_aimPunchCache);//后座缓存
				   if (PunchCache.count > 0 && PunchCache.count < 0xFFFF)return CS2_MEM.Read<Variable::Vector3>(PunchCache.data + (PunchCache.count - 1) * sizeof(Variable::Vector3));
			   }
			   Variable::Vector3 ViewOffset() const noexcept { return CS2_MEM.Read<Variable::Vector3>(m_PlayerPawn + CS2_Offsets::m_vecViewOffset); }//人物朝向偏移
			   Variable::Vector3 BonePos(short Bone_ID = 3) const noexcept//人物骨骼坐标
			   {
				   const auto BoneMatrix = CS2_MEM.Read<uintptr_t>(CS2_MEM.Read<uintptr_t>(m_PlayerPawn + CS2_Offsets::m_pGameSceneNode) + CS2_Offsets::m_dwBoneMatrix);
				   return CS2_MEM.Read<Variable::Vector3>(BoneMatrix + Bone_ID * 0x20);
			   }
			   Variable::Vector3 ViewAngles() const noexcept { return CS2_MEM.Read<Variable::Vector3>(m_PlayerPawn + CS2_Offsets::m_angEyeAngles); }//人物朝向角度
		};
		PlayerPawn LocalPlayer() noexcept { return CS2_MEM.Read<uintptr_t>(Module_client + CS2_Offsets::dwLocalPlayerPawn); }//本地人物
		uintptr_t LocalPlayerController() noexcept { return CS2_MEM.Read<uintptr_t>(Module_client + CS2_Offsets::dwLocalPlayerController); }//本地人物控制器
		Variable::Vector3 ViewAngles() noexcept { return CS2_MEM.Read<Variable::Vector3>(Module_client + CS2_Offsets::dwViewAngles); }//本地人物朝向
		Variable::view_matrix_t ViewMatrix() noexcept { return CS2_MEM.Read<Variable::view_matrix_t>(Module_client + CS2_Offsets::dwViewMatrix); }//本地人物视觉矩阵(用于制作ESP)
	}
	Base::PlayerPawn Global_LocalPlayer = NULL;//本地人物地址
	namespace Advanced//进阶内存扩展函数
	{
		Base::PlayerPawn Traverse_Player(short i, BOOL ReturnPlayerController = false) noexcept//遍历人物Pawn
		{
			const auto Entitylist = Base::EntityList();
			const auto PlayerController = Base::Convert(Entitylist, i);
			if (ReturnPlayerController)return PlayerController;
			return Base::Convert(Entitylist, CS2_MEM.Read<uint32_t>(PlayerController + CS2_Offsets::m_hPlayerPawn));
		}
		string LocalPlayer_Name() noexcept { return CS2_MEM.Read_str(Base::LocalPlayerController() + CS2_Offsets::m_iszPlayerName); }//本地人物名称
		string Player_Name(short i) noexcept//通过ClassID获取名称
		{
			const auto PlayerController = Base::Convert(Base::EntityList(), i);
			if (!PlayerController)return "None";
			else return CS2_MEM.Read_str(PlayerController + CS2_Offsets::m_iszPlayerName);
		}
		BOOL Check_Enemy(Base::PlayerPawn PlayerPawn) noexcept { return (PlayerPawn.Pawn() != Global_LocalPlayer.Pawn() && PlayerPawn.Health() > 0 && (!Global_TeamCheck || Global_LocalPlayer.TeamNumber() != PlayerPawn.TeamNumber()) && PlayerPawn.TeamNumber() != 1); }//判断人物是否是敌人
		BOOL Stop_Move(short TriggerValue = 85, BOOL Movement = true) noexcept//急停
		{
			const auto LocalVel = Global_LocalPlayer.Velocity();
			if (hypot(LocalVel.x, LocalVel.y) <= TriggerValue)return true;//当精准则返回真
			if (Movement)//停止移动 反之只返回是否精准
			{
				const auto LocalYaw = Base::ViewAngles().y;
				const auto X = (LocalVel.x * cos(LocalYaw / 180 * 3.1415926) + LocalVel.y * sin(LocalYaw / 180 * 3.1415926));
				const auto Y = (LocalVel.y * cos(LocalYaw / 180 * 3.1415926) - LocalVel.x * sin(LocalYaw / 180 * 3.1415926));
				ExecuteCommand("-back"); ExecuteCommand("-forward"); ExecuteCommand("-right"); ExecuteCommand("-left");
				if (X > 30) { ExecuteCommand("+back"); Sleep(1); ExecuteCommand("-back"); }
				else if (X < -30) { ExecuteCommand("+forward"); Sleep(1); ExecuteCommand("-forward"); }
				if (Y > 30) { ExecuteCommand("+right"); Sleep(1); ExecuteCommand("-right"); }
				else if (Y < -30) { ExecuteCommand("+left"); Sleep(1); ExecuteCommand("-left"); }
			}
			return false;
		}
		Variable::Vector3 World_Screen(Variable::Vector3 Pos) noexcept { return WorldToScreen(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), Pos, Base::ViewMatrix()); }//世界坐标转换屏幕坐标
		short Local_RoundDamage(BOOL Return_Kill = false) noexcept//回合伤害和击杀数
		{
			const auto Local_RoundValue = CS2_MEM.Read<uintptr_t>(Base::LocalPlayerController() + CS2_Offsets::m_pActionTrackingServices);
			if (Return_Kill)return CS2_MEM.Read<short>(Local_RoundValue + CS2_Offsets::m_iNumRoundKills);
			else return CS2_MEM.Read<short>(Local_RoundValue + CS2_Offsets::m_unTotalRoundDamageDealt);
		}
		void Move_to_Angle(Variable::Vector3 Target_Angles = { 0,0,0 }, float Smooth = 40, float Offset = 0.25, int Traversals_Mum = 100) noexcept//本地人物将视角移动到指定坐标
		{
			for (int i = 0; i <= Traversals_Mum; ++i)
			{
				const auto LocalPlayer_Angle = Base::ViewAngles();//本地人物朝向
				if (hypot(LocalPlayer_Angle.x - Target_Angles.x, LocalPlayer_Angle.y - Target_Angles.y) <= Offset)return;
				System::Mouse_Move((-Target_Angles.y + LocalPlayer_Angle.y) * Smooth, (Target_Angles.x - LocalPlayer_Angle.x) * Smooth);
				if (Traversals_Mum != 1)Sleep(1);
			}
		}
		BOOL Move_to_Pos(Variable::Vector3 Target_Pos = { 0,0,0 }, float Edge = 5) noexcept//本地人物移动到指定世界坐标
		{
			const auto LocalPlayer_Pos = Global_LocalPlayer.Origin();//本地人物所处世界坐标
			const auto Target_Distance = hypot(LocalPlayer_Pos.x - Target_Pos.x, LocalPlayer_Pos.y - Target_Pos.y);//计算与目标坐标的距离
			if (Target_Distance <= Edge)return true;//达到边缘则不进行移动
			auto Offset_Angle = Base::ViewAngles().y - Variable::Pos_Angle(LocalPlayer_Pos, Target_Pos); if (Offset_Angle < 0)Offset_Angle += 360;//角度偏移
			if (Offset_Angle > 315 - 15 || Offset_Angle < 45 + 15)ExecuteCommand("+forward");
			else ExecuteCommand("-forward");
			if (Offset_Angle > 45 - 15 && Offset_Angle < 135 + 15)ExecuteCommand("+right");
			else ExecuteCommand("-right");
			if (Offset_Angle > 135 - 15 && Offset_Angle < 225 + 15)ExecuteCommand("+back");
			else ExecuteCommand("-back");
			if (Offset_Angle > 225 - 15 && Offset_Angle < 315 + 15)ExecuteCommand("+left");
			else ExecuteCommand("-left");
			if (Target_Distance <= Edge * 2)//降低移动速度
			{
				Sleep(1);//按键缓冲
				ExecuteCommand("-forward");
				ExecuteCommand("-right");
				ExecuteCommand("-back");
				ExecuteCommand("-left");//释放所有按键
			}
			return false;//未移动到目标坐标
		}
	}
	void ReLoad(BOOL Timeout = false) noexcept//刷新CS2进程地址和模块地址和有效实体
	{
		if (System::Sleep_Tick<class CLASS_CS2_SDK_Timeout_Reload>(1000) || Timeout)
		{
			CS2_MEM = { "cs2.exe" };
			CS2_HWND = CS2_MEM.Get_ProcessHWND();
			Module_client = CS2_MEM.Get_Module("client.dll");
			Module_engine = CS2_MEM.Get_Module("engine.dll");
			Module_server = CS2_MEM.Get_Module("server.dll");
			Global_LocalPlayer = Base::LocalPlayer();
			if (System::Sleep_Tick<class CLASS_CS2_SDK_Offsets_Timeout_Reload>(5000) || Timeout)//自动更新偏移量延迟 (减少流量使用)
			{
				System::URL_READ URL_OFFSETS = { "Cache_CS2_Offsets" };
				if (URL_OFFSETS.StoreMem("https://github.com/Coslly/Rensen/blob/main/Cloud%20Files/Offsets.ofs?raw=true"))//自动更新偏移量 Github更新有十分钟延迟 中国用户需要挂梯子
				{
					CS2_Offsets::Offsets_Date = URL_OFFSETS.Read(1);CS2_Offsets::Offsets_Date.erase(0, 2);//偏移更新日期 删除注释符号
					CS2_Offsets::Offsets_Date = "[" + CS2_Offsets::Offsets_Date + "]";//加上括号
					CS2_Offsets::dwLocalPlayerController = Variable::string_uint_(URL_OFFSETS.Read(4));
					CS2_Offsets::dwLocalPlayerPawn = Variable::string_uint_(URL_OFFSETS.Read(6));
					CS2_Offsets::dwEntityList = Variable::string_uint_(URL_OFFSETS.Read(8));
					CS2_Offsets::dwViewAngles = Variable::string_uint_(URL_OFFSETS.Read(10));
					CS2_Offsets::dwViewMatrix = Variable::string_uint_(URL_OFFSETS.Read(12));
					CS2_Offsets::m_hPlayerPawn = Variable::string_uint_(URL_OFFSETS.Read(14));
					CS2_Offsets::m_iTeamNum = Variable::string_uint_(URL_OFFSETS.Read(16));
					CS2_Offsets::m_ArmorValue = Variable::string_uint_(URL_OFFSETS.Read(18));
					CS2_Offsets::m_iHealth = Variable::string_uint_(URL_OFFSETS.Read(20));
					CS2_Offsets::m_iIDEntIndex = Variable::string_uint_(URL_OFFSETS.Read(22));
					CS2_Offsets::m_fFlags = Variable::string_uint_(URL_OFFSETS.Read(24));
					CS2_Offsets::m_iShotsFired = Variable::string_uint_(URL_OFFSETS.Read(26));
					CS2_Offsets::m_vecVelocity = Variable::string_uint_(URL_OFFSETS.Read(28));
					CS2_Offsets::m_bSpotted = Variable::string_uint_(URL_OFFSETS.Read(30));
					CS2_Offsets::m_bIsScoped = Variable::string_uint_(URL_OFFSETS.Read(32));
					CS2_Offsets::m_pClippingWeapon = Variable::string_uint_(URL_OFFSETS.Read(34));
					CS2_Offsets::m_pGameSceneNode = Variable::string_uint_(URL_OFFSETS.Read(36));
					CS2_Offsets::m_vecOrigin = Variable::string_uint_(URL_OFFSETS.Read(38));
					CS2_Offsets::m_aimPunchCache = Variable::string_uint_(URL_OFFSETS.Read(40));
					CS2_Offsets::m_vecViewOffset = Variable::string_uint_(URL_OFFSETS.Read(42));
					CS2_Offsets::m_dwBoneMatrix = Variable::string_uint_(URL_OFFSETS.Read(44));
					CS2_Offsets::m_iszPlayerName = Variable::string_uint_(URL_OFFSETS.Read(46));
					CS2_Offsets::m_pActionTrackingServices = Variable::string_uint_(URL_OFFSETS.Read(48));
					CS2_Offsets::m_iNumRoundKills = Variable::string_uint_(URL_OFFSETS.Read(50));
					CS2_Offsets::m_unTotalRoundDamageDealt = Variable::string_uint_(URL_OFFSETS.Read(52));
					CS2_Offsets::m_iItemDefinitionIndex = Variable::string_uint_(URL_OFFSETS.Read(54));
					CS2_Offsets::m_angEyeAngles = Variable::string_uint_(URL_OFFSETS.Read(56));
					URL_OFFSETS.Release();//释放文件
				}
				if (!Timeout)//报错项
				{
					if (!CS2_HWND)System::Log("Error: CS2 process not found", true);//未启动CS时报错
					if (CS2_Offsets::Offsets_Date == "[0000-00-00 00:00]")System::Log("Error: Unable to obtain cloud offset", true);//无法获取偏移量时报错
				}
			}
			Global_ValidClassID = {};//遍历前刷新有效实体ID
			for (short i = 0; i <= 64; ++i)//最大人数64
			{
				const auto PlayerPawn = Advanced::Traverse_Player(i);
				if (!PlayerPawn.Health() > 0 || (PlayerPawn.Origin().x == 0 && PlayerPawn.Origin().y == 0))continue;//多点检测
				Global_ValidClassID.push_back(i);
			}
		}
		Global_IsShowWindow = CS2_MEM.Get_ProcessHWND() == GetForegroundWindow();//刷新是否是最前端窗口
	}
}
using namespace CS2_SDK;