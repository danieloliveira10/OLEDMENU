# OLEDMENU
Utilizando-se de um display oled ssd1306, esse menu simples visa facilitar o desenvolvimento de um projeto multifacetado.

Esse código é uma base para outros projetos como ferramenta de prototipagem com o intuito de permitir o usuário a escolher até 4 opcões de um menu dinamicamente alocado. O design do menu se alterará de 2x1 para 2x2 automaticamente. Nota-se que para um projeto no qual espaço é crucial não é muito recomendado, mas para os que querem colocar para funcionar com agilidade e facilidade é o ideal.

Para utilizar o menu comece alterando no setup o código `menuOled("MAIN MENU", "ZERO", "UM", "", "");` deixar em branco quando não utilizado, o primeiro argumento é referente ao título do menu.
O código para cada opcão deverá ser adicionado a sua respectiva função ao final do programa. opt0(); opt1(); opt2(); opt3().

Fotos da interface e funcionamento:
![IMG_4264 (1)](https://github.com/danieloliveira10/OLEDMENU/assets/103888008/a5b8d179-fc09-454a-a455-d1979698db5d)
![IMG_4261 (1)](https://github.com/danieloliveira10/OLEDMENU/assets/103888008/fab64bec-348a-4e3f-8075-4ee85e5920da)
