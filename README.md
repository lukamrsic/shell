# Moj Shell

Vlastita implementacija Unix shella napisana u C-u

## Što radi

- Čita i parsira korisnički unos
- Pokreće vanjske programe (`ls`, `pwd`, itd.) koristeći `fork()` i `execvp()`
- Podržava ugrađene komande: `cd` i `exit`

## Kako pokrenuti

Potreban je GCC kompajler i Unix/Linux okruženje (ili WSL na Windowsu).

```bash
gcc shell.c -o mojshell
./mojshell
```

## Primjer korištenja

mojshell> ls -la
mojshell> cd ..
mojshell> pwd
mojshell> exit