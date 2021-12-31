/* $Id: dw.h 2246 2021-01-05 01:52:35Z bsmith $ */

#ifndef _H_DW
#define _H_DW

#ifdef __cplusplus
extern "C" {
#endif

/* Dynamic Windows version numbers */
#define DW_MAJOR_VERSION 3
#define DW_MINOR_VERSION 1
#define DW_SUB_VERSION 0

#define DW_HOME_URL "http://dwindows.netlabs.org"

/* Support for API deprecation in supported compilers */
#ifndef __has_attribute
# define __has_attribute(x) 0
#endif

#ifndef __has_extension
# define __has_extension __has_feature
#endif
    
#ifndef __has_feature
# define __has_feature(x) 0
#endif
    
#ifndef __GNUC_PREREQ
# if defined(__GNUC__) && defined(__GNUC_MINOR__)
#  define __GNUC_PREREQ(maj, min) ((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
# else
#  define __GNUC_PREREQ(maj, min) 0
# endif
#endif

/* Visual C */
#if defined(_MSC_VER)
#  if _MSC_VER >= 1400
#  define DW_DEPRECATED(func, message) __declspec(deprecated(message)) func
#  endif
/* Clang or GCC */
#elif __has_extension(attribute_deprecated_with_message) || __GNUC_PREREQ(4, 5)
#  define DW_DEPRECATED(func, message) func __attribute__((deprecated (message)))
#elif __has_extension(attribute_deprecated) || __GNUC_PREREQ(3, 1)
#  define DW_DEPRECATED(func, message) func __attribute__((deprecated))
#endif

/* Compiler without deprecation support */
#ifndef DW_DEPRECATED
#define DW_DEPRECATED(func, message) func
#endif

/* Support for unused variables in supported compilers */
#if __has_attribute(unused) || __GNUC_PREREQ(2, 95)
#define DW_UNUSED(x) x __attribute__((__unused__))
#else
#define DW_UNUSED(x) x
#endif

/* These corespond to the entries in the color
 * arrays in the Win32 dw.c, they are also the
 * same as DOS ANSI colors.
 */
#define DW_CLR_BLACK             0
#define DW_CLR_DARKRED           1
#define DW_CLR_DARKGREEN         2
#define DW_CLR_BROWN             3
#define DW_CLR_DARKBLUE          4
#define DW_CLR_DARKPINK          5
#define DW_CLR_DARKCYAN          6
#define DW_CLR_PALEGRAY          7
#define DW_CLR_DARKGRAY          8
#define DW_CLR_RED               9
#define DW_CLR_GREEN             10
#define DW_CLR_YELLOW            11
#define DW_CLR_BLUE              12
#define DW_CLR_PINK              13
#define DW_CLR_CYAN              14
#define DW_CLR_WHITE             15
#define DW_CLR_DEFAULT           16

/* Signal handler defines */
#define DW_SIGNAL_CONFIGURE      "configure_event"
#define DW_SIGNAL_KEY_PRESS      "key_press_event"
#define DW_SIGNAL_BUTTON_PRESS   "button_press_event"
#define DW_SIGNAL_BUTTON_RELEASE "button_release_event"
#define DW_SIGNAL_MOTION_NOTIFY  "motion_notify_event"
#define DW_SIGNAL_DELETE         "delete_event"
#define DW_SIGNAL_EXPOSE         "expose_event"
#define DW_SIGNAL_CLICKED        "clicked"
#define DW_SIGNAL_ITEM_ENTER     "container-select"
#define DW_SIGNAL_ITEM_CONTEXT   "container-context"
#define DW_SIGNAL_ITEM_SELECT    "tree-select"
#define DW_SIGNAL_LIST_SELECT    "item-select"
#define DW_SIGNAL_SET_FOCUS      "set-focus"
#define DW_SIGNAL_VALUE_CHANGED  "value_changed"
#define DW_SIGNAL_SWITCH_PAGE    "switch-page"
#define DW_SIGNAL_COLUMN_CLICK   "click-column"
#define DW_SIGNAL_TREE_EXPAND    "tree-expand"
#define DW_SIGNAL_HTML_CHANGED   "html-changed"
#define DW_SIGNAL_HTML_RESULT    "html-result"

/* status of menu items */
#define DW_MIS_ENABLED           1
#define DW_MIS_DISABLED          (1 << 1)
#define DW_MIS_CHECKED           (1 << 2)
#define DW_MIS_UNCHECKED         (1 << 3)

/* Gravity */
#define DW_GRAV_TOP              0
#define DW_GRAV_LEFT             0
#define DW_GRAV_CENTER           1
#define DW_GRAV_RIGHT            2
#define DW_GRAV_BOTTOM           2
#define DW_GRAV_OBSTACLES        (1 << 10)

/* ensure we can build the Gtk port with MingW on Windows */
#if defined(DW_USE_GTK) && defined(__MINGW32__)
# ifndef GDK_WINDOWING_WIN32
#   define GDK_WINDOWING_WIN32
# endif
#endif

#if defined(__OS2__) || (defined(__WIN32__) && !defined(GDK_WINDOWING_WIN32)) || defined(__MAC__) || defined(__EMX__) || defined(__TEMPLATE__)
/* OS/2, Windows or MacOS */

#ifdef __OS2__
# if (defined(__IBMC__) || defined(__WATCOMC__) || defined(_System)) && !defined(API)
# define API _System
# endif
#endif

/* Used internally */
#define TYPEBOX  0
#define TYPEITEM 1

#define SIZESTATIC 0
#define SIZEEXPAND 1

#define SPLITBAR_WIDTH 4

typedef struct _user_data
{
   struct _user_data *next;
   void              *data;
   char              *varname;
} UserData;

/* OS/2 Specific section */
#if defined(__OS2__) || defined(__EMX__)
#define INCL_DOS
#define INCL_WIN
#define INCL_GPI

#include <os2.h>

#define DW_DT_LEFT               DT_LEFT
#define DW_DT_QUERYEXTENT        DT_QUERYEXTENT
#define DW_DT_UNDERSCORE         DT_UNDERSCORE
#define DW_DT_STRIKEOUT          DT_STRIKEOUT
#define DW_DT_TEXTATTRS          DT_TEXTATTRS
#define DW_DT_EXTERNALLEADING    DT_EXTERNALLEADING
#define DW_DT_CENTER             DT_CENTER
#define DW_DT_RIGHT              DT_RIGHT
#define DW_DT_TOP                DT_TOP
#define DW_DT_VCENTER            DT_VCENTER
#define DW_DT_BOTTOM             DT_BOTTOM
#define DW_DT_HALFTONE           DT_HALFTONE
#define DW_DT_MNEMONIC           DT_MNEMONIC
#define DW_DT_WORDBREAK          DT_WORDBREAK
#define DW_DT_ERASERECT          DT_ERASERECT

#ifndef FCF_CLOSEBUTTON
#define FCF_CLOSEBUTTON            0x04000000L
#endif

#define DW_FCF_CLOSEBUTTON       0
#define DW_FCF_TITLEBAR          FCF_TITLEBAR
#define DW_FCF_SYSMENU           (FCF_SYSMENU | FCF_CLOSEBUTTON)
#define DW_FCF_MENU              FCF_MENU
#define DW_FCF_SIZEBORDER        FCF_SIZEBORDER
#define DW_FCF_MINBUTTON         FCF_MINBUTTON
#define DW_FCF_MAXBUTTON         FCF_MAXBUTTON
#define DW_FCF_MINMAX            FCF_MINMAX
#define DW_FCF_DLGBORDER         FCF_DLGBORDER
#define DW_FCF_BORDER            FCF_BORDER
#define DW_FCF_TASKLIST          FCF_TASKLIST
#define DW_FCF_NOMOVEWITHOWNER   FCF_NOMOVEWITHOWNER
#define DW_FCF_SYSMODAL          FCF_SYSMODAL
#define DW_FCF_HIDEBUTTON        FCF_HIDEBUTTON
#define DW_FCF_HIDEMAX           FCF_HIDEMAX
#define DW_FCF_AUTOICON          FCF_AUTOICON
#define DW_FCF_MAXIMIZE          WS_MAXIMIZED
#define DW_FCF_MINIMIZE          WS_MINIMIZED
#define DW_FCF_TEXTURED          0
#define DW_FCF_FULLSCREEN        0

#define DW_CFA_BITMAPORICON      CFA_BITMAPORICON
#define DW_CFA_STRING            CFA_STRING
#define DW_CFA_ULONG             CFA_ULONG
#define DW_CFA_TIME              CFA_TIME
#define DW_CFA_DATE              CFA_DATE
#define DW_CFA_CENTER            CFA_CENTER
#define DW_CFA_LEFT              CFA_LEFT
#define DW_CFA_RIGHT             CFA_RIGHT
#define DW_CFA_HORZSEPARATOR     CFA_HORZSEPARATOR
#define DW_CFA_SEPARATOR         CFA_SEPARATOR
#define DW_CFA_STRINGANDICON     0

#define DW_CRA_SELECTED          CRA_SELECTED
#define DW_CRA_CURSORED          CRA_CURSORED

#define DW_CR_RETDATA            (1 << 10)

#define DW_LS_MULTIPLESEL        LS_MULTIPLESEL

#define DW_LIT_NONE              -1

#define DW_MLE_CASESENSITIVE     MLFSEARCH_CASESENSITIVE

#define DW_POINTER_DEFAULT       0
#define DW_POINTER_ARROW         SPTR_ARROW
#define DW_POINTER_CLOCK         SPTR_WAIT
#define DW_POINTER_QUESTION      SPTR_ICONQUESTION

#define DW_BS_NOBORDER           BS_NOBORDER

/* flag values for dw_messagebox() */
#define DW_MB_OK                 MB_OK
#define DW_MB_OKCANCEL           MB_OKCANCEL
#define DW_MB_YESNO              MB_YESNO
#define DW_MB_YESNOCANCEL        MB_YESNOCANCEL

#define DW_MB_WARNING            MB_WARNING
#define DW_MB_ERROR              MB_ERROR
#define DW_MB_INFORMATION        MB_INFORMATION
#define DW_MB_QUESTION           MB_QUERY

/* Virtual Key Codes */
#define VK_LBUTTON           VK_BUTTON1
#define VK_RBUTTON           VK_BUTTON2
#define VK_MBUTTON           VK_BUTTON3
#define VK_RETURN            VK_NEWLINE
#define VK_SNAPSHOT          VK_PRINTSCRN
#define VK_CANCEL            VK_BREAK
#define VK_CAPITAL           VK_CAPSLOCK
#define VK_ESCAPE            VK_ESC
#define VK_PRIOR             VK_PAGEUP
#define VK_NEXT              VK_PAGEDOWN
#define VK_SELECT            133
#define VK_EXECUTE           134
#define VK_PRINT             135
#define VK_HELP              136
#define VK_LWIN              137
#define VK_RWIN              138
#define VK_MULTIPLY          ('*' + 128)
#define VK_ADD               ('+' + 128)
#define VK_SEPARATOR         141
#define VK_SUBTRACT          ('-' + 128)
#define VK_DECIMAL           ('.' + 128)
#define VK_DIVIDE            ('/' + 128)
#define VK_SCROLL            VK_SCRLLOCK
#define VK_LSHIFT            VK_SHIFT
#define VK_RSHIFT            147
#define VK_LCONTROL          VK_CTRL
#define VK_RCONTROL          149
#define VK_NUMPAD0           ('0' + 128)
#define VK_NUMPAD1           ('1' + 128)
#define VK_NUMPAD2           ('2' + 128)
#define VK_NUMPAD3           ('3' + 128)
#define VK_NUMPAD4           ('4' + 128)
#define VK_NUMPAD5           ('5' + 128)
#define VK_NUMPAD6           ('6' + 128)
#define VK_NUMPAD7           ('7' + 128)
#define VK_NUMPAD8           ('8' + 128)
#define VK_NUMPAD9           ('9' + 128)
#define VK_BACK              VK_BACKSPACE
#define VK_LMENU             VK_MENU
#define VK_RMENU             VK_MENU

#define BUBBLE_HELP_MAX 256

typedef struct _window_data {
   PFNWP oldproc;
   UserData *root;
   HWND clickdefault;
   ULONG flags;
   void *data;
   char bubbletext[BUBBLE_HELP_MAX];
} WindowData;

typedef struct _hpixmap {
   unsigned long width, height;
   HDC hdc;
   HPS hps;
   HBITMAP hbm;
   HWND handle, font;
   unsigned long transcolor;
   int depth;
} *HPIXMAP;

typedef void *HTREEITEM;
typedef HWND HMENUI;
typedef HMODULE HMOD;
typedef unsigned short UWORD;
typedef unsigned long HSHM;
typedef unsigned long HICN;

extern HAB dwhab;
extern HMQ dwhmq;

#include <stdio.h>

/* Mostly safe but slow snprintf() for compilers that don't have it...
 * like VisualAge.  So we can write safe code and still use VAC to test.
 */
#if defined(__IBMC__) && !defined(snprintf)
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
static int _dw_snprintf(char *str, size_t size, const char *format, ...)
{
   va_list args;
   char *outbuf = calloc(1, size + strlen(format) + 1024);
   int retval = -1;

   if(outbuf)
   {
      va_start(args, format);
      vsprintf(outbuf, format, args);
      va_end(args);
      retval = strlen(outbuf);
      strncpy(str, outbuf, size);
      free(outbuf);
   }
   return retval;
}
#define snprintf _dw_snprintf
#endif

#endif

#if defined(__MAC__)
/* MacOS specific section */
#include <pthread.h>
#include <dlfcn.h>

/* Unfortunately using Cocoa we can't include
 * Cocoa.h from C code, so we have to instead
 * use opaque types and use the values from
 * Cocoa.h in the header here directly without
 * using the symbolic names.
 */

#define TRUE 1
#define FALSE 0

typedef void *HWND;
typedef void *HSHM;
typedef unsigned long ULONG;
typedef long LONG;
typedef unsigned short USHORT;
typedef short SHORT;
typedef unsigned short UWORD;
typedef short WORD ;
typedef unsigned char UCHAR;
typedef char CHAR;
typedef unsigned UINT;
typedef int INT;
typedef pthread_mutex_t *HMTX;
typedef struct _dw_unix_event {
   pthread_mutex_t mutex;
   pthread_cond_t event;
   pthread_t thread;
   int alive;
   int posted;
} *HEV;
typedef pthread_t DWTID;
typedef void * HMOD;
struct _dw_unix_shm {
   int fd;
   char *path;
   int sid;
   int size;
};
typedef void *HTREEITEM;
typedef void *HMENUI;
typedef void *HICN;

typedef struct _window_data {
   UserData *root;
   HWND clickdefault;
   ULONG flags;
   void *data;
} WindowData;

typedef struct _hpixmap {
    unsigned long width, height;
    void *image, *font;
    HWND handle;
} *HPIXMAP;

void _dw_pool_drain(void);

#define DW_DT_LEFT               0 /* NSLeftTextAlignment */
#define DW_DT_QUERYEXTENT        0
#define DW_DT_UNDERSCORE         0
#define DW_DT_STRIKEOUT          0
#define DW_DT_TEXTATTRS          0
#define DW_DT_EXTERNALLEADING    0
#define DW_DT_CENTER             2 /* NSCenterTextAlignment */
#define DW_DT_RIGHT              1 /* NSRightTextAlignment */
#define DW_DT_TOP                0
#define DW_DT_VCENTER            (1 << 10)
#define DW_DT_BOTTOM             0
#define DW_DT_HALFTONE           0
#define DW_DT_MNEMONIC           0
#define DW_DT_WORDBREAK          (1 << 11)
#define DW_DT_ERASERECT          0

#define DW_FCF_CLOSEBUTTON       (1 << 1) /* NSClosableWindowMask */
#define DW_FCF_TITLEBAR          (1 << 0) /* NSTitledWindowMask */
#define DW_FCF_SYSMENU           (1 << 1) /* NSClosableWindowMask */
#define DW_FCF_MENU              0
#define DW_FCF_SIZEBORDER        (1 << 3) /* NSResizableWindowMask */
#define DW_FCF_MINBUTTON         (1 << 2) /* NSMiniaturizableWindowMask */
#define DW_FCF_MAXBUTTON         0
#define DW_FCF_MINMAX            (1 << 2) /* NSMiniaturizableWindowMask */
#define DW_FCF_DLGBORDER         0
#define DW_FCF_BORDER            0
#define DW_FCF_TASKLIST          0
#define DW_FCF_NOMOVEWITHOWNER   0
#define DW_FCF_SYSMODAL          0
#define DW_FCF_HIDEBUTTON        0
#define DW_FCF_HIDEMAX           0
#define DW_FCF_AUTOICON          0
#define DW_FCF_MAXIMIZE          0
#define DW_FCF_MINIMIZE          0
#define DW_FCF_TEXTURED          (1 << 8) /* NSTexturedBackgroundWindowMask */
#define DW_FCF_FULLSCREEN        (1 << 4)

#define DW_CFA_BITMAPORICON      1
#define DW_CFA_STRING            (1 << 1)
#define DW_CFA_ULONG             (1 << 2)
#define DW_CFA_TIME              (1 << 3)
#define DW_CFA_DATE              (1 << 4)
#define DW_CFA_CENTER            (1 << 5)
#define DW_CFA_LEFT              (1 << 6)
#define DW_CFA_RIGHT             (1 << 7)
#define DW_CFA_STRINGANDICON     (1 << 8)
#define DW_CFA_HORZSEPARATOR     0
#define DW_CFA_SEPARATOR         0

#define DW_CRA_SELECTED          1
#define DW_CRA_CURSORED          (1 << 1)

#define DW_CR_RETDATA            (1 << 10)

#define DW_LS_MULTIPLESEL        1

#define DW_LIT_NONE              -1

#define DW_MLE_CASESENSITIVE     2 /* NSLiteralSearch */

#define DW_BS_NOBORDER           1

#define DW_POINTER_DEFAULT       0
#define DW_POINTER_ARROW         1
#define DW_POINTER_CLOCK         2
#define DW_POINTER_QUESTION      3

#define HWND_DESKTOP     ((HWND)0)

/* flag values for dw_messagebox() */
#define DW_MB_OK                 (1 << 1)
#define DW_MB_OKCANCEL           (1 << 2)
#define DW_MB_YESNO              (1 << 3)
#define DW_MB_YESNOCANCEL        (1 << 4)

#define DW_MB_WARNING            (1 << 10)
#define DW_MB_ERROR              (1 << 11)
#define DW_MB_INFORMATION        (1 << 12)
#define DW_MB_QUESTION           (1 << 13)

/* Virtual Key Codes */
#define VK_LBUTTON               0xFF10 /* TODO */
#define VK_RBUTTON               0xFF11 /* TODO */
#define VK_CANCEL                0xFF12 /* TODO */
#define VK_MBUTTON               0xFF13 /* TODO */
#define VK_BACK                  0x7F
#define VK_TAB                   0x09
#define VK_CLEAR                 71
#define VK_RETURN                13
#define VK_MENU                  0xF735 /* NSMenuFunctionKey */
#define VK_PAUSE                 0xF730 /* NSPauseFunctionKey */
#define VK_CAPITAL               57
#define VK_ESCAPE                0x1B
#define VK_SPACE                 ' '
#define VK_PRIOR                 0xF72C /* NSPageUpFunctionKey */
#define VK_NEXT                  0xF72D /* NSPageDownFunctionKey */
#define VK_END                   0xF72B /* NSEndFunctionKey */
#define VK_HOME                  0xF729 /* NSHomeFunctionKey */
#define VK_LEFT                  0xF702 /* NSLeftArrowFunctionKey */
#define VK_UP                    0xF700 /* NSUpArrowFunctionKey */
#define VK_RIGHT                 0xF703 /* NSRightArrowFunctionKey */
#define VK_DOWN                  0xF701 /* NSDownArrowFunctionKey */
#define VK_SELECT                0xF741 /* NSSelectFunctionKey */
#define VK_PRINT                 0xF738 /* NSPrintFunctionKey */
#define VK_EXECUTE               0xF742 /* NSExecuteFunctionKey */
#define VK_SNAPSHOT              0xF72E /* NSPrintScreenFunctionKey */
#define VK_INSERT                0xF727 /* NSInsertFunctionKey */
#define VK_DELETE                0xF728 /* NSDeleteFunctionKey */
#define VK_HELP                  0xF746 /* NSHelpFunctionKey */
#define VK_LWIN                  55
#define VK_RWIN                  0xFF14 /* TODO */
#define VK_NUMPAD0               82
#define VK_NUMPAD1               83
#define VK_NUMPAD2               84
#define VK_NUMPAD3               85
#define VK_NUMPAD4               86
#define VK_NUMPAD5               87
#define VK_NUMPAD6               88
#define VK_NUMPAD7               89
#define VK_NUMPAD8               91
#define VK_NUMPAD9               92
#define VK_MULTIPLY              67
#define VK_ADD                   69
#define VK_SEPARATOR             0xFF15 /* TODO */
#define VK_SUBTRACT              78
#define VK_DECIMAL               65
#define VK_DIVIDE                75
#define VK_F1                    0xF704 /* NSF1FunctionKey */
#define VK_F2                    0xF705 /* NSF2FunctionKey */
#define VK_F3                    0xF706 /* NSF3FunctionKey */
#define VK_F4                    0xF707 /* NSF4FunctionKey */
#define VK_F5                    0xF708 /* NSF5FunctionKey */
#define VK_F6                    0xF709 /* NSF6FunctionKey */
#define VK_F7                    0xF70A /* NSF7FunctionKey */
#define VK_F8                    0xF70B /* NSF8FunctionKey */
#define VK_F9                    0xF70C /* NSF9FunctionKey */
#define VK_F10                   0xF70D /* NSF10FunctionKey */
#define VK_F11                   0xF70E /* NSF11FunctionKey */
#define VK_F12                   0xF70F /* NSF12FunctionKey */
#define VK_F13                   0xF710 /* NSF13FunctionKey */
#define VK_F14                   0xF711 /* NSF14FunctionKey */
#define VK_F15                   0xF712 /* NSF15FunctionKey */
#define VK_F16                   0xF713 /* NSF16FunctionKey */
#define VK_F17                   0xF714 /* NSF17FunctionKey */
#define VK_F18                   0xF715 /* NSF18FunctionKey */
#define VK_F19                   0xF716 /* NSF19FunctionKey */
#define VK_F20                   0xF717 /* NSF20FunctionKey */
#define VK_F21                   0xF718 /* NSF21FunctionKey */
#define VK_F22                   0xF719 /* NSF22FunctionKey */
#define VK_F23                   0xF71A /* NSF23FunctionKey */
#define VK_F24                   0xF71B /* NSF24FunctionKey */
#define VK_NUMLOCK               0xFF16 /* TODO */
#define VK_SCROLL                0xF72F /* NSScrollLockFunctionKey */
#define VK_LSHIFT                56
#define VK_RSHIFT                60
#define VK_LCONTROL              59
#define VK_RCONTROL              62
#define VK_LMENU                 0xF735 /* NSMenuFunctionKey */
#define VK_RMENU                 0xF735 /* NSMenuFunctionKey */

/* Key Modifiers */
#define KC_CTRL                  (1 << 18) /* NSControlKeyMask */
#define KC_SHIFT                 (1 << 17) /* NSShiftKeyMask */
#define KC_ALT                   (1 << 19) /* NSAlternateKeyMask */
#endif

/* Windows specific section */
#if defined(__WIN32__)
#include <winsock2.h>
#include <windows.h>
#include <commctrl.h>

#if defined(MSVC) && !defined(API)
# if defined(__MINGW32__) && defined(BUILD_DLL)
#  define API _cdecl __declspec(dllexport)
# else
#  define API _cdecl
#endif
#define DWSIGNAL _cdecl
#endif

#define DW_DT_LEFT               SS_LEFTNOWORDWRAP
#define DW_DT_QUERYEXTENT        0
#define DW_DT_UNDERSCORE         0
#define DW_DT_STRIKEOUT          0
#define DW_DT_TEXTATTRS          0
#define DW_DT_EXTERNALLEADING    0
#define DW_DT_CENTER             SS_CENTER
#define DW_DT_RIGHT              SS_RIGHT
#define DW_DT_TOP                0
#define DW_DT_VCENTER            (1 << 29)
#define DW_DT_BOTTOM             0
#define DW_DT_HALFTONE           0
#define DW_DT_MNEMONIC           0
#define DW_DT_WORDBREAK          (1 << 28)
#define DW_DT_ERASERECT          0

#define DW_FCF_CLOSEBUTTON       0
#define DW_FCF_TITLEBAR          WS_CAPTION
#define DW_FCF_SYSMENU           WS_SYSMENU
#define DW_FCF_MENU              0
#define DW_FCF_SIZEBORDER        WS_THICKFRAME
#define DW_FCF_MINBUTTON         WS_MINIMIZEBOX
#define DW_FCF_MAXBUTTON         WS_MAXIMIZEBOX
#define DW_FCF_MINMAX            (WS_MINIMIZEBOX|WS_MAXIMIZEBOX)
#define DW_FCF_DLGBORDER         WS_DLGFRAME
#define DW_FCF_BORDER            WS_BORDER
#define DW_FCF_TASKLIST          (1 << 1)
#define DW_FCF_NOMOVEWITHOWNER   0
#define DW_FCF_SYSMODAL          0
#define DW_FCF_HIDEBUTTON        WS_MINIMIZEBOX
#define DW_FCF_HIDEMAX           (WS_MINIMIZEBOX|WS_MAXIMIZEBOX)
#define DW_FCF_AUTOICON          0
#define DW_FCF_MAXIMIZE          WS_MAXIMIZE
#define DW_FCF_MINIMIZE          WS_MINIMIZE
#define DW_FCF_COMPOSITED        1
#define DW_FCF_TEXTURED          0
#define DW_FCF_FULLSCREEN        (1 << 2)

#define DW_CFA_BITMAPORICON      1
#define DW_CFA_STRING            (1 << 1)
#define DW_CFA_ULONG             (1 << 2)
#define DW_CFA_TIME              (1 << 3)
#define DW_CFA_DATE              (1 << 4)
#define DW_CFA_CENTER            (1 << 5)
#define DW_CFA_LEFT              (1 << 6)
#define DW_CFA_RIGHT             (1 << 7)
#define DW_CFA_STRINGANDICON     (1 << 8)
#define DW_CFA_HORZSEPARATOR     0
#define DW_CFA_SEPARATOR         0

#define DW_CRA_SELECTED          LVNI_SELECTED
#define DW_CRA_CURSORED          LVNI_FOCUSED

#define DW_CR_RETDATA            (1 << 10)

#define DW_LS_MULTIPLESEL        LBS_MULTIPLESEL

#define DW_LIT_NONE              -1

#define DW_MLE_CASESENSITIVE     1

#define DW_BS_NOBORDER           BS_FLAT

#define DW_POINTER_DEFAULT       0
#define DW_POINTER_ARROW         32512
#define DW_POINTER_CLOCK         32514
#define DW_POINTER_QUESTION      32651

/* flag values for dw_messagebox() */
#define DW_MB_OK                 MB_OK
#define DW_MB_OKCANCEL           MB_OKCANCEL
#define DW_MB_YESNO              MB_YESNO
#define DW_MB_YESNOCANCEL        MB_YESNOCANCEL

#define DW_MB_WARNING            MB_ICONWARNING
#define DW_MB_ERROR              MB_ICONERROR
#define DW_MB_INFORMATION        MB_ICONINFORMATION
#define DW_MB_QUESTION           MB_ICONQUESTION

/* Key Modifiers */
#define KC_CTRL                  (1)
#define KC_SHIFT                 (1 << 1)
#define KC_ALT                   (1 << 2)

typedef struct _color {
   int fore;
   int back;
   HWND combo, buddy;
   ULONG style;
   RECT rect;
   HWND clickdefault;
   HBRUSH hbrush;
   HFONT hfont;
   HMENU hmenu;
   char fontname[128];
   WNDPROC pOldProc;
   UserData *root;
} ColorInfo;

typedef struct _notebookpage {
   ColorInfo cinfo;
   TC_ITEM item;
   HWND hwnd;
   int realid;
} NotebookPage;

typedef HANDLE HMTX;
typedef HANDLE HEV;
typedef HANDLE HMOD;
typedef HANDLE HSHM;
typedef HANDLE HICN;

typedef struct _container {
   ColorInfo cinfo;
   ULONG *flags;
   ULONG columns;
   COLORREF odd, even;
} ContainerInfo;

typedef struct _hpixmap {
   unsigned long width, height;
   HBITMAP hbm;
   HDC hdc;
   unsigned long transcolor;
   HWND handle;
   void *bits;
   unsigned long depth;
   HFONT font;
} *HPIXMAP;

typedef HWND HMENUI;
#endif

/* Template section, framework for new platform ports */
#if defined(__TEMPLATE__)
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

/* Can remove this for your port when you know where MAX_PATH is */
#ifndef MAX_PATH
#define MAX_PATH 260
#endif

#define TRUE  1
#define FALSE 0

typedef void *HWND;

typedef unsigned long ULONG;
typedef long LONG;
typedef unsigned short USHORT;
typedef short SHORT;
typedef unsigned short UWORD;
typedef short WORD ;
typedef unsigned char UCHAR;
typedef char CHAR;
typedef unsigned UINT;
typedef int INT;
typedef void *HMTX;
typedef void *HEV;
typedef void *HSHM;
typedef void *HMOD;
typedef void *HTREEITEM;
typedef HWND HMENUI;
typedef int DWTID;
typedef unsigned long HICN;

typedef struct _window_data {
   UserData *root;
   HWND clickdefault;
   ULONG flags;
   void *data;
} WindowData;

typedef struct _hpixmap {
   unsigned long width, height;
   /* ?? *pixmap; */
   HWND handle;
} *HPIXMAP;

#define DW_DT_LEFT               0
#define DW_DT_QUERYEXTENT        0
#define DW_DT_UNDERSCORE         0
#define DW_DT_STRIKEOUT          0
#define DW_DT_TEXTATTRS          0
#define DW_DT_EXTERNALLEADING    0
#define DW_DT_CENTER             0
#define DW_DT_RIGHT              0
#define DW_DT_TOP                0
#define DW_DT_VCENTER            0
#define DW_DT_BOTTOM             0
#define DW_DT_HALFTONE           0
#define DW_DT_MNEMONIC           0
#define DW_DT_WORDBREAK          0
#define DW_DT_ERASERECT          0

#define DW_FCF_CLOSEBUTTON       0
#define DW_FCF_TITLEBAR          0
#define DW_FCF_SYSMENU           0
#define DW_FCF_MENU              0
#define DW_FCF_SIZEBORDER        0
#define DW_FCF_MINBUTTON         0
#define DW_FCF_MAXBUTTON         0
#define DW_FCF_MINMAX            (DW_FCF_MINBUTTON|DW_FCF_MAXBUTTON)
#define DW_FCF_DLGBORDER         0
#define DW_FCF_BORDER            0
#define DW_FCF_TASKLIST          0
#define DW_FCF_NOMOVEWITHOWNER   0
#define DW_FCF_SYSMODAL          0
#define DW_FCF_HIDEBUTTON        0
#define DW_FCF_HIDEMAX           0
#define DW_FCF_AUTOICON          0
#define DW_FCF_MAXIMIZE          0
#define DW_FCF_MINIMIZE          0
#define DW_FCF_TEXTURED          0
#define DW_FCF_FULLSCREEN        0

#define DW_CFA_BITMAPORICON      1
#define DW_CFA_STRING            (1 << 1)
#define DW_CFA_ULONG             (1 << 2)
#define DW_CFA_TIME              (1 << 3)
#define DW_CFA_DATE              (1 << 4)
#define DW_CFA_CENTER            (1 << 5)
#define DW_CFA_LEFT              (1 << 6)
#define DW_CFA_RIGHT             (1 << 7)
#define DW_CFA_STRINGANDICON     (1 << 8)
#define DW_CFA_HORZSEPARATOR     0
#define DW_CFA_SEPARATOR         0

#define DW_CRA_SELECTED          1
#define DW_CRA_CURSORED          (1 << 1)

#define DW_CR_RETDATA            (1 << 10)

#define DW_LS_MULTIPLESEL        1

#define DW_LIT_NONE              -1

#define DW_MLE_CASESENSITIVE    0

#define DW_BS_NOBORDER           0

#define DW_POINTER_DEFAULT       0
#define DW_POINTER_ARROW         0
#define DW_POINTER_CLOCK         0
#define DW_POINTER_QUESTION      0

#define HWND_DESKTOP     ((HWND)0)

/* flag values for dw_messagebox() */
#define DW_MB_OK                 (1 << 1)
#define DW_MB_OKCANCEL           (1 << 2)
#define DW_MB_YESNO              (1 << 3)
#define DW_MB_YESNOCANCEL        (1 << 4)

#define DW_MB_WARNING            (1 << 10)
#define DW_MB_ERROR              (1 << 11)
#define DW_MB_INFORMATION        (1 << 12)
#define DW_MB_QUESTION           (1 << 13)

/* Virtual Key Codes */
#define VK_LBUTTON               0
#define VK_RBUTTON               1
#define VK_CANCEL                2
#define VK_MBUTTON               3
#define VK_BACK                  4
#define VK_TAB                   5
#define VK_CLEAR                 6
#define VK_RETURN                7
#define VK_MENU                  8
#define VK_PAUSE                 9
#define VK_CAPITAL               10
#define VK_ESCAPE                11
#define VK_SPACE                 12
#define VK_PRIOR                 13
#define VK_NEXT                  14
#define VK_END                   15
#define VK_HOME                  16
#define VK_LEFT                  17
#define VK_UP                    18
#define VK_RIGHT                 19
#define VK_DOWN                  20
#define VK_SELECT                21
#define VK_PRINT                 22
#define VK_EXECUTE               23
#define VK_SNAPSHOT              24
#define VK_INSERT                25
#define VK_DELETE                26
#define VK_HELP                  27
#define VK_LWIN                  28
#define VK_RWIN                  29
#define VK_NUMPAD0               30
#define VK_NUMPAD1               31
#define VK_NUMPAD2               32
#define VK_NUMPAD3               33
#define VK_NUMPAD4               34
#define VK_NUMPAD5               35
#define VK_NUMPAD6               36
#define VK_NUMPAD7               37
#define VK_NUMPAD8               38
#define VK_NUMPAD9               39
#define VK_MULTIPLY              40
#define VK_ADD                   41
#define VK_SEPARATOR             42
#define VK_SUBTRACT              43
#define VK_DECIMAL               44
#define VK_DIVIDE                45
#define VK_F1                    46
#define VK_F2                    47
#define VK_F3                    48
#define VK_F4                    49
#define VK_F5                    50
#define VK_F6                    51
#define VK_F7                    52
#define VK_F8                    53
#define VK_F9                    54
#define VK_F10                   55
#define VK_F11                   56
#define VK_F12                   57
#define VK_F13                   58
#define VK_F14                   59
#define VK_F15                   60
#define VK_F16                   61
#define VK_F17                   62
#define VK_F18                   63
#define VK_F19                   64
#define VK_F20                   65
#define VK_F21                   66
#define VK_F22                   67
#define VK_F23                   68
#define VK_F24                   69
#define VK_NUMLOCK               70
#define VK_SCROLL                71
#define VK_LSHIFT                72
#define VK_RSHIFT                73
#define VK_LCONTROL              74
#define VK_RCONTROL              75
#define VK_LMENU                 76
#define VK_RMENU                 77

/* Key Modifiers */
#define KC_CTRL                  (1)
#define KC_SHIFT                 (1 << 1)
#define KC_ALT                   (1 << 2)
#endif

typedef struct _item {
   /* Item type - Box or Item */
   int type;
   /* Handle to Frame or Window */
   HWND hwnd;
   /* Width and Height of static size */
   int width, height, origwidth, origheight;
   /* Size Type - Static or Expand */
   int hsize, vsize;
   /* Padding */
   int pad;
} Item;

typedef struct _box {
#if defined(__WIN32__)
   ColorInfo cinfo;
   int fullscreen;
#elif defined(__OS2__) || defined(__EMX__)
   PFNWP oldproc;
   UserData *root;
   HWND hwndtitle, hwnd;
   int titlebar;
#endif
   /* Number of items in the box */
   int count;
   /* Box type - horizontal or vertical */
   int type;
   /* Keep track of how box is packed */
   int hsize, vsize;
   /* Padding */
   int pad, grouppadx, grouppady;
   /* Groupbox */
   HWND grouphwnd;
   /* Default item */
   HWND defaultitem;
   /* Used as temporary storage in the calculation stage */
   int usedpadx, usedpady, minheight, minwidth;
   /* Used for calculating individual item ratios */
   int width, height;
   /* Any combinations of flags describing the box */
   unsigned long flags;
   /* Array of item structures */
   struct _item *items;
} Box;

#else
/* GTK Specific section */
#define _GNU_SOURCE
#include <gtk/gtk.h>
#ifdef GDK_WINDOWING_X11
# include <gdk/gdkx.h>
#else
# include <gdk/gdk.h>
#endif
#include <gdk/gdkprivate.h>
#include <gdk/gdkkeysyms.h>
#include <pthread.h>
#if !defined(GDK_WINDOWING_WIN32)
# include <dlfcn.h>
#endif

#define DW_DT_LEFT               1
#define DW_DT_UNDERSCORE         (1 << 1)
#define DW_DT_STRIKEOUT          (1 << 2)
#define DW_DT_CENTER             (1 << 3)
#define DW_DT_RIGHT              (1 << 4)
#define DW_DT_TOP                (1 << 5)
#define DW_DT_VCENTER            (1 << 6)
#define DW_DT_BOTTOM             (1 << 7)
#define DW_DT_HALFTONE           (1 << 8)
#define DW_DT_MNEMONIC           (1 << 9)
#define DW_DT_WORDBREAK          (1 << 10)
#define DW_DT_ERASERECT          (1 << 11)

/* these don't exist under gtk, so make them dummy entries */
#define DW_DT_QUERYEXTENT        0
#define DW_DT_TEXTATTRS          0
#define DW_DT_EXTERNALLEADING    0

#define DW_FCF_TITLEBAR          1
#define DW_FCF_SYSMENU           (1 << 1)
#define DW_FCF_MENU              (1 << 2)
#define DW_FCF_SIZEBORDER        (1 << 3)
#define DW_FCF_MINBUTTON         (1 << 4)
#define DW_FCF_MAXBUTTON         (1 << 5)
#define DW_FCF_MINMAX            (1 << 6)
#define DW_FCF_DLGBORDER         (1 << 9)
#define DW_FCF_BORDER            (1 << 10)
#define DW_FCF_TASKLIST          (1 << 12)
#define DW_FCF_NOMOVEWITHOWNER   (1 << 14)
#define DW_FCF_SYSMODAL          (1 << 15)
#define DW_FCF_HIDEBUTTON        (1 << 16)
#define DW_FCF_HIDEMAX           (1 << 17)
#define DW_FCF_AUTOICON          (1 << 18)
#define DW_FCF_MAXIMIZE          (1 << 19)
#define DW_FCF_MINIMIZE          (1 << 20)
#define DW_FCF_CLOSEBUTTON       (1 << 21)
#define DW_FCF_TEXTURED          0
#define DW_FCF_FULLSCREEN        (1 << 22)

#define DW_CFA_BITMAPORICON      1
#define DW_CFA_STRING            (1 << 1)
#define DW_CFA_ULONG             (1 << 2)
#define DW_CFA_TIME              (1 << 3)
#define DW_CFA_DATE              (1 << 4)
#define DW_CFA_CENTER            (1 << 5)
#define DW_CFA_LEFT              (1 << 6)
#define DW_CFA_RIGHT             (1 << 7)
#define DW_CFA_HORZSEPARATOR     (1 << 8)
#define DW_CFA_SEPARATOR         (1 << 9)
#define DW_CFA_STRINGANDICON     (1 << 10)

#define DW_CRA_SELECTED          1
#define DW_CRA_CURSORED          (1 << 1)

#define DW_CR_RETDATA            (1 << 10)

#define DW_LS_MULTIPLESEL        1

#define DW_LIT_NONE              -1

#define DW_MLE_CASESENSITIVE     1

#define DW_BS_NOBORDER           1

#define DW_POINTER_DEFAULT       0
#define DW_POINTER_ARROW         GDK_TOP_LEFT_ARROW
#define DW_POINTER_CLOCK         GDK_WATCH
#define DW_POINTER_QUESTION      GDK_QUESTION_ARROW

#define HWND_DESKTOP             ((HWND)0)

/* flag values for dw_messagebox() */
#define DW_MB_OK                 (1 << 1)
#define DW_MB_OKCANCEL           (1 << 2)
#define DW_MB_YESNO              (1 << 3)
#define DW_MB_YESNOCANCEL        (1 << 4)

#define DW_MB_WARNING            (1 << 10)
#define DW_MB_ERROR              (1 << 11)
#define DW_MB_INFORMATION        (1 << 12)
#define DW_MB_QUESTION           (1 << 13)

/* Virtual Key Codes */
#if GTK_MAJOR_VERSION > 2
#define VK_LBUTTON           GDK_KEY_Pointer_Button1
#define VK_RBUTTON           GDK_KEY_Pointer_Button3
#define VK_CANCEL            GDK_KEY_Cancel
#define VK_MBUTTON           GDK_KEY_Pointer_Button2
#define VK_BACK              GDK_KEY_BackSpace
#define VK_TAB               GDK_KEY_Tab
#define VK_CLEAR             GDK_KEY_Clear
#define VK_RETURN            GDK_KEY_Return
#define VK_MENU              GDK_KEY_Menu
#define VK_PAUSE             GDK_KEY_Pause
#define VK_CAPITAL           GDK_KEY_Caps_Lock
#define VK_ESCAPE            GDK_KEY_Escape
#define VK_SPACE             GDK_KEY_space
#define VK_PRIOR             GDK_KEY_Page_Up
#define VK_NEXT              GDK_KEY_Page_Down
#define VK_END               GDK_KEY_End
#define VK_HOME              GDK_KEY_Home
#define VK_LEFT              GDK_KEY_Left
#define VK_UP                GDK_KEY_Up
#define VK_RIGHT             GDK_KEY_Right
#define VK_DOWN              GDK_KEY_Down
#define VK_SELECT            GDK_KEY_Select
#define VK_PRINT             GDK_KEY_Sys_Req
#define VK_EXECUTE           GDK_KEY_Execute
#define VK_SNAPSHOT          GDK_KEY_Print
#define VK_INSERT            GDK_KEY_Insert
#define VK_DELETE            GDK_KEY_Delete
#define VK_HELP              GDK_KEY_Help
#define VK_LWIN              GDK_KEY_Super_L
#define VK_RWIN              GDK_KEY_Super_R
#define VK_NUMPAD0           GDK_KEY_KP_0
#define VK_NUMPAD1           GDK_KEY_KP_1
#define VK_NUMPAD2           GDK_KEY_KP_2
#define VK_NUMPAD3           GDK_KEY_KP_3
#define VK_NUMPAD4           GDK_KEY_KP_4
#define VK_NUMPAD5           GDK_KEY_KP_5
#define VK_NUMPAD6           GDK_KEY_KP_6
#define VK_NUMPAD7           GDK_KEY_KP_7
#define VK_NUMPAD8           GDK_KEY_KP_8
#define VK_NUMPAD9           GDK_KEY_KP_9
#define VK_MULTIPLY          GDK_KEY_KP_Multiply
#define VK_ADD               GDK_KEY_KP_Add
#define VK_SEPARATOR         GDK_KEY_KP_Separator
#define VK_SUBTRACT          GDK_KEY_KP_Subtract
#define VK_DECIMAL           GDK_KEY_KP_Decimal
#define VK_DIVIDE            GDK_KEY_KP_Divide
#define VK_F1                GDK_KEY_F1
#define VK_F2                GDK_KEY_F2
#define VK_F3                GDK_KEY_F3
#define VK_F4                GDK_KEY_F4
#define VK_F5                GDK_KEY_F5
#define VK_F6                GDK_KEY_F6
#define VK_F7                GDK_KEY_F7
#define VK_F8                GDK_KEY_F8
#define VK_F9                GDK_KEY_F9
#define VK_F10               GDK_KEY_F10
#define VK_F11               GDK_KEY_F11
#define VK_F12               GDK_KEY_F12
#define VK_F13               GDK_KEY_F13
#define VK_F14               GDK_KEY_F14
#define VK_F15               GDK_KEY_F15
#define VK_F16               GDK_KEY_F16
#define VK_F17               GDK_KEY_F17
#define VK_F18               GDK_KEY_F18
#define VK_F19               GDK_KEY_F19
#define VK_F20               GDK_KEY_F20
#define VK_F21               GDK_KEY_F21
#define VK_F22               GDK_KEY_F22
#define VK_F23               GDK_KEY_F23
#define VK_F24               GDK_KEY_F24
#define VK_NUMLOCK           GDK_KEY_Num_Lock
#define VK_SCROLL            GDK_KEY_Scroll_Lock
#define VK_LSHIFT            GDK_KEY_Shift_L
#define VK_RSHIFT            GDK_KEY_Shift_R
#define VK_LCONTROL          GDK_KEY_Control_L
#define VK_RCONTROL          GDK_KEY_Control_R
#define VK_LMENU             GDK_KEY_Menu
#define VK_RMENU             GDK_KEY_Menu

#else
#define VK_LBUTTON           GDK_Pointer_Button1
#define VK_RBUTTON           GDK_Pointer_Button3
#define VK_CANCEL            GDK_Cancel
#define VK_MBUTTON           GDK_Pointer_Button2
#define VK_BACK              GDK_BackSpace
#define VK_TAB               GDK_Tab
#define VK_CLEAR             GDK_Clear
#define VK_RETURN            GDK_Return
#define VK_MENU              GDK_Menu
#define VK_PAUSE             GDK_Pause
#define VK_CAPITAL           GDK_Caps_Lock
#define VK_ESCAPE            GDK_Escape
#define VK_SPACE             GDK_space
#define VK_PRIOR             GDK_Page_Up
#define VK_NEXT              GDK_Page_Down
#define VK_END               GDK_End
#define VK_HOME              GDK_Home
#define VK_LEFT              GDK_Left
#define VK_UP                GDK_Up
#define VK_RIGHT             GDK_Right
#define VK_DOWN              GDK_Down
#define VK_SELECT            GDK_Select
#define VK_PRINT             GDK_Sys_Req
#define VK_EXECUTE           GDK_Execute
#define VK_SNAPSHOT          GDK_Print
#define VK_INSERT            GDK_Insert
#define VK_DELETE            GDK_Delete
#define VK_HELP              GDK_Help
#define VK_LWIN              GDK_Super_L
#define VK_RWIN              GDK_Super_R
#define VK_NUMPAD0           GDK_KP_0
#define VK_NUMPAD1           GDK_KP_1
#define VK_NUMPAD2           GDK_KP_2
#define VK_NUMPAD3           GDK_KP_3
#define VK_NUMPAD4           GDK_KP_4
#define VK_NUMPAD5           GDK_KP_5
#define VK_NUMPAD6           GDK_KP_6
#define VK_NUMPAD7           GDK_KP_7
#define VK_NUMPAD8           GDK_KP_8
#define VK_NUMPAD9           GDK_KP_9
#define VK_MULTIPLY          GDK_KP_Multiply
#define VK_ADD               GDK_KP_Add
#define VK_SEPARATOR         GDK_KP_Separator
#define VK_SUBTRACT          GDK_KP_Subtract
#define VK_DECIMAL           GDK_KP_Decimal
#define VK_DIVIDE            GDK_KP_Divide
#define VK_F1                GDK_F1
#define VK_F2                GDK_F2
#define VK_F3                GDK_F3
#define VK_F4                GDK_F4
#define VK_F5                GDK_F5
#define VK_F6                GDK_F6
#define VK_F7                GDK_F7
#define VK_F8                GDK_F8
#define VK_F9                GDK_F9
#define VK_F10               GDK_F10
#define VK_F11               GDK_F11
#define VK_F12               GDK_F12
#define VK_F13               GDK_F13
#define VK_F14               GDK_F14
#define VK_F15               GDK_F15
#define VK_F16               GDK_F16
#define VK_F17               GDK_F17
#define VK_F18               GDK_F18
#define VK_F19               GDK_F19
#define VK_F20               GDK_F20
#define VK_F21               GDK_F21
#define VK_F22               GDK_F22
#define VK_F23               GDK_F23
#define VK_F24               GDK_F24
#define VK_NUMLOCK           GDK_Num_Lock
#define VK_SCROLL            GDK_Scroll_Lock
#define VK_LSHIFT            GDK_Shift_L
#define VK_RSHIFT            GDK_Shift_R
#define VK_LCONTROL          GDK_Control_L
#define VK_RCONTROL          GDK_Control_R
#define VK_LMENU             GDK_Menu
#define VK_RMENU             GDK_Menu
#endif

/* Key Modifiers */
#define KC_CTRL              GDK_CONTROL_MASK
#define KC_SHIFT             GDK_SHIFT_MASK
#define KC_ALT               GDK_MOD1_MASK

typedef GtkWidget *HWND;
#ifndef _ENVRNMNT_H
typedef unsigned long ULONG;
#endif
typedef long LONG;
typedef unsigned short USHORT;
typedef short SHORT;
typedef unsigned short UWORD;
typedef short WORD ;
typedef unsigned char UCHAR;
typedef char CHAR;
typedef unsigned UINT;
typedef int INT;
typedef pthread_mutex_t *HMTX;
typedef struct _dw_unix_event {
   pthread_mutex_t mutex;
   pthread_cond_t event;
   pthread_t thread;
   int alive;
   int posted;
} *HEV;
typedef pthread_t DWTID;
typedef void * HMOD;
struct _dw_unix_shm {
   int fd;
   char *path;
   int sid;
   int size;
};

typedef struct _hpixmap {
   unsigned long width, height;
   HWND handle;
   char *font;
#if GTK_MAJOR_VERSION > 1
   GdkPixbuf *pixbuf;  /* the actual image */
#endif
#if GTK_MAJOR_VERSION > 2
   cairo_surface_t *image; /* Going to have dual storage for now */
#else
   GdkPixmap *pixmap;  /* the actual image */
   GdkBitmap *bitmap;  /* if not null, the image mask representing the transparency mask */
   void *image;        /* Opaque handle to a cairo_surface_t for printing */
#endif
} *HPIXMAP;

typedef GtkWidget *HMENUI;
typedef void *HTREEITEM;
typedef void *HSHM;
typedef void *HICN;

/* As of Dynamic Windows 3.1 GResource is default if supported.
 * Using --with-deprecated at configure time will include
 * support for our old home brewed resource system.
 * GLib 2.32 is required for GResource, so we automatically 
 * enable our old system if using an old Glib.
 * Test for GResource using: dwindows-config --gresource
 */
#ifndef DW_INCLUDE_DEPRECATED_RESOURCES
#if defined(DW_INCLUDE_DEPRECATED) || GTK_MAJOR_VERSION < 2 || !GLIB_CHECK_VERSION(2,32,0)
#define DW_INCLUDE_DEPRECATED_RESOURCES 1
#endif
#endif

/* Only reference our old style resources if required. */
#ifdef DW_INCLUDE_DEPRECATED_RESOURCES
typedef struct _resource_struct {
   long resource_max, *resource_id;
   char **resource_data;
} DWResources;

#if !defined(DW_RESOURCES) || defined(BUILD_DLL)
static DWResources DW_UNUSED(_resources) = { 0, 0, 0 };
#else
extern DWResources _resources;
#endif
#endif

#endif

#if !defined(__OS2__) && !defined(__EMX__)
typedef struct _CDATE
{
   UCHAR  day;
   UCHAR  month;
   USHORT year;
} CDATE;
typedef CDATE *PCDATE;

typedef struct _CTIME
{
   UCHAR hours;
   UCHAR minutes;
   UCHAR seconds;
   UCHAR ucReserved;
} CTIME;
typedef CTIME *PCTIME;
#endif

#if defined(__OS2__) || (defined(__WIN32__) && !defined(GDK_WINDOWING_WIN32)) || (defined(WINNT) && !defined(GDK_WINDOWING_WIN32)) || defined(__EMX__)
typedef unsigned long DWTID;
#endif

/* Some dark mode constants for supported platforms */
#define DW_DARK_MODE_DISABLED 0
#define DW_DARK_MODE_BASIC    1
#define DW_DARK_MODE_FULL     2
#define DW_DARK_MODE_FORCED   3

/* Application ID support lengths */
#define _DW_APP_ID_SIZE 100

/* Use at least the linux utsname limit to avoid gcc fortify warnings */
#define _DW_ENV_STRING_SIZE 257

typedef struct _dwenv {
   /* Operating System Name and DW Build Date/Time */
   char osName[_DW_ENV_STRING_SIZE], buildDate[_DW_ENV_STRING_SIZE], buildTime[_DW_ENV_STRING_SIZE];
   /* Versions and builds */
   short MajorVersion, MinorVersion, MajorBuild, MinorBuild;
   /* Dynamic Window version */
   short DWMajorVersion, DWMinorVersion, DWSubVersion;
   /* Which HTML engine is compiled in */
   char htmlEngine[_DW_ENV_STRING_SIZE];
} DWEnv;


typedef struct _dwexpose {
   int x, y;
   int width, height;
} DWExpose;

typedef struct _dwdialog {
   HEV eve;
   int done;
   int method;
   void *data, *result;
} DWDialog;

typedef void *HPRINT;

#define DW_SIGNAL_FUNC(a) ((void *)a)

#define DW_DESKTOP               HWND_DESKTOP
#define DW_MINIMIZED 1

#define DW_BUTTON1_MASK 1
#define DW_BUTTON2_MASK (1 << 1)
#define DW_BUTTON3_MASK (1 << 2)

#define DW_EXEC_CON 0
#define DW_EXEC_GUI 1

#define DW_FILE_OPEN      0
#define DW_FILE_SAVE      1
#define DW_DIRECTORY_OPEN 2

#define DW_HORZ 0
#define DW_VERT 1

#define DW_TIMEOUT_INFINITE ((unsigned long)-1)

/* Obsolete, should disappear sometime */
#define BOXHORZ DW_HORZ
#define BOXVERT DW_VERT
#define DW_FCF_SHELLPOSITION     0
#define DW_FCF_NOBYTEALIGN       0
#define DW_FCF_VERTSCROLL        0
#define DW_FCF_HORZSCROLL        0

/* Scrolling constants */
#define DW_SCROLL_UP 0
#define DW_SCROLL_DOWN 1
#define DW_SCROLL_TOP 2
#define DW_SCROLL_BOTTOM 3

/* return values for dw_messagebox() */
#define DW_MB_RETURN_OK           0
#define DW_MB_RETURN_YES          1
#define DW_MB_RETURN_NO           0
#define DW_MB_RETURN_CANCEL       2

#define DW_PIXMAP_WIDTH(x) (x ? x->width : 0)
#define DW_PIXMAP_HEIGHT(x) (x ? x->height : 0)

#define DW_RGB_COLOR (0xF0000000)
#define DW_RGB_TRANSPARENT (0x0F000000)
#define DW_RGB_MASK (0x00FFFFFF)
#define DW_RED_MASK (0x000000FF)
#define DW_GREEN_MASK (0x0000FF00)
#define DW_BLUE_MASK (0x00FF0000)
#define DW_RED_VALUE(a) (a & DW_RED_MASK)
#define DW_GREEN_VALUE(a) ((a & DW_GREEN_MASK) >> 8)
#define DW_BLUE_VALUE(a) ((a & DW_BLUE_MASK) >> 16)
#define DW_RGB(a, b, c) (0xF0000000 | (a) | (b) << 8 | (c) << 16)

/* Menu convenience paramaters */
#define DW_MENU_SEPARATOR ""
#define DW_NOMENU 0
#define DW_MENU_AUTO 0
#define DW_MENU_POPUP (unsigned long)-1

/* Convenience parameters for various types */
#define DW_NOHWND 0
#define DW_NOHTIMER 0
#define DW_NOHPRINT 0
#define DW_NOHPIXMAP 0
#define DW_NOHICN 0

#define DW_PERCENT_INDETERMINATE ((unsigned int)-1)

/* Return value error codes */
#define DW_ERROR_NONE      0
#define DW_ERROR_GENERAL   1
#define DW_ERROR_TIMEOUT   2
#define DW_ERROR_NON_INIT  3
#define DW_ERROR_NO_MEM    4
#define DW_ERROR_INTERRUPT 5
#define DW_ERROR_UNKNOWN   -1

/* Embedded HTML actions */
#define DW_HTML_GOBACK     0
#define DW_HTML_GOFORWARD  1
#define DW_HTML_GOHOME     2
#define DW_HTML_SEARCH     3
#define DW_HTML_RELOAD     4
#define DW_HTML_STOP       5
#define DW_HTML_PRINT      6

/* Embedded HTML notifcations */
#define DW_HTML_CHANGE_STARTED  1
#define DW_HTML_CHANGE_REDIRECT 2
#define DW_HTML_CHANGE_LOADING  3
#define DW_HTML_CHANGE_COMPLETE 4

/* Drawing flags  */
#define DW_DRAW_DEFAULT    0
#define DW_DRAW_FILL       1
#define DW_DRAW_FULL       (1 << 1)
#define DW_DRAW_NOAA       (1 << 2)

/* MLE Completion flags */
#define DW_MLE_COMPLETE_TEXT      1
#define DW_MLE_COMPLETE_DASH      (1 << 1)
#define DW_MLE_COMPLETE_QUOTE     (1 << 2)

/* Library feature constants */
#define DW_FEATURE_UNSUPPORTED  -1
#define DW_FEATURE_DISABLED     0
#define DW_FEATURE_ENABLED      1

typedef enum 
{
    DW_FEATURE_HTML = 0,                /* Supports the HTML Widget */
    DW_FEATURE_HTML_RESULT,             /* Supports the DW_SIGNAL_HTML_RESULT callback */
    DW_FEATURE_WINDOW_BORDER,           /* Supports custom window border sizes */
    DW_FEATURE_WINDOW_TRANSPARENCY,     /* Supports window frame transparency */
    DW_FEATURE_DARK_MODE,               /* Supports Dark Mode user interface */
    DW_FEATURE_MLE_AUTO_COMPLETE,       /* Supports auto completion in Multi-line Edit boxes */
    DW_FEATURE_MLE_WORD_WRAP,           /* Supports word wrapping in Multi-line Edit boxes */
    DW_FEATURE_CONTAINER_STRIPE,        /* Supports striped line display in container widgets */ 
    DW_FEATURE_MDI,                     /* Supports Multiple Document Interface window frame */
    DW_FEATURE_NOTEBOOK_STATUS_TEXT,    /* Supports status text area on notebook/tabbed controls */
    DW_FEATURE_NOTIFICATION,            /* Supports sending system notifications */
    DW_FEATURE_UTF8_UNICODE,            /* Supports UTF8 encoded Unicode text */
    DW_FEATURE_MLE_RICH_EDIT,           /* Supports Rich Edit based MLE control (Windows) */
    DW_FEATURE_MAX
} DWFEATURE;

/* Macro for casting resource IDs to HICN */
#define DW_RESOURCE(a) (a < 65536 ? (HICN)a : (HICN)0)

#include <limits.h>
/* Macros for converting from INT/UINT to and from POINTER without compiler warnings */
#if _MSC_VER > 1500 || __GNUC_PREREQ(3, 1) || defined(__clang__)
#include <stdint.h>
/* There has got to be a better way to check for the intptr_t type....
 * for now just include valid versions of Visual C and GCC plus clang.
 */
#define DW_INT_TO_POINTER(a) ((void *)(intptr_t)a)
#define DW_POINTER_TO_INT(a) ((int)(intptr_t)a)
#define DW_UINT_TO_POINTER(a) ((void *)(uintptr_t)a)
#define DW_POINTER_TO_UINT(a) ((unsigned int)(uintptr_t)a)
#define DW_LONGLONG_TO_POINTER(a) ((void *)(intptr_t)a)
#define DW_POINTER_TO_LONGLONG(a) ((long long)(intptr_t)a)
#define DW_ULONGLONG_TO_POINTER(a) ((void *)(uintptr_t)a)
#define DW_POINTER_TO_ULONGLONG(a) ((unsigned long long)(uintptr_t)a)
#elif ULONG_MAX > UINT_MAX
/* If no intptr_t... ULONG is often bigger than UINT */
#define DW_INT_TO_POINTER(a) ((void *)(long)a)
#define DW_POINTER_TO_INT(a) ((int)(long)a)
#define DW_UINT_TO_POINTER(a) ((void *)(unsigned long)a)
#define DW_POINTER_TO_UINT(a) ((unsigned int)(unsigned long)a)
#else
/* Otherwise just fall back to standard casts */
#define DW_INT_TO_POINTER(a) ((void *)a)
#define DW_POINTER_TO_INT(a) ((int)a)
#define DW_UINT_TO_POINTER(a) ((void *)a)
#define DW_POINTER_TO_UINT(a) ((unsigned int)a)
#endif
#ifndef DW_LONGLONG_TO_POINTER
#define DW_LONGLONG_TO_POINTER(a) ((void *)a)
#define DW_POINTER_TO_LONGLONG(a) ((long long)a)
#define DW_ULONGLONG_TO_POINTER(a) ((void *)a)
#define DW_POINTER_TO_ULONGLONG(a) ((unsigned long long)a)
#endif
#define DW_POINTER(a) ((void *)a)

#ifndef DW_FCF_COMPOSITED
#define DW_FCF_COMPOSITED        0
#endif

#ifndef API
#define API
#endif

#ifndef DWSIGNAL
#define DWSIGNAL API
#endif

/* Constants for sizing scrolled widgets */
#define _DW_SCROLLED_MIN_WIDTH   100
#define _DW_SCROLLED_MIN_HEIGHT  75
#define _DW_SCROLLED_MAX_WIDTH   500
#define _DW_SCROLLED_MAX_HEIGHT  400

#include <wchar.h>

/* Let other APIs know what types we've defined,
 * Regina REXX in particular, on Unix.
 */
#define ULONG_TYPEDEFED 1
#define LONG_TYPEDEFED 1
#define USHORT_TYPEDEFED 1
#define SHORT_TYPEDEFED 1
#define UWORD_TYPEDEFED 1
#define WORD_TYPEDEFED 1
#define UCHAR_TYPEDEFED 1
#define CHAR_TYPEDEFED 1
#define UINT_TYPEDEFED 1
#define INT_TYPEDEFED 1

/* Use the dbsoft.org application domain by default if not specified */
#define DW_APP_DOMAIN_DEFAULT "org.dbsoft.dwindows"

/* Public function prototypes */
void API dw_box_pack_start(HWND box, HWND item, int width, int height, int hsize, int vsize, int pad);
void API dw_box_pack_end(HWND box, HWND item, int width, int height, int hsize, int vsize, int pad);
void API dw_box_pack_at_index(HWND box, HWND item, int index, int width, int height, int hsize, int vsize, int pad);
HWND API dw_box_unpack_at_index(HWND box, int index);
int API dw_box_unpack(HWND handle);
int API dw_init(int newthread, int argc, char *argv[]);
#ifdef DW_INCLUDE_DEPRECATED_RESOURCES
int API dw_int_init(DWResources *res, int newthread, int *argc, char **argv[]);
#define dw_init(a, b, c) dw_int_init(&_resources, a, &b, &c)
#endif
void API dw_main(void);
void API dw_main_quit(void);
void API dw_main_sleep(int seconds);
void API dw_main_iteration(void);
void API dw_free(void *ptr);
int API dw_window_show(HWND handle);
int API dw_window_hide(HWND handle);
int API dw_window_minimize(HWND handle);
int API dw_window_raise(HWND handle);
int API dw_window_lower(HWND handle);
int API dw_window_destroy(HWND handle);
void API dw_window_redraw(HWND handle);
int API dw_window_set_font(HWND handle, const char *fontname);
char * API dw_window_get_font(HWND handle);
int API dw_window_set_color(HWND handle, unsigned long fore, unsigned long back);
HWND API dw_window_new(HWND hwndOwner, const char *title, unsigned long flStyle);
HWND API dw_box_new(int type, int pad);
HWND API dw_scrollbox_new(int type, int pad);
int API dw_scrollbox_get_pos( HWND handle, int orient );
int API dw_scrollbox_get_range( HWND handle, int orient );
HWND API dw_groupbox_new(int type, int pad, const char *title);
DW_DEPRECATED(HWND API dw_mdi_new(unsigned long id), "Due to lack of full Mac support consider avoiding this function.");
HWND API dw_bitmap_new(unsigned long id);
HWND API dw_bitmapbutton_new(const char *text, unsigned long id);
HWND API dw_bitmapbutton_new_from_file(const char *text, unsigned long id, const char *filename);
HWND API dw_bitmapbutton_new_from_data(const char *text, unsigned long id, const char *str, int len);
HWND API dw_container_new(unsigned long id, int multi);
HWND API dw_tree_new(unsigned long id);
HWND API dw_text_new(const char *text, unsigned long id);
HWND API dw_status_text_new(const char *text, unsigned long id);
HWND API dw_mle_new(unsigned long id);
HWND API dw_entryfield_new(const char *text, unsigned long id);
HWND API dw_entryfield_password_new(const char *text, ULONG id);
HWND API dw_combobox_new(const char *text, unsigned long id);
HWND API dw_button_new(const char *text, unsigned long id);
HWND API dw_spinbutton_new(const char *text, unsigned long id);
HWND API dw_radiobutton_new(const char *text, ULONG id);
HWND API dw_percent_new(unsigned long id);
HWND API dw_slider_new(int vertical, int increments, ULONG id);
HWND API dw_scrollbar_new(int vertical, ULONG id);
HWND API dw_checkbox_new(const char *text, unsigned long id);
HWND API dw_listbox_new(unsigned long id, int multi);
void API dw_listbox_append(HWND handle, const char *text);
void API dw_listbox_insert(HWND handle, const char *text, int pos);
void API dw_listbox_list_append(HWND handle, char **text, int count);
void API dw_listbox_clear(HWND handle);
int API dw_listbox_count(HWND handle);
void API dw_listbox_set_top(HWND handle, int top);
void API dw_listbox_select(HWND handle, int index, int state);
void API dw_listbox_delete(HWND handle, int index);
void API dw_listbox_get_text(HWND handle, unsigned int index, char *buffer, unsigned int length);
void API dw_listbox_set_text(HWND handle, unsigned int index, const char *buffer);
int API dw_listbox_selected(HWND handle);
int API dw_listbox_selected_multi(HWND handle, int where);
void API dw_percent_set_pos(HWND handle, unsigned int position);
unsigned int API dw_slider_get_pos(HWND handle);
void API dw_slider_set_pos(HWND handle, unsigned int position);
unsigned int API dw_scrollbar_get_pos(HWND handle);
void API dw_scrollbar_set_pos(HWND handle, unsigned int position);
void API dw_scrollbar_set_range(HWND handle, unsigned int range, unsigned int visible);
void API dw_window_set_pos(HWND handle, long x, long y);
void API dw_window_set_size(HWND handle, unsigned long width, unsigned long height);
void API dw_window_set_pos_size(HWND handle, long x, long y, unsigned long width, unsigned long height);
void API dw_window_get_pos_size(HWND handle, long *x, long *y, unsigned long *width, unsigned long *height);
void API dw_window_get_preferred_size(HWND handle, int *width, int *height);
void API dw_window_set_gravity(HWND handle, int horz, int vert);
void API dw_window_set_style(HWND handle, unsigned long style, unsigned long mask);
void API dw_window_set_icon(HWND handle, HICN icon);
void API dw_window_set_bitmap(HWND handle, unsigned long id, const char *filename);
void API dw_window_set_bitmap_from_data(HWND handle, unsigned long id, const char *data, int len);
char * API dw_window_get_text(HWND handle);
void API dw_window_set_text(HWND handle, const char *text);
void API dw_window_set_tooltip(HWND handle, const char *bubbletext);
int API dw_window_set_border(HWND handle, int border);
void API dw_window_disable(HWND handle);
void API dw_window_enable(HWND handle);
void API dw_window_capture(HWND handle);
void API dw_window_release(void);
void API dw_window_reparent(HWND handle, HWND newparent);
void API dw_window_set_pointer(HWND handle, int pointertype);
void API dw_window_set_focus(HWND handle);
void API dw_window_default(HWND window, HWND defaultitem);
void API dw_window_click_default(HWND window, HWND next);
unsigned int API dw_mle_import(HWND handle, const char *buffer, int startpoint);
void API dw_mle_export(HWND handle, char *buffer, int startpoint, int length);
void API dw_mle_get_size(HWND handle, unsigned long *bytes, unsigned long *lines);
void API dw_mle_delete(HWND handle, int startpoint, int length);
void API dw_mle_clear(HWND handle);
void API dw_mle_freeze(HWND handle);
void API dw_mle_thaw(HWND handle);
void API dw_mle_set_cursor(HWND handle, int point);
void API dw_mle_set_visible(HWND handle, int line);
void API dw_mle_set_editable(HWND handle, int state);
void API dw_mle_set_word_wrap(HWND handle, int state);
void API dw_mle_set_auto_complete(HWND handle, int state);
int API dw_mle_search(HWND handle, const char *text, int point, unsigned long flags);
void API dw_spinbutton_set_pos(HWND handle, long position);
void API dw_spinbutton_set_limits(HWND handle, long upper, long lower);
void API dw_entryfield_set_limit(HWND handle, ULONG limit);
long API dw_spinbutton_get_pos(HWND handle);
int API dw_checkbox_get(HWND handle);
void API dw_checkbox_set(HWND handle, int value);
HTREEITEM API dw_tree_insert(HWND handle, const char *title, HICN icon, HTREEITEM parent, void *itemdata);
HTREEITEM API dw_tree_insert_after(HWND handle, HTREEITEM item, const char *title, HICN icon, HTREEITEM parent, void *itemdata);
void API dw_tree_clear(HWND handle);
void API dw_tree_item_delete(HWND handle, HTREEITEM item);
void API dw_tree_item_change(HWND handle, HTREEITEM item, const char *title, HICN icon);
void API dw_tree_item_expand(HWND handle, HTREEITEM item);
void API dw_tree_item_collapse(HWND handle, HTREEITEM item);
void API dw_tree_item_select(HWND handle, HTREEITEM item);
void API dw_tree_item_set_data(HWND handle, HTREEITEM item, void *itemdata);
void * API dw_tree_item_get_data(HWND handle, HTREEITEM item);
char * API dw_tree_get_title(HWND handle, HTREEITEM item);
HTREEITEM API dw_tree_get_parent(HWND handle, HTREEITEM item);
int API dw_container_setup(HWND handle, unsigned long *flags, char **titles, int count, int separator);
HICN API dw_icon_load(unsigned long module, unsigned long id);
HICN API dw_icon_load_from_file(const char *filename);
HICN API dw_icon_load_from_data(const char *data, int len);
void API dw_icon_free(HICN handle);
void * API dw_container_alloc(HWND handle, int rowcount);
void API dw_container_set_item(HWND handle, void *pointer, int column, int row, void *data);
void API dw_container_change_item(HWND handle, int column, int row, void *data);
void API dw_container_set_column_width(HWND handle, int column, int width);
void API dw_container_set_row_title(void *pointer, int row, const char *title);
void API dw_container_change_row_title(HWND handle, int row, const char *title);
void API dw_container_set_row_data(void *pointer, int row, void *data);
void API dw_container_change_row_data(HWND handle, int row, void *data);
void API dw_container_insert(HWND handle, void *pointer, int rowcount);
void API dw_container_clear(HWND handle, int redraw);
void API dw_container_delete(HWND handle, int rowcount);
char * API dw_container_query_start(HWND handle, unsigned long flags);
char * API dw_container_query_next(HWND handle, unsigned long flags);
void API dw_container_scroll(HWND handle, int direction, long rows);
void API dw_container_cursor(HWND handle, const char *text);
void API dw_container_cursor_by_data(HWND handle, void *data);
void API dw_container_delete_row(HWND handle, const char *text);
void API dw_container_delete_row_by_data(HWND handle, void *data);
void API dw_container_optimize(HWND handle);
void API dw_container_set_stripe(HWND handle, unsigned long oddcolor, unsigned long evencolor);
void API dw_filesystem_set_column_title(HWND handle, const char *title);
int API dw_filesystem_setup(HWND handle, unsigned long *flags, char **titles, int count);
void API dw_filesystem_set_item(HWND handle, void *pointer, int column, int row, void *data);
void API dw_filesystem_set_file(HWND handle, void *pointer, int row, const char *filename, HICN icon);
void API dw_filesystem_change_item(HWND handle, int column, int row, void *data);
void API dw_filesystem_change_file(HWND handle, int row, const char *filename, HICN icon);
int API dw_container_get_column_type(HWND handle, int column);
int API dw_filesystem_get_column_type(HWND handle, int column);
void API dw_taskbar_insert(HWND handle, HICN icon, const char *bubbletext);
void API dw_taskbar_delete(HWND handle, HICN icon);
int API dw_screen_width(void);
int API dw_screen_height(void);
unsigned long API dw_color_depth_get(void);
HWND API dw_notebook_new(unsigned long id, int top);
unsigned long API dw_notebook_page_new(HWND handle, unsigned long flags, int front);
void API dw_notebook_page_destroy(HWND handle, unsigned int pageid);
void API dw_notebook_page_set_text(HWND handle, unsigned long pageid, const char *text);
void API dw_notebook_page_set_status_text(HWND handle, unsigned long pageid, const char *text);
void API dw_notebook_page_set(HWND handle, unsigned int pageid);
unsigned long API dw_notebook_page_get(HWND handle);
void API dw_notebook_pack(HWND handle, unsigned long pageid, HWND page);
HWND API dw_splitbar_new(int type, HWND topleft, HWND bottomright, unsigned long id);
void API dw_splitbar_set(HWND handle, float percent);
float API dw_splitbar_get(HWND handle);
HMENUI API dw_menu_new(unsigned long id);
HMENUI API dw_menubar_new(HWND location);
HWND API dw_menu_append_item(HMENUI menu, const char *title, unsigned long id, unsigned long flags, int end, int check, HMENUI submenu);
int API dw_menu_delete_item(HMENUI menu, unsigned long id);
DW_DEPRECATED(void API dw_menu_item_set_check(HMENUI menu, unsigned long id, int check), "Use dw_menu_item_set_state() for new code.");
void API dw_menu_item_set_state( HMENUI menux, unsigned long id, unsigned long state);
void API dw_menu_popup(HMENUI *menu, HWND parent, int x, int y);
void API dw_menu_destroy(HMENUI *menu);
void API dw_pointer_query_pos(long *x, long *y);
void API dw_pointer_set_pos(long x, long y);
void API dw_window_function(HWND handle, void *function, void *data);
HWND API dw_window_from_id(HWND handle, int id);
HMTX API dw_mutex_new(void);
void API dw_mutex_close(HMTX mutex);
void API dw_mutex_lock(HMTX mutex);
int API dw_mutex_trylock(HMTX mutex);
void API dw_mutex_unlock(HMTX mutex);
HEV API dw_event_new(void);
int API dw_event_reset(HEV eve);
int API dw_event_post(HEV eve);
int API dw_event_wait(HEV eve, unsigned long timeout);
int API dw_event_close (HEV *eve);
DWTID API dw_thread_new(void *func, void *data, int stack);
void API dw_thread_end(void);
DWTID API dw_thread_id(void);
void API dw_exit(int exitcode);
void API dw_shutdown(void);
HWND API dw_render_new(unsigned long id);
void API dw_color_foreground_set(unsigned long value);
void API dw_color_background_set(unsigned long value);
unsigned long API dw_color_choose(unsigned long value);
char * API dw_font_choose(const char *currfont);
void API dw_draw_point(HWND handle, HPIXMAP pixmap, int x, int y);
void API dw_draw_line(HWND handle, HPIXMAP pixmap, int x1, int y1, int x2, int y2);
void API dw_draw_rect(HWND handle, HPIXMAP pixmap, int fill, int x, int y, int width, int height);
void API dw_draw_polygon(HWND handle, HPIXMAP pixmap, int fill, int npoints, int *x, int *y);
void API dw_draw_arc(HWND handle, HPIXMAP pixmap, int flags, int xorigin, int yorigin, int x1, int y1, int x2, int y2);
void API dw_draw_text(HWND handle, HPIXMAP pixmap, int x, int y, const char *text);
void API dw_font_text_extents_get(HWND handle, HPIXMAP pixmap, const char *text, int *width, int *height);
void API dw_font_set_default(const char *fontname);
void API dw_flush(void);
void API dw_pixmap_bitblt(HWND dest, HPIXMAP destp, int xdest, int ydest, int width, int height, HWND src, HPIXMAP srcp, int xsrc, int ysrc);
int API dw_pixmap_stretch_bitblt(HWND dest, HPIXMAP destp, int xdest, int ydest, int width, int height, HWND src, HPIXMAP srcp, int xsrc, int ysrc, int srcwidth, int srcheight);
HPIXMAP API dw_pixmap_new(HWND handle, unsigned long width, unsigned long height, int depth);
HPIXMAP API dw_pixmap_new_from_file(HWND handle, const char *filename);
HPIXMAP API dw_pixmap_new_from_data(HWND handle, const char *data, int len);
HPIXMAP API dw_pixmap_grab(HWND handle, ULONG id);
void API dw_pixmap_set_transparent_color( HPIXMAP pixmap, ULONG color );
int API dw_pixmap_set_font(HPIXMAP pixmap, const char *fontname);
void API dw_pixmap_destroy(HPIXMAP pixmap);
void API dw_beep(int freq, int dur);
void API dw_debug(const char *format, ...);
int API dw_messagebox(const char *title, int flags, const char *format, ...);
void API dw_environment_query(DWEnv *env);
int API dw_exec(const char *program, int type, char **params);
int API dw_browse(const char *url);
char * API dw_file_browse(const char *title, const char *defpath, const char *ext, int flags);
char * API dw_user_dir(void);
char * API dw_app_dir(void);
int API dw_app_id_set(const char *appid, const char *appname);
DWDialog * API dw_dialog_new(void *data);
int API dw_dialog_dismiss(DWDialog *dialog, void *result);
void * API dw_dialog_wait(DWDialog *dialog);
void API dw_window_set_data(HWND window, const char *dataname, void *data);
void * API dw_window_get_data(HWND window, const char *dataname);
int API dw_module_load(const char *name, HMOD *handle);
int API dw_module_symbol(HMOD handle, const char *name, void**func);
int API dw_module_close(HMOD handle);
int API dw_timer_connect(int interval, void *sigfunc, void *data);
void API dw_timer_disconnect(int id);
void API dw_signal_connect(HWND window, const char *signame, void *sigfunc, void *data);
void API dw_signal_connect_data(HWND window, const char *signame, void *sigfunc, void *discfunc, void *data);
void API dw_signal_disconnect_by_window(HWND window);
void API dw_signal_disconnect_by_data(HWND window, void *data);
void API dw_signal_disconnect_by_name(HWND window, const char *signame);
HEV API dw_named_event_new(const char *name);
HEV API dw_named_event_get(const char *name);
int API dw_named_event_reset(HEV eve);
int API dw_named_event_post(HEV eve);
int API dw_named_event_wait(HEV eve, unsigned long timeout);
int API dw_named_event_close(HEV eve);
HSHM API dw_named_memory_new(void **dest, int size, const char *name);
HSHM API dw_named_memory_get(void **dest, int size, const char *name);
int API dw_named_memory_free(HSHM handle, void *ptr);
void API dw_html_action(HWND hwnd, int action);
int API dw_html_raw(HWND hwnd, const char *string);
int API dw_html_url(HWND hwnd, const char *url);
int API dw_html_javascript_run(HWND hwnd, const char *script, void *scriptdata);
HWND API dw_html_new(unsigned long id);
char * API dw_clipboard_get_text(void);
void API dw_clipboard_set_text(const char *str, int len);
HWND API dw_calendar_new(unsigned long id);
void API dw_calendar_set_date(HWND window, unsigned int year, unsigned int month, unsigned int day);
void API dw_calendar_get_date(HWND window, unsigned int *year, unsigned int *month, unsigned int *day);
HPRINT API dw_print_new(const char *jobname, unsigned long flags, unsigned int pages, void *drawfunc, void *drawdata);
int API dw_print_run(HPRINT print, unsigned long flags);
void API dw_print_cancel(HPRINT print);
HWND API dw_notification_new(const char *title, const char *imagepath, const char *description, ...);
int API dw_notification_send(HWND notification);
wchar_t * API dw_utf8_to_wchar(const char *utf8string);
char * API dw_wchar_to_utf8(const wchar_t *wstring);
int API dw_feature_get(DWFEATURE feature); 
int API dw_feature_set(DWFEATURE feature, int state); 
/* Exported for language bindings */
void API _dw_init_thread(void);
void API _dw_deinit_thread(void);

#ifdef __cplusplus
}
#endif

#endif
