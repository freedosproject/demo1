THESE ARE DEMO PROGRAMS FROM THE YOUTUBE CHANNEL

If you're just getting started with C programming, DOS is a good place
to start.  These sample programs show how you might write your own
simple replacements for common DOS commands, like ECHO, TYPE, COPY,
CHOICE, PAUSE, and MORE.

When I started as a newbie programmer in the 1990s, I learned C
programming by writing my own DOS commands, just like these.

I should add that these are *not* the best way to write these
programs. For example, reading and writing ONE CHARACTER AT A TIME is
very slow, especially on DOS. It's much faster if you use buffers. But
as a demo for how to get started in programming, this is not a bad
place to start.


HOW TO USE THESE FILES:

Run SETENV.BAT to set your environment.
(This sets the PATH for the IA-16 GCC compiler, sets an alias for
EDLIN16 as EDLIN, and unloads the CuteMouse driver)

Run BUILD.BAT to build all the programs.

Run CLEAN.BAT to clean up the build and start fresh.

Run T.BAT to test the programs.
(Also uses TEST.TXT, TEST30.TXT, and TESTLONG.TXT)
