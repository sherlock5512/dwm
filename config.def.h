/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int	borderpx		= 3;   /* border pixel of windows */
static const unsigned int	snap			= 32;  /* snap pixel */
static const int		swallowfloating		= 0;   /* 1 means swallow floating windows by default */
static const unsigned int	gappih			= 20;  /* horiz inner gap between windows */
static const unsigned int	gappiv			= 10;  /* vert inner gap between windows */
static const unsigned int	gappoh			= 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int	gappov			= 10;  /* vert outer gap between windows and screen edge */
static int			smartgaps		= 1;   /* 1 means no outer gap when there is only one window */
static const char		autostartblocksh[]	= "autostart_blocking.sh";
static const char		autostartsh[]		= "autostart.sh";
static const char		dwmdir[]		= "dwm";
static const char		localshare[]		= ".local/share";
static const int		showbar			= 1;   /* 0 means no bar */
static const int		topbar			= 1;   /* 0 means bottom bar */
static const unsigned int	systrayspacing		= 0;   /* systray spacing */
static const int		showsystray		= 1;   /* 0 means no systray */

/* Indicators: see patch/bar_indicators.h for options */
static int 			tagindicatortype	= INDICATOR_CLIENT_DOTS;
static int 			floatindicatortype	= INDICATOR_TOP_LEFT_SQUARE;

static const char 		statussep		= ';'; /* separator between status bars */
static const char 		dmenufont[]		= "JetBrainsMono Nerd Font:size=8";
static const char 		*fonts[]		= { "Noto Color Emoji:size=8",
							"serif:size=9",
							"mono:size=8" };


/* Colour Settings: HTML colour codes encased in quotes as # makes fuckery happen otherwise */

static char 			normfgcolor[]		= "#BBBBBB"; /* Foreground of status bar */
static char 			normbgcolor[]		= "#132613"; /* Background of status bar */
static char 			normbordercolor[]	= "#222222"; /* Unselected window border colour (also bar border)*/
static char 			normfloatcolor[]	= "#2D1738"; /* Unselected floating window border colour*/

static char			selfgcolor[]		= "#EEEEEE"; /* Dmenu Selected item colour */
static char			selbgcolor[]		= "#007722"; /* Dmenu Selected item Background */
static char			selbordercolor[]	= "#CC549C"; /* Selected window border colour */
static char			selfloatcolor[]		= "#cc55cc"; /* Selected floating window border colour */

static char			titlenormfgcolor[]	= "#EEEEEE"; /* Foreground of unselected window title */
static char			titlenormbgcolor[]	= "#132613"; /* Background of unselected window title */
static char			titlenormbordercolor[]	= "#ffffff"; /* UNUSED ?? */
static char			titlenormfloatcolor[]	= "#ffffff"; /* UNUSED ?? */

static char			titleselfgcolor[]	= "#EEEEEE"; /* Foreground of selected window title */
static char			titleselbgcolor[]	= "#007722"; /* Backgroud of selected window title */
static char			titleselbordercolor[]	= "#FFFFFF"; /* UNUSED ?? */
static char			titleselfloatcolor[]	= "#FFFFFF"; /* UNUSED ?? */

static char			tagsnormfgcolor[]	= "#BBBBBB"; /* Tag unselected text colour */
static char			tagsnormbgcolor[]	= "#222222"; /* Tag unselected background colour */
static char			tagsnormbordercolor[]	= "#FFFFFF"; /* UNUSED ?? */
static char			tagsnormfloatcolor[]	= "#FFFFFF"; /* UNUSED ?? */

static char			tagsselfgcolor[]	= "#EEEEEE"; /* Tag selected tect colour */
static char			tagsselbgcolor[]	= "#007722"; /* Tag selected background colour */
static char			tagsselbordercolor[]	= "#FFFFFF"; /* UNUSED ?? */
static char			tagsselfloatcolor[]	= "#FFFFFF"; /* UNUSED ?? */

static char			hidfgcolor[]		= "#226622"; /* Hidden window text colour */
static char			hidbgcolor[]		= "#000000"; /* Hidden windon background color */
static char			hidbordercolor[]	= "#005577"; /* UNUSED ?? */
static char			hidfloatcolor[]		= "#f76e0c"; /* UNUSED ?? */

static char			urgfgcolor[]		= "#FFFFFF"; /* Urgent Tag Foreground colour */
static char			urgbgcolor[]		= "#FF7000"; /* Urgent Tag Background colour */
static char			urgbordercolor[]	= "#FF7000"; /* urgent window border colour */
static char			urgfloatcolor[]		= "#FF7070"; /* urgent FLOATING window border colour */

/* Alpha Settings */
static const unsigned int 	baralpha	= 0xD0; /* 208 */
static const unsigned int 	hidalpha	= 0x4D; /* 77 */
static const unsigned int 	borderalpha	= OPAQUE; /* COMPILER MACRO see dwm.c */

/* Alpha Schemes */
static const unsigned int alphas[][3]	= {
	/*			    fg		bg		border		*/
	[SchemeNorm]		= { OPAQUE,	baralpha,	borderalpha },
	[SchemeSel]		= { OPAQUE,	baralpha,	borderalpha },
	[SchemeTitleNorm]	= { OPAQUE,	baralpha,	borderalpha },
	[SchemeTitleSel]	= { OPAQUE,	baralpha,	borderalpha },
	[SchemeTagsNorm]	= { OPAQUE,	baralpha,	borderalpha },
	[SchemeTagsSel]		= { OPAQUE,	baralpha,	borderalpha },
	[SchemeHid]		= { baralpha,	hidalpha,	borderalpha }, /* Text is slightly transparent */
	[SchemeUrg]		= { OPAQUE,	OPAQUE,		borderalpha }, /* URGENCY IS OPAQUE*/
};

/* Color Schemes */
static char *colors[][ColCount] = {
	/*			    fg			bg			border			float */
	[SchemeNorm]		= { normfgcolor,	normbgcolor,		normbordercolor,	normfloatcolor },
	[SchemeSel]		= { selfgcolor,		selbgcolor,		selbordercolor,		selfloatcolor },
	[SchemeTitleNorm]	= { titlenormfgcolor,	titlenormbgcolor,	titlenormbordercolor,	titlenormfloatcolor },
	[SchemeTitleSel]	= { titleselfgcolor, 	titleselbgcolor,  	titleselbordercolor,	titleselfloatcolor },
	[SchemeTagsNorm]	= { tagsnormfgcolor,	tagsnormbgcolor,	tagsnormbordercolor,	tagsnormfloatcolor },
	[SchemeTagsSel]		= { tagsselfgcolor,	tagsselbgcolor,		tagsselbordercolor,	tagsselfloatcolor },
	[SchemeHid]		= { hidfgcolor,		hidbgcolor,		hidbordercolor,		hidfloatcolor },
	[SchemeUrg]		= { urgfgcolor,		urgbgcolor,		urgbordercolor,		urgfloatcolor },
};


/* Scratchpad Settings */
	const char *spcmd1[] = {"st", "-n", "spterm",	"-g", "120x34", 			NULL };
	const char *spcmd2[] = {"st", "-n", "spfm",	"-g", "144x41", "-e", "ranger", 	NULL };
	const char *spcmd3[] = {"st", "-n", "spmocp",	"-g", "140x20", "-e", "mocp", 		NULL };
	const char *spcmd4[] = {"st", "-n", "stMENU",			"-e", "Launcher.sh", 	NULL };
	const char *spcmd5[] = {"st", "-n", "stMAIL",	"-g", "200x50",	"-e", "neomutt", 	NULL };

static Sp scratchpads[] = {
	/* name		cmd  */
	{"spterm",	spcmd1},
	{"spranger",	spcmd2},
	{"spmocp",	spcmd3},
	{"MENU",	spcmd4},
	{"mail",	spcmd5},
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] = {
	[DEFAULT_TAGS]		= { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]	= { "", "", "", "", "", "", "ﭮ", "", "" },
	[ALT_TAGS_DECORATION]	= { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG"	FLOATING)
	RULE(.wintype = WTYPE "UTILITY"	FLOATING)
	RULE(.wintype = WTYPE "TOOLBAR"	FLOATING)
	RULE(.wintype = WTYPE "SPLASH"	FLOATING)

	RULE(.class = "Gimp",		.tags = 1 << 4 )
	RULE(.class = "st-256color"	TERMINAL)
	RULE(.class = "Google-chrome",	.tags = 1 << 1 )
	RULE(.class = "discord",	.tags = 1 << 6 )
	RULE(.class = "qBittorrent",	.tags = 1 << 8 )
	RULE(.class = "Tor Browser",	.tags = 1 << 1 )

	RULE(.instance = "SoulseekQt",	.tags = 1 << 8)
	RULE(.instance = "spterm",	.tags = SPTAG(0) FLOATING TERMINAL)
	RULE(.instance = "spfm",	.tags = SPTAG(1) FLOATING)
	RULE(.instance = "spmocp",	.tags = SPTAG(2) FLOATING)
	RULE(.instance = "stMENU",	.tags = SPTAG(3) FLOATING)
	RULE(.instance = "stMAIL",	.tags = SPTAG(4) FLOATING)

	RULE(.title = "FLOATER",	.tags = ~0 FLOATING)
	RULE(.title = "Event Tester"	NOSWALLOW)
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor  bar    alignment         widthfunc                drawfunc                clickfunc                name */
	{ -1,       0,     BAR_ALIGN_LEFT,   width_tags,              draw_tags,              click_tags,              "tags" },
	{ 'A',       0,     BAR_ALIGN_RIGHT,  width_systray,           draw_systray,           click_systray,           "systray" },
	{ -1,       0,     BAR_ALIGN_LEFT,   width_ltsymbol,          draw_ltsymbol,          click_ltsymbol,          "layout" },
	{ 'A',       0,     BAR_ALIGN_RIGHT,  width_status,            draw_status,            click_statuscmd,         "status" },
	{ -1,       0,     BAR_ALIGN_NONE,   width_awesomebar,        draw_awesomebar,        click_awesomebar,        "awesomebar" },
	{ -1,      1,     BAR_ALIGN_CENTER, width_status_es,         draw_status_es,         click_statuscmd_es,      "status_es" },
};

/* layout(s) */
static const float mfact	= 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster	= 1;    /* number of clients in master area */
static const int resizehints	= 1;    /* 1 means respect size hints in tiled resizals */
static const int decorhints	= 1;    /* 1 means respect decoration hints */

#define FORCE_VSPLIT 1

static const Layout layouts[] = {
	/* symbol	arrange function */
	{ "[]=",	tile },    /* first entry is default */
	{ "><>",	NULL },    /* no layout function means floating behavior */
	{ "[M]",	monocle },
	{ "TTT",	bstack },
	{ "===",	bstackhoriz },
	{ "|M|",	centeredmaster },
	{ "[D]",	deck },
	{ "(@)",	spiral },
	{ "[\\]",	dwindle }, // fibbonaci?
	{ "HHH",	grid },
	{ "---",	horizgrid },
	{ "###",	nrowgrid },
	{ NULL,		NULL },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	topbar ? NULL : "-b",
	NULL
};
static const char *termcmd[]	= { "st", NULL };
static const char *lockcmd[]	= { "slockWrap", NULL};
static const char *rangercmd[]	= {"st", "-e", "ranger", NULL};

#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier			key		function		argument */

	/* BASIC FUNCTIONALITY */
	{ MODKEY,			XK_p,		spawn,			{.v = dmenucmd } },
	{ MODKEY|ShiftMask,		XK_Return,	spawn,			{.v = termcmd } },
	//{ MODKEY|ShiftMask,		XK_q,		quit,			{0} }, // exit
	{ MODKEY|ControlMask|ShiftMask,	XK_q,		quit,			{1} }, // reload
	{ MODKEY,			XK_b,		togglebar,		{0} },
	{ MODKEY|ControlMask,		XK_z,		showhideclient,		{0} },
	{ MODKEY|ShiftMask,		XK_c,		killclient,		{0} },

	/* STACK CONTROL */
	{ MODKEY,			XK_j,		focusstack,		{.i = +1 } },
	{ MODKEY,			XK_k,		focusstack,		{.i = -1 } },
	{ MODKEY,			XK_i,		incnmaster,		{.i = +1 } },
	{ MODKEY,			XK_d,		incnmaster,		{.i = -1 } },
	{ MODKEY,			XK_h,		setmfact,		{.f = -0.05} },
	{ MODKEY,			XK_l,		setmfact,		{.f = +0.05} },
	{ MODKEY|ShiftMask,		XK_j,		movestack,		{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_k,		movestack,		{.i = -1 } },
	{ MODKEY,			XK_Return,	zoom,			{0} },

	/* GAP CONTROL */
	{ MODKEY|Mod4Mask,		XK_u,		incrgaps,		{.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,	XK_u,		incrgaps,		{.i = -1 } },
	{ MODKEY|Mod4Mask,		XK_i,		incrigaps,		{.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,	XK_i,		incrigaps,		{.i = -1 } },
	{ MODKEY|Mod4Mask,		XK_o,		incrogaps,		{.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,	XK_o,		incrogaps,		{.i = -1 } },
	{ MODKEY|Mod4Mask,		XK_6,		incrihgaps,		{.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,	XK_6,		incrihgaps,		{.i = -1 } },
	{ MODKEY|Mod4Mask,		XK_7,		incrivgaps,		{.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,	XK_7,		incrivgaps,		{.i = -1 } },
	{ MODKEY|Mod4Mask,		XK_8,		incrohgaps,		{.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,	XK_8,		incrohgaps,		{.i = -1 } },
	{ MODKEY|Mod4Mask,		XK_9,		incrovgaps,		{.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,	XK_9,		incrovgaps,		{.i = -1 } },
	{ MODKEY|Mod4Mask,		XK_0,		togglegaps,		{0} },
	{ MODKEY|Mod4Mask,		XK_s,		togglesmartgaps,	{0} },
	{ MODKEY|Mod4Mask|ShiftMask,	XK_0,		defaultgaps,		{0} },


	/* LAYOUT CONTROL */
	{ MODKEY,			XK_t,		setlayout,		{.v = &layouts[0]} },
	{ MODKEY,			XK_f,		setlayout,		{.v = &layouts[1]} },
	{ MODKEY,			XK_m,		setlayout,		{.v = &layouts[2]} },
	{ MODKEY,			XK_c,		setlayout,		{.v = &layouts[3]} },
	{ MODKEY,			XK_space,	setlayout,		{0} },
	{ MODKEY|ControlMask,		XK_comma,	cyclelayout,		{.i = -1 } },
	{ MODKEY|ControlMask,		XK_period,	cyclelayout,		{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_space,	togglefloating,		{0} },

	/* SCRATCHPAD CONTROL */
	{ MODKEY,			XK_grave,	togglescratch,		{.ui = 0 } },
	{ MODKEY|ControlMask,		XK_grave,	togglescratch,		{.ui = 1 } },
	{ MODKEY|ShiftMask,		XK_grave,	togglescratch,		{.ui = 2 } },
	{ MODKEY|ControlMask,		XK_p,		togglescratch,		{.ui = 3 } },
	{ MODKEY|ShiftMask,		XK_m,		togglescratch,		{.ui = 4 } },

	/* MULTIMON CONTROL */
	{ MODKEY,			XK_comma,	focusmon,		{.i = -1 } },
	{ MODKEY,			XK_period,	focusmon,		{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_comma,	tagmon,			{.i = -1 } },
	{ MODKEY|ShiftMask,		XK_period,	tagmon,			{.i = +1 } },

	/* SPAWN PROGRAMS*/
	{ Mod4Mask,			XK_l,		spawn,			{.v = lockcmd } },
	{ Mod4Mask,			XK_period,	spawn,			SHCMD("dmenuunicode") },
	{ MODKEY,			XK_r,		spawn,			{.v = rangercmd}},
	{ Mod4Mask,			XK_v,		spawn,			SHCMD("videoDownload") },
	{ MODKEY,			XK_slash,	spawn,			SHCMD("dmenuman") },
	{ MODKEY,			XK_e,		spawn,			SHCMD("deopkg") },
	{ 0,				XK_Print,	spawn,			SHCMD("xscrot")},
	/* TAG CONTROL*/
	{ MODKEY,			XK_n,		togglealttag,		{0} },
	{ MODKEY,			XK_0,		view,			{.ui = ~0 } },
	{ MODKEY|ShiftMask,		XK_0,		tag,			{.ui = ~0 } },
	{ MODKEY,			XK_Tab,		view,			{0} },

	/* TAG KEYS */
	TAGKEYS(			XK_1,		0)
	TAGKEYS(			XK_2,		1)
	TAGKEYS(			XK_3,		2)
	TAGKEYS(			XK_4,		3)
	TAGKEYS(			XK_5,		4)
	TAGKEYS(			XK_6,		5)
	TAGKEYS(			XK_7,		6)
	TAGKEYS(			XK_8,		7)
	TAGKEYS(                        XK_9,		8)

	/* XF86XK bindings */
	{ 0,	XF86XK_AudioMute,		spawn,	SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	{ 0,	XF86XK_AudioRaiseVolume,	spawn,	SHCMD("pamixer --allow-boost -i 1; kill -44 $(pidof dwmblocks)")},
	{ 0,	XF86XK_AudioLowerVolume,	spawn,	SHCMD("pamixer --allow-boost -d 1; kill -44 $(pidof dwmblocks)")},

	// { 0,	XF86XK_HomePage,		spawn,	SHCMD("~/bin/dwmChrome") }, // TODO: FIX FOR THINKPAD

	{ 0,	XF86XK_MonBrightnessDown,	spawn,	SHCMD("~/bin/backlight -dec")}, // TODO: FIX FOR THINKPAD
	{ 0,	XF86XK_MonBrightnessUp,  	spawn,	SHCMD("~/bin/backlight -inc")}, // TODO: FIX FOR THINKPAD
	{ 0,	XF86XK_Display,			spawn,	SHCMD("displayselect") },
	// TODO: ADD MUSIC SUPPORT (USE SCRIPT TO ALLOW FOR ALL EVENTUALITIES (MAYBE ALSO MPRIS))
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click		event mask		button		function	argument */
	{ ClkLtSymbol,		0,			Button1,        setlayout,      {0} },
	{ ClkLtSymbol,		0,			Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,		0,			Button1,        togglewin,      {0} },
	{ ClkWinTitle,		0,			Button3,        showhideclient, {0} },
	{ ClkWinTitle,		0,			Button2,        zoom,           {0} },
	{ ClkStatusText,	0,			Button1,        sigdwmblocks,   {.i = 1 } },
	{ ClkStatusText,	0,			Button2,        sigdwmblocks,   {.i = 2 } },
	{ ClkStatusText,	0,			Button3,        sigdwmblocks,   {.i = 3 } },
	{ ClkStatusText,	0,			Button4,        sigdwmblocks,   {.i = 4 } },
	{ ClkStatusText,	0,			Button5,        sigdwmblocks,   {.i = 5 } },
	{ ClkStatusText,	ShiftMask,		Button1,        sigdwmblocks,   {.i = 6 } },
	{ ClkClientWin,		MODKEY,			Button1,        movemouse,      {0} },
	{ ClkClientWin,		MODKEY,			Button2,        togglefloating, {0} },
	{ ClkClientWin,		MODKEY,			Button3,        resizemouse,    {0} },
	{ ClkTagBar,		0,			Button1,        view,           {0} },
	{ ClkTagBar,		0,			Button3,        toggleview,     {0} },
	{ ClkTagBar,		MODKEY,			Button1,        tag,            {0} },
	{ ClkTagBar,		MODKEY,			Button3,        toggletag,      {0} },
};
