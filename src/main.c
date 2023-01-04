/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** desc
*/

#include <poke_functions.h>

int main(int argc, char **argv)
{
    window_s *window_datas = init_window();

    sprite_s *background = new_sprite(window_datas, "assets/ui/background.png", "background");
    sfSprite_setPosition(background->sf_sprite, (sfVector2f){ 0.0, 350.0});

    sprite_s *pokemon = new_sprite(window_datas, "assets/poke_test.png", "Pokemon");
    sfSprite_setPosition(pokemon->sf_sprite, (sfVector2f){ 250.0, 260.0});
    sfSprite_scale(pokemon->sf_sprite, (sfVector2f){0.7, 0.7});
    center_sprite(pokemon);

    init_arrow(window_datas);

    text_s *name = new_text(window_datas, "Pikatchu", "name");
    sfText_setPosition(name->sf_text, (sfVector2f){50.0, 50.0});
    sfText_setCharacterSize(name->sf_text, 24);

    text_s *id = new_text(window_datas, "#001", "id");
    sfText_setPosition(id->sf_text, (sfVector2f){380.0, 50.0});
    sfText_setCharacterSize(id->sf_text, 24);

    new_window(window_datas);
    return 0;
}
