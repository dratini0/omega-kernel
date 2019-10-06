#include "lang.h"

const char* gl_init_error;
const char* gl_power_off;
const char* gl_init_ok;
const char* gl_Loading;
const char* gl_file_overflow;

const char* gl_menu_btn;
const char* gl_lastest_game;

const char* gl_writing;

const char* gl_time;
const char* gl_Mon;
const char* gl_Tues;
const char* gl_Wed;
const char* gl_Thur;
const char* gl_Fri;
const char* gl_Sat;
const char* gl_Sun;

const char* gl_addon;
const char* gl_reset;
const char* gl_rts;
const char* gl_sleep;
const char* gl_cheat;

const char* gl_hot_key;
const char* gl_hot_key2;

const char* gl_language;
const char* gl_en_lang;
const char* gl_zh_lang;
const char* gl_set_btn;
const char* gl_ok_btn;

const char* gl_formatnor_info;

const char* gl_check_sav;
const char* gl_make_sav;

const char* gl_check_RTS;
const char* gl_make_RTS;

const char* gl_check_pat;
const char* gl_make_pat;

const char* gl_loading_game;

const char* gl_engine;
const char* gl_use_engine;

const char*  gl_recently_play;

const char* gl_START_help;
const char* gl_SELECT_help;
const char* gl_L_A_help;
const char* gl_LSTART_help;
const char* gl_online_manual;

const char* gl_no_game_played;

const char* gl_ingameRTC;
//const char* gl_offRTC_powersave;
const char* gl_ingameRTC_open;
const char* gl_ingameRTC_close;

const char* gl_error_0;
const char* gl_error_1;
const char* gl_error_2;
const char* gl_error_3;
const char* gl_error_4;
const char* gl_error_5;
const char* gl_error_6;
//--
const char* const *gl_rom_menu;
const char* const *gl_nor_op;


//中文
static const char zh_init_error[]="TF卡初始化失败";
static const char zh_power_off[]="关机";
static const char zh_init_ok[]="TF卡初始化成功";
static const char zh_Loading[]="加载中...";
static const char zh_file_overflow[]="文件太大,不能加载";

static const char zh_menu_btn[]=" [B]取消    [A]确定";
static const char zh_writing[]="正在写...";
static const char zh_lastest_game[]="请选择最后一个游戏";

static const char zh_time[] ="     时间";
static const char zh_Mon[]="一";
static const char zh_Tues[]="二";
static const char zh_Wed[]="三";
static const char zh_Thur[]="四";
static const char zh_Fri[]="五";
static const char zh_Sat[]="六";
static const char zh_Sun[]="日";

static const char zh_addon[]="     功能";
static const char zh_reset[]="软复位";
static const char zh_rts[]="即时存档";
static const char zh_sleep[]="睡眠";
static const char zh_cheat[]="金手指";

static const char zh_hot_key[]=" 睡眠热键";
static const char zh_hot_key2[]=" 菜单热键";

static const char zh_language[]=" LANGUAGE";
static const char zh_lang[]=" 中文";

static const char zh_set_btn[]="设置";
static const char zh_ok_btn[]="保存";
static const char zh_formatnor_info[]="确定?大约4分钟";

static const char zh_check_sav[]="检查SAV文件";
static const char zh_make_sav[]="创建SAV文件";

static const char zh_check_RTS[]="检查RTS文件";
static const char zh_make_RTS[]="创建RTS文件";

static const char zh_check_pat[]="检查PAT文件";
static const char zh_make_pat[]="创建PAT文件";

static const char zh_loading_game[]="加载游戏";

static const char zh_engine[]="     引擎";
static const char zh_use_engine[]="快速补丁引擎";

static const char zh_recently_play[]="最近游戏列表";

static const char zh_START_help[]="打开最近游戏列表";
static const char zh_SELECT_help[]="缩略图开关";
static const char zh_L_A_help[]="冷启动";
static const char zh_LSTART_help[]="删除文件";
static const char zh_online_manual[]="  在线说明书";

static const char zh_no_game_played[]="还没玩过游戏";

static const char zh_ingameRTC[]=" 游戏时钟";
//static const char zh_offRTC_powersave[]=" ";
static const char zh_ingameRTC_open[]="打开";
static const char zh_ingameRTC_close[]="关闭";//TURNOFF TO POWER SAVE

static const char zh_error_0[]="文件夹错误";
static const char zh_error_1[]="文件错误";
static const char zh_error_2[]="SAVER错误";
static const char zh_error_3[]="存档错误";
static const char zh_error_4[]="读取存档错误";
static const char zh_error_5[]="创建存档错误";
static const char zh_error_6[]="RTS文件错误";

static const char * const zh_rom_menu[]={
	"直接启动",
	"启动带辅助",
	"烧录到NOR",
	"烧录到NOR带辅助",
	"存档类型",
	"金手指",
};
static const char * const zh_nor_op[]={
	"直接运行",
	"删除",
	"全部格式化",
};



//英文
static const char en_init_error[]="Micro SD card initial error";
static const char en_power_off[]="Power off";
static const char en_init_ok[]="Micro SD card initial OK";
static const char en_Loading[]="Loading...";
static const char en_file_overflow[]="The file overflow";

static const char en_menu_btn[]="[B]CANCEL    [A]OK";
static const char en_writing[]="WRITING...";
static const char en_lastest_game[]="SELECT THE LASTEST";

static const char en_time[]="     TIME";
static const char en_Mon[]="MON";
static const char en_Tues[]="TUE";
static const char en_Wed[]="WED";
static const char en_Thur[]="THU";
static const char en_Fri[]="FRI";
static const char en_Sat[]="SAT";
static const char en_Sun[]="SUN";

static const char en_addon[]="    ADDON";
static const char en_reset[]="RESET";
static const char en_rts[]="SAVESTATE";
static const char en_sleep[]="SLEEP";
static const char en_cheat[]="CHEAT";

static const char en_hot_key[] ="SLEEP KEY";
static const char en_hot_key2[]=" MENU KEY";

static const char en_language[]=" LANGUAGE";
static const char en_lang[]="ENGLISH";
static const char en_set_btn[]="SET";
static const char en_ok_btn[]=" OK";

static const char en_formatnor_info[]="SURE?about 4 mins";

static const char en_check_sav[]="CHECKING SAV FILE";
static const char en_make_sav[] ="CREATING SAV FILE";

static const char en_check_RTS[]="CHECKING RTS FILE";
static const char en_make_RTS[] ="CREATING RTS FILE";

static const char en_check_pat[]="CHECKING PAT FILE";
static const char en_make_pat[] ="CREATING PAT FILE";

static const char en_loading_game[]="LOADING GAME";

static const char en_engine[]="   ENGINE";
static const char en_use_engine[]="FAST PATCH ENGINE";

static const char en_recently_play[]="RECENT PLAYED";

static const char en_START_help[]="Open recently played list";
static const char en_SELECT_help[]="Thumbnail toggle";
static const char en_L_A_help[]="Multiboot";
static const char en_LSTART_help[]="Delete file";
static const char en_online_manual[]="Online manual";

static const char en_no_game_played[]="No game played yet";

static const char en_ingameRTC[]=" GAME RTC";
static const char en_ingameRTC_open[]="OPEN";
static const char en_ingameRTC_close[]="CLOSE";//TURNOFF TO POWER SAVE

static const char en_error_0[]="Folder error";
static const char en_error_1[]="File error";
static const char en_error_2[]="SAVER error";
static const char en_error_3[]="Save error";
static const char en_error_4[]="Read save error";
static const char en_error_5[]="Make save error";
static const char en_error_6[]="RTS file error";

static const char * const en_rom_menu[] = {
	"CLEAN BOOT",
	"BOOT WITH ADDON",
	"WRITE TO NOR CLEAN",
	"WRITE TO NOR ADDON",
	"SAVE TYPE",
	"CHEAT",
};
static const char * const en_nor_op[]={
	"DIRECT BOOT",
	"DELETE",
	"FORMAT ALL",
};	

//---------------------------------------------------------------------------------
void LoadChinese(void)
{
	gl_init_error = zh_init_error;
	gl_power_off = zh_power_off;
	gl_init_ok = zh_init_ok;
	gl_Loading = zh_Loading;
	gl_file_overflow = zh_file_overflow;

	gl_menu_btn = zh_menu_btn;
	gl_writing = zh_writing;
	gl_lastest_game = zh_lastest_game;
	
	
	gl_time = zh_time;	
	gl_Mon = zh_Mon;
	gl_Tues = zh_Tues;
	gl_Wed = zh_Wed;
	gl_Thur = zh_Thur;
	gl_Fri = zh_Fri;
	gl_Sat = zh_Sat;
	gl_Sun = zh_Sun;

	gl_addon = zh_addon;
	gl_reset = zh_reset;
	gl_rts = zh_rts;
	gl_sleep = zh_sleep;
	gl_cheat = zh_cheat;	
	
	gl_hot_key = zh_hot_key;
	gl_hot_key2 = zh_hot_key2;

	gl_language =  zh_language;
	gl_en_lang = en_lang;
	gl_zh_lang = zh_lang;;
	gl_set_btn = zh_set_btn;
	gl_ok_btn = zh_ok_btn;
	gl_formatnor_info = zh_formatnor_info;

	gl_check_sav = zh_check_sav;
	gl_make_sav = zh_make_sav;
		
	gl_check_RTS = zh_check_RTS;
	gl_make_RTS = zh_make_RTS;
	
	gl_check_pat = zh_check_pat;
	gl_make_pat = zh_make_pat;
	
	gl_loading_game = zh_loading_game;
	gl_engine = zh_engine;
	gl_use_engine = zh_use_engine;
	
	gl_recently_play = zh_recently_play;

	gl_START_help = zh_START_help;
	gl_SELECT_help = zh_SELECT_help;
	gl_L_A_help = zh_L_A_help;
	gl_LSTART_help = zh_LSTART_help;
	gl_online_manual = zh_online_manual;
	
	gl_no_game_played = zh_no_game_played;
	
	gl_ingameRTC = zh_ingameRTC;
	//gl_offRTC_powersave = zh_offRTC_powersave;
	gl_ingameRTC_open = zh_ingameRTC_open;
	gl_ingameRTC_close = zh_ingameRTC_close;
	
	gl_error_0 = zh_error_0;
	gl_error_1 = zh_error_1;
	gl_error_2 = zh_error_2;
	gl_error_3 = zh_error_3;
	gl_error_4 = zh_error_4;
	gl_error_5 = zh_error_5;
	gl_error_6 = zh_error_6;
	
	//
	gl_rom_menu = zh_rom_menu;
	gl_nor_op = zh_nor_op;

}
//---------------------------------------------------------------------------------
void LoadEnglish(void)
{
	gl_init_error = en_init_error;
	gl_power_off = en_power_off;
	gl_init_ok = en_init_ok;
	gl_Loading = en_Loading;
	gl_file_overflow = en_file_overflow;

	gl_menu_btn = en_menu_btn;
	gl_writing = en_writing;
	gl_lastest_game = en_lastest_game;
	
	gl_time = en_time;	
	gl_Mon = en_Mon;
	gl_Tues = en_Tues;
	gl_Wed = en_Wed;
	gl_Thur = en_Thur;
	gl_Fri = en_Fri;
	gl_Sat = en_Sat;
	gl_Sun = en_Sun;
	gl_addon = en_addon;
	gl_reset = en_reset;
	gl_rts = en_rts;
	gl_sleep = en_sleep;
	gl_cheat = en_cheat;	
	
	gl_hot_key = en_hot_key;
	gl_hot_key2 = en_hot_key2;
	
	gl_language =  en_language;
	gl_en_lang = en_lang;
	gl_zh_lang = zh_lang;;
	gl_set_btn = en_set_btn;
	gl_ok_btn = en_ok_btn;
	gl_formatnor_info = en_formatnor_info;

	gl_check_sav = en_check_sav;
	gl_make_sav = en_make_sav;
		
	gl_check_RTS = en_check_RTS;
	gl_make_RTS = en_make_RTS;
	
	gl_check_pat = en_check_pat;
	gl_make_pat = en_make_pat;
	
	gl_loading_game = en_loading_game;
	
	gl_engine = en_engine;
	gl_use_engine = en_use_engine;
	
	gl_recently_play = en_recently_play;
	
	gl_START_help = en_START_help;
	gl_SELECT_help = en_SELECT_help;
	gl_L_A_help = en_L_A_help;
	gl_LSTART_help = en_LSTART_help;
	gl_online_manual = en_online_manual;
	
	gl_no_game_played = en_no_game_played;
	
	gl_ingameRTC = en_ingameRTC;
	//gl_offRTC_powersave = en_offRTC_powersave;
	gl_ingameRTC_open = en_ingameRTC_open;
	gl_ingameRTC_close = en_ingameRTC_close;
	
	gl_error_0 = en_error_0;
	gl_error_1 = en_error_1;
	gl_error_2 = en_error_2;
	gl_error_3 = en_error_3;
	gl_error_4 = en_error_4;
	gl_error_5 = en_error_5;
	gl_error_6 = en_error_6;
	//
	gl_rom_menu = en_rom_menu;
	gl_nor_op = en_nor_op;
}
