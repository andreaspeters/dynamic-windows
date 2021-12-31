# Dynamic Windows version 

## This is a fork of: http://trac.netlabs.org/dwindows/
Please do not bother Brain for faulures you will find on my fork. :-) Just
open an issue here.

---

The current Dynamic Windows source base is considered stable on:
OS/2, Mac, Windows, Linux, FreeBSD and OpenSolaris.

## Build Recommendations:

### MacOS:

```
    11.0: configure --with-arch=modern --with-minver=10.14
        64bit Intel and Apple Silicon support with Dark Mode.
    10.13-10.15: configure --with-minver=10.8
        64bit Intel with Notifications, Dark Mode for 10.14-15.
    10.8-10.12: configure --with-arch=intel --with-minver=10.8
        64 and 32bit Intel with Notifications but no Dark Mode.
    10.6: configure --with-arch=classic --with-minver=10.5
        32bit PowerPC, 64bit and 32bit Intel classic support.
        No Notifications, Dark Mode nor NSView container/trees.
```

### Windows:

```
    10: Visual Studio 2017-2019, WebView2 and WinToast.
        Should run on Vista and later, but sockpipe() only on 10.
        Supports domain sockets on Windows 10 dwcompat sockpipe().
    7-8.1: Visual Studio 2015, WebView2 and WinToast with 8 SDK.
        Should run on Vista and later, old sockpipe() on all.
    XP: Visual Studio 2010.  Old sockpipe() on all versions.
        Should run on XP and later, with Aero on Vista and 7.
        No Notifications nor WebView2 and old sockpipe() on all.
    2000: Visual Studio 2005. Remove -DAEROGLASS from CFLAGS.
        Should run on 2000 and later, no Aero, Notifications, 
        WebView2 and old sockpipe() on all versions.
```

## Known problems:

Boxes with no expandable items will have their contents centered on 
GTK2 instead of top or left justified on the other platforms.
GTK3 due to changes in the core architecture does not support
widgets that are smaller than what is contained within them,
unless they use scrolled windows. GTK2 and other platforms do.
Therefore windows or other elements may expand their size to 
fit the contents, overriding requested size settings.
In Unicode mode on OS/2 there are some bugs in the input controls,
minor bugs in entryfield based controls and major bugs in the MLE.
The text displays properly but the cursor and selection jumps
around oddly when passing over multibyte characters.

## Known limitations:

It is not safe on all platforms to operate on widgets before they
are packed.  For portability pack widgets before operating on them.

## Future features:

- OS/2 is currently missing the HTML widget because the system does 
not support it by default. Looking into importing functionality 
from available libraries (Firefox, Webkit, Qt, etc).
- OS/2 is also missing a notification system, so the new notification
APIs are not yet supported on OS/2.  May implement our own system 
- if a popular notification system is not already in existance.
Ports to iOS and Android are underway.


