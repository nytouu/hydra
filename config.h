/* See LICENSE file for copyright and license details. */

/* appearance */
#define ICONSIZE 16   /* icon size */
#define ICONSPACING 8 /* space between icon and title */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 10;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 12;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 12;       /* vert inner gap between windows */
static const unsigned int gappoh    = 20;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 20;       /* vert outer gap between windows and screen edge */
static const char buttonbar[]       = "";
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window, behaves weirdly with barpadding */
static const int smartborders       = 0;        /* 1 means no border when there is only one window (unless floating) */
static const int showbar            = 1;        /* 0 means no bar */
static const int statmonval         = 0;
static const int topbar             = 1;        /* 0 means bottom bar */
static const int viewontag          = 1;        /* Switch view on tag switch */
static const unsigned int systraypinning = 1;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray             = 1;   /* 0 means no systray */
static       int linepx             = 2;        /* 0 means no underline */
static const int vertpad            = 8;       /* vertical padding of bar */
static const int sidepad            = 12;       /* horizontal padding of bar */
static const int nmaxmaster         = 3;        /* maximum number of clients allowed in master area */
static const int user_bh            = 28;       /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const int pertag             = 1;
static const char slopspawnstyle[]  = "-t 0 -b 2 -c 0.5,0.6,1.0"; /* do NOT define -f (format) here "-t 0 -b 2 -c 0.7,0.6,0.9,0.1 -l" for alternate, hope the highlight thing gets fixed or maybe i should do it myself but im lazy */
static const char slopresizestyle[] = "-t 0 -b 2 -c 0.5,0.6,1.0"; /* do NOT define -f (format) here */
static const int riodraw_borders    = 0;        /* 0 or 1, indicates whether the area drawn using slop includes the window borders */
static const int riodraw_matchpid   = 1;        /* 0 or 1, indicates whether to match the PID of the client that was spawned with riospawn */
static const int riodraw_spawnasync = 0;        /* 0 spawns after successful sel, 1 spawn during selection */
static const char *fonts[]          = { "Roboto Mono:size=11:style=Medium", "RobotoMono Nerd Font:size=13:style=Medium", "Siji:size=13" };
static const char dmenufont[]       = "Roboto Mono:size=12:style=Medium";
static const char col_gray1[]       = "#1a1b26"; // default bg color
static const char col_gray2[]       = "#414868"; // unfocused border
static const char col_gray3[]       = "#c0caf5"; // fg color
static const char col_cyan[]        = "#7aa2f7"; // accent color
static const char col_red[]         = "#f7768e"; // urgent color
static const unsigned int baralpha = 0x70;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               	fg         bg         border   */
	[SchemeNorm]      = { col_gray3, col_gray1, col_gray1 },
	[SchemeSel]       = { col_gray3, col_cyan,  col_gray2 },
	[SchemeUrg]       = { col_gray1, col_red,   col_red   }, // idk why fg and bg colors are inverted but it works so who cares
    [SchemeTagsNorm]  = { col_gray3, col_gray1, col_gray2 }, // tags in the middle of the bar
	[SchemeTagsSel]   = { col_cyan,  col_cyan,  col_cyan  }, // selected tags
    [SchemeInfo]   	  = { col_gray3, col_gray1, col_cyan  }, // focused window name text
};
static const unsigned int alphas[][3] = {
	/*               fg      bg        border     */
	[SchemeNorm]      = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]       = { OPAQUE, baralpha, borderalpha },
	[SchemeUrg]       = { baralpha, OPAQUE, borderalpha }, // idk why fg and bg colors are inverted but it works so who cares
    [SchemeTagsNorm]  = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]   = { OPAQUE, baralpha, borderalpha },
    [SchemeInfo]   	  = { OPAQUE, baralpha, borderalpha  }
};
static const XPoint stickyicon[]    = { {0,0}, {4,0}, {4,8}, {2,6}, {0,8}, {0,0} }; /* represents the icon as an array of vertices */
static const XPoint stickyiconbb    = {4,8};	/* defines the bottom right corner of the polygon's bounding box (speeds up scaling) */

/* tagging */
/* static const char *tags[] = { "I", "II","III", "IV", "V", "VI", "VII"}; */
static const char *tags[] = { "", "","", "", "", "ﭮ", ""};
/* static const char *tags[] = { "home", "tty", "www", "game", "chat", "misc"}; */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   isterminal noswallow   monitor */
	{ "discord",  NULL,       NULL,       1<<5,         0,           0,         0,          -1 },
	{ "Firefox",  NULL,       NULL,       0,            0,           0,         0,          -1 },
	{ "Carla2-Plugin","carla-plugin",NULL,0,            1,           0,         0,          -1 },
	{ NULL, NULL, "BakkesModInjectorCpp", 0,            1,           0,         0,          -1 },
	{ "Blueberry.py",NULL,    NULL,       0,            1,           0,         0,          -1 },
	{ "Nitrogen", NULL,    	  NULL,       0,            1,           0,         0,          -1 },
	{ "Connman-gtk", NULL,    NULL,       0,            1,           0,         0,          -1 },
	{ "Engrampa",    NULL,    NULL,       0,            1,           0,         0,          -1 },
	{ "st", 	  NULL,    	 "pulsemixer",0,            1,           0,         0,          -1 },
	{ "st", 	  NULL,    	  "calculse", 0,            1,           0,         0,          -1 },
	{ "st",       NULL,       NULL,       0,            0,           1,         0,          -1 },
	{ NULL,      NULL,     "Event Tester", 0,           0,           0,         1,          -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int decorhints  = 1;    /* 1 means respect decoration hints */

#include "gaps.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },    /* first entry is default */
	{ "",      NULL },    /* no layout function means floating behavior */
	{ "",      centeredmaster },
	{ "",      spiral },
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
static const char *dmenucmd[] = { "dmenu_run" };
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    /* rio */
	{ MODKEY,                       XK_r,      rioresize,      {0} },
	{ MODKEY|ControlMask,           XK_Return, riospawn,       {.v = termcmd } },
    { MODKEY|ControlMask,           XK_n,      riospawn,       SHCMD("$FILEBROWSER")},
    { MODKEY|ShiftMask|ControlMask, XK_n,      riospawn,       SHCMD("$TERMINAL -e ranger")},
    { MODKEY|ControlMask,           XK_b,      riospawn,       SHCMD("$BROWSER")},
    { MODKEY|ControlMask,           XK_t,      riospawn,       SHCMD("$TERMINAL -e htop")},
    { MODKEY|ControlMask,           XK_c,      riospawn,       SHCMD("$TERMINAL -e calcurse")},
    { MODKEY|ControlMask,           XK_m,      riospawn,       SHCMD("$TERMINAL -e ncmpcpp")},
    /* dwm stuff */
	{ MODKEY|ShiftMask,             XK_u,      togglebar,      {0} },
	{ MODKEY,                       XK_s,      togglesticky,   {0} },
	{ MODKEY,                       XK_f,      togglefullscr,  {0} },
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
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_agrave, view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_agrave, tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_v,      focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_v,      tagmon,         {.i = +1 } },
    /* TODO need to find a way to reset both mfact and cfact */
    { MODKEY|ShiftMask,             XK_f,      setmfact,       {.f =  0.50} },
	{ MODKEY|ShiftMask,             XK_f,      setcfact,       {.f =  0.00} },
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
	TAGKEYS(                        XK_underscore,             7)
	TAGKEYS(                        XK_ccedilla,               8)
    /* for qwerty */
	TAGKEYS(                        XK_1,					   0)
	TAGKEYS(                        XK_2,					   1)
	TAGKEYS(                        XK_3,					   2)
	TAGKEYS(                        XK_4,					   3)
	TAGKEYS(                        XK_5,					   4)
	TAGKEYS(                        XK_6,					   5)
	TAGKEYS(                        XK_7,					   6)
	TAGKEYS(                        XK_8,					   7)
	TAGKEYS(                        XK_9,					   8)
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
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask, Button1,      dragmfact,      {0} },
	{ ClkClientWin,         MODKEY|ShiftMask, Button3,      dragcfact,      {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
