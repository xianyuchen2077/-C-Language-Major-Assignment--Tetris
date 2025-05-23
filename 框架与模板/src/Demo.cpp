// Demo.cpp : 定义应用程序的入口点。
#include "Demo.h"
using namespace std;

#pragma region 全局变量

#define MAX_LOADSTRING 100

// 全局变量：
HINSTANCE hInst;                      // 当前实例
WCHAR szTitle[MAX_LOADSTRING];        // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];  // 主窗口类名

// 位图资源：
HBITMAP bmp_StartButton;     // 开始按钮图像资源
HBITMAP bmp_MoreDetailButton;
HBITMAP bmp_Rock;            // 石头图像资源
HBITMAP bmp_Brick;           // 砖块图像资源

HBITMAP bmp_beth;
HBITMAP bmp_jerry;
HBITMAP bmp_morty;
HBITMAP bmp_rick;
HBITMAP bmp_summer;
HBITMAP bmp_snowball_white;
HBITMAP bmp_snowball;
HBITMAP bmp_math_teacher;
HBITMAP bmp_jessica;
HBITMAP bmp_Mr_Meeseeks;
HBITMAP bmp_president;
HBITMAP bmp_dreaming_jerry;

HBITMAP bmp_block_predict;
HBITMAP bmp_shadow_rick;
HBITMAP bmp_shadow_jerry;
HBITMAP bmp_shadow_beth;
HBITMAP bmp_shadow_math_teacher;
HBITMAP bmp_shadow_president;

HBITMAP bmp_beth_small;
HBITMAP bmp_jerry_small;
HBITMAP bmp_morty_small;
HBITMAP bmp_rick_small;
HBITMAP bmp_summer_small;
HBITMAP bmp_snowball_small;
HBITMAP bmp_jessica_small;
HBITMAP bmp_math_teacher_small;
HBITMAP bmp_president_small;
HBITMAP bmp_Mr_Meeseeks_small;

HBITMAP bmp_button_150_Mr_Meeseeks;
HBITMAP bmp_button_150_jessica;
HBITMAP bmp_button_150_dreaming_jerry;
HBITMAP bmp_button_150_morty;
HBITMAP bmp_button_150_evilmorty;
HBITMAP bmp_button_150_rick;
HBITMAP bmp_button_150_jerry;
HBITMAP bmp_button_200_morty;
HBITMAP bmp_button_200_evilmorty;
HBITMAP bmp_button_200_rick;
HBITMAP bmp_button_200_jerry;
HBITMAP bmp_button_black_jerry;
HBITMAP bmp_button_black_beth;

HBITMAP bmp_add_50bmp;
HBITMAP bmp_minus_50bmp;
HBITMAP bmp_uparrow_button;
HBITMAP bmp_downarrow_button;
HBITMAP bmp_leftarrow_button;
HBITMAP bmp_rightarrow_button;
HBITMAP bmp_finish_button;
HBITMAP bmp_start_button;
HBITMAP bmp_win;
HBITMAP bmp_win_button;
HBITMAP bmp_nextpage_button;
HBITMAP bmp_lastpage_button;
HBITMAP bmp_yesbutton;
HBITMAP bmp_nobutton;
HBITMAP bmp_SHOUYANG;
HBITMAP bmp_XIANZHUO;
HBITMAP bmp_WARNING_LINE;
HBITMAP bmp_gameover;
HBITMAP bmp_background1;
HBITMAP bmp_background2;
HBITMAP bmp_background3;
HBITMAP bmp_background4;
HBITMAP bmp_background5;
HBITMAP bmp_background6;
HBITMAP bmp_background7;
HBITMAP bmp_background8;
HBITMAP bmp_background9;
HBITMAP bmp_background10;
HBITMAP bmp_background11;

HBITMAP bmp_WhiteBackground; // 生成的纯白色背景图像
HBITMAP bmp_GameBackground;  // 生成的游戏背景图像

// 游戏状态：
Stage* currentStage = NULL; // 当前场景状态
std::vector<Button*> buttons(70);   // 按钮
Brick* brick = nullptr;        // 砖块
Block* block = nullptr;
Block* block_shadow = nullptr;
Block* block_next = nullptr;
std::vector<Brick*>base;//所有的砖块
std::vector<bool>flags;//所有的旗子
int base_all[30][30] = {};
int map_base[30][30] = {};

//俄罗斯方块
const int shape_Blue_Ricky[4][4][4] = {
   {{1,0,0,0},
    {1,1,1,0},
    {0,0,0,0},
    {0,0,0,0}},

   {{0,1,1,0},
    {0,1,0,0},
    {0,1,0,0},
    {0,0,0,0}},

   {{0,0,0,0},
    {1,1,1,0},
    {0,0,1,0},
    {0,0,0,0}},

   {{0,1,0,0},
    {0,1,0,0},
    {1,1,0,0},
    {0,0,0,0}},
};
const int shape_Orange_Ricky[4][4][4] = {
   {{0,0,1,0},
    {1,1,1,0},
    {0,0,0,0},
    {0,0,0,0}},

   {{0,1,0,0},
    {0,1,0,0},
    {0,1,1,0},
    {0,0,0,0}},

   {{0,0,0,0},
    {1,1,1,0},
    {1,0,0,0},
    {0,0,0,0}},

   {{1,1,0,0},
    {0,1,0,0},
    {0,1,0,0},
    {0,0,0,0}},
};
const int shape_Rhode_Island_Z[4][4][4] = {
   {{0,1,1,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0}},

   {{0,1,0,0},
    {0,1,1,0},
    {0,0,1,0},
    {0,0,0,0}},

   {{0,0,0,0},
    {0,1,1,0},
    {1,1,0,0},
    {0,0,0,0}},

   {{1,0,0,0},
    {1,1,0,0},
    {0,1,0,0},
    {0,0,0,0}},
};
const int shape_Cleveland_Z[4][4][4] = {
   {{1,1,0,0},
    {0,1,1,0},
    {0,0,0,0},
    {0,0,0,0}},

   {{0,0,1,0},
    {0,1,1,0},
    {0,1,0,0},
    {0,0,0,0}},

   {{0,0,0,0},
    {1,1,0,0},
    {0,1,1,0},
    {0,0,0,0}},

   {{0,1,0,0},
    {1,1,0,0},
    {1,0,0,0},
    {0,0,0,0}},
};
const int shape_Teewee[4][4][4] = {
   {{0,1,0,0},
    {1,1,1,0},
    {0,0,0,0},
    {0,0,0,0}},

   {{0,1,0,0},
    {0,1,1,0},
    {0,1,0,0},
    {0,0,0,0}},

   {{0,0,0,0},
    {1,1,1,0},
    {0,1,0,0},
    {0,0,0,0}},

   {{0,1,0,0},
    {1,1,0,0},
    {0,1,0,0},
    {0,0,0,0}},
};
const int shape_Hero[4][4][4] = {
   {{0,1,0,0},
    {0,1,0,0},
    {0,1,0,0},
    {0,1,0,0}},

   {{0,0,0,0},
    {1,1,1,1},
    {0,0,0,0},
    {0,0,0,0}},

   {{0,1,0,0},
    {0,1,0,0},
    {0,1,0,0},
    {0,1,0,0}},

   {{0,0,0,0},
    {1,1,1,1},
    {0,0,0,0},
    {0,0,0,0}},
};
const int shape_Smashboy[4][4][4] = {
   {{1,1,0,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0}},

   {{1,1,0,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0}},

   {{1,1,0,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0}},

   {{1,1,0,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0}},
};

// 键盘：
bool keyUpDown = false;    // 上
bool keyDownDown = false;  // 下
bool keyLeftDown = false;  // 左
bool keyRightDown = false; // 右
bool keyEsc = false;

// 鼠标：
int mouseX = 0;         // 鼠标X坐标
int mouseY = 0;         // 鼠标Y坐标
bool mouseDown = false; // 鼠标按下

int volume_music=800;//音乐音量
int volume_sound = 800;//音效音量
char volume_str1[100] = {};
char volume_str2[100] = {};
int Cnt_fall = 0;       //方块自然下落“计时器”
int Cnt_fall_standard = 10;//方块自然下落“计时器”标准
int difficulty_level = 2;//游戏难度
int up_line_standard=4;//游戏上线
int countdown = 181;      //限时模式“计时器”
int type = 0;           //方块类型
int type_next = 0;      //下一个方块类型
int shape_original_id = 0;//方块初始方向
int shape_next_original_id = -1;//下一个方块初始方向
int grade = 0;          //总分数
int grade_limit = 100;  //游戏结束分数上限
int times = 1;          //消行得数倍率
int ranklist_id = 0;    //排行榜中游戏模式的id（默认是普通模式0）
int normal_top5[5] = {};//普通模式分数排行榜
int blind_top5[5] = {};//盲打模式分数排行榜
int designmap_top5[5] = {};//自定义地图模式分数排行榜
int props_top5[5] = {};//道具模式分数排行榜
int timelimited_top5[5] = {};//限时模式分数排行榜

bool leftflag = false;
bool rightflag = false;
bool right_out_possible_flag = false;
bool upflag = false;
bool downflag = false;
bool next_step = true;//键盘能否进行下一步操作
bool delete_the_row = false;//消行
bool blindgame_open = false;//盲打模式开关
bool blindgame_not_draw = false;//盲打不画图
bool sneer = false;//退出触发嘲讽
bool key_updateflag = true;
bool win_or_defeat = false;//游戏输赢判断
bool design_map_flag = false;//自定义地图开关1
bool design_map_flag_2 = false;//自定义地图开关2
bool design_map_keep_flag = false;//自定义地图是否保存
bool entertainmentgame_flag = false;//道具模式开关
bool time_limited_game = false;//限时模式开关
bool time_limited_game_begin = false;//限时模式是否开始
bool zero_out_all = false;//是否全部清零
bool click_button = false;//一次点击最多触发一个按钮
bool store_button = false;//判断打开的是不是存档游戏
bool file_loading_flag = false;//改程序之后貌似也没用了
bool grade_limit_judgeflag = false;//是否询问是否需要设置分数上限
bool grade_limit_setting = false;//是否需要设置分数上限
bool grade_storage = false;//游戏结束时成绩是否保存
bool music_flag = true;//音乐开关
bool sound_flag = true;//音效开关
bool warning_flag = false;//警报音效的开关

//加旗子的时候记得在zeroout（）里面也加一下
//还有存档函数里面加一下

#pragma endregion

#pragma region Win32程序框

// 此代码模块中包含的函数的前向声明:
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nCmdShow)
{
    //音乐
    mciSendStringA("open l_really_wanna_stay_at_your_house.mp3 alias background_bgm", NULL, 0, NULL);
    mciSendStringA("open BYE.mp3 alias byebye", NULL, 0, NULL);
    mciSendStringA("open YOUWIN.mp3 alias youwin", NULL, 0, NULL);
    mciSendStringA("open WARNING.mp3 alias warning", NULL, 0, NULL);
    mciSendStringA("open WHATEVER.mp3 alias whatever", NULL, 0, NULL);
    mciSendStringA("open OH.mp3 alias oh", NULL, 0, NULL);
    mciSendStringA("open NO.mp3 alias no", NULL, 0, NULL);
    mciSendStringA("open ITS_ALL_COOL.mp3 alias cool", NULL, 0, NULL);
    mciSendStringA("open FALLDOWN.mp3 alias falldown", NULL, 0, NULL);
    mciSendStringA("open I_QUIT.mp3 alias i_quit", NULL, 0, NULL);
    mciSendStringA("open NOT_SURE.mp3 alias not_sure", NULL, 0, NULL);
    mciSendStringA("open WOW.mp3 alias wow", NULL, 0, NULL);
    mciSendStringA("open GOOD_LUCK.mp3 alias good_luck", NULL, 0, NULL);
    mciSendStringA("open HELLO.mp3 alias hello", NULL, 0, NULL);
    mciSendStringA("open BOOM.mp3 alias boom", NULL, 0, NULL);

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DEMO, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DEMO));

    MSG msg;

    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex{};

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DEMO));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_DEMO);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 将实例句柄存储在全局变量中

    HWND hWnd = CreateWindowW(
        szWindowClass, szTitle,
        WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, // 设置窗口样式，不可改变大小，不可最大化
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        WINDOW_WIDTH,
        WINDOW_HEIGHT + WINDOW_TITLEBARHEIGHT,
        nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_CREATE   - 处理窗口创建事件
//  WM_TIMER    - 处理定时器TimeOut事件
//  WM_PAINT    - 绘制主窗口
//  WM_COMMAND  - 处理应用程序菜单
//  WM_DESTROY  - 发送退出消息并返回
//
//所有的函数都来自这里！！！
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        // 初始化游戏窗体
        InitGame(hWnd, wParam, lParam);
    }
    break;
    case WM_KEYDOWN:
    {
        // 键盘按下事件
        KeyDown(hWnd, wParam, lParam);
    }
    break;
    case WM_KEYUP:
    {
        // 键盘松开事件
        KeyUp(hWnd, wParam, lParam);
    }
    break;
    case WM_MOUSEMOVE:
    {
        // 鼠标移动事件
        MouseMove(hWnd, wParam, lParam);
    }
    break;
    case WM_LBUTTONDOWN:
    {
        // 鼠标左键按下事件
        LButtonDown(hWnd, wParam, lParam);
    }
    break;
    case WM_LBUTTONUP:
    {
        // 鼠标左键松开事件
        LButtonUp(hWnd, wParam, lParam);
    }
    break;
    case WM_TIMER:
    {
        if (wParam == TIMER_GAMETIMER)
        {
            // 判断游戏是否暂停
            if (currentStage != NULL && !currentStage->pause)
            {
                TimerUpdate(hWnd, wParam, lParam);
            }
        }
        if (wParam == TIMER_PAINTTIMER)
        {
            if (currentStage != NULL && !currentStage->pause)
            {
                PaintUpdate(hWnd, wParam, lParam);
            }
        }
        if (wParam == TIMER_KEYUPDATETIMER)//这个计时器的作用貌似不大
        {
            if (currentStage != NULL && !currentStage->pause)
            {
                key_updateflag = true;
            }
        }
        if (wParam == TIMER_COUNTDOWNTIMER)
        {
            if (currentStage != NULL && !currentStage->pause && countdown > 1 && !GameOver())
            {
                countdown--;
            }
        }
        if (wParam == TIMER_WARNINGTIMER)
        {
            if (currentStage != NULL && !currentStage->pause)
            {
                warning_flag = true;
            }
        }
    }
    break;
    case WM_PAINT:
    {
        // 绘图
        Paint(hWnd);
    }
    break;

    // TODO：其他消息
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 分析菜单选择:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_DESTROY:
    {
        mciSendString("close background_bgm", 0, 0, 0);

        // 窗口退出
        PostQuitMessage(0);
    }
    break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

#pragma endregion

#pragma region 事件处理函数

// 初始化游戏窗体函数
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    // 加载图像资源
    bmp_StartButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_startbutton2));
    bmp_MoreDetailButton= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_family));
    bmp_Rock = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_ROCK));
    bmp_Brick = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BRICK));
    //100*100
    bmp_beth = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character1_big));
    bmp_jerry = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character2_big));
    bmp_morty = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character3_big));
    bmp_rick = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character4_big));
    bmp_summer = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character5_big));
    bmp_snowball = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character6_big));
    bmp_snowball_white = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character6_big_white));
    bmp_jessica = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character7_big));
    bmp_math_teacher = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character8_big));
    bmp_Mr_Meeseeks = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character9_big));
    bmp_president = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character10_big));
    bmp_dreaming_jerry = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character11_big));
    //50*50
    bmp_beth_small = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character1));
    bmp_jerry_small = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character2));
    bmp_morty_small = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character3));
    bmp_rick_small = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character4));
    bmp_summer_small = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character5));
    bmp_snowball_small = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character6));
    bmp_jessica_small = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character7));
    bmp_math_teacher_small = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character8));
    bmp_Mr_Meeseeks_small = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character9));
    bmp_president_small = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_character10));
    bmp_shadow_rick = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_shadow_rick));
    bmp_shadow_beth = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_shadow_beth));
    bmp_shadow_jerry = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_shadow_jerry));
    bmp_shadow_math_teacher = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_shadow_math_teacher));
    bmp_shadow_president = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_shadow_president));
    //150*150
    bmp_button_150_morty = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_button150_1));
    bmp_button_150_evilmorty = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_button150_2));
    bmp_button_150_rick = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_button150_3));
    bmp_button_150_jerry = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_button150_4));
    bmp_button_150_dreaming_jerry = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_button150_5));
    bmp_button_150_jessica = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_button150_6));
    bmp_button_150_Mr_Meeseeks = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_button150_7));
    //200*200
    bmp_button_200_morty = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_button200_11));
    bmp_button_200_evilmorty = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_button200_2));
    bmp_button_200_rick = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_button200_3));
    bmp_button_200_jerry = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_button200_4));
    //按钮
    bmp_button_black_jerry = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_black_jerry));
    bmp_button_black_beth = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_black_beth));
    bmp_add_50bmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_add_button));
    bmp_minus_50bmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_minus_button));
    bmp_lastpage_button = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_lastpage));
    bmp_nextpage_button = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_nextpage));
    bmp_block_predict = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_predict));
    bmp_uparrow_button = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_arrow_up));
    bmp_downarrow_button = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_arrow_down));
    bmp_leftarrow_button = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_arrow_left));
    bmp_rightarrow_button = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_arrow_right));
    bmp_finish_button = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_finish_button));
    bmp_start_button = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_start_button));
    bmp_win = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_win));
    bmp_win_button = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_win_button_2));
    bmp_yesbutton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_YES_BUTTON));
    bmp_nobutton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NO_BUTTON));
    bmp_SHOUYANG = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SHOUYANG));
    bmp_XIANZHUO = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_XIANZHUO));
    bmp_WARNING_LINE = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_WARNING_LINE));
    bmp_gameover = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_gameover));
    //背景图
    bmp_background1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_bg1));
    bmp_background8 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_bg5));
    bmp_background9 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_bg6));
    bmp_background10 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_bg7));
    bmp_background11 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_bg8));
    //大背景图
    bmp_WhiteBackground = CreateWhiteBackground(hWnd);
    bmp_GameBackground = CreateGameBackground(hWnd);

    //背景音乐播放
    mciSendString("play background_bgm repeat", 0, 0, 0);

    // 初始化开始场景
    InitStage(hWnd, STAGE_START);

    // 初始化主计时器
    SetTimer(hWnd, TIMER_GAMETIMER, TIMER_GAMETIMER_ELAPSE, NULL);
    SetTimer(hWnd, TIMER_PAINTTIMER, TIMER_PAINTTIMER_ELAPSE, NULL);
    SetTimer(hWnd, TIMER_KEYUPDATETIMER, TIMER_KEYUPDATETIMER_ELAPSE, NULL);
    SetTimer(hWnd, TIMER_COUNTDOWNTIMER, TIMER_COUNTDOWNTIMER_ELAPSE, NULL);
    SetTimer(hWnd, TIMER_WARNINGTIMER, TIMER_WARNINGTIMER_ELAPSE, NULL);
}

// 键盘按下事件处理函数
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    if (key_updateflag == false)
    {
        return;
    }
    key_updateflag = false;
    switch (wParam)
    {
    case 0x57:  // W
    case VK_UP: // 方向键上
        keyUpDown = true;
        break;
    case 0x53:    // S
    case VK_DOWN: // 方向键下
        keyDownDown = true;
        break;
    case 0x41:    // A
    case VK_LEFT: // 方向键左
        keyLeftDown = true;
        break;
    case 0x44:     // D
    case VK_RIGHT: // 方向键右
        keyRightDown = true;
        break;
    case VK_ESCAPE:// ESC
        keyEsc = true;
        break;
      
            // TODO：其他按键
    default:
        key_updateflag = true;
        break;
    }
}

// 键盘松开事件处理函数
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    switch (wParam)
    {
    case 0x57:  // W
    case VK_UP: // 方向键上
        keyUpDown = false;
        break;
    case 0x53:    // S
    case VK_DOWN: // 方向键下
        keyDownDown = false;
        break;
    case 0x41:    // A
    case VK_LEFT: // 方向键左
        keyLeftDown = false;
        break;
    case 0x44:     // D
    case VK_RIGHT: // 方向键右
        keyRightDown = false;
        break;
    case VK_ESCAPE:// ESC
        keyEsc = false;
        break;

        // TODO：其他按键
    default:
        break;
    }
}

// 鼠标移动事件处理函数
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    mouseX = LOWORD(lParam);
    mouseY = HIWORD(lParam);
}

// 鼠标左键按下事件处理函数
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    mouseX = LOWORD(lParam);
    mouseY = HIWORD(lParam);
    mouseDown = true;

    // 判断鼠标是否点击按钮
    for (int i = 0; i < buttons.size(); i++)
    {
        Button* button = buttons[i];
        if (button->x <= mouseX && button->x + button->width >= mouseX && button->y <= mouseY && button->y + button->height >= mouseY)
        {
            click_button = true;
            switch (button->buttonID)
            {
            case BUTTON_STARTGAME_ID:
            {
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_RANKLIST_ID:
            {
                ranklist_loading();
                ranklist_id = 0;
                InitStage(hWnd, STAGE_RANKLIST);
            }
            break;
            case BUTTON_HELP_ID:
            {
                InitStage(hWnd, STAGE_HELP);
            }
            break;
            case BUTTON_GAMEMODE_ID:
            {
                //不注释就可能导致重开时游戏模式改变
                //zero_out_all = true;
                InitStage(hWnd, STAGE_GAME_MODE);
            }
            break;
            case BUTTON_BLINDGAME_ID:
            {
                blindgame_open = true;
                InitStage(hWnd, STAGE_BILNDGAME_START);
            }
            break;
            case BUTTON_EXIT_ID:
            {
                //不要随意清零
                //ZeroOut();
                InitStage(hWnd, STAGE_EXIT);
            }
            break;
            case BUTTON_AGAIN_ID:
            {
                if (design_map_flag_2)
                {
                    InitStage(hWnd, STAGE_MAP_KEEP);
                    break;
                }
                ZeroOut();
                Sleep(800);
                if (music_flag)
                    mciSendString("resume background_bgm", 0, 0, 0);
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_YES_ID:
            {
                sneer = true;
                if (sound_flag)
                {
                    mciSendString("play i_quit from 0", 0, 0, 0);
                }
                Sleep(1000);
                if (!GameOver())
                    InitStage(hWnd, STAGE_STORE);
                else
                    InitStage(hWnd, STAGE_EXIT);
            }
            break;
            case BUTTON_NO_ID:
            {
                sneer = false;
                if (sound_flag)
                {
                    mciSendString("play not_sure from 0", 0, 0, 0);
                }
                Sleep(2500);
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_BACK_ID:
            {
                InitStage(hWnd, STAGE_START);
            }
            break;
            case BUTTON_DESIGNMAP_ID:
            {
                currentStage->pause = true;
                design_map_flag = true;
                design_map_flag_2 = true;
                InitStage(hWnd, STAGE_MAPDESIGNGAME_START);
            }
            break;
            case BUTTON_FINISHDRAW_ID:
            {
                currentStage->pause = false;
                design_map_flag = false;
                design_map_flag_2 = true;
                for (size_t i = 0; i < buttons.size(); i++)
                {
                    Button* button = buttons[i];
                    if (button->buttonID == BUTTON_FINISHDRAW_ID)
                    {
                        delete button;
                        buttons.erase(buttons.begin() + i);
                    }
                }
                Sleep(500);
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_ENTERTAINMENTGAME_ID:
            {
                entertainmentgame_flag = true;
                InitStage(hWnd, STAGE_ENTERTAINMENT_INTRODUCTION);
            }
            break;
            case BUTTON_CONTINUE_ID:
            {
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_BACK_TO_BEGINPAGE_ID:
            {
                InitStage(hWnd, STAGE_STORE_2);
            }
            break;
            case BUTTON_MOUSE_UP_ID:
            {
                keyUpDown = true;
            }
            break;
            case BUTTON_MOUSE_DOWN_ID:
            {
                keyDownDown = true;
            }
            break;
            case BUTTON_MOUSE_LEFT_ID:
            {
                keyLeftDown = true;
            }
            break;
            case BUTTON_MOUSE_RIGHT_ID:
            {
                keyRightDown = true;
            }
            break;
            case BUTTON_TIMELIMITEDGAME_ID:
            {
                time_limited_game = true;
                time_limited_game_begin = false;
                currentStage->pause = true;
                countdown = 181;
                InitStage(hWnd, STAGE_TIMELIMITEDGAME_START);
            }
            break;
            case BUTTON_BEGIN_TIMELIMITEDGAME_ID:
            {
                Sleep(800);
                currentStage->pause = false;
                time_limited_game = true;
                time_limited_game_begin = true;
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_RESTART_THE_GAME_ID:
            {
                if (design_map_flag_2)
                {
                    InitStage(hWnd, STAGE_MAP_KEEP);
                    break;
                }
                ZeroOut();
                Sleep(300);
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_KEEP_THE_MAP_ID:
            {
                design_map_keep_flag = true;
                ZeroOut();
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_NOT_KEEP_THE_MAP_ID:
            {
                design_map_keep_flag = false;
                ZeroOut();
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_STORE_THE_GAME_ID:
            {
                file_storage();
                if (sound_flag)
                {
                    mciSendString("pause background_bgm", 0, 0, 0);
                    mciSendString("play byebye from 0", 0, 0, 0);
                }
                Sleep(1000);
                InitStage(hWnd, STAGE_EXIT);
            }
            break;
            case BUTTON_NOT_STORE_THE_GAME_ID:
            {
                if (sound_flag)
                {
                    mciSendString("pause background_bgm", 0, 0, 0);
                    mciSendString("play byebye from 0", 0, 0, 0);
                }
                Sleep(1000);
                InitStage(hWnd, STAGE_EXIT);
            }
            break;
            case BUTTON_LOADSAVE_ID:
            {
                file_loading();
                sneer = false;
                time_limited_game_begin = false;
                click_button = false;
                grade_storage = false;
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_SET_GRADE_LIMIT_ID:
            {
                grade_limit_setting = true;
                InitStage(hWnd, STAGE_GRADE_LIMIT_SET);
            }
            break;
            case BUTTON_NOT_SET_GRADE_LIMIT_ID:
            {
                grade_limit_setting = false;
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_ADD_GRADE_ID:
            {
                if (grade_limit < 500)
                    grade_limit = grade_limit + 10;
            }
            break;
            case BUTTON_MINUS_GRADE_ID:
            {
                if (grade_limit > 10)
                    grade_limit = grade_limit - 10;
            }
            break;
            case BUTTON_GRADE_LIMIT_DEFINE_ID:
            {
                if (sound_flag)
                {
                    mciSendString("play wow from 0", 0, 0, 0);
                }
                Sleep(800);
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_SETUP_ID:
            {
                InitStage(hWnd, STAGE_SETUP_INTERFACE);
            }
            break;
            case BUTTON_DETAILED_SETUP_ID:
            {
                InitStage(hWnd, STAGE_DETAILED_SETUP_INTERFACE);
            }
            break;
            case BUTTON_BACK_TO_SETUP_ID:
            {
                InitStage(hWnd, STAGE_SETUP_INTERFACE);
            }
            break;
            case BUTTON_BEGIN_BLINDGAME_ID:
            {
                if (sound_flag)
                {
                    mciSendString("play good_luck from 0", 0, 0, 0);
                }
                Sleep(800);
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_BEGIN_MAPDESIGNGAME_ID:
            {
                if (sound_flag)
                {
                    mciSendString("play good_luck from 0", 0, 0, 0);
                }
                Sleep(800);
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_BEGIN_ENTERTAINMENT_ID:
            {
                if (sound_flag)
                {
                    mciSendString("play good_luck from 0", 0, 0, 0);
                }
                Sleep(800);
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_BEGIN_TIME_LIMITEDGAME_ID:
            {
                if (sound_flag)
                {
                    mciSendString("play good_luck from 0", 0, 0, 0);
                }
                Sleep(800);
                countdown = 181;
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_LASTPAGE_ID:
            {
                ranklist_id--;
                if (ranklist_id < 0)
                {
                    ranklist_id = ranklist_id + 5;
                }
                ranklist_loading();
                InitStage(hWnd, STAGE_RANKLIST);
            }
            break;
            case BUTTON_NEXTPAGE_ID:
            {
                ranklist_id++;
                if (ranklist_id > 4)
                {
                    ranklist_id = ranklist_id - 5;
                }
                ranklist_loading();
                InitStage(hWnd, STAGE_RANKLIST);
            }
            break;
            case BUTTON_RANKLIST_RESTORAGE_ID:
            {
                ranklist_restorage();
                ranklist_loading();
                InitStage(hWnd, STAGE_RANKLIST);
            }
            break;
            case BUTTON_SLOWEST_SPEED_ID:
            {
                Cnt_fall_standard = 40;
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_SLOW_SPEED_ID:
            {
                Cnt_fall_standard = 20;
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_MEDIUM_SPEED_ID:
            {
                Cnt_fall_standard = 10;
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_QUICK_SPEED_ID:
            {
                Cnt_fall_standard = 3;
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_EASY_GAME_ID:
            {
                difficulty_level = 1;
                up_line_standard = 1;
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_NORMAL_GAME_ID:
            {
                difficulty_level = 2;
                up_line_standard = 4;
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_HARD_GAME_ID:
            {
                difficulty_level = 3;
                up_line_standard = 8;
                InitStage(hWnd, STAGE_GAME);
            }
            break;
            case BUTTON_MUSIC_ID:
            {
                music_flag = !music_flag;
                InitStage(hWnd, STAGE_DETAILED_SETUP_INTERFACE);
            }
            break;
            case BUTTON_SOUND_ID:
            {
                sound_flag = !sound_flag;
                InitStage(hWnd, STAGE_DETAILED_SETUP_INTERFACE);
            }
            break;
            case BUTTON_STORE_THE_GAME_2_ID:
            {
                file_storage();
                Sleep(300);
                zero_out_all = true;
                ZeroOut();
                InitStage(hWnd, STAGE_START);
            }
            break;
            case BUTTON_NOT_STORE_THE_GAME_2_ID:
            {
                zero_out_all = true;
                ZeroOut();
                InitStage(hWnd, STAGE_START);
            }
            break;
            case BUTTON_MUSIC_ADD_ID:
            {
                if (volume_music < 1000)
                {
                    volume_music += 50;
                    music_flag = true;
                }
                if (music_flag)
                {
                    sprintf(volume_str1, "setaudio background_bgm volume to %d", volume_music);
                    mciSendString(volume_str1, 0, 0, 0);
                }
                InitStage(hWnd, STAGE_DETAILED_SETUP_INTERFACE);
            }
            break;
            case BUTTON_MUSIC_MINUS_ID:
            {
                if (volume_music > 50)
                    volume_music -= 50;
                else if (volume_music == 50)
                {
                    volume_music -= 50;
                    music_flag = false;
                    InitStage(hWnd, STAGE_DETAILED_SETUP_INTERFACE);
                }
                if (music_flag)
                {
                    sprintf(volume_str1, "setaudio background_bgm volume to %d", volume_music);
                    mciSendString(volume_str1, 0, 0, 0);
                }
                InitStage(hWnd, STAGE_DETAILED_SETUP_INTERFACE);
            }
            break;
            case BUTTON_SOUND_ADD_ID:
            {
                if (volume_sound < 1000)
                {
                    volume_sound += 50;
                    sound_flag = true;
                }
                if (sound_flag)
                {
                    sprintf(volume_str2, "setaudio byebye volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio youwin volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio warning volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio whatever volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio oh volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio no volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio cool volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio falldown volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio i_quit volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio not_sure volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio wow volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio good_luck volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio hello volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio boom volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                }
                InitStage(hWnd, STAGE_DETAILED_SETUP_INTERFACE);
            }
            break;
            case BUTTON_SOUND_MINUS_ID:
            {
                if (volume_sound > 50)
                    volume_sound -= 50;
                else if (volume_sound == 50)
                {
                    volume_sound -= 50;
                    sound_flag = false;
                    InitStage(hWnd, STAGE_DETAILED_SETUP_INTERFACE);
                }
                if (sound_flag)
                {
                    sprintf(volume_str2, "setaudio byebye volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio youwin volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio warning volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio whatever volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio oh volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio no volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio cool volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio falldown volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio i_quit volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio not_sure volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio wow volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio good_luck volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio hello volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                    sprintf(volume_str2, "setaudio boom volume to %d", volume_sound);
                    mciSendString(volume_str2, 0, 0, 0);
                }
                InitStage(hWnd, STAGE_DETAILED_SETUP_INTERFACE);
            }
            break;
            // TODO: 其他按钮
            default:
            {
                click_button = false;
            }
            break;
            }
            break;
        }
    }

    //判断绘图过程中是否点击砖块
    if (design_map_flag && design_map_flag_2 && !click_button)
    {
        currentStage->pause = true;
        for (int i = LEFT_LINE + 1; i < RIGHT_LINE; i++)
        {
            for (int j = UP_LINE + 1; j < DOWN_LINE; j++)
            {
                if (mouseX > i * BG_CELL_WIDTH && mouseX <= (i + 1) * BG_CELL_WIDTH && mouseY > j * BG_CELL_HEIGHT && mouseY <= (j + 1) * BG_CELL_HEIGHT)
                {
                    map_base[j][i] = (map_base[j][i] + 1) % 2;
                    if (sound_flag && map_base[j][i] % 2 != 0)
                    {
                        mciSendString("play hello from 0", 0, 0, 0);
                    }
                }
            }
        }
    }
    InvalidateRect(hWnd, NULL, FALSE);
}

// 鼠标左键松开事件处理函数
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    mouseX = LOWORD(lParam);
    mouseY = HIWORD(lParam);
    mouseDown = false;
    click_button = false;
    keyUpDown = false;
    keyDownDown = false;
    keyLeftDown = false;
    keyRightDown = false;
}

// 定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    // 状态更新
    switch (currentStage->stageID)
    {
    case STAGE_START:
        break;
    case STAGE_GAME:
    {
        //UpdateBrick(hWnd);
        UpdateBlock(hWnd);
    }
    break;
    // TODO：添加多个游戏场景
    default:
        break;
    }

    // 刷新显示
    InvalidateRect(hWnd, NULL, FALSE);
}

void PaintUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    if (currentStage->stageID == STAGE_GAME)
    {
        //brick->frame_index = (brick->frame_index + 1) % BRICK_FRAME_SIZE;
        InvalidateRect(hWnd, NULL, FALSE);
    }
}

#pragma endregion

#pragma region 其它游戏状态处理函数

// 初始化游戏场景函数
void InitStage(HWND hWnd, int stageID)
{
    // 开始绘制
    PAINTSTRUCT ps;
    HDC hdc_window = BeginPaint(hWnd, &ps);
    // 创建缓存
    HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
    HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

    // 初始化场景实例
    if (currentStage != NULL)
        delete currentStage;
    currentStage = new Stage();
    currentStage->stageID = stageID;

    switch (stageID)
    {
    case STAGE_START:
    {
        currentStage->bg = bmp_background8;
        currentStage->pause = true;

        // 删除旧的按钮
        for (size_t i = 0; i < buttons.size(); i++)
        {
            Button* button = buttons[i];
            delete button;
            button = nullptr;
        }
        buttons.clear();

        // 添加新的开始按钮
        //开始按钮
        Button* startButton = CreateButton(
            BUTTON_STARTGAME_ID, bmp_StartButton,
            BUTTON_STARTGAME_X, BUTTON_STARTGAME_Y,
            BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT);
        buttons.push_back(startButton);

        //排行榜按钮
        Button* rank_listButton = CreateButton(
            BUTTON_RANKLIST_ID, bmp_beth,
            475, BUTTON_STARTGAME_Y + 400,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(rank_listButton);

        //帮助按钮
        Button* help_meButton = CreateButton(
            BUTTON_HELP_ID, bmp_jerry,
            250, BUTTON_STARTGAME_Y + 400,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(help_meButton);

        //读档按钮
        Button* load_saveButton = CreateButton(
            BUTTON_LOADSAVE_ID, bmp_summer,
            700, BUTTON_STARTGAME_Y + 400,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(load_saveButton);

        //游戏模式按钮
        Button* game_modeButton = CreateButton(
            BUTTON_GAMEMODE_ID, bmp_snowball_white,
            925, BUTTON_STARTGAME_Y + 400,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(game_modeButton);

        //设置按钮
        Button* setupButton = CreateButton(
            BUTTON_SETUP_ID, bmp_Mr_Meeseeks,
            50, 50,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(setupButton);
    }
    break;
    case STAGE_GAME:
    {
        //先判断游戏是否需要设置分数上限
        if (!grade_limit_judgeflag)
        {
            InitStage(hWnd, STAGE_GRADE_LIMIT_SET);
            grade_limit_judgeflag = true;
            break;
        }

        if (design_map_flag && design_map_flag_2)//自定义地图模式
        {
            currentStage->pause = true;
            // 删除旧的按钮
            for (size_t i = 0; i < buttons.size(); i++)
            {
                Button* button = buttons[i];
                delete button;
                button = nullptr;
            }
            buttons.clear();
            //完成按钮
            Button* finishButton = CreateButton(
                BUTTON_FINISHDRAW_ID, bmp_finish_button,
                (RIGHT_LINE + 4) * BG_CELL_WIDTH - BG_CELL_WIDTH / 2, 9 * BG_CELL_HEIGHT,
                BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
            buttons.push_back(finishButton);
            // 删除旧的砖块，创建新的砖块
            if (brick != NULL)
                delete brick;
            brick = nullptr;
            brick = CreateBrick(bmp_Brick);
            currentStage->bg = bmp_GameBackground;
        }
        else if (time_limited_game)//限时模式
        {
            currentStage->pause = true;
            for (size_t i = 0; i < buttons.size(); i++)
            {
                Button* button = buttons[i];
                delete button;
                button = nullptr;
            }
            buttons.clear();
            if (!time_limited_game_begin)
            {
                //开始游戏按钮
                Button* start_timelimitedgameButton = CreateButton(
                    BUTTON_BEGIN_TIMELIMITEDGAME_ID, bmp_start_button,
                    (RIGHT_LINE + 4) * BG_CELL_WIDTH - 60, 10 * BG_CELL_HEIGHT, 180, 66);
                buttons.push_back(start_timelimitedgameButton);
            }
            else
            {
                currentStage->pause = false;
            }
            if (brick != NULL)
                delete brick;
            brick = nullptr;
            brick = CreateBrick(bmp_Brick);
            currentStage->bg = bmp_GameBackground;
        }
        else//其他模式
        {
            currentStage->bg = bmp_GameBackground;
            currentStage->pause = false;
            for (size_t i = 0; i < buttons.size(); i++)
            {
                Button* button = buttons[i];
                delete button;
                button = nullptr;
            }
            buttons.clear();
            // 删除旧的砖块，创建新的砖块
            if (brick != NULL)
                delete brick;
            brick = nullptr;
            brick = CreateBrick(bmp_Brick);
        }

        //画出上下左右键位
        if (!currentStage->pause)
        {
            //上下左右按键
            Button* mouse_upButton = CreateButton(
                BUTTON_MOUSE_UP_ID, bmp_uparrow_button,
                (RIGHT_LINE + 3) * BG_CELL_WIDTH + 25, (19 * BG_CELL_HEIGHT) / 2 - 20,
                BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
            buttons.push_back(mouse_upButton);
            Button* mouse_downButton = CreateButton(
                BUTTON_MOUSE_DOWN_ID, bmp_downarrow_button,
                (RIGHT_LINE + 3) * BG_CELL_WIDTH + 25, (23 * BG_CELL_HEIGHT) / 2,
                BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
            buttons.push_back(mouse_downButton);
            Button* mouse_leftButton = CreateButton(
                BUTTON_MOUSE_LEFT_ID, bmp_leftarrow_button,
                (RIGHT_LINE + 1) * BG_CELL_WIDTH + 2, (23 * BG_CELL_HEIGHT) / 2,
                BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
            buttons.push_back(mouse_leftButton);
            Button* mouse_rightButton = CreateButton(
                BUTTON_MOUSE_RIGHT_ID, bmp_rightarrow_button,
                (RIGHT_LINE + 5) * BG_CELL_WIDTH + 48, (23 * BG_CELL_HEIGHT) / 2,
                BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
            buttons.push_back(mouse_rightButton);
        }
    }
    break;
    case STAGE_RANKLIST:
    {
        currentStage->bg = bmp_background10;
        currentStage->pause = true;

        // 删除旧的按钮
        for (size_t i = 0; i < buttons.size(); i++)
        {
            Button* button = buttons[i];
            delete button;
            button = nullptr;
        }
        buttons.clear();

        // 返回按钮
        Button* backButton = CreateButton(
            BUTTON_BACK_ID, bmp_snowball_white,
            50, 50,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(backButton);

        //上一页面按钮
        Button* lastpageButton = CreateButton(
            BUTTON_LASTPAGE_ID, bmp_lastpage_button,
            100, 425,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(lastpageButton);

        //下一页面按钮
        Button* nextpageButton = CreateButton(
            BUTTON_NEXTPAGE_ID, bmp_nextpage_button,
            1000, 425,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(nextpageButton);

        //重置按钮
        Button* restorageButton = CreateButton(
            BUTTON_RANKLIST_RESTORAGE_ID, bmp_Mr_Meeseeks,
            1050, 50,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(restorageButton);
    }
    break;
    case STAGE_HELP:
    {
        currentStage->bg = bmp_background9;
        currentStage->pause = true;

        for (size_t i = 0; i < buttons.size(); i++)
        {
            Button* button = buttons[i];
            delete button;
            button = nullptr;
        }
        buttons.clear();

        Button* backButton = CreateButton(
            BUTTON_BACK_ID, bmp_snowball_white,
            50, 50,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(backButton);
    }
    break;
    case STAGE_GAME_MODE:
    {
        currentStage->bg = bmp_background11;
        currentStage->pause = true;
        for (size_t i = 0; i < buttons.size(); i++)
        {
            Button* button = buttons[i];
            delete button;
            button = nullptr;
        }
        buttons.clear();
        //盲打模式按钮
        Button* blindgameButton = CreateButton(
            BUTTON_BLINDGAME_ID, bmp_button_200_evilmorty,
            300, 150,
            BUTTON_big_WIDTH, BUTTON_big_HEIGHT);
            buttons.push_back(blindgameButton);
        //自定义地图按钮
        Button* designmapButton = CreateButton(
            BUTTON_DESIGNMAP_ID, bmp_button_200_jerry,
            700, 150,
            BUTTON_big_WIDTH, BUTTON_big_HEIGHT);
            buttons.push_back(designmapButton);
        //娱乐模式按钮
        Button* entertainmentgameButton = CreateButton(
            BUTTON_ENTERTAINMENTGAME_ID, bmp_button_200_rick,
            300, 480,
            BUTTON_big_WIDTH, BUTTON_big_HEIGHT);
            buttons.push_back(entertainmentgameButton);
        //限时模式按钮
        Button* timelimitedButton = CreateButton(
            BUTTON_TIMELIMITEDGAME_ID, bmp_button_200_morty,
            700, 480,
            BUTTON_big_WIDTH, BUTTON_big_HEIGHT);
            buttons.push_back(timelimitedButton);
        //返回按钮
        Button* backButton = CreateButton(
            BUTTON_BACK_ID, bmp_snowball_white,
            50, 50,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
            buttons.push_back(backButton);
    }
    break;
    case STAGE_GAME_OVER_DEFEAT:
    {
        currentStage->bg = bmp_gameover;
        if (sound_flag)
        {
            mciSendString("pause background_bgm", 0, 0, 0);
            mciSendString("play oh from 0", 0, 0, 0);
            Sleep(500);
            mciSendString("play no from 0", 0, 0, 0);
            Sleep(800);
            mciSendString("play whatever from 0", 0, 0, 0);
        }
        for (size_t i = 0; i < buttons.size(); i++)
        {
            Button* button = buttons[i];
            delete button;
            button = nullptr;
        }
        buttons.clear();
        //退出游戏按钮
        Button* exit_Button = CreateButton(
            BUTTON_EXIT_ID, bmp_XIANZHUO,
            310, 450,
            235, 321);
        buttons.push_back(exit_Button);
        //再来一局按钮
        Button* paly_againButton = CreateButton(
            BUTTON_AGAIN_ID, bmp_SHOUYANG,
            653, 450,
            235, 321);
        buttons.push_back(paly_againButton);
        currentStage->pause = true;
    }
    break;
    case STAGE_GAME_OVER_VICTOR:
    {
        currentStage->bg = bmp_win;
        if (sound_flag)
        {
            mciSendString("pause background_bgm", 0, 0, 0);
            mciSendString("play cool from 0", 0, 0, 0);
            Sleep(1000);
            mciSendString("play youwin from 0", 0, 0, 0);
        }
        for (size_t i = 0; i < buttons.size(); i++)
        {
            Button* button = buttons[i];
            delete button;
            button = nullptr;
        }
        buttons.clear();
        //退出游戏按钮
        Button* win_exit_Button = CreateButton(
            BUTTON_EXIT_ID, bmp_win_button,
            160, 450,
            235, 321);
        buttons.push_back(win_exit_Button);
        //再来一局按钮
        Button* paly_againButton = CreateButton(
            BUTTON_AGAIN_ID, bmp_SHOUYANG,
            803, 450,
            235, 321);
        buttons.push_back(paly_againButton);
        currentStage->pause = true;
    }
    break;
    case STAGE_EXIT:
    {
        currentStage->bg = bmp_background8;
        currentStage->pause = true;
        for (size_t i = 0; i < buttons.size(); i++)
        {
            Button* button = buttons[i];
            delete button;
            button = nullptr;
        }
        buttons.clear();
        //yes按钮
        Button* yes_Button = CreateButton(
            BUTTON_YES_ID, bmp_yesbutton,
            750, 450,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(yes_Button);

        //no按钮
        Button* no_Button = CreateButton(
            BUTTON_NO_ID, bmp_nobutton,
            450, 450,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(no_Button);
    }
    break;
    case STAGE_STORE:
    {
        currentStage->bg = bmp_background8;
        currentStage->pause = true;
        for (size_t i = 0; i < buttons.size(); i++)
        {
            Button* button = buttons[i];
            delete button;
            button = nullptr;
        }
        buttons.clear();

        //yes按钮
        Button* yes_store_Button = CreateButton(
            BUTTON_STORE_THE_GAME_ID, bmp_yesbutton,
            750, 450,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(yes_store_Button);

        //no按钮
        Button* no_store_Button = CreateButton(
            BUTTON_NOT_STORE_THE_GAME_ID, bmp_nobutton,
            450, 450,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(no_store_Button);
    }
    break;
    case STAGE_STORE_2:
    {
        currentStage->bg = bmp_background8;
        currentStage->pause = true;
        for (size_t i = 0; i < buttons.size(); i++)
        {
            Button* button = buttons[i];
            delete button;
            button = nullptr;
        }
        buttons.clear();

        //yes按钮
        Button* yes_store_Button = CreateButton(
            BUTTON_STORE_THE_GAME_2_ID, bmp_yesbutton,
            750, 450,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(yes_store_Button);

        //no按钮
        Button* no_store_Button = CreateButton(
            BUTTON_NOT_STORE_THE_GAME_2_ID, bmp_nobutton,
            450, 450,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(no_store_Button);
    }
    break;
    case STAGE_ENTERTAINMENT_INTRODUCTION:
    {
        currentStage->bg = bmp_background8;
        currentStage->pause = true;

        for (size_t i = 0; i < buttons.size(); i++)
        {
            Button* button = buttons[i];
            delete button;
            button = nullptr;
        }
        buttons.clear();

        //准备开始按钮
        Button* readyButton = CreateButton(
            BUTTON_BEGIN_ENTERTAINMENT_ID, bmp_Mr_Meeseeks,
            1000, 45,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(readyButton);
    }
    break;
    case STAGE_SETUP_INTERFACE:
    {
        currentStage->bg = bmp_background10;
        currentStage->pause = true;

        for (size_t i = 0; i < buttons.size(); i++)
        {
            Button* button = buttons[i];
            delete button;
            button = nullptr;
        }
        buttons.clear();
        //退出游戏按钮
        Button* escButton = CreateButton(
            BUTTON_EXIT_ID, bmp_math_teacher,
            475, BUTTON_STARTGAME_Y + 400,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(escButton);

        //返回游戏按钮
        Button* continueButton = CreateButton(
            BUTTON_CONTINUE_ID, bmp_jessica,
            250, BUTTON_STARTGAME_Y + 400,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(continueButton);

        //重新游戏按钮
        Button* restartButton = CreateButton(
            BUTTON_RESTART_THE_GAME_ID, bmp_dreaming_jerry,
            700, BUTTON_STARTGAME_Y + 400,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(restartButton);//怎么样保证重新开始的时候，模式不会变

        //回到初始界面按钮
        Button* back_to_beginButton = CreateButton(
            BUTTON_BACK_TO_BEGINPAGE_ID, bmp_president,
            925, BUTTON_STARTGAME_Y + 400,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(back_to_beginButton);

        //详细设置按钮
        Button* detailed_setupButton = CreateButton(
            BUTTON_DETAILED_SETUP_ID, bmp_MoreDetailButton,
            BUTTON_STARTGAME_X-115, BUTTON_STARTGAME_Y -25,
            529, 300);
        buttons.push_back(detailed_setupButton);
    }
    break;
    case STAGE_MAP_KEEP:
    {
        currentStage->bg = bmp_background11;
        currentStage->pause = true;
        for (size_t i = 0; i < buttons.size(); i++)
        {
            Button* button = buttons[i];
            delete button;
            button = nullptr;
        }
        buttons.clear();

        //yes按钮
        Button* keep_Button = CreateButton(
            BUTTON_KEEP_THE_MAP_ID, bmp_yesbutton,
            750, 450,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(keep_Button);
        //no按钮
        Button* not_keep_Button = CreateButton(
            BUTTON_NOT_KEEP_THE_MAP_ID, bmp_nobutton,
            400, 450,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(not_keep_Button);
    }
    break;
    case STAGE_GRADE_LIMIT_SET:
    {
        currentStage->bg = bmp_background10;
        currentStage->pause = true;
        if (!grade_limit_setting)
        {
            for (size_t i = 0; i < buttons.size(); i++)
            {
                Button* button = buttons[i];
                delete button;
                button = nullptr;
            }
            buttons.clear();

            //yes按钮
            Button* yes_Button = CreateButton(
                BUTTON_SET_GRADE_LIMIT_ID, bmp_yesbutton,
                750, 450,
                BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
            buttons.push_back(yes_Button);

            //no按钮
            Button* no_Button = CreateButton(
                BUTTON_NOT_SET_GRADE_LIMIT_ID, bmp_nobutton,
                350, 450,
                BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
            buttons.push_back(no_Button);
        }
        else
        {
            for (size_t i = 0; i < buttons.size(); i++)
            {
                Button* button = buttons[i];
                delete button;
                button = nullptr;
            }
            buttons.clear();
            
            //＋按钮
            Button* add_Button = CreateButton(
                BUTTON_ADD_GRADE_ID, bmp_button_200_rick,
                750, 400,
                200, 200);
            buttons.push_back(add_Button);

            //-按钮
            Button* minus_Button = CreateButton(
                BUTTON_MINUS_GRADE_ID, bmp_button_200_evilmorty,
                250, 400,
                200, 200);
            buttons.push_back(minus_Button);

            //确认按钮
            Button* comfirm_Button = CreateButton(
                BUTTON_GRADE_LIMIT_DEFINE_ID, bmp_Mr_Meeseeks,
                1000, 100,
                100, 100);
            buttons.push_back(comfirm_Button);
        }
    }
    break;
    case STAGE_DETAILED_SETUP_INTERFACE:
    {
        currentStage->bg = bmp_background8;
        currentStage->pause = true;
        for (size_t i = 0; i < buttons.size(); i++)
        {
            Button* button = buttons[i];
            delete button;
            button = nullptr;
        }
        buttons.clear();
        //返回上一界面按钮
        Button* backButton = CreateButton(
            BUTTON_BACK_TO_SETUP_ID, bmp_snowball_white,
            50, 50,
            BUTTON_small_WIDTH, BUTTON_small_HEIGHT);
        buttons.push_back(backButton);
        //超慢速按钮
        Button* slowestButton = CreateButton(
            BUTTON_SLOWEST_SPEED_ID, bmp_button_150_jerry,250, 125, 150, 150);
        buttons.push_back(slowestButton);
        //慢速按钮
        Button* slowButton = CreateButton(
            BUTTON_SLOW_SPEED_ID, bmp_button_150_morty, 500, 125, 150, 150);
        buttons.push_back(slowButton);
        //中速按钮
        Button* mediumButton = CreateButton(
            BUTTON_MEDIUM_SPEED_ID, bmp_button_150_evilmorty, 750, 125, 150, 150);
        buttons.push_back(mediumButton);
        //快速按钮
        Button* quickButton = CreateButton(
            BUTTON_QUICK_SPEED_ID, bmp_button_150_rick, 990, 125, 150, 150);
        buttons.push_back(quickButton);
        //简单按钮
        Button* easyButton = CreateButton(
            BUTTON_EASY_GAME_ID, bmp_button_150_dreaming_jerry, 375, 350, 150, 150);
        buttons.push_back(easyButton);
        //正常按钮
        Button* normalButton = CreateButton(
            BUTTON_NORMAL_GAME_ID, bmp_button_150_jessica, 625, 350, 150, 150);
        buttons.push_back(normalButton);
        //困难按钮
        Button* hardButton = CreateButton(
            BUTTON_HARD_GAME_ID, bmp_button_150_Mr_Meeseeks, 875, 350, 150, 150);
        buttons.push_back(hardButton);
        //音乐开关按钮
        if (music_flag)
        {
            mciSendString("resume background_bgm", 0, 0, 0);
            Button* musicButton = CreateButton(
                BUTTON_MUSIC_ID, bmp_jerry, 300, 540, 100, 100);
            buttons.push_back(musicButton);
        }
        else
        {
            mciSendString("pause background_bgm", 0, 0, 0);
            Button* musicButton = CreateButton(
                BUTTON_MUSIC_ID, bmp_button_black_jerry, 300, 540, 100, 100);
            buttons.push_back(musicButton);
        }
        //音效开关按钮
        if (sound_flag)
        {
            Button* soundButton = CreateButton(
                BUTTON_SOUND_ID, bmp_beth, 750, 540, 100, 100);
            buttons.push_back(soundButton);
        }
        else
        {
            Button* soundButton = CreateButton(
                BUTTON_SOUND_ID, bmp_button_black_beth, 750, 540, 100, 100);
            buttons.push_back(soundButton);
        }
        //音乐音量“+”开关按钮
        Button* musicaddButton = CreateButton(
            BUTTON_MUSIC_ADD_ID, bmp_add_50bmp, 250, 685, 89, 50);
        buttons.push_back(musicaddButton);
        //音乐音量“-”开关按钮
        Button* musicminusButton = CreateButton(
            BUTTON_MUSIC_MINUS_ID, bmp_minus_50bmp, 500, 685, 84, 50);
        buttons.push_back(musicminusButton);
        //音效音量“+”开关按钮
        Button* soundaddButton = CreateButton(
            BUTTON_SOUND_ADD_ID, bmp_add_50bmp, 850, 685, 89, 50);
        buttons.push_back(soundaddButton);
        //音效音量“-”开关按钮
        Button* soundminusButton = CreateButton(
            BUTTON_SOUND_MINUS_ID, bmp_minus_50bmp, 1100, 685, 84, 50);
        buttons.push_back(soundminusButton);
    }
    break;
    case STAGE_BILNDGAME_START:
    {
        currentStage->bg = bmp_background8;
        currentStage->pause = true;
        for (size_t i = 0; i < buttons.size(); i++)
        {
            Button* button = buttons[i];
            delete button;
            button = nullptr;
        }
        buttons.clear();

        //开始按钮
        Button* start_blindgameButton = CreateButton(
            BUTTON_BEGIN_BLINDGAME_ID, bmp_start_button,
            510, 8 * BG_CELL_HEIGHT+30, 180, 66);
        buttons.push_back(start_blindgameButton);
    }
    break;
    case STAGE_MAPDESIGNGAME_START:
    {
        currentStage->bg = bmp_background8;
        currentStage->pause = true;
        for (size_t i = 0; i < buttons.size(); i++)
        {
            Button* button = buttons[i];
            delete button;
            button = nullptr;
        }
        buttons.clear();
        //开始按钮
        Button* start_mapdesigngameButton = CreateButton(
            BUTTON_BEGIN_MAPDESIGNGAME_ID, bmp_start_button,
            510, 8 * BG_CELL_HEIGHT + 30, 180, 66);
        buttons.push_back(start_mapdesigngameButton);
    }
    break;
    case STAGE_TIMELIMITEDGAME_START:
    {
        currentStage->bg = bmp_background8;
        currentStage->pause = true;
        for (size_t i = 0; i < buttons.size(); i++)
        {
            Button* button = buttons[i];
            delete button;
            button = nullptr;
        }
        buttons.clear();
        //开始按钮
        Button* start_timelimitedgameButton = CreateButton(
            BUTTON_BEGIN_TIME_LIMITEDGAME_ID, bmp_start_button,
            510, 8 * BG_CELL_HEIGHT + 30, 180, 66);
        buttons.push_back(start_timelimitedgameButton);
    }
    break;
    // TODO：添加多个游戏场景
    default:
        break;
    }

    // 刷新显示
    InvalidateRect(hWnd, NULL, FALSE);
}

// 添加按钮函数
Button* CreateButton(int buttonID, HBITMAP img, int x, int y, int width, int height)
{
    Button* button = new Button();
    button->buttonID = buttonID;
    button->img = img;
    button->x = x;
    button->y = y;
    button->width = width;
    button->height = height;
    return button;
}

//添加砖块函数
Brick* CreateBrick(HBITMAP img)
{
    Brick* brick = new Brick();
    brick->img = img;
    brick->frame_index = 0;
    brick->cell_x = BRICK_COLUMNS / 2;
    brick->cell_y = BRICK_ROWS / 2;
    return brick;
}

//添加俄罗斯方块函数
Block* CreateBlock(HBITMAP img, int type,int shape_id)
{
    next_step = true;
    Block* b = nullptr;
    b = new Block();
    int sort = generateRandomNumber3();
    if (entertainmentgame_flag)
    {
        if (b != nullptr && sort == 10)
            b->property = 1;//1代表消行砖块
        else if (b != nullptr && sort == 9)
            b->property = 2;//2代表消列砖块
        else if (b != nullptr && sort == 8)
            b->property = 3;//3代表添乱砖块
        else if (b != nullptr && sort == 7)
            b->property = 4;//4代表添镜像块
        else if (b != nullptr && sort != 7 && sort != 8 && sort != 9 && sort != 10)
            b->property = 0;//0代表普通砖块
    }
    else
    {
        b->property = 0;//0代表普通砖块
    }

    if (type == 1)//蓝色瑞克 7456
    {
        b->img = img;
        b->x = generateRandomNumber2();
        b->y = 1;
        b->shape_id = shape_id;
        b->shape_type = 1;
        memcpy(b->shape, shape_Blue_Ricky[b->shape_id], sizeof(b->shape));
    }
    else if (type == 2)//橘色瑞克 4569
    {
        b->img = img;
        b->x = generateRandomNumber2();
        b->y = 1;
        b->shape_id = shape_id;
        b->shape_type = 2;
        memcpy(b->shape, shape_Orange_Ricky[b->shape_id], sizeof(b->shape));
    }
    else if (type == 3)//罗德岛Z 4589
    {
        b->img = img;
        b->x = generateRandomNumber2();
        b->y = 1;
        b->shape_id = shape_id;
        b->shape_type = 3;
        memcpy(b->shape, shape_Rhode_Island_Z[b->shape_id], sizeof(b->shape));
    }
    else if (type == 4)//克利夫兰Z 7856
    {
        b->img = img;
        b->x = generateRandomNumber2();
        b->y = 1;
        b->shape_id = shape_id;
        b->shape_type = 4;
        memcpy(b->shape, shape_Cleveland_Z[b->shape_id], sizeof(b->shape));
    }
    else if (type == 5)//英雄 7410
    {
        b->img = img;
        b->x = generateRandomNumber2();
        if (b->x >= 12)
            b->x--;
        b->y = 1;
        b->shape_id = shape_id;
        b->shape_type = 5;
        memcpy(b->shape, shape_Hero[b->shape_id], sizeof(b->shape));
    }
    else if (type == 6)//小T 4568
    {
        b->img = img;
        b->x = generateRandomNumber2();
        b->y = 1;
        b->shape_id = shape_id;
        b->shape_type = 6;
        memcpy(b->shape, shape_Teewee[b->shape_id], sizeof(b->shape));
    }
    else if (type == 7)//粉碎男孩 7845
    {
        b->img = img;
        b->x = generateRandomNumber2();
        b->y = 1;
        b->shape_id = shape_id;
        b->shape_type = 7;
        memcpy(b->shape, shape_Smashboy[b->shape_id], sizeof(b->shape));
    }

    if (b->property == 1)
    {
        b->img = bmp_jerry_small;
    }
    else if (b->property == 2)
    {
        b->img = bmp_beth_small;
    }
    else if (b->property == 3)
    {
        b->img = bmp_math_teacher_small;
    }
    else if (b->property == 4)
    {
        b->img = bmp_president_small;
    }
    return b;
}

//添加预测方块函数
Block* CreatePredictBlock(HBITMAP img, int type, int shape_id)
{
    Block* b = new Block();
    b->img = bmp_block_predict;
    b->x = RIGHT_LINE + 3;
    b->y = UP_LINE - 2;
    b->shape_type = type;
    if (type == 1)//蓝色瑞克 7456
    {
        b->shape_id = shape_id;
        memcpy(b->shape, shape_Blue_Ricky[b->shape_id], sizeof(b->shape));
    }
    else if (type == 2)//橘色瑞克 4569
    {
        b->shape_id = shape_id;
        memcpy(b->shape, shape_Orange_Ricky[b->shape_id], sizeof(b->shape));
    }
    else if (type == 3)//罗德岛Z 4589
    {
        b->shape_id = shape_id;
        memcpy(b->shape, shape_Rhode_Island_Z[b->shape_id], sizeof(b->shape));
    }
    else if (type == 4)//克利夫兰Z 7856
    {
        b->shape_id = shape_id;
        memcpy(b->shape, shape_Cleveland_Z[b->shape_id], sizeof(b->shape));
    }
    else if (type == 5)//英雄 7410
    {
        b->shape_id = shape_id;
        memcpy(b->shape, shape_Hero[b->shape_id], sizeof(b->shape));
    }
    else if (type == 6)//小T 4568
    {
        b->shape_id = shape_id;
        memcpy(b->shape, shape_Teewee[b->shape_id], sizeof(b->shape));
    }
    else if (type == 7)//粉碎男孩 7845
    {
        b->shape_id = shape_id;
        memcpy(b->shape, shape_Smashboy[b->shape_id], sizeof(b->shape));
    }
    return b;
}

//生成随机数，实现随机生成俄罗斯方块
int generateRandomNumber1()
{
    srand((unsigned int)time(NULL));
    return (rand() % 7 + 1);
}

//生成随机数，实现俄罗斯方块生成位置随机
int generateRandomNumber2()
{
    srand((unsigned int)time(NULL));
    return (rand() % 12 + 1);
}

//生成随机数，实现生成四种特殊砖块，概率为1/15
int generateRandomNumber3()
{
    srand((unsigned int)time(NULL));
    return (rand() % 15 + 1);
}

//生成随机数，实现俄罗斯方块初始方向随机
int generateRandomNumber4()
{
    srand((unsigned int)time(NULL));
    return (rand() % 4);
}

//方块碰撞检测函数
void BlockCollideDetect()
{
    //初始化方块边界（后续判断使用
    for (int i = 0; i < 16; i++)
    {
        base_all[i][0] = 1;
        base_all[i][BG_COLUMNS - 1] = 1;
        base_all[i][BG_COLUMNS - 9] = 1;
        base_all[i][BG_COLUMNS - 8] = 1;
        base_all[i][BG_COLUMNS] = 1;
        base_all[i][BG_COLUMNS+1] = 1;
    }
    for (int i = 0; i < 24; i++)
    {
        base_all[BG_ROWS-1][i] = 1;
        base_all[BG_ROWS][i] = 1;
        base_all[BG_ROWS+1][i] = 1;
    }
    DesignMap();

    int cur_x, cur_y;
    //先遍历block内的brick
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (block->shape[y][x] == 1)
            {
                cur_x = block->x + x;
                cur_y = block->y + y;
                if (cur_x == 14)
                    right_out_possible_flag = true;
                if (base_all[cur_y][cur_x - 1] == 1)
                    leftflag = false;
                if (base_all[cur_y][cur_x + 1] == 1)
                    rightflag = false;
                if (base_all[cur_y + 1][cur_x] == 1)
                {
                    next_step = false;
                    downflag = false;
                    blindgame_not_draw = true;
                    return;
                }
            }
        }
    }
}

//判断是否可以旋转
void REVOLVE()
{
    if (type != 5 && type != 7)
    {
        int revolve[30][30] = {};
        revolve[block->y][block->x] = base_all[block->y + 2][block->x];
        revolve[block->y + 2][block->x] = base_all[block->y + 2][block->x + 2];
        revolve[block->y + 2][block->x + 2] = base_all[block->y][block->x + 2];
        revolve[block->y][block->x + 2] = base_all[block->y][block->x];
        revolve[block->y][block->x + 1] = base_all[block->y + 1][block->x];
        revolve[block->y + 1][block->x] = base_all[block->y + 2][block->x + 1];
        revolve[block->y + 2][block->x + 1] = base_all[block->y + 1][block->x + 2];
        revolve[block->y + 1][block->x + 2] = base_all[block->y][block->x + 1];
        for (int x = 0; x < 24; x++)
        {
            for (int y = 0; y < 16; y++)
            {
                if (revolve[y][x] == 1 && base_all[y][x] == 1)
                    upflag = false;
            }
        }
    }
    else if (type == 5)
    {
        if (block->shape_id == 0 || block->shape_id == 2)
        {
            if (base_all[block->y + 1][block->x] == 1 || base_all[block->y + 1][block->x + 2] == 1 || base_all[block->y + 1][block->x + 3] == 1)
            {
                upflag = false;
            }
        }
        else
        {
            if (base_all[block->y][block->x + 1] == 1 || base_all[block->y + 2][block->x + 1] == 1 || base_all[block->y + 3][block->x + 1] == 1)
            {
                upflag = false;
            }
        }
    }
}

//下边碰撞检测
void BlockBottomCollideDetect()
{
    //初始化方块边界（后续判断使用)
    for (int i = 0; i < 16; i++)
    {
        base_all[i][0] = 1;
        base_all[i][BG_COLUMNS - 1] = 1;
        base_all[i][BG_COLUMNS] = 1;
        base_all[i][BG_COLUMNS+1] = 1;
        base_all[i][BG_COLUMNS - 9] = 1;
        base_all[i][BG_COLUMNS - 8] = 1;
    }
    for (int i = 0; i < 24; i++)
    {
        base_all[BG_ROWS-1][i] = 1;
        base_all[BG_ROWS][i] = 1;
        base_all[BG_ROWS+1][i] = 1;
    }
    DesignMap();

    //先遍历block内的brick
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (block != nullptr && block->shape[y][x] == 1)
            {
                int cur_x = block->x + x;
                int cur_y = block->y + y;
                if (cur_x == 14)
                    right_out_possible_flag = true;
                if (base_all[cur_y + 1][cur_x] == 1)
                {
                    next_step = false;
                    downflag = false;
                    blindgame_not_draw = true;
                    return;
                }
            }
        }
    }
}

//方块状态更新函数
void UpdateBlock(HWND hWnd)
{
    if (GameOver())
    {
        if (!grade_storage)
        {
            ranklist_storage();
            grade_storage = true;
        }
        if (!win_or_defeat)
        {
            if (mouseDown)
            {
                Sleep(500);
                InitStage(hWnd, STAGE_GAME_OVER_DEFEAT);
            }
        }
        else
        {
            if (mouseDown)
            {
                Sleep(500);
                InitStage(hWnd, STAGE_GAME_OVER_VICTOR);
            }
        }
        return;
    }
    upflag = true;
    downflag = true;
    leftflag = true;
    rightflag = true;
    right_out_possible_flag = false;

    // 位置更新
    if (!GameOver() && block == nullptr)
    {
        if (type_next == 0)
            type_next = generateRandomNumber1();
        type = type_next;
        type_next = generateRandomNumber1();
        if(shape_next_original_id ==-1)
            shape_next_original_id = generateRandomNumber4();
        shape_original_id = shape_next_original_id;
        shape_next_original_id = generateRandomNumber4();

        block = CreateBlock(bmp_rick_small, type, shape_original_id);
        block_shadow = CreateBlock(block->img, type, shape_original_id);
        block_next = CreatePredictBlock(bmp_block_predict, type_next, shape_next_original_id);
        return;
    }

    //实现自动下落
    BlockBottomCollideDetect();
    if (block!=nullptr&&++Cnt_fall >= Cnt_fall_standard && downflag&&!keyDownDown)
    {
        block->y++;
        Cnt_fall = 0;
    }

    //碰撞检测
    if (block != nullptr)
    {      
        //实现俄罗斯方块转换方向
        if (keyUpDown)
        {
            REVOLVE();
            if (upflag)
            {
                block->shape_id = (block->shape_id + 1) % 4;
                block_shadow->shape_id = block->shape_id;
                if (type == 1)
                {
                    memcpy(block->shape, shape_Blue_Ricky[block->shape_id], sizeof(block->shape));
                    memcpy(block_shadow->shape, shape_Blue_Ricky[block_shadow->shape_id], sizeof(block_shadow->shape));
                }
                else if (type == 2)
                {
                    memcpy(block->shape, shape_Orange_Ricky[block->shape_id], sizeof(block->shape));
                    memcpy(block_shadow->shape, shape_Orange_Ricky[block_shadow->shape_id], sizeof(block_shadow->shape));
                }
                else if (type == 3)
                {
                    memcpy(block->shape, shape_Rhode_Island_Z[block->shape_id], sizeof(block->shape));
                    memcpy(block_shadow->shape, shape_Rhode_Island_Z[block_shadow->shape_id], sizeof(block_shadow->shape));
                }
                else if (type == 4)
                {
                    memcpy(block->shape, shape_Cleveland_Z[block->shape_id], sizeof(block->shape));
                    memcpy(block_shadow->shape, shape_Cleveland_Z[block_shadow->shape_id], sizeof(block_shadow->shape));
                }
                else if (type == 5)
                {
                    memcpy(block->shape, shape_Hero[block->shape_id], sizeof(block->shape));
                    memcpy(block_shadow->shape, shape_Hero[block_shadow->shape_id], sizeof(block_shadow->shape));
                }
                else if (type == 6)
                {
                    memcpy(block->shape, shape_Teewee[block->shape_id], sizeof(block->shape));
                    memcpy(block_shadow->shape, shape_Teewee[block_shadow->shape_id], sizeof(block_shadow->shape));
                }
                else if (type == 7)
                {
                    memcpy(block->shape, shape_Smashboy[block->shape_id], sizeof(block->shape));
                    memcpy(block_shadow->shape, shape_Smashboy[block_shadow->shape_id], sizeof(block_shadow->shape));
                }
                upflag = false;
                keyUpDown = false;
            }
        }

        //影子投影
        Reflect();

        if (keyLeftDown)
        {
            BlockCollideDetect();
            if (leftflag)
            {
                    block->x--;
            }
            keyLeftDown = false;
        }
        if (keyRightDown)
        {
            BlockCollideDetect();
            if (rightflag&&!right_out_possible_flag)
            {
                    block->x++;
            }
            keyRightDown = false;
        }
        if (keyDownDown)
        {
            BlockBottomCollideDetect();
            if (downflag == true)
            {
                block->y++;
            }
            keyDownDown = false;
        }
        if (keyEsc)
        {
            InitStage(hWnd, STAGE_SETUP_INTERFACE);
            keyEsc = false;
        }
    }

    if (!downflag)
    {
        if (block->property == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (block->shape[i][j] == 1)
                    {
                        int cur_x = block->x + j;
                        int cur_y = block->y + i;
                        Brick* b = CreateBrick(bmp_morty_small);
                        b->cell_x = cur_x;
                        b->cell_y = cur_y;
                        b->img_id = IDB_character3;
                        b->property = 0;
                        base_all[cur_y][cur_x] = 1;
                        base.push_back(b);
                    }
                }
            }
            if (sound_flag)
            {
                mciSendString("play falldown from 0", 0, 0, 0);
            }
        }
        else if (block->property == 1)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (block->shape[j][i] == 1)
                    {
                        int cur_y = block->y + j;
                        for (int i = LEFT_LINE + 1; i < RIGHT_LINE; i++)
                        {
                            base_all[cur_y][i] = 0;
                        }
                        for (int m = 0; m < base.size(); m++)
                        {
                            if (base[m] != nullptr && base[m]->cell_y == cur_y)
                            {
                                delete base[m];
                                base[m] = nullptr;
                            }
                        }
                        break;
                    }
                }
            }
            if (sound_flag)
            {
                mciSendString("play falldown from 0", 0, 0, 0);
            }
        }
        else if (block->property == 2)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (block->shape[i][j] == 1)
                    {
                        int cur_x = block->x + j;
                        for (int i = UP_LINE + 1; i < DOWN_LINE; i++)
                        {
                            base_all[i][cur_x] = 0;
                        }
                        for (int m = 0; m < base.size(); m++)
                        {
                            if (base[m] != nullptr && base[m]->cell_x == cur_x)
                            {
                                delete base[m];
                                base[m] = nullptr;
                            }
                        }
                        break;
                    }
                }
            }
            if (sound_flag)
            {
                mciSendString("play falldown from 0", 0, 0, 0);
            }
        }
        else if (block->property == 3)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (block->shape[i][j] == 1)
                    {
                        int cur_x = block->x + j;
                        for (int i = UP_LINE + 3; i < DOWN_LINE-1; i++)
                        {
                            base_all[i][cur_x] = 1;
                            Brick* b = CreateBrick(bmp_morty_small);
                            b->cell_x = cur_x;
                            b->cell_y = i;
                            b->img_id = IDB_character3;
                            b->property = 0;
                            base.push_back(b);
                        }
                        break;
                    }
                }
            }
            if (sound_flag)
            {
                mciSendString("play falldown from 0", 0, 0, 0);
            }
        }
        else if (block->property == 4)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (block->shape[i][j] == 1)
                    {
                        int cur_x = block->x + j;
                        int cur_y = block->y + i;
                        Brick* b = CreateBrick(bmp_morty_small);
                        b->cell_x = cur_x;
                        b->cell_y = cur_y;
                        b->img_id = IDB_character3;
                        b->property = 0;
                        base_all[cur_y][cur_x] = 1;
                        base.push_back(b);
                    }
                }
            }
            if (sound_flag)
            {
                mciSendString("play falldown from 0", 0, 0, 0);
            }
            for (int i = LEFT_LINE + 1; i <= (RIGHT_LINE)/2; i++)
            {
                for (int j = UP_LINE + 1; j < DOWN_LINE - 1; j++)
                {
                        int tem = base_all[j][i];
                        base_all[j][i] = base_all[j][RIGHT_LINE - i];
                        base_all[j][RIGHT_LINE - i] = tem;
                }
                for (int k = 0; k < base.size(); k++)
                {
                    if (base[k] != nullptr && base[k]->cell_x == i&& base[k]->mirror_chage != 1)
                    {
                        base[k]->cell_x = RIGHT_LINE - i;
                        base[k]->mirror_chage = 1;
                    }
                    else if (base[k] != nullptr && base[k]->cell_x == RIGHT_LINE - i&& base[k]->mirror_chage != 1)
                    {
                        base[k]->cell_x = i;
                        base[k]->mirror_chage = 1;
                    }
                }
            }
            for (int k = 0; k < base.size(); k++)
            {
                if(base[k]!=nullptr)
                base[k]->mirror_chage = 0;
            }
            Reflect();
            InvalidateRect(hWnd, NULL, FALSE);
            Reflect();
        }
        delete block;
        delete block_shadow;
        block = nullptr;
        block_shadow = nullptr;
    }
    DetectRow();

    //逼近上线警报判断
    for (int i = 0; i < base.size(); i++)
    {
        if (base[i] != nullptr && base[i]->cell_x > LEFT_LINE && base[i]->cell_x < RIGHT_LINE && base[i]->cell_y == up_line_standard + 1)
        {
            if (sound_flag && warning_flag)
            {
                mciSendString("play warning from 0", 0, 0, 0);
                warning_flag = false;
            }
        }
    }
}

//方块投影函数
void Reflect()
{
    int k = 0;
    int cur_x, cur_y;
    int block_shadow_y = DOWN_LINE - 2;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            bool shadow = false;
            if (block->shape[y][x] == 1)
            {
                cur_x = block->x + x;
                cur_y = block->y + y;
                for (k = cur_y; k < DOWN_LINE; k++)
                {
                    if (base_all[k][cur_x] == 1)
                    {
                        bool shadow = true;
                        if (block_shadow_y > k - 1 - y)
                        {
                            block_shadow_y = k - 1 - y;
                        }
                        break;
                    }
                    if (shadow)
                        break;
                }
            }
        }
    }
    block_shadow->y = block_shadow_y ;
    block_shadow->x = block->x ;
}

//消行检测执行函数
void DetectRow()
{
    delete_the_row = false;
    int sum = 0, ii = 0;
    int grade_one = 0;
    times = 0;

    for (int i = DOWN_LINE - 2; i > UP_LINE; )//行从下往上
    {
        int test[30] = {};
        sum = 0;
        for (int j = LEFT_LINE + 1; j < RIGHT_LINE; j++)//列从左往右
        {
            if (base_all[i][j] != 1)
                break;
            sum++;
        }
        if (sum == RIGHT_LINE - LEFT_LINE - 1)
        {
            delete_the_row = true;
            times++;
        }
        //触发消行
        if (delete_the_row)
        {
            for (int k = LEFT_LINE + 1; k < RIGHT_LINE; k++)
            {
                if (map_base[i][k] == 1)
                    test[k] = 1;
            }
            if (sound_flag)
                mciSendString("play boom from 0", 0, 0, 0);
            for (int m = 0; m < base.size(); m++)
            {
                if (base[m] != nullptr && base[m]->cell_y == i && test[base[m]->cell_x] != 1)
                {
                    delete base[m];
                    base[m] = nullptr;
                }
                if (base[m] != nullptr && base[m]->cell_y < i && test[base[m]->cell_x] != 1)
                {
                    base[m]->cell_y++;
                }
            }
            for (int k = LEFT_LINE + 1; k < RIGHT_LINE; k++)
            {
                if (test[k] != 1)
                    base_all[i][k] = 0;
            }
            for (int j = i - 1; j > UP_LINE; j--)
            {
                for (int n = LEFT_LINE + 1; n < RIGHT_LINE; n++)
                {
                    if (test[n] != 1)
                    {
                        base_all[j + 1][n] = base_all[j][n];
                        base_all[j][n] = 0;
                    }
                }
            }
            delete_the_row = false;
        }
        else
            i--;
    }
    //计算分数
    for (int time_x = 1; time_x <= times; time_x++)
    {
        grade_one = grade_one * 2 + 10;
    }
    grade = grade + grade_one;
    return;
}

//判断游戏是否结束
int GameOver()
{
    //限时模式结束判断
    if (time_limited_game && countdown == 1)
    {
        win_or_defeat = true;
        return 1;
    }
    for (int i = 0; i < base.size(); i++)
    {
        //碰上线结束判断
        if (base[i] != nullptr && base[i]->cell_x > LEFT_LINE && base[i]->cell_x < RIGHT_LINE && base[i]->cell_y <= up_line_standard)
        {
            win_or_defeat = false;
            return 1;
        }
        //部分模式分数结束判断
        else if (!time_limited_game && grade_limit_setting && grade >= grade_limit)
        {
            win_or_defeat = true;
            return 1;
        }
    }
    return 0;
}

//游戏清零
void ZeroOut()
{
    type_next = 0;
    shape_next_original_id= -1;
    grade = 0;
    countdown = 181;
    leftflag = false;
    rightflag = false;
    upflag = false;
    downflag = false;
    next_step = true;
    delete_the_row = false;
    win_or_defeat = false;
    sneer = false;
    key_updateflag = true;
    time_limited_game_begin = false;
    file_loading_flag = false;
    warning_flag = true;

    //游戏模式是否更改
    if (zero_out_all)
    {
        click_button = false;
        blindgame_open = false;
        blindgame_not_draw = false;
        design_map_flag_2 = false;
        design_map_keep_flag = false;
        entertainmentgame_flag = false;
        time_limited_game = false;
        grade_limit_judgeflag = false;
        grade_limit_setting = false;
        zero_out_all = false;
        Cnt_fall_standard = 10;
    }
    //确保自定义地图游戏模式不变
    if (design_map_flag_2)
    {
        design_map_flag = true;
    }
    //删除砖块
    for (int m = 0; m < base.size(); m++)
    {
        delete base[m];
        base[m] = nullptr;
    }
    for (int j = 1; j < DOWN_LINE - 1; j++)
    {
        for (int i = LEFT_LINE + 1; i < RIGHT_LINE; i++)
        {
            base_all[j][i] = 0;
            if (!design_map_keep_flag)
                map_base[j][i] = 0;
        }
    }
    delete block;
    delete block_shadow;
    delete block_next;
    block = nullptr;
    block_shadow = nullptr;
    block_next = nullptr;
    return;
}

//文件存档
void file_storage()
{
    FILE* fp1 = nullptr, * fp2 = nullptr, * fp3 = nullptr;
    fp1 = fopen("lastgame_grade.txt", "w");
    fp2 = fopen("lastgame_block.txt", "w");
    fp3 = fopen("lastgame_bool.txt", "w");
    int base_size = 0;
    //保存重要数据
    fprintf(fp1, "%d\n", grade);
    fprintf(fp1, "%d\n", type_next);
    fprintf(fp1, "%d\n", shape_next_original_id);
    fprintf(fp1, "%d\n", countdown);
    fprintf(fp1, "%d\n", Cnt_fall_standard);
    fprintf(fp1, "%d\n", difficulty_level);
    fprintf(fp1, "%d\n", grade_limit);
    for (int i = 0; i < base.size(); i++)
    {
        if (base[i] != nullptr)
            base_size++;
    }
    fprintf(fp1, "%d\n", base_size);

    //保存砖块数据
    for (int j = UP_LINE; j <= DOWN_LINE - 1; j++)
    {
        for (int i = LEFT_LINE; i <= RIGHT_LINE; i++)
        {
            fprintf(fp2, "%d ", base_all[j][i]);
            fprintf(fp2, "%d ", map_base[j][i]);
        }
        fprintf(fp2, "\n");
    }
    for (int i = 0; i < base.size(); i++)
    {
        if (base[i] != nullptr)
        {
            fprintf(fp2, "%d ", base[i]->cell_x);
            fprintf(fp2, "%d ", base[i]->cell_y);
            fprintf(fp2, "%d ", base[i]->img_id);
            fprintf(fp2, "%d\n", base[i]->property);
        }
    }
    if (block != nullptr)
    {
        //娱乐模式（砖块有多种图案）
        if (entertainmentgame_flag)
        {
            if (block->property == 1)
                fprintf(fp2, "%d ", IDB_character2);
            else if (block->property == 2)
                fprintf(fp2, "%d ", IDB_character1);
            else if (block->property == 3)
                fprintf(fp2, "%d ", IDB_character8);
            else if (block->property == 4)
                fprintf(fp2, "%d ", IDB_character10);
            else
                fprintf(fp2, "%d ", IDB_character4);
        }
        //其他模式（砖块都是rick）
        else
            fprintf(fp2, "%d ", IDB_character4);

        fprintf(fp2, "%d ", block->shape_id);
        fprintf(fp2, "%d ", block->shape_type);
        fprintf(fp2, "%d ", block->x);
        fprintf(fp2, "%d ", block->y);
        fprintf(fp2, "%d\n", block->property);
    }
    if (block_shadow != nullptr)
    {
        if (entertainmentgame_flag)
        {
            if (block->property == 1)
                fprintf(fp2, "%d ", IDB_shadow_jerry);
            else if (block->property == 2)
                fprintf(fp2, "%d ", IDB_shadow_beth);
            else if (block->property == 3)
                fprintf(fp2, "%d ", IDB_shadow_math_teacher);
            else if (block->property == 4)
                fprintf(fp2, "%d ", IDB_shadow_president);
            else
                fprintf(fp2, "%d ", IDB_shadow_rick);
        }
        //其他模式（砖块都是rick）
        else
            fprintf(fp2, "%d ", IDB_shadow_rick);

        fprintf(fp2, "%d ", block_shadow->x);
        fprintf(fp2, "%d\n ", block_shadow->y);
    }
    if (block_next != nullptr)
    {
        fprintf(fp2, "%d ", block_next->shape_type);
        fprintf(fp2, "%d ", block_next->shape_id);
        fprintf(fp2, "%d\n", block_next->property);
    }

    //保存旗子数据
    fprintf(fp3, "%d ", leftflag);
    fprintf(fp3, "%d ", rightflag);
    fprintf(fp3, "%d ", upflag);
    fprintf(fp3, "%d ", downflag);
    fprintf(fp3, "%d ", next_step);
    fprintf(fp3, "%d ", delete_the_row);
    fprintf(fp3, "%d ", blindgame_open);
    fprintf(fp3, "%d ", blindgame_not_draw);
    fprintf(fp3, "%d ", sneer);
    fprintf(fp3, "%d ", key_updateflag);
    fprintf(fp3, "%d ", win_or_defeat);
    fprintf(fp3, "%d ", design_map_flag);
    fprintf(fp3, "%d ", design_map_flag_2);
    fprintf(fp3, "%d ", design_map_keep_flag);
    fprintf(fp3, "%d ", entertainmentgame_flag);
    fprintf(fp3, "%d ", time_limited_game);
    fprintf(fp3, "%d ", time_limited_game_begin);
    fprintf(fp3, "%d ", zero_out_all);
    fprintf(fp3, "%d ", click_button);
    fprintf(fp3, "%d ", store_button);
    fprintf(fp3, "%d ", file_loading_flag);
    fprintf(fp3, "%d ", grade_limit_judgeflag);
    fprintf(fp3, "%d ", grade_limit_setting);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fp1 = nullptr;
    fp2 = nullptr;
    fp3 = nullptr;
}

//文件读档
void file_loading()
{
    FILE* fp1 = nullptr, * fp2 = nullptr, * fp3 = nullptr;
    fp1 = fopen("lastgame_grade.txt", "r");
    fp2 = fopen("lastgame_block.txt", "r");
    fp3 = fopen("lastgame_bool.txt", "r");

    int base_size=0;
    fscanf(fp1, "%d", &grade);
    fscanf(fp1, "%d", &type_next);
    fscanf(fp1, "%d", &shape_next_original_id);
    fscanf(fp1, "%d", &countdown);
    fscanf(fp1, "%d", &Cnt_fall_standard);
    fscanf(fp1, "%d", &difficulty_level);
    fscanf(fp1, "%d", &grade_limit);
    fscanf(fp1, "%d", &base_size);

    for (int j = UP_LINE; j <= DOWN_LINE - 1; j++)
    {
        for (int i = LEFT_LINE; i <= RIGHT_LINE; i++)
        {
            fscanf(fp2, "%d", &base_all[j][i]);
            fscanf(fp2, "%d", &map_base[j][i]);
        }
    }
    for (int i = 0; i < base_size; i++)
    {
        Brick* b = CreateBrick(bmp_morty_small);
        fscanf(fp2, "%d", &b->cell_x);
        fscanf(fp2, "%d", &b->cell_y);
        fscanf(fp2, "%d", &b->img_id);
        fscanf(fp2, "%d", &b->property);
        if (b->property == 1)
            b->img = bmp_summer_small;
        base.push_back(b);
    }

    int bmp = 0, block_shape_id, block_type, block_next_shape_type, block_next_shape_id;
    HBITMAP block_img = nullptr, block_shadow_img = nullptr;
    fscanf(fp2, "%d", &bmp);
    if (bmp == IDB_character1)
    {
        block_img = bmp_beth_small;
    }
    else if (bmp == IDB_character2)
    {
        block_img = bmp_jerry_small;
    }
    else if (bmp == IDB_character8)
    {
        block_img = bmp_math_teacher_small;
    }
    else if (bmp == IDB_character10)
    {
        block_img = bmp_president_small;
    }
    else if (bmp == IDB_character4)
    {
        block_img = bmp_rick_small;
    }
    fscanf(fp2, "%d", &block_shape_id);
    fscanf(fp2, "%d", &block_type);

    type = block_type;
    shape_original_id = block_shape_id;
    block = CreateBlock(block_img, block_type, block_shape_id);

    fscanf(fp2, "%d", &block->x);
    fscanf(fp2, "%d", &block->y);
    fscanf(fp2, "%d", &block->property);

    fscanf(fp2, "%d", &bmp);
    if (bmp == IDB_shadow_beth)
    {
        block_shadow_img = bmp_shadow_beth;
    }
    else if (bmp == IDB_shadow_jerry)
    {
        block_shadow_img = bmp_shadow_jerry;
    }
    else if (bmp == IDB_shadow_math_teacher)
    {
        block_shadow_img = bmp_shadow_math_teacher;
    }
    else if (bmp == IDB_shadow_president)
    {
        block_shadow_img = bmp_shadow_president;
    }
    else if (bmp == IDB_shadow_rick)
    {
        block_shadow_img = bmp_shadow_rick;
    }

    block_shadow = CreateBlock(block_shadow_img, block_type, block_shape_id);

    fscanf(fp2, "%d", &block_shadow->x);
    fscanf(fp2, "%d", &block_shadow->y);

    fscanf(fp2, "%d", &block_next_shape_type);
    fscanf(fp2, "%d", &block_next_shape_id);

    type_next = block_next_shape_type;
    shape_next_original_id = block_next_shape_id;
    block_next = CreatePredictBlock(bmp_block_predict, block_next_shape_type, block_next_shape_id);

    fscanf(fp2, "%d", &block_next->property);

        int tem = 0;
        fscanf(fp3, "%d", &tem);
        if (tem)
            leftflag = true;
        else
            leftflag = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            rightflag = true;
        else
            rightflag = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            upflag = true;
        else
            upflag = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            downflag = true;
        else
            downflag = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            next_step = true;
        else
            next_step = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            delete_the_row = true;
        else
            delete_the_row = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            blindgame_open = true;
        else
            blindgame_open = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            blindgame_not_draw = true;
        else
            blindgame_not_draw = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            sneer = true;
        else
            sneer = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            key_updateflag = true;
        else
            key_updateflag = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            win_or_defeat = true;
        else
            win_or_defeat = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            design_map_flag = true;
        else
            design_map_flag = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            design_map_flag_2 = true;
        else
            design_map_flag_2 = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            design_map_keep_flag = true;
        else
            design_map_keep_flag = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            entertainmentgame_flag = true;
        else
            entertainmentgame_flag = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            time_limited_game = true;
        else
            time_limited_game = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            time_limited_game_begin = true;
        else
            time_limited_game_begin = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            zero_out_all = true;
        else
            zero_out_all = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            click_button = true;
        else
            click_button = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            store_button = true;
        else
            store_button = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            file_loading_flag = true;
        else
            file_loading_flag = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            grade_limit_judgeflag = true;
        else
            grade_limit_judgeflag = false;
        fscanf(fp3, "%d", &tem);
        if (tem)
            grade_limit_setting = true;
        else
            grade_limit_setting = false;

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fp1 = nullptr;
    fp2 = nullptr;
    fp3 = nullptr;
}

//分数排行榜存档
void ranklist_storage()
{
    FILE* fp = nullptr;
    if (blindgame_open)
    {
        fp = fopen("blindgame_ranklist.txt", "r");
        for (int i = 0; i < 5; i++)
        {
            fscanf(fp, "%d", &blind_top5[i]);
        }
        for (int i = 0; i < 5; i++)
        {
            if (grade > blind_top5[i])
            {
                normal_top5[4] = grade;
            }
        }
        //冒泡
        for (int i = 0; i < 5; i++)
        {
            for (int j = i + 1; j < 5; j++)
            {
                if (blind_top5[i] < blind_top5[j])
                {
                    int czy = blind_top5[i];
                    blind_top5[i] = blind_top5[j];
                    blind_top5[j] = czy;
                }
            }
        }
        fp = fopen("blindgame_ranklist.txt", "w");
        for (int i = 0; i < 5; i++)
        {
            fprintf(fp, "%d\n", blind_top5[i]);
        }
    }
    else if (design_map_flag||design_map_flag_2)
    {
        fp = fopen("designmapgame_ranklist.txt", "r");
        for (int i = 0; i < 5; i++)
        {
            fscanf(fp, "%d", &designmap_top5[i]);
        }
        for (int i = 0; i < 5; i++)
        {
            if (grade > designmap_top5[i])
            {
                designmap_top5[4] = grade;
            }
        }
        //冒泡
        for (int i = 0; i < 5; i++)
        {
            for (int j = i + 1; j < 5; j++)
            {
                if (designmap_top5[i] < designmap_top5[j])
                {
                    int czy = designmap_top5[i];
                    designmap_top5[i] = designmap_top5[j];
                    designmap_top5[j] = czy;
                }
            }
        }
        fp = fopen("designmapgame_ranklist.txt", "w");
        for (int i = 0; i < 5; i++)
        {
            fprintf(fp, "%d\n", designmap_top5[i]);
        }
    }
    else if (entertainmentgame_flag)
    {
        fp = fopen("propsgame_ranklist.txt", "r");
        for (int i = 0; i < 5; i++)
        {
            fscanf(fp, "%d", &props_top5[i]);
        }
        for (int i = 0; i < 5; i++)
        {
            if (grade > props_top5[i])
            {
                props_top5[4] = grade;
            }
        }
        //冒泡
        for (int i = 0; i < 5; i++)
        {
            for (int j = i + 1; j < 5; j++)
            {
                if (props_top5[i] < props_top5[j])
                {
                    int czy = props_top5[i];
                    props_top5[i] = props_top5[j];
                    props_top5[j] = czy;
                }
            }
        }
        fp = fopen("propsgame_ranklist.txt", "w");
        for (int i = 0; i < 5; i++)
        {
            fprintf(fp, "%d\n", props_top5[i]);
        }
    }
    else if (time_limited_game)
    {
        fp = fopen("timelimitedgame_ranklist.txt", "r");
        for (int i = 0; i < 5; i++)
        {
            fscanf(fp, "%d", &timelimited_top5[i]);
        }
        for (int i = 0; i < 5; i++)
        {
            if (grade > timelimited_top5[i])
            {
                timelimited_top5[4] = grade;
            }
        }
        //冒泡
        for (int i = 0; i < 5; i++)
        {
            for (int j = i + 1; j < 5; j++)
            {
                if (timelimited_top5[i] < timelimited_top5[j])
                {
                    int czy = timelimited_top5[i];
                    timelimited_top5[i] = timelimited_top5[j];
                    timelimited_top5[j] = czy;
                }
            }
        }
        fp = fopen("timelimitedgame_ranklist.txt", "w");
        for (int i = 0; i < 5; i++)
        {
            fprintf(fp, "%d\n", timelimited_top5[i]);
        }
    }
    else
    {
        fp = fopen("normalgame_ranklist.txt", "r");
        for (int i = 0; i < 5; i++)
        {
            fscanf(fp, "%d", &normal_top5[i]);
        }
        for (int i = 0; i < 5; i++)
        {
            if (grade > normal_top5[i])
            {
                normal_top5[4] = grade;
            }
        }
        //冒泡
        for (int i = 0; i < 5; i++)
        {
            for (int j = i + 1; j < 5; j++)
            {
                if (normal_top5[i] < normal_top5[j])
                {
                    int czy = normal_top5[i];
                    normal_top5[i] = normal_top5[j];
                    normal_top5[j] = czy;
                }
            }
        }
        fp = fopen("normalgame_ranklist.txt", "w");
        for (int i = 0; i < 5; i++)
        {
            fprintf(fp, "%d\n", normal_top5[i]);
        }
    }
    fclose(fp);
    fp= nullptr;
}

//分数排行榜重置
void ranklist_restorage()
{
    FILE* fp = nullptr;
    if (ranklist_id == 0)
    {
        fp = fopen("normalgame_ranklist.txt", "w");
        for(int i=0;i<5;i++)
        {
            normal_top5[i] = 0;
            fprintf(fp, "%d\n", normal_top5[i]);
        }
    }
    else if (ranklist_id == 1)
    {
        fp = fopen("blindgame_ranklist.txt", "w");
        for (int i = 0; i < 5; i++)
        {
            blind_top5[i] = 0;
            fprintf(fp, "%d\n", blind_top5[i]);
        }
    }
    else if (ranklist_id == 2)
    {
        fp = fopen("designmapgame_ranklist.txt", "w");
        for (int i = 0; i < 5; i++)
        {
            designmap_top5[i] = 0;
            fprintf(fp, "%d\n", designmap_top5[i]);
        }
    }
    else if (ranklist_id == 3)
    {
        fp = fopen("propsgame_ranklist.txt", "w");
        for (int i = 0; i < 5; i++)
        {
            props_top5[i] = 0;
            fprintf(fp, "%d\n", props_top5[i]);
        }
    }
    else if (ranklist_id == 4)
    {
        fp = fopen("timelimitedgame_ranklist.txt", "w");
        for (int i = 0; i < 5; i++)
        {
            timelimited_top5[i] = 0;
            fprintf(fp, "%d\n", timelimited_top5[i]);
        }
    }
    fclose(fp);
    fp = nullptr;
}

//分数排行榜读档
void ranklist_loading()
{
    FILE* fp = nullptr;
    if (ranklist_id == 0)
    {
        fp = fopen("normalgame_ranklist.txt", "r");
        for (int i = 0; i < 5; i++)
        {
            fscanf(fp, "%d", &normal_top5[i]);
        }
    }
    else if (ranklist_id == 1)
    {
        fp = fopen("blindgame_ranklist.txt", "r");
        for (int i = 0; i < 5; i++)
        {
            fscanf(fp, "%d", &blind_top5[i]);
        }
    }
    else if (ranklist_id == 2)
    {
        fp = fopen("designmapgame_ranklist.txt", "r");
        for (int i = 0; i < 5; i++)
        {
            fscanf(fp, "%d", &designmap_top5[i]);
        }
    }
    else if (ranklist_id == 3)
    {
        fp = fopen("propsgame_ranklist.txt", "r");
        for (int i = 0; i < 5; i++)
        {
            fscanf(fp, "%d", &props_top5[i]);
        }
    }
    else if (ranklist_id == 4)
    {
        fp = fopen("timelimitedgame_ranklist.txt", "r");
        for (int i = 0; i < 5; i++)
        {
            fscanf(fp, "%d", &timelimited_top5[i]);
        }
    }
    fclose(fp);
    fp = nullptr;
}

//自定义地图
void DesignMap()
{
    if (design_map_flag|| design_map_flag_2)
    {
        for (int i = LEFT_LINE + 1; i < RIGHT_LINE; i++)
        {
            for (int j = UP_LINE + 1; j < DOWN_LINE; j++)
            {
                if (map_base[j][i] == 1)
                {
                    Brick* b = CreateBrick(bmp_summer_small);
                    b->cell_x = i * BG_CELL_WIDTH;
                    b->cell_y = j * BG_CELL_HEIGHT;
                    b->img_id = IDB_character5;
                    b->property = 1;
                    base_all[j][i] = 1;
                    base.push_back(b);
                }
            }
        }
    }
}

#pragma endregion

#pragma region 绘图函数

// 绘图函数
void Paint(HWND hWnd)
{
    // 开始绘制
    PAINTSTRUCT ps;
    HDC hdc_window = BeginPaint(hWnd, &ps);

    // 创建缓存
    HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
    HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

    // 初始化缓存
    HBITMAP blankBmp = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
    SelectObject(hdc_memBuffer, blankBmp);

    // 绘制背景到缓存
    SelectObject(hdc_loadBmp, currentStage->bg);
    BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);

    // 按场景分类绘制内容到缓存
    switch (currentStage->stageID)
    {
    case STAGE_START:
    {
        // 绘制开始界面提示文字

        // 创建一个字体，设置高度为 30（单位是逻辑单元）
        HFONT hFont = CreateFont(
            30,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL,                // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("微软雅黑")           // 字体名称
        );
        // 选择自定义字体到设备上下文
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont);
        // 设置字体区域
        RECT rect1 = {
            BUTTON_STARTGAME_X - 25,
            BUTTON_STARTGAME_Y + 250,
            BUTTON_STARTGAME_X + BUTTON_STARTGAME_WIDTH + 25,
            BUTTON_STARTGAME_Y + 300 };
        RECT rect2 = {
            BUTTON_STARTGAME_X - 25,
            BUTTON_STARTGAME_Y -50,
            BUTTON_STARTGAME_X + BUTTON_STARTGAME_WIDTH + 25,
            BUTTON_STARTGAME_Y };
        RECT rank_list = {
            475,
            BUTTON_STARTGAME_Y + 350,
            575,
            BUTTON_STARTGAME_Y + 450 };
        RECT game_tutorial = {
            250,
            BUTTON_STARTGAME_Y + 350,
            350,
            BUTTON_STARTGAME_Y + 450 };
        RECT load_save = {
            700,
            BUTTON_STARTGAME_Y + 350,
            800,
            BUTTON_STARTGAME_Y + 450 };
        RECT game_mode = {
            925,
            BUTTON_STARTGAME_Y + 350,
            1025,
            BUTTON_STARTGAME_Y + 450 };
        RECT setup = { 50,10,150,50 };

        // 绘制
        DrawText(hdc_memBuffer, TEXT("咸鱼の俄罗斯方块"), -1, &rect1, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("点击即可开始摸鱼"), -1, &rect2, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("排行榜"), -1, &rank_list, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("游戏教程"), -1, &game_tutorial, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("游戏读档"), -1, &load_save, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("游戏模式"), -1, &game_mode, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("设置界面"), -1, &setup, DT_CENTER);

        // 恢复原来的字体
        SelectObject(hdc_memBuffer, hOldFont);
        // 删除自定义字体以释放资源
        DeleteObject(hFont);
    }
    break;
    case STAGE_GAME:
    {
        if (block_shadow != nullptr && next_step)
        {
            if (entertainmentgame_flag)
            {
                if (block->property == 0)
                    SelectObject(hdc_loadBmp, bmp_shadow_rick);
                else if (block->property == 1)
                    SelectObject(hdc_loadBmp, bmp_shadow_jerry);
                else if (block->property == 2)
                    SelectObject(hdc_loadBmp, bmp_shadow_beth);
                else if (block->property == 3)
                    SelectObject(hdc_loadBmp, bmp_shadow_math_teacher);
                else if (block->property == 4)
                    SelectObject(hdc_loadBmp, bmp_shadow_president);
            }
            else
                SelectObject(hdc_loadBmp, bmp_shadow_rick);
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (block_shadow->shape[i][j] == 1)
                    {
                        TransparentBlt(
                            hdc_memBuffer, (block_shadow->x + j) * BG_CELL_WIDTH, (block_shadow->y + i) * BG_CELL_HEIGHT,
                            BG_CELL_WIDTH, BG_CELL_HEIGHT,
                            hdc_loadBmp, 0, 0, BG_CELL_WIDTH, BG_CELL_HEIGHT,
                            RGB(255, 255, 255));
                    }
                }
            }
        }
        if (block != nullptr && next_step)
        {
            SelectObject(hdc_loadBmp, block->img);
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (block->shape[i][j] == 1)
                    {
                        TransparentBlt(
                            hdc_memBuffer, (block->x + j) * BG_CELL_WIDTH, (block->y + i) * BG_CELL_HEIGHT,
                            BG_CELL_WIDTH, BG_CELL_HEIGHT,
                            hdc_loadBmp, 0, 0, BG_CELL_WIDTH, BG_CELL_HEIGHT,
                            RGB(255, 255, 255));
                    }
                }
            }
        }
        if (block_next != nullptr && next_step)
        {
            SelectObject(hdc_loadBmp, block_next->img);
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (type_next == 7)
                    {
                        if (block_next->shape[i][j] == 1)
                        {
                            TransparentBlt(
                                hdc_memBuffer, (block_next->x + 1)* BG_CELL_WIDTH + j * 35, block_next->y* BG_CELL_HEIGHT + i * 35 + 10,
                                35, 35,
                                hdc_loadBmp, 0, 0, 35, 35,
                                RGB(255, 255, 255));
                        }
                    }
                    else
                    {
                        if (block_next->shape[i][j] == 1)
                        {
                            TransparentBlt(
                                hdc_memBuffer, block_next->x * BG_CELL_WIDTH + j * 35 + 25, block_next->y * BG_CELL_HEIGHT + i * 35 + 10,
                                35, 35,
                                hdc_loadBmp, 0, 0, 35, 35,
                                RGB(255, 255, 255));
                        }
                    }
                }
            }
        }

        for (int i = 0; i < base.size(); i++)
        {
            if (base[i] != nullptr && (!blindgame_open || !blindgame_not_draw))
            {
                SelectObject(hdc_loadBmp, base[i]->img);
                Brick* brick = base[i];
                TransparentBlt(
                    hdc_memBuffer, brick->cell_x * BG_CELL_WIDTH, brick->cell_y * BG_CELL_HEIGHT,
                    BG_CELL_WIDTH, BG_CELL_HEIGHT,
                    hdc_loadBmp, 0, 0, BG_CELL_WIDTH, BG_CELL_HEIGHT,
                    RGB(255, 255, 255));
            }
        }
        //画警戒线
        SelectObject(hdc_loadBmp, bmp_WARNING_LINE);
        if (difficulty_level == 2)
        {
            for (int i = 0; i < 2; i++)
            {
                TransparentBlt(
                    hdc_memBuffer, BG_CELL_WIDTH + i * 350, UP_LINE * BG_CELL_HEIGHT,
                    350, BG_CELL_HEIGHT,
                    hdc_loadBmp, 0, 0, 299, 52,
                    RGB(255, 255, 255));
            }
        }
        else if (difficulty_level == 3)
        {
            for (int i = 0; i < 2; i++)
            {
                TransparentBlt(
                    hdc_memBuffer, BG_CELL_WIDTH + i * 350, (UP_LINE+4) * BG_CELL_HEIGHT,
                    350, BG_CELL_HEIGHT,
                    hdc_loadBmp, 0, 0, 299, 52,
                    RGB(255, 255, 255));
            }
        }

        //画自定义地图
        SelectObject(hdc_loadBmp, bmp_summer_small);
        if (design_map_flag || design_map_flag_2)
        {
            for (int i = LEFT_LINE + 1; i < RIGHT_LINE; i++)
            {
                for (int j = UP_LINE + 1; j < DOWN_LINE; j++)
                {
                    if (map_base[j][i] == 1)
                        BitBlt(hdc_memBuffer, i * BG_CELL_WIDTH, j * BG_CELL_HEIGHT, BG_CELL_WIDTH, BG_CELL_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
                }
            }
        }

        //显示分数
        HFONT Impact = CreateFont(
            60,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 2,              // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("Impact")           // 字体名称
        );
        HFONT yaoti= CreateFont(
            100,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            10,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 3,              // 字体的粗细
            TRUE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("方正姚体")           // 字体名称
        );
        RECT rect1 = {
            (RIGHT_LINE + 1) * BG_CELL_WIDTH,
            7 * BG_CELL_HEIGHT+15,
            WINDOW_WIDTH- BG_CELL_WIDTH,
            8 * BG_CELL_HEIGHT+15 };
        RECT rect2 = {
            (RIGHT_LINE + 1) * BG_CELL_WIDTH,
            1 * BG_CELL_HEIGHT,
            WINDOW_WIDTH - BG_CELL_WIDTH,
            2 * BG_CELL_HEIGHT };
        RECT rect3 = {
            BG_CELL_WIDTH,
            6 * BG_CELL_HEIGHT,
            WINDOW_WIDTH - BG_CELL_WIDTH,
            8 * BG_CELL_HEIGHT };
        RECT rect4 = {
            (RIGHT_LINE + 1)* BG_CELL_WIDTH,
            6 * BG_CELL_HEIGHT,
            WINDOW_WIDTH - BG_CELL_WIDTH-25,
            8 * BG_CELL_HEIGHT };

        //实时显示分数
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, Impact);
        TCHAR text1[100];
        _stprintf_s(text1, TEXT("%d"), grade);
        DrawText(hdc_memBuffer, text1, -1, &rect1, DT_CENTER);

        //显示分数上限
        if (grade_limit_setting)
        {
            TCHAR text4[100];
            _stprintf_s(text4, TEXT("目标分数：%d"), grade_limit);
            DrawText(hdc_memBuffer, text4, -1, &rect4, DT_CENTER);
        }

        //实时倒计时
        if (time_limited_game)
        {
            HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, Impact);
            TCHAR text2[100];
            _stprintf_s(text2, TEXT("%d s"), countdown-1);
            DrawText(hdc_memBuffer, text2, -1, &rect2, DT_CENTER);
        }

        //倒计时结束
        if (GameOver())
        {
            HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, yaoti);
            TCHAR text3[100];
            _stprintf_s(text3, TEXT("游戏结束 您的得分是 %d "), grade);
            DrawText(hdc_memBuffer, text3, -1, &rect3, DT_CENTER);
        }

        SelectObject(hdc_memBuffer, hOldFont);
        DeleteObject(Impact);
        DeleteObject(yaoti);
    }
    break;
    case STAGE_RANKLIST:
    {
        // 创建一个字体，设置高度为 30（单位是逻辑单元）
        HFONT hFont_songti = CreateFont(
            30,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL*2.5,                // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("华文隶书")           // 字体名称
        );
        HFONT hFont_lishu = CreateFont(
            80,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 3,            // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("华文隶书")           // 字体名称
        );
        HFONT hFont_lishu_small = CreateFont(
            80,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 2,            // 字体的粗细
            FALSE,                    // 是否斜体
            TRUE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("华文隶书")           // 字体名称
        );
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont_songti);
        RECT go_back = {50,10,150,50};
        RECT ranklist_restorage = {1050,10,1150,50 };
        DrawText(hdc_memBuffer, TEXT("返回"), -1, &go_back, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("重置"), -1, &ranklist_restorage, DT_CENTER);

        RECT title = {
        2 * BG_CELL_WIDTH,
        1 * BG_CELL_HEIGHT,
        WINDOW_WIDTH - BG_CELL_WIDTH,
        1 * BG_CELL_HEIGHT+80 };
        RECT rect1 = {
        1 * BG_CELL_WIDTH,
        4 * BG_CELL_HEIGHT,
        WINDOW_WIDTH - BG_CELL_WIDTH,
        4 * BG_CELL_HEIGHT+80 };
        TCHAR text1[100];
        hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont_lishu);
        if (ranklist_id == 0)
            DrawText(hdc_memBuffer, TEXT("普通模式排行榜"), -1, &title, DT_CENTER);
        else if (ranklist_id == 1)
            DrawText(hdc_memBuffer, TEXT("盲打模式排行榜"), -1, &title, DT_CENTER);
        else if (ranklist_id == 2)
            DrawText(hdc_memBuffer, TEXT("自定义地图模式排行榜"), -1, &title, DT_CENTER);
        else if (ranklist_id == 3)
            DrawText(hdc_memBuffer, TEXT("道具模式排行榜"), -1, &title, DT_CENTER);
        else if (ranklist_id == 4)
            DrawText(hdc_memBuffer, TEXT("限时模式排行榜"), -1, &title, DT_CENTER);

        hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont_lishu_small);
        if (ranklist_id == 0)
        {
            for (int i = 0; i < 5; i++)
            {
                rect1 = {
                1 * BG_CELL_WIDTH,
                (4 + i) * BG_CELL_HEIGHT + i * 60,
                WINDOW_WIDTH - BG_CELL_WIDTH,
                (4 + i) * BG_CELL_HEIGHT + i * 60 + 80 };
                _stprintf_s(text1, TEXT("%d "), normal_top5[i]);
                DrawText(hdc_memBuffer, text1, -1, &rect1, DT_CENTER);
            }
        }
        else if (ranklist_id == 1)
        {
            for (int i = 0; i < 5; i++)
            {
                rect1 = {
                1 * BG_CELL_WIDTH,
                (4 + i) * BG_CELL_HEIGHT + i * 60,
                WINDOW_WIDTH - BG_CELL_WIDTH,
                (4 + i) * BG_CELL_HEIGHT + i * 60 + 80 };
                _stprintf_s(text1, TEXT("%d "), blind_top5[i]);
                DrawText(hdc_memBuffer, text1, -1, &rect1, DT_CENTER);
            }
        }
        else if (ranklist_id == 2)
        {
            for (int i = 0; i < 5; i++)
            {
                rect1 = {
                1 * BG_CELL_WIDTH,
                (4 + i) * BG_CELL_HEIGHT + i * 60,
                WINDOW_WIDTH - BG_CELL_WIDTH,
                (4 + i) * BG_CELL_HEIGHT + i * 60 + 80 };
                _stprintf_s(text1, TEXT("%d "), designmap_top5[i]);
                DrawText(hdc_memBuffer, text1, -1, &rect1, DT_CENTER);
            }
        }
        else if (ranklist_id == 3)
        {
            for (int i = 0; i < 5; i++)
            {
                rect1 = {
                1 * BG_CELL_WIDTH,
                (4 + i) * BG_CELL_HEIGHT + i * 60,
                WINDOW_WIDTH - BG_CELL_WIDTH,
                (4 + i) * BG_CELL_HEIGHT + i * 60 + 80 };
                _stprintf_s(text1, TEXT("%d "), props_top5[i]);
                DrawText(hdc_memBuffer, text1, -1, &rect1, DT_CENTER);
            }
        }
        else if (ranklist_id == 4)
        {
            for (int i = 0; i < 5; i++)
            {
                rect1 = {
                1 * BG_CELL_WIDTH,
                (4 + i) * BG_CELL_HEIGHT + i * 60,
                WINDOW_WIDTH - BG_CELL_WIDTH,
                (4 + i) * BG_CELL_HEIGHT + i * 60 + 80 };
                _stprintf_s(text1, TEXT("%d "), timelimited_top5[i]);
                DrawText(hdc_memBuffer, text1, -1, &rect1, DT_CENTER);
            }
        }

        SelectObject(hdc_memBuffer, hOldFont);
        DeleteObject(hFont_songti);
    }
    break;
    case STAGE_HELP:
    {
        HFONT hFont_songti = CreateFont(
            30,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 2.5,          // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("华文隶书")           // 字体名称
        );
        HFONT hFont_lishu = CreateFont(
            50,                       // 字体高度
            15,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 2,            // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("华文隶书")           // 字体名称
        );
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont_songti);
        RECT go_back = { 50,10,150,50 };
        DrawText(hdc_memBuffer, TEXT("返回"), -1, &go_back, DT_CENTER);
        hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont_lishu);
        RECT guide_0 = { 100,50,1150,100 };
        RECT guide_1 = { 200,125,830,175 };
        RECT guide_2 = { 200,200,1040,250 };
        RECT guide_3 = { 200,275,670,325 };
        RECT guide_4 = { 200,350,840,400 };
        RECT guide_5 = { 200,425,1015,475 };
        RECT guide_6 = { 200,500,1145,550 };
        RECT guide_7 = { 200,575,860,625 };
        RECT guide_8 = { 200,650,1020,700 };
        DrawText(hdc_memBuffer, TEXT("玩法教程："), -1, &guide_0, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("1.俄罗斯方块总共有7 种类型"), -1, &guide_1, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("2.←↓→/asd分别控制方块向左下右移动"), -1, &guide_2, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("3.↑/w控制方块转向"), -1, &guide_3, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("4.每排满一行即可消除并得分"), -1, &guide_4, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("5.同时消除多行，每行得分会相应翻倍"), -1, &guide_5, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("6.达到对应分数或者方块触碰上线则游戏结束"), -1, &guide_6, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("7.有多种娱乐模式可供选择^-^"), -1, &guide_7, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("8.直接关闭窗口将不能保存游戏数据！"), -1, &guide_8, DT_CENTER);

        SelectObject(hdc_memBuffer, hOldFont);
        DeleteObject(hFont_songti);

    }
    break;
    case STAGE_GAME_MODE:
    {
        // 创建一个字体，设置高度为 30（单位是逻辑单元）
        HFONT hFont_xingkai = CreateFont(
            40,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 2.5,                // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("华文行楷")           // 字体名称
        );
        HFONT hFont_songti = CreateFont(
            30,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 2.5,                // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("华文隶书")           // 字体名称
        );

        HFONT hOldFont_1 = (HFONT)SelectObject(hdc_memBuffer, hFont_songti);
        RECT go_back = { 50,10,150,50 };
        DrawText(hdc_memBuffer, TEXT("返回"), -1, &go_back, DT_CENTER);
        SelectObject(hdc_memBuffer, hOldFont_1);
        DeleteObject(hFont_songti);

        HFONT hOldFont_2 = (HFONT)SelectObject(hdc_memBuffer, hFont_xingkai);
        RECT blind_game = { 325,100,475,140 };
        RECT design_map = { 700,100,900,140 };
        RECT entertainment_game = { 325,430,475,470 };
        RECT timelimited_game = { 700,430,900,470 };
        DrawText(hdc_memBuffer, TEXT("盲打模式"), -1, &blind_game, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("自定义地图"), -1, &design_map, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("娱乐模式"), -1, &entertainment_game, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("限时模式"), -1, &timelimited_game, DT_CENTER);
        SelectObject(hdc_memBuffer, hOldFont_2);
        DeleteObject(hFont_xingkai);
    }
    break;
    case STAGE_EXIT:
    {
        HFONT hFont_lishu = CreateFont(
            70,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 2.5,                // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("隶书")           // 字体名称
        );
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont_lishu);
        RECT really_want_to_exit = { 250,170,1100,240 };
        if (!sneer)
        {
            SelectObject(hdc_loadBmp, bmp_jessica);
            BitBlt(hdc_memBuffer, 170, 155, BUTTON_small_WIDTH, BUTTON_small_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
            DrawText(hdc_memBuffer, TEXT("你真的想要退出吗 QAQ "), -1, &really_want_to_exit, DT_CENTER);
        }
        else
        {
            SelectObject(hdc_loadBmp, bmp_math_teacher);
            BitBlt(hdc_memBuffer, 170, 155, BUTTON_small_WIDTH, BUTTON_small_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
            DrawText(hdc_memBuffer, TEXT("菜 就多练 w_w "), -1, &really_want_to_exit, DT_CENTER);
            PostQuitMessage(0);
        }
        SelectObject(hdc_memBuffer, hOldFont);
        DeleteObject(hFont_lishu);
    }
    break;
    case STAGE_STORE:
    {
        HFONT hFont_lishu = CreateFont(
            70,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 2.5,                // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("隶书")           // 字体名称
        );
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont_lishu);
        RECT really_want_to_exit = { 250,170,1100,240 };
        SelectObject(hdc_loadBmp, bmp_Mr_Meeseeks);
        BitBlt(hdc_memBuffer, 170, 155, BUTTON_small_WIDTH, BUTTON_small_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
        DrawText(hdc_memBuffer, TEXT("是否需要保存游戏"), -1, &really_want_to_exit, DT_CENTER);
        SelectObject(hdc_memBuffer, hOldFont);
        DeleteObject(hFont_lishu);
    }
    break;
    case STAGE_STORE_2:
    {
        HFONT hFont_lishu = CreateFont(
            70,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 2.5,                // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("隶书")           // 字体名称
        );
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont_lishu);
        RECT really_want_to_exit = { 250,170,1100,240 };
        SelectObject(hdc_loadBmp, bmp_Mr_Meeseeks);
        BitBlt(hdc_memBuffer, 170, 155, BUTTON_small_WIDTH, BUTTON_small_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
        DrawText(hdc_memBuffer, TEXT("是否需要保存游戏"), -1, &really_want_to_exit, DT_CENTER);
        SelectObject(hdc_memBuffer, hOldFont);
        DeleteObject(hFont_lishu);
    }
    break;
    case STAGE_ENTERTAINMENT_INTRODUCTION:
    {
        HFONT hFont_kaiti = CreateFont(
            30,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 2.5,                // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("华文楷体")           // 字体名称
        );
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont_kaiti);
        RECT begin = { 975,10,1125,50 };
        DrawText(hdc_memBuffer, TEXT("开始游戏"), -1, &begin, DT_CENTER);
        HFONT hFont_songti = CreateFont(
            60,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 2,                // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("华文中宋")           // 字体名称
        );
        hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont_songti);
        RECT specialblock = { 250,150,1060,210 };
        DrawText(hdc_memBuffer, TEXT("杰瑞将消除其所在列上的所有方块"), -1, &specialblock, DT_CENTER);
        specialblock = { 250,300,1060,360 };
        DrawText(hdc_memBuffer, TEXT("贝丝将消除其所在行上的所有方块"), -1, &specialblock, DT_CENTER);
        specialblock = { 250,450,1170,510 };
        DrawText(hdc_memBuffer, TEXT("数学老师会在其所在列筑起“高数墙”"), -1, &specialblock, DT_CENTER);
        specialblock = { 250,600,900,660 };
        DrawText(hdc_memBuffer, TEXT("总统会将游戏画面镜面翻转"), -1, &specialblock, DT_CENTER);

        SelectObject(hdc_loadBmp, bmp_jerry);
        BitBlt(hdc_memBuffer, 120, 130, BUTTON_small_WIDTH, BUTTON_small_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
        SelectObject(hdc_loadBmp, bmp_beth);
        BitBlt(hdc_memBuffer, 120, 280, BUTTON_small_WIDTH, BUTTON_small_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
        SelectObject(hdc_loadBmp, bmp_math_teacher);
        BitBlt(hdc_memBuffer, 120, 430, BUTTON_small_WIDTH, BUTTON_small_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
        SelectObject(hdc_loadBmp, bmp_president);
        BitBlt(hdc_memBuffer, 120, 580, BUTTON_small_WIDTH, BUTTON_small_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);

        SelectObject(hdc_memBuffer, hOldFont);
        DeleteObject(hFont_kaiti);
    }
    break;
    case STAGE_SETUP_INTERFACE:
    {
        HFONT hFont = CreateFont(
            30,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL,                // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("华文新魏")           // 字体名称
        );
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont);
        RECT out = {
            465,BUTTON_STARTGAME_Y + 350,
            585,BUTTON_STARTGAME_Y + 450 };
        RECT continuegame = {
            240,BUTTON_STARTGAME_Y + 350,
            360,BUTTON_STARTGAME_Y + 450 };
        RECT beginpage = {
            875,BUTTON_STARTGAME_Y + 350,
            1075,BUTTON_STARTGAME_Y + 450 };
        RECT restartpage = {
            690,BUTTON_STARTGAME_Y + 350,
            810,BUTTON_STARTGAME_Y + 450 };
        DrawText(hdc_memBuffer, TEXT("退出游戏"), -1, &out, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("继续游戏"), -1, &continuegame, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("重开游戏"), -1, &restartpage, DT_CENTER);
        DrawText(hdc_memBuffer, TEXT("返回初始界面"), -1, &beginpage, DT_CENTER);

        HFONT hFont_2 = CreateFont(
            60,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 2,                // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("华文新魏")           // 字体名称
        );
        hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont_2);
        RECT more_detail = { 250,30,1000,90 };
        DrawText(hdc_memBuffer, TEXT("更多设置"), -1, &more_detail, DT_CENTER);
        SelectObject(hdc_memBuffer, hOldFont);
        DeleteObject(hFont);
        DeleteObject(hFont_2);
    }
    break;
    case STAGE_MAP_KEEP:
    {
        HFONT yaoti = CreateFont(
            100,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            10,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 3,              // 字体的粗细
            TRUE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("方正姚体")           // 字体名称
        );
        RECT rect3 = {
            BG_CELL_WIDTH,
            6 * BG_CELL_HEIGHT,
            WINDOW_WIDTH - BG_CELL_WIDTH,
            8 * BG_CELL_HEIGHT };
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, yaoti);
        DrawText(hdc_memBuffer, TEXT("是否需要保存地图嘞"), -1, &rect3, DT_CENTER);
        SelectObject(hdc_memBuffer, hOldFont);
        DeleteObject(yaoti);
    }
    break;
    case STAGE_GRADE_LIMIT_SET:
    {
        HFONT yaoti = CreateFont(
            100,                      // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 3,            // 字体的粗细
            FALSE,                     // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("方正姚体")           // 字体名称
        );
        HFONT yaoti_2 = CreateFont(
            70,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 3/2,          // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("方正姚体")           // 字体名称
        );
        HFONT yaoti_3 = CreateFont(
            40,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL,                // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("方正姚体")           // 字体名称
        );
        RECT rect = {
            BG_CELL_WIDTH,
            4 * BG_CELL_HEIGHT,
            WINDOW_WIDTH - BG_CELL_WIDTH,
            6 * BG_CELL_HEIGHT };
        RECT rect_add = {
            5*BG_CELL_WIDTH,
            5 * BG_CELL_HEIGHT,
            9*BG_CELL_WIDTH,
            7 * BG_CELL_HEIGHT };
        RECT rect_minus = {
            15*BG_CELL_WIDTH,
            5 * BG_CELL_HEIGHT,
            19*BG_CELL_WIDTH,
            7 * BG_CELL_HEIGHT };
        RECT rect_2 = {
            5 * BG_CELL_WIDTH,
            2 * BG_CELL_HEIGHT,
            12 * BG_CELL_WIDTH,
            4 * BG_CELL_HEIGHT };
        RECT rect_grade_limit = {
            14 * BG_CELL_WIDTH,
            2 * BG_CELL_HEIGHT,
            19 * BG_CELL_WIDTH,
            4 * BG_CELL_HEIGHT };
        RECT rect_confirm = {
            20 * BG_CELL_WIDTH,
            1 * BG_CELL_HEIGHT-20,
            22 * BG_CELL_WIDTH,
            3 * BG_CELL_HEIGHT };
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, yaoti);
        if (!grade_limit_setting)
        {
            DrawText(hdc_memBuffer, TEXT("是否需要设置分数上限"), -1, &rect, DT_CENTER);
        }
        else
        {
            HFONT hOldFont_2 = (HFONT)SelectObject(hdc_memBuffer, yaoti_2);
            DrawText(hdc_memBuffer, TEXT("减十分"), -1, &rect_add, DT_CENTER);
            DrawText(hdc_memBuffer, TEXT("加十分"), -1, &rect_minus, DT_CENTER);
            HFONT hOldFont_3 = (HFONT)SelectObject(hdc_memBuffer, yaoti_3);
            DrawText(hdc_memBuffer, TEXT("确定"), -1, &rect_confirm, DT_CENTER);
            HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, yaoti);
            DrawText(hdc_memBuffer, TEXT("分数上限"), -1, &rect_2, DT_CENTER);
            TCHAR text2[100];
            _stprintf_s(text2, TEXT("%d"), grade_limit);
            DrawText(hdc_memBuffer, text2, -1, &rect_grade_limit, DT_CENTER);
        }

        SelectObject(hdc_memBuffer, hOldFont);
        DeleteObject(yaoti);
    }
    break;
    case STAGE_DETAILED_SETUP_INTERFACE:
    {
        HFONT hFont_songti = CreateFont(
            30,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 2.5,                // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("华文隶书")           // 字体名称
        );
        HFONT hFont_zhongsong = CreateFont(
            40,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 2,                // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("华文中宋")           // 字体名称
        );
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont_songti);
        RECT go_back = { 50,10,150,50 };
        DrawText(hdc_memBuffer, TEXT("返回"), -1, &go_back, DT_CENTER);
        hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont_zhongsong);
        RECT speed = { 250,75,400,115 };
        DrawText(hdc_memBuffer, TEXT("超慢"), -1, &speed, DT_CENTER);
        speed = { 500,75,650,115 };
        DrawText(hdc_memBuffer, TEXT("慢速"), -1, &speed, DT_CENTER);
        speed = { 750,75,900,115 };
        DrawText(hdc_memBuffer, TEXT("中速"), -1, &speed, DT_CENTER);
        speed = { 990,75,1140,115 };
        DrawText(hdc_memBuffer, TEXT("超快"), -1, &speed, DT_CENTER);
        speed = { 375,300,525,340 };
        DrawText(hdc_memBuffer, TEXT("简单"), -1, &speed, DT_CENTER);
        speed = { 625,300,775,340 };
        DrawText(hdc_memBuffer, TEXT("正常"), -1, &speed, DT_CENTER);
        speed = { 875,300,1025,340 };
        DrawText(hdc_memBuffer, TEXT("困难"), -1, &speed, DT_CENTER);
        RECT title = { 50,180,195,220 };
        DrawText(hdc_memBuffer, TEXT("速度档位"), -1, &title, DT_CENTER);
        title = { 50,390,195,430 };
        DrawText(hdc_memBuffer, TEXT("游戏难度"), -1, &title, DT_CENTER);
        title = { 50,575,195,615 };
        DrawText(hdc_memBuffer, TEXT("音乐开关"), -1, &title, DT_CENTER);
        title = { 500,575,645,615 };
        DrawText(hdc_memBuffer, TEXT("音效开关"), -1, &title, DT_CENTER);
        title = { 50,690,195,730 };
        DrawText(hdc_memBuffer, TEXT("音乐音量"), -1, &title, DT_CENTER);
        title = { 650,690,795,730 };
        DrawText(hdc_memBuffer, TEXT("音效音量"), -1, &title, DT_CENTER);
        title = { 350,690,500,730 };
        TCHAR text1[100];
        _stprintf_s(text1, TEXT("%d"), volume_music / 10);
        DrawText(hdc_memBuffer, text1, -1, &title, DT_CENTER);
        title = { 950,690,1100,730 };
        _stprintf_s(text1, TEXT("%d"), volume_sound / 10);
        DrawText(hdc_memBuffer, text1, -1, &title, DT_CENTER);
        SelectObject(hdc_memBuffer, hOldFont);
        DeleteObject(hFont_songti);
    }
    break;
    case STAGE_BILNDGAME_START:
    {
        HFONT hFont_lishu = CreateFont(
            70,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 2.5,                // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("隶书")           // 字体名称
        );
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont_lishu);
        RECT blindgame = { 100,170,1100,240 };
        DrawText(hdc_memBuffer, TEXT("你中了姥爷的黑科技"), -1, &blindgame, DT_CENTER);
        blindgame = { 100,270,1100,340 };
        DrawText(hdc_memBuffer, TEXT("你将无法看到已经落下的砖块"), -1, &blindgame, DT_CENTER);
        SelectObject(hdc_memBuffer, hOldFont);
        DeleteObject(hFont_lishu);
    }
    break;
    case STAGE_MAPDESIGNGAME_START:
    {
        HFONT hFont_lishu = CreateFont(
            70,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 2.5,                // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("隶书")           // 字体名称
        );
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont_lishu);
        RECT blindgame = { 50,170,1150,240 };
        DrawText(hdc_memBuffer, TEXT("鉴于你已经陪姥爷完成了10次冒险"), -1, &blindgame, DT_CENTER);
        blindgame = { 100,270,1100,340 };
        DrawText(hdc_memBuffer, TEXT("这一局你可以自行定义地图"), -1, &blindgame, DT_CENTER);
        SelectObject(hdc_memBuffer, hOldFont);
        DeleteObject(hFont_lishu);
    }
    break;
    case STAGE_TIMELIMITEDGAME_START:
    {
        HFONT hFont_lishu = CreateFont(
            70,                       // 字体高度
            0,                        // 字体宽度（0 表示自动计算）
            0,                        // 字体的倾斜角度
            0,                        // 字体的基线倾斜角度
            FW_NORMAL * 2.5,                // 字体的粗细
            FALSE,                    // 是否斜体
            FALSE,                    // 是否下划线
            FALSE,                    // 是否删除线
            DEFAULT_CHARSET,          // 字符集
            OUT_DEFAULT_PRECIS,       // 输出精度
            CLIP_DEFAULT_PRECIS,      // 剪裁精度
            DEFAULT_QUALITY,          // 输出质量
            DEFAULT_PITCH | FF_SWISS, // 字体家族和间距
            TEXT("隶书")           // 字体名称
        );
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont_lishu);
        RECT blindgame = { 50,170,1150,240 };
        DrawText(hdc_memBuffer, TEXT("姥爷说这次“任务紧急”"), -1, &blindgame, DT_CENTER);
        blindgame = { 100,270,1100,340 };
        DrawText(hdc_memBuffer, TEXT("所以这一局的时间十分有限..."), -1, &blindgame, DT_CENTER);
        SelectObject(hdc_memBuffer, hOldFont);
        DeleteObject(hFont_lishu);
    }
    break;
    default:
    break;
    }
    // TODO：添加多个游戏场景
    // 绘制按钮到缓存
    for (int i = 0; i < buttons.size(); i++)
    {
        Button* button = buttons[i];
        SelectObject(hdc_loadBmp, button->img);
        TransparentBlt(
            hdc_memBuffer, button->x, button->y,
            button->width, button->height,
            hdc_loadBmp, 0, 0, button->width, button->height,
            RGB(255, 255, 255));
    }

    // 最后将所有的信息绘制到屏幕上
    BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);

    // 回收资源所占的内存（非常重要）
    DeleteObject(blankBmp);
    DeleteDC(hdc_loadBmp);
    DeleteDC(hdc_memBuffer);

    // 结束绘制
    EndPaint(hWnd, &ps);
}

// 创建纯白背景图像
HBITMAP CreateWhiteBackground(HWND hWnd)
{
    // 开始绘制
    PAINTSTRUCT ps;
    HDC hdc_window = BeginPaint(hWnd, &ps);

    // 创建缓存
    HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);

    // 初始化缓存
    HBITMAP bmp_output = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
    SelectObject(hdc_memBuffer, bmp_output);

    // 创建纯白色画刷
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));

    // 创建一个矩形
    RECT rect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };

    // 将缓存填充为白色
    FillRect(hdc_memBuffer, &rect, hBrush);

    // 回收资源所占的内存（非常重要）
    DeleteObject(hBrush);
    DeleteDC(hdc_memBuffer);

    // 结束绘制
    EndPaint(hWnd, &ps);

    return bmp_output;
}

// 创建游戏背景
HBITMAP CreateGameBackground(HWND hWnd)
{
    // 开始绘制
    PAINTSTRUCT ps;
    HDC hdc_window = BeginPaint(hWnd, &ps);

    // 创建缓存
    HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
    HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

    // 初始化缓存
    HBITMAP bmp_output = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
    SelectObject(hdc_memBuffer, bmp_output);

    // 初始化为白色背景
    SelectObject(hdc_loadBmp, bmp_background9);
    BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);

    // 画四周石头
    SelectObject(hdc_loadBmp, bmp_summer_small);
    for (int i = 0; i < BG_ROWS; i++)
    {
        BitBlt(hdc_memBuffer, 0, i * BG_CELL_HEIGHT, BG_CELL_WIDTH, BG_CELL_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
        BitBlt(hdc_memBuffer, (BG_COLUMNS - 1) * BG_CELL_WIDTH, i * BG_CELL_HEIGHT, BG_CELL_WIDTH, BG_CELL_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
        BitBlt(hdc_memBuffer, (BG_COLUMNS - 9) * BG_CELL_WIDTH, i * BG_CELL_HEIGHT, BG_CELL_WIDTH, BG_CELL_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
    }
    for (int j = 0; j < BG_COLUMNS; j++)
    {
        BitBlt(hdc_memBuffer, j * BG_CELL_WIDTH, 0, BG_CELL_WIDTH, BG_CELL_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
        BitBlt(hdc_memBuffer, j * BG_CELL_WIDTH, (BG_ROWS - 1) * BG_CELL_HEIGHT, BG_CELL_WIDTH, BG_CELL_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
    }
    for (int j = RIGHT_LINE+1; j < BG_COLUMNS; j++)
    {
        BitBlt(hdc_memBuffer, j * BG_CELL_WIDTH, 5 * BG_CELL_HEIGHT, BG_CELL_WIDTH, BG_CELL_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
    }

    // 回收资源所占的内存（非常重要）
    DeleteDC(hdc_loadBmp);
    DeleteDC(hdc_memBuffer);

    // 结束绘制
    EndPaint(hWnd, &ps);

    return bmp_output;
}

#pragma endregion