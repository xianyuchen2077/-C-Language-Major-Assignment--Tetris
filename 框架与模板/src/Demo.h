#pragma once

#pragma region 头文件引用
#define _CRT_SECURE_NO_DEPRECATE
// 平台版本头文件
#include "targetver.h"

// Windows 头文件
#define WIN32_LEAN_AND_MEAN // 从 Windows 头文件中排除极少使用的内容
#include <windows.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>

// 资源头文件
#include "resource.h"
#pragma comment(lib, "Msimg32.lib") // 解决报错：无法解析的外部符号 __imp_TransparentBlt
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")

// TODO: 在此处引用程序需要的其他头文件
#include <cmath>
#include <vector>

#pragma endregion

#pragma region 宏定义

// 窗体
#define WINDOW_TITLEBARHEIGHT 40 // 标题栏高度
#define WINDOW_WIDTH 1216        // 游戏窗口宽度
#define WINDOW_HEIGHT 820        // 游戏窗口高度

// 计时器
#define TIMER_GAMETIMER 1           // 游戏的默认计时器ID
#define TIMER_GAMETIMER_ELAPSE 80  // 默认计时器刷新间隔的毫秒数
                                    //100毫秒基本上恰到好处
#define TIMER_PAINTTIMER 2
#define TIMER_PAINTTIMER_ELAPSE 20
#define TIMER_KEYUPDATETIMER 3
#define TIMER_KEYUPDATETIMER_ELAPSE 90
#define TIMER_COUNTDOWNTIMER 4
#define TIMER_COUNTDOWNTIMER_ELAPSE 1000
#define TIMER_WARNINGTIMER 5
#define TIMER_WARNINGTIMER_ELAPSE 8000

// 游戏阶段
#define STAGE_START 0 // 开始画面的ID
#define STAGE_GAME 1  // 第一个游戏场景的ID
#define STAGE_RANKLIST 2  // 第二个游戏场景的ID——排行榜
#define STAGE_HELP 3  //第三个游戏场景的ID——帮助界面
#define STAGE_SETTING 4
#define STAGE_GAME_MODE 5
#define STAGE_GAME_OVER_DEFEAT 6
#define STAGE_GAME_OVER_VICTOR 7
#define STAGE_EXIT 8
#define STAGE_STORE 9
#define STAGE_ENTERTAINMENT_INTRODUCTION 10
#define STAGE_SETUP_INTERFACE 11
#define STAGE_MAP_KEEP 12
#define STAGE_GRADE_LIMIT_SET 13
#define STAGE_DETAILED_SETUP_INTERFACE 14
#define STAGE_BILNDGAME_START 15
#define STAGE_MAPDESIGNGAME_START 16
#define STAGE_TIMELIMITEDGAME_START 17
#define STAGE_STORE_2 18

// 背景
#define BG_CELL_WIDTH 50                      // 背景单格宽度
#define BG_CELL_HEIGHT 50                      // 背景单格高度
#define BG_COLUMNS WINDOW_WIDTH / BG_CELL_WIDTH // 背景沿X方向的单元个数
#define BG_ROWS WINDOW_HEIGHT / BG_CELL_HEIGHT  // 背景沿Y方向的单元个数

// 砖块
#define BRICK_CELL_WIDTH 50                          // 砖块单格宽度
#define BRICK_CELL_HEIGHT 50                         // 砖块单格高度
#define BRICK_COLUMNS WINDOW_WIDTH / BRICK_CELL_WIDTH // 砖块沿X方向的单元个数
#define BRICK_ROWS WINDOW_HEIGHT / BRICK_CELL_HEIGHT  // 砖块沿Y方向的单元个数
#define BRICK_FRAME_SIZE 4                            // 砖块动画帧序列的大小
#define UP_LINE 4                                      //游戏盼定输赢的线\\上线
#define DOWN_LINE BRICK_ROWS
#define RIGHT_LINE BG_COLUMNS-9
#define LEFT_LINE 0

// 开始游戏按钮
#define BUTTON_STARTGAME_ID 1001                                              // 开始游戏按钮ID
#define BUTTON_RANKLIST_ID 1002                                               //排行榜的ID
#define BUTTON_HELP_ID 1003
#define BUTTON_LOADSAVE_ID 1004
#define BUTTON_GAMEMODE_ID 1005
#define BUTTON_BLINDGAME_ID 1006
#define BUTTON_EXIT_ID 1007
#define BUTTON_AGAIN_ID 1008
#define BUTTON_YES_ID 1009
#define BUTTON_NO_ID 1010
#define BUTTON_BACK_ID 1011
#define BUTTON_DESIGNMAP_ID 1012
#define BUTTON_FINISHDRAW_ID 1013
#define BUTTON_ENTERTAINMENTGAME_ID 1014
#define BUTTON_BEGIN_ENTERTAINMENT_ID 1015
#define BUTTON_CONTINUE_ID 1016
#define BUTTON_BACK_TO_BEGINPAGE_ID 1017
#define BUTTON_MOUSE_UP_ID 1018
#define BUTTON_MOUSE_DOWN_ID 1019
#define BUTTON_MOUSE_LEFT_ID 1020
#define BUTTON_MOUSE_RIGHT_ID 1021
#define BUTTON_TIMELIMITEDGAME_ID 1022
#define BUTTON_BEGIN_TIMELIMITEDGAME_ID 1023
#define BUTTON_RESTART_THE_GAME_ID 1024
#define BUTTON_KEEP_THE_MAP_ID 1025
#define BUTTON_NOT_KEEP_THE_MAP_ID 1026
#define BUTTON_STORE_THE_GAME_ID 1027
#define BUTTON_NOT_STORE_THE_GAME_ID 1028
#define BUTTON_SET_GRADE_LIMIT_ID 1029
#define BUTTON_NOT_SET_GRADE_LIMIT_ID 1030
#define BUTTON_ADD_GRADE_ID 1031
#define BUTTON_MINUS_GRADE_ID 1032
#define BUTTON_GRADE_LIMIT_DEFINE_ID 1033
#define BUTTON_SETUP_ID 1034
#define BUTTON_DETAILED_SETUP_ID 1035
#define BUTTON_BACK_TO_SETUP_ID 1036
#define BUTTON_BEGIN_BLINDGAME_ID 1037
#define BUTTON_BEGIN_MAPDESIGNGAME_ID 1038
#define BUTTON_BEGIN_TIME_LIMITEDGAME_ID 1039
#define BUTTON_NEXTPAGE_ID 1040
#define BUTTON_LASTPAGE_ID 1041
#define BUTTON_RANKLIST_RESTORAGE_ID 1042
#define BUTTON_SLOWEST_SPEED_ID 1043
#define BUTTON_SLOW_SPEED_ID 1044
#define BUTTON_MEDIUM_SPEED_ID 1045
#define BUTTON_QUICK_SPEED_ID 1046
#define BUTTON_EASY_GAME_ID 1047
#define BUTTON_NORMAL_GAME_ID 1048
#define BUTTON_HARD_GAME_ID 1049
#define BUTTON_MUSIC_ID 1050
#define BUTTON_SOUND_ID 1051
#define BUTTON_SOUND_ADD_ID 1052
#define BUTTON_SOUND_MINUS_ID 1053
#define BUTTON_STORE_THE_GAME_2_ID 1054
#define BUTTON_NOT_STORE_THE_GAME_2_ID 1055
#define BUTTON_MUSIC_ADD_ID 1056
#define BUTTON_MUSIC_MINUS_ID 1057

#define BUTTON_STARTGAME_WIDTH 300                                            // 开始游戏按钮宽度
#define BUTTON_small_WIDTH 100
#define BUTTON_big_WIDTH 200
#define BUTTON_STARTGAME_HEIGHT 200                                           // 开始游戏按钮高度
#define BUTTON_small_HEIGHT 100
#define BUTTON_big_HEIGHT 200
#define BUTTON_STARTGAME_X (WINDOW_WIDTH - BUTTON_STARTGAME_WIDTH) / 2+25        // 开始游戏按钮X坐标
#define BUTTON_STARTGAME_Y (WINDOW_HEIGHT - BUTTON_STARTGAME_HEIGHT) / 2 - 175 // 开始游戏按钮Y坐标

// TODO: 添加游戏需要的更多宏定义

#pragma endregion

#pragma region 结构体声明

// 场景结构体
struct Stage
{
    int stageID; // 场景编号
    HBITMAP bg;  // 背景图片
    bool pause;  // 游戏是否被暂停（计时器是否运行）

    // TODO: 其他需要记录的信息
};

// 按钮结构体
struct Button
{
    int buttonID; // 按钮编号
    HBITMAP img;  // 图片
    int x;        // 坐标x
    int y;        // 坐标y
    int width;    // 宽度
    int height;   // 高度
};

// 砖块结构体
struct Brick
{
    HBITMAP img;     // 图片
    int img_id;      // 图片id
    int frame_index; // 当前显示的是帧序列的第几个
    int cell_x;      // 单元坐标x
    int cell_y;      // 单元坐标y
    int mirror_chage;       // 是否发生镜面对换
    int property;    //是否是可删除块
};

// 俄罗斯方块结构体
struct Block
{
    HBITMAP img;    // 图片
    int x;          // 单元坐标x
    int y;          // 单元坐标y
    int shape[4][4];// 方块的形状
    int shape_id;   // 方块方向的编号
    int shape_type; // 方向类型的编号
    int property;   // 方块的属性
};


// TODO: 添加游戏需要的更多结构体

#pragma endregion

#pragma region 事件处理函数声明

// 初始化游戏窗体函数
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 键盘按下事件处理函数
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 键盘松开事件处理函数
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标移动事件处理函数
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标左键按下事件处理函数
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标左键松开事件处理函数
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 定时器事件处理函
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);
void PaintUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);

// TODO: 添加游戏需要的更多处事件理函数

#pragma endregion

#pragma region 其它游戏状态处理函数声明

// 初始化场景函数
void InitStage(HWND hWnd, int stageID);

// 添加按钮函数
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y);

// 添加砖块函数
Brick* CreateBrick(HBITMAP img);

//添加俄罗斯方块函数
Block* CreateBlock(HBITMAP img, int type,int shape_id);

//添加预测方块函数
Block* CreatePredictBlock(HBITMAP img, int type, int shape_id);

// 刷新砖块状态函数
//void UpdateBrick(HWND hWnd);
void BlockCollideDetect();
void REVOLVE();
void BlockBottomCollideDetect();
void UpdateBlock(HWND hWnd);

//随机数函数
int generateRandomNumber1();
int generateRandomNumber2();
int generateRandomNumber3();
int generateRandomNumber4();

//消行检测函数
void DetectRow();

//判断游戏是否结束函数
int GameOver();

//影子投影函数
void Reflect();

//游戏清零函数
void ZeroOut();

//自定义地图函数
void DesignMap();

//文件存档函数
void file_storage();

//文件读档函数
void file_loading();

//分数排行榜存档函数
void ranklist_storage();

//分数排行榜重置
void ranklist_restorage();

//分数排行榜读档函数
void ranklist_loading();

// TODO: 添加游戏需要的更多函数

#pragma endregion

#pragma region 绘图函数声明

// 绘图函数
void Paint(HWND hWnd);

// 创建纯白背景图像
HBITMAP CreateWhiteBackground(HWND hWnd);

// 创建游戏背景资源
HBITMAP CreateGameBackground(HWND hWnd);

// TODO: 添加游戏需要的更多绘图函数

#pragma endregion
