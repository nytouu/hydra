/* See LICENSE file for copyright and license details. */

/* appearance */
#define ICONSIZE 18   /* icon size */
#define ICONSPACING 10 /* space between icon and title */
static const unsigned int refreshrate = 144;
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 16;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 16;       /* vert inner gap between windows */
static const unsigned int gappoh    = 28;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 28;       /* vert outer gap between windows and screen edge */
static const unsigned int panel[]   = {0, 0, 0, 0};//positions: 0-top panel, 1-bottom panel, 2-left panel, 3-right panel
static       unsigned int smartgaps          = 0;        /* 1 means no outer gap when there is only one window, behaves weirdly with barpadding */
static       unsigned int smartborders       = 0;        /* 1 means no border when there is only one window (unless floating) */
static const int showbar            = 1;        /* 0 means no bar */
static const int showtitle          = 1;        /* 0 means no title */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int viewontag          = 0;        /* Switch view on tag switch */
static       int linepx             = 1;        /* 0 means no underline */
static const int rainbowtags  	    = 1;        /* 1 means rainbow tags */
static const int vertpad            = 0;        /* vertical padding of bar */
static const int sidepad            = 0;        /* horizontal padding of bar */
static const int statuspad          = 12;
static const int nmaxmaster         = 3;        /* maximum number of clients allowed in master area */
static const int user_bh            = 38;       /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const unsigned int systraypinning = 1;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 4;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray             = 1;   /* 0 means no systray */
static const unsigned int systrayiconsize = 20; /* systray icon size in px */
static const char slopspawnstyle[]  = "-t 0 -b 2 -c 1.0,0.8,0.7"; /* do NOT define -f (format) here "-t 0 -b 2 -c 0.7,0.6,0.9,0.1 -l" for alternate, hope the highlight thing gets fixed or maybe i should do it myself but im lazy */
static const char slopresizestyle[] = "-t 0 -b 2 -c 1.0,0.8,0.7"; /* do NOT define -f (format) here */
static const int riodraw_borders    = 0;        /* 0 or 1, indicates whether the area drawn using slop includes the window borders */
static const int riodraw_matchpid   = 1;        /* 0 or 1, indicates whether to match the PID of the client that was spawned with riospawn */
static const int riodraw_spawnasync = 0;        /* 0 spawns after successful sel, 1 spawn during selection */
static const char *fonts[]          = {
    "SF Pro Display:size=11:style=Regular:autohint=true", 
    "nonicons:size=11",
    "Symbols Nerd Font Mono:size=11:style=Regular", 
    "Siji:size=14"
};
static const char dmenufont[]       = "SF Mono:size=12:style=Medium";
static char black[]           = "#0a0a0a";
static char darkgray[]        = "#1a1b26";
static char gray[]            = "#414868";
static char blue[]            = "#7aa2f7";
static char red[]             = "#f7768e";
static char green[]           = "#9ece6a";
static char purple[]          = "#bb9af2";
static char orange[]          = "#e0af68";
static char yellow[]          = "#e0d168";
static char lightblue[]       = "#7dcfff";
static char white[]           = "#c0caf5";
static char border[]          = "#ffffff";
static char buttoncolor[]     = "#7aa2f7";
static const unsigned int baralpha  = 0xe5; // 0xe5 - 0xf2 = 0.95
static const unsigned int borderalpha = OPAQUE;
static const char buttonbar[]       = "󰘳 ";
static const char *colors[][3]      = {
	/*               	fg          bg          border   */
	[SchemeNorm]      = { white,    darkgray,   black   },
	[SchemeSel]       = { white,    blue,       border  },
	[SchemeUrg]       = { darkgray, red,        red     },
    [SchemeInfo]   	  = { white,    darkgray,   blue    },
	[SchemeTag]  	  = { white, 	darkgray,   white   },
	[SchemeTag1] 	  = { green, 	darkgray,   black   },
	[SchemeTag2] 	  = { purple, 	darkgray,   black   },
	[SchemeTag3]      = { red, 	    darkgray,   black   },
	[SchemeTag4] 	  = { orange,	darkgray,   black   },
	[SchemeTag5]      = { blue,     darkgray,   black   },
	[SchemeTag6]      = { lightblue,darkgray,   black   },
	[SchemeTag7]      = { yellow,	darkgray,   black   },
	[SchemeButton]    = { buttoncolor, darkgray,black   },
	[SchemeAlt]       = { white,	darkgray,   black   },
	[SchemeAlt1] 	  = { green, 	darkgray,   black   },
	[SchemeAlt2] 	  = { purple, 	darkgray,   black   },
	[SchemeAlt3]      = { red, 	    darkgray,   black   },
	[SchemeAlt4] 	  = { orange,	darkgray,   black   },
	[SchemeAlt5]      = { blue,     darkgray,   black   },
	[SchemeAlt6]      = { lightblue,darkgray,   black   },
	[SchemeAlt7]      = { yellow,	darkgray,   black   },
};
static const unsigned int alphas[][3] = {
	/*               fg      bg        border     */
	[SchemeNorm]      = { OPAQUE, baralpha, borderalpha  },
	[SchemeSel]       = { OPAQUE, baralpha, borderalpha  },
	[SchemeUrg]       = { baralpha, OPAQUE, borderalpha  }, // idk why fg and bg colors are inverted but it works so who cares
    [SchemeInfo]   	  = { OPAQUE, baralpha, borderalpha  },
	[SchemeTag]  	  = { OPAQUE, baralpha, borderalpha  },
	[SchemeTag1] 	  = { OPAQUE, baralpha, borderalpha  },
	[SchemeTag2] 	  = { OPAQUE, baralpha, borderalpha  },
	[SchemeTag3]      = { OPAQUE, baralpha, borderalpha  },
	[SchemeTag4] 	  = { OPAQUE, baralpha, borderalpha  },
	[SchemeTag5]      = { OPAQUE, baralpha, borderalpha  },
	[SchemeTag6]      = { OPAQUE, baralpha, borderalpha  },
	[SchemeTag7]      = { OPAQUE, baralpha, borderalpha  },
	[SchemeButton]    = { OPAQUE, OPAQUE,   borderalpha  },
    [SchemeAlt]       = { OPAQUE, OPAQUE,   borderalpha  },
	[SchemeAlt1] 	  = { OPAQUE, OPAQUE,   borderalpha  },
	[SchemeAlt2] 	  = { OPAQUE, OPAQUE,   borderalpha  },
	[SchemeAlt3]      = { OPAQUE, OPAQUE,   borderalpha  },
	[SchemeAlt4] 	  = { OPAQUE, OPAQUE,   borderalpha  },
	[SchemeAlt5]      = { OPAQUE, OPAQUE,   borderalpha  },
	[SchemeAlt6]      = { OPAQUE, OPAQUE,   borderalpha  },
	[SchemeAlt7]      = { OPAQUE, OPAQUE,   borderalpha  },
};
ResourcePref resources[] = {
	{ "border",     STRING,  &border },
	{ "white",     	STRING,  &white },
	{ "lightblue",  STRING,  &lightblue },
	{ "yellow",    	STRING,  &yellow },
	{ "orange",    	STRING,  &orange },
	{ "purple",    	STRING,  &purple },
	{ "green",     	STRING,  &green },
	{ "red",     	STRING,  &red },
	{ "blue",     	STRING,  &blue },
	{ "gray",     	STRING,  &gray },
	{ "darkgray",   STRING,  &darkgray },
	{ "black",     	STRING,  &black },
	{ "buttoncolor",STRING,  &buttoncolor },
};
static const XPoint stickyicon[]    = { {0,0}, {4,0}, {4,8}, {2,6}, {0,8}, {0,0} }; /* represents the icon as an array of vertices */
static const XPoint stickyiconbb    = {4,8};	/* defines the bottom right corner of the polygon's bounding box (speeds up scaling) */

/* staticstatus */
static const int statmonval = 0;

/* tagging */
static const char *tags[] = { "", "","", "󰈹", "󰊖", "󰙯", ""};
static const int tagschemes[] = { SchemeTag1, SchemeTag2, SchemeTag3, SchemeTag4, SchemeTag5, SchemeTag6, SchemeTag7 };
static const int altschemes[] = { SchemeAlt1, SchemeAlt2, SchemeAlt3, SchemeAlt4, SchemeAlt5, SchemeAlt6, SchemeAlt7 };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class            instance        title           tags mask     isfloating   isterminal noswallow   isfullscreen  monitor */
	{ "discord",        NULL,           NULL,           1<<5,         0,           0,         0,          0,            -1 },
	{ "vesktop",        NULL,           NULL,           1<<5,         0,           0,         0,          0,            -1 },
	{ "LibreWolf",      NULL,           NULL,           1<<3,         0,           0,         1,          0,            -1 },
	{ "firefox",        NULL,           NULL,           1<<3,         0,           0,         1,          0,            -1 },
	{ "Deno",           NULL,       "Peek preview",     0,            0,           0,         1,          0,            -1 },
	{ "Steam",          NULL,           NULL,           1,            0,           0,         0,          0,            -1 },
	{ "steam",          NULL,           NULL,           1,            0,           0,         0,          0,            -1 },
	{ "steam_app_252950", NULL,         NULL,           1<<4,         0,           0,         0,          0,            -1 },
	{ "osu!.exe",       NULL,           NULL,           1<<4,         0,           0,         0,          0,            -1 },
	{ "LibreWolf",      "Toolkit",      NULL,           0,            1,           0,         0,          0,            -1 },
	{ "firefox",        "Toolkit",      NULL,           0,            1,           0,         0,          0,            -1 },
	{ "kdeconnect.daemon", "kdeconnectd", NULL,         0,            1,           0,         0,          1,            -1 },
	{ "Thunar",        NULL, "File Operation Progress", 0,            1,           0,         0,          0,            -1 },
	{ "Carla2-Plugin",  "carla-plugin", NULL,           0,            1,           0,         0,          0,            -1 },
	{ "Blueberry.py",   NULL,           NULL,           0,            1,           0,         0,          0,            -1 },
	{ "Nitrogen",       NULL,    	    NULL,           0,            1,           0,         0,          0,            -1 },
	{ "Galculator",     NULL,    	    NULL,           0,            1,           0,         0,          0,            -1 },
	{ "Maya-2024",      NULL,    	    "Maya-2024",    0,            1,           0,         0,          0,            -1 },
	{ "Maya-2024",      NULL,    "Attribute Editor",    0,            1,           0,         0,          0,            -1 },
	{ "Connman-gtk",    NULL,           NULL,           0,            1,           0,         0,          0,            -1 },
	{ "Engrampa",       NULL,           NULL,           0,            1,           0,         0,          0,            -1 },
	{ "File-roller",    NULL,           NULL,           0,            1,           0,         0,          0,            -1 },
	{ "steam_proton",   NULL,           NULL,           0,            1,           0,         0,          0,            -1 },
	{ "pulsemixer", 	NULL,    	    NULL,           0,            1,           0,         0,          0,            -1 },
	{ "calcurse", 	    NULL,    	    NULL,           0,            1,           0,         0,          0,            -1 },
	{ "ncmpcpp", 	    NULL,    	    NULL,           0,            1,           0,         0,          0,            -1 },
    { NULL,             "Godot_Engine", NULL,           0,            0,           0,         1,          0,            -1 },
	{ "st",             NULL,           NULL,           0,            0,           1,         0,          0,            -1 },
	{ NULL,             NULL,           "Event Tester", 0,            0,           0,         1,          0,            -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int decorhints  = 1;    /* 1 means respect decoration hints */

#include "gaps.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "󰽙",      tile },    /* first entry is default */
	{ "󰊕",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle },
	{ "󱒅",      centeredmaster },
	{ "",      spiral },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
/* static const char *dmenucmd[] = { "dmenu_run", NULL }; */
static const char *dmenucmd[] = { "rofi", "-show", "drun", NULL };
static const char *termcmd[] = { "st", "-e", "tmux", NULL };

#include <X11/XF86keysym.h>

#include "selfrestart.c"

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    /* apps */
	{ MODKEY,                       XK_b,      spawn,          SHCMD("firefox") },
	{ MODKEY,                       XK_n,      spawn,          SHCMD("thunar") },
	{ MODKEY|ShiftMask,             XK_n,      spawn,          SHCMD("st -e lf") },
	{ MODKEY,                       XK_t,      spawn,          SHCMD("st -e htop") },
	{ MODKEY|ShiftMask,             XK_m,      spawn,          SHCMD("st -c ncmpcpp -e ncmpcpp") },
    /* useful keybinds */
    { MODKEY,                       XK_r,      spawn,          SHCMD("dmenurecord") },
	{ MODKEY,                       XK_x,      spawn,          SHCMD("xkill") },
	{ MODKEY,                       XK_p,      spawn,          SHCMD("maim $HOME/pics/screenshots/$(date +%d-%m-%G-%T).png && screenshotnotify") },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("sleep 0.3 && maim -s $HOME/pics/screenshots/$(date +%d-%m-%G-%T).png && screenshotnotify") },
	{ MODKEY|ControlMask,           XK_p,      spawn,          SHCMD("cd $HOME/pics/screenshots && sxiv $(/bin/ls -t | head -n1)") },
	{ MODKEY|ShiftMask,             XK_h,      spawn,          SHCMD("colorpicknotify") },
	{ MODKEY|ControlMask,           XK_x,      spawn,          SHCMD("kill -USR1 $(pidof st)") },
	/* { MODKEY|ShiftMask,             XK_d,      spawn,          SHCMD("[ $(dunstctl is-paused) ] && (dunstctl set-paused false && notify-send -a Notifications \"Disabled\") || (dunstctl set-paused true && notify-send -a Notifications \"Enabled\")") }, */
	{ MODKEY|ShiftMask,             XK_d,      spawn,          SHCMD("dunstctl set-paused toggle") },
	{ MODKEY|ShiftMask,             XK_c,      spawn,          SHCMD("[ ! $(pgrep compfy) ] && (notify-send -r 555 -a Picom Enabled && compfy) || (notify-send -r 555 -a Picom Disabled && pkill compfy)") },
	{ Mod1Mask,                     XK_Tab,    spawn,          SHCMD("skippy-xd --switch --next") },
	{ Mod1Mask|ShiftMask,           XK_Tab,    spawn,          SHCMD("skippy-xd --switch --prev") },
    /* keyboard */
	{ Mod1Mask|ShiftMask,           XK_f,      spawn,          SHCMD("setxkbmap fr # && pkill -RTMIN+5 hydrablocks") },
	{ Mod1Mask|ShiftMask,           XK_e,      spawn,          SHCMD("setxkbmap us # && pkill -RTMIN+5 hydrablocks") },
    /* fn keys */
    { (unsigned int)NULL,          XF86XK_MonBrightnessDown, spawn,          SHCMD("brightnessctl s 10-%% && pkill -RTMIN+9 hydrablocks && notify-send -r 555 -a Brightness \"$(printf \"%.0f\\n\" \"$(brightnessctl g -P)\")\"%") },
    { (unsigned int)NULL,          XF86XK_MonBrightnessUp,   spawn,          SHCMD("brightnessctl s 10+%% 1 && pkill -RTMIN+9 hydrablocks && notify-send -r 555 -a Brightness \"$(printf \"%.0f\\n\" \"$(brightnessctl g -P)\")\"%") },
    { (unsigned int)NULL,          XF86XK_AudioMute,         spawn,          SHCMD("pamixer -t && pkill -RTMIN+4 hydrablocks && notify-send -r 555 -a Volume $( [ $(pamixer --get-mute) = \"true\" ] && (echo Muted) || (echo Unmuted) )") },
    { (unsigned int)NULL,          XF86XK_AudioRaiseVolume,  spawn,          SHCMD("pamixer -i 1 && pkill -RTMIN+4 hydrablocks && notify-send -r 555 -a Volume \"$(pamixer --get-volume)\"%") },
    { (unsigned int)NULL,          XF86XK_AudioLowerVolume,  spawn,          SHCMD("pamixer -d 1 && pkill -RTMIN+4 hydrablocks && notify-send -r 555 -a Volume \"$(pamixer --get-volume)\"%") },
    { (unsigned int)NULL,          XF86XK_AudioPrev,         spawn,          SHCMD("mpc prev && songnotify") },
    { (unsigned int)NULL,          XF86XK_AudioNext,         spawn,          SHCMD("mpc next && songnotify") },
    { (unsigned int)NULL,          XF86XK_AudioPlay,         spawn,          SHCMD("mpc toggle") },
    /* mpc */
	{ Mod1Mask|ControlMask,         XK_h,      spawn,          SHCMD("mpc prev") },
	{ Mod1Mask|ControlMask,         XK_l,      spawn,          SHCMD("mpc next") },
	{ Mod1Mask|ControlMask,         XK_j,      spawn,          SHCMD("mpc volume -2") },
	{ Mod1Mask|ControlMask,         XK_k,      spawn,          SHCMD("mpc volume +2") },
	{ Mod1Mask|ControlMask,         XK_space,  spawn,          SHCMD("mpc toggle") },
    /* rio */
	{ MODKEY|ControlMask,           XK_r,      rioresize,      {0} },
    /* dwm stuff */
	{ MODKEY|ShiftMask,             XK_u,      togglebar,      {0} },
	{ MODKEY,                       XK_s,      togglesticky,   {0} },
	{ MODKEY,                       XK_f,      togglefullscr,  {0} },
    { MODKEY,                       XK_u,      focusurgent,    {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_o,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,             			XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_a,      killclient,     {0} }, /* a = q on qwerty */
	{ MODKEY,           		    XK_w,      cyclelayout,    {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_w,      cyclelayout,    {.i = +1 } },
	{ MODKEY,                       XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_Left,   viewtoleft,     {0} },
	{ MODKEY|ShiftMask,             XK_Right,  viewtoright,    {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_agrave, view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_agrave, tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_v,      focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_v,      tagmon,         {.i = +1 } },
	{ MODKEY|ControlMask,           XK_x,      xrdb,           {.v = NULL } },
    /* TODO need to find a way to reset both mfact and cfact */
    { MODKEY|ShiftMask,             XK_f,      setmfact,       {.f =  0.50} },
	{ MODKEY|ShiftMask,             XK_f,      setcfact,       {.f =  0.00} },
    /* maxmize when gaps */
    { MODKEY,             			XK_m,      togglesmart,    {0} },
	/* gaps */
	{ MODKEY,             			XK_g,      togglegaps,     {0} },
	{ MODKEY|ShiftMask,    			XK_g,      defaultgaps,    {0} },
	{ MODKEY|ControlMask,           XK_KP_Add, incrgaps,       {.i = +1 } },
	{ MODKEY|ControlMask,    		XK_KP_Subtract, incrgaps,  {.i = -1 } },
    /* for azerty */
	TAGKEYS(                        XK_ampersand,              0)
	TAGKEYS(                        XK_eacute,                 1)
	TAGKEYS(                        XK_quotedbl,               2)
	TAGKEYS(                        XK_apostrophe,             3)
	TAGKEYS(                        XK_parenleft,              4)
	TAGKEYS(                        XK_minus,                  5)
	TAGKEYS(                        XK_egrave,                 6)
    /* for qwerty */
	TAGKEYS(                        XK_1,					   0)
	TAGKEYS(                        XK_2,					   1)
	TAGKEYS(                        XK_3,					   2)
	TAGKEYS(                        XK_4,					   3)
	TAGKEYS(                        XK_5,					   4)
	TAGKEYS(                        XK_6,					   5)
	TAGKEYS(                        XK_7,					   6)
    { MODKEY|ShiftMask,             XK_r,      self_restart,   {0} },
	{ MODKEY|ShiftMask,             XK_e,      spawn,          SHCMD("powermenu")},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkButton,		    0,		        Button1,	    spawn,		      {.v = dmenucmd } },
	{ ClkWinTitle,          0,              Button2,        zoom,             {0} },
	{ ClkStatusText,        0,              Button1,        sighydrablocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sighydrablocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sighydrablocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sighydrablocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sighydrablocks,   {.i = 5} },
    /* placemouse : 0=tiled pos rel to m cur 1=tiled pos rel to win center 2=m cur warps to win center */
	{ ClkClientWin,         MODKEY,         Button1,        moveorplace,    {.i = 0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizeorfacts,  {0} },
	{ ClkClientWin,       MODKEY|ShiftMask, Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask, Button1,      dragmfact,      {0} },
	{ ClkClientWin,         MODKEY|ShiftMask, Button3,      dragcfact,      {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
