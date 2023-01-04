/*
** EPITECH PROJECT, 2022
** B-MUL-100-REN-1-1-myhunter-hugo.murat
** File description:
** my_hunter
*/

#include "search_bar.h"

search_t sb_enter(search_t sb, sfEvent ev)
{
    for (int i = 0; i < 151; i++) {
        if (my_strcmp(sb.text, /* nom du pokemon dans la list chainé */) == 0) {
            // Edit du pokemon affiché
            break;
        }
    }
    for (int i = 0; i < 50; i++) {
        sb.text[i] = '\0';
        sb.nav_index = 0;
    }
    return sb;
}

search_t sb_intput(search_t sb, sfEvent ev)
{
    for (int letter = 'a'; letter - 97 < 26; letter++)
        if (ev.key.code == (sfKeyA - 97 + letter)) {
            sb.text[sb.nav_index] = letter;
            sb.nav_index++;
        }
    return sb;
}

search_t sb_events(search_t sb, sfEvent ev)
{
    if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyBackspace) {
        sb.text[sb.nav_index - 1] = '\0';
        sb.nav_index--;
    }
    if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyEnter)
        sb = sb_enter(sb, ev);
    if (ev.type == sfEvtKeyPressed)
        sb = sb_intput(sb, ev);
    return sb;
}

search_t sb_draw(search_t sb, sfRenderWindow *w)
{
    sfRenderWindow_drawRectangleShape(w ,sb.search_bar_line, NULL);
    sfRenderWindow_drawText(w, sb.textbox, NULL);
    sfText_setString(sb.textbox, sb.text);
    return sb;
}

search_t sb_init(search_t sb)
{
    sb.search_bar_line = sfRectangleShape_create();
    sfRectangleShape_setSize(sb.search_bar_line, (sfVector2f){200, 3});
    sfRectangleShape_setPosition(sb.search_bar_line, (sfVector2f){150, 40});
    sb.nav_index = 0;
    for (int i = 0; i < 50; i++)
        sb.text[i] = '\0';
    sb.pokemon = sfFont_createFromFile("./assets/pokemon.ttf");
    sb.textbox = sfText_create();
    sfText_setFont(sb.textbox, sb.pokemon);
    sfText_setCharacterSize(sb.textbox, 18);
    sfText_setColor(sb.textbox, sfWhite);
    sfText_setPosition(sb.textbox, (sfVector2f) {155, 15});
    sfText_setString(sb.textbox, sb.text);
    return sb;
}
