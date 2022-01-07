i16gcc -Wall -o ech.exe echo.c
i16gcc -Wall -c cpyfile.c
i16gcc -Wall -o typ.exe type.c cpyfile.o
i16gcc -Wall -o cpy.exe copy.c cpyfile.o
i16gcc -Wall -o choic.exe choice.c -li86
i16gcc -Wall -o paus.exe pause.c -li86
i16gcc -Wall -o mor.exe more.c -li86
