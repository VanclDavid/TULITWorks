
## Zadání 7:


Problematika je řešena třemi vlákny:
- Vlákno 1 - Obsluha LCD
- Vlákno 2 - Obsluha seriové komunkace
- Vlákno 3 - Obsluha tlačíka


Nastavení WD a softwarového restartu je realizováno příakzy poslanými sériovou komunikací - "konzole" PowerNut.
- reset-device
- set-watchdoguloha7

V souboru **[main.cpp](https://gitlab.tul.cz/david.dlouhy/ops_2020_dlouhy/-/blob/master/zadani_7/main.cpp)** se nachází převážně vlákna.
V souboru **[win_ext_powernut.cpp](https://gitlab.tul.cz/david.dlouhy/ops_2020_dlouhy/-/blob/master/zadani_7/WinExt/win_ext_powernut.cpp)** se nachází vše okolo obsluhy sériové komunikace.

Vytvořil jsem si externí soubor c++ kam jsem si přesunul část kódu. Následně tento kód upravím a budu jej chtít napojit na **[WinExtension](https://gitlab.tul.cz/david.dlouhy/ops_2020_dlouhy/-/tree/master/WinExtension)**.

  
> Řešení úlohy bude napojeno na nadstavbu Mbed OS zavné **[WinExtension](https://gitlab.tul.cz/david.dlouhy/ops_2020_dlouhy/-/tree/master/WinExtension)**

*V repositáři je pouze hlavní zdrojový soubor, nejsou zde dodány všechny potřebné soubory.*
