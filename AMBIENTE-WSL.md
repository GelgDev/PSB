# Ambiente WSL para programar em C

Anotações do setup feito em 10/08/2026. Máquina `GelgNote`, usuário Linux `gelg`.

## O que está instalado

| Item | Versão |
|---|---|
| WSL | 2.6.3 (kernel 6.6.87, WSLg 1.0.71) |
| Distro | Ubuntu 26.04 LTS |
| gcc | 15.2.0 |
| gdb | 17.1 |
| make | 4.4.1 |
| valgrind | 3.26.0 |

Pasta de trabalho: `~/aulas` (= `/home/gelg/aulas`).

## ARMADILHA: distro errada

Se o terminal aparecer como `GelgNote:~#` (root, `-sh`) e disser **`sudo: not found`**, você caiu na distro
`docker-desktop`, não no Ubuntu. Ela é o motor do Docker: Alpine pelada, sem apt, sem sudo. Não use.

Já corrigido com `wsl --set-default Ubuntu`. Se voltar a acontecer:

```powershell
wsl --list --verbose      # o "*" marca a default
wsl --set-default Ubuntu
```

## Esqueci a senha do sudo

Root no WSL não pede senha. Do PowerShell:

```powershell
wsl -d Ubuntu -u root
```

Depois, dentro:

```bash
passwd gelg     # digita 2x; não aparece nada na tela, é normal
exit
```

## Compilar e rodar

```bash
gcc -Wall -Wextra -g -o programa programa.c && ./programa
```

- `-Wall -Wextra` → liga os avisos. **Sempre.** É o que pega 90% dos bugs de C antes de rodar.
- `-g` → símbolos de debug, necessário para o gdb.
- `-o programa` → nome do executável. No Linux não tem `.exe`.
- `-lm` → adicione no fim se usar `math.h` (`sqrt`, `pow`, `sin`...).

Depurar:

```bash
gdb ./programa
```

Dentro do gdb: `break main` · `run` · `next` (próxima linha) · `step` (entra na função) · `print x` ·
`backtrace` (onde estourou) · `continue` · `quit`.

Caçar problema de memória (segfault, vazamento, acesso inválido):

```bash
valgrind --leak-check=full ./programa
```

## Alternar Windows <-> WSL

**Windows Terminal** (default = PowerShell):

- `Ctrl+Shift+1` → Windows PowerShell
- `Ctrl+Shift+6` → Ubuntu
- `Alt+Shift+D` → divide o painel (os dois lado a lado); `Alt+←` / `Alt+→` pula entre eles
- `Ctrl+Tab` → circula entre abas

**Dentro de um shell só:** `wsl` entra no Ubuntu, `exit` (ou `Ctrl+D`) volta.
Comando único sem entrar: `wsl gcc -Wall -o Teste Teste.c`.

**VS Code** (extensões `WSL` e `C/C++` já instaladas):

- Botão `><` no canto inferior esquerdo, ou `Ctrl+Shift+P`:
  - `WSL: Reopen Folder in WSL` → projeto roda no Linux (**use este para as aulas**)
  - `WSL: Reopen Folder in Windows` → volta
- Dois terminais na mesma janela: setinha ao lado do `+` no painel do terminal → `Ubuntu (WSL)`
- `` Ctrl+` `` mostra/esconde o terminal; `F5` depura (só funciona bem em modo WSL)
- Não abra o VS Code como Administrador — bagunça o dono dos arquivos no Linux.

## Atravessando os arquivos

- Do Linux para o Windows: `C:\` está em `/mnt/c/`
  - `cd "$(wslpath 'C:\Users\dbl-r\Desktop')"` converte caminho do Windows
- Do Windows para o Linux: `\\wsl.localhost\Ubuntu\home\gelg` (tem ícone **Linux** na lateral do Explorer)
- De dentro do Linux, chamando o Windows: `explorer.exe .` · `code .` · `notepad.exe arquivo`

**Regra:** código C mora **dentro** do Linux (`~/aulas`). Compilar em `/mnt/c/` funciona, mas é lento e a
permissão de arquivo fica bagunçada.

## Interface gráfica

WSLg já vem ativo — app gráfico Linux abre como janela normal do Windows, sem configurar nada. Testar:

```bash
sudo apt install -y x11-apps && xeyes
```

Desktop completo (XFCE + xrdp) é possível, mas desnecessário para C — o VS Code em modo WSL resolve.

## Manutenção

```bash
sudo apt update && sudo apt upgrade
```

Encerrar o WSL quando travar ou comer RAM demais (do PowerShell): `wsl --shutdown`.
